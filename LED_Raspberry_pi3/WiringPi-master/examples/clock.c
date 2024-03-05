#include <stdio.h>
#include <wiringPi.h>

#define PIN 21 // Номер GPIO-пина для генерации сигнала

int main(void) {
    if (wiringPiSetup() == -1) {
        printf("Ошибка инициализации WiringPi\n");
        return 1;
    }

    pinMode(PIN, OUTPUT);

    // Вычисление периода для заданной частоты
    int frequency = 1000; // 1 МГц
    int period = 1000 / frequency; // Период в микросекундах

    while (1) {
        digitalWrite(PIN, HIGH); // Устанавливаем высокий уровень
        delayMicroseconds(100); // Полупериод
        digitalWrite(PIN, LOW); // Устанавливаем низкий уровень
        delayMicroseconds(100); // Полупериод
    }

    return 0;
}
