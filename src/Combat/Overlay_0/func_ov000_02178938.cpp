#include <globaldefs.h>
#include <GameState/GameState.h>

struct Container020e0310;
struct Struct_ov000_02178938_3 { char* unknown_0_; char* unknown_4_; unsigned int flags; };
struct StoreStruct { char pad[0x20]; Struct_ov000_02178938_3* name; };
#if defined(jpn)
struct Struct_ov000_02178938 { char pad0[0xb8]; char messages[0x20]; char pad1[0x1d94 - 0xd8]; char unknown_1d94_[8][0x38]; int kinds[8]; int unknown_1f74_[8]; };
#else
struct Struct_ov000_02178938 { char pad0[0xb8]; char messages[0x20]; char pad1[0x1c44]; int kinds[8]; int unknown_1d3c_[8]; };
#endif
struct Struct_ov000_02178938_2 { char pad[0x1d]; signed char index; };
extern "C" int func_ov000_02175348(void*, int);
extern "C" int func_ov000_0217542c(void*);
extern "C" StoreStruct* MessageSystem_GetInstance();
extern "C" int KeyTable_Get(Container020e0310*, int);
extern "C" void Text_AppendFrameTag(char*, int, int, int, int, int);
extern "C" void Text_AppendCursorTag(char*, int);
extern "C" void Text_Append(char*, const char*);
extern "C" void __clear(void*, int);
extern "C" void func_02046380(StoreStruct*);
extern "C" void NameText_Clear(void*);
extern "C" GameObject* func_0200fea4(GameState*, int);
extern "C" void func_020e4ce8(Struct_ov000_02178938_3*, GameObject*, int);
extern "C" void func_ov000_0217aa08(char*, char*);
extern "C" void func_020e4f18(Struct_ov000_02178938_3*, Struct_ov000_02178938_3*, int);
extern "C" void func_020465c0(StoreStruct*, int, int);
extern "C" void MessageSystem_FormatText(StoreStruct*, int, const char*, char*, int, int, int);
extern "C" void Text_AppendNTag(char*, int, const char*);
extern const char data_ov000_02184060[];

#if defined(jpn)
extern "C" void func_0203bdf4(char*, char*);
extern "C" void MessageSystem_SetStringArgument(StoreStruct*, int, char*);
extern "C" void func_020474a8(StoreStruct*, int, const char*, char*);
#endif

// USA: func_ov000_02178938
extern "C" ARM void func_ov000_02178938(Struct_ov000_02178938* menu, Struct_ov000_02178938_2* selection, int count, char* output) {
    if (!output) return;
    int previous = -1;
#if defined(jpn)
    int selectedStart;
    int appended;
    appended = 0;
    selectedStart = 0;
#else
    int selectedStart = 0;
    int appended = 0;
#endif
    int selected = selection->index;
    for (int i = 0; i < count; i++) {
        int kind = menu->kinds[i];
        if (previous != kind) {
            previous = kind;
            int var6 = func_ov000_02175348(menu, kind);
            if (i <= selected && selected < i + var6) selectedStart = i;
        }
    }
    int var7 = func_ov000_0217542c(menu);
    StoreStruct* formatter = MessageSystem_GetInstance();
#if !defined(jpn)
    GameState* game = GameState::GetInstance();
    const char* separator = (const char*)KeyTable_Get((Container020e0310*)menu->messages, 0);
    const char* format = (const char*)KeyTable_Get((Container020e0310*)menu->messages, 0x754f);
#endif
    previous = -1;
    if (var7) {
        Text_AppendFrameTag(output, selectedStart, 8, 5, 5, 5);
    }
    Text_AppendCursorTag(output, selectedStart);
    for (int i = 0; i < count; i++) {
        int kind = menu->kinds[i];
        if (previous != kind) {
            previous = kind;
            int var14 = func_ov000_02175348(menu, kind);
            if (var14) {
#if defined(jpn)
                if (appended) Text_Append(output, (const char*)KeyTable_Get((Container020e0310*)menu->messages, 0));
#else
                if (appended) Text_Append(output, separator);
#endif
#if defined(jpn)
                char nameText[0x20];
                __clear(nameText, sizeof(nameText));
                char text[0x40];
                __clear(text, sizeof(text));
#else
                char text[128];
                __clear(text, 128);
#endif
                int index = i;
                if (i <= selected && selected < i + var14) index = selected;
#if defined(jpn)
                func_0203bdf4(menu->unknown_1d94_[index], nameText);
                if (var7 && selectedStart == i) {
                    char original[0x20];
                    __clear(original, sizeof(original));
                    memcpy(original, nameText, sizeof(original));
                    memset(nameText, 0, sizeof(nameText));
                    func_ov000_0217aa08(original, nameText);
                }
                func_02046380(formatter);
                MessageSystem_SetStringArgument(formatter, 0, nameText);
                func_020465c0(formatter, 0, var14);
                func_020474a8(formatter, 10, (const char*)KeyTable_Get((Container020e0310*)menu->messages, 0x754f), text);
#else
                func_02046380(formatter);
                Struct_ov000_02178938_3 name;
                NameText_Clear(&name);
                GameObject* combatant = func_0200fea4(game, menu->unknown_1d3c_[index]);
                char var21[128];
                char var22[128];
                __clear(var21, 128);
                __clear(var22, 128);
                if (combatant) {
                    func_020e4ce8(&name, combatant, 1);
                    Struct_ov000_02178938_3 var23;
                    func_020e4ce8(&var23, combatant, 0);
                    func_ov000_0217aa08(name.unknown_0_, var21);
                    func_ov000_0217aa08(name.unknown_4_, var22);
                    name.unknown_0_ = var21;
                    name.unknown_4_ = var22;
                    func_020e4f18(&var23, &name, 2);
                    name.flags &= ~0x80000000;
                }
                formatter->name = &name;
                func_020465c0(formatter, 0, var14);
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
