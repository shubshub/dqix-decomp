#include <globaldefs.h>
#include "std_library_functions.h"

extern signed char data_020efc18;
extern char data_020efd54[];
extern char data_020efd60[];
extern char data_020efd6c[];
extern char data_020efd78[];
extern char data_020efd84[];

extern "C" float _fflt(int v);
extern "C" float _fsub(float arg0, float arg1);
extern "C" int _ffix(float v);

extern void ClearIntAt0x23c_020a27b8(unsigned char* obj);
extern int Camera_GetOrbitYaw(void* obj);
extern void SetField0x23cTrue_020a27ac(void* obj);
struct Struct0203cedc;
extern void SetCombatFlags0x5c(struct Struct0203cedc* obj, int b, int c);
struct Obj0203f1e4;
extern void SelectNamedEntry0203f1e4(struct Obj0203f1e4* obj, const char* name);

enum { Enum_0203ca24_m1 = -1 };

struct Struct_0203ca24_3 {
    char unknown_0_[0x4];
    int unknown_4_;
    char unknown_8_[0x5c - 0x8];
    int unknown_5c_;
    char unknown_60_[0x94 - 0x60];
    unsigned char unknown_94_;
    char unknown_95_[0x98 - 0x95];
    int unknown_98_;
};

// Main, originally func_0203ca24 (USA 0x0203ca24, EUR 0x0203ca34, JPN 0x0203cf5c)
extern "C" ARM void NpcWalker_UpdateTalkAnimation(struct Obj0203ca24* obj, void* p23c) {
    char buf[20];
    int a;
    int b;
    signed char v;

    ClearIntAt0x23c_020a27b8((unsigned char*)p23c);
    a = Camera_GetOrbitYaw(p23c);
    b = _ffix(_fsub(25736.0f, _fflt(1608)));
    memset(buf, 0, 19);

    var3 = data_020efc18;
    if (var3 > Enum_0203ca24_m1) {
        if (var3 == 0) {
            goto pathB;
        }
    }
    if (var1 >= 1608) {
        if (var2 > var1) {
            goto pathC;
        }
    }

pathB:
    if (arg0->unknown_98_ > arg0->unknown_4_) {
        memcpy(var0, data_020efd54, 11);
    } else {
        memcpy(var0, data_020efd60, 11);
    }
    data_020efc18 = 0;
    goto tail;

pathC:
    if (var3 > Enum_0203ca24_m1) {
        if (var3 == 1) {
            goto path1;
        }
    }
    if (var1 >= 12868) {
        goto path2;
    }

path1:
    memcpy(var0, data_020efd6c, 11);
    data_020efc18 = 1;
    goto tail;

path2:
    memcpy(var0, data_020efd78, 11);
    data_020efc18 = 2;

tail:
    if (arg0->unknown_5c_ & 0x20) {
        memcpy((char*)var0 + 11, data_020efd84, 7);
        var0[19] = 0;
        arg0->unknown_94_--;
        if (arg0->unknown_94_ == 0) {
            func_0203cedc((struct Struct_0203ca24*)arg0, 0, 0);
            arg0->unknown_94_ = 0xf;
            func_020a27ac(arg1);
            data_020efc18 = -1;
        }
    }

    func_0203f1e4((struct Struct_0203ca24_2*)arg0, var0);
}
