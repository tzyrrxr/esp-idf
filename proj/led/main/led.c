#include "driver/gpio.h"
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void blink() {
 gpio_pad_select_gpio(23);
 gpio_set_direction (23, GPIO_MODE_OUTPUT);

 while(1) {
  gpio_set_level(23, 0);
  vTaskDelay(1000/portTICK_RATE_MS);
  gpio_set_level(23, 1);
  vTaskDelay(1000/portTICK_RATE_MS);
 }
}

void app_main(void)
{
 blink();
}
