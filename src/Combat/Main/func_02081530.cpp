#include <globaldefs.h>

extern "C" void func_0204f3bc(void* ctx, int value);

struct Struct_02081498 {
    char pad[4];
    short* entries;
    char pad2[0x14 - 8];
    unsigned char count;
};

// USA: func_02081530
extern "C" ARM void func_02081530(void* unused, void* ctx, struct Struct_02081498* list) {
    unsigned char i;
    if (list == NULL) {
        return;
    }
    for (i = 0; i < list->count; i++) {
        func_0204f3bc(ctx, list->entries[i]);
    }
}
