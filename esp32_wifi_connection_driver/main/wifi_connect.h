#ifndef WIFI_CONNECT_H
#define WIFI_CONNECT_H

#include "esp_err.h"
#include <stdio.h>
#include <string.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_wifi.h"
#include "esp_netif.h"
#include "esp_event_legacy.h"



void wifi_init(void);
esp_err_t wifi_connection_sta(const char *ssid, const char *pcode, int timeout);
void wifi_connection_ap(const char *ssid, const char *pcode);
void wifi_disconnect(void);


#endif