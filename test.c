#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/binary_info.h"

const uint RED_LED = 0;

const uint GPIO_ON = 1;
const uint GPIO_OFF = 0;

int main()
{
  bi_decl(bi_program_description("This is a test binary."));
  bi_decl(bi_1pin_with_name(RED_LED, "LED on GPIO 2"));

  stdio_init_all();

  gpio_init(RED_LED);
  gpio_set_dir(RED_LED, GPIO_OUT);
  while (true)
  {
    gpio_put(RED_LED, GPIO_OFF);
    sleep_ms(250);
    gpio_put(RED_LED, GPIO_ON);
    puts("Hello Ryan!\n");
    sleep_ms(1000);
  }
  
}
