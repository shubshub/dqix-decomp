#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_02179ff0_2204 = 0x818 };
enum { Enum_ov003_02179ff0_2208 = 0x81c };
enum { Enum_ov003_02179ff0_4108 = 0xf88 };
enum { Enum_ov003_02179ff0_4118 = 0xf92 };
enum { Enum_ov003_02179ff0_4154 = 0xfb6 };
#else
enum { Enum_ov003_02179ff0_2204 = 0x89c };
enum { Enum_ov003_02179ff0_2208 = 0x8a0 };
enum { Enum_ov003_02179ff0_4108 = 0x100c };
enum { Enum_ov003_02179ff0_4118 = 0x1016 };
enum { Enum_ov003_02179ff0_4154 = 0x103a };
#endif
#include "GameState/GameState.h"

void* GameState_GetParty(GameState* battleStruct);
short FindMappedMemberId02080468(void* obj, int id);
unsigned char GetTableByte0207ca94(int index);
short CountPositiveEntries0207c638(void* base, unsigned int index);
int FindNthPositiveShort0207c6b8(unsigned char* obj, unsigned int index, int target);
struct S_a0b8c;
int CountNonZeroValues020a0b8c(struct S_a0b8c* p);

struct Struct_ov003_02179ff0 {
    unsigned char unknown_0_[Enum_ov003_02179ff0_2204];
    void* unknown_89c_;
    unsigned char unknown_8a0_[Enum_ov003_02179ff0_4108 - Enum_ov003_02179ff0_2208];
    short unknown_100c_;
    short unknown_100e_;
    short unknown_1010_;
    short unknown_1012_;
    short unknown_1014_;
    unsigned char unknown_1016_[Enum_ov003_02179ff0_4154 - Enum_ov003_02179ff0_4118];
    short unknown_103a_;
};

// USA: func_ov003_02179ff0
extern "C" ARM void func_ov003_02179ff0(ListMenu_02179ff0* menu) {
    void* memberMap = menu->memberMap;
    unsigned char* list = (unsigned char*)GameState_GetParty(GameState::GetInstance());
    if (menu->mode == 0x77) {
        short tableIndex = menu->tableCursor - FindMappedMemberId02080468(memberMap, 0x1d);
        unsigned int table =GetTableByte0207ca94(tableIndex);
        int count = CountPositiveEntries0207c638(list + 0x1d4, table);
        short row = menu->cursor - FindMappedMemberId02080468(memberMap, 0x1e);
        short sel = row + menu->page * 5;
        if (count <= sel) sel = count - 1;
        menu->selectedId = FindNthPositiveShort0207c6b8(list + 0x1d4, table, sel);
        menu->cursor = sel % 5 + FindMappedMemberId02080468(memberMap, 0x1e);
    } else {
        int var7 = func_020a0b8c((struct Struct_020a0b8c*)var1);
        short var8 = arg0->unknown_100e_ - func_02080468(var0, 0x16);
        short var9 = var8 + arg0->unknown_1014_ * 8;
        if (var7 <= var9) var9 = var7 - 1;
        arg0->unknown_103a_ = ((short*)(var1 + 0xc))[var9];
        arg0->unknown_100e_ = var9 % 8 + func_02080468(var0, 0x16);
    }
}
