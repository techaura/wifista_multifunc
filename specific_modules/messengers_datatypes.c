#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "messengers_datatypes.h"

void set_current_chat_impl(Bot* self, unsigned int newID) {
    self->current_chat = newID;
    printf("Current chat updated to: %u\n", self->current_chat);
}

void init_bot(Bot* bot, const char* token){
    // fields init
    memset(bot->chats, 0, sizeof(bot->chats));
    bot->buffer_lng = 0;
    bot->current_chat = 0;

    // Copy getted token
    strncpy((char*)bot->token, token, sizeof(bot->token) - 1);
    bot->token[sizeof(bot->token) - 1] = '\0';

    // Set pointer
    bot->set_current_chat = set_current_chat_impl;
}