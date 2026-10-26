#include <globaldefs.h>
#include "GameState/GameState.h"

void* LinkMessageQueue_GetInstance(void);
GameObject* GetCombatantWithFlag0x100_0200ff1c(GameState* battleStruct, int combatantId);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021c9e00 {
    unsigned char unknown_0_0_ : 3;
    unsigned char unknown_0_3_ : 1;
    unsigned char unknown_0_4_ : 1;
    unsigned char unknown_0_5_ : 1;
    unsigned char unknown_1_;
    unsigned short unknown_2_;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    unsigned short unknown_8_;
    int unknown_c_;
};

struct Struct_ov017_021c9e00_2 {
    unsigned char unknown_0_;
    unsigned char unknown_1_[3];
    struct Struct_ov017_021c9e00 unknown_4_;
};

// USA: func_ov017_021c9e00  (semantic: EnqueueCombatantStatsEvent_021c9e00)
extern "C" ARM void func_ov017_021c9e00(int id, int flagA, int flagB, int flagC) {
    void* data = LinkMessageQueue_GetInstance();
    GameState* battle = GameState::GetInstance();

    int var2 = (arg0 >= 0) && (arg0 <= 3);
    if (!var2) {
        return;
    }

    GameObject* var3 = func_0200ff1c(var1, arg0);
    if (var3 == NULL) {
        return;
    }

    struct Struct_ov017_021c9e00_2 var4;
    struct Struct_ov017_021c9e00* var5 = &var4.unknown_4_;
    var4.unknown_0_ = 4;
    var5->unknown_0_0_ = arg0;
    var5->unknown_2_ = *(unsigned short*)(*(char**)((char*)var3 + 0x130) + 4);
    var5->unknown_6_ = *(unsigned short*)(*(char**)((char*)var3 + 0x130) + 6);
    var5->unknown_4_ = *(unsigned short*)(*(char**)((char*)var3 + 0x134) + 0x30);
    var5->unknown_8_ = *(unsigned short*)(*(char**)((char*)var3 + 0x134) + 0x32);
    var5->unknown_1_ = *(unsigned char*)(*(char**)((char*)var3 + 0x130) + 8);
    var5->unknown_c_ = *(int*)(*(char**)((char*)var3 + 0x130));
    var5->unknown_0_3_ = arg1;
    var5->unknown_0_4_ = arg2;
    var5->unknown_0_5_ = arg3;

    func_0205e330(var0, &var4, 0);
}
