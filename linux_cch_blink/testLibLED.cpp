#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "ws2811.h"

#define LED_COUNT  10  // Количество светодиодов
#define TARGET_FREQ  WS2811_TARGET_FREQ
#define GPIO_PIN  18
#define DMA  5

int main()
{
    ws2811_t ledstring = {
        .freq = TARGET_FREQ,
        .dmanum = DMA,
        .channel = {
            [0] = {
                .gpionum = GPIO_PIN,
                .count = LED_COUNT,
                .invert = 0,
                .brightness = 255,
            },
        },
    };

    if (ws2811_init(&ledstring)) {
        printf("Failed to initialize LED string\n");
        return -1;
    }

    for (int i = 0; i < LED_COUNT; i++) {
        // Set LED color to red
        ledstring.channel[0].leds[i] = 0x00FF0000;
        ws2811_render(&ledstring);
        

        // Set LED color to green
        ledstring.channel[0].leds[i] = 0x0000FF00;
        ws2811_render(&ledstring);
        

        // Set LED color to blue
        ledstring.channel[0].leds[i] = 0x000000FF;
        ws2811_render(&ledstring);
        
    }

    ws2811_fini(&ledstring);

    return 0;
}
