#ifndef __DHT11_THREAD_H__
#define __DHT11_THREAD_H__

#include <rtthread.h>

typedef struct{
    uint8_t temp;
    uint8_t humi;
}rt_dht11;

#endif /* __DHT11_THREAD_H_ */

