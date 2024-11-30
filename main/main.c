/* WiFi station Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.

   GET EXAMPLE FROM
   https://github.com/GyverLibs/FastBot/blob/main/src/FastBot.h

   addition materials:
   https://habr.com/ru/companies/epam_systems/articles/522730/
*/
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "nvs_flash.h"

#include "lwip/err.h"
#include "lwip/sys.h"

#include "platform.h"
#include "connection.h"
#include "../specific_modules/adc_tools.h"


static const char *TAG = "Steppefort";



void app_main(void)
{
    //Initialize NVS
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
      ESP_ERROR_CHECK(nvs_flash_erase());
      ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    ESP_LOGI(TAG, "ESP_WIFI_MODE_STA");
    wifi_init_sta();

    adctools_init();

    xTaskCreatePinnedToCore(
        adc_task,           // Указатель на функцию задачи
        "ADC Task",         // Имя задачи
        2048,               // Размер стека в байтах
        NULL,               // Параметры задачи
        5,                  // Приоритет задачи
        NULL,               // Дескриптор задачи
        1                   // Ядро (0 - Core 0, 1 - Core 1)
    );

}
