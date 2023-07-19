#include <rtthread.h>
#include <rtdevice.h>
#include <wifi_module.h>
#include "drv_common.h"

#include "bt_module.h"

#define LED_PIN GET_PIN(H, 2)

int main(void)
{
    rt_uint32_t count = 1;

    rt_pin_mode(LED_PIN, PIN_MODE_OUTPUT);

    //wifi init
    wifi_init();

    //bt init
    bluetooth_init();

    /* init Wi-Fi auto connect feature */
    wlan_autoconnect_init();

    while(count++)
    {
        rt_thread_mdelay(500);
        rt_pin_write(LED_PIN, PIN_HIGH);
        rt_thread_mdelay(500);
        rt_pin_write(LED_PIN, PIN_LOW);
    }
    return RT_EOK;
}

#include "stm32h7xx.h"
static int vtor_config(void)
{
    /* Vector Table Relocation in Internal QSPI_FLASH */
    SCB->VTOR = QSPI_BASE;
    return 0;
}
INIT_BOARD_EXPORT(vtor_config);


