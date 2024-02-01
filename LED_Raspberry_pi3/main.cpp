#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "ws2811.h"

#define TARGET_FREQ             WS2811_TARGET_FREQ
#define GPIO_PIN                18
#define DMA                     5
#define LED_COUNT               8

ws2811_t ledstring =
{
    .freq = TARGET_FREQ,
    .dmanum = DMA,
    .channel =
    {
        [0] =
        {
            .gpionum = GPIO_PIN,
            .invert = 0,
            .count = LED_COUNT,
            .strip_type = WS2811_STRIP_GBR,
            .brightness = 255,
        },
        [1] =
        {
            .gpionum = 0,
            .invert = 0,
            .count = 0,
            .brightness = 0,
        },
    },
};


int main()
{
    if (ws2811_init(&ledstring))
    {
        printf("Failed to initialize LED strip\n");
        return -1;
    }

    for (int i = 0; i < LED_COUNT; i++)
    {
        ledstring.channel[0].leds[i] = 0x00200000;  // Red color
    }

    if (ws2811_render(&ledstring))
    {
        printf("Failed to render LED strip\n");
        return -1;
    }

    //sleep(1);

    for (int i = 0; i < LED_COUNT; i++)
    {
        ledstring.channel[0].leds[i] = 0x00002000;  // Green color
    }

    if (ws2811_render(&ledstring))
    {
        printf("Failed to render LED strip\n");
        return -1;
    }

    //sleep(1);

    for (int i = 0; i < LED_COUNT; i++)
    {
        ledstring.channel[0].leds[i] = 0x00000020;  // Blue color
    }

    if (ws2811_render(&ledstring))
    {
        printf("Failed to render LED strip\n");
        return -1;
    }

    //sleep(1);

    for (int i = 0; i < LED_COUNT; i++)
    {
        ledstring.channel[0].leds[i] = 0x00000000;  // Turn off
    }

    if (ws2811_render(&ledstring))
    {
        printf("Failed to render LED strip\n");
        return -1;
    }

    ws2811_fini(&ledstring);

    return 0;
}
