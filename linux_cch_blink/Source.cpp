#include <iostream>
#include <pigpio.h>

int main()
{
    // ������������� ���������� pigpio
    if (gpioInitialise() < 0)
    {
        std::cout << "�� ������� ���������������� pigpio" << std::endl;
        return 1;
    }

    // ��������� ������ ���� GPIO
    int gpioPin = 21; // ������: ������������� ���� GPIO 17
    gpioSetMode(gpioPin, PI_OUTPUT);
    // ��������� ����
    for (int i = 0; i < 50; i++) {
       
        
        gpioWrite(gpioPin, 1); // ��������� �������� ������ �������

        // ��������
        time_sleep(0.1); // ����� � 1 �������

        // ���������� ����
        gpioWrite(gpioPin, 0); // ��������� ������� ������ �������
        // ��������
        time_sleep(0.1); // ����� � 1 �������

    }
    // ������������ ��������
    gpioTerminate();

    return 0;
}