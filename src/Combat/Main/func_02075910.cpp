#include <globaldefs.h>
#include "NitroSDK/Memory.h"

struct Struct_02108dfc {
    unsigned char flag;
    unsigned char pad1;
    unsigned short value;
    char* field4;
};

extern struct Struct_02108dfc data_02108dfc;
extern unsigned char data_020f0dc8;

extern "C" void func_020d0040(int mode);
extern "C" int func_020d06d4();
extern "C" void func_020d0050(int value);
int GetCardReadManagerSharedStatus();
extern "C" int func_020d0834();
extern "C" void func_020758a0(void* obj);
extern "C" void func_020d05ec(int a, int b, int c, void* d, int e, int f, int g, int h, int i);

// USA: func_02075910
extern "C" ARM int func_02075910(int a1, int a2, int a3, int a4) {
    if (data_02108dfc.field4) {
        if (a1 >= 0x8000) {
            a1 -= 0x8000;
        }
        VectorizedInvertedMemcpy(data_02108dfc.field4 + a1, (void*)a2, (unsigned int)a3);
        return 1;
    }

    if (data_020f0dc8 == 0) {
        return 0;
    }

    data_02108dfc.flag = 0;
    int result = 1;
    func_020d0040((int)data_02108dfc.value);

    int b = ((func_020d06d4() & 0xff) == 1);
    if (b) {
        func_020d05ec(a1, a2, a3, func_020758a0, 0, 1, 6, 1, 0);
    } else {
        b = ((func_020d06d4() & 0xff) == 2);
        if (b) {
            func_020d05ec(a1, a2, a3, func_020758a0, 0, 1, 6, 1, 0);
        } else {
            b = ((func_020d06d4() & 0xff) == 3);
            if (b) {
                func_020d05ec(a1, a2, a3, func_020758a0, 0, 1, 6, 1, 0);
            }
        }
    }

    if (a4) {
        if (GetCardReadManagerSharedStatus()) {
            result = 0;
        }
    } else {
        func_020d0834();
        if (GetCardReadManagerSharedStatus()) {
            result = 0;
        }
        func_020d0050((int)data_02108dfc.value);
        data_02108dfc.flag = 1;
    }

    return result;
}
