#include <globaldefs.h>

struct Obj0204bbb4;
void CallListEntry0204bbb4(struct Obj0204bbb4* obj, unsigned int idx, int a2, int a3,
                           short a4, short a5, short a6, short a7, unsigned short a8);
extern "C" void SpriteContext_DrawSprite(void* dst, void* src);
extern "C" int* func_0202ae18(void);
extern "C" int func_0202b7d8(int* arg0);

extern const int data_ov000_021836a0[];

struct Struct_ov000_02180bac {
    char unknown_0_[0x14];
    int unknown_14_;
    int unknown_18_;
    char unknown_1c_[0x22 - 0x1c];
    unsigned char unknown_22_;
    char unknown_23_[0x26 - 0x23];
    unsigned char unknown_26_;
    char unknown_27_[0x28 - 0x27];
};

struct Struct_ov000_02180bac_2 {
    char unknown_0_[0x1a];
    signed char unknown_1a_;
    char unknown_1b_[0x11c - 0x1b];
    char unknown_11c_[0x170 - 0x11c];
    struct Struct_ov000_02180bac* unknown_170_;
    char unknown_174_[0x8c4 - 0x174];
    char unknown_8c4_[0x930 - 0x8c4];
    int unknown_930_;
    int unknown_934_;
#if defined(jpn)
    char unknown_938_[0x1faa - 0x938];
#else
    char unknown1_938_[0x1d72 - 0x938];
#endif
    unsigned short unknown_1d72_;
};

// USA: func_ov000_02180bac
extern "C" ARM void func_ov000_02180bac(struct Struct_ov000_02180bac_2* arg0) {
    func_0204bbb4((struct Struct_0204bbb4*)arg0->unknown_8c4_, 4, 1, 4, 0, 0, 0x20, 1, 0xffff);
    if (arg0->unknown_934_ != 3) {
        struct Struct_ov000_02180bac* var0 = &arg0->unknown_170_[19];
        var0->unknown_14_ = arg0->unknown_930_ << 12;
        var0->unknown_18_ = 0x2000;
#if defined(jpn)
        var0->unknown_22_ = 0x44;
#else
        var0->unknown_22_ = 0x48;
#endif
        e->field26 = 1;
        SpriteContext_DrawSprite(obj->field11c, e);
    }
    int var1 = (arg0->unknown_1d72_ & 0x400) ? 1 : 0;
    if (var1 & func_0202b7d8(func_0202ae18())) {
        struct Struct_ov000_02180bac* var2 = &arg0->unknown_170_[6];
        int var3 = arg0->unknown_1a_ - 2;
        if (arg0->unknown_1a_ < 0) {
            arg0->unknown_1a_ = 0;
        }
        var2->unknown_14_ = 0xc8000;
        var2->unknown_18_ = data_ov000_021836a0[var3] << 12;
#if defined(jpn)
        var2->unknown_22_ = 0x78;
#else
        var2->unknown_22_ = 0;
#endif
        e->field26 = 0;
        SpriteContext_DrawSprite(obj->field11c, e);
    }
}
