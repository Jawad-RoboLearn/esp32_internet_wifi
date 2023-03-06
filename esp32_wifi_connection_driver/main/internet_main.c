#include "wifi_connect.h"
#include "stdio.h"
#include "nvs_flash.h"

void app_main()
{
    ESP_ERROR_CHECK(nvs_flash_init()); // if we init the flash, we can also save the wifi information in memory flash or ram
    wifi_init();
}