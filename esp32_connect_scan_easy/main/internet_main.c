#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "esp_sntp.h"
#include "esp_wifi.h"
#include "nvs_flash.h"
#include "protocol_examples_common.h"
#include "esp_log.h"

#define TAG "NTP_TIME"

void print_time(long time, const char *msg)
{
    // timezone
    setenv("TZ", "UTC +8", 1);
    tzset();

    //
    struct tm *timeinfo = localtime(&time);

    char buffer[50];
    strftime(buffer, sizeof(buffer), "%c", timeinfo);
    ESP_LOGI(TAG, "msg: %s: %s", msg, buffer);
}

void get_time(struct timeval *tv)
{
  printf("secs %lld\n", tv->tv_sec);
  print_time(tv->tv_sec, "time at callback");

  esp_restart();
}

void wifi_init()
{
    nvs_flash_init();
    esp_netif_init();
    esp_event_loop_create_default();
    example_connect();
}

void sntp_fcn()
{
    sntp_set_sync_mode(SNTP_SYNC_MODE_IMMED);
    sntp_setservername(0, "pool.ntp.org");
    sntp_init();
    sntp_set_time_sync_notification_cb(get_time);
}

void app_main()
{
    time_t now = 0;
    time(&now);
    print_time(now, "Beginning of application");
    
    wifi_init();
    sntp_fcn();

}