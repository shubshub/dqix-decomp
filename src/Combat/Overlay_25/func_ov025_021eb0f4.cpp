#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"


struct Struct_02000c9c_79 {
    char pad0[0x30];
    short key;
    signed char val;
    char unknown_33_[0x44 - 0x33];
};

struct Struct_ov025_021eb0f4 {
    char pad0[0x124];
    int count;
    struct Struct_02000c9c_79 entries[1];
};


struct Struct_ov025_021eb0f4_2 {
    char pad[0x582];
    unsigned char count;
    char pad2[1];
    unsigned short arr[1];
};

// USA: func_ov025_021eb0f4
extern "C" ARM int func_ov025_021eb0f4(struct Struct_ov025_021eb0f4_2* obj) {
    struct Struct_ov025_021eb0f4* list = (struct Struct_ov025_021eb0f4*)(int)BackgroundLoader::GetInstance();
    unsigned short* p = obj->arr;
    for (int i = 0; i < obj->count; p++, i++) {
        if (!((BackgroundLoader*)(list))->GetTaskStatus((int)(*p))) {
            return 0;
        }
    }
    return 1;
}
