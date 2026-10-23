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

struct MessageWork02168b50* GetGlobalField0x1c020421a0();
struct DataEntry02108d18* GetData02108d18_0206f504();
int AppendFormatted02041fe8(char* buf, int a);
int KeyTable_Get(struct Container020e0310* c, int key);
int AppendString02042058(char* dst, const char* src);
extern "C" void func_02046380(void* obj);
void SetIndexedName02046574(struct Obj02046574* obj, int index, char* str);
void StoreInArray0x8b0_020465c0(struct StoreStruct* base, int index, int value);
void SetByteInRange_020465f0(unsigned char* base, int index, unsigned char value);

#if defined(jpn)
extern "C" void func_0204500c(void*, char*, int);
#endif
#if !defined(jpn)
extern "C" void func_0204500c(void* arg0, char* arg1, int arg2, int arg3);
#endif
extern "C" void func_ov003_0216982c(struct Struct_ov003_02168b50_4* arg0);
extern "C" void func_ov003_0216997c(struct Struct_ov003_02168b50_4* arg0);
extern "C" void func_0205deb4(struct Struct_0205d81c* arg0, int arg1, int arg2);

// USA: func_ov003_02168b50
extern "C" ARM void func_ov003_02168b50(struct Struct_ov003_02168b50_4* arg0) {
    struct Struct_ov003_02168b50* var0 = func_020421a0();
    struct Struct_0201099c_3* var1 = (struct Struct_0201099c_3*)arg0->unknown_64_;
    if (arg0->unknown_4e8_ == 0) {
        memset(arg0->unknown_7c_, 0, Enum_ov003_02168b50_2400);
        struct Struct_ov003_02168b50_2* var2 = func_0206f504();
        if (var2->unknown_10_[0] != 0) {
            func_02041fe8(arg0->unknown_7c_, (int)var2->unknown_10_);
        }
        AppendString02042058(self->text, (const char*)KeyTable_Get(messages, 0x3e8));
        GameState* game = GameState::GetInstance();
        struct BattleData02168b50* battle = (struct BattleData02168b50*)GetPtrField0x2a04_02010828(game);
        func_02046380(work);
        SetIndexedName02046574((struct Obj02046574*)work, 0, (char*)game->GetProtagonist()->baseStats_);
        if (battle->field_0xf68 != 0) {
            StoreInArray0x8b0_020465c0((struct StoreStruct*)work, 0, battle->field_0xf68);
            SetByteInRange_020465f0((unsigned char*)work, 0, 0);
            AppendString02042058(self->text, (const char*)KeyTable_Get(messages, 0x3ea));
        } else {
            AppendString02042058(self->text, (const char*)KeyTable_Get(messages, 0x3e9));
        }
        var0->unknown_998_ = 1;
#if defined(jpn)
        func_0204500c(var0, arg0->unknown_7c_, 0);
#else
        func_0204500c(var0, arg0->unknown_7c_, 0, 0xe3);
#endif
        var0->unknown_99c_ = 2;
        arg0->unknown_4e8_++;
    } else if (arg0->unknown_4e8_ == 1 && arg0->unknown_5a4_ == 0 && var0->unknown_9a0_ == 3) {
        func_ov003_0216982c(arg0);
        func_ov003_0216997c(arg0);
        func_0205deb4((struct Struct_0205d81c*)arg0->unknown_e4_, 0, 0);
        arg0->unknown_4ec_ = 2;
        arg0->unknown_4e8_ = 0;
    }
}
