#include <globaldefs.h>
#include "NitroSDK/Memory.h"

extern "C" void func_020d0040(int mode);
extern "C" int func_020d06d4();
extern "C" void func_020d0050(int value);
extern "C" void func_020758a4(void* obj);
int GetCardReadManagerSharedStatus();
extern "C" int func_020d0834();
extern "C" void func_020d05ec(const void* src, int offset, unsigned int length, void (*proc)(void*), int a4, int a5, int a6, int a7, int a8);

struct Struct_02108dfc {
    unsigned char flag;
    unsigned char pad1;
    unsigned short value;
    void* base;
};

extern struct Struct_02108dfc data_02108dfc;
extern unsigned char data_020f0dc8;

// USA: func_02075acc
extern "C" ARM int func_02075acc(int offset, void* src, unsigned int length, int arg3) {
    int result;
    int var1;
    int var2;
    int var3;

    if (data_02108dfc.base != 0) {
        if (offset >= 0x8000) {
            offset -= 0x8000;
        }
        VectorizedInvertedMemcpy(src, (void*)((unsigned char*)data_02108dfc.base + offset), length);
        return 1;
    }

    if (data_020f0dc8 == 0) {
        return 0;
    }

    data_02108dfc.flag = 0;
    result = 1;
    func_020d0040((int)data_02108dfc.value);

    var1 = (func_020d06d4() & 0xff) == 1;
    if (var1) {
        func_020d05ec(src, offset, length, func_020758a4, 0, 1, 8, 10, 2);
    } else {
        var2 = (func_020d06d4() & 0xff) == 2;
        if (var2) {
            func_020d05ec(src, offset, length, func_020758a4, 0, 1, 7, 10, 2);
        } else {
            var3 = (func_020d06d4() & 0xff) == 3;
            if (var3) {
                func_020d05ec(src, offset, length, func_020758a4, 0, 1, 8, 10, 2);
            }
        }
    }

    if (arg3 != 0) {
        if (GetCardReadManagerSharedStatus() != 0) {
            result = 0;
        }
    } else {
        func_020d0834();
        if (GetCardReadManagerSharedStatus() != 0) {
            result = 0;
        }
        func_020d0050((int)data_02108dfc.value);
        data_02108dfc.flag = 1;
    }

    return result;
}
