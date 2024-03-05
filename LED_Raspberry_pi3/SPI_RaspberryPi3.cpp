#include <iostream>
#include <wiringPi.h>
#include <wiringPiSPI.h>
#include <unistd.h>
#define LED_NUMBER 580

 uint8_t txBuf[LED_NUMBER * 3];
void fillArrayWithColor(uint8_t red, uint8_t green, uint8_t blue) {
    for (int i = 0; i < LED_NUMBER * 3; i += 3) {
        txBuf[i] = red;     // Красный компонент цвета
        txBuf[i + 1] = green; // Зелёный компонент цвета
        txBuf[i + 2] = blue;  // Синий компонент цвета
    }
}

int main() {
    int spiChannel0 = 0; // CE0
    int speed = 500000; // 1 MHz
    

    if (wiringPiSPISetup(spiChannel0, speed) == -1) {
        std::cerr << "Could not initialize SPI for channel 0!" << std::endl;
        return -1;
    }

    
    for (int i1 = 0; i1 < 1; i1++) {
        for (int i = 0; i < LED_NUMBER; i++) {
            fillArrayWithColor(0, 0, 50);
            ////txBuf[i * 3] = 0;     // Красный компонент цвета
            //txBuf[i * 3 + 1] = 255; // Зелёный компонент цвета
            //txBuf[i * 3 + 2] = 0;  // Синий компонент цвета

            wiringPiSPIDataRW(spiChannel0, reinterpret_cast<unsigned char*>(&txBuf), LED_NUMBER * 3);
            //txBuf[i * 3] = 255;     // Красный компонент цвета
            //txBuf[i * 3 + 1] = 0; // Зелёный компонент цвета
            //txBuf[i * 3 + 2] = 0;  // Синий компонент цвета
           
            usleep(500000); // Задержка на 1 секунду
            fillArrayWithColor(0, 50, 0);
            wiringPiSPIDataRW(spiChannel0, reinterpret_cast<unsigned char*>(&txBuf), LED_NUMBER * 3);
            
            usleep(500000); // Задержка на 1 секунду
        }
    }
    
    
      
    

    return 0;
}

 
////Вариант с мультиплексором 74HC4051
//#include <iostream>
//#include <wiringPi.h>
//#include <wiringPiSPI.h>
//#include <unistd.h>
//
//#define MUX_A 0 // GPIO pin connected to A
//#define MUX_B 1 // GPIO pin connected to B
//#define MUX_C 2 // GPIO pin connected to C
//#define SPI_CHANNEL 0 // SPI channel
//#define SPEED 1000000 // 1 MHz
//
//void selectArduino(int arduino) {
//    digitalWrite(MUX_A, arduino & 0x01);
//    digitalWrite(MUX_B, (arduino >> 1) & 0x01);
//    digitalWrite(MUX_C, (arduino >> 2) & 0x01);
//}
//
//int main() {
//    unsigned char data[1];
//
//    if (wiringPiSetup() == -1) {
//        std::cerr << "Could not initialize wiringPi!" << std::endl;
//        return -1;
//    }
//
//    if (wiringPiSPISetup(SPI_CHANNEL, SPEED) == -1) {
//        std::cerr << "Could not initialize SPI!" << std::endl;
//        return -1;
//    }
//
//    pinMode(MUX_A, OUTPUT);
//    pinMode(MUX_B, OUTPUT);
//    pinMode(MUX_C, OUTPUT);
//
//    while (true) {
//        for (int i = 0; i < 4; ++i) {
//            selectArduino(i);
//            data[0] = i + 1;
//            wiringPiSPIDataRW(SPI_CHANNEL, data, 1);
//            std::cout << "Received from Arduino " << i << ": " << static_cast<int>(data[0]) << std::endl;
//            usleep(1000000); // sleep for 1 second
//        }
//    }
//
//    return 0;
//}
