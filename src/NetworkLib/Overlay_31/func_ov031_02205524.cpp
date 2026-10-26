#include <globaldefs.h>
#include <NitroSDK/Mutex.h>

struct Struct_ov031_022054fc {
    unsigned short stackSize;
    unsigned char unknown_2_, priority;
};
struct Struct_ov031_02205620 { int size, offset; };
struct Struct_ov031_02205524_2 {
    char padding[0xe0];
    Mutex unknown_e0_;
    int unknown_f8_;
    unsigned short capacity;
    signed char unknown_fe_;
    unsigned char unknown_ff_;
    char unknown_100_[0xa];
    unsigned short tag;
    int unknown_10c_, unknown_110_;
    char storage[1];
};
struct Struct_ov031_02205524_3;
struct Struct_ov031_02205524_4 {
    char padding[0xe0];
    Mutex unknown_e0_;
    Struct_ov031_02205620 buffer;
    int unknown_100_;
    int unknown_104_, unknown_108_;
    Struct_ov031_02205524_3* owner;
    char storage[1];
};
struct Struct_ov031_02205524_3 {
    char padding[0x3c];
    Struct_ov031_02205620 receiveBuffer;
    int unknown_44_;
    Struct_ov031_02205620 sendBuffer, unknown_50_, unknown_58_;
    int unknown_60_;
    Struct_ov031_02205524_2* receiver;
    Struct_ov031_02205524_4* sender;
    char unknown_6c_[6];
    signed char unknown_72_, unknown_73_;
    char unknown_74_[12];
    char unknown_80_[1];
};
struct Struct_ov031_02205524 {
    signed char unknown_0_, unknown_1_;
    unsigned short unknown_2_, unknown_4_, unknown_6_;
    unsigned short unknown_8_, unknown_a_, sendBuffer, tag;
    Struct_ov031_022054fc unknown_10_, unknown_14_;
};
extern Struct_ov031_02205524_3* data_ov031_0224e1cc;
extern "C" int func_ov031_02205648(int, void*, Struct_ov031_022054fc*);
extern "C" int func_ov031_02205620(int, Struct_ov031_02205620*, int);

// USA: func_ov031_02205524
extern "C" ARM int func_ov031_02205524(Struct_ov031_02205524_3* self, Struct_ov031_02205524* params) {
    self->unknown_73_ = params->unknown_0_;
    self->unknown_72_ = params->unknown_1_;
    int cursor = (int)self->unknown_80_;
    if (params->unknown_2_) {
        Struct_ov031_02205524_2* receiver = (Struct_ov031_02205524_2*)cursor;
        self->receiver = receiver;
        receiver->capacity = params->unknown_4_;
        cursor = func_ov031_02205648((int)receiver->storage, receiver, &params->unknown_10_);
        cursor = func_ov031_02205620(cursor, &self->receiveBuffer, params->unknown_2_);
        cursor = func_ov031_02205620(cursor, &self->unknown_50_, params->unknown_8_);
        receiver->tag = params->tag;
        receiver->unknown_110_ = 0;
        receiver->unknown_10c_ = 0;
    }
    if (params->unknown_6_) {
        Struct_ov031_02205524_4* sender = (Struct_ov031_02205524_4*)cursor;
        self->sender = sender;
        sender->owner = self;
        cursor = func_ov031_02205648((int)sender->storage, sender, &params->unknown_14_);
        cursor = func_ov031_02205620(cursor, &self->sendBuffer, params->unknown_6_);
        cursor = func_ov031_02205620(cursor, &self->unknown_58_, params->unknown_a_);
        cursor = func_ov031_02205620(cursor, &sender->buffer, params->sendBuffer);
        sender->unknown_108_ = 0;
        sender->unknown_104_ = 0;
    } else self->sender = data_ov031_0224e1cc->sender;
    return cursor;
}
