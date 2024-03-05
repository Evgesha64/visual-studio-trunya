#include <fcntl.h> // ��� open()
#include <unistd.h> // ��� close()
#include <sys/ioctl.h>
#include <linux/spi/spidev.h>
#include <cstring> // ��� memset()
#include <cstdint>

#define LED_NUMBER 580 // ���������� �����������
#define SPI_PATH "/dev/spidev0.0" // ���� � SPI ����������

// ������� ��� ���������� ������� �������
uint8_t txBuf1[LED_NUMBER * 3];
void fillArrayWithColor(uint8_t red, uint8_t green, uint8_t blue) {
    for (int i = 0; i < LED_NUMBER * 3; i += 3) {
        txBuf1[i] = red;     // ������� ��������� �����
        txBuf1[i + 1] = green; // ������ ��������� �����
        txBuf1[i + 2] = blue;  // ����� ��������� �����
    }
}

int main() {
    int spi_fd = open(SPI_PATH, O_RDWR); // �������� SPI ����������

    if (spi_fd < 0) {
        // ��������� ������ ��������
        return -1;
    }

   
    //memset(txBuf, 0, sizeof(txBuf)); // ������� �������
    
    // ���������� ������� �������� ������
    fillArrayWithColor(0xFF, 0x00, 0x00); // ������: ������� ����

    struct spi_ioc_transfer transfer;
    memset(&transfer, 0, sizeof(transfer)); // ������� ��������� ����� ��������������
    transfer.tx_buf = (unsigned long)txBuf1;
    transfer.rx_buf = (unsigned long)NULL; // �� ������� ��������� ������
    transfer.len = sizeof(txBuf1);
    transfer.speed_hz = 100000; // �������� �������� ������
    transfer.bits_per_word = 8; // ���������� ��� � �����

    ioctl(spi_fd, SPI_IOC_MESSAGE(1), &transfer); // �������� ������

   

    // �������� ����������
    close(spi_fd);

    return 0;
}
