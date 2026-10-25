#include <globaldefs.h>
#if defined(jpn)
#define REGION_LAYOUT(j,u) j
#define data_ov003_021801b2 data_ov003_0217e96e
#define data_ov003_021801c2 data_ov003_0217e97e
#else
#define REGION_LAYOUT(j,u) u
#endif

#include "GameState/GameState.h"
#include "std_library_functions.h"

struct Struct_ov003_0216b7bc {
    char unknown_0_[REGION_LAYOUT(0x28, 0x5c)];
    char* unknown_5c_;
    char unknown_60_[REGION_LAYOUT(0x868, 0x998) - REGION_LAYOUT(0x2c, 0x60)];
    int unknown_998_;
    int unknown_99c_;
    int unknown_9a0_;
    char unknown_9a4_[REGION_LAYOUT(0x17e2, 0x19b2) - REGION_LAYOUT(0x874, 0x9a4)];
    unsigned char unknown_19b2_;
};

struct Struct_ov003_0216b7bc_2 {
    char unknown_0_[0x1b42];
    unsigned char unknown_1b42_;
};

struct Struct_0201099c_3;

struct Struct_ov003_0216b7bc_3 {
    char unknown_0_[4];
    short unknown_4_;
    short unknown_6_;
    char unknown_8_[2];
    short unknown_a_;
    char unknown_c_[REGION_LAYOUT(0x11b4, 0x1324) - 0xc];
    char unknown_1324_[4];
};

struct MsgCtl0216b7bc* MessageSystem_GetInstance();
extern "C" void* Zone3D_GetInstance(void);
const char* KeyTable_Get(struct Container020e0310* c, int key);
int Text_Append(char* dst, const char* src);
extern "C" void func_02046380(struct MsgCtl0216b7bc* ctl);
#if !defined(jpn)
extern "C" void func_0204500c(struct Struct_ov003_0216b7bc* arg0, char* arg1, int arg2, int arg3);
#endif
#if defined(jpn)
extern "C" void func_ov003_0216d8d4(struct Struct_ov003_0216b7bc_3* arg0, int arg1);
extern "C" void func_0204500c(struct Struct_ov003_0216b7bc* arg0, char* arg1, int arg2);
#else
extern "C" void func_ov003_0216d8d4(struct Struct_ov003_0216b7bc_3* arg0, int arg1, int arg2, int arg3, int arg4);
#endif

extern char data_ov003_021801b2[];
extern char data_ov003_021801c2[];

// USA: func_ov003_0216b7bc
extern "C" ARM void func_ov003_0216b7bc(struct Msg0216b7bc* obj) {
    struct MsgCtl0216b7bc* ctl = MessageSystem_GetInstance();
    GameState::GetInstance();
    if (arg0->unknown_a_ == 3) {
        arg0->unknown_6_ = 2;
        arg0->unknown_a_ = 0;
    }
    if (arg0->unknown_6_ == 0) {
#if defined(jpn)
        char* buf;
        struct Progress840* progress = (struct Progress840*)((char*)Zone3D_GetInstance() + REGION_LAYOUT(0x860, 0x840));
        buf = ctl->textBuf;
#else
        struct Progress840* progress = (struct Progress840*)((char*)Zone3D_GetInstance() + REGION_LAYOUT(0x860, 0x840));
        char* buf = ctl->textBuf;
#endif
        memset(buf, 0, REGION_LAYOUT(0x800, 0x960));
        Text_Append(buf, KeyTable_Get((struct Container020e0310*)obj->names, 0));
        if (progress->rewardFlags == 0) {
            Text_Append(buf, data_ov003_021801b2);
        } else {
            Text_Append(buf, data_ov003_021801c2);
        }
        unsigned char var3 = var1->unknown_1b42_;
#if defined(jpn)
        if (flags & 0x1) {
            Text_Append(buf, KeyTable_Get((struct Container020e0310*)obj->names, 1));
        }
        else if (flags & 0x2) {
            Text_Append(buf, KeyTable_Get((struct Container020e0310*)obj->names, 2));
        }
        else if (flags & 0x4) {
            Text_Append(buf, KeyTable_Get((struct Container020e0310*)obj->names, 3));
        }
        else if (flags & 0x8) {
            Text_Append(buf, KeyTable_Get((struct Container020e0310*)obj->names, 4));
        }
        else if (flags & 0x10) {
            Text_Append(buf, KeyTable_Get((struct Container020e0310*)obj->names, 5));
        }
#else
        int var4 = -1;
        if (var3 & 1) {
            var4 = 1;
        } else if (var3 & 2) {
            var4 = 2;
        } else if (var3 & 4) {
            var4 = 3;
        } else if (var3 & 8) {
            var4 = 4;
        } else if (var3 & 0x10) {
            var4 = 5;
        }
        if (idx >= 0) {
            Text_Append(buf, KeyTable_Get((struct Container020e0310*)obj->names, idx));
        }
#endif
        var1->unknown_1b42_ &= ~0xff;
#if defined(jpn)
        func_0204500c(var0, var2, 0);
#else
        func_02046380(var0);
        func_0204500c(var0, var2, 0, 0xe3);
#endif
        var0->unknown_19b2_ = 1;
        var0->unknown_99c_ = 2;
        var0->unknown_998_ = 1;
        arg0->unknown_6_ = 1;
    } else if (arg0->unknown_6_ == 1) {
        if (var0->unknown_9a0_ == 3) {
#if defined(jpn)
            func_ov003_0216d8d4(arg0, 0x29);
#else
            func_ov003_0216d8d4(arg0, 0x29, -1, -1, -1);
#endif
            arg0->unknown_6_ = 2;
        }
    } else if (arg0->unknown_6_ == 2 && var0->unknown_9a0_ == 3) {
        arg0->unknown_4_ = 2;
        arg0->unknown_6_ = 0;
    }
}
