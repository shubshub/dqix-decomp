#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"
#include "Input/Input.h"
#include "Resource/Brightness.h"

struct Struct_0202b2f0;
struct Struct_ov017_0218e674;
struct Struct_02037d88_11;

struct Struct_ov017_0218e674_2 {
    char unknown_0_[0xf78];
    unsigned char unknown_f78_[4];
    unsigned char unknown_f7c_;
};

extern "C" struct SearchStruct* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsGuest(struct SearchStruct* obj);
extern "C" void __clear(void* buf, int n);
extern "C" void GameObject_UpdatePartyMember(GameObject* obj);
extern "C" void func_ov017_0218e210(int id, int flag);
int HasFlag3orFlag2And9a_021bd3a4(struct Obj_021bd3a4* obj);
void DispatchByFlag020d9834(int flag);
int GetSignedByte0x1c8_02039860(void* obj);
int GameObject_GetLinePosition(void* obj);
void DispatchWithZeroExtras_02193428(void* a, void* b);
void StepValueTowardTarget02052ae8(struct Obj02052ae8* obj);
Object3D* GetField4334_021bdbc0(unsigned char* ov);

// USA: func_ov017_0218e674
extern "C" ARM void func_ov017_0218e674(unsigned char* arg0) {
#if defined(jpn)
 enum {Enum_ov017_0218e674_1844=0x524, Enum_ov017_0218e674_396=0x180};
#else
 enum {Enum_ov017_0218e674_1844=0x734, Enum_ov017_0218e674_396=0x18c};
#endif
    GameState* battle = GameState::GetInstance();
    LinkSession_GetInstance();
    if (battle->GetCamera() == 0) return;

    struct Party2a04* party = (struct Party2a04*)GameState_GetParty(battle);
    int handled[4];
    __clear(handled, sizeof(handled));
    battle->GetEffectiveDeltaTime();

    int var3 = 1;
    if ((TestFlags00((GameResources*)arg0, 0x20) != 0 && g_keyManager.TestKeysHeld(var3) != 0) ||
        TestFlags00((GameResources*)arg0, 0x2000) != 0) {
        var3 = 0;
    }
    if (func_ov017_021bd3a4(*(struct Struct_ov017_0218e674**)(arg0 + 0x3000 + Enum_ov017_0218e674_1844)) != 0) {
        var3 = 0;
    }
    int var4 = 0;
    if (TestFlags00((GameResources*)arg0, 0x4000) != 0) var4 = 1;

    int var5 = 0;
    for (int var6 = 0; var6 < var1->unknown_f7c_; var6++) {
        if (var5 != 0 && var4 != 0) func_020d9834(1);
        int var7 = var1->unknown_f78_[var6];
        var5++;
        var2[var7] = 1;
        func_ov017_0218e210(var7, var3);
    }

    for (int i = 0; i < 4; i++) {
        if (handled[i] != 0) continue;
        GameObject* member = battle->GetPartyMemberByIndex(i);
        if (member == NULL) continue;
        if (count != 0 && dispatch != 0) DispatchByFlag020d9834(1);
        count++;
        if (LinkSession_IsGuest(LinkSession_GetInstance()) != 0 &&
            member->obj3D_.GetField06() == battle->GetLeader()->obj3D_.GetField06() &&
            ((member->obj3D_.unknown_0_ & 0x1000) != 0 ||
             (member->obj3D_.actorIndex_ == 0 && (*(unsigned int*)((char*)member + regionalOffset1) & 1) != 0)) &&
            GetSignedByte0x1c8_02039860(member) >= 0) {
            handled[i] = 1;
            GameObject_UpdatePartyMember(member);
            DispatchWithZeroExtras_02193428(member, NULL);
        } else if (GameObject_GetLinePosition(member) != 0) {
            GameObject_UpdatePartyMember(member);
        } else {
            func_02052ae8((struct Struct_02037d88_11*)var9);
        }
    }

    Object3D* var10 = func_ov017_021bdbc0(arg0);
    if (var10 != NULL) var10->AdvanceEffects();

    if (var0->GetPartyMemberByIndex(0xce) == NULL) return;
    if (var5 != 0 && var4 != 0) func_020d9834(1);
    func_ov017_0218e210(0xce, var3);
}
