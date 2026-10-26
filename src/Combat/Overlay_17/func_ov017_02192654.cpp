#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" void LinkSession_GetInstance(void);
extern "C" int LinkSession_IsHostOrSolo(void);
extern "C" void func_ov017_021a23b0(void* self, int val);

extern "C" GameObject* func_0200ffe0(GameState* battleStruct, int id);
extern "C" void func_02079710(unsigned char* obj, int bit, int cond);
extern "C" int func_0207973c(unsigned char* obj);
extern "C" int func_020797bc(unsigned char* obj);
extern "C" void func_ov017_021d0aa8(unsigned short a, unsigned char b);
extern "C" void func_020797d0(unsigned char* obj);

// USA: func_ov017_02192654
extern "C" ARM void func_ov017_02192654(int bit, int id, unsigned char cond) {
    void* base = GetGameResources();
    GameState* battleStruct = GameState::GetInstance();
    LinkSession_GetInstance();
    if (LinkSession_IsHostOrSolo()) {
        GameObject* combatant = func_0200ffe0(battleStruct, id);
        if (combatant != 0) {
            func_02079710((unsigned char*)combatant, bit, cond);
            if (func_0207973c((unsigned char*)combatant)) {
                if (func_020797bc((unsigned char*)combatant)) {
                    func_ov017_021d0aa8((unsigned short)id, 1);
                    func_ov017_021a23b0(base, id);
                }
                func_020797d0((unsigned char*)combatant);
            }
        }
    } else {
        func_ov017_021d0aa8((unsigned short)id, cond);
    }
}
