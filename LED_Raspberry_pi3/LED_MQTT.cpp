#include <mosquitto.h> //Библиотека MQTT клиент 
#include <stdio.h>     //Стандартная библиотека ввода-вывода в C и C++.
#include <stdlib.h>    //Библиотека языка C, которая содержит функции для выполнения различных операций, включая обработку строк, математические вычисления, управление памятью, обработку окружения и другие.
#include <string.h>    //Библиотека которая содержит функции для обработки строк.

#include <cstring>     //Библиотека которая содержит функции для работы со строками и блоками памяти.
#include <iostream>    //Библиотека которая включает в программу стандартную библиотеку ввода-вывода.
#include <thread>      //Библиотека предоставляет функции и классы, которые позволяют создавать и управлять потоками выполнения в программе.
extern "C" {           //"extern" в C++ используется для указания компилятору, что включаемые функции написаны на языке C
#include "ws2811.h"
}

#define MQTT_HOSTNAME "192.168.1.3"   // IP адрес брокера.
#define MQTT_PORT 1883                  // Порт брокера.    
#define MQTT_TOPIC1 "topic_num_RGB"      // Топик для приёма изображения от брокера.
#define MQTT_TOPIC2 "topic_num_RGB2" 
#define MQTT_TOPIC3 "topic_stop" 
#define MQTT_TOPIC4 "topicCallback"     // Топик для обратной связи. 

#define TARGET_FREQ             WS2811_TARGET_FREQ // Устанавливаем целевую частоту для светодиодной ленты WS2811.
#define GPIO_PIN                18                 // Устанавливаем номер GPIO (General Purpose Input/Output) пина.
#define DMA                     10                 // Устанавливаем номер канала Direct Memory Access (DMA), который будет использоваться для отправки данных на светодиодную ленту.
#define STRIP_TYPE              WS2811_STRIP_RGB   // Устанавливаем тип светодиодной ленты.
#define LED_COUNT               600  // Обновлено на 50 светодиодов
// Здесь создается экземпляр структуры ws2811_t, которая используется для настройки и управления светодиодной лентой WS2811.
void message_publish(struct mosquitto* mosq, const char* msg);
ws2811_t ledstring = 
{
    .freq = TARGET_FREQ,
    .dmanum = DMA,
    .channel =
    {
        //Здесь настраивается первый канал управления светодиодами.
        [0] =
        {
            .gpionum = GPIO_PIN,
            .invert = 0,
            .count = LED_COUNT,
            .strip_type = STRIP_TYPE,
            .brightness = 255,
        },
        [1] =
        {
            .gpionum = 13,
            .invert = 0,
            .count = LED_COUNT,
            .strip_type = WS2811_STRIP_GRB,
            .brightness = 255,
        }
    },
};
 // Функция on_connect вызывается, когда клиент MQTT подключается к брокеру MQTT.
void on_connect(struct mosquitto* mosq, void* obj, int reason_code)
{
    int rc = mosquitto_subscribe(mosq, NULL, MQTT_TOPIC1, 1);
    rc = mosquitto_subscribe(mosq, NULL, MQTT_TOPIC2, 1);
    rc = mosquitto_subscribe(mosq, NULL, MQTT_TOPIC3, 1);
    if (rc != MOSQ_ERR_SUCCESS) {
        fprintf(stderr, "Error subscribing to topic: %s\n", mosquitto_strerror(rc));
        mosquitto_disconnect(mosq);
    }
}

void on_message(struct mosquitto* mosq, void* obj, const struct mosquitto_message* message)
{
    
        if (std::string(message->topic) == "topic_num_RGB") {
            //Проверяем, соответствует ли длина полученного сообщения ожидаемому размеру
            if (message->payloadlen != LED_COUNT * sizeof(uint32_t)) {
                std::cout << "12345";
                std::cout << "Incorrect message size  " << message->payloadlen << " a nado " << LED_COUNT * sizeof(uint32_t) << std::endl;

                char msg[256]; // Буфер для форматированной строки. 
                snprintf(msg, sizeof(msg), "Incorrect message size %d a nado %lu", message->payloadlen, LED_COUNT * sizeof(uint32_t));
                message_publish(mosq, msg);
                return;

            }

            std::memcpy(ledstring.channel[0].leds, message->payload, LED_COUNT * sizeof(uint32_t));
            std::memcpy(ledstring.channel[1].leds, message->payload, LED_COUNT * sizeof(uint32_t));
            ws2811_render(&ledstring);

            char* msg = "1";
            message_publish(mosq, msg);
   
        }else if(std::string(message->topic) == "topic_stop")
        {
            char* msg = "MQTT_LED Stop";
            message_publish(mosq, msg);
            exit(0);
            
        }
        else
        {
             char* msg = "0";
             message_publish(mosq,msg);
        }
                
}
void message_publish(struct mosquitto* mosq, const char* msg) {
    int ret = mosquitto_publish(mosq, NULL, MQTT_TOPIC4, strlen(msg), msg, 0, false);
    if (ret != MOSQ_ERR_SUCCESS) {
        std::cout << "Error: Could not publish message. %s\n"<< mosquitto_strerror(ret);
    }

}
void running_fire() {
    static int position = 0;
    static uint32_t color[60]
    {
        ((0 << 16) | (0 << 8) | 255),
        ((0 << 16) | (255 << 8) | 0),
        ((255 << 16) | (0 << 8) | 0),
        ((0 << 16) | (0 << 8) | 255),
        ((0 << 16) | (255 << 8) | 0)
        
    };
    // Очистка матрицы
   // for (int i = 0; i < LED_COUNT; i++)
    //{
        ledstring.channel[0].leds = color;  // Красный цвет
   // }
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

int main()
{
    
    struct mosquitto* mosq;
    int rc;

    mosquitto_lib_init();

    mosq = mosquitto_new(NULL, true, NULL);
    if (!mosq) {
       
        std::cout << "Error: Out of memory.\n" ;
        return 1;
    }
    
    mosquitto_connect_callback_set(mosq, on_connect);
    mosquitto_message_callback_set(mosq, on_message);

   
    if (mosquitto_connect(mosq, MQTT_HOSTNAME, MQTT_PORT, 60) != MOSQ_ERR_SUCCESS) {
        mosquitto_destroy(mosq);
        std::cout << "Error: %s\n" << mosquitto_strerror(rc);
        return 1;
    }

    ws2811_return_t ret;
    delete[] ledstring.channel[0].leds;
    delete[] ledstring.channel[1].leds;
    ledstring.channel[0].leds = new uint32_t[LED_COUNT]; // Выделяем память под массив светодиодов.
    if (ledstring.channel[0].leds == nullptr) {
        std::cerr << "Error allocating memory for LEDs\n";
        return 1;
    }

    ledstring.channel[1].leds = new uint32_t[LED_COUNT];
    if (ledstring.channel[1].leds == nullptr) {
        std::cerr << "Error allocating memory for LEDs\n";
        return 1;
    }
    if ((ret = ws2811_init(&ledstring)) != WS2811_SUCCESS)
    {
        std::cerr << "ws2811_init failed: " << ws2811_get_return_t_str(ret) << "\n";
        return ret;
    }

    /*rc = mosquitto_loop_start(mosq);
    if (rc != MOSQ_ERR_SUCCESS) {
        mosquitto_destroy(mosq);
        fprintf(stderr, "Error: %s\n", mosquitto_strerror(rc));
        return 1;
    }*/
    //running_fire();
    // ws2811_render(&ledstring);
    
     mosquitto_loop_forever(mosq, 0, 1);
     mosquitto_destroy(mosq);
     mosquitto_lib_cleanup();

    return 0;
}
