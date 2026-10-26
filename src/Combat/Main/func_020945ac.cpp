#include <globaldefs.h>
#include "NitroSDK/Memory.h"

extern "C" void func_02093980(char* storage);

struct Struct_02093980 {
#if defined(jpn)
    char name[11];
    unsigned char unknownB;
#else
    char name[48];
#endif
    short unknown_30_;
    signed char partySlot;
    unsigned char flags;
};

struct Struct_02093428_5 {
    Struct_02093980 active[8];
    Struct_02093980 saved[8];
#if defined(jpn)
    char unknown_100_[0x13b - 0x100];
#else
    char unknown_340_[0x3cb - 0x340];
#endif
    signed char count;
    signed char unknown_3cc_;
    unsigned char flags;
};

// USA: func_020945ac
extern "C" ARM void func_020945ac(Struct_02093428_5* queue) {
    if (queue->count <= 0) {
        return;
    }
    int last = queue->count - 1;
    for (int i = 0; i < last; i++) {
        VectorizedInvertedMemcpy(&queue->active[i + 1], &queue->active[i], sizeof(Struct_02093980));
    }
    for (int i = last; i < 8; i++) {
        func_02093980((char*)&queue->active[i]);
    }
    if (queue->count > 0) {
        queue->count = queue->count - 1;
    }
    if (queue->count > 0) {
        queue->flags = (queue->flags | 1) & ~4;
    } else {
        queue->flags = queue->flags & ~4;
    }
}
