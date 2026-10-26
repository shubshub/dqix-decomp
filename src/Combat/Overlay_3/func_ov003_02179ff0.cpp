#include <globaldefs.h>
#if defined(jpn)
enum { kRegion89c = 0x818 };
enum { Enum_ov003_02179ff0_2208 = 0x81c };
enum { Enum_ov003_02179ff0_4108 = 0xf88 };
enum { Enum_ov003_02179ff0_4118 = 0xf92 };
enum { kRegion103a = 0xfb6 };
#else
enum { kRegion89c = 0x89c };
enum { Enum_ov003_02179ff0_2208 = 0x8a0 };
enum { Enum_ov003_02179ff0_4108 = 0x100c };
enum { Enum_ov003_02179ff0_4118 = 0x1016 };
enum { kRegion103a = 0x103a };
#endif
#include "GameState/GameState.h"

extern "C" void* GameState_GetParty(GameState* battleStruct);
extern "C" short func_02080468(void* obj, int id);
extern "C" unsigned char func_0207ca94(int index);
extern "C" short func_0207c638(void* base, unsigned int index);
extern "C" int func_0207c6b8(unsigned char* obj, unsigned int index, int target);
struct Struct_020a0b8c;
extern "C" int func_020a0b8c(struct Struct_020a0b8c* p);

struct Struct_ov003_02179ff0 {
    unsigned char pad0[kRegion89c];
    void* unknown_89c_;
    unsigned char unknown_8a0_[Enum_ov003_02179ff0_4108 - Enum_ov003_02179ff0_2208];
    short mode;
    short cursor;
    short unknown_1010_;
    short unknown_1012_;
    short page;
    unsigned char unknown_1016_[kRegion103a - Enum_ov003_02179ff0_4118];
    short unknown_103a_;
};

// USA: func_ov003_02179ff0
extern "C" ARM void func_ov003_02179ff0(Struct_ov003_02179ff0* menu) {
    void* var0 = menu->unknown_89c_;
    unsigned char* list = (unsigned char*)GameState_GetParty(GameState::GetInstance());
    if (menu->mode == 0x77) {
        short tableIndex = menu->unknown_1012_ - func_02080468(var0, 0x1d);
        unsigned int table =func_0207ca94(tableIndex);
        int count = func_0207c638(list + 0x1d4, table);
        short row = menu->cursor - func_02080468(var0, 0x1e);
        short sel = row + menu->page * 5;
        if (count <= sel) sel = count - 1;
        menu->unknown_103a_ = func_0207c6b8(list + 0x1d4, table, sel);
        menu->cursor = sel % 5 + func_02080468(var0, 0x1e);
    } else {
        int count = func_020a0b8c((struct Struct_020a0b8c*)list);
        short row = menu->cursor - func_02080468(var0, 0x16);
        short sel = row + menu->page * 8;
        if (count <= sel) sel = count - 1;
        menu->unknown_103a_ = ((short*)(list + 0xc))[sel];
        menu->cursor = sel % 8 + func_02080468(var0, 0x16);
    }
}
