#include <globaldefs.h>
#include <NitroSDK/BGBases.h>

struct Struct_020e58dc_2 { int field0; int field4; int lo; int hi; int field10; };
struct Struct_020e58dc { Struct_020e58dc_2* base; int field4; int count; };

struct Struct_ov016_0219d144 {
    int pending;
    int bank;
    char context[4];
    int started;
    void* info;
    int busy;
    int elapsed;
    int unknown_1c_;
    unsigned int unknown_20_;
    unsigned int frames;
    int position;
    short* buffer;
    volatile int unknown_30_;
    unsigned int unknown_34_;
    unsigned int unknown_38_;
    unsigned int unknown_3c_;
    unsigned int unknown_40_;
    volatile unsigned int unknown_44_;
    volatile unsigned int unknown_48_;
};

#if defined(jpn)
struct Struct_ov016_0219d144_2 {
    int pending;
    int bank;
    char pad08[4];
    volatile int unknown_c_;
    char pad10[4];
    int elapsed;
    int unknown_18_;
    unsigned int unknown_1c_;
};
extern Struct_ov016_0219d144_2 data_ov016_0219d144;
#else
extern Struct_ov016_0219d144 data_ov016_0219d144;
#endif
void SleepCurrentContext(unsigned int ticks);
extern "C" Struct_020e58dc_2* func_020e58dc(Struct_020e58dc* list, int key);
extern "C" int func_ov016_0218e708(void* object, void* destination, int stride, int mode);
extern "C" int func_ov016_0218e72c(void* object);
extern "C" void func_ov016_0218e240(unsigned short* destination, char* text, unsigned short color, int x, int y, unsigned char arg5, int arg6, int limit);

// USA: func_ov016_0218d0d4
extern "C" ARM void func_ov016_0218d0d4(void* first, void* second, int arg2) {
#if defined(jpn)
    int var0;
    while (data_ov016_0219d144.unknown_c_ == 0) {
    }
    while (data_ov016_0219d144.elapsed <= (var0 = data_ov016_0219d144.unknown_18_)) {
        SleepCurrentContext(1);
    }
    data_ov016_0219d144.pending = 0;
    if (data_ov016_0219d144.unknown_1c_ < 2 ||
        data_ov016_0219d144.elapsed - var0 <= 1) {
        unsigned short* destination;
        if (data_ov016_0219d144.bank == 0) {
            destination = (unsigned short*)0x06820000;
        } else {
            destination = (unsigned short*)0x06800000;
        }
        func_ov016_0218e708(first, destination, 0x100, 0);
        if (data_ov016_0219d144.bank == 0) {
            destination = (unsigned short*)0x06600000;
        } else {
            destination = (unsigned short*)GetSubBG2ScreenBase();
        }
        func_ov016_0218e708(second, destination, 0x100, 0);
        data_ov016_0219d144.unknown_c_ = 0;
    } else {
        func_ov016_0218e72c(first);
        func_ov016_0218e72c(second);
        data_ov016_0219d144.bank ^= 1;
        data_ov016_0219d144.unknown_1c_ = 0;
    }
    data_ov016_0219d144.unknown_18_++;
    data_ov016_0219d144.unknown_1c_++;
#else
    int var2;
    while (data_ov016_0219d144.unknown_30_ == 0) {
    }
    while (data_ov016_0219d144.elapsed <= (var2 = data_ov016_0219d144.unknown_1c_)) {
        SleepCurrentContext(1);
    }
    data_ov016_0219d144.pending = 0;
    if (data_ov016_0219d144.unknown_20_ < 2 ||
        data_ov016_0219d144.elapsed - var2 <= 1) {
        Struct_020e58dc_2* caption = func_020e58dc((Struct_020e58dc*)arg2, var2);
        unsigned short* destination;
        if (data_ov016_0219d144.bank == 0) {
            destination = (unsigned short*)0x06820000;
        } else {
            destination = (unsigned short*)0x06800000;
        }
        func_ov016_0218e708(first, destination, 0x100, 0);
        if (caption != 0 && caption->field4 == 0) {
            func_ov016_0218e240(destination, (char*)caption->field10, 0x7fff, 0, 0xa8, 1, 1, caption->field0);
            caption->field0 += 4;
        }
        if (data_ov016_0219d144.bank == 0) {
            destination = (unsigned short*)0x06600000;
        } else {
            destination = (unsigned short*)GetSubBG2ScreenBase();
        }
        func_ov016_0218e708(second, destination, 0x100, 0);
        if (caption != 0 && caption->field4 == 1) {
            func_ov016_0218e240(destination, (char*)caption->field10, 0xffff, 0, 0xa8, 1, 1, caption->field0);
            caption->field0 += 4;
        }
        data_ov016_0219d144.unknown_30_ = 0;
    } else {
        func_ov016_0218e72c(first);
        func_ov016_0218e72c(second);
        data_ov016_0219d144.unknown_20_ = 0;
    }
    data_ov016_0219d144.unknown_1c_++;
    data_ov016_0219d144.unknown_20_++;
#endif
}
