#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "rom/gpio.h"
#include "esp_log.h"

#define gpio_num 22

void app_main(void)
{
 unsigned int pin = 0;
 gpio_pad_select_gpio(GPIO_NUM_22);
 gpio_set_direction(GPIO_NUM_22, GPIO_MODE_OUTPUT);
 while(1) {
  pin = !pin;
  gpio_set_level(GPIO_NUM_22, pin);
  ESP_LOGI("LED Test", "PIN 22 is %d", pin);
  vTaskDelay(1000/portTICK_PERIOD_MS);
 }
}
