#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include <globaldefs.h>
#include "Resource/ActionDataTables.h"
#include "GameState/GameState.h"

struct Container020e0310;
char* KeyTable_Get(struct Container020e0310* c, int key);

struct Struct_0203c108_3 {
    char unknown_0_[0x14];
    short unknown_14_;
    short unknown_16_;
};
extern "C" void func_0203c108(struct Struct_0203c108_3* arg0, char* arg1);

extern "C" void* func_02079e2c(char* arg0, int arg1);
extern "C" int func_ov000_02171210(void* arg0, void* arg1);

struct Struct_ov000_02171e60_2 {
    char unknown_0_[0xf7c];
    unsigned char unknown_f7c_;
};

extern "C" void __clear(void* arg0, int arg1);
extern "C" void func_020e4864(const char* arg0, char* arg1, int arg2, int arg3, int arg4, int arg5);
extern "C" void func_0206819c(const char* arg0, char* arg1, int arg2);
struct Struct_02021b84;
extern "C" struct Struct_02021b84* func_020421a0();
extern "C" void func_02046608(struct Struct_02021b84* arg0, int arg1, const char* arg2, char* arg3, int arg4, int arg5, int arg6);

struct Struct_ov000_0215767c_8 {
    int unknown_0_;
    const char* unknown_4_;
    char unknown_8_[0xe];
    short unknown_16_;
    short unknown_18_;
};

struct Struct_ov000_02171e60 {
    char unknown_0_[4];
    struct Struct_0201099c_3* unknown_4_;
    char unknown_8_[8];
    signed char unknown_10_[8];
    signed char unknown_18_;
    char unknown_19_[4];
    signed char unknown_1d_;
    char unknown_1e_[3];
    signed char unknown_21_;
    signed char unknown_22_;
    char unknown_23_[0xb];
    signed char unknown_2e_;
    char unknown_2f_[0x1d];
    int unknown_4c_;
    struct Struct_0203c108_3 unknown_50_;
    char unknown_68_[LOW_REGION(0x3c8, 0x388)];
    struct Struct_ov000_0215767c_8* unknown_3f0_[16];
};

// USA: func_ov000_02171e60
extern "C" ARM void func_ov000_02171e60(struct CommandMenu* self) {
    struct ActionEntry* entry = self->entries[self->curIndex];
    if (entry->count <= 0) {
        self->stackTop++;
        self->stack[self->stackTop] = 0xe;
        self->result = 0;
        SwapGlobalEntry0203c108(&self->message, KeyTable_Get(self->texts, 5));
        return;
    }
    void* rec = SearchBothTables02079e2c((char*)GetData02108e10_020797dc(), entry->recordId);
    if (rec == NULL) {
        self->stackTop++;
        self->stack[self->stackTop] = 0xe;
        self->result = 0;
        SwapGlobalEntry0203c108(&self->message, KeyTable_Get(self->texts, 5));
        return;
    }
    arg0->unknown_18_++;
    arg0->unknown_10_[arg0->unknown_18_] = func_ov000_02171210(var1, arg0);
    if (arg0->unknown_10_[arg0->unknown_18_] == 0x13) {
        arg0->unknown_21_ = 0;
        arg0->unknown_2e_ = arg0->unknown_4c_;
        if (((struct Struct_ov000_02171e60_2*)func_02010828(GameState::GetInstance()))->unknown_f7c_ == 1) {
            arg0->unknown_10_[arg0->unknown_18_] = 100;
        }
    }
#if defined(jpn)
    func_0203c108(&arg0->unknown_50_, (char*)var0->unknown_4_);
#else
    char var2[0x80];
    __clear(var2, 0x80);
    char var3[0x80];
    __clear(var3, 0x80);
    func_020e4864(var0->unknown_4_, var2, 1, 0, 0, 0);
    func_0206819c(var2, var3, 0);
    func_02046608(func_020421a0(), 10, var3, var2, 0x100, 0, 0);
    func_0203c108(&arg0->unknown_50_, var2);
#endif
}
