#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"

#if defined(jpn)
#define func_ov009_021855dc func_ov009_021867bc
#endif

extern "C" void func_ov009_02188c2c(CharacterCreationUI* self);
extern "C" void func_ov009_02188d9c(CharacterCreationUI* self);
extern "C" void func_ov009_02188e70(CharacterCreationUI* self, int choice);
extern "C" void applyCreationChoice(CharacterCreationUI* self, int choice);
extern "C" int func_ov009_02188ee8(CharacterCreationUI* self);
#if defined(jpn)
extern "C" void func_ov009_021867bc(unsigned char*, int);
#define func_ov009_021855dc func_ov009_021867bc
#else
extern "C" void func_ov009_021855dc(unsigned char* arg0, int arg1);
#endif
extern "C" void func_0202ee38(char* arg0, int arg1, int arg2);
extern "C" void func_0202ee58(char* arg0, int arg1, int arg2);

#if defined(jpn)
#define data_ov009_0218a9f8 data_ov009_0218b9d4
#endif
extern const Vector3fix data_ov009_0218a9f8;
#if defined(jpn)
#define data_ov009_0218aa04 data_ov009_0218b9e0
#endif
extern const Vector3fix data_ov009_0218aa04;
#if defined(jpn)
#define data_ov009_0218aa10 data_ov009_0218b9ec
#endif
extern const Vector3fix data_ov009_0218aa10;
#if defined(jpn)
#define data_ov009_0218aa1c data_ov009_0218b9f8
#endif
extern const Vector3fix data_ov009_0218aa1c;

// USA: func_ov009_02186c00
extern "C" ARM void func_ov009_02186c00(Struct_ov009_021842a0* arg0)
{
    if (arg0->unknown_c59_ == 0)
    {
        func_ov009_02188c2c(arg0);
        func_ov009_02188d9c(arg0);
        func_ov009_02188e70(arg0, arg0->unknown_da8_[arg0->unknown_da3_]);
        Vector3fix var0 = data_ov009_0218a9f8;
        Vector3fix var1 = data_ov009_0218aa04;
        func_0202ee38((char*)arg0->unknown_924_, (int)&var0, 0x1e000);
        func_0202ee58((char*)arg0->unknown_924_, (int)&var1, 0x1e000);
        arg0->unknown_804_ = 0x1eb;
        arg0->unknown_d9c_ = (arg0->unknown_d9c_ | 8) & ~1;
        arg0->unknown_c59_++;
    }
    else if (arg0->unknown_c59_ == 1)
    {
        if (arg0->unknown_d9c_ & 0x80)
            return;
        applyCreationChoice(self, self->skinColor[self->sex]);
        self->step++;
    }
    else if (arg0->unknown_c59_ == 2)
    {
        if (!(arg0->unknown_d9c_ & 1) && !(arg0->unknown_d9c_ & 8))
            arg0->unknown_d9c_ |= 1;
        int var2 = func_ov009_02188ee8(arg0);
        int var3 = 0;
        if (var2 == -2)
        {
            func_ov009_021855dc((unsigned char*)arg0, 8);
            var3 = 1;
        }
        else if (var2 == -3)
        {
            func_ov009_021855dc((unsigned char*)arg0, 6);
            var3 = 1;
        }
        else if (var2 >= 101 && var2 <= 108)
        {
            int var4 = var2 - 100;
            if (var4 <= arg0->unknown_da0_[arg0->unknown_da3_] && var4 != arg0->unknown_c58_)
            {
                func_ov009_021855dc((unsigned char*)arg0, (unsigned char)var4);
                var3 = 1;
            }
        }
        if (var3)
        {
            Vector3fix var5 = data_ov009_0218aa10;
            Vector3fix var6 = data_ov009_0218aa1c;
            func_0202ee38((char*)arg0->unknown_924_, (int)&var5, 0x1e000);
            func_0202ee58((char*)arg0->unknown_924_, (int)&var6, 0x1e000);
        }
    }
}
