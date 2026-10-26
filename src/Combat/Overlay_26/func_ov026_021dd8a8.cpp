#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct S_10088;
struct Struct_ov026_021d8ba0_10;
struct StoreStruct;
struct Container_021dae60;

struct Struct_ov026_021dd8a8_2 {
    unsigned short leader;
    unsigned char ids[8];
    unsigned char count : 4;
    unsigned char unknown_a_4_ : 4;
    unsigned char unknown_b_[0xd];
};

struct Struct_ov026_021dd8a8_3 {
    unsigned char unk0;
    unsigned char kind : 4;
    unsigned char unknown_1_4_ : 2;
    unsigned char unknown_1_6_ : 2;
    unsigned char unk2[2];
    Struct_ov026_021dd8a8_2 entries[4];
};

struct Struct_ov000_02161e30 {
    char pad0[0x81b0];
    Struct_ov026_021dd8a8_3 groups;
    char unknown_8214_[0xc10];
    int busy;
    char unknown_8e28_[0x21];
    unsigned char kind;
};

struct PartyState {
    char pad0[0x8];
    unsigned short netId;
};

struct Struct_ov026_021db090_3 {
    int data[3];
};

struct Struct_ov026_021db090_2 {
    unsigned int flags;
};

struct CombatantView {
    char pad0[0x130];
    Struct_ov026_021db090_2* status;
    char unknown_134_[0x14];
    void* owner;
};

struct Struct_ov026_021d8ba0_8 {
    char pad0[0xc];
    int count;
};

struct Struct_ov026_021dd8a8 {
    char pad0[0x955];
    unsigned char unknown_955_;
};

struct MessageWork {
    char pad0[0x20];
    Struct_ov026_021db090_3* unknown_20_[4];
    unsigned char total;
    unsigned char unknown_31_;
    char unknown_32_[0x5c - 0x32];
    char* text;
    char pad60[0x998 - 0x60];
    int active;
    char unknown_99c_[0x195b - 0x99c];
    unsigned char flags;
    char unknown_195c_[0x19b1 - 0x195c];
    unsigned char unknown_19b1_;
    unsigned char unknown_19b2_;
    char unknown_19b3_[0x19d7 - 0x19b3];
    unsigned char unknown_19d7_;
};

extern "C" void __clear(void*, int);
extern "C" void func_02046380(MessageWork*);
extern "C" void func_020e4ce8(Struct_ov026_021db090_3*, GameObject*, int);
extern "C" Struct_ov026_021d8ba0_8* func_ov017_021b8478(void*);
extern "C" void* func_ov017_021b8468(void*);
extern "C" void func_020dd0b0(int, char*);
extern "C" void func_0204500c(MessageWork*, char*, int, int);
extern "C" void func_02042b98(MessageWork*, int, int, int, int);
extern "C" MessageWork* MessageSystem_GetInstance();
extern "C" GameObject* func_0200fea4(GameState*, int);
extern "C" int func_02010088(S_10088*);
extern "C" int func_ov026_021dd3c4(Struct_ov026_021d8ba0_10*);
extern "C" void func_020465c0(StoreStruct*, int, int);
extern "C" unsigned char GameState_GetPartyOrder(char*, void*);
extern "C" void* func_ov000_02160130();
extern "C" void* func_ov000_02160f08(void*);
extern "C" void* func_ov026_021dae60(Container_021dae60*, int);
extern "C" int func_020a35e0(unsigned char*, unsigned char);
extern "C" char* func_ov026_021d8a78(void*);

extern signed char data_ov026_021de6a6[];
extern signed char data_ov026_021de6a8[];
extern char data_ov026_021deebd[];
extern signed char data_ov026_021de6a2[];
extern char data_ov026_021deec7[];
extern char data_ov026_021deed8[];

// USA: func_ov026_021dd8a8
extern "C" ARM void func_ov026_021dd8a8(Struct_ov000_02161e30* battle, PartyState* party) {
    char message[0x300];
    Struct_ov026_021db090_3 var1[3];
    unsigned short var2[3];
    unsigned char found[3];
    unsigned char kinds[3];
    unsigned char ids[4];
    GameState* gs;
    void* zone;
    MessageWork* win;
    int n;
    Struct_ov026_021dd8a8_2* e;
    int var11;
    int g;
    int extra;
    int j;
    int none;
    unsigned char idle;
    Struct_ov026_021dd8a8_3* groups;
    int i;
    unsigned char present;
    int count;
    void* slots;
    GameResources* res;
    Struct_ov026_021d8ba0_8* view;
    char* text;
    int var25;
    int msgId;

    gs = GameState::GetInstance();
    win = MessageSystem_GetInstance();
    if (battle->busy != 0) {
        return;
    }
    func_02046380(win);
    groups = &battle->groups;
    n = 0;
    __clear(found, sizeof(found));
    __clear(kinds, sizeof(kinds));
    for (e = groups->entries, g = 0; g < groups->unknown_1_4_; e++, g++) {
        var25 = 0;
        for (int k = 0; k < n; k++) {
            if (e->leader == var2[k] || e->leader == 0) {
                if (e->leader == var2[k]) {
                    found[k] = 1;
                }
                var25 = 1;
                break;
            }
        }
        if (var25) {
            continue;
        }
        var2[n] = e->leader;
        for (j = 0; j < e->count; j++) {
            GameObject* c = func_0200fea4(gs, e->ids[j] + 0xc0);
            if (c == NULL || func_02010088((S_10088*)c) || func_ov026_021dd3c4((Struct_ov026_021d8ba0_10*)c)) {
                continue;
            }
            if (((CombatantView*)c)->owner == NULL) {
                continue;
            }
            Struct_ov026_021db090_3* var29 = &var1[n];
            func_020e4ce8(var29, c, 1);
            var29->data[2] &= ~0x80000000;
            win->unknown_20_[n] = var29;
            kinds[n] = e->count;
            n++;
            break;
        }
    }

    res = GetGameResources();
    zone = NULL;
    view = NULL;
    none = (int)zone;
    if (res != NULL) {
        zone = res->unknown_ptr_3718;
    }
    var11 = none - 1;
    if (zone != NULL) {
        view = func_ov017_021b8478(zone);
    }
    if (view != NULL) {
        var11 = view->count;
    }
    extra = 0;
    if (kinds[0] > 1 || found[0] == 1) {
        func_020465c0((StoreStruct*)win, 0, 0);
        extra = 1;
    } else {
        func_020465c0((StoreStruct*)win, 0, 1);
    }

    count = GameState_GetPartyOrder((char*)gs, ids);
    idle = 0;
    present = 0;
    slots = func_ov000_02160f08(func_ov000_02160130());
    for (i = 0; i < count; i++) {
        GameObject* c = gs->GetCombatantByIndex(ids[i]);
        func_ov026_021dae60((Container_021dae60*)slots, ids[i]);
        if (c == NULL) {
            continue;
        }
        if (!func_020a35e0((unsigned char*)party, ids[i])) {
            continue;
        }
        present++;
        if (!(((CombatantView*)c)->status->flags & 1)) {
            idle++;
        }
    }
    win->total = present;
    win->unknown_31_ = idle;

    switch (n) {
    case 1:
        msgId = 6;
        break;
    case 2:
        msgId = 7;
        {
            int arg = 1;
            if (kinds[1] > 1 || found[1] == 1) {
                arg = 0;
            }
            func_020465c0((StoreStruct*)win, 1, arg);
        }
        extra = 1;
        break;
    default:
        if (var11 == 0x36 || var11 == 0x43 || var11 == 0x50) {
            msgId = 8;
        } else {
            extra = 1;
            msgId = 9;
        }
        break;
    }

    text = MessageSystem_GetInstance()->text;
    memset(text, 0, 0x960);
    func_020dd0b0(msgId, text);
    strcpy(message, text);
    if (battle->kind == 1) {
        Struct_ov026_021dd8a8* info = (Struct_ov026_021dd8a8*)func_ov000_02160f08(func_ov017_021b8468(zone));
        unsigned char var33 = party->netId % 2;
        if (info != NULL) {
            info->unknown_955_ = var33;
        }
        msgId = data_ov026_021de6a6[var33];
        if (extra) {
            msgId = data_ov026_021de6a8[var33];
            win->unknown_19d7_ = 1;
        }
        text = MessageSystem_GetInstance()->text;
        memset(text, 0, 0x960);
        func_020dd0b0(msgId, text);
        strcat(message, text);
    } else if (battle->kind == 2) {
        strcat(message, data_ov026_021deebd);
        strcat(message, func_ov026_021d8a78((void*)data_ov026_021de6a2[party->netId % 2]));
        if (extra) {
            win->unknown_19d7_ = 1;
        }
    }
    if (battle->kind != 0) {
        strcat(message, data_ov026_021deec7);
    } else {
        strcat(message, data_ov026_021deed8);
    }
    func_0204500c(win, message, 0, 0xe3);
    win->unknown_19b1_ = 0;
    func_02042b98(win, 2, 0x92, 0xfc, 0x4a);
    win->unknown_19b2_ = 0;
    win->flags |= 2;
    win->active = 1;
}
