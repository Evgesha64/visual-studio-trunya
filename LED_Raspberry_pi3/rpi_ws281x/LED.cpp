#include <iostream>
//#include <vector>
//#include <chrono>
#include <thread>

extern "C" {
#include "ws2811.h"
}

#define TARGET_FREQ             WS2811_TARGET_FREQ
#define GPIO_PIN                18
#define DMA                     10
#define STRIP_TYPE              WS2811_STRIP_RGB

#define LED_COUNT               60  // Обновлено на 50 светодиодов

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
            .strip_type = STRIP_TYPE,
            .brightness = 255,
        }
    },
};

void running_fire() {
    static int position = 0;
    static uint32_t color[60]
    { 
        ((0 << 16) | (0 << 8) | 255),
        ((0 << 16) | (255 << 8) | 0),
        ((255 << 16) | (0 << 8) | 0)
    };
    // Очистка матрицы
    for (int i = 0; i < LED_COUNT; i++)
    {
        ledstring.channel[0].leds[i] = color[position];  // Красный цвет
    }
    //ledstring.channel[0].leds[i] = 0;
    // Установка "огня" в текущую позицию
    //std::cout << std::hex << ledstring.channel[0].leds[1] << std::endl;
    //std::cout << std::hex << ledstring.channel[0].leds[0] << std::endl;
    
    // Обновление позиции
    position++;
    if (position >= 3)
    {
        position = 0;
    }
}

int main() {
    ws2811_return_t ret;

    if ((ret = ws2811_init(&ledstring)) != WS2811_SUCCESS)
    {
        std::cerr << "ws2811_init failed: " << ws2811_get_return_t_str(ret) << "\n";
        return ret;
    }

    while (true)
    {
        running_fire();
        //std::cout << "_ ";
        if ((ret = ws2811_render(&ledstring)) != WS2811_SUCCESS)
        {
            std::cerr << "render failed: " << ws2811_get_return_t_str(ret) << "\n";
            break;
        }

        // 15 frames /sec
        //std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    ws2811_fini(&ledstring);

    return ret;
}
