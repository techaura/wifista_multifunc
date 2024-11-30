/*
Primitive file types typical for instant messengers are listed
*/
enum FileTypes{
    AUDIO,
    BIN,
    GIF,
    PHOTO,
    TEXT,
    VIDEO,
    VOICE,
};

struct Telegram_msg{
    String& userID;
}