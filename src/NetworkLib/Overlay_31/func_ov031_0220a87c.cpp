#include <globaldefs.h>
#include "NitroSDK/Memory.h"

struct Struct_0200fd14_2 {
    unsigned char type;
    unsigned char unknown_1_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
    unsigned char unknown_4_;
    unsigned char payload[1];
};
struct Struct_ov031_0220a87c { unsigned char unknown_0_[0x8]; unsigned char type, unknown_9_; unsigned char unknown_a_[2]; void* context; };

extern void* (*data_ov031_0224c994)(unsigned int);
extern void (*data_ov031_0224c9c0)(void*);
extern "C" int func_ov031_0220963c(void* context, Struct_0200fd14_2* record);
extern "C" unsigned int func_ov031_022037a8(const void* first, unsigned int arg1, const void* second, unsigned int arg3, Struct_ov031_0220a87c* arg4);

static inline int inline_ov031_0220a87c(const unsigned char* first, unsigned int arg1, const unsigned char* second, unsigned int arg3, Struct_ov031_0220a87c* arg4, void* context) {
    int var0;
    int head;
    int tail;
    int var3 = 0;
    int remaining = arg1 + arg3;
    do {
        var0 = remaining > 0xb4f ? 0xb4f : remaining;
        Struct_0200fd14_2* record = (Struct_0200fd14_2*)data_ov031_0224c994(var0 + 0x19);
        if (record == NULL) return var3;
        head = arg1 >= var0 ? var0 : arg1;
        tail = var0 - head;
        VectorizedInvertedMemcpy(first, record->payload, head);
        first += head;
        arg1 -= head;
        VectorizedInvertedMemcpy(second, record->payload + head, tail);
        second += tail;
        record->type = 0x17;
        record->unknown_1_ = 3;
        record->unknown_2_ = 0;
        record->unknown_3_ = var0 >> 8;
        record->unknown_4_ = var0;
        unsigned int length = func_ov031_0220963c(context, record);
        if (func_ov031_022037a8(record, length, 0, 0, arg4) < length) var0 = 0;
        data_ov031_0224c9c0(record);
        remaining -= var0;
        var3 += var0;
    } while (remaining != 0 && var0 != 0);
    return var3;
}

// USA: func_ov031_0220a87c
extern "C" ARM int func_ov031_0220a87c(const unsigned char* first, unsigned int arg1, const unsigned char* second, unsigned int arg3, Struct_ov031_0220a87c* arg4) {
    return inline_ov031_0220a87c(first, arg1, second, arg3, arg4, arg4->context);
}
