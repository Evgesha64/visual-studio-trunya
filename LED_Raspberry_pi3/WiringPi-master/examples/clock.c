#include <stdio.h>
#include <wiringPi.h>

#define PIN 21 // ����� GPIO-���� ��� ��������� �������

int main(void) {
    if (wiringPiSetup() == -1) {
        printf("������ ������������� WiringPi\n");
        return 1;
    }

    pinMode(PIN, OUTPUT);

    // ���������� ������� ��� �������� �������
    int frequency = 1000; // 1 ���
    int period = 1000 / frequency; // ������ � �������������

    while (1) {
        digitalWrite(PIN, HIGH); // ������������� ������� �������
        delayMicroseconds(100); // ����������
        digitalWrite(PIN, LOW); // ������������� ������ �������
        delayMicroseconds(100); // ����������
    }

    return 0;
}
