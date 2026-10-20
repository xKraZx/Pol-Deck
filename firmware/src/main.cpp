#include "backlight.h"
#include "gfx.h"
#include "hardware/gpio.h"
#include "ili9488.h"
#include "pico/stdlib.h"

int main(void)
{
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    backlight_init();
    ili9488_init();
    backlight_set(60);

    ili9488_clear(COLOR_RED);
    gfx_text(10, 10, "Hello, world", COLOR_WHITE, COLOR_BLACK);

    while (true)
    {
        gpio_put(LED_PIN, 1);
        sleep_ms(500);

        gpio_put(LED_PIN, 0);
        sleep_ms(500);
    }

    return 0;
}
