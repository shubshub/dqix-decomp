#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/CharacterCreationUI.h"
#include "std_library_functions.h"

struct Struct_020465c0 { void* unknown_0_; };
struct Struct_ov003_0215b964 { unsigned int unknown_0_; unsigned short unknown_4_; };
struct Struct_ov003_0215b964_2 {
    unsigned char unknown_0_[4];
    short unknown_4_;
    unsigned char unknown_6_[0x12a];
    Struct_ov003_0215b964* unknown_130_;
    BaseCombatStats* unknown_134_;
};
struct Struct_ov003_0215b964_3 {
    unsigned char unknown_0_[0x16c];
    unsigned short unknown_16c_[13];
#if defined(jpn)
    unsigned char unknown_186_[0x8b8 - 0x186];
#else
    unsigned char unknown1_186_[0x950 - 0x186];
#endif
    int unknown_950_;
};
struct Struct_ov003_0215b964_4 {
    char unknown_0_[0x8e0];
    char unknown_8e0_[0x40];
    char unknown_920_[0x40];
};
struct Struct_ov003_0215b964_5 {
    unsigned char unknown_0_[0x64];
    Struct_0201099c_3 unknown_64_;
#if defined(jpn)
    unsigned char unknown1_6c_[0x585 - 0x64 - sizeof(Struct_0201099c_3)];
#else
    unsigned char unknown_6c_[0x10];
    Struct_ov003_0215b964_4* unknown_7c_;
    unsigned char unknown_80_[0x505];
#endif
    signed char unknown_585_;
    unsigned char unknown_586_[0xa];
    unsigned char unknown_590_;
    unsigned char unknown_591_[1];
};
int MessageSystem_GetInstance();
int KeyTable_Get(Container020e0310*, int);
int GetFieldAt0x150_02053c6c(unsigned char*);
#if defined(jpn)
extern "C" int func_02042638(char*, int, int);
#else
extern "C" int func_02041fac(char*, int, int);
#endif
int Text_AppendFrameTag(char*, int, int, int, int, int);
int Text_AppendCursorTag(char*, int);
int Text_AppendPaletteTag(char*, int);
int AppendXYTag_02041a90(char*, int, int);
int AppendXTag_02041a28(char*, int);
int Text_Append(char*, const char*);
int Text_AppendNTag(char*, int, const char*);
void NameText_InitFromPartyMember(void*, int);
extern "C" void func_02046380(void*);
extern "C" void MessageSystem_FormatText(void*, int, void*, void*, int, int, int);
void StoreInArray0x8b0_020465c0(StoreStruct*, int, int);
void SetByteInRange_020465f0(unsigned char*, int, unsigned char);
void SetByteAtIndex_020465d8(unsigned char*, int, unsigned char);
int StandardStrings_Get(int);

#if defined(jpn)
extern const char data_ov003_0217fe7f[];
extern "C" void __clear(void*, int);
extern "C" void func_020474a8(void*, int, char*, char*);
#endif

// JPN: func_ov003_0215b964 (0215cd60)
// USA: func_ov003_0215b964
extern "C" ARM void func_ov003_0215b964(Struct_ov003_0215b964_5* arg0, char* arg1, int arg2) {
#if !defined(jpn)
    Struct_ov003_0215b964_4* var0;
#endif
    if (!output) return;
    StoreStruct* formatter = (StoreStruct*)MessageSystem_GetInstance();
    int cursor = menu->cursor;
#if !defined(jpn)
    var0 = arg0->unknown_7c_;
#endif
    if (var2 == -1) {
#if defined(jpn)
        func_02042638(output, KeyTable_Get(&menu->texts, 10), 14);
#else
        AppendFormatted02041fac(output, KeyTable_Get(&menu->texts, 10), 14);
#endif
    } else {
#if defined(jpn)
        func_02042638(output, KeyTable_Get(&menu->texts, 11), 14);
#else
        AppendFormatted02041fac(output, KeyTable_Get(&menu->texts, 11), 14);
#endif
        if (showFrame) Text_AppendFrameTag(output, cursor, 8, 5, 5, 5);
        Text_AppendCursorTag(output, cursor);
    }
    GameState* var3 = GameState::GetInstance();
    for (int var4 = 0; var4 < arg0->unknown_590_; ++var4) {
        Struct_ov003_0215b964_2* var5 = (Struct_ov003_0215b964_2*)func_0200ff1c(var3, arg0->unknown_591_[var4]);
        Struct_ov003_0215b964_3* var6 = (Struct_ov003_0215b964_3*)func_02053c6c((unsigned char*)var5);
        float var7;
        int var8;
        Struct_ov003_0215b964* var9 = var5->unknown_130_;
        unsigned int var10 = var9->unknown_0_;
        var8 = var5->unknown_134_->primaryStats.maxHP;
        if (0.0f == (float)var8) var7 = 0.0f;
        else {
            float var11 = (float)(int)var9->unknown_4_;
            var7 = var11 / (float)var8;
        }
        if (flags & 1) Text_AppendPaletteTag(output, 9);
        else if (ratio <= 0.08f) Text_AppendPaletteTag(output, 11);
        else if (ratio <= 0.25f) Text_AppendPaletteTag(output, 13);
        else Text_AppendPaletteTag(output, 15);
#if defined(jpn)
        func_02041a28(arg1, 12);
#else
        func_02041a90(arg1, 12, var4 * 14 + 20);
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
            StoreInArray0x8b0_020465c0(formatter, 0, detail->values[detail->selected]);
            SetByteInRange_020465f0(((unsigned char*)(formatter)), 0, 2);
            SetByteAtIndex_020465d8(((unsigned char*)(formatter)), 0, 1);
            char formatted[0x40];
            __clear(formatted, sizeof(formatted));
            func_020474a8(formatter, 10, ((char*)(KeyTable_Get(&menu->texts, 12))), formatted);
            Text_Append(output, formatted);
        }
        if (index != menu->count - 1) Text_Append(output, data_ov003_0217fe7f);
#else
        memset(buffers->formatted, 0, 0x40);
        memset(buffers->input, 0, 0x40);
        AppendXTag_02041a28(buffers->input, 0x40);
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
            StoreInArray0x8b0_020465c0(formatter, 0, detail->values[detail->selected]);
            SetByteInRange_020465f0((unsigned char*)formatter, 0, 2);
            SetByteAtIndex_020465d8((unsigned char*)formatter, 0, 1);
            memset(buffers->formatted, 0, 0x40);
            memset(buffers->input, 0, 0x40);
            AppendXTag_02041a28(buffers->input, 0x40);
            Text_Append(buffers->input, (const char*)StandardStrings_Get(0x3f3));
            Text_Append(buffers->input, (const char*)KeyTable_Get(&menu->texts, 12));
            MessageSystem_FormatText(formatter, 10, buffers->input, buffers->formatted, 0x100, 0, 0);
            Text_Append(output, buffers->formatted);
        }
#endif
    }
}
