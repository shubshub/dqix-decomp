#include <globaldefs.h>

struct Struct_020beed8 { int f0; int f4; int f8; int fc; };
struct Struct_020bc180_2 { int f0; int f4; int f8; int fc; };

extern "C" void func_020c01ec(struct Struct_020beed8* t);
extern "C" void func_020c0204(struct Struct_020bc180_2* t, int end, int duration);

struct Struct_020bc4f8 {
    unsigned char unknown_0_[0x1c];   /* 0x00 */
    Struct_020beed8 unknown_1c_;         /* 0x1c */
    unsigned char pad2c;         /* 0x2c */
    unsigned char unknown_2d_;           /* 0x2d */
    unsigned char unknown_2e_;           /* 0x2e */
    unsigned char unknown_2f_;           /* 0x2f */
    unsigned char unknown_30_[4];      /* 0x30 */
    unsigned short f34;          /* 0x34 */
    unsigned char unknown_36_[8];      /* 0x36 */
    unsigned short unknown_3e_;          /* 0x3e */
    unsigned char f40;           /* 0x40 */
    unsigned char unknown_41_;           /* 0x41 */
};

// USA: func_020bc610
extern "C" ARM void func_020bc610(struct Struct_020bc4f8* obj) {
    obj->unknown_2e_ = 0;
    obj->unknown_2d_ = 0;
    obj->unknown_2f_ = 0;
    obj->f34 = 0;
    obj->unknown_3e_ = 0;
    obj->f40 = 0x7f;
    obj->unknown_41_ = 0x7f;
    func_020c01ec(&obj->unknown_1c_);
    func_020c0204((struct Struct_020bc180_2*)&obj->unknown_1c_, 0x7f00, 1);
}
