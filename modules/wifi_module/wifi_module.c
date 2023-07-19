/**
  ******************************************************************************
  * @file                wifi_module.c
  * @author              BruceOu
  * @rtt version         V4.0.3
  * @version             V1.0
  * @date                2021-04-06
  * @blog                https://blog.bruceou.cn/
  * @Official Accounts   嵌入式实验楼
  * @brief
  ******************************************************************************
  */
#include <rtthread.h>
#include <rtdevice.h>
#include <cJSON.h>
#include <wlan_mgnt.h>
#include <netdev_ipaddr.h>
#include <netdev.h>
#include <stdio.h>
#include <stdlib.h>

#include <wifi_module.h>

#define DBG_TAG "wifi"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>

#define MAX_SSID_PASSWD_STR_LEN 50
#define BT_SEND_TIMES 1
#define BT_SEND_FAIL_RETRY 3

extern int bt_stack_blufi_send(uint8_t *string, uint32_t length);
extern int adb_socket_init(void);

char wifi_status_str[100];

struct _wifi
{
    char ssid[MAX_SSID_PASSWD_STR_LEN];
    char passwd[MAX_SSID_PASSWD_STR_LEN];
} wifi;


#ifdef RT_WLAN_AUTO_CONNECT_ENABLE

#include <wlan_mgnt.h>
#include <wlan_cfg.h>
#include <wlan_prot.h>
#include <easyflash.h>
#include <fal.h>

static int read_cfg(void *buff, int len)
{
    size_t saved_len;

    ef_get_env_blob("wlan_cfg_info", buff, len, &saved_len);
    if (saved_len == 0)
    {
        return 0;
    }

    return len;
}

static int get_len(void)
{
    int len;
    size_t saved_len;

    ef_get_env_blob("wlan_cfg_len", &len, sizeof(len), &saved_len);
    if (saved_len == 0)
    {
        return 0;
    }

    return len;
}

static int write_cfg(void *buff, int len)
{
    /* set and store the wlan config lengths to Env */
    ef_set_env_blob("wlan_cfg_len", &len, sizeof(len));

    /* set and store the wlan config information to Env */
    ef_set_env_blob("wlan_cfg_info", buff, len);

    return len;
}


static const struct rt_wlan_cfg_ops ops =
{
    read_cfg,
    get_len,
    write_cfg
};

void wlan_autoconnect_init(void)
{
    fal_init();
    easyflash_init();

    rt_wlan_cfg_set_ops(&ops);
    rt_wlan_cfg_cache_refresh();

    /* enable auto reconnect on WLAN device */
    rt_wlan_config_autoreconnect(RT_TRUE);
}
#endif

int wifi_connect(char *conn_str)
{
    cJSON *conn = cJSON_Parse(conn_str);
    if (conn)
    {
        cJSON *ssid = cJSON_GetObjectItem(conn, "ssid");
        cJSON *passwd = cJSON_GetObjectItem(conn, "passwd");
        rt_memset(wifi.ssid,0,sizeof(wifi.ssid));
        rt_memset(wifi.passwd,0,sizeof(wifi.passwd));
        if (ssid && passwd)
        {
            if (rt_strlen(ssid->valuestring) > MAX_SSID_PASSWD_STR_LEN ||
                rt_strlen(passwd->valuestring) > MAX_SSID_PASSWD_STR_LEN)
            {
                LOG_E("invalid ssid or passwd length,max %d", MAX_SSID_PASSWD_STR_LEN);
            }
            else
            {
                rt_memcpy(wifi.ssid, ssid->valuestring, rt_strlen(ssid->valuestring));
                rt_memcpy(wifi.passwd, passwd->valuestring, rt_strlen(passwd->valuestring));
                return rt_wlan_connect(wifi.ssid, wifi.passwd);
            }
        }
        else
        {
            LOG_E("cannot find ssid or password.");
        }

        cJSON_Delete(conn);
    }
    else
    {
        LOG_E("invalid wifi connection string.");
    }
    return -1;
}

int wifi_is_ready(void)
{
    return rt_wlan_is_ready();
}

char *wifi_get_ip(void)
{
    struct netdev *dev = netdev_get_by_name(WIFI_DEVICE_NAME);
    if (dev)
    {
        return inet_ntoa(dev->ip_addr);
    }
    else
    {
        return NULL;
    }
}

char *wifi_status_get(void)
{
    rt_memset(wifi_status_str, 0, sizeof(wifi_status_str));
    uint8_t wifi_status = wifi_is_ready();
    char *wifi_ip = wifi_get_ip();
    rt_sprintf(wifi_status_str, "{wifi:'%s', url:'%s'}", wifi_status ? "on" : "off", wifi_ip);
    return wifi_status_str;
}

static void wifi_ready_handler(int event, struct rt_wlan_buff *buff, void *parameter)
{
    int cnt = BT_SEND_TIMES;

    //wifi status send
    rt_memset(wifi_status_str, 0, sizeof(wifi_status_str));
    while (cnt--)
    {
        char *wifi_status = wifi_status_get();
        int retry_cnt = BT_SEND_FAIL_RETRY;
        while (bt_stack_blufi_send((uint8_t *)wifi_status, rt_strlen(wifi_status)) < 0)
        {
            if (retry_cnt == 0)
                break;
            retry_cnt--;
            rt_thread_mdelay(1000);
        }
        rt_thread_mdelay(5000);
    }
}

int wifi_init(void)
{
    rt_memset(&wifi, 0, sizeof(wifi));
    rt_wlan_register_event_handler(RT_WLAN_EVT_READY, wifi_ready_handler, NULL);
    
    return 0;
}


