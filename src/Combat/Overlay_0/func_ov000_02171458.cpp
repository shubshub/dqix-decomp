#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* Zone3D_GetInstance(void);

struct Container020e0310;
char* KeyTable_Get(struct Container020e0310* c, int key);

struct Struct_0203c108_3 {
    char unknown_0_[0x14];
    short unknown_14_;
};
extern "C" void func_0203c108(struct Struct_0203c108_3* arg0, char* arg1);

extern "C" int func_ov000_02153a8c(GameObject* arg0);
extern "C" int func_020dd290(void* arg0, unsigned int arg1);

struct Struct_ov000_02171458_3 {
    int unknown_0_;
    unsigned int unknown_4_0_ : 12;
    unsigned int unknown_5_4_ : 20;
    unsigned int unknown_8_0_ : 8;
    unsigned int unknown_9_0_ : 24;
};

extern "C" int func_ov000_02171210(struct Struct_ov000_02171458_3* arg0, void* arg1);
extern "C" struct Struct_ov000_02171458_3* func_ov000_02170cf8(void* arg0, int arg1);
extern "C" void* __clear(void* arg0, int arg1);
#if !defined(jpn)
extern "C" void func_020e4864(int arg0, char* arg1, int arg2, int arg3, int arg4, int arg5);
#endif
extern "C" void func_0206819c(const char* arg0, char* arg1, int arg2);

struct Struct_ov000_02171458 {
    char unknown_0_[6];
    short unknown_6_;
    signed char unknown_8_[8];
    signed char unknown_10_;
    char unknown_11_[0x15 - 0x11];
    unsigned char unknown_15_;
    char unknown_16_[0x18 - 0x16];
    signed char unknown_18_;
    char unknown_19_[0x1e - 0x19];
    unsigned short unknown_1e_;
};

struct Struct_ov000_02171458_2 {
    char unknown_0_[4];
    struct Struct_0201099c_3* unknown_4_;
    struct Struct_ov000_02171458 unknown_8_;
    char unknown_28_[0x4c - 0x28];
    int unknown_4c_;
    struct Struct_0203c108_3 unknown_50_;
    char unknown_66_[LOW_REGION(0xdc, 0x9c) - 0x66];
    struct Struct_ov000_02171458_3* unknown_9c_[1];
};

// USA: func_ov000_02171458
extern "C" ARM void func_ov000_02171458(struct Menu02171458* menu) {
    Zone3D_GetInstance();
    struct MenuState02171458* state = &menu->state;
    int cursor = state->cursor;
    if (menu->entries[cursor] == NULL) {
        state->depth++;
        state->results[menu->state.depth] = 0xe;
        state->field15 = 0;
        SwapGlobalEntry0203c108(&menu->label, KeyTable_Get(menu->container, 5));
        return;
    }
    GameObject* var2 = func_0200ff1c(GameState::GetInstance(), arg0->unknown_4c_);
    int var3 = arg0->unknown_9c_[var1]->unknown_8_0_;
    if (var2 != NULL && func_ov000_02153a8c(var2)) {
        var3 = 0;
    } else if (arg0->unknown_9c_[var1]->unknown_4_0_ == 0x28) {
        var3 = 0x14;
    } else if (arg0->unknown_9c_[var1]->unknown_8_0_ >= 0xff) {
        var3 = 1;
    } else {
        var3 = func_020dd290(var2, var3);
    }
    if (arg0->unknown_8_.unknown_6_ < var3) {
        var0->unknown_10_++;
        var0->unknown_8_[arg0->unknown_8_.unknown_10_] = 0x1a;
        return;
    }
    var0->unknown_1e_ = arg0->unknown_9c_[var1]->unknown_4_0_;
    var0->unknown_10_++;
    var0->unknown_8_[var0->unknown_10_] = func_ov000_02171210(arg0->unknown_9c_[var1], arg0);
    struct Struct_ov000_02171458_3* var4 = func_ov000_02170cf8(arg0, var0->unknown_1e_);
    if (var4 == NULL) {
        return;
    }
#if defined(jpn)
    func_0203c108(&arg0->unknown_50_, (char*)var4->unknown_0_);
#else
    char var5[0x80];
    __clear(var5, 0x80);
    char var6[0x80];
    __clear(var6, 0x80);
    func_020e4864(var4->unknown_0_, var5, 1, 0, 0, 0);
    func_0206819c(var5, var6, 0);
    func_0203c108(&arg0->unknown_50_, var6);
#endif
}
