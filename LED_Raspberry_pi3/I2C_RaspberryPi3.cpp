#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>

int main() {
    // ��������� ���������� � ����� I2C
    int file;
    const char* filename = "/dev/i2c-1";
    if ((file = open(filename, O_RDWR)) < 0) {
        std::cerr << "Failed to open the I2C bus." << std::endl;
        return 1;
    }

    // ������������� ����� ���������� I2C
    int addr = 0x12; // �������� �� ����� ������ ����������
    if (ioctl(file, I2C_SLAVE, addr) < 0) {
        std::cerr << "Failed to acquire bus access and/or talk to slave." << std::endl;
        return 1;
    }

    // ���������� ������ ����
    uint8_t data[] = { 0x01, 0x02, 0x03, 0x04 }; // �������� �� ��� ������ ����
    int length = sizeof(data) / sizeof(data[0]);

    if (write(file, data, length) != length) {
        std::cerr << "Failed to write to the I2C bus." << std::endl;
        return 1;
    }

    // ��������� ���������� � ����� I2C
    close(file);

    std::cout << "Data sent successfully." << std::endl;

    return 0;
}
