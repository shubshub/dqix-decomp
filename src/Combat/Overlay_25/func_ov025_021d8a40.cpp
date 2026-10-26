#include <globaldefs.h>

extern "C" void func_ov025_021d8ab8(void* arg0, void* arg1, int flag, int type, int idx);

struct Struct_ov025_021d8a40 {
    char pad[8];
    unsigned char f8;
    unsigned char unknown_9_;
};

// USA: func_ov025_021d8a40
extern "C" ARM void func_ov025_021d8a40(void* arg0, struct Struct_ov025_021d8a40* arg1) {
    int var0[2];
    var0[0] = arg1->unknown_9_;
    var0[1] = arg1->f8;
    for (int j = 0; j < 2; j++) {
        for (int k = 0; k < var0[j]; k++) {
            func_ov025_021d8ab8(arg0, arg1, 1, 6, j);
        }
    }
}
