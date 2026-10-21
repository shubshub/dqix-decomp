#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"

extern "C" void func_ov009_02188c2c(CharacterCreationUI* self);
extern "C" void func_ov009_02188d9c(CharacterCreationUI* self);
extern "C" void func_ov009_02188e70(CharacterCreationUI* self, int val);
extern "C" void applyCreationChoice(CharacterCreationUI* self, int val);
extern "C" int func_ov009_02188ee8(CharacterCreationUI* self);
#if defined(jpn)
extern "C" ARM void func_ov009_021867bc(unsigned char* arg0, int arg1);
#define func_ov009_021855dc func_ov009_021867bc
#else
extern "C" ARM void func_ov009_021855dc(unsigned char* arg0, int arg1);
#endif

extern "C" int func_0202ee38(char* arg0, int arg1, int arg2);
extern "C" void func_0202ee58(char* arg0, int arg1, int arg2);

#if defined(jpn)
#define data_ov009_0218a9c8 data_ov009_0218b9a4
#endif
extern Vector3fix data_ov009_0218a9c8;
#if defined(jpn)
#define data_ov009_0218a9d4 data_ov009_0218b9b0
#endif
extern Vector3fix data_ov009_0218a9d4;
#if defined(jpn)
#define data_ov009_0218a9e0 data_ov009_0218b9bc
#endif
extern Vector3fix data_ov009_0218a9e0;
#if defined(jpn)
#define data_ov009_0218a9ec data_ov009_0218b9c8
#endif
extern Vector3fix data_ov009_0218a9ec;

// USA: func_ov009_021866f0
extern "C" ARM void func_ov009_021866f0(Struct_ov009_021842a0* arg0) {
    unsigned char var0 = arg0->unknown_c59_;
    if (var0 == 0) {
        func_ov009_02188c2c(arg0);
        func_ov009_02188d9c(arg0);
        int var1 = arg0->unknown_da3_;
        unsigned char var2 = arg0->unknown_da6_[var1];
        func_ov009_02188e70(arg0, var2);

        Vector3fix var3 = data_ov009_0218a9c8;
        Vector3fix var4 = data_ov009_0218a9d4;
        func_0202ee38((char*)arg0->unknown_924_, (int)&var3, 0x1e000);
        func_0202ee58((char*)arg0->unknown_924_, (int)&var4, 0x1e000);

        arg0->unknown_d9c_ |= 1;
        arg0->unknown_c59_ = arg0->unknown_c59_ + 1;
        return;
    }
    if (var0 == 1) {
        if (arg0->unknown_d9c_ & 0x80) {
            return;
        }
        int idx = self->sex;
        unsigned char val = self->faceStyle[idx];
        applyCreationChoice(self, val);
        self->step = self->step + 1;
        return;
    }
    if (var0 != 2) {
        return;
    }

    int var7 = func_ov009_02188ee8(arg0);
    int var8 = 0;
    if (var7 == -2) {
        func_ov009_021855dc((unsigned char*)arg0, 6);
        var8 = 1;
    } else if (var7 == -3) {
        func_ov009_021855dc((unsigned char*)arg0, 4);
        var8 = 1;
    } else if (var7 >= 0x65 && var7 <= 0x6c) {
        int var9 = arg0->unknown_da3_;
        int var10 = var7 - 0x64;
        signed char var11 = arg0->unknown_da0_[var9];
        if (var10 <= var11) {
            signed char var12 = arg0->unknown_c58_;
            if (var10 != var12) {
                func_ov009_021855dc((unsigned char*)arg0, var10 & 0xff);
                var8 = 1;
            }
        }
    }

    if (var8 != 0) {
        Vector3fix var13 = data_ov009_0218a9e0;
        Vector3fix var14 = data_ov009_0218a9ec;
        func_0202ee38((char*)arg0->unknown_924_, (int)&var13, 0x1e000);
        func_0202ee58((char*)arg0->unknown_924_, (int)&var14, 0x1e000);
    }
}
