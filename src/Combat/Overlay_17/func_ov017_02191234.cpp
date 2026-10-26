#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_0202b2f0;

extern "C" SearchStruct* LinkSession_GetInstance(void);
int LinkSession_IsActive(int* obj);
int LinkSession_IsSlotMember(SearchStruct* search, int index);
int GameState_GetProtagonistIndex(GameState* battleStruct);
unsigned char* GetCombatantWithFlag0x1000_0200ff58(GameState* battleStruct, int combatantId);
int GetSignedByte0x2d0_020546a8(void* obj);
void MapDisplay_SetPartyOrder(char* obj, unsigned char* src, int count);
void GameState_SetPartyOrder(char* obj, int len, void* src);
void GameState_SetOwnPartyOrder(void* obj, int size, void* src);

// USA: func_ov017_02191234
extern "C" ARM void func_ov017_02191234(unsigned char* arg0) {
#if defined(jpn)
 enum {Enum_ov017_02191234_722=0x2c6, Enum_ov017_02191234_14032=0x34c0};
#else
 enum {Enum_ov017_02191234_722=0x2d2, Enum_ov017_02191234_14032=0x36d0};
#endif
    GameState* battle = GameState::GetInstance();
    SearchStruct* search = LinkSession_GetInstance();
    unsigned char count = 0;
    unsigned char subCount = 0;
    unsigned char list[4];
    unsigned char subList[4];

    if (LinkSession_IsActive((int*)search)) {
        for (int group = 0; group < 4; group++) {
            if (!LinkSession_IsSlotMember(search, group)) continue;
            list[count++] = group;
            int isCurrent = 0;
            if (group == GameState_GetProtagonistIndex(battle)) {
                subList[subCount++] = group;
                isCurrent = 1;
            }
            for (int var8 = 1; var8 < 4; var8++) {
                unsigned char* var9 = func_0200ff58(var0, var8);
                if (var9 == 0) continue;
                if (var6 != func_020546a8(var9)) continue;
                var4[var9[Enum_ov017_02191234_722]] = var8;
                var2++;
                if (var7) {
                    var5[var9[Enum_ov017_02191234_722]] = var8;
                    var3++;
                }
            }
        }
    } else {
        var4[var2++] = 0;
        var5[var3++] = 0;
        for (int var10 = 1; var10 < 4; var10++) {
            unsigned char* var11 = func_0200ff58(var0, var10);
            if (var11 != 0) {
                var4[var11[Enum_ov017_02191234_722]] = var10;
                var2++;
                var5[var11[Enum_ov017_02191234_722]] = var10;
                var3++;
            }
        }
    }
    MapDisplay_SetPartyOrder(*(char**)(obj + regionalOffset1), list, count);
    GameState_SetPartyOrder((char*)battle, count, list);
    GameState_SetOwnPartyOrder(battle, subCount, subList);
}
