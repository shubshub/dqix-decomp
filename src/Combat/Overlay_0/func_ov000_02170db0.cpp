#include <globaldefs.h>
#include "GameState/GameState.h"
#if defined(jpn)
#define data_ov000_02183ff4 data_ov000_02185118
#endif

struct Struct_ov000_02170db0_2 {
    #if defined(jpn)
    char unknown_0_[0x8b4];
#else
    char unknown1_0_[0x94c];
#endif
    int unknown_94c_;
};

struct Container020e0310;
int KeyTable_Get(struct Container020e0310* c, int key);
struct CombatantExt02170db0* GetFieldAt0x150_02053c6c(unsigned char* obj);

struct Struct_0203c108_3 {
    #if defined(jpn)
    char unknown_0_[0x2c];
#else
    char unknown1_0_[0x10];
#endif
    int unknown_10_;
    short unknown_14_;
};
extern "C" void func_0203c108(struct Struct_0203c108_3* arg0, char* arg1);

extern "C" void __clear(void* arg0, int arg1);

struct Struct_ov000_02170db0_3 {
    char unknown_0_[4];
    struct Struct_0201099c_3* unknown_4_;
    char unknown_8_[0x1c - 0x8];
    signed char unknown_1c_;
    char unknown_1d_[0x26 - 0x1d];
    unsigned short unknown_26_;
    char unknown_28_[0x2c - 0x28];
    short unknown_2c_;
    char unknown_2e_[0x4c - 0x2e];
    int unknown_4c_;
    struct Struct_0203c108_3 unknown_50_;
};

struct Struct_ov000_02170cf8 {
    void* unknown_0_;
};

struct Struct_ov000_02170db0 {
    char unknown_0_[4];
    void* unknown_4_;
    char unknown_8_[0x18 - 0x8];
    short unknown_18_;
};

extern "C" struct Struct_ov000_02170cf8* func_ov000_02170cf8(struct Struct_ov000_02170db0_3* arg0, int arg1);
extern "C" struct Struct_ov000_02170db0* func_ov000_02171d90(struct Struct_ov000_02170db0_3* arg0, int arg1);
extern "C" int func_ov000_021719f8(int* arg0);
#if defined(jpn)
extern "C" int func_ov000_02171a74(struct Struct_ov000_02170db0_3* arg0);
#else
extern "C" int func_ov000_02171a74(struct Struct_ov000_02170db0_3* arg0, char* arg1);
#endif
extern "C" void func_020e4864(void* src, char* dst, int a, int b, int c, int d);
void CopyTextAndUppercaseIfFlagged0206819c(const char* src, char* dst, int flag);
int MessageSystem_GetInstance(void);
extern "C" void MessageSystem_FormatText(int messages, int mode, char* input, char* output, int size, int a, int b);
extern "C" void func_ov000_0217616c(struct Obj02170db0* obj);

extern char data_ov000_02183ff4[];

// USA: func_ov000_02170db0
extern "C" ARM void func_ov000_02170db0(struct Struct_ov000_02170db0_3* arg0) {
    struct Struct_ov000_02170cf8* var0 = func_ov000_02170cf8(arg0, arg0->unknown_26_);
    struct Struct_ov000_02170db0* var1 = func_ov000_02171d90(arg0, arg0->unknown_2c_);
    GameObject* var2 = func_0200ff1c(GameState::GetInstance(), arg0->unknown_4c_);
    if (var2 == NULL) {
        return;
    }
    struct Struct_ov000_02170db0_2* var3 = func_02053c6c((unsigned char*)var2);
    arg0->unknown_50_.unknown_10_ = 1;
    if (func_ov000_021719f8((int*)arg0)) {
#if defined(jpn)
        char* text = (char*)KeyTable_Get(obj->container, func_ov000_02171a74(obj));
        if (text != NULL) {
            SwapGlobalEntry0203c108(&obj->label, text);
        }
#else
        char var5[0x80];
        __clear(var5, sizeof(var5));
        if (func_ov000_02171a74(arg0, var5) >= 0) {
            func_0203c108(&arg0->unknown_50_, var5);
        }
#endif
    } else if (ext != NULL && (signed char)ext->field94c != 5 && obj->kind != 6) {
        char* text = (char*)KeyTable_Get(obj->container, (short)((signed char)ext->field94c + 0x753e));
        if (text != NULL) {
            SwapGlobalEntry0203c108(&obj->label, text);
        } else {
            func_0203c108(&arg0->unknown_50_, data_ov000_02183ff4);
        }
    } else if (var0 != NULL) {
#if defined(jpn)
        func_0203c108(&arg0->unknown_50_, (char*)var0->unknown_0_);
#else
        char var7[0x80];
        char var8[0x80];
        __clear(var7, sizeof(var7));
        __clear(var8, sizeof(var8));
        func_020e4864(var0->unknown_0_, var7, 1, 0, 0, 0);
        func_0206819c(var7, var8, 0);
        func_0203c108(&arg0->unknown_50_, var8);
#endif
    } else if (var1 != NULL) {
        if (var1->unknown_18_ > 0) {
#if defined(jpn)
            func_0203c108(&arg0->unknown_50_, (char*)var1->unknown_4_);
#else
            char raw[0x80];
            char name[0x80];
            __clear(raw, sizeof(raw));
            __clear(name, sizeof(name));
            func_020e4864(equip->text, raw, 1, 0, 0, 0);
            CopyTextAndUppercaseIfFlagged0206819c(raw, name, 0);
            MessageSystem_FormatText(MessageSystem_GetInstance(), 10, name, raw, 0x100, 0, 0);
            SwapGlobalEntry0203c108(&obj->label, raw);
#endif
        }
    } else if (obj->kind == 6) {
        SwapGlobalEntry0203c108(&obj->label, (char*)KeyTable_Get(obj->container, 0x7531));
    } else {
        func_0203c108(&arg0->unknown_50_, data_ov000_02183ff4);
    }
    func_ov000_0217616c(arg0);
}
