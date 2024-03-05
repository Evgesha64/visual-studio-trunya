#include <iostream>
#include <pigpio.h>
#include <unistd.h>

#define SPI_CHANNEL 0
#define BAUD_RATE 24000000
#define FLAGS 0
#define LED_NUMBER 580

int flag = 0;

uint8_t txBuf[LED_NUMBER * 3];
void fillArrayWithColor(uint8_t red, uint8_t green, uint8_t blue) {
    for (int i = 0; i < LED_NUMBER * 3; i += 3) {
        txBuf[i] = red;     // ������� ��������� �����
        txBuf[i + 1] = green; // ������ ��������� �����
        txBuf[i + 2] = blue;  // ����� ��������� �����
    }
}



int main()
{
    if (gpioInitialise() < 0)
    {
        std::cout << "������ ������������� GPIO" << std::endl;
        return 1;
    }

    int handle = spiOpen(SPI_CHANNEL, BAUD_RATE, FLAGS);
    if (handle < 0)
    {
        std::cout << "������ �������� SPI: " << handle << std::endl;
        return 1;
    }
    
      fillArrayWithColor(0xfa, 0xfb, 0xfc);
     // spiWrite(handle, reinterpret_cast<char*>(&txBuf), 128);
      for (int i1 = 0; i1 < 1; i1++) {
          for (int i = 0; i < LED_NUMBER; i++) {

              //txBuf[i * 3] = 0;     // ������� ��������� �����
              //txBuf[i * 3 + 1] = 255; // ������ ��������� �����
              //txBuf[i * 3 + 2] = 0;  // ����� ��������� �����

              spiWrite(handle, reinterpret_cast<char*>(&txBuf), LED_NUMBER * 3);
              //txBuf[i * 3] = 0;     // ������� ��������� �����
              //txBuf[i * 3 + 1] = 0; // ������ ��������� �����
              //txBuf[i * 3 + 2] = 0;  // ����� ��������� �����

              usleep(100000); // �������� �� 1 �������
          }
      }
  

    spiClose(handle);
    gpioTerminate();

    return 0;
}