#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include <globaldefs.h>
#include "Resource/ActionDataTables.h"
#include "GameState/GameState.h"

struct Container020e0310;
extern "C" char* KeyTable_Get(struct Container020e0310* c, int key);

struct Obj0203c108 {
    char pad[0x14];
    short idx;
    short pad16;
};
extern "C" void CachedTextLabel_SetText(struct Obj0203c108* obj, char* fmt);

extern "C" void* func_02079e2c(char* table, int key);
extern "C" int func_ov000_02171210(void* rec, void* self);

struct BattleInfo2a04 {
    char pad[0xf7c];
    unsigned char mode;
};

extern "C" void __clear(void* buf, int n);
extern "C" void func_020e4864(const char* src, char* dst, int a, int b, int c, int d);
extern "C" void func_0206819c(const char* src, char* dst, int flag);
struct MessageSystem;
extern "C" struct MessageSystem* MessageSystem_GetInstance();
extern "C" void MessageSystem_FormatText(struct MessageSystem* messages, int a, const char* format, char* output, int size, int b, int c);

struct ActionEntry {
    int field_0x0;
    const char* name;
    char pad8[0xe];
    short unknown_16_;
    short count;
};

struct Struct_ov000_02171e60 {
    char pad0[4];
    struct Container020e0310* texts;
    char pad8[8];
    signed char unknown_10_[8];
    signed char unknown_18_;
    char unknown_19_[4];
    signed char result;
    char pad1e[3];
    signed char unknown_21_;
    signed char unknown_22_;
    char unknown_23_[0xb];
    signed char unknown_2e_;
    char unknown_2f_[0x1d];
    int unknown_4c_;
    struct Obj0203c108 message;
    char pad68[LOW_REGION(0x3c8, 0x388)];
    struct ActionEntry* entries[16];
};

// USA: func_ov000_02171e60
extern "C" ARM void func_ov000_02171e60(struct Struct_ov000_02171e60* self) {
    struct ActionEntry* entry = self->entries[self->unknown_22_];
    if (entry->count <= 0) {
        self->unknown_18_++;
        self->unknown_10_[self->unknown_18_] = 0xe;
        self->result = 0;
        CachedTextLabel_SetText(&self->message, KeyTable_Get(self->texts, 5));
        return;
    }
    void* rec = func_02079e2c((char*)func_020797dc(), entry->unknown_16_);
    if (rec == NULL) {
        self->unknown_18_++;
        self->unknown_10_[self->unknown_18_] = 0xe;
        self->result = 0;
        CachedTextLabel_SetText(&self->message, KeyTable_Get(self->texts, 5));
        return;
    }
    self->unknown_18_++;
    self->unknown_10_[self->unknown_18_] = func_ov000_02171210(rec, self);
    if (self->unknown_10_[self->unknown_18_] == 0x13) {
        self->unknown_21_ = 0;
        self->unknown_2e_ = self->unknown_4c_;
        if (((struct BattleInfo2a04*)GameState_GetParty(GameState::GetInstance()))->mode == 1) {
            self->unknown_10_[self->unknown_18_] = 100;
        }
    }
#if defined(jpn)
    CachedTextLabel_SetText(&self->message, (char*)entry->name);
#else
    char text[0x80];
    __clear(text, 0x80);
    char format[0x80];
    __clear(format, 0x80);
    func_020e4864(entry->name, text, 1, 0, 0, 0);
    func_0206819c(text, format, 0);
    MessageSystem_FormatText(MessageSystem_GetInstance(), 10, format, text, 0x100, 0, 0);
    CachedTextLabel_SetText(&self->message, text);
#endif
}
