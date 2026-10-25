#include <globaldefs.h>
#include "Combat/Main/CopyRecord0200fbb4.h"
#include "GameState/GameState.h"
#include "NitroSDK/Memory.h"

struct FieldFlagBlock;
void ResetAndEnableFieldFlag_02011b24(struct FieldFlagBlock* block);
GameObject* GetCombatantWithFlag0x1000_0200ff58(GameState* battleStruct, int combatantId);
void EnqueueEventTag58_021cf594(unsigned short, int, int);
extern "C" void* Zone3D_GetInstance(void);

// USA: func_ov004_02168760
extern "C" ARM int func_ov004_02168760(void) {
    GameState* var0 = GameState::GetInstance();
    func_02011b24((struct Struct_02011b24*)var0);

    char var1[0x70];
    VectorizedMemset(var1, 0, 0x70);

    unsigned char var2 = 1;
    var1[8] = var2;
    var1[9] = var2;
    int var3 = var2 - 2;
    *(signed char*)(var1 + 0xb) = var3;
    *(int*)(var1 + 0x20) = var3;
    *(int*)(var1 + 0x24) = var3;
    *(int*)(var1 + 0x28) = var3;
    *(int*)(var1 + 0x2c) = var3;
    *(short*)(var1 + 0x1e) = var3;
    var1[0xc] = 0;
    *(short*)(var1 + 0x6c) = var3;

    *(unsigned short*)var1 = 0x1130;
    *(int*)(var1 + 0x14) = -0x5ccc;
    *(int*)(var1 + 0x18) = 0x1000;
    *(short*)(var1 + 0x1c) = 0x323d;
    var1[2] = var2;
    var1[4] = 0;
    var1[5] = 0;
    *(int*)(var1 + 0x10) = 0;
    var1[7] = var2;

    func_0200fba4(var0, var1);

    unsigned short zone = *(unsigned short*)Zone3D_GetInstance();

    for (signed char var5 = 1; var5 < 4; var5++) {
        GameObject* var6 = var0->GetPartyMemberByIndex(var5);
        if (!var6) continue;
        if (func_0200ff58(var0, var5)) continue;
        if (var6->obj3D_.GetField06() != var4) continue;
        func_ov017_021cf594(0x1130, var5, 1);
    }
    return 0;
}
