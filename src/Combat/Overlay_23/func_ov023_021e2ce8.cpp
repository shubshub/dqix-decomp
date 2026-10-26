#include <globaldefs.h>
#include "GameState/GameState.h"
#include "NitroSDK/Cache.h"
#include "Resource/GameResources.h"

extern "C" int func_ov017_021bdbcc(void* obj);
extern "C" ARM void* func_020421b0(int idx);
extern "C" int LoadToMainObjVRAM(int, int, unsigned int);

// USA: func_ov023_021e2ce8
extern "C" ARM void func_ov023_021e2ce8(int combatantId, void* p1) {
    if (combatantId < 0) return;

    GameState* bs = GameState::GetInstance();
    GameObject* combatant = bs->GetPartyMemberByIndex(combatantId);
    if (p1 != 0 && combatant != 0) {
        void* var2 = *(void**)((char*)p1 + 0x40);
        void* entry = 0;
        if (var2 != 0) {
            unsigned short var4 = *(unsigned short*)((char*)p1 + 0x4e);
            if (var4 > 15) entry = (char*)var2 + 0x258;
        }

        if (entry != 0) {
            void* var5 = *(void**)((char*)entry + 8);
            if (var5 != 0) {
                void* var6 = *(void**)((char*)combatant + 0x150);
                int var7 = *(int*)((char*)var6 + 0x950);

                int var8 = ((int)GetGameResources());
                int var9 = func_ov017_021bdbcc((void*)var8);
                if (var9 != 0) var7 = 0;

                unsigned short f4 = *(unsigned short*)((char*)var5 + 0x4);
                int tableIdx = (var7 * 4 + 0x28) & 0xff;
                unsigned short var12 = f4 & 0x3ff;
                int var13 = var12 << 5;

                int i;
                for (i = 0; i < 4; i++) {
                    void* var15 = func_020421b0(tableIdx);
                    CleanInvalidateCacheRange(var15, 0x20);
                    LoadToMainObjVRAM((int)var15, var13, 0x20);
                    CleanCacheRange(var15, 0x20);
                    tableIdx = (tableIdx + 1) & 0xff;
                    var13 += 0x20;
                }
            }
        }
    }
}
