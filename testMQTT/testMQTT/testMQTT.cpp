#include <mosquittopp.h>
#include <iostream>



int main() {
    
    libmosq_EXPORT int mosquitto_lib_init();
    
    std::cout << MOSQ_ERR_SUCCESS;
    std::cout << MOSQ_ERR_UNKNOWN;
    libmosq_EXPORT struct mosquitto* mosquitto_new(const 	char* id,
        bool 		clean_session,
        void* obj);








    return 0;
}
