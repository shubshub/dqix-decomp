// USA: func_ov009_02184ca4
#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"

struct Struct_0205d2bc;
extern "C" void func_0205d2bc(Struct_0205d2bc*);
extern "C" void func_0204b088(Struct_02000c9c_7*, void*);
#if defined(jpn)
extern "C" void func_ov009_02184e58(unsigned char*);
extern "C" void func_ov023_021d9a6c(char*);
void RefreshFieldIfFlag4000_021d9d34(char*);
void CharacterCreationUI_RefreshNameText(char*);
extern "C" void func_ov023_021da1dc(unsigned char*);
#else
extern "C" void func_ov009_02184e58(unsigned char*);
extern "C" void func_ov023_021d9a6c(char*);
void RefreshFieldIfFlag4000_021d9d34(char*);
void CharacterCreationUI_RefreshNameText(char*);
extern "C" void func_ov023_021da1dc(unsigned char*);
#endif

extern "C" ARM void func_ov009_02184ca4(unsigned char* arg0) {
    Struct_ov009_021842a0* var0 = (Struct_ov009_021842a0*)arg0;
#if defined(jpn)
    func_ov009_02184e58(arg0);
#else
    func_ov009_02184e58(arg0);
#endif
    signed char var1 = var0->unknown_c58_;
    if (var1 == 0 || var1 == 12)
        return;
    if (var0->unknown_d9c_ & 0x80)
        return;
    func_0205d2bc((Struct_0205d2bc*)&var0->unknown_1f8_[0]);
    func_0205d2bc((Struct_0205d2bc*)&var0->unknown_1f8_[1]);
    if (var0->unknown_d9c_ & 0x1000) {
        func_0204b088(&var0->unknown_158_[0], 0);
        var0->unknown_d9c_ &= ~0x1000;
    }
    if (var0->unknown_d9c_ & 0x2000) {
        func_0204b088(&var0->unknown_158_[3], 0);
#if defined(jpn)
        if (var0->unknown_c58_ == 8 || var0->unknown_c58_ == 9)
#else
        signed char var2 = var1 - 8;
        if ((unsigned char)var2 <= 1)
#endif
            func_0204b088(&var0->unknown_158_[2], 0);
        var0->unknown_d9c_ &= ~0x2000;
    }
#if defined(jpn)
    func_ov023_021d9a6c((char*)storage);
    RefreshFieldIfFlag4000_021d9d34((char*)storage);
    CharacterCreationUI_RefreshNameText((char*)storage);
    func_ov023_021da1dc(storage);
#else
    func_ov023_021d9a6c((char*)storage);
    RefreshFieldIfFlag4000_021d9d34((char*)storage);
    CharacterCreationUI_RefreshNameText((char*)storage);
    func_ov023_021da1dc(storage);
#endif
}
