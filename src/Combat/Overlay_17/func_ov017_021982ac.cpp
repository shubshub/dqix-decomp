#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov017_021982ac_108 = 0x8c };
#else
enum { Enum_ov017_021982ac_108 = 0x6c };
#endif
#include "GameState/GameState.h"

struct Struct_020a2908;
struct Struct_020a28e0;

void* ZoneFeatures_GetFirstOfType(unsigned char* obj, unsigned int index);
int GameState_GetFollowCamera(char* obj);
int CheckField0x245Bit0x2Set_020a2cc4(unsigned char* obj);
void SetOrClearField0x245Bit0x2_020a2cd8(unsigned char* obj, int flag);
void CopySubstateAndSetFlag4_020a2908(unsigned char* obj, struct Struct020a2928* src);
void CopySubstateAndSetFlag4_020a296c(unsigned char* obj, struct Struct020a2928* src);
void ClearFlagAt0x240_020a28d0(unsigned char* obj);
void SetFlagAt0x240_020a28c4(unsigned char* obj);
void ResetField270Block_020a28e0(struct S_a28e0* p);
void ClearFlag0x4At0x245_020a298c(unsigned char* obj);

extern "C" void* Zone3D_GetInstance(void);

struct Struct_ov017_021982ac_2 {
    char unknown_0_[0x2c];
    unsigned char unknown_2c_0_ : 7;
    unsigned char unknown_2c_7_ : 1;
    char unknown_2d_[3];
    unsigned char unknown_30_[0x2c];
    unsigned char unknown_5c_[0x14];
    struct Struct_ov017_021982ac_2* unknown_70_;
};

struct Struct_ov017_021982ac {
    unsigned int unknown_0_[3];
};

extern "C" int func_02094b9c(struct Struct_ov017_021982ac_2* arg0, struct Struct_ov017_021982ac* arg1);
extern "C" void func_020a28dc(void* arg0, int arg1, void* arg2, void* arg3);

// USA: func_ov017_021982ac
extern "C" ARM void func_ov017_021982ac(void) {
    GameState* battle = GameState::GetInstance();
    void* ctx = Zone3D_GetInstance();
    GameObject* combatant = battle->GetLeader();
    struct Anchor_021982ac anchor = *(struct Anchor_021982ac*)((char*)combatant + 0x44);
    struct PendingNode_021982ac* node;
    unsigned char* state;
    int applied;

    node = (struct PendingNode_021982ac*)ZoneFeatures_GetFirstOfType((unsigned char*)ctx + kRegionalFieldOffset, 4);
    state = (unsigned char*)GameState_GetFollowCamera((char*)battle);
    if (state == 0) {
        return;
    }

    var6 = 0;
    while (var4 != 0) {
        if (func_02094b9c(var4, &var3)) {
            int var7 = var4->unknown_2c_0_;
            if (var7 == 4) {
                if (func_020a2cc4(var5)) {
                    func_020a2cd8(var5, 0);
                }
                func_020a2908(var5, (struct Struct_020a2908*)var4->unknown_30_);
                var6 = 1;
            } else if (var7 == 5) {
                func_020a296c(var5, (struct Struct_020a2908*)var4->unknown_30_);
                var6 = 1;
            } else {
                func_020a28dc(var5, var7, var4->unknown_30_, var4->unknown_5c_);
            }
            if (!var4->unknown_2c_7_) {
                func_020a28d0(var5);
            }
            break;
        }
        var4 = var4->unknown_70_;
    }

    if (var4 == 0) {
        func_020a28c4(var5);
        func_020a28e0((struct Struct_020a28e0*)var5);
    }
    if (!var6) {
        func_020a298c(var5);
    }
}
