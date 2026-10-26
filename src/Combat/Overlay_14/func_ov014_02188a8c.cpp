#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_02097418;
extern "C" ARM void* func_02097418(struct Struct_02097418* obj);

struct Struct_02097420;
extern "C" ARM int func_02097420(struct Struct_02097420* obj);

struct Struct_ov014_02188a8c {
    char pad0[0xc];
    short f0c;
    char unknown_e_[5];
    unsigned char unknown_13_0_:1;
    unsigned char unknown_13_1_:1;
    unsigned char unknown_13_2_:6;
    char unknown_14_[6];
    short unknown_1a_;
    char unknown_1c_[4];
};

// USA: func_ov014_02188a8c
extern "C" ARM void func_ov014_02188a8c(void* self, short key) {
    Struct_ov014_02188a8c* arr = (Struct_ov014_02188a8c*)func_02097418((struct Struct_02097418*)((char*)self + 0xa4));
    if (!arr) {
        return;
    }
    int count = func_02097420((struct Struct_02097420*)((char*)self + 0xa4));
    if (!count) {
        return;
    }
    memset((char*)self + 0x182, 0, 0x10);
    int i = 0;
    while (i < count) {
        if (arr) {
            if (arr->unknown_13_1_) {
                if (arr->unknown_1a_ == key) {
                    *(short*)((char*)self + 0x182) = arr->f0c;
                    return;
                }
            }
        }
        i++;
        arr = (Struct_ov014_02188a8c*)((char*)arr + 0x20);
    }
}
