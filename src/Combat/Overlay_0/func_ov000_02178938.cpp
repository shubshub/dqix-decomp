#include <globaldefs.h>
#include <GameState/GameState.h>

struct Struct_0201099c_3;
struct Struct_ov000_02178938_3 { char* unknown_0_; char* unknown_4_; unsigned int unknown_8_; };
struct Struct_020465c0 { char unknown_0_[0x20]; Struct_ov000_02178938_3* unknown_20_; };
#if defined(jpn)
struct Struct_ov000_02178938 { char unknown_0_[0xb8]; char unknown_b8_[0x20]; char unknown_d8_[0x1d94 - 0xd8]; char unknown_1d94_[8][0x38]; int unknown_1d1c_[8]; int unknown_1f74_[8]; };
#else
struct Struct_ov000_02178938 { char unknown_0_[0xb8]; char unknown_b8_[0x20]; char unknown_d8_[0x1c44]; int unknown_1d1c_[8]; int unknown_1d3c_[8]; };
#endif
struct TargetSelection { char pad[0x1d]; signed char index; };
int CountMatchingValues02175348(void*, int);
int IsField0x118Equal2_ov000_0217542c(void*);
StoreStruct* MessageSystem_GetInstance();
int KeyTable_Get(Container020e0310*, int);
void Text_AppendFrameTag(char*, int, int, int, int, int);
void Text_AppendCursorTag(char*, int);
void Text_Append(char*, const char*);
extern "C" void __clear(void*, int);
extern "C" void func_02046380(StoreStruct*);
void Clear12Bytes020e46c4(void*);
GameObject* GetCombatantWithFlag0x400_0200fea4(GameState*, int);
extern "C" void func_020e4ce8(NameParts*, GameObject*, int);
void TrimTrailingLetterCode_0217aa08(char*, char*);
extern "C" void func_020e4f18(NameParts*, NameParts*, int);
void StoreInArray0x8b0_020465c0(StoreStruct*, int, int);
extern "C" void MessageSystem_FormatText(StoreStruct*, int, const char*, char*, int, int, int);
void Text_AppendNTag(char*, int, const char*);
extern const char data_ov000_02184060[];

#if defined(jpn)
extern "C" void func_0203bdf4(char*, char*);
extern "C" void _Z31MessageSystem_SetStringArgumentP11Obj02046574iPc(StoreStruct*, int, char*);
extern "C" void func_020474a8(StoreStruct*, int, const char*, char*);
#endif

// USA: func_ov000_02178938
extern "C" ARM void func_ov000_02178938(Struct_ov000_02178938* arg0, Struct_ov000_02178938_2* arg1, int arg2, char* arg3) {
    if (!arg3) return;
    int var0 = -1;
#if defined(jpn)
    int var1;
    int var2;
    var2 = 0;
    var1 = 0;
#else
    int var1 = 0;
    int var2 = 0;
#endif
    int var3 = arg1->unknown_1d_;
    for (int var4 = 0; var4 < arg2; var4++) {
        int var5 = arg0->unknown_1d1c_[var4];
        if (var0 != var5) {
            var0 = var5;
            int var6 = func_ov000_02175348(arg0, var5);
            if (var4 <= var3 && var3 < var4 + var6) var1 = var4;
        }
    }
    int showCursor = IsField0x118Equal2_ov000_0217542c(menu);
    StoreStruct* formatter = MessageSystem_GetInstance();
#if !defined(jpn)
    GameState* game = GameState::GetInstance();
    const char* separator = (const char*)KeyTable_Get((Container020e0310*)menu->messages, 0);
    const char* format = (const char*)KeyTable_Get((Container020e0310*)menu->messages, 0x754f);
#endif
    previous = -1;
    if (showCursor) {
        Text_AppendFrameTag(output, selectedStart, 8, 5, 5, 5);
    }
    Text_AppendCursorTag(output, selectedStart);
    for (int i = 0; i < count; i++) {
        int kind = menu->kinds[i];
        if (previous != kind) {
            previous = kind;
            int groupSize = CountMatchingValues02175348(menu, kind);
            if (groupSize) {
#if defined(jpn)
                if (appended) Text_Append(output, (const char*)KeyTable_Get((Container020e0310*)menu->messages, 0));
#else
                if (appended) Text_Append(output, separator);
#endif
#if defined(jpn)
                char var15[0x20];
                __clear(var15, sizeof(var15));
                char var16[0x40];
                __clear(var16, sizeof(var16));
#else
                char var16[128];
                __clear(var16, 128);
#endif
                int var17 = var12;
                if (var12 <= var3 && var3 < var12 + var14) var17 = var3;
#if defined(jpn)
                func_0203bdf4(arg0->unknown_1d94_[var17], var15);
                if (var7 && var1 == var12) {
                    char var18[0x20];
                    __clear(var18, sizeof(var18));
                    memcpy(var18, var15, sizeof(var18));
                    memset(var15, 0, sizeof(var15));
                    func_ov000_0217aa08(var18, var15);
                }
                func_02046380(formatter);
                _Z31MessageSystem_SetStringArgumentP11Obj02046574iPc(formatter, 0, nameText);
                StoreInArray0x8b0_020465c0(formatter, 0, groupSize);
                func_020474a8(formatter, 10, (const char*)KeyTable_Get((Container020e0310*)menu->messages, 0x754f), text);
#else
                func_02046380(var8);
                Struct_ov000_02178938_3 var19;
                func_020e46c4(&var19);
                GameObject* var20 = func_0200fea4(var9, arg0->unknown_1d3c_[var17]);
                char var21[128];
                char var22[128];
                __clear(var21, 128);
                __clear(var22, 128);
                if (var20) {
                    func_020e4ce8(&var19, var20, 1);
                    Struct_ov000_02178938_3 var23;
                    func_020e4ce8(&var23, var20, 0);
                    func_ov000_0217aa08(var19.unknown_0_, var21);
                    func_ov000_0217aa08(var19.unknown_4_, var22);
                    var19.unknown_0_ = var21;
                    var19.unknown_4_ = var22;
                    func_020e4f18(&var23, &var19, 2);
                    var19.unknown_8_ &= ~0x80000000;
                }
                formatter->name = &name;
                StoreInArray0x8b0_020465c0(formatter, 0, groupSize);
                MessageSystem_FormatText(formatter, 10, format, text, 256, 0, 0);
#endif
                Text_AppendNTag(output, i, text);
                appended = 1;
            }
        }
    }
#if !defined(jpn)
    Text_Append(output, data_ov000_02184060);
#endif
}
