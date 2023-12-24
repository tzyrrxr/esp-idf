#include <stdio.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
//#include "freertos/task.h"

void app_main(void)
{
    unsigned int counter = 1;

    for (; counter; counter++) {
        ESP_LOGI("QEMU", "counter: %d", counter);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }

}
