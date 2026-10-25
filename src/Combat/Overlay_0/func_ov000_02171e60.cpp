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

extern "C" void __clear(void* buf, int n);
extern "C" void func_020e4864(const char* src, char* dst, int a, int b, int c, int d);
void CopyTextAndUppercaseIfFlagged0206819c(const char* src, char* dst, int flag);
struct MessageSystem;
struct MessageSystem* MessageSystem_GetInstance();
extern "C" void MessageSystem_FormatText(struct MessageSystem* messages, int a, const char* format, char* output, int size, int b, int c);

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
    self->stackTop++;
    self->stack[self->stackTop] = func_ov000_02171210(rec, self);
    if (self->stack[self->stackTop] == 0x13) {
        self->field_0x21 = 0;
        self->field_0x2e = self->field_0x4c;
        if (((struct BattleInfo2a04*)GameState_GetParty(GameState::GetInstance()))->mode == 1) {
            self->stack[self->stackTop] = 100;
        }
    }
#if defined(jpn)
    func_0203c108(&arg0->unknown_50_, (char*)var0->unknown_4_);
#else
    char text[0x80];
    __clear(text, 0x80);
    char format[0x80];
    __clear(format, 0x80);
    func_020e4864(entry->name, text, 1, 0, 0, 0);
    CopyTextAndUppercaseIfFlagged0206819c(text, format, 0);
    MessageSystem_FormatText(MessageSystem_GetInstance(), 10, format, text, 0x100, 0, 0);
    SwapGlobalEntry0203c108(&self->message, text);
#endif
}
