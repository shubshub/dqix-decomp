#if defined(jpn)
enum { Enum_ov017_021c6ff0_1816 = 0x508 };
#else
enum { Enum_ov017_021c6ff0_1816 = 0x718 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"
#include "Resource/GameResources.h"

extern "C" void* func_ov017_021b8478(void* obj);
int TestBitAt0x34_020a35e0(unsigned char* obj, unsigned char index);
void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021c6ff0 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    int unknown_4_;
    short unknown_8_;
    short unknown_a_;
    short unknown_c_;
    short unknown_e_;
};

struct Struct_ov017_021c6ff0_2 {
    unsigned char unknown_0_;
    unsigned char unknown_1_[3];
    struct Struct_ov017_021c6ff0 unknown_4_;
};

// USA: func_ov017_021c6ff0
extern "C" ARM void func_ov017_021c6ff0() {
    GameState* bs = GameState::GetInstance();
    unsigned char* table = *(unsigned char**)((char*)GetGameResources() + 0x3000 + RegionOffset718);
    unsigned char* search = (unsigned char*)func_ov017_021b8478(table);
    void* data = LinkMessageQueue_GetInstance();

    struct Struct_ov017_021c6ff0_2 var4;
    var4.unknown_0_ = 0x70;
    struct Struct_ov017_021c6ff0* var5 = &var4.unknown_4_;

    for (int var6 = 0; var6 < 4; var6++) {
        if (!func_020a35e0(var2, var6)) {
            continue;
        }
        GameObject* var7 = var0->GetCombatantByIndex(var6);
        if (var7 == 0 || *(unsigned char*)(*(char**)((char*)var7 + 0x138) + 0x26) == 0) {
            continue;
        }
        var5->unknown_0_ = *(unsigned short*)(var2 + 0x8);
        var5->unknown_2_ = (unsigned short)var6;
        memcpy(&var5->unknown_4_, *(char**)((char*)var7 + 0x138) + 0x58, 4);
        var5->unknown_8_ = *(short*)(*(char**)((char*)var7 + 0x138) + 0x28);
        var5->unknown_a_ = *(short*)(*(char**)((char*)var7 + 0x138) + 0x2a);
        var5->unknown_c_ = *(short*)(*(char**)((char*)var7 + 0x138) + 0x2c);
        var5->unknown_e_ = *(short*)(*(char**)((char*)var7 + 0x138) + 0x2e);
        func_0205e330(var3, &var4, 0);
    }
}
