#include <globaldefs.h>
#include "Resource/GameResources.h"
#if defined(jpn)
enum { Enum_ov003_02173508_237 = 0xe9 };
enum { Enum_ov003_02173508_235 = 0xeb };
enum { Enum_ov003_02173508_240 = 0xec };
enum { Enum_ov003_02173508_268 = 0x11a };
enum { Enum_ov003_02173508_269 = 0x11b };
enum { Enum_ov003_02173508_292 = 0x130 };
#else
enum { Enum_ov003_02173508_237 = 0xed };
enum { Enum_ov003_02173508_239 = 0xef };
enum { Enum_ov003_02173508_240 = 0xf0 };
enum { Enum_ov003_02173508_268 = 0x10c };
enum { Enum_ov003_02173508_269 = 0x10d };
enum { Enum_ov003_02173508_292 = 0x124 };
#endif

extern "C" void func_020dc2bc(void);
struct Struct_02074b64;
extern "C" void func_02074b64(struct Struct_02074b64* obj);

struct Struct_ov003_02173508 {
    char unknown_0_[Enum_ov003_02173508_237];
    unsigned char unknown_ed_;
    unsigned char unknown_ee_;
    unsigned char unknown_ef_;
    char unknown_f0_[Enum_ov003_02173508_268 - Enum_ov003_02173508_240];
    char unknown_10c_[1];
    char unknown_10d_[Enum_ov003_02173508_292 - Enum_ov003_02173508_269];
    int unknown_124_;
};

// USA: func_ov003_02173508
extern "C" ARM void func_ov003_02173508(Struct_ov003_02173508* obj) {
    (int)GetGameResources();
    if (obj->unknown_ef_ != 0) return;

    func_020dc2bc();
    func_02074b64((struct Struct_02074b64*)((char*)obj + Enum_ov003_02173508_268));

    volatile unsigned int* reg = (volatile unsigned int*)0x4001000;
    obj->unknown_124_ = (*reg & 0x1f00) >> 8;
    *reg = (*reg & ~0x1f00) | 0x1300;

    volatile unsigned short* bg = (volatile unsigned short*)((char*)reg + 0x8);
    bg[0] = bg[0] & ~3;
    bg[1] = (bg[1] & ~3) | 1;
    bg[2] = (bg[2] & ~3) | 2;
    bg[3] = (bg[3] & ~3) | 3;

    bg[0] = (bg[0] & 0x43) | 0xe00;
    bg[1] = (bg[1] & 0x43) | 0xf00;

    obj->unknown_ed_ = 1;
    obj->unknown_ef_ = 0;
}
