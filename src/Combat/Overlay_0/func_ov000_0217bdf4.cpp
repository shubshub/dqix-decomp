#include <globaldefs.h>
#include "Resource/ActionDataTables.h"
#include "GameState/GameState.h"
#include "Input/Input.h"

#if defined(jpn)
#define data_ov000_02183658 data_ov000_02184714
#endif
struct Struct_0205c570;
struct Struct_0205def8;
struct SePlayer;

extern "C" int Window_GetSelectedIndex(struct Struct_0205c570* s);
extern "C" void func_0205def8(struct Struct_0205def8* s, int clear, int key);
struct Obj_0205da38;
extern "C" int Window_IsSelectionTouched(struct Obj_0205da38* obj, int key);
extern "C" void* func_02053c6c(unsigned char* obj);
extern "C" void SePlayer_Play(struct SePlayer* obj, int a, int b);

extern "C" void* func_02079e2c(char* p, int key);
extern "C" int func_ov000_0217ab48(void* obj);
extern "C" void func_ov000_021718a4(void* obj);
extern "C" void func_ov000_0217629c(void* obj);
extern "C" void func_ov000_0217ab8c(void* obj, int a, int b);
extern "C" void func_ov000_02176e3c(void* ctx, void* obj, int sel, int a, int b, int c);

struct Struct_ov000_0217bdf4_4 {
    char pad0[0x188];
#if defined(jpn)
    char list[0x1faa - 0x188];
#else
    char list[0x1d72 - 0x188];
#endif
    unsigned short flags;
};

struct Struct_ov000_02184294_8 {
#if defined(jpn)
    Struct_ov000_0217bdf4_4* ctx;
    int field0;
    int field4;
#else
    int field0;
    int field4;
    Struct_ov000_0217bdf4_4* ctx;
#endif
};

struct Struct_ov000_0217bdf4 {
    int field0;
    unsigned int id : 12;
};

struct Struct_ov000_0217bdf4_2 {
#if defined(jpn)
    char pad0[0x8b8];
#else
    char pad0[0x950];
#endif
    int unknown_950_;
};

struct Struct_ov000_0217bdf4_3 {
    char pad0[0x10];
    signed char unknown_10_[8];
    signed char depth;
    char unknown_19_[0x1d - 0x19];
    signed char unknown_1d_;
    char pad1e[0x23 - 0x1e];
    signed char field23;
    char pad24[0x26 - 0x24];
    unsigned short field26;
    char pad28[0x38 - 0x28];
    void* field38;
    char unknown_3c_[0x4c - 0x3c];
    int memberIndex;
#if defined(jpn)
    char unknown_50_[0x484 - 0x50];
#else
    char unknown1_50_[0x444 - 0x50];
#endif
    unsigned char unknown_444_;
};

extern Struct_ov000_02184294_8 data_ov000_02184294;
extern char g_sePlayer;
extern short data_ov000_02183658[];

// USA: func_ov000_0217bdf4
extern "C" ARM int func_ov000_0217bdf4(Struct_ov000_0217bdf4_3* obj, int arg1, int arg2) {
    data_ov000_02184294.ctx->flags |= 0x100;
    obj->field23 = Window_GetSelectedIndex((struct Struct_0205c570*)obj->field38);
    Struct_ov000_0217bdf4_4* ctx = data_ov000_02184294.ctx;
    func_0205def8((struct Struct_0205def8*)ctx->list, 1, 0x16);
    int t = g_keyManager.TestKeysPressed(0x601);
    int active = (t | Window_IsSelectionTouched((struct Obj_0205da38*)obj->field38, 0x14)) != 0;
    if (active || obj->unknown_444_ != 0) {
        GameObject* member = GameState::GetInstance()->GetPartyMemberByIndex(obj->memberIndex);
        if (member == NULL) {
            return -1;
        }
        int kind = ((Struct_ov000_0217bdf4_2*)func_02053c6c((unsigned char*)member))->unknown_950_;
        SePlayer_Play((struct SePlayer*)&g_sePlayer, 1, 0);
        obj->unknown_1d_ = 0;
        ActionDataTables* data = func_020797dc();
        if (data == NULL) {
            return -1;
        }
        Struct_ov000_0217bdf4* entry = (Struct_ov000_0217bdf4*)func_02079e2c((char*)data, data_ov000_02183658[kind]);
        if (entry == NULL) {
            return -1;
        }
        obj->field26 = entry->id;
        func_ov000_021718a4(obj);
        func_0205def8((struct Struct_0205def8*)ctx->list, 0, 0x16);
        return obj->unknown_10_[obj->depth];
    }
    if (func_ov000_0217ab48(obj)) {
        func_ov000_0217629c(obj);
        obj->unknown_10_[obj->depth] = 0;
        obj->depth--;
        obj->field23 = -1;
        obj->unknown_1d_ = -1;
        obj->field26 = 0;
        func_ov000_0217ab8c(obj, arg1, arg2);
        func_ov000_02176e3c(data_ov000_02184294.ctx, obj, obj->unknown_10_[obj->depth], data_ov000_02184294.field4, data_ov000_02184294.field0, 0);
    }
    return -1;
}
