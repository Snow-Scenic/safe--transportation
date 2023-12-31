/**
  ******************************************************************************
  * @file                dht11_thread.c
  * @author              BruceOu
  * @rtt version         V4.0.3
  * @version             V1.0
  * @date                2021-04-15
  * @blog                https://blog.bruceou.cn/
  * @Official Accounts   嵌入式实验楼
  * @brief               DHT11线程
  ******************************************************************************
  */
#include <rtthread.h>
#include <rtdevice.h>
#include "sensor.h"
#include "sensor_dallas_dht11.h"
#include "drv_gpio.h"
#include "dht11_thread.h"

/* Modify this pin according to the actual wiring situation */
#define DHT11_DATA_PIN    GET_PIN(B, 12)

rt_dht11 dht11;

static void read_temp_entry(void *parameter)
{
    rt_device_t dev = RT_NULL;
    struct rt_sensor_data sensor_data;
    rt_size_t res;
    rt_uint8_t get_data_freq = 1; /* 1Hz */

    dev = rt_device_find("temp_dht11");
    if (dev == RT_NULL)
    {
        return;
    }

    if (rt_device_open(dev, RT_DEVICE_FLAG_RDWR) != RT_EOK)
    {
        rt_kprintf("open device failed!\n");
        return;
    }

    rt_device_control(dev, RT_SENSOR_CTRL_SET_ODR, (void *)(&get_data_freq));

    while (1)
    {
        res = rt_device_read(dev, 0, &sensor_data, 1);

        if (res != 1)
        {
            rt_kprintf("read data failed! result is %d\n", res);
            rt_device_close(dev);
            return;
        }
        else
        {
            if (sensor_data.data.temp >= 0)
            {
                dht11.temp = (sensor_data.data.temp & 0xffff) >> 0;      // get temp
                dht11.humi = (sensor_data.data.temp & 0xffff0000) >> 16; // get humi
                //rt_kprintf("temp:%d, humi:%d\n" ,dht11.temp, dht11.humi);
            }
        }

        rt_thread_delay(1000);
    }
}

static int dht11_thread(void)
{
    rt_thread_t dht11_thread;

    dht11_thread = rt_thread_create("dht_tem",
                                     read_temp_entry,
                                     RT_NULL,
                                     1024,
                                     RT_THREAD_PRIORITY_MAX / 2,
                                     20);
    if (dht11_thread != RT_NULL)
    {
        rt_thread_startup(dht11_thread);
    }

    return RT_EOK;
}

INIT_APP_EXPORT(dht11_thread);

/* 导出到 msh 命令列表中 */
//MSH_CMD_EXPORT(dht11_thread, dht11 thread);

static int rt_hw_dht11_port(void)
{
    struct rt_sensor_config cfg;
    
    cfg.intf.user_data = (void *)DHT11_DATA_PIN;
    rt_hw_dht11_init("dht11", &cfg);

    return RT_EOK;
}
INIT_COMPONENT_EXPORT(rt_hw_dht11_port);
