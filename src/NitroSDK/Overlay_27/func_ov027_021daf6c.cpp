#include <globaldefs.h>

struct Struct_ov027_021dd940_6 {
    unsigned char pad0[0x1c];
    void* f1c;
    void* f20;
    unsigned char f24;
    unsigned char pad1[0x28 - 0x25];
    unsigned char f28;
};

extern Struct_ov027_021dd940_6 data_ov027_021dd940;

// USA: func_ov027_021daf6c
extern "C" ARM void func_ov027_021daf6c(void) {
    if (data_ov027_021dd940.f24 != 2) return;
    void* obj = data_ov027_021dd940.f1c;
    switch (*((unsigned char*)obj + 0x4b2)) {
        case 0:
            data_ov027_021dd940.f28 = 9;
            data_ov027_021dd940.f20 = obj;
            break;
        default:
            data_ov027_021dd940.f28 = 4;
            data_ov027_021dd940.f20 = (char*)obj + 0x220;
            break;
    }
    data_ov027_021dd940.f24 = 3;
}
