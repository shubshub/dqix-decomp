#include <globaldefs.h>
#include "GameState/GameState.h"

struct SearchStruct;

extern "C" SearchStruct* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsActive(int* obj);
extern "C" int LinkSession_IsSlotMember(SearchStruct* search, int index);
extern "C" int GameState_GetProtagonistIndex(GameState* battleStruct);
extern "C" unsigned char* func_0200ff58(GameState* battleStruct, int combatantId);
extern "C" int func_020546a8(void* obj);
extern "C" void MapDisplay_SetPartyOrder(char* obj, unsigned char* src, int count);
extern "C" void GameState_SetPartyOrder(char* obj, int len, void* src);
extern "C" void GameState_SetOwnPartyOrder(void* obj, int size, void* src);

// USA: func_ov017_02191234
extern "C" ARM void func_ov017_02191234(unsigned char* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x2c6, regionalOffset1=0x34c0};
#else
 enum {regionalOffset0=0x2d2, regionalOffset1=0x36d0};
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
            int var7 = 0;
            if (group == GameState_GetProtagonistIndex(battle)) {
                subList[subCount++] = group;
                var7 = 1;
            }
            for (int i = 1; i < 4; i++) {
                unsigned char* combatant = func_0200ff58(battle, i);
                if (combatant == 0) continue;
                if (group != func_020546a8(combatant)) continue;
                list[combatant[regionalOffset0]] = i;
                count++;
                if (var7) {
                    subList[combatant[regionalOffset0]] = i;
                    subCount++;
                }
            }
        }
    } else {
        list[count++] = 0;
        subList[subCount++] = 0;
        for (int i = 1; i < 4; i++) {
            unsigned char* combatant = func_0200ff58(battle, i);
            if (combatant != 0) {
                list[combatant[regionalOffset0]] = i;
                count++;
                subList[combatant[regionalOffset0]] = i;
                subCount++;
            }
        }
    }
    MapDisplay_SetPartyOrder(*(char**)(obj + regionalOffset1), list, count);
    GameState_SetPartyOrder((char*)battle, count, list);
    GameState_SetOwnPartyOrder(battle, subCount, subList);
}
