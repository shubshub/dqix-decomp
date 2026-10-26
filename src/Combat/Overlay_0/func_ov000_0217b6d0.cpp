#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Input/Input.h"

struct Struct_0205c570;
struct Struct_0205def8;
struct SePlayer;

extern "C" int Window_GetSelectedIndex(struct Struct_0205c570* s);
extern "C" void func_0205def8(struct Struct_0205def8* s, int clear, int key);
struct Obj_0205da38;
extern "C" int Window_IsSelectionTouched(struct Obj_0205da38* obj, int key);
extern "C" int func_ov000_0217c4e8(void* obj, int bit);
extern "C" void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern "C" void func_ov000_021716d0(void* obj);
extern "C" void* func_02053c6c(unsigned char* obj);
extern "C" int func_ov000_0217ab48(void* obj);
extern "C" void func_ov000_0217629c(void* obj);
extern "C" void func_ov000_0217ab8c(void* obj, int a, int b);
extern "C" void func_ov000_02176e3c(void* ctx, void* obj, int sel, int a, int b, int c);

struct Struct_ov000_0217b6d0_4 {
    char pad0[0x188];
#if defined(jpn)
    char list[0x1faa - 0x188];
#else
    char list[0x1d72 - 0x188];
#endif
    unsigned short flags;
};

struct Struct_ov000_02184294_5 {
#if defined(jpn)
    Struct_ov000_0217b6d0_4* ctx;
    int field0;
    int field4;
    Struct_ov000_0217b6d0_4* const& GetWindow() const {
        return ctx;
    }
#else
    int field0;
    int field4;
    Struct_ov000_0217b6d0_4* ctx;
#endif
    short cur;
};

struct Struct_ov000_0217b6d0 {
#if defined(jpn)
    char pad0[0x8ca];
#else
    char pad0[0x962];
#endif
    unsigned short unknown_962_;
};

struct Struct_ov000_0217b6d0_2 {
    char pad0[0xb8];
    unsigned char state;
};

struct Struct_ov000_0217b6d0_3 {
    char pad0[0x10];
    signed char unknown_10_[8];
    signed char depth;
    char unknown_19_[0x1e - 0x19];
    short selected;
    char pad20[0x26 - 0x20];
    unsigned short unknown_26_;
    char pad28[0x38 - 0x28];
    Struct_ov000_0217b6d0_2* window;
    char unknown_3c_[0x4c - 0x3c];
    int memberIndex;
#if defined(jpn)
    char unknown_50_[0x484 - 0x50];
#else
    char unknown1_50_[0x444 - 0x50];
#endif
    unsigned char unknown_444_;
#if defined(jpn)
    const short& inline_ov000_0217b6d0_2() const {
        return selected;
    }
#endif
};

extern Struct_ov000_02184294_5 data_ov000_02184294;
extern char g_sePlayer;

#if defined(jpn)
// USA: func_ov000_0217b6d0
extern "C" ARM int func_ov000_0217b6d0(Struct_ov000_0217b6d0_3* obj, int arg1, int arg2) {
    Struct_ov000_0217b6d0_4* ctx;
    enum Selection { Enum_ov000_0217b518_m32768 = -32768, Enum_ov000_0217b518_32767 = 32767 };
    Selection cur;
    data_ov000_02184294.ctx->flags |= 0x100;
    const short prev = obj->inline_ov000_0217b6d0_2();
    cur = (Selection)(short)Window_GetSelectedIndex((struct Struct_0205c570*)obj->window);
    obj->selected = cur;
    {
    ctx = data_ov000_02184294.GetWindow();
    func_0205def8((struct Struct_0205def8*)ctx->list, 1, 0x23);
    if (prev != cur) {
        return -1;
    }
    int t = g_keyManager.TestKeysPressed(0x601);
    bool active = (t | Window_IsSelectionTouched((struct Obj_0205da38*)obj->window, 0x14)) != 0;
    if (active || obj->unknown_444_ != 0) {
        if (!func_ov000_0217c4e8(obj, cur)) {
            return obj->unknown_10_[obj->depth];
        }
        func_0205def8((struct Struct_0205def8*)ctx->list, 0, 0x23);
        SePlayer_Play((struct SePlayer*)&g_sePlayer, 1, 0);
        func_ov000_021716d0(obj);
        GameObject* member = GameState::GetInstance()->GetPartyMemberByIndex(obj->memberIndex);
        if (member != NULL) {
            Struct_ov000_0217b6d0* info = (Struct_ov000_0217b6d0*)func_02053c6c((unsigned char*)member);
            if (info != NULL) {
                info->unknown_962_ = obj->unknown_26_;
            }
        }
        if (obj->unknown_10_[obj->depth] != 0x64) {
            obj->window->state = 0x10;
        }
        return obj->unknown_10_[obj->depth];
    }
    if (func_ov000_0217ab48(obj)) {
        func_ov000_0217629c(obj);
        obj->unknown_10_[obj->depth] = 0;
        obj->depth--;
        obj->selected = -1;
        obj->unknown_26_ = 0;
        func_ov000_0217ab8c(obj, arg1, arg2);
        func_ov000_02176e3c(data_ov000_02184294.ctx, obj, obj->unknown_10_[obj->depth], data_ov000_02184294.field4, data_ov000_02184294.field0, 0);
    }
    return -1;
    }
}
#else
// USA: func_ov000_0217b6d0
extern "C" ARM int func_ov000_0217b6d0(Struct_ov000_0217b6d0_3* obj, int arg1, int arg2) {
    Struct_ov000_0217b6d0_4* ctx;
    short cur;
    data_ov000_02184294.ctx->flags |= 0x100;
    short prev = obj->selected;
    cur = Window_GetSelectedIndex((struct Struct_0205c570*)obj->window);
    obj->selected = cur;
    ctx = data_ov000_02184294.ctx;
    func_0205def8((struct Struct_0205def8*)ctx->list, 1, 0x23);
    if (prev != cur) {
        return -1;
    }
    int t = g_keyManager.TestKeysPressed(0x601);
    int active = (t | Window_IsSelectionTouched((struct Obj_0205da38*)obj->window, 0x14)) != 0;
    if (active || obj->unknown_444_ != 0) {
        if (!func_ov000_0217c4e8(obj, cur)) {
            return obj->unknown_10_[obj->depth];
        }
        func_0205def8((struct Struct_0205def8*)ctx->list, 0, 0x23);
        SePlayer_Play((struct SePlayer*)&g_sePlayer, 1, 0);
        func_ov000_021716d0(obj);
        GameObject* member = GameState::GetInstance()->GetPartyMemberByIndex(obj->memberIndex);
        if (member != NULL) {
            Struct_ov000_0217b6d0* info = (Struct_ov000_0217b6d0*)func_02053c6c((unsigned char*)member);
            if (info != NULL) {
                info->unknown_962_ = obj->unknown_26_;
            }
        }
        if (obj->unknown_10_[obj->depth] != 0x64) {
            obj->window->state = 0x10;
        }
        return obj->unknown_10_[obj->depth];
    }
    if (func_ov000_0217ab48(obj)) {
        func_ov000_0217629c(obj);
        obj->unknown_10_[obj->depth] = 0;
        obj->depth--;
        obj->selected = -1;
        obj->unknown_26_ = 0;
        func_ov000_0217ab8c(obj, arg1, arg2);
        func_ov000_02176e3c(data_ov000_02184294.ctx, obj, obj->unknown_10_[obj->depth], data_ov000_02184294.field4, data_ov000_02184294.field0, 0);
    }
    return -1;
}
#endif
