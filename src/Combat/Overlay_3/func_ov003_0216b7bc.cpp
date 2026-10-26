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

struct MsgCtl0216b7bc {
    char pad0[REGION_LAYOUT(0x28, 0x5c)];
    char* textBuf;
    char pad60[REGION_LAYOUT(0x868, 0x998) - REGION_LAYOUT(0x2c, 0x60)];
    int busy;
    int mode;
    int status;
    char unknown_9a4_[REGION_LAYOUT(0x17e2, 0x19b2) - REGION_LAYOUT(0x874, 0x9a4)];
    unsigned char unknown_19b2_;
};

struct Progress840 {
    char pad0[0x1b42];
    unsigned char unknown_1b42_;
};

struct Container020e0310;

struct Struct_ov003_0216b7bc_3 {
    char pad0[4];
    short state;
    short unknown_6_;
    char pad8[2];
    short request;
    char unknown_c_[REGION_LAYOUT(0x11b4, 0x1324) - 0xc];
    char names[4];
};

extern "C" struct MsgCtl0216b7bc* MessageSystem_GetInstance();
extern "C" void* Zone3D_GetInstance(void);
extern "C" const char* KeyTable_Get(struct Container020e0310* c, int key);
extern "C" int Text_Append(char* dst, const char* src);
extern "C" void func_02046380(struct MsgCtl0216b7bc* ctl);
#if !defined(jpn)
extern "C" void func_0204500c(struct MsgCtl0216b7bc* ctl, char* text, int a, int b);
#endif
#if defined(jpn)
extern "C" void func_ov003_0216d8d4(struct Struct_ov003_0216b7bc_3* obj, int key);
extern "C" void func_0204500c(struct MsgCtl0216b7bc* ctl, char* text, int flags);
#else
extern "C" void func_ov003_0216d8d4(struct Struct_ov003_0216b7bc_3* obj, int key, int p3, int p4, int p5);
#endif

extern char data_ov003_021801b2[];
extern char data_ov003_021801c2[];

// USA: func_ov003_0216b7bc
extern "C" ARM void func_ov003_0216b7bc(struct Struct_ov003_0216b7bc_3* obj) {
    struct MsgCtl0216b7bc* ctl = MessageSystem_GetInstance();
    GameState::GetInstance();
    if (obj->request == 3) {
        obj->unknown_6_ = 2;
        obj->request = 0;
    }
    if (obj->unknown_6_ == 0) {
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
        if (progress->unknown_1b42_ == 0) {
            Text_Append(buf, data_ov003_021801b2);
        } else {
            Text_Append(buf, data_ov003_021801c2);
        }
        unsigned char flags = progress->unknown_1b42_;
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
        int idx = -1;
        if (flags & 1) {
            idx = 1;
        } else if (flags & 2) {
            idx = 2;
        } else if (flags & 4) {
            idx = 3;
        } else if (flags & 8) {
            idx = 4;
        } else if (flags & 0x10) {
            idx = 5;
        }
        if (idx >= 0) {
            Text_Append(buf, KeyTable_Get((struct Container020e0310*)obj->names, idx));
        }
#endif
        progress->unknown_1b42_ &= ~0xff;
#if defined(jpn)
        func_0204500c(ctl, buf, 0);
#else
        func_02046380(ctl);
        func_0204500c(ctl, buf, 0, 0xe3);
#endif
        ctl->unknown_19b2_ = 1;
        ctl->mode = 2;
        ctl->busy = 1;
        obj->unknown_6_ = 1;
    } else if (obj->unknown_6_ == 1) {
        if (ctl->status == 3) {
#if defined(jpn)
            func_ov003_0216d8d4(obj, 0x29);
#else
            func_ov003_0216d8d4(obj, 0x29, -1, -1, -1);
#endif
            obj->unknown_6_ = 2;
        }
    } else if (obj->unknown_6_ == 2 && ctl->status == 3) {
        obj->state = 2;
        obj->unknown_6_ = 0;
    }
}
