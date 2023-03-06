#include "wifi_connect.h"
const static char *TAG = "WIFI";

void event_handler(void* event_handler_arg, esp_event_base_t event_base, int32_t event_id, void* event_data)
{
    switch (event_id)
    {
    case SYSTEM_EVENT_STA_START:
        ESP_LOGI(TAG, "connecting ...");
        esp_wifi_connect();
        break;
    case SYSTEM_EVENT_STA_CONNECTED:
        ESP_LOGI(TAG, "connected!");
        break;
    case SYSTEM_EVENT_STA_DISCONNECTED:
        ESP_LOGI(TAG, "disconnected!");
        break;
    case IP_EVENT_STA_GOT_IP:
        ESP_LOGI(TAG, "GOT IP ADDRESS");
        break;
    default:
        break;
    }

}

void wifi_init(void)
{
    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());
    wifi_init_config_t wifi_initial_config = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&wifi_initial_config));
    ESP_ERROR_CHECK(esp_event_handler_register(WIFI_EVENT,ESP_EVENT_ANY_ID,event_handler,NULL));
    ESP_ERROR_CHECK(esp_event_handler_register(IP_EVENT, IP_EVENT_STA_GOT_IP, event_handler, NULL));
    ESP_ERROR_CHECK(esp_wifi_set_storage(WIFI_STORAGE_RAM));
}

esp_err_t wifi_connection_sta(const char *ssid, const char *pcode, int timeout){

    return NULL;
}

void wifi_connection_ap(const char *ssid, const char *pcode){

}

void wifi_disconnect(void){

}