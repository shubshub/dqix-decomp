#include <globaldefs.h>

struct Block020473c8 {
    char pad[8];
    int val;
};

struct ArrEntry020473c8 {
    int unused0;
    struct Block020473c8* field4;
};

struct Flags020473c8 {
    unsigned char flag0 : 1;
    unsigned char flag1 : 1;
    unsigned char rest : 6;
};

struct StructAt020473c8 {
    char pad0[0xc];
    struct ArrEntry020473c8* arrayPtr; // 0xc
    char pad1[0x70 - 0xc - 4];
    int idx70; // 0x70
    int idx74; // 0x74
    char pad2[0x82 - 0x78];
    short field82; // 0x82
    struct Flags020473c8 field84; // 0x84
};

extern "C" void SprSprite_DrawGroup(struct StructAt020473c8* obj, int val, int param1);

// USA: func_020473c8
ARM void RenderFlaggedIndexedEntry(struct StructAt020473c8* obj, int param1) {
    struct ArrEntry020473c8* entry;
    struct Block020473c8* block;
    if (!obj->field84.flag0) {
        return;
    }
    if (!obj->field84.flag1) {
        return;
    }
    if (obj->field82 <= 0) {
        return;
    }
    if (obj->arrayPtr == NULL) {
        return;
    }
    entry = &obj->arrayPtr[obj->idx74];
    block = &entry->field4[obj->idx70];
    *(int*)0x4000444 = 0;
    SprSprite_DrawGroup(obj, block->val, param1);
    *(int*)0x4000448 = 1;
}
