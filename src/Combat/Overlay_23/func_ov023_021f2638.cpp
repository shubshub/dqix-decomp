#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

extern "C" void func_02046380(void);
extern "C" int MessageSystem_GetInstance(void);
extern "C" void* LinkSession_GetInstance(void);
extern "C" void* Zone3D_GetInstance(void);
extern "C" unsigned char GameState_GetPartyOrder(char* obj, void* dst);
extern "C" int func_020a35e0(unsigned char* obj, unsigned char index);
extern "C" int func_ov023_021f4438(void* obj);
struct TableA68;
extern "C" void* func_02072a68(struct TableA68* table, int key);
struct StoreStruct;
extern "C" void func_020465c0(struct StoreStruct* base, int index, int value);
extern "C" int ZoneId_IsGrottoBossFloor(int x);
#if defined(jpn)
extern "C" void func_0204500c(void* obj, char* buffer, int a);
#else
extern "C" void func_0204500c(void* obj, char* buffer, int a, int b);
#endif
extern "C" int func_ov023_021f4fc8(void);
struct Struct_ov023_021eeaac_2;
extern "C" void func_ov023_021eefac(struct Struct_ov023_021eeaac_2* s);

extern "C" int* _ZZ21inline_ov023_021f4c04vE1s;

// USA: func_ov023_021f2638
extern "C" ARM int func_ov023_021f2638(unsigned char* obj) {
#if defined(jpn)
    GameState* battleStruct = GameState::GetInstance();
    int* g = _ZZ21inline_ov023_021f4c04vE1s;
    int state = MessageSystem_GetInstance();
    unsigned char* stateObj = (unsigned char*)state;
    LinkSession_GetInstance();
    void* search = Zone3D_GetInstance();
    int counter = *g;

    if (counter == 0) {
        if (*(int*)(obj + 0x5958) != 0) {
            char var6[0x100];
            int var7 = func_ov023_021f4438(obj);
            char* e1 = (char*)func_02072a68((struct TableA68*)(obj + 0x5af4), 0x10);
            sprintf(var6, e1, *(int*)(obj + 0x5958));
            int inRange = 0;
            if (*(unsigned char*)(obj + 0x5af0) == 0 && *(int*)(obj + 0x7014) != 0) {
                if (ZoneId_IsGrottoBossFloor(*(unsigned short*)search) != 0) inRange = 1;
            }
            if (var7 != 0 && inRange == 0) {
                char* e2 = (char*)func_02072a68((struct TableA68*)(obj + 0x5af4), 0x22);
                strcat(var6, e2);
            }
            func_0204500c(stateObj, var6, 1);
            stateObj[0x17e2] = 0;
            *(int*)(stateObj + 0x868) = 1;
        } else {
            *g = 2;
            return *(int*)(obj + 0xe28);
        }
        *g = *g + 1;
    } else if (counter == 1) {
        if (func_ov023_021f4fc8() != 0 || *(int*)(stateObj + 0x868) == 0) {
            *g = *g + 1;
        }
    } else if (counter == 2) {
        func_ov023_021eefac((struct Struct_ov023_021eeaac_2*)g);
        if (*(unsigned char*)(obj + 0x5af0) != 0 || *(int*)(obj + 0x7014) != 0) {
            int var11 = func_ov023_021f4438(obj);
            if (var11 != 0) return 0xd;
            *(int*)(obj + 0x7014) = 0;
        }
        return 0xe;
    }
    return *(int*)(obj + 0xe28);
#else
    GameState* battleStruct = GameState::GetInstance();
    int* g = _ZZ21inline_ov023_021f4c04vE1s;
    int state = MessageSystem_GetInstance();
    unsigned char* stateObj = (unsigned char*)state;
    func_02046380();
    LinkSession_GetInstance();
    void* search = Zone3D_GetInstance();
    int counter = *g;

    if (counter == 0) {
        if (*(int*)(obj + 0x5768) != 0) {
            char var18[0x100];
            unsigned char idBuf[4];
            GameObject* combatant;
            int n = GameState_GetPartyOrder((char*)battleStruct, idBuf);
            unsigned char var22 = 0;
            unsigned char total = 0;
            int i;
            for (i = 0; i < n; i++) {
                combatant = battleStruct->GetCombatantByIndex(idBuf[i]);
                if (combatant == NULL) continue;
                if (!func_020a35e0(*(unsigned char**)(obj + 0x2a0), idBuf[i])) continue;
                total = total + 1;
                void* var25 = *(void**)((char*)combatant + 0x130);
                if ((*(int*)var25 & 1) == 0) var22 = var22 + 1;
            }
            stateObj[0x30] = total;
            stateObj[0x31] = var22;
            int var26 = func_ov023_021f4438(obj);
            char* e1 = (char*)func_02072a68((struct TableA68*)(obj + 0x5904), 0x10);
            sprintf(var18, e1);
            func_020465c0((struct StoreStruct*)stateObj, 0, *(int*)(obj + 0x5768));
            int inRange = 0;
            if (*(unsigned char*)(obj + 0x5900) == 0 && *(int*)(obj + 0x6e24) != 0) {
                if (ZoneId_IsGrottoBossFloor(*(unsigned short*)search) != 0) inRange = 1;
            }
            if (var26 != 0 && inRange == 0) {
                char* e2 = (char*)func_02072a68((struct TableA68*)(obj + 0x5904), 0x22);
                strcat(var18, e2);
            }
            func_0204500c(stateObj, var18, 1, 0xe3);
            stateObj[0x19b2] = 0;
            *(int*)(stateObj + 0x998) = 1;
        } else {
            *g = 2;
            return *(int*)(obj + 0xeac);
        }
        *g = *g + 1;
    } else if (counter == 1) {
        if (func_ov023_021f4fc8() != 0 || *(int*)(stateObj + 0x998) == 0) {
            *g = *g + 1;
        }
    } else if (counter == 2) {
        func_ov023_021eefac((struct Struct_ov023_021eeaac_2*)g);
        if (*(unsigned char*)(obj + 0x5900) != 0 || *(int*)(obj + 0x6e24) != 0) {
            int var30 = func_ov023_021f4438(obj);
            if (var30 != 0) return 0xd;
            *(int*)(obj + 0x6e24) = 0;
        }
        return 0xe;
    }
    return *(int*)(obj + 0xeac);
#endif
}
