#include <globaldefs.h>
#include "GameState/GameState.h"
#include "NitroSDK/Cache.h"
#include "std_library_functions.h"
#include "Resource/GameResources.h"

extern "C" int func_ov017_021bdbcc(void* obj);
extern "C" ARM void* func_020421b0(int idx);
extern "C" int LoadToMainObjVRAM(int, int, unsigned int);

// USA: func_ov002_021619b4
extern "C" ARM void func_ov002_021619b4(int combatantId, void* p1, void* dst) {
    if (combatantId < 0) return;

    GameState* bs = GameState::GetInstance();
    GameObject* combatant = bs->GetPartyMemberByIndex(combatantId);
    if (p1 == 0 || dst == 0 || combatant == 0) return;

    void* var2 = *(void**)((char*)p1 + 0x40);
    void* entry = 0;
    if (var2 != 0) {
        unsigned short var4 = *(unsigned short*)((char*)p1 + 0x4e);
        if (var4 > 0x2a) entry = (char*)var2 + 0x690;
    }

    void* var5;
    if (entry == 0 || (var5 = *(void**)((char*)entry + 8)) == 0) return;

    void* var6 = *(void**)((char*)combatant + 0x150);
    int var7 = *(int*)((char*)var6 + 0x950);

    int var8 = ((int)GetGameResources());
    int var9 = func_ov017_021bdbcc((void*)var8);
    if (var9 != 0) var7 = 0;

    int tableIdx = (var7 * 4 + 0x28) & 0xff;
    void* var11 = func_020421b0(tableIdx);
    memcpy(dst, var11, 0x80);

    unsigned short f4 = *(unsigned short*)((char*)var5 + 4);
    unsigned short var13 = f4 & 0x3ff;
    int var14 = var13 << 5;

    CleanInvalidateCacheRange(dst, 0x80);
    LoadToMainObjVRAM((int)dst, var14, 0x80);
    CleanCacheRange(dst, 0x80);
}
