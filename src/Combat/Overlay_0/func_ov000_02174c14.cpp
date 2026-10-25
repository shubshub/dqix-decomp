#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov000_02174c14_7520 = 0x1f98, Enum_ov000_02174c14_7528 = 0x1fa0, Enum_ov000_02174c14_7538 = 0x1faa };
#else
enum { Enum_ov000_02174c14_7520 = 0x1d60, Enum_ov000_02174c14_7528 = 0x1d68, Enum_ov000_02174c14_7538 = 0x1d72 };
#endif
#include "std_library_functions.h"

struct Entry_0205d6a0;
void Window_ClosePane(struct Entry_0205d6a0* a, int flag);
int HasAnyFlags_021719f8_021719f8(int* obj);
void ResetElem2081Entry_0204c804(void* obj);

struct Struct_ov000_02174c14 {
    char unknown_0_[0xc];
    short unknown_c_;
    char unknown_e_[0x44 - 0xe];
    int unknown_44_;
    int unknown_48_;
    int unknown_4c_;
#if defined(jpn)
    char unknown_50_[0xc7 - 0x50];
#else
    char unknown1_50_[0x87 - 0x50];
#endif
    unsigned char unknown_87_;
    char unknown_88_[0x448 - 0x88];
};

struct Struct_ov000_02174c14_2 {
    char unknown_0_[0xac];
    short unknown_ac_;
    short unknown_ae_;
    char unknown_b0_[0xc2 - 0xb0];
    short unknown_c2_;
};

// USA: func_ov000_02174c14
extern "C" ARM void func_ov000_02174c14(char* arg0) {
    struct Struct_ov000_02174c14* var0;
    int var1;

    Window_ClosePane((struct Entry_0205d6a0*)(obj + 0x188), 1);
    memset(obj + queueOffset, 0, 8);
    *(signed char*)(obj + countOffset) = 0;
    (obj + *(signed char*)(obj + countOffset))[queueOffset] = 1;

    for (var1 = 0; var1 < 4; var1++) {
        var0 = (struct Struct_ov000_02174c14*)(arg0 + 0x958) + *(signed char*)(arg0 + 0x6c + var1);
        if (var0->unknown_4c_ < 0) continue;
        if (var0->unknown_c_ == 0) continue;
        if (func_ov000_021719f8((int*)var0)) continue;
        if (var0->unknown_87_ == 0) continue;

        struct Struct_ov000_02174c14_2* var2 = (struct Struct_ov000_02174c14_2*)(arg0 + 0x284);
        int var3 = var0->unknown_44_;
        int var4 = var0->unknown_48_;
        func_0204c804(var2);
        var2->unknown_ac_ = (var3 >> 3) + 9;
        var2->unknown_ae_ = var4 >> 3;
        var2->unknown_c2_ = 0;
        *(unsigned short*)(arg0 + Enum_ov000_02174c14_7538) |= 2;
        return;
    }
}
