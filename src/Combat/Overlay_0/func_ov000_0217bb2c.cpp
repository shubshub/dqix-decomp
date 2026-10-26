#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Input/Input.h"

struct Struct_0205c570;
struct SePlayer;
struct S_10088;

extern "C" int Window_GetSelectedIndex(struct Struct_0205c570* s);
struct Obj_0205da38;
extern "C" int Window_IsSelectionTouched(struct Obj_0205da38* obj, int key);
extern "C" void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern "C" int func_ov000_0217ab48(void* obj);
extern "C" int func_02010088(struct S_10088* obj);
extern "C" GameObject* func_0200ff1c(GameState* gameState, int combatantId);

struct Struct_ov000_0217bb2c_3 {
    char pad0[4];
    unsigned int id : 12;
    unsigned int unknown_5_4_ : 20;
    char pad8[0x10];
    unsigned int unknown_18_0_ : 5;
    unsigned int kind : 7;
    unsigned int rest18 : 20;
};

extern "C" int func_ov000_0217b518(void* obj, int arg1, int arg2);
extern "C" int func_ov000_0217b6d0(void* obj, int arg1, int arg2);
extern "C" int func_ov000_0217b8a4(void* obj, int arg1, int arg2);
extern "C" void func_ov000_0217629c(void* obj);
extern "C" void func_ov000_0217ab8c(void* obj, int a, int b);
extern "C" Struct_ov000_0217bb2c_3* func_ov000_02170cf8(void* obj, int val);
extern "C" void func_ov000_02176e3c(void* ctx, void* obj, int sel, int a, int b, int c);

struct Struct_ov000_0217bb2c {
    char pad0[0x188];
#if defined(jpn)
    char list[0x1faa - 0x188];
#else
    char list[0x1d72 - 0x188];
#endif
    unsigned short flags;
};

struct Struct_ov000_02184294_7 {
#if defined(jpn)
    Struct_ov000_0217bb2c* ctx;
    int field0;
    int field4;
#else
    int field0;
    int field4;
    Struct_ov000_0217bb2c* ctx;
#endif
};

struct Struct_ov000_0217bb2c_2 {
    char pad0[0x10];
    signed char unknown_10_[8];
    signed char depth;
    char unknown_19_[0x21 - 0x19];
    signed char cursor;
    char unknown_22_[0x26 - 0x22];
    unsigned short unknown_26_;
    char pad28[0x2e - 0x28];
    signed char unknown_2e_;
    char unknown_2f_[0x30 - 0x2f];
    signed char* order;
    char unknown_34_[0x38 - 0x34];
    void* window;
#if defined(jpn)
    char unknown_3c_[0x47d - 0x3c];
#else
    char unknown1_3c_[0x43d - 0x3c];
#endif
    signed char unknown_43d_;
    char unknown_43e_[0x441 - 0x43e];
    signed char unknown_441_;
    signed char unknown_442_;
    char unknown_443_;
    unsigned char unknown_444_;
};

extern Struct_ov000_02184294_7 data_ov000_02184294;
extern char g_sePlayer;

// USA: func_ov000_0217bb2c
extern "C" ARM int func_ov000_0217bb2c(Struct_ov000_0217bb2c_2* obj, int arg1, int arg2) {
    data_ov000_02184294.ctx->flags |= 0x100;
    obj->cursor = Window_GetSelectedIndex((struct Struct_0205c570*)obj->window);
    obj->unknown_2e_ = -1;
    if (obj->unknown_441_ != arg1) {
        obj->unknown_441_ = arg1;
        obj->unknown_442_ = obj->order[obj->cursor];
        obj->unknown_444_ = 1;
        func_ov000_0217629c(obj);
        obj->unknown_10_[obj->depth] = 0;
        obj->depth--;
        obj->cursor = -1;
        obj->unknown_2e_ = -1;
        func_ov000_0217ab8c(obj, arg1, arg2);
        int result = -1;
        switch (obj->unknown_10_[obj->depth]) {
        case 0xf:
            result = func_ov000_0217b518(obj, data_ov000_02184294.field4, data_ov000_02184294.field0);
            break;
        case 0x10:
            result = func_ov000_0217b6d0(obj, data_ov000_02184294.field4, data_ov000_02184294.field0);
            break;
        case 0x11:
            result = func_ov000_0217b8a4(obj, data_ov000_02184294.field4, data_ov000_02184294.field0);
            break;
        }
        return result;
    }
    int t = g_keyManager.TestKeysPressed(0x601);
    int active = (t | Window_IsSelectionTouched((struct Obj_0205da38*)obj->window, 0x14)) != 0;
    if (active) {
        GameObject* combatant = func_0200ff1c(GameState::GetInstance(), obj->order[obj->cursor]);
        if (combatant == NULL) {
            return -1;
        }
        int ok = !func_02010088((struct S_10088*)combatant);
        Struct_ov000_0217bb2c_3* entry = func_ov000_02170cf8(obj, obj->unknown_26_);
        if (entry != NULL) {
            if (entry->kind == 0x12) {
                ok = func_02010088((struct S_10088*)combatant);
            }
            if (entry->id == 0x26 || entry->id == 0x27 || entry->id == 0x54) {
                ok = 1;
            }
        } else {
            ok = 1;
        }
        if (ok) {
            obj->unknown_43d_ = obj->unknown_10_[obj->depth];
            obj->unknown_2e_ = obj->order[obj->cursor];
            SePlayer_Play((struct SePlayer*)&g_sePlayer, 1, 0);
            obj->depth++;
            obj->unknown_10_[obj->depth] = 100;
        }
    } else if (func_ov000_0217ab48(obj)) {
        func_ov000_0217629c(obj);
        obj->unknown_10_[obj->depth] = 0;
        obj->depth--;
        obj->cursor = -1;
        obj->unknown_2e_ = -1;
        func_ov000_0217ab8c(obj, arg1, arg2);
        func_ov000_02176e3c(data_ov000_02184294.ctx, obj, obj->unknown_10_[obj->depth], data_ov000_02184294.field4, data_ov000_02184294.field0, 0);
    }
    return -1;
}
