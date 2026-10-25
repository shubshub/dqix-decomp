#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_02168b50_2456 = 0x868 };
enum { Enum_ov003_02168b50_228 = 0xe0 };
enum { Enum_ov003_02168b50_1256 = 0x4e4 };
enum { Enum_ov003_02168b50_1260 = 0x4e8 };
enum { Enum_ov003_02168b50_1257 = 0x4e5 };
enum { Enum_ov003_02168b50_1261 = 0x4e9 };
enum { Enum_ov003_02168b50_1444 = 0x5a0 };
enum { Enum_ov003_02168b50_2400 = 0x800 };
#else
enum { Enum_ov003_02168b50_2456 = 0x998 };
enum { Enum_ov003_02168b50_228 = 0xe4 };
enum { Enum_ov003_02168b50_1256 = 0x4e8 };
enum { Enum_ov003_02168b50_1260 = 0x4ec };
enum { Enum_ov003_02168b50_1257 = 0x4e9 };
enum { Enum_ov003_02168b50_1261 = 0x4ed };
enum { Enum_ov003_02168b50_1444 = 0x5a4 };
enum { Enum_ov003_02168b50_2400 = 0x960 };
#endif
#include "std_library_functions.h"
#include "GameState/GameState.h"

struct Struct_ov003_02168b50 {
    char unknown_0_[Enum_ov003_02168b50_2456];
    int unknown_998_;
    int unknown_99c_;
    int unknown_9a0_;
};

struct Struct_ov003_02168b50_2 {
    char unknown_0_[0x10];
    char unknown_10_[0x20];
};

struct Struct_ov003_02168b50_3 {
    char unknown_0_[0xf68];
    int unknown_f68_;
};

struct Struct_0201099c_3;
struct Struct_02046574_2;
struct Struct_020465c0;
struct Struct_0205d81c;

struct Struct_ov003_02168b50_4 {
    char unknown_0_[0x64];
    char unknown_64_[0x7c - 0x64];
    char* unknown_7c_;
    char unknown_80_[Enum_ov003_02168b50_228 - 0x80];
    char unknown_e4_[Enum_ov003_02168b50_1256 - Enum_ov003_02168b50_228];
    unsigned char unknown_4e8_;
    char unknown_4e9_[Enum_ov003_02168b50_1260 - Enum_ov003_02168b50_1257];
    unsigned char unknown_4ec_;
    char unknown_4ed_[Enum_ov003_02168b50_1444 - Enum_ov003_02168b50_1261];
    unsigned char unknown_5a4_;
};

struct MessageWork02168b50* MessageSystem_GetInstance();
struct DataEntry02108d18* GetData02108d18_0206f504();
int AppendFormatted02041fe8(char* buf, int a);
int KeyTable_Get(struct Container020e0310* c, int key);
int Text_Append(char* dst, const char* src);
extern "C" void func_02046380(void* obj);
void MessageSystem_SetStringArgument(struct Obj02046574* obj, int index, char* str);
void StoreInArray0x8b0_020465c0(struct StoreStruct* base, int index, int value);
void SetByteInRange_020465f0(unsigned char* base, int index, unsigned char value);

#if defined(jpn)
extern "C" void func_0204500c(void*, char*, int);
#endif
#if !defined(jpn)
extern "C" void func_0204500c(void* arg0, char* arg1, int arg2, int arg3);
#endif
extern "C" void func_ov003_0216982c(struct BattleMenu02168b50* self);
extern "C" void func_ov003_0216997c(struct BattleMenu02168b50* self);
void Window_SetPanePalette(struct Struct_0205d81c* s, int key, int value);

// USA: func_ov003_02168b50
extern "C" ARM void func_ov003_02168b50(struct BattleMenu02168b50* self) {
    struct MessageWork02168b50* work = MessageSystem_GetInstance();
    struct Container020e0310* messages = (struct Container020e0310*)self->messages;
    if (self->step == 0) {
        memset(self->text, 0, kRegion960);
        struct DataEntry02108d18* data = GetData02108d18_0206f504();
        if (data->title[0] != 0) {
            AppendFormatted02041fe8(self->text, (int)data->title);
        }
        Text_Append(self->text, (const char*)KeyTable_Get(messages, 0x3e8));
        GameState* game = GameState::GetInstance();
        struct BattleData02168b50* battle = (struct BattleData02168b50*)GameState_GetParty(game);
        func_02046380(work);
        MessageSystem_SetStringArgument((struct Obj02046574*)work, 0, (char*)game->GetProtagonist()->baseStats_);
        if (battle->field_0xf68 != 0) {
            StoreInArray0x8b0_020465c0((struct StoreStruct*)work, 0, battle->field_0xf68);
            SetByteInRange_020465f0((unsigned char*)work, 0, 0);
            Text_Append(self->text, (const char*)KeyTable_Get(messages, 0x3ea));
        } else {
            Text_Append(self->text, (const char*)KeyTable_Get(messages, 0x3e9));
        }
        var0->unknown_998_ = 1;
#if defined(jpn)
        func_0204500c(var0, arg0->unknown_7c_, 0);
#else
        func_0204500c(var0, arg0->unknown_7c_, 0, 0xe3);
#endif
        work->field_0x99c = 2;
        self->step++;
    } else if (self->step == 1 && self->busy == 0 && work->state == 3) {
        func_ov003_0216982c(self);
        func_ov003_0216997c(self);
        Window_SetPanePalette((struct Struct_0205d81c*)self->menu, 0, 0);
        self->mode = 2;
        self->step = 0;
    }
}
