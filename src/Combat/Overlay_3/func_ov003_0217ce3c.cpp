#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { Enum_ov003_0217ce3c_20 = 0x10 };
enum { Enum_ov003_0217ce3c_144 = 0x8c };
enum { Enum_ov003_0217ce3c_24 = 0x14 };
#else
enum { Enum_ov003_0217ce3c_20 = 0x14 };
enum { Enum_ov003_0217ce3c_144 = 0x90 };
enum { Enum_ov003_0217ce3c_24 = 0x18 };
#endif


struct Struct_ov003_0217ce3c;
extern "C" void func_ov003_0217dc94(Struct_ov003_0217ce3c* arg0);
extern "C" int Window_Update(void* arg0, int arg1);

struct Struct_ov003_0217fbc8 { unsigned int unknown_0_[10]; };
extern struct Struct_ov003_0217fbc8 data_ov003_0217fbc8;
struct Struct_020e6d5c_19 { unsigned int unknown_0_; unsigned int unknown_4_; };
extern struct Struct_020e6d5c_19 __ptmf_null;
struct Struct_ov003_0217ce3c_2 { unsigned int unknown_0_; unsigned int unknown_4_; };

struct Struct_ov003_0217ce3c_3 {
    char unknown_0_[4];
    signed char unknown_4_;
    char unknown_5_[8 - 5];
    unsigned short unknown_8_;
    char unknown_a_[Enum_ov003_0217ce3c_20 - 0xa];
    int unknown_14_;
    char unknown_18_[Enum_ov003_0217ce3c_144 - Enum_ov003_0217ce3c_24];
    void* unknown_90_;
};

// USA: func_ov003_0217ce3c
extern "C" ARM int func_ov003_0217ce3c(struct Struct_ov003_0217ce3c_3* arg0) {
    GameState* var0 = GameState::GetInstance();
    func_ov003_0217dc94((struct Struct_ov003_0217ce3c*)arg0);
    if (arg0->unknown_8_ & 1) return 1;

    unsigned int var1 = var0->GetTickCount();
    if (arg0->unknown_90_ != 0) {
        arg0->unknown_14_ = Window_Update(arg0->unknown_90_, var1);
    }

    struct Struct_ov003_0217fbc8 var2;
    var2 = data_ov003_0217fbc8;
    struct Struct_020e6d5c_19* var3 = &__ptmf_null;
    unsigned int var4 = var3->unknown_4_;
    unsigned int var5 = var3->unknown_0_;
    ((struct Struct_ov003_0217ce3c_2*)&var2)[4].unknown_4_ = var4;
    ((struct Struct_ov003_0217ce3c_2*)&var2)[4].unknown_0_ = var5;

    signed char var6 = arg0->unknown_4_;
    struct Struct_ov003_0217ce3c_2* var7 = (struct Struct_ov003_0217ce3c_2*)&var2;
    if (var7[var6].unknown_0_ == 0) return 0;
    struct Struct_ov003_0217ce3c_2* var8 = &var7[var6];
    void* var9 = (char*)arg0 + ((int)var8->unknown_4_ >> 1);
    void (*var10)(void*);
    if (var8->unknown_4_ & 1) {
        var10 = (void(*)(void*))(*(void**)((char*)*(void**)var9 + var8->unknown_0_));
    } else {
        var10 = (void(*)(void*))var8->unknown_0_;
    }
    var10(var9);
    return 1;
}
