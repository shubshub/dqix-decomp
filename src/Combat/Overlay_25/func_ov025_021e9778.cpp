#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
#define data_ov025_021ef538 data_ov025_021ef818
#define data_ov025_021ef8de data_ov025_021efba0
#endif

struct Struct_02078398_2 {
    unsigned char unknown_0_;
    unsigned char unknown_1_[0xf];
    unsigned char f10;
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
    unsigned char unknown_11_4_ : 1;
    unsigned char unknown_11_5_ : 1;
    unsigned char unknown_11_6_ : 1;
    unsigned char unknown_11_7_ : 1;
    short f12;
    short f14;
    short unknown_16_;
    short f18;
    short unknown_1a_;
    short f1c;
    short pad1e;
    int f20; int f24; int f28; int unknown_2c_; int unknown_30_;
    int f34; int unknown_38_; int f3c; int f40;
    int unknown_44_; int unknown_48_; int unknown_4c_;
};

struct Struct_ov025_021e9778_7 {
    int code;
    struct Struct_ov025_021e9778_7* next;
};

struct Struct_ov025_021e9778_8 {
    unsigned short id;
    unsigned char unknown_2_[8];
    unsigned char kind;
};

struct Struct_ov000_0215440c_2;
struct Struct_ov000_02160094;
struct Struct_ov025_021e9778_9;
struct Struct_ov025_021e9778;
struct Struct_ov025_021e9778_2;
struct Struct_ov025_021e9778_3;
struct Struct_ov025_021e9778_4;
struct Struct_ov025_021e9778_5;
struct Struct_ov025_021e9778_6 {
    unsigned int unknown_0_0_ : 12;
    unsigned int mode : 4;
    unsigned int unknown16 : 16;
};

typedef int (*Type_02000c9c_17)(struct Struct_ov025_021e9778_7*, struct Struct_ov025_021e9778_8*, void*, int);

extern "C" void* func_ov000_02160130(void);
extern "C" void* func_ov000_02160f00(void* obj);
extern "C" void* func_ov000_02160f20(void* obj);
extern "C" Struct_ov000_02160094* func_ov000_02160094(Struct_ov000_0215440c_2* list, int index);
extern "C" void func_02078484(Struct_02078398_2* p);
extern "C" void* func_ov000_02160f14(void* obj);
extern "C" void Camera_Shake(unsigned char* obj, int a, int b);
extern "C" short func_ov000_0216352c(int id, float a, float b);
extern "C" void func_02057fb4(void* list, int id, void* argument);
extern "C" void* func_02057924(void);
extern "C" GameObject* func_0200fea4(GameState* battleStruct, int combatantId);
extern "C" void func_ov025_021eb6fc(Struct_ov025_021e9778_9* self, int force);
extern "C" int func_ov025_021eb46c(Struct_ov025_021e9778* self);
extern "C" int func_ov025_021eb204(Struct_ov025_021e9778_2* self);
extern "C" void func_ov025_021e9b2c(Struct_ov025_021e9778_3* self);
extern "C" void func_ov025_021ebb90(Struct_ov025_021e9778_4* obj);
extern "C" void func_ov025_021e9a94(Struct_ov025_021e9778_5* obj);
extern "C" char* strcpy(char* d, const char* s);

extern void* data_ov025_021ef994;
extern Type_02000c9c_17 data_ov025_021ef538[];
extern unsigned int data_ov025_021ef9a4;
extern char data_ov025_021ef8de[];

// USA: func_ov025_021e9778
extern "C" ARM void func_ov025_021e9778(void* self) {
    unsigned char* object = (unsigned char*)self;
    GameState* gs = GameState::GetInstance();
    void* work = func_ov000_02160130();
    void* var3 = func_ov000_02160f00(work);
    struct Struct_ov025_021e9778_8* slot = (struct Struct_ov025_021e9778_8*)func_ov000_02160f20(work);
    data_ov025_021ef994 = self;
    if ((*(unsigned short*)(object + 0x5ce)) != 0) {
        unsigned int var5 = gs->GetEffectiveDeltaTime();
        if (var5 < (unsigned int)(*(unsigned short*)(object + 0x5ce))) {
            (*(unsigned short*)(object + 0x5ce)) = (unsigned short)((*(unsigned short*)(object + 0x5ce)) - var5);
            return;
        }
        (*(unsigned short*)(object + 0x5ce)) = 0;
        func_ov025_021eb6fc((Struct_ov025_021e9778_9*)self, 0);
    }
    if ((*(unsigned char*)(object + 0x839)) == 0) {
        return;
    }
    if (func_ov025_021eb46c((Struct_ov025_021e9778*)self) != 0) {
        return;
    }
    if (func_ov025_021eb204((Struct_ov025_021e9778_2*)self) != 0) {
        return;
    }
    while ((*(Struct_ov025_021e9778_7**)(object + 0x4)) != 0) {
        int ret;
        if ((*(unsigned short*)(object + 0x57c)) != 0) {
            if ((*(Struct_ov025_021e9778_7**)(object + 0x4))->code == 0xa) {
                ret = data_ov025_021ef538[(*(Struct_ov025_021e9778_7**)(object + 0x4))->code]((*(Struct_ov025_021e9778_7**)(object + 0x4)), slot, var3, (*(int*)(object + 0xc)));
            } else {
                ret = 1;
            }
        } else {
            if ((*(Struct_ov025_021e9778_7**)(object + 0x4))->code == 0xb) {
                ret = 0;
                (*(Struct_ov025_021e9778_7**)(object + 0x4)) = 0;
            } else {
                ret = data_ov025_021ef538[(*(Struct_ov025_021e9778_7**)(object + 0x4))->code]((*(Struct_ov025_021e9778_7**)(object + 0x4)), slot, var3, (*(int*)(object + 0xc)));
            }
        }
        if (ret == 0) {
            break;
        }
        if (ret == -1) {
            (*(Struct_ov025_021e9778_7**)(object + 0x4)) = (*(Struct_ov025_021e9778_7**)(object + 0x4))->next;
            break;
        }
        (*(Struct_ov025_021e9778_7**)(object + 0x4)) = (*(Struct_ov025_021e9778_7**)(object + 0x4))->next;
    }
    func_ov025_021e9b2c((Struct_ov025_021e9778_3*)self);
    func_ov025_021ebb90((Struct_ov025_021e9778_4*)(object + 0x22c));
    data_ov025_021ef9a4 &= ~4;
    if ((*(int*)(object + 0x224)) != 0) {
        func_ov025_021e9a94((Struct_ov025_021e9778_5*)self);
    }
    if (*(void**)(object + 8) != NULL && ((Struct_ov025_021e9778_6*)((char*)*(void**)(object + 8) + 0x18))->mode == 2) {
        int id = *(unsigned short*)((char*)func_ov000_02160094((Struct_ov000_0215440c_2*)slot, 0) + 0x20);
        int flag = 0;
        GameState* gs2 = GameState::GetInstance();
        int isParty = (id >= 0xc0 && id <= 0xc7);
        if (isParty != 0) {
            GameObject* c = func_0200fea4(gs2, id);
            if (c != 0) {
                short v = c->obj3D_.unknown_2_;
                if (v == 0x200 || (unsigned int)(v - 0x289) <= 4) {
                    flag = 1;
                } else {
                    if (v == 0xb9 && slot->id == 0x247) {
                        flag = 1;
                    }
                }
            }
        }
        if (flag == 0 && (data_ov025_021ef9a4 & 0x200) && !(data_ov025_021ef9a4 & 0x400)) {
            void* list = func_02057924();
            struct Struct_02078398_2 s;
            func_02078484(&s);
            s.f14 = *(unsigned short*)((char*)func_ov000_02160094((Struct_ov000_0215440c_2*)slot, 0) + 0x20);
            if (slot->kind & 1) {
                strcpy((char*)&s, data_ov025_021ef8de);
                unsigned char* p = (unsigned char*)func_ov000_02160f14(work);
                Camera_Shake(p, 0x199, 0x3e8);
            }
            int inParty = (id >= 0xc0 && id <= 0xc7);
            if (inParty != 0) {
                short t = func_ov000_0216352c(id, 1.0f, 0.5f);
                s.unknown_44_ = t;
                s.unknown_48_ = t;
                s.unknown_4c_ = t;
            }
            func_02057fb4(list, 4, &s);
            data_ov025_021ef9a4 |= 0x400;
        }
    }
    data_ov025_021ef9a4 &= ~8;
}
