#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { Enum_ov003_02175df4_2204 = 0x818 };
enum { Enum_ov003_02175df4_4108 = 0xf88 };
enum { Enum_ov003_02175df4_2208 = 0x81c };
enum { Enum_ov003_02175df4_4124 = 0xf98 };
enum { Enum_ov003_02175df4_4114 = 0xf8e };
enum { Enum_ov003_02175df4_4154 = 0xfb6 };
enum { Enum_ov003_02175df4_4148 = 0xfb0 };
#else
enum { Enum_ov003_02175df4_2204 = 0x89c };
enum { Enum_ov003_02175df4_4108 = 0x100c };
enum { Enum_ov003_02175df4_2208 = 0x8a0 };
enum { Enum_ov003_02175df4_4124 = 0x101c };
enum { Enum_ov003_02175df4_4114 = 0x1012 };
enum { Enum_ov003_02175df4_4154 = 0x103a };
enum { Enum_ov003_02175df4_4148 = 0x1034 };
#endif

struct Struct_0207c484;
struct Struct_02061c04_23;
struct Struct_02061c04_22;

extern "C" int func_0207c484(struct Struct_0207c484* arg0, int arg1, int arg2, int arg3);
extern "C" short func_02080468(void* arg0, int arg1);
extern "C" struct Struct_02061c04_22* func_02053c6c(unsigned char* arg0);
extern "C" void func_0208386c(struct Struct_02061c04_22* arg0, int arg1);
extern "C" int func_020a0a08(struct Struct_02061c04_23* arg0, int arg1, int arg2);

struct Struct_ov003_02175df4 {
    char unknown_0_[0x8];
    unsigned int unknown_8_0_ : 4;
};

struct Struct_ov003_02175df4_2 {
    char unknown_0_[0x8];
    Struct_ov003_02175df4* unknown_8_;
    char unknown_c_[Enum_ov003_02175df4_2204 - 0xc];
    void* unknown_89c_;
    char unknown_8a0_[Enum_ov003_02175df4_4108 - Enum_ov003_02175df4_2208];
    short unknown_100c_;
    short unknown_100e_;
    short unknown_1010_;
    char unknown_1012_[Enum_ov003_02175df4_4124 - Enum_ov003_02175df4_4114];
    int unknown_101c_[5];
    int unknown_1030_;
    char unknown_1034_[Enum_ov003_02175df4_4154 - Enum_ov003_02175df4_4148];
    short unknown_103a_;
    signed char unknown_103c_;
};

// USA: func_ov003_02175df4
extern "C" ARM int func_ov003_02175df4(Ctx02175df4* self) {
    GameState* bs = GameState::GetInstance();
    char* bag = (char*)GameState_GetParty(bs);
    if (self->mode_ == 0x77) {
        return DecrementKeyedStackAmount0207c484((struct KeyedList0207c484*)(bag + 0x1d4), self->key_, self->amount_, self->owner_->category_);
    }
    int var2;
    switch (arg0->unknown_1030_) {
    case 1:
        var2 = 0x11;
        break;
    case 2:
        var2 = 0x12;
        break;
    case 3:
        var2 = 0x13;
        break;
    case 4:
        var2 = 0x14;
        break;
    }
    short var3 = arg0->unknown_1010_ - func_02080468(arg0->unknown_89c_, var2);
    if (arg0->unknown_1030_ > var3) {
        GameObject* var4 = var0->GetPartyMemberByIndex(arg0->unknown_101c_[var3]);
        if (var4 == NULL) {
            return 0;
        }
        short var5 = arg0->unknown_100e_ - func_02080468(arg0->unknown_89c_, 0x15);
        func_0208386c(func_02053c6c((unsigned char*)var4), (signed char)var5);
        return 1;
    }
    func_020a0a08((struct Struct_02061c04_23*)var1, arg0->unknown_103a_, arg0->unknown_103c_);
    return 1;
}
