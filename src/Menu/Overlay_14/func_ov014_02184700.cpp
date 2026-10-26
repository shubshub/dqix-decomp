#include "globaldefs.h"
#include "World/Object3D.h"
#include "GameState/GameState.h"
#include "std_library_functions.h"
#include "Input/Input.h"

struct Struct_ov014_02184700 { char unknown[0xc]; short id; };
struct Struct_ov014_02184700_2 { char unknown[0x1c]; float rotationY; };
struct Struct_ov014_02184700_3 {
    char unknown0[0xc];
    char unknown_c_[0x10];
    char unknown_1c_[0x24];
    Object3D* model;
    void* unknown_44_;
    Struct_ov014_02184700* monster;
    char unknown4c[0x30];
    unsigned char phase;
    char unknown_7d_[5];
    union {
        struct { unsigned char returning : 1; unsigned char unknown_0_1_ : 7; } mode;
        unsigned char flags;
    } unknown_82_;
    char unknown_83_[0xd];
    unsigned char unknown_90_, unknown_91_, unknown_92_;
};
typedef void (Struct_ov014_02184700_3::*Type_02000c9c_9)();
extern "C" {
void func_ov014_02185c48(void*);
extern "C" void* func_02097224(void*, short);
extern void* data_ov014_02189800[4];
extern Type_02000c9c_9 __ptmf_null;
extern Type_02000c9c_9 data_ov014_021895a0[];
extern Type_02000c9c_9 data_ov014_021895b0[];
extern const char data_ov014_021895c8[];
extern const char data_ov014_021895ce[];
}

extern "C" ARM void func_ov014_02184700(Struct_ov014_02184700_3* state) {
    func_ov014_02185c48(state);
    if (state->model) {
        state->model->AdvanceEffects();
        int target = 0;
        if (state->monster) {
            Struct_ov014_02184700_2* descriptor = (Struct_ov014_02184700_2*)func_02097224(state->unknown_c_, state->monster->id);
            if (descriptor) target = (int)(4096.0f * descriptor->rotationY);
        }
        Object3D* model = state->model;
        int returning = state->unknown_82_.mode.returning;
        int speed;
        int var5;
        Vector3fix var6;
        Vector3fix var7;
        if (!model) var5 = 0;
        else {
            int var8 = 0;
            state->unknown_90_ = 0;
            state->unknown_91_ = 0;
            var5 = returning;
            speed = 0;
            if (g_keyManager.TestKeysHeld(0x200) && g_keyManager.TestKeysHeld(0x100)) {
                if (!returning) {
                    var5 = 1;
                    state->unknown_90_ = 1;
                    state->unknown_91_ = 1;
                }
            } else if (g_keyManager.TestKeysHeld(0x200) && !g_keyManager.TestKeysReleased(0x100)) {
                var8 = 1;
                state->unknown_90_ = 1;
                speed = 0xcc;
            } else if (g_keyManager.TestKeysHeld(0x100) && !g_keyManager.TestKeysReleased(0x200)) {
                var8 = 1;
                state->unknown_91_ = 1;
                speed = -0xcc;
            }
            if (returning) {
                var7 = model->rotation_;
                int difference = target - var7.y;
                if (var7.y >= target + 0x3243) difference = target + 0x6487 - var7.y;
                speed = difference / 5;
                if (!g_keyManager.TestKeysHeld(0x100) && !g_keyManager.TestKeysHeld(0x200) && var7.y == target) var5 = 0;
            }
            if (var8 || returning) {
                speed *= GameState::GetInstance()->GetTickCount();
                var6 = model->rotation_;
                var6.y += speed;
                if (returning) {
                    if (var6.y < target + 0xcc || var6.y > target + 0x63bb) var6.y = target;
                    if (!(state->unknown_90_ && state->unknown_91_ && var6.y != target)) {
                        state->unknown_90_ = 0;
                        state->unknown_91_ = 0;
                    }
                }
                if (var6.y < 0) var6.y += 0x6487;
                if (var6.y >= 0x6487) var6.y -= 0x6487;
                model->rotation_ = var6;
            }
        }
        state->unknown_82_.flags = (state->unknown_82_.flags & ~1) | (var5 & 1);
        if (state->model->HasAnimationStopped() || state->model->HasAnimationReachedEnd()) {
            model = state->model;
            const char* animation = (const char*)model->activeAnimationRecord_;
            if (animation && strcmp(data_ov014_021895c8, animation) && strcmp(data_ov014_021895ce, animation)) model->SetAnimationByName(data_ov014_021895c8, 0);
        }
    }
    state->unknown_92_ = 0;
    unsigned int initialized = (unsigned int)data_ov014_02189800[1];
    if (!(initialized & 1)) {
        data_ov014_021895a0[4] = __ptmf_null;
        data_ov014_02189800[1] = (void*)(initialized | 1);
    }
    if (data_ov014_021895b0[state->phase]) (state->*data_ov014_021895b0[state->phase])();
}
