#include <fcntl.h> // для open()
#include <unistd.h> // для close()
#include <sys/ioctl.h>
#include <linux/spi/spidev.h>
#include <cstring> // для memset()
#include <cstdint>

#define LED_NUMBER 580 // Количество светодиодов
#define SPI_PATH "/dev/spidev0.0" // Путь к SPI устройству

// Функция для заполнения массива цветами
uint8_t txBuf1[LED_NUMBER * 3];
void fillArrayWithColor(uint8_t red, uint8_t green, uint8_t blue) {
    for (int i = 0; i < LED_NUMBER * 3; i += 3) {
        txBuf1[i] = red;     // Красный компонент цвета
        txBuf1[i + 1] = green; // Зелёный компонент цвета
        txBuf1[i + 2] = blue;  // Синий компонент цвета
    }
}

int main() {
    int spi_fd = open(SPI_PATH, O_RDWR); // Открытие SPI устройства

    if (spi_fd < 0) {
        // Обработка ошибки открытия
        return -1;
    }

   
    //memset(txBuf, 0, sizeof(txBuf)); // Очистка массива
    
    // Заполнение массива заданным цветом
    fillArrayWithColor(0xFF, 0x00, 0x00); // Пример: красный цвет

    struct spi_ioc_transfer transfer;
    memset(&transfer, 0, sizeof(transfer)); // Очистка структуры перед использованием
    transfer.tx_buf = (unsigned long)txBuf1;
    transfer.rx_buf = (unsigned long)NULL; // Не ожидаем получения данных
    transfer.len = sizeof(txBuf1);
    transfer.speed_hz = 100000; // Скорость передачи данных
    transfer.bits_per_word = 8; // Количество бит в слове

    ioctl(spi_fd, SPI_IOC_MESSAGE(1), &transfer); // Передача данных

   

    // Закрытие устройства
    close(spi_fd);

    return 0;
}
