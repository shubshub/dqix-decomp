#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_02011b24;
struct Struct_02093428_5;

extern "C" void Zone3D_GetInstance();
extern "C" int func_020457e0(char* g);
extern "C" void func_020531f0(GameObject* c);
extern "C" void MessageSystem_Stop(char* g);
extern "C" void func_020945ac(struct Struct_02093428_5* ctx);
extern "C" void func_0200fb40(void* obj);
extern "C" void MessageSystem_Reset(char* obj);
extern "C" void func_02011b24(struct Struct_02011b24* obj);
extern "C" void func_02011af0(void* obj);
extern "C" void func_ov017_021acd30(char* self, unsigned char a, unsigned char b, unsigned char c);
extern "C" void func_ov017_021cf4b0(int a, int b);
extern "C" void func_ov017_021d1810(int, int, signed char);
extern "C" int GameState_GetProtagonistIndex(GameState* gs);
extern "C" int* func_020936f8(void);
extern "C" char* MessageSystem_GetInstance(void);
extern "C" int GameObject_IsGesturing(signed char* p);

struct Struct_02093428_6 {
    char unk0[0x30];
    short unknown_30_;
    char unknown_32_[0x34 - 0x32];
    unsigned char field34;
    unsigned char unknown_35_;
};

struct CombatantIndexList02093428 {
    char unk0[0xf78];
    unsigned char entries[4];
    unsigned char count;
};

struct Struct_02093428_2 {
#if defined(jpn)
    char unk0[0x868];
#else
    char unk0[0x998];
#endif
    int unknown_998_;
    char unknown_99c_[0x9a0 - 0x99c];
    int unknown_9a0_;
};

struct Struct_02093428_3 {
#if defined(jpn)
    char unk0[0x7ca0];
#else
    char unk0[0x7f74];
#endif
    unsigned char unknown_7f74_;
    unsigned char unknown_7f75_;
};

struct Struct_02093428_4 {
    char unk0[0xbe];
    unsigned char unknown_be_;
#if defined(jpn)
    char unknown_bf_[0x1a6 - 0xbf];
#else
    char unknown1_bf_[0x1b2 - 0xbf];
#endif
    unsigned short field1b2;
};

// USA: func_02093428
extern "C" ARM void func_02093428(struct Struct_02093428_6* s) {
    GameState* bs = GameState::GetInstance();
    char* gf = MessageSystem_GetInstance();
    Zone3D_GetInstance();
    unsigned char v = GameState_GetProtagonistIndex(bs);
    unsigned char state = s->unknown_35_;

    if (state == 0) {
        struct CombatantIndexList02093428* list = (struct CombatantIndexList02093428*)GameState_GetParty(bs);
        unsigned char count = list->count;
        for (unsigned char i = 0; i < count; i++) {
            GameObject* c = func_0200ff1c(bs, list->entries[i]);
            if (c != 0 && GameObject_IsGesturing((signed char*)c) != 0) {
                func_020531f0(c);
            }
        }
        s->unknown_30_ = 10;
        s->unknown_35_++;
        return;
    }

    if (state == 1) {
        if (((struct Struct_02093428_3*)bs)->unknown_7f74_ == 0) {
            s->unknown_35_ = 3;
            return;
        }
        if (((struct Struct_02093428_2*)gf)->unknown_9a0_ != 0) return;
        int r = func_020457e0(gf);
        if (r == 0) {
            s->unknown_35_++;
            return;
        }
        if (r != 1) return;
        s->unknown_30_ = 3;
        s->unknown_35_ = 4;
        func_ov017_021cf4b0(v, 3);
        func_ov017_021d1810(10000, -1, (signed char)GameState_GetProtagonistIndex(bs));
        return;
    }

    if (state == 2) {
        if (((struct Struct_02093428_3*)bs)->unknown_7f74_ == 0) {
            s->unknown_30_ = 11;
            s->unknown_35_ = 4;
            return;
        }
        func_ov017_021cf4b0(v, 2);
        unsigned char flag = 0;
        GameObject* c = func_0200ff1c(bs, 0);
        if (c != 0) {
            if (((struct Struct_02093428_4*)c)->unknown_be_ == 2 || c->obj3D_.GetField06() == 0x170c) {
                unsigned short t = ((struct Struct_02093428_4*)c)->field1b2;
                if (t != 0) {
                    if (t >= 1 && t <= 0x7fff) {
                        flag = 1;
                    } else if (t >= 0x8005 && t <= 0x83ed) {
                        flag = 1;
                    }
                }
            }
        }
        func_ov017_021acd30((char*)bs->GetResources(), 1, flag, 0);
        func_02011af0(bs);
        if (((struct Struct_02093428_3*)bs)->unknown_7f75_ != 0) {
            func_02011b24((struct Struct_02011b24*)bs);
        }
        func_020945ac((struct Struct_02093428_5*)func_020936f8());
        s->field34 = 4;
        s->unknown_35_ = 0;
        return;
    }

    if (state == 3) {
        MessageSystem_Reset(gf);
        MessageSystem_Stop(gf);
        func_020945ac((struct Struct_02093428_5*)func_020936f8());
        s->field34 = 4;
        s->unknown_35_ = 0;
        func_0200fb40(bs);
        return;
    }

    if (state == 4) {
        if (((struct Struct_02093428_2*)gf)->unknown_998_ == 0) {
            s->unknown_35_ = 3;
        }
    }
}
