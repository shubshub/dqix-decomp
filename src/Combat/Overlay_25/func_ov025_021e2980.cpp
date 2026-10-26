#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"
#include "Graphics/LightingManager.h"

struct Struct_ov025_021e2980 {
    unsigned char padding0[8];
    const char* animation;
    unsigned short animationFlags;
    unsigned char target;
    unsigned char flags;
};
struct Struct_ov025_021e2980_2 {
    unsigned short kind;
    unsigned char padding2[8];
    unsigned char flags;
};
struct Struct_ov025_021e2980_3 {
    Object3D object;
    unsigned char unknown_ac_[0x12];
    unsigned char state;
};
struct Struct_ov025_021ef988_4 {
#if defined(jpn)
    unsigned char padding0[0xc];
#else
    unsigned char padding0[0x1c];
#endif

    unsigned int flags;
};
struct Struct_ov025_021e2980_4 {
#if defined(jpn)
    unsigned char padding0[0x71c4];
#else
    unsigned char padding0[0x6fd4];
#endif

    unsigned char unknown_6fd4_;
};
struct S0204a438;
struct AngleTrig0202e9a4;
struct Struct_02048c90;
struct Bytes02033b88;
struct SePlayer;
extern Struct_ov025_021ef988_4 data_ov025_021ef988;
extern char data_ov025_021ef7d9[];
extern char data_ov025_021ef7df[];
extern char data_ov025_021ef7e6[];
extern SePlayer g_sePlayer;
extern "C" int Camera_GetKindFlags(int);
extern "C" Object3D* func_0204a438(S0204a438*);
extern "C" void Camera_SetFieldOfView(AngleTrig0202e9a4*, int);
extern "C" void func_0204a170(int);
extern "C" int func_ov000_021820bc(void*, int, int, int);
extern "C" void func_02048c90(Struct_02048c90*);
extern "C" void func_02049ae4(unsigned char*);
extern "C" void GameObject_ForceMotionState(Bytes02033b88*, int);
extern "C" Struct_ov025_021e2980_4* func_ov000_02160130();
extern "C" void SePlayer_Play(SePlayer*, int, int);

// USA: func_ov025_021e2980
extern "C" ARM int func_ov025_021e2980(Struct_ov025_021e2980* command, Struct_ov025_021e2980_2* targets, int unused, void* context) {
    GameState* game = GameState::GetInstance();
    if (command->target == 0x19) {
        void* camera = game->GetCamera();
        if (Camera_GetKindFlags((int)camera) & 0x10) {
            Object3D* object = func_0204a438((S0204a438*)camera);
            if (object) {
                Camera_SetFieldOfView((AngleTrig0202e9a4*)camera, 0xf000);
                object->SetAnimationByName(command->animation, command->animationFlags);
                func_0204a170((int)camera);
                data_ov025_021ef988.flags |= 8;
            }
        }
    } else {
        int ids[8];
        int count = func_ov000_021820bc(context, (int)targets, command->target, (int)ids);
        if (!count) return 1;
        for (int i = 0; i < count; i++) {
            Struct_ov025_021e2980_3* combatant = (Struct_ov025_021e2980_3*)game->GetGameObjectByIndex(ids[i]);
            if (!combatant) continue;
            if (combatant->object.unknown_0_ & 0x80) {
                func_02048c90((Struct_02048c90*)combatant);
                func_02049ae4((unsigned char*)combatant);
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
        LightingManager* lighting = LightingManager::GetInstance();
        if (!(command->flags & 2) && targets->kind != 1 && targets->kind != 2 && targets->kind != 0xdb) {
            Struct_ov025_021e2980_4* work = func_ov000_02160130();
            if (!work->unknown_6fd4_) {
                lighting->BeginFade(0x999, 300);
                work->unknown_6fd4_ = 1;
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
            lighting->BeginFade(0x4cc, 1000);
            data_ov025_021ef988.flags |= 0x200;
        } else {
            data_ov025_021ef988.flags |= 1;
        }
    }
    data_ov025_021ef988.flags |= 4;
    return 1;
}
