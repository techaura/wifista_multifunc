#ifndef _MESSENGERS_DATATYPES_H
#define _MESSENGERS_DATATYPES_H
#include <string.h>
/*
Primitive file types typical for instant messengers are listed
*/

enum doctype{
    TEXT,
    MARKDOWN,
    HTML,
};

enum FileTypes{
    fAUDIO,
    fBIN,
    fGIF,
    fPHOTO,
    fTEXT,
    fVIDEO,
    fVOICE,
};

struct Telegram_msg{
    //unsigned char& UserID;

};

typedef struct SomeBot{
    unsigned char token[48];
    unsigned int chats[16]; //mean chat IDs
    unsigned int buffer_lng;
    unsigned int current_chat;

    void (*set_current_chat)(struct SomeBot* self, unsigned int newID);
}Bot;

void set_current_chat_impl(Bot* self, unsigned int newID);
void init_bot(Bot* bot, const char* token);
#endif
