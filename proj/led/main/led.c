#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

void blink() {
 gpio_set_direction (23, GPIO_MODE_OUTPUT);

 while(1) {
  ESP_LOGI("LOG", "OFF");
  gpio_set_level(23, 0);
  vTaskDelay(1000/portTICK_PERIOD_MS);
  ESP_LOGI("LOG", "ON");
  gpio_set_level(23, 1);
  vTaskDelay(1000/portTICK_PERIOD_MS);
 }

}

void app_main(void)
{

 blink();

}
