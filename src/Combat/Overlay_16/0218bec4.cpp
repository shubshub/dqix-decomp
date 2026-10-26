#include <globaldefs.h>

struct Struct_020e58dc_2 { int field0; int field4; int lo; int hi; int field10; };
struct Struct_020e58dc { Struct_020e58dc_2* base; int field4; int count; };

struct Struct_0200f374_2 {
    char pad0[0x10];
    unsigned char isSet;
    char unknown_11_;
    short id;
    unsigned int delay;
};

struct Struct_ov016_0219d0c0 {
    int unknown_0_;
    int pending;
    void* allocator;
    char context[4];
    int started;
    volatile int unknown_14_;
    int bank;
    int unknown_1c_;
    unsigned int unknown_20_;
    unsigned int frames;
    int position;
    short* unknown_2c_;
    short* unknown_30_;
    Struct_0200f374_2* info;
    int busy;
    int elapsed;
    unsigned long long unknown_40_;
    volatile long long unknown_48_;
    long long unknown_50_;
};

#if defined(jpn)
struct Struct_ov016_0219d0c0_2 {
    char pad0[4];
    int pending;
    volatile int unknown_8_;
    char unknown_c_[0x1c - 0xc];
    unsigned int unknown_1c_;
    char pad20[0x30 - 0x20];
    int elapsed;
    int toggle;
    int unknown_38_;
};
extern Struct_ov016_0219d0c0_2 data_ov016_0219d0c0;
#else
extern Struct_ov016_0219d0c0 data_ov016_0219d0c0;
#endif
void SleepCurrentContext(unsigned int ticks);
extern "C" Struct_020e58dc_2* func_020e58dc(Struct_020e58dc* list, int key);
extern "C" int func_ov016_0218be5c();
extern "C" int func_ov016_0218e708(void* object, void* destination, int stride, int mode);
extern "C" int func_ov016_0218e72c(void* object);
extern "C" void* __clear(void* destination, int size);
extern "C" int MessageSystem_GetInstance();
extern "C" void MessageSystem_FormatText(void* context, int unused, int id, int bufferAddress, int d, int e, int f);
extern "C" void func_ov016_0218e240(unsigned short* destination, char* text, unsigned short color, int x, int y, unsigned char arg5, int arg6, int limit);

// USA: func_ov016_0218bec4
extern "C" ARM void func_ov016_0218bec4(void* object, int arg1) {
#if defined(jpn)
    int var0;
    while (data_ov016_0219d0c0.unknown_8_ == 0) {
    }
    while (data_ov016_0219d0c0.elapsed <= (var0 = data_ov016_0219d0c0.unknown_38_)) {
        SleepCurrentContext(1);
    }
    data_ov016_0219d0c0.pending = 0;
    if (data_ov016_0219d0c0.unknown_1c_ < 2 ||
        data_ov016_0219d0c0.elapsed - var0 <= 1) {
        func_ov016_0218e708(object, (void*)func_ov016_0218be5c(), 0x100, 0);
        data_ov016_0219d0c0.unknown_8_ = 0;
    } else {
        func_ov016_0218e72c(object);
        data_ov016_0219d0c0.unknown_1c_ = 0;
        data_ov016_0219d0c0.toggle ^= 1;
    }
    data_ov016_0219d0c0.unknown_38_++;
    data_ov016_0219d0c0.unknown_1c_++;
#else
    char buffer[0x200];
    int var2;
    while (data_ov016_0219d0c0.unknown_14_ == 0) {
    }
    while (data_ov016_0219d0c0.elapsed <= (var2 = data_ov016_0219d0c0.unknown_1c_)) {
        SleepCurrentContext(1);
    }
    data_ov016_0219d0c0.pending = 0;
    if (data_ov016_0219d0c0.unknown_20_ < 2 ||
        data_ov016_0219d0c0.elapsed - var2 <= 1) {
        Struct_020e58dc_2* caption = func_020e58dc((Struct_020e58dc*)arg1, var2);
        func_ov016_0218e708(object, (void*)func_ov016_0218be5c(), 0x100, 0);
        if (caption != 0 && caption->field4 == 0) {
            __clear(buffer, 0x200);
            MessageSystem_FormatText((void*)MessageSystem_GetInstance(), 0xc, caption->field10, (int)buffer, 0xe3, 0, 1);
            func_ov016_0218e240((unsigned short*)func_ov016_0218be5c(), buffer, 0x7fff, 0, 0xa8, 1, 1, caption->field0);
            caption->field0 += 4;
        }
        data_ov016_0219d0c0.unknown_14_ = 0;
    } else {
        func_ov016_0218e72c(object);
        data_ov016_0219d0c0.unknown_20_ = 0;
    }
    data_ov016_0219d0c0.unknown_1c_++;
    data_ov016_0219d0c0.unknown_20_++;
#endif
}
