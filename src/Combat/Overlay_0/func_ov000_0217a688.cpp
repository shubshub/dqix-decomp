#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Resource/CharacterCreationUI.h>

struct NameDescriptor { char* unknown_0_; char* unknown_4_; unsigned int flags_; };
struct StoreStruct { char pad0[0x20]; NameDescriptor* names_; };
struct Struct_ov000_02178938 {
    char pad0[0x1c];
    signed char unknown_1c_;
    char unknown_1d_[0xb8 - 0x1d];
    Container020e0310 strings_;
#if defined(jpn)
    char unknown_c0_[0x1d94 - 0xc0];
    char unknown_1d94_[8][0x38];
#else
    char unknown1_c0_[0x1d1c - 0xc0];
#endif
    int unknown_1d1c_[8];
    int unknown_1d3c_[8];
};

extern "C" int func_ov000_02175348(void*, int);
extern "C" StoreStruct* MessageSystem_GetInstance();
extern "C" int KeyTable_Get(Container020e0310*, int);
extern "C" int func_ov000_0217542c(void*);
extern "C" int Text_AppendFrameTag(char*, int, int, int, int, int);
extern "C" int Text_AppendCursorTag(char*, int);
extern "C" int Text_Append(char*, const char*);
extern "C" void* __clear(void*, int);
extern "C" void func_02046380(StoreStruct*);
extern "C" void* NameText_Clear(void*);
extern "C" GameObject* func_0200fea4(GameState*, int);
extern "C" void func_020e4ce8(NameDescriptor*, GameObject*, int);
extern "C" void func_ov000_0217aa08(char*, char*);
extern "C" void func_020e4f18(NameDescriptor*, NameDescriptor*, int);
extern "C" void func_020465c0(StoreStruct*, int, int);
extern "C" void MessageSystem_FormatText(StoreStruct*, int, const char*, char*, int, int, int);
extern "C" int Text_AppendNTag(char*, int, const char*);
extern char data_ov000_02184060[];

#if defined(jpn)
extern "C" void func_0203bdf4(char*, char*);
extern "C" void MessageSystem_SetStringArgument(StoreStruct*, int, char*);
extern "C" void func_020474a8(StoreStruct*, int, const char*, char*);
#endif

// USA: func_ov000_0217a688
extern "C" ARM void func_ov000_0217a688(Struct_ov000_02178938* self, void* unused, int count, char* output) {
    if (!output) return;
    int cursor;
    unsigned int previous;
#if defined(jpn)
    bool separated;
#else
    int separated;
#endif
    int selected;
    int i;
    previous = -1;
    cursor = 0;
    separated = 0;
    i = 0;
    selected = self->unknown_1c_;
    for (; i < count; ++i) {
        int group = self->unknown_1d1c_[i];
        if (previous == group) continue;
        previous = group;
        int members = func_ov000_02175348(self, group);
        if (i <= selected && selected < i + members) cursor = i;
    }
    StoreStruct* store = MessageSystem_GetInstance();
#if !defined(jpn)
    GameState* game = GameState::GetInstance();
    const char* separator = (const char*)KeyTable_Get(&self->strings_, 0);
    const char* format = (const char*)KeyTable_Get(&self->strings_, 0x754f);
#endif
    previous = -1;
#if defined(jpn)
    int var11 = func_ov000_0217542c(self);
    if (var11)
#else
    if (func_ov000_0217542c(self))
#endif
        Text_AppendFrameTag(output, cursor, 8, 5, 5, 5);
    Text_AppendCursorTag(output, cursor);
    for (int i = 0; i < count; ++i) {
        int group = self->unknown_1d1c_[i];
        if (previous == group) continue;
        previous = group;
        int members = func_ov000_02175348(self, group);
        if (!members) continue;
#if defined(jpn)
        if (separated) Text_Append(output, (const char*)KeyTable_Get(&self->strings_, 0));
#else
        if (separated) Text_Append(output, separator);
#endif
#if defined(jpn)
        char nameText[0x20];
        __clear(nameText, sizeof(nameText));
        char text[0x40];
        __clear(text, sizeof(text));
#else
        char text[0x80];
        __clear(text, sizeof(text));
#endif
        int index = i;
        if (i <= selected && selected < i + members) index = selected;
#if defined(jpn)
        func_0203bdf4(self->unknown_1d94_[index], nameText);
        if (var11 && cursor == i) {
            char original[0x20];
            __clear(original, sizeof(original));
            memcpy(original, nameText, sizeof(original));
            memset(nameText, 0, sizeof(nameText));
            func_ov000_0217aa08(original, nameText);
        }
        func_02046380(store);
        MessageSystem_SetStringArgument(store, 0, nameText);
        func_020465c0(store, 0, members);
        func_020474a8(store, 10, (const char*)KeyTable_Get(&self->strings_, 0x754f), text);
#else
        func_02046380(store);
        NameDescriptor names;
        NameText_Clear(&names);
        GameObject* target = func_0200fea4(game, self->unknown_1d3c_[index]);
        char var21[0x80];
        __clear(var21, sizeof(var21));
        char var22[0x80];
        __clear(var22, sizeof(var22));
        if (target) {
            func_020e4ce8(&names, target, 1);
            NameDescriptor original;
            func_020e4ce8(&original, target, 0);
            func_ov000_0217aa08(names.unknown_0_, var21);
            func_ov000_0217aa08(names.unknown_4_, var22);
            names.unknown_0_ = var21;
            names.unknown_4_ = var22;
            func_020e4f18(&original, &names, 2);
            names.flags_ &= ~0x80000000;
        }
        store->names_ = &names;
        func_020465c0(store, 0, members);
        MessageSystem_FormatText(store, 10, format, text, 0x100, 0, 0);
#endif
        Text_AppendNTag(output, i, text);
        separated = 1;
    }
#if !defined(jpn)
    Text_Append(output, data_ov000_02184060);
#endif
}
