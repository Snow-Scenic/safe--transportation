#ifndef __WIFI_MODULE_H__
#define __WIFI_MODULE_H__

#define WIFI_DEVICE_NAME "w0"

#ifdef RT_WLAN_AUTO_CONNECT_ENABLE
void wlan_autoconnect_init(void);
#endif

int wifi_init(void);
int wifi_is_ready(void);
char *wifi_get_ip(void);
int wifi_connect(char *conn_str);
char *wifi_status_get(void);

#endif /*__WIFIMODULE_H*/
