#include <mosquitto.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MQTT_HOSTNAME "192.168.0.103"
#define MQTT_PORT 1883
#define MQTT_TOPIC "topic1"

void on_connect(struct mosquitto* mosq, void* obj, int reason_code)
{
    int rc = mosquitto_subscribe(mosq, NULL, MQTT_TOPIC, 1);
    if (rc != MOSQ_ERR_SUCCESS) {
        fprintf(stderr, "Error subscribing to topic: %s\n", mosquitto_strerror(rc));
        mosquitto_disconnect(mosq);
    }
}

void on_message(struct mosquitto* mosq, void* obj, const struct mosquitto_message* message)
{


    printf("Received message: %s\n", (const char*)message->payload);
}

int main()
{
    struct mosquitto* mosq;
    int rc;

    mosquitto_lib_init();

    mosq = mosquitto_new(NULL, true, NULL);
    if (!mosq) {
        fprintf(stderr, "Error: Out of memory.\n");
        return 1;
    }

    mosquitto_connect_callback_set(mosq, on_connect);
    mosquitto_message_callback_set(mosq, on_message);

    rc = mosquitto_connect(mosq, MQTT_HOSTNAME, MQTT_PORT, 60);
    if (rc != MOSQ_ERR_SUCCESS) {
        mosquitto_destroy(mosq);
        fprintf(stderr, "Error: %s\n", mosquitto_strerror(rc));
        return 1;
    }

    rc = mosquitto_loop_start(mosq);
    if (rc != MOSQ_ERR_SUCCESS) {
        mosquitto_destroy(mosq);
        fprintf(stderr, "Error: %s\n", mosquitto_strerror(rc));
        return 1;
    }

    pause();

    mosquitto_destroy(mosq);
    mosquitto_lib_cleanup();

    return 0;
}
