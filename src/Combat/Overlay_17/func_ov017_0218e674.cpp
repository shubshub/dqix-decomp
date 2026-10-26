#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"
#include "Input/Input.h"
#include "Resource/Brightness.h"

struct SearchStruct;
struct Obj_021bd3a4;
struct Obj02052ae8;

struct Party2a04 {
    char unk_0[0xf78];
    unsigned char ids[4];
    unsigned char count;
};

extern "C" struct SearchStruct* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsGuest(struct SearchStruct* obj);
extern "C" void __clear(void* buf, int n);
extern "C" void GameObject_UpdatePartyMember(GameObject* obj);
extern "C" void func_ov017_0218e210(int id, int flag);
extern "C" int func_ov017_021bd3a4(struct Obj_021bd3a4* obj);
extern "C" void func_020d9834(int flag);
extern "C" int func_02039860(void* obj);
extern "C" int GameObject_GetLinePosition(void* obj);
extern "C" void func_ov017_02193428(void* a, void* b);
extern "C" void func_02052ae8(struct Obj02052ae8* obj);
extern "C" Object3D* func_ov017_021bdbc0(unsigned char* ov);

// USA: func_ov017_0218e674
extern "C" ARM void func_ov017_0218e674(unsigned char* ov) {
#if defined(jpn)
 enum {regionalOffset0=0x524, regionalOffset1=0x180};
#else
 enum {regionalOffset0=0x734, regionalOffset1=0x18c};
#endif
    GameState* battle = GameState::GetInstance();
    LinkSession_GetInstance();
    if (battle->GetCamera() == 0) return;

    struct Party2a04* party = (struct Party2a04*)GameState_GetParty(battle);
    int handled[4];
    __clear(handled, sizeof(handled));
    battle->GetEffectiveDeltaTime();

    int flag = 1;
    if ((TestFlags00((GameResources*)ov, 0x20) != 0 && g_keyManager.TestKeysHeld(flag) != 0) ||
        TestFlags00((GameResources*)ov, 0x2000) != 0) {
        flag = 0;
    }
    if (func_ov017_021bd3a4(*(struct Obj_021bd3a4**)(ov + 0x3000 + regionalOffset0)) != 0) {
        flag = 0;
    }
    int dispatch = 0;
    if (TestFlags00((GameResources*)ov, 0x4000) != 0) dispatch = 1;

    int count = 0;
    for (int i = 0; i < party->count; i++) {
        if (count != 0 && dispatch != 0) func_020d9834(1);
        int id = party->ids[i];
        count++;
        handled[id] = 1;
        func_ov017_0218e210(id, flag);
    }

    for (int i = 0; i < 4; i++) {
        if (handled[i] != 0) continue;
        GameObject* member = battle->GetPartyMemberByIndex(i);
        if (member == NULL) continue;
        if (count != 0 && dispatch != 0) func_020d9834(1);
        count++;
        if (LinkSession_IsGuest(LinkSession_GetInstance()) != 0 &&
            member->obj3D_.GetField06() == battle->GetLeader()->obj3D_.GetField06() &&
            ((member->obj3D_.unknown_0_ & 0x1000) != 0 ||
             (member->obj3D_.actorIndex_ == 0 && (*(unsigned int*)((char*)member + regionalOffset1) & 1) != 0)) &&
            func_02039860(member) >= 0) {
            handled[i] = 1;
            GameObject_UpdatePartyMember(member);
            func_ov017_02193428(member, NULL);
        } else if (GameObject_GetLinePosition(member) != 0) {
            GameObject_UpdatePartyMember(member);
        } else {
            func_02052ae8((struct Obj02052ae8*)member);
        }
    }

    Object3D* effects = func_ov017_021bdbc0(ov);
    if (effects != NULL) effects->AdvanceEffects();

    if (battle->GetPartyMemberByIndex(0xce) == NULL) return;
    if (count != 0 && dispatch != 0) func_020d9834(1);
    func_ov017_0218e210(0xce, flag);
}
