#include <globaldefs.h>
#include "std_library_functions.h"

void CleanInvalidateCacheRange(const void* addr, unsigned int size);

struct HeaderAt0204ab4c {
    char pad0[2];
    unsigned short unknown_2_;
};

struct BufferAt0204ab4c {
    char pad0[8];
    unsigned int unknown_8_;
    char blocks[0x20 * 16];
};

// USA: func_0204ab4c
extern "C" ARM void func_0204ab4c(struct HeaderAt0204ab4c* header, struct BufferAt0204ab4c* buffer) {
    unsigned int var0;
    int var1;
    int i;
    memcpy(&var0, &buffer->unknown_8_, 4);
    if (header->unknown_2_ == 0xffff) {
        CleanInvalidateCacheRange((const void*)((int)&buffer->blocks[0]), var0);
        return;
    }
    var1 = header->unknown_2_ & 0xff;
    for (i = 0; i < 16; i++) {
        if (var1 & 1) {
            CleanInvalidateCacheRange((const void*)((int)&buffer->blocks[i * 0x20]), 0x20);
        }
        var1 = (var1 >> 1) & 0xff;
    }
}
