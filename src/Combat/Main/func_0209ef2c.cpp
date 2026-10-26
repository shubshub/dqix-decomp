#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_0209ef2c {
    char pad0[4];
    void* unknown_4_;      // +4
    char pad1[0x98 - 8];
    int unknown_98_;       // +0x98
    char unknown_9c_[0x400]; // +0x9c
    int unknown_49c_;      // +0x49c
    char unknown_4a0_[0x400];// +0x4a0
};

// USA: func_0209ef2c
extern "C" ARM void func_0209ef2c(struct Struct_0209ef2c* obj, int mode, int slot, int id) {
    int var0 = 0x40;
    if (mode == 0) {
        int count;
        int i;
        obj->unknown_98_ = 0;
        count = *(unsigned char*)((char*)obj->unknown_4_ + 0x8e07);
        for (i = 0; i < count; i++) {
            char* elem = (char*)obj->unknown_4_ + 0x5c60 + i * var0;
            if (elem != 0 && *(short*)(elem + 0x30 + slot * 2) == id) {
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
        if (*(short*)(elem + 0x30 + slot * 2) == id) {
            int idx = obj->unknown_49c_++;
            memcpy(obj->unknown_4a0_ + idx * var0, elem, var0);
        }
    }
    }
    obj->unknown_98_ = obj->unknown_49c_;
    memcpy(obj->unknown_9c_, obj->unknown_4a0_, 0x400);
}
