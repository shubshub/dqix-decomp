#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" int func_02053c6c(unsigned char* obj);
extern "C" int func_ov017_0218d4ec(void* obj, int bit);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021d25f4 {
    unsigned char field0;
    unsigned char unknown_1_0_ : 1;
    unsigned char flag1 : 1;
    unsigned char unknown_1_2_ : 6;
    unsigned char pad2[0xe];
};

struct Struct_ov017_021d25f4_2 {
    unsigned char tag;
    unsigned char pad[3];
    struct Struct_ov017_021d25f4 sub;
};

// USA: func_ov017_021d25f4
extern "C" ARM void func_ov017_021d25f4(int combatantId) {
    int handle = ((int)GetGameResources());
    void* p = LinkMessageQueue_GetInstance();
    struct Struct_ov017_021d25f4_2 buf;
    buf.tag = 0x20;
    struct Struct_ov017_021d25f4* sub = &buf.sub;

    GameState* battle = GameState::GetInstance();
    if (battle == 0) return;
    GameObject* combatant = battle->GetPartyMemberByIndex(combatantId);
    if (combatant == 0) return;
    int val = func_02053c6c((unsigned char*)combatant);
    if (val == 0) return;

    sub->field0 = (unsigned char)combatantId;
    sub->unknown_1_0_ = *(unsigned char*)((char*)val + 0x56c);
    int var7 = func_ov017_0218d4ec((void*)handle, combatantId);
    sub->flag1 = (var7 != 0);

    func_0205e330(p, &buf, 0);
}
