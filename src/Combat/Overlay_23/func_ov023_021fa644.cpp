#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov011_021845f8(void*, int);
extern "C" void* func_ov011_0218466c(void* arg0, unsigned short arg1);

struct EncodedSize020e03b8;
int IsEncodedSizeEqual(int unused, struct EncodedSize020e03b8* obj, int val);
void* ResetAndReturnSelf020dfc2c(void* p);
struct Struct020dfc40;
void KeyTable_Reset(struct Struct020dfc40* p);
extern "C" void KeyTable_Load(void*, void*, void*, unsigned int);
struct Source020e03f0;
struct StructAA8;
int ApplyPtrAndShorts(struct Source020e03f0* self, struct StructAA8* obj);

struct Struct_ov023_021fa644 {
    char unknown_0_[0x49c];
    unsigned char unknown_49c_0_ : 1;
};

extern "C" int func_020100a8(GameState* arg0);

struct Struct_020727d8;
extern "C" void func_020727d8(struct Struct_020727d8* arg0);

struct Struct_02013fb4;
extern "C" void func_020728ac(int, int, struct Struct_02013fb4*, int, int, unsigned short, unsigned char);

struct Struct_ov023_021fa644_2 {
    char unknown_0_[8];
    unsigned short unknown_8_;
    unsigned short unknown_a_;
#if defined(jpn)
    char unknown_c_[0x28 - 0xc];
#else
    char unknown1_c_[0x2c - 0xc];
#endif

    unsigned char unknown_2c_;
};

// USA: func_ov023_021fa644
extern "C" ARM void func_ov023_021fa644(Struct_ov023_021fa644_2* arg0, void* arg1, Struct_020e03b8* arg2, int arg3) {
#if defined(jpn)
 enum {Enum_ov023_021fa644_336=0x144};
#else
 enum {Enum_ov023_021fa644_336=0x150};
#endif
    if (arg2 == 0 || arg3 == 0) {
        return;
    }
    void* var0 = func_ov011_021845f8(arg1, arg0->unknown_8_);
    void* var1 = func_ov011_0218466c(arg1, arg0->unknown_a_);
    if (var0 == 0 || var1 == 0) {
        return;
    }

    char local[0x18];
    ResetAndReturnSelf020dfc2c(local);
    if (IsEncodedSizeEqual((int)local, p2, p3)) {
        KeyTable_Reset((Struct020dfc40*)local);
        KeyTable_Load(local, (char*)allocBase + 4, p2, (unsigned int)p3);
        ApplyPtrAndShorts((Source020e03f0*)local, (StructAA8*)((char*)obj + 0x20));
        return;
    }

    unsigned char var3 = arg0->unknown_2c_;
    int var4 = 0;
    if (var3 == 1) {
        GameState* var5 = GameState::GetInstance();
        int var6 = func_020100a8(var5);
        GameObject* var7 = var5->GetPartyMemberByIndex(var6);
        if (var7 != 0) {
            Struct_ov023_021fa644* var8 = *(Struct_ov023_021fa644**)((char*)var7 + Enum_ov023_021fa644_336);
            var4 = var8->unknown_49c_0_;
        }
    } else if (var3 == 2) {
    } else if (var3 == 3) {
        var4 = 1;
    }

    func_020727d8((Struct_020727d8*)((char*)arg0 + 0x20));
    func_020728ac((int)((char*)arg0 + 0x20), (int)((char*)var0 + 4), (Struct_02013fb4*)arg2, arg3, 0, 0, var4);
}
