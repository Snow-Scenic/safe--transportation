/**
  ******************************************************************************
  * @file                onenet_sample.c
  * @author              BruceOu
  * @rtt version         V4.0.3
  * @version             V1.0
  * @date                2021-04-15
  * @blog                https://blog.bruceou.cn/
  * @Official Accounts   嵌入式实验楼
  * @brief               OneNET应用
  ******************************************************************************
  */
#include <stdlib.h>
#include <onenet.h>
#include <wlan_mgnt.h>
#include "dht11_thread.h"

#define DBG_ENABLE
#define DBG_COLOR
#define DBG_SECTION_NAME    "onenet.sample"
#if ONENET_DEBUG
#define DBG_LEVEL           DBG_LOG
#else
#define DBG_LEVEL           DBG_INFO
#endif /* ONENET_DEBUG */

#include <rtdbg.h>

#ifdef FINSH_USING_MSH
#include <finsh.h>

extern rt_dht11 dht11;

static int onenetOk = -1;

/* upload random value to temperature*/
static void onenet_upload_entry(void *parameter)
{
    while (1)
    {
        if(onenetOk == 1)
        {
            //dht11
            //temperature
            if (onenet_mqtt_upload_digit("temperature", dht11.temp) < 0)
            {
                LOG_E("upload has an error, please check the network");
                //break;
            }
            else
            {
                //LOG_D("buffer : {\"temperature\":%d}", dht11.temp);
            }

            rt_thread_delay(rt_tick_from_millisecond(2 * 1000));

            //humidity
            if (onenet_mqtt_upload_digit("humidity", dht11.humi) < 0)
            {
                LOG_E("upload has an error, please check the network");
                //break;
            }
            else
            {
                //LOG_D("buffer : {\"humidity\":%d}", dht11.humi);
            }
        }
        rt_thread_delay(rt_tick_from_millisecond(5 * 1000));
    }
}

int onenet_upload_cycle(void)
{
    rt_thread_t tid;

    tid = rt_thread_create("onenet_send",
                           onenet_upload_entry,
                           RT_NULL,
                           2 * 1024,
                           RT_THREAD_PRIORITY_MAX / 3 - 1,
                           5);
    if (tid)
    {
        rt_thread_startup(tid);
    }

    return 0;
}

//MSH_CMD_EXPORT(onenet_upload_cycle, send data to OneNET cloud cycle);
INIT_APP_EXPORT(onenet_upload_cycle);

int onenet_publish_digit(int argc, char **argv)
{
    if (argc != 3)
    {
        LOG_E("onenet_publish [datastream_id]  [value]  - mqtt pulish digit data to OneNET.");
        return -1;
    }

    if (onenet_mqtt_upload_digit(argv[1], atoi(argv[2])) < 0)
    {
        LOG_E("upload digit data has an error!\n");
    }

    return 0;
}
MSH_CMD_EXPORT_ALIAS(onenet_publish_digit, onenet_mqtt_publish_digit, send digit data to onenet cloud);

int onenet_publish_string(int argc, char **argv)
{
    if (argc != 3)
    {
        LOG_E("onenet_publish [datastream_id]  [string]  - mqtt pulish string data to OneNET.");
        return -1;
    }

    if (onenet_mqtt_upload_string(argv[1], argv[2]) < 0)
    {
        LOG_E("upload string has an error!\n");
    }

    return 0;
}
MSH_CMD_EXPORT_ALIAS(onenet_publish_string, onenet_mqtt_publish_string, send string data to onenet cloud);

/* onenet mqtt command response callback function */
static void onenet_cmd_rsp_cb(uint8_t *recv_data, size_t recv_size, uint8_t **resp_data, size_t *resp_size)
{
    char res_buf[] = { "cmd is received!\n" };

    LOG_D("recv data is %.*s\n", recv_size, recv_data);

    /* user have to malloc memory for response data */
    *resp_data = (uint8_t *) ONENET_MALLOC(strlen(res_buf));

    strncpy((char *)*resp_data, res_buf, strlen(res_buf));

    *resp_size = strlen(res_buf);
}

/* set the onenet mqtt command response callback function */
int onenet_set_cmd_rsp(int argc, char **argv)
{
    onenet_set_cmd_rsp_cb(onenet_cmd_rsp_cb);
    return 0;
}
MSH_CMD_EXPORT(onenet_set_cmd_rsp, set cmd response function);

/* onenet init*/
static void onenet_init_entry(void *parameter)
{
    int result = -1;
    while(1)
    {
        if (rt_wlan_is_connected())
        {
            result = onenet_mqtt_init();
            if(result == 0)
            {
                onenetOk = 1;
                break;
            }
        }
        rt_thread_delay(5000);
    }
}

int onenet_init(void)
{
    rt_thread_t tid;

    tid = rt_thread_create("onenet_init",
                           onenet_init_entry,
                           RT_NULL,
                           2 * 1024,
                           RT_THREAD_PRIORITY_MAX / 2 - 1,
                           5);
    if (tid)
    {
        rt_thread_startup(tid);
    }

    return 0;
}

INIT_APP_EXPORT(onenet_init);

#endif /* FINSH_USING_MSH */
