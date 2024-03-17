#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define GPIO_OUT_W1TS_REG 0x3FF44008
#define GPIO_OUT_W1TC_REG 0x3FF4400C
#define GPIO_ENABLE_REG   0x3FF44020

#define HIGH     1
#define GPIO22   23
#define DELAY_MS 500

void app_main(void)
{
  volatile uint32_t *Gpio_start = (volatile uint32_t *) GPIO_OUT_W1TS_REG;
  volatile uint32_t *Gpio_close = (volatile uint32_t *) GPIO_OUT_W1TC_REG;
  volatile uint32_t *Gpio_enable = (volatile uint32_t *) GPIO_ENABLE_REG;

  // enable register
  *Gpio_enable = HIGH << GPIO22;
  for (;;) {
    // high
    *Gpio_start = HIGH << GPIO22;
    vTaskDelay(pdMS_TO_TICKS(DELAY_MS));
    // low
    *Gpio_close = HIGH << GPIO22;
    vTaskDelay(pdMS_TO_TICKS(DELAY_MS));
  }

}
