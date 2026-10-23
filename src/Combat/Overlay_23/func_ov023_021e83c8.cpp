#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Resource/CharacterCreationUI.h"

#if defined(jpn)
enum { Enum_ov023_021e83c8_1550 = 0x604, Enum_ov023_021e83c8_56 = 0x14 };
#else
enum { Enum_ov023_021e83c8_1550 = 0x60e, Enum_ov023_021e83c8_56 = 0x38 };
#endif
namespace {
struct Struct_ov023_021e83c8 {
    unsigned char unknown_0_[0x4c];
    Struct_0201099c_3 unknown_4c_;
    unsigned char unknown_54_[0x5d8 - 0x54];
    char* unknown_5d8_;
    unsigned char unknown_5dc_[Enum_ov023_021e83c8_1550 - 0x5dc];
    unsigned short unknown_60e_;
    unsigned char unknown_610_;
};
struct Struct_ov023_021fd75c_2 {
    unsigned char unknown_0_[Enum_ov023_021e83c8_56];
    int unknown_38_;
    int unknown_3c_;
};
}

extern "C" int func_020421a0(void);

struct Struct_020465c0;
extern "C" void func_020465c0(struct Struct_020465c0* arg0, int arg1, int arg2);
extern "C" void func_020465d8(unsigned char* arg0, int arg1, unsigned char arg2);
extern "C" void func_020465f0(unsigned char* arg0, int arg1, unsigned char arg2);

struct Container020e0310;
int KeyTable_Get(struct Container020e0310* c, int key);

#if defined(jpn)
extern "C" void func_020474a8(void* arg0, unsigned char arg1, const char* arg2, char* arg3);
#else
extern "C" ARM void func_02046608(void* arg0, int arg1, void* arg2, void* arg3, int arg4, int arg5, int arg6);
#endif

struct Struct_02000c9c_8;
extern "C" ARM unsigned char func_0200fb08(Struct_02000c9c_8* arg0);

#if defined(jpn)
#define data_ov023_021fd75c data_ov023_021fd760
#endif
extern Struct_ov023_021fd75c_2 data_ov023_021fd75c;
extern char data_ov023_021fddb0;
extern char data_ov023_021fddb4;

struct Struct_01ff8b48_15 { char unknown_0_[0x38]; int unknown_38_; int unknown_3c_; };

// USA: func_ov023_021e83c8
// JPN: func_ov023_021e8404
extern "C" ARM void func_ov023_021e83c8(void* arg0) {
    Struct_ov023_021e83c8* var0 = static_cast<Struct_ov023_021e83c8*>(arg0);
    int var1 = func_020421a0();

    int* var2;
    int var3;
    int var4[2];
    int var5[2];
    var4[0] = var0->unknown_60e_;
    var4[1] = var0->unknown_610_;
    var5[0] = data_ov023_021fd75c.unknown_38_;
    var5[1] = data_ov023_021fd75c.unknown_3c_;

    var2 = var5;
    var3 = 0;
    for (; var3 < 2; var3++) {
        func_020465c0((struct Struct_020465c0*)var1, var3, var4[var3]);
        func_020465d8((unsigned char*)var1, var3, 1);
        func_020465f0((unsigned char*)var1, var3, var2[var3] & 0xff);
    }

    int key = KeyTable_Get(&state->messages, 0);
#if defined(jpn)
    func_020474a8(((void*)(var1)), 0xa, ((const char*)(var6)), var0->unknown_5d8_);
#else
    func_02046608(((void*)(var1)), 0xa, ((void*)(var6)), var0->unknown_5d8_, 0x100, 0, 0);

    int var7, var8;
    char* var9 = strstr(var0->unknown_5d8_, &data_ov023_021fddb0);
    char* var10 = strstr(var9 + 1, &data_ov023_021fddb0);
    var7 = 0x82; var8 = 0xb4;
    int var11 = func_0200fb08((struct Struct_02000c9c_8*)GameState::GetInstance());
    switch (var11) {
    case 2:
    case 5:
        var7 = 0xa5; var8 = 0xc1;
        break;
    case 3:
        var7 = 0x92; var8 = 0xb6;
        break;
    }

    char var12[4];
    char var13[4];
    sprintf(var12, &data_ov023_021fddb4, var7);
    sprintf(var13, &data_ov023_021fddb4, var8);
    memcpy(var9 + 3, var12, 3);
    memcpy(var10 + 3, var13, 3);
#endif
}

#if defined(jpn)
#undef data_ov023_021fd75c
#endif
