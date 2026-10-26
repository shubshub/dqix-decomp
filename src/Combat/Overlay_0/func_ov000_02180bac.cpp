#include <globaldefs.h>

struct Struct_0204bbb4;
extern "C" void func_0204bbb4(struct Struct_0204bbb4* obj, unsigned int idx, int a2, int a3,
                           short a4, short a5, short a6, short a7, unsigned short a8);
extern "C" void SpriteContext_DrawSprite(void* dst, void* src);
extern "C" int* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsActive(int* obj);

extern const int data_ov000_021836a0[];

struct Struct_ov000_02180bac {
    char pad0[0x14];
    int field14;
    int field18;
    char pad1[0x22 - 0x1c];
    unsigned char field22;
    char pad2[0x26 - 0x23];
    unsigned char field26;
    char pad3[0x28 - 0x27];
};

struct Struct_ov000_02180bac_2 {
    char pad0[0x1a];
    signed char unknown_1a_;
    char pad1[0x11c - 0x1b];
    char field11c[0x170 - 0x11c];
    struct Struct_ov000_02180bac* entries;
    char pad2[0x8c4 - 0x174];
    char list8c4[0x930 - 0x8c4];
    int unknown_930_;
    int unknown_934_;
#if defined(jpn)
    char pad3[0x1faa - 0x938];
#else
    char pad3[0x1d72 - 0x938];
#endif
    unsigned short unknown_1d72_;
};

// USA: func_ov000_02180bac
extern "C" ARM void func_ov000_02180bac(struct Struct_ov000_02180bac_2* obj) {
    func_0204bbb4((struct Struct_0204bbb4*)obj->list8c4, 4, 1, 4, 0, 0, 0x20, 1, 0xffff);
    if (obj->unknown_934_ != 3) {
        struct Struct_ov000_02180bac* e = &obj->entries[19];
        e->field14 = obj->unknown_930_ << 12;
        e->field18 = 0x2000;
#if defined(jpn)
        e->field22 = 0x44;
#else
        e->field22 = 0x48;
#endif
        e->field26 = 1;
        SpriteContext_DrawSprite(obj->field11c, e);
    }
    int flag = (obj->unknown_1d72_ & 0x400) ? 1 : 0;
    if (flag & LinkSession_IsActive(LinkSession_GetInstance())) {
        struct Struct_ov000_02180bac* e = &obj->entries[6];
        int idx = obj->unknown_1a_ - 2;
        if (obj->unknown_1a_ < 0) {
            obj->unknown_1a_ = 0;
        }
        e->field14 = 0xc8000;
        e->field18 = data_ov000_021836a0[idx] << 12;
#if defined(jpn)
        e->field22 = 0x78;
#else
        e->field22 = 0;
#endif
        e->field26 = 0;
        SpriteContext_DrawSprite(obj->field11c, e);
    }
}
