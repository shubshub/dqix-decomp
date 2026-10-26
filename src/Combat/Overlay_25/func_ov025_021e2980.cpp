#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"
#include "Graphics/LightingManager.h"

struct Struct_ov025_021e2980 {
    unsigned char unknown_0_[8];
    const char* unknown_8_;
    unsigned short unknown_c_;
    unsigned char unknown_e_;
    unsigned char unknown_f_;
};
struct Struct_ov025_021e2980_2 {
    unsigned short unknown_0_;
    unsigned char unknown_2_[8];
    unsigned char unknown_a_;
};
struct Struct_ov025_021e2980_3 {
    Object3D unknown_0_;
    unsigned char unknown_ac_[0x12];
    unsigned char unknown_be_;
};
struct Struct_ov025_021ef988_4 {
#if defined(jpn)
    unsigned char unknown_0_[0xc];
#else
    unsigned char unknown1_0_[0x1c];
#endif

    unsigned int unknown_1c_;
};
struct Struct_ov025_021e2980_4 {
#if defined(jpn)
    unsigned char unknown_0_[0x71c4];
#else
    unsigned char unknown1_0_[0x6fd4];
#endif

    unsigned char unknown_6fd4_;
};
struct S0204a438;
struct AngleTrig0202e9a4;
struct Obj02048c90;
struct Bytes02033b88;
struct SePlayer;
extern AnimationGlobals data_ov025_021ef988;
extern char data_ov025_021ef7d9[];
extern char data_ov025_021ef7df[];
extern char data_ov025_021ef7e6[];
extern SePlayer g_sePlayer;
int Camera_GetKindFlags(int);
Object3D* GetField0x21c(S0204a438*);
void Camera_SetFieldOfView(AngleTrig0202e9a4*, int);
extern "C" void func_0204a170(int);
int DispatchByIndex021820bc(void*, int, int, int);
void ResetInnerState02048c90(Obj02048c90*);
void ClearSubstructFlag0x4_02049ae4(unsigned char*);
void GameObject_ForceMotionState(Bytes02033b88*, int);
AnimationWork* GetActiveCombatWork_ov000_02160130();
void SePlayer_Play(SePlayer*, int, int);

// USA: func_ov025_021e2980
extern "C" ARM int func_ov025_021e2980(AnimationCommand* command, AnimationTargets* targets, int unused, void* context) {
    GameState* game = GameState::GetInstance();
    if (command->target == 0x19) {
        void* camera = game->GetCamera();
        if (Camera_GetKindFlags((int)camera) & 0x10) {
            Object3D* object = GetField0x21c((S0204a438*)camera);
            if (object) {
                Camera_SetFieldOfView((AngleTrig0202e9a4*)camera, 0xf000);
                object->SetAnimationByName(command->animation, command->animationFlags);
                func_0204a170((int)camera);
                data_ov025_021ef988.flags |= 8;
            }
        }
    } else {
        int ids[8];
        int count = DispatchByIndex021820bc(context, (int)targets, command->target, (int)ids);
        if (!count) return 1;
        for (int i = 0; i < count; i++) {
            AnimationCombatant* combatant = (AnimationCombatant*)game->GetGameObjectByIndex(ids[i]);
            if (!combatant) continue;
            if (combatant->object.unknown_0_ & 0x80) {
                ResetInnerState02048c90((Obj02048c90*)combatant);
                ClearSubstructFlag0x4_02049ae4((unsigned char*)combatant);
                int state = combatant->state;
                if (state != 0 && state != 4 && state != 6)
                    GameObject_ForceMotionState((Bytes02033b88*)combatant, 0);
            }
            combatant->object.SetAnimationPlaybackSpeed(0x1000, 0);
            combatant->object.SkipAnimationTransition();
            if (!combatant->object.SetAnimationByName(command->animation, command->animationFlags) &&
                strcmp(command->animation, data_ov025_021ef7d9) == 0) {
                if (!combatant->object.SetAnimationByName(data_ov025_021ef7df, command->animationFlags))
                    combatant->object.SetAnimationByName(data_ov025_021ef7e6, command->animationFlags);
            }
        }
        LightingManager* var8 = LightingManager::GetInstance();
        if (!(arg0->unknown_f_ & 2) && arg1->unknown_0_ != 1 && arg1->unknown_0_ != 2 && arg1->unknown_0_ != 0xdb) {
            Struct_ov025_021e2980_4* var9 = func_ov000_02160130();
            if (!var9->unknown_6fd4_) {
                var8->BeginFade(0x999, 300);
                var9->unknown_6fd4_ = 1;
            }
        }
        const char* animation = command->animation;
        if (strcmp(animation, data_ov025_021ef7e6) == 0 ||
            strcmp(animation, data_ov025_021ef7d9) == 0 ||
            strcmp(animation, data_ov025_021ef7df) == 0) {
            if (!(command->flags & 1)) {
                if (targets->flags & 1) SePlayer_Play(&g_sePlayer, 0x66, 0);
                else SePlayer_Play(&g_sePlayer, 0x64, 0);
            }
            var8->BeginFade(0x4cc, 1000);
            data_ov025_021ef988.unknown_1c_ |= 0x200;
        } else {
            data_ov025_021ef988.unknown_1c_ |= 1;
        }
    }
    data_ov025_021ef988.unknown_1c_ |= 4;
    return 1;
}
