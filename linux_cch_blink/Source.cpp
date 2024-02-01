#include <iostream>
#include <pigpio.h>

int main()
{
    // Инициализация библиотеки pigpio
    if (gpioInitialise() < 0)
    {
        std::cout << "Не удалось инициализировать pigpio" << std::endl;
        return 1;
    }

    // Установка режима пина GPIO
    int gpioPin = 21; // Пример: использование пина GPIO 17
    gpioSetMode(gpioPin, PI_OUTPUT);
    // Включение пина
    for (int i = 0; i < 50; i++) {
       
        
        gpioWrite(gpioPin, 1); // Установка высокого уровня сигнала

        // Задержка
        time_sleep(0.1); // Пауза в 1 секунду

        // Выключение пина
        gpioWrite(gpioPin, 0); // Установка низкого уровня сигнала
        // Задержка
        time_sleep(0.1); // Пауза в 1 секунду

    }
    // Освобождение ресурсов
    gpioTerminate();

    return 0;
}