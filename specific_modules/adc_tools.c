#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/adc.h>
#include <esp_log.h>

#include "adc_tools.h"
#include "../main/platform.h"

#define TAG "ADC_TOOLS"

void adc_task(void *pvParameters) {
    while (1) {
        // Пример считывания ADC
        int adc_value = adc1_get_raw(ADC1_CHANNEL_0); // Канал 0
        ESP_LOGI(TAG, "ADC Value: %d", adc_value);

        // Задержка 1 мс
        vTaskDelay(pdMS_TO_TICKS(1));
    }
}

void adctools_init(void){
    adc1_config_width(ADC_WIDTH_BIT_12); // 12-битная точность
    adc1_config_channel_atten(ADC1_CHANNEL_0, ADC_ATTEN_DB_0); // Канал 0, 0 дБ аттенюация
    }