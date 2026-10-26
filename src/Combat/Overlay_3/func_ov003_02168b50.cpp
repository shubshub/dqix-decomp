#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_02168b50_2456 = 0x868 };
enum { kRegione4 = 0xe0 };
enum { Enum_ov003_02168b50_1256 = 0x4e4 };
enum { Enum_ov003_02168b50_1260 = 0x4e8 };
enum { Enum_ov003_02168b50_1257 = 0x4e5 };
enum { Enum_ov003_02168b50_1261 = 0x4e9 };
enum { Enum_ov003_02168b50_1444 = 0x5a0 };
enum { Enum_ov003_02168b50_2400 = 0x800 };
#else
enum { Enum_ov003_02168b50_2456 = 0x998 };
enum { kRegione4 = 0xe4 };
enum { Enum_ov003_02168b50_1256 = 0x4e8 };
enum { Enum_ov003_02168b50_1260 = 0x4ec };
enum { Enum_ov003_02168b50_1257 = 0x4e9 };
enum { Enum_ov003_02168b50_1261 = 0x4ed };
enum { Enum_ov003_02168b50_1444 = 0x5a4 };
enum { Enum_ov003_02168b50_2400 = 0x960 };
#endif
#include "std_library_functions.h"
#include "GameState/GameState.h"

struct MessageWork02168b50 {
    char pad0[Enum_ov003_02168b50_2456];
    int field_0x998;
    int unknown_99c_;
    int state;
};

struct Struct_ov003_02168b50_2 {
    char pad0[0x10];
    char title[0x20];
};

struct BattleData02168b50 {
    char pad0[0xf68];
    int unknown_f68_;
};

struct Container020e0310;
struct Obj02046574;
struct StoreStruct;
struct Struct_0205d81c;

struct Struct_ov003_02168b50_4 {
    char pad0[0x64];
    char messages[0x7c - 0x64];
    char* text;
    char unknown_80_[kRegione4 - 0x80];
    char menu[Enum_ov003_02168b50_1256 - kRegione4];
    unsigned char step;
    char unknown_4e9_[Enum_ov003_02168b50_1260 - Enum_ov003_02168b50_1257];
    unsigned char mode;
    char unknown_4ed_[Enum_ov003_02168b50_1444 - Enum_ov003_02168b50_1261];
    unsigned char busy;
};

extern "C" struct MessageWork02168b50* MessageSystem_GetInstance();
extern "C" struct Struct_ov003_02168b50_2* func_0206f504();
extern "C" int func_02041fe8(char* buf, int a);
extern "C" int KeyTable_Get(struct Container020e0310* c, int key);
extern "C" int Text_Append(char* dst, const char* src);
extern "C" void func_02046380(void* obj);
extern "C" void MessageSystem_SetStringArgument(struct Obj02046574* obj, int index, char* str);
extern "C" void func_020465c0(struct StoreStruct* base, int index, int value);
extern "C" void func_020465f0(unsigned char* base, int index, unsigned char value);

#if defined(jpn)
extern "C" void func_0204500c(void*, char*, int);
#endif
#if !defined(jpn)
extern "C" void func_0204500c(void* obj, char* buffer, int a, int b);
#endif
extern "C" void func_ov003_0216982c(struct Struct_ov003_02168b50_4* self);
extern "C" void func_ov003_0216997c(struct Struct_ov003_02168b50_4* self);
extern "C" void Window_SetPanePalette(struct Struct_0205d81c* s, int key, int value);

// USA: func_ov003_02168b50
extern "C" ARM void func_ov003_02168b50(struct Struct_ov003_02168b50_4* self) {
    struct MessageWork02168b50* work = MessageSystem_GetInstance();
    struct Container020e0310* messages = (struct Container020e0310*)self->messages;
    if (self->step == 0) {
        memset(self->text, 0, Enum_ov003_02168b50_2400);
        struct Struct_ov003_02168b50_2* data = func_0206f504();
        if (data->title[0] != 0) {
            func_02041fe8(self->text, (int)data->title);
        }
        Text_Append(self->text, (const char*)KeyTable_Get(messages, 0x3e8));
        GameState* game = GameState::GetInstance();
        struct BattleData02168b50* battle = (struct BattleData02168b50*)GameState_GetParty(game);
        func_02046380(work);
        MessageSystem_SetStringArgument((struct Obj02046574*)work, 0, (char*)game->GetProtagonist()->baseStats_);
        if (battle->unknown_f68_ != 0) {
            func_020465c0((struct StoreStruct*)work, 0, battle->unknown_f68_);
            func_020465f0((unsigned char*)work, 0, 0);
            Text_Append(self->text, (const char*)KeyTable_Get(messages, 0x3ea));
        } else {
            Text_Append(self->text, (const char*)KeyTable_Get(messages, 0x3e9));
        }
        work->field_0x998 = 1;
#if defined(jpn)
        func_0204500c(work, self->text, 0);
#else
        func_0204500c(work, self->text, 0, 0xe3);
#endif
        work->unknown_99c_ = 2;
        self->step++;
    } else if (self->step == 1 && self->busy == 0 && work->state == 3) {
        func_ov003_0216982c(self);
        func_ov003_0216997c(self);
        Window_SetPanePalette((struct Struct_0205d81c*)self->menu, 0, 0);
        self->mode = 2;
        self->step = 0;
    }
}
