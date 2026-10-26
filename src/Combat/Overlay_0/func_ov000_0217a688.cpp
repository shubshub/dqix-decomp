#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Resource/CharacterCreationUI.h>

struct Struct_020200c0_5 { char* unknown_0_; char* unknown_4_; unsigned int unknown_8_; };
struct Struct_020465c0 { char unknown_0_[0x20]; Struct_020200c0_5* unknown_20_; };
struct Struct_ov000_02178938 {
    char unknown_0_[0x1c];
    signed char unknown_1c_;
    char unknown_1d_[0xb8 - 0x1d];
    Struct_0201099c_3 unknown_b8_;
#if defined(jpn)
    char unknown_c0_[0x1d94 - 0xc0];
    char unknown_1d94_[8][0x38];
#else
    char unknown1_c0_[0x1d1c - 0xc0];
#endif
    int unknown_1d1c_[8];
    int unknown_1d3c_[8];
};

int CountMatchingValues02175348(void*, int);
StoreStruct* MessageSystem_GetInstance();
int KeyTable_Get(Container020e0310*, int);
int IsField0x118Equal2_ov000_0217542c(void*);
int Text_AppendFrameTag(char*, int, int, int, int, int);
int Text_AppendCursorTag(char*, int);
int Text_Append(char*, const char*);
extern "C" void* __clear(void*, int);
extern "C" void func_02046380(StoreStruct*);
void* NameText_Clear(void*);
GameObject* GetCombatantWithFlag0x400_0200fea4(GameState*, int);
extern "C" void func_020e4ce8(NameDescriptor*, GameObject*, int);
void TrimTrailingLetterCode_0217aa08(char*, char*);
extern "C" void func_020e4f18(NameDescriptor*, NameDescriptor*, int);
void StoreInArray0x8b0_020465c0(StoreStruct*, int, int);
extern "C" void MessageSystem_FormatText(StoreStruct*, int, const char*, char*, int, int, int);
int Text_AppendNTag(char*, int, const char*);
extern char data_ov000_02184060[];

#if defined(jpn)
extern "C" void func_0203bdf4(char*, char*);
extern "C" void _Z31MessageSystem_SetStringArgumentP11Obj02046574iPc(StoreStruct*, int, char*);
extern "C" void func_020474a8(StoreStruct*, int, const char*, char*);
#endif

// USA: func_ov000_0217a688
extern "C" ARM void func_ov000_0217a688(Struct_ov000_02178938* arg0, void* arg1, int arg2, char* arg3) {
    if (!arg3) return;
    int var0;
    unsigned int var1;
#if defined(jpn)
    bool var2;
#else
    int var2;
#endif
    int var3;
    int var4;
    var1 = -1;
    var0 = 0;
    var2 = 0;
    var4 = 0;
    var3 = arg0->unknown_1c_;
    for (; var4 < arg2; ++var4) {
        int var5 = arg0->unknown_1d1c_[var4];
        if (var1 == var5) continue;
        var1 = var5;
        int var6 = func_ov000_02175348(arg0, var5);
        if (var4 <= var3 && var3 < var4 + var6) var0 = var4;
    }
    StoreStruct* store = MessageSystem_GetInstance();
#if !defined(jpn)
    GameState* game = GameState::GetInstance();
    const char* separator = (const char*)KeyTable_Get(&self->strings_, 0);
    const char* format = (const char*)KeyTable_Get(&self->strings_, 0x754f);
#endif
    var1 = -1;
#if defined(jpn)
    int var11 = func_ov000_0217542c(arg0);
    if (var11)
#else
    if (func_ov000_0217542c(arg0))
#endif
        Text_AppendFrameTag(output, cursor, 8, 5, 5, 5);
    Text_AppendCursorTag(output, cursor);
    for (int i = 0; i < count; ++i) {
        int group = self->groupIDs_[i];
        if (previous == group) continue;
        previous = group;
        int members = CountMatchingValues02175348(self, group);
        if (!members) continue;
#if defined(jpn)
        if (separated) Text_Append(output, (const char*)KeyTable_Get(&self->strings_, 0));
#else
        if (separated) Text_Append(output, separator);
#endif
#if defined(jpn)
        char var15[0x20];
        __clear(var15, sizeof(var15));
        char var16[0x40];
        __clear(var16, sizeof(var16));
#else
        char var16[0x80];
        __clear(var16, sizeof(var16));
#endif
        int var17 = var12;
        if (var12 <= var3 && var3 < var12 + var14) var17 = var3;
#if defined(jpn)
        func_0203bdf4(arg0->unknown_1d94_[var17], var15);
        if (var11 && var0 == var12) {
            char var18[0x20];
            __clear(var18, sizeof(var18));
            memcpy(var18, var15, sizeof(var18));
            memset(var15, 0, sizeof(var15));
            func_ov000_0217aa08(var18, var15);
        }
        func_02046380(store);
        _Z31MessageSystem_SetStringArgumentP11Obj02046574iPc(store, 0, nameText);
        StoreInArray0x8b0_020465c0(store, 0, members);
        func_020474a8(store, 10, (const char*)KeyTable_Get(&self->strings_, 0x754f), text);
#else
        func_02046380(store);
        NameDescriptor names;
        NameText_Clear(&names);
        GameObject* target = GetCombatantWithFlag0x400_0200fea4(game, self->combatantIDs_[index]);
        char singular[0x80];
        __clear(singular, sizeof(singular));
        char plural[0x80];
        __clear(plural, sizeof(plural));
        if (target) {
            func_020e4ce8(&names, target, 1);
            NameDescriptor original;
            func_020e4ce8(&original, target, 0);
            TrimTrailingLetterCode_0217aa08(names.singular_, singular);
            TrimTrailingLetterCode_0217aa08(names.plural_, plural);
            names.singular_ = singular;
            names.plural_ = plural;
            func_020e4f18(&original, &names, 2);
            names.flags_ &= ~0x80000000;
        }
        store->names_ = &names;
        StoreInArray0x8b0_020465c0(store, 0, members);
        MessageSystem_FormatText(store, 10, format, text, 0x100, 0, 0);
#endif
        Text_AppendNTag(output, i, text);
        separated = 1;
    }
#if !defined(jpn)
    Text_Append(output, data_ov000_02184060);
#endif
}
