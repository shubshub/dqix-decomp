#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/CharacterCreationUI.h"
#include "std_library_functions.h"

struct StoreStruct { void* object; };
struct Struct_ov003_0215b964 { unsigned int flags; unsigned short unknown_4_; };
struct Struct_ov003_0215b964_2 {
    unsigned char unknown_0_[4];
    short id;
    unsigned char unknown_6_[0x12a];
    Struct_ov003_0215b964* status;
    BaseCombatStats* baseStats;
};
struct Struct_ov003_0215b964_3 {
    unsigned char unknown_0_[0x16c];
    unsigned short values[13];
#if defined(jpn)
    unsigned char unknown_186_[0x8b8 - 0x186];
#else
    unsigned char unknown1_186_[0x950 - 0x186];
#endif
    int selected;
};
struct Struct_ov003_0215b964_4 {
    char unknown_0_[0x8e0];
    char formatted[0x40];
    char input[0x40];
};
struct Struct_ov003_0215b964_5 {
    unsigned char unknown_0_[0x64];
    Container020e0310 texts;
#if defined(jpn)
    unsigned char unknown1_6c_[0x585 - 0x64 - sizeof(Container020e0310)];
#else
    unsigned char unknown_6c_[0x10];
    Struct_ov003_0215b964_4* buffers;
    unsigned char unknown_80_[0x505];
#endif
    signed char cursor;
    unsigned char unknown_586_[0xa];
    unsigned char count;
    unsigned char unknown_591_[1];
};
extern "C" int MessageSystem_GetInstance();
extern "C" int KeyTable_Get(Container020e0310*, int);
extern "C" int func_02053c6c(unsigned char*);
#if defined(jpn)
extern "C" int func_02042638(char*, int, int);
#else
extern "C" int func_02041fac(char*, int, int);
#endif
extern "C" int Text_AppendFrameTag(char*, int, int, int, int, int);
extern "C" int Text_AppendCursorTag(char*, int);
extern "C" int Text_AppendPaletteTag(char*, int);
extern "C" int func_02041a90(char*, int, int);
extern "C" int func_02041a28(char*, int);
extern "C" int Text_Append(char*, const char*);
extern "C" int Text_AppendNTag(char*, int, const char*);
extern "C" void NameText_InitFromPartyMember(void*, int);
extern "C" void func_02046380(void*);
extern "C" void MessageSystem_FormatText(void*, int, void*, void*, int, int, int);
extern "C" void func_020465c0(StoreStruct*, int, int);
extern "C" void func_020465f0(unsigned char*, int, unsigned char);
extern "C" void func_020465d8(unsigned char*, int, unsigned char);
extern "C" int StandardStrings_Get(int);

#if defined(jpn)
extern const char data_ov003_0217fe7f[];
extern "C" void __clear(void*, int);
extern "C" void func_020474a8(void*, int, char*, char*);
#endif

// JPN: func_ov003_0215b964 (0215cd60)
// USA: func_ov003_0215b964
extern "C" ARM void func_ov003_0215b964(Struct_ov003_0215b964_5* menu, char* output, int showFrame) {
#if !defined(jpn)
    Struct_ov003_0215b964_4* buffers;
#endif
    if (!output) return;
    StoreStruct* formatter = (StoreStruct*)MessageSystem_GetInstance();
    int cursor = menu->cursor;
#if !defined(jpn)
    buffers = menu->buffers;
#endif
    if (cursor == -1) {
#if defined(jpn)
        func_02042638(output, KeyTable_Get(&menu->texts, 10), 14);
#else
        func_02041fac(output, KeyTable_Get(&menu->texts, 10), 14);
#endif
    } else {
#if defined(jpn)
        func_02042638(output, KeyTable_Get(&menu->texts, 11), 14);
#else
        func_02041fac(output, KeyTable_Get(&menu->texts, 11), 14);
#endif
        if (showFrame) Text_AppendFrameTag(output, cursor, 8, 5, 5, 5);
        Text_AppendCursorTag(output, cursor);
    }
    GameState* game = GameState::GetInstance();
    for (int index = 0; index < menu->count; ++index) {
        Struct_ov003_0215b964_2* combatant = (Struct_ov003_0215b964_2*)func_0200ff1c(game, menu->unknown_591_[index]);
        Struct_ov003_0215b964_3* detail = (Struct_ov003_0215b964_3*)func_02053c6c((unsigned char*)combatant);
        float ratio;
        int var8;
        Struct_ov003_0215b964* status = combatant->status;
        unsigned int flags = status->flags;
        var8 = combatant->baseStats->primaryStats.maxHP;
        if (0.0f == (float)var8) ratio = 0.0f;
        else {
            float var11 = (float)(int)status->unknown_4_;
            ratio = var11 / (float)var8;
        }
        if (flags & 1) Text_AppendPaletteTag(output, 9);
        else if (ratio <= 0.08f) Text_AppendPaletteTag(output, 11);
        else if (ratio <= 0.25f) Text_AppendPaletteTag(output, 13);
        else Text_AppendPaletteTag(output, 15);
#if defined(jpn)
        func_02041a28(output, 12);
#else
        func_02041a90(output, 12, index * 14 + 20);
#endif
        const char* name;
        if (cursor == -1) {
            name = combatant->baseStats->name;
            Text_Append(output, name);
        } else {
            name = combatant->baseStats->name;
            Text_AppendNTag(output, index, name);
        }
#if defined(jpn)
        if (combatant->status->flags & 1)
            Text_Append(output, ((const char*)(KeyTable_Get(&menu->texts, 13))));
        else if (flags & 2)
            Text_Append(output, ((const char*)(KeyTable_Get(&menu->texts, 14))));
        else if (flags & 4)
            Text_Append(output, ((const char*)(KeyTable_Get(&menu->texts, 15))));
        if (!(combatant->status->flags & 1) && !(flags & 6)) {
            func_02046380(formatter);
            func_020465c0(formatter, 0, detail->values[detail->selected]);
            func_020465f0(((unsigned char*)(formatter)), 0, 2);
            func_020465d8(((unsigned char*)(formatter)), 0, 1);
            char formatted[0x40];
            __clear(formatted, sizeof(formatted));
            func_020474a8(formatter, 10, ((char*)(KeyTable_Get(&menu->texts, 12))), formatted);
            Text_Append(output, formatted);
        }
        if (index != menu->count - 1) Text_Append(output, data_ov003_0217fe7f);
#else
        memset(buffers->formatted, 0, 0x40);
        memset(buffers->input, 0, 0x40);
        func_02041a28(buffers->input, 0x40);
        if (combatant->status->flags & 1)
            Text_Append(buffers->input, (const char*)KeyTable_Get(&menu->texts, 13));
        else if (flags & 2)
            Text_Append(buffers->input, (const char*)KeyTable_Get(&menu->texts, 14));
        else if (flags & 4)
            Text_Append(buffers->input, (const char*)KeyTable_Get(&menu->texts, 15));
        unsigned int descriptor[3];
        NameText_InitFromPartyMember(descriptor, combatant->id);
        func_02046380(formatter);
        formatter->object = descriptor;
        MessageSystem_FormatText(formatter, 10, buffers->input, buffers->formatted, 0x100, 0, 0);
        Text_Append(output, buffers->formatted);
        if (!(combatant->status->flags & 1) && !(flags & 6)) {
            func_02046380(formatter);
            func_020465c0(formatter, 0, detail->values[detail->selected]);
            func_020465f0((unsigned char*)formatter, 0, 2);
            func_020465d8((unsigned char*)formatter, 0, 1);
            memset(buffers->formatted, 0, 0x40);
            memset(buffers->input, 0, 0x40);
            func_02041a28(buffers->input, 0x40);
            Text_Append(buffers->input, (const char*)StandardStrings_Get(0x3f3));
            Text_Append(buffers->input, (const char*)KeyTable_Get(&menu->texts, 12));
            MessageSystem_FormatText(formatter, 10, buffers->input, buffers->formatted, 0x100, 0, 0);
            Text_Append(output, buffers->formatted);
        }
#endif
    }
}
