#include <globaldefs.h>

struct Struct_02093b54 {
#if defined(jpn)
    char data[11];
#else
    char data[48];
#endif
};
struct Struct_02093ad8 {
    Struct_02093b54 payload;
#if defined(jpn)
    unsigned char unknown_b_;
#endif
    short unknown_30_;
    signed char unknown_32_;
    unsigned char unknown_33_;
};

struct Struct_02093a58 {
    Struct_02093ad8 active[8];
    Struct_02093ad8 saved[8];
#if defined(jpn)
    char unknown_100_[0x13b - 0x100];
#else
    char unknown_340_[0x3cb - 0x340];
#endif
    signed char unknown_3cb_;
    signed char unknown_3cc_;
    unsigned char flags;
};

extern "C" void func_02093ad8(void*, Struct_02093ad8* source, Struct_02093ad8* destination, int count);

extern "C" ARM void func_02093a58(char* storage) {
    Struct_02093a58* queue = reinterpret_cast<Struct_02093a58*>(storage);
    func_02093ad8(queue, queue->active, queue->saved, queue->unknown_3cb_);
    queue->unknown_3cc_ = queue->unknown_3cb_;
    queue->unknown_3cb_ = 0;
    queue->flags &= ~4;
}
