#include <globaldefs.h>

struct Struct_020473c8_2 {
    char pad[8];
    int val;
};

struct Struct_020473c8_3 {
    int unused0;
    struct Struct_020473c8_2* field4;
};

struct Struct_020473c8 {
    unsigned char unknown_0_0_ : 1;
    unsigned char flag1 : 1;
    unsigned char rest : 6;
};

struct StructAt020473c8 {
    char pad0[0xc];
    struct Struct_020473c8_3* unknown_c_; // 0xc
    char pad1[0x70 - 0xc - 4];
    int unknown_70_; // 0x70
    int unknown_74_; // 0x74
    char pad2[0x82 - 0x78];
    short unknown_82_; // 0x82
    struct Struct_020473c8 unknown_84_; // 0x84
};

extern "C" void SprSprite_DrawGroup(struct StructAt020473c8* obj, int val, int param1);

// USA: func_020473c8
extern "C" ARM void func_020473c8(struct StructAt020473c8* obj, int param1) {
    struct Struct_020473c8_3* entry;
    struct Struct_020473c8_2* block;
    if (!obj->unknown_84_.unknown_0_0_) {
        return;
    }
    if (!obj->unknown_84_.flag1) {
        return;
    }
    if (obj->unknown_82_ <= 0) {
        return;
    }
    if (obj->unknown_c_ == NULL) {
        return;
    }
    entry = &obj->unknown_c_[obj->unknown_74_];
    block = &entry->field4[obj->unknown_70_];
    *(int*)0x4000444 = 0;
    SprSprite_DrawGroup(obj, block->val, param1);
    *(int*)0x4000448 = 1;
}
