#include <globaldefs.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif
#include "GameState/GameState.h"
#include "Input/Input.h"

struct IntField0x23c_020a27c4 {
    char pad0[0x23c];
    int value;
    char unknown_240_[4];
    unsigned char flags;
};
struct Struct_020676e0_2 { char pad0[0xda]; unsigned short flags; };
struct Struct_020676e0_3 { char pad0[(IS_JPN ? 0x5a68 : 0x5cc8)]; unsigned char mode; };
struct Struct_020676e0_4 {
    char pad0[(IS_JPN ? 0x4c : 0x8c)];
    Struct_020676e0_2* owner;
    unsigned char controls[(IS_JPN ? 0x824 - 0x50 : 0x954 - 0x90)];
    int value;
    char unknown_958_[(IS_JPN ? 0x85c - 0x828 : 0x98c - 0x958)];
    int mode;
    char unknown_990_[(IS_JPN ? 0x870 - 0x860 : 0x9a0 - 0x990)];
    int state;
    char unknown_9a4_[(IS_JPN ? 0x17ea - 0x874 : 0x19ba - 0x9a4)];
    unsigned char enabled;
    char unknown_19bb_[(IS_JPN ? 0x17ff - 0x17eb : 0x19d2 - 0x19bb)];
    #if defined(jpn)
    unsigned char unknown_17ff_0_ : 4;
    unsigned char unknown_19d2_ : 1;
    unsigned char unknown_17ff_5_ : 3;
#else
    unsigned char unknown_19d2_;
#endif
};
typedef void (Struct_020676e0_4::*Type_02000c9c_11)(int);
#if defined(jpn)
extern Type_02000c9c_11 data_020f079c[2];
#define data_020f08b8 data_020f079c
#else
extern Type_02000c9c_11 data_020f08b8[2];
#endif
extern "C" void func_0205c904(unsigned char*, int);
extern "C" int func_0205cde8(unsigned char*);
extern "C" void func_0205cd94(unsigned char*);
extern "C" int GameState_GetFollowCamera(char*);
extern "C" int func_020a27c4(IntField0x23c_020a27c4*);
extern "C" int func_ov017_021a4e70(unsigned char*);
extern "C" int func_0205cecc(void*);
extern "C" int func_0205cb64(void*);

// USA: func_020676e0
extern "C" ARM void func_020676e0(Struct_020676e0_4* state, int elapsed) {
    if (state->state != 6) return;
    if (!state->enabled) return;
    func_0205c904(state->controls, elapsed);
    if (!func_0205cde8(state->controls)) {
        func_0205cd94(state->controls);
        return;
    }
    int enabled = 1;
    bool pressed = g_keyManager.TestKeysPressed(0x401) != 0;
    bool cancelled = g_keyManager.TestKeysPressed(2) != 0;
    GameState* game;
    unsigned char* resource;
    int mode = state->mode;
    game = GameState::GetInstance();
    IntField0x23c_020a27c4* field = (IntField0x23c_020a27c4*)GameState_GetFollowCamera((char*)game);
    resource = (unsigned char*)(int)game->GetResources();
    if (mode != 1 && state->unknown_19d2_) {
        if (field) {
            if ((field->flags & 2) || !func_020a27c4(field))
                pressed |= g_keyManager.TestKeysPressed(0x200);
        } else {
            pressed |= g_keyManager.TestKeysPressed(0x200);
        }
    }
    int var7 = 0;
    if (((Struct_020676e0_3*)game)->mode == 2) var7 = 1;
    if (!var7 && resource && !func_ov017_021a4e70(resource)) {
        pressed = 0;
        cancelled = 0;
        enabled = 0;
    }
    if (!var7 && state->owner && (state->owner->flags & 0x20)) {
        pressed = 0;
        cancelled = 0;
        enabled = 0;
    }
    int value = -1;
    if (enabled) value = func_0205cecc(state->controls);
    if (pressed) value = func_0205cb64(state->controls);
    else if (cancelled) value = -2;
    state->value = value;
    (state->*data_020f08b8[mode])(value);
}
