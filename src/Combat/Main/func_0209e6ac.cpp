#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_0209e6ac {
    char pad0[4];
    void* unknown_4_;
    char pad1[0x98 - 8];
    int unknown_98_;
    char unknown_9c_[0x400];
    int unknown_49c_;
    char unknown_4a0_[0x400];
};

// USA: func_0209e6ac
extern "C" ARM void func_0209e6ac(struct Struct_0209e6ac* obj, int mode, int mask) {
    int var0 = 0x40;
    if (mode == 0) {
        int count;
        int i;
        obj->unknown_98_ = 0;
        count = *(unsigned char*)((char*)obj->unknown_4_ + 0x8e07);
        for (i = 0; i < count; i++) {
            char* elem = (char*)obj->unknown_4_ + 0xc60 + 0x5000 + i * var0;
            if (elem != 0 && (*(int*)(elem + 4) & mask)) {
                int idx = obj->unknown_98_++;
                memcpy(obj->unknown_9c_ + idx * var0, elem, var0);
            }
        }
        return;
    }
    obj->unknown_49c_ = 0;
    memset(obj->unknown_4a0_, 0, 0x400);
    {
    int i;
    for (i = 0; i < obj->unknown_98_; i++) {
        char* elem = obj->unknown_9c_ + i * var0;
        if (*(int*)(elem + 4) & mask) {
            int idx = obj->unknown_49c_++;
            memcpy(obj->unknown_4a0_ + idx * var0, elem, var0);
        }
    }
    }
    obj->unknown_98_ = obj->unknown_49c_;
    memcpy(obj->unknown_9c_, obj->unknown_4a0_, 0x400);
}