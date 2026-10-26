#include <globaldefs.h>
#include "GameState/GameState.h"

void* LinkMessageQueue_GetInstance(void);
GameObject* GetCombatantWithFlag0x100_0200ff1c(GameState* battleStruct, int combatantId);
struct Field150Holder02052e2c;
short* GetField150Ptr0x488_02052e2c(struct Field150Holder02052e2c* obj);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021c4418 {
    char unknown_0_[0x14];
    unsigned char unknown_14_0_ : 1;
    unsigned char unknown_14_1_ : 3;
    unsigned char unknown_14_4_ : 4;
    unsigned char unknown_15_0_ : 4;
    unsigned char unknown_15_4_ : 4;
    short unknown_16_;
    short unknown_18_;
    short unknown_1a_;
};

struct Struct_ov017_021c4418_2 {
    unsigned char unknown_0_;
    unsigned char unknown_1_[3];
    unsigned char unknown_4_;
    unsigned char unknown_5_;
    unsigned char unknown_6_;
    unsigned char unknown_7_;
    unsigned char unknown_8_;
    unsigned char unknown_9_;
    short unknown_a_;
    short unknown_c_;
    short unknown_e_;
    signed char unknown_10_;
};

// USA: func_ov017_021c4418  (semantic: EnqueueEntryBitsForCombatant_021c4418)
extern "C" ARM void func_ov017_021c4418(int combatantId, signed char flag10) {
    GameState* battleStruct = GameState::GetInstance();
    void* p = LinkMessageQueue_GetInstance();
    GameObject* c = GetCombatantWithFlag0x100_0200ff1c(battleStruct, combatantId);
    if (!c) return;
    struct Entry150_021c4418* entry = (struct Entry150_021c4418*)GetField150Ptr0x488_02052e2c((struct Field150Holder02052e2c*)c);
    if (!entry) return;

    struct Struct_ov017_021c4418_2 var4;
    var4.unknown_0_ = 1;
    var4.unknown_4_ = arg0;
    var4.unknown_5_ = var3->unknown_15_0_;
    var4.unknown_6_ = var3->unknown_14_4_;
    var4.unknown_7_ = var3->unknown_14_1_;
    var4.unknown_8_ = var3->unknown_14_0_;
    var4.unknown_a_ = var3->unknown_16_;
    var4.unknown_c_ = var3->unknown_18_;
    var4.unknown_e_ = var3->unknown_1a_;
    var4.unknown_10_ = arg1;
    func_0205e330(var1, &var4, 0);
}
