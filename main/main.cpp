#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "nvs_flash.h"
#include "esp_event.h"
#include "esp_log.h"
#include "protocol_examples_common.h"
#include <ableton/Link.hpp>

unsigned int if_nametoindex(const char *ifname) {
    return 0;
}

char *if_indextoname(unsigned int ifindex, char *ifname) {
    return nullptr;
}

void link_task(void* user_param) {
    ESP_ERROR_CHECK(nvs_flash_init());
    tcpip_adapter_init();
    ESP_ERROR_CHECK(esp_event_loop_create_default());
    ESP_ERROR_CHECK(example_connect());

    ableton::Link link(120.0f);
    link.enable(true);
    while (true) {
        vTaskDelay(portMAX_DELAY);
    }
}

extern "C" void app_main() {
    xTaskCreatePinnedToCore(
        link_task,
        "link",
        8192,
        nullptr,
        10,
        nullptr, 1);
    vTaskDelete(nullptr);
}
