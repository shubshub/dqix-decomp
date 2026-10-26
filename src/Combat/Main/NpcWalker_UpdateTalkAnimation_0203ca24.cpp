#include <globaldefs.h>
#include "std_library_functions.h"

extern signed char data_020efc18;
extern char data_020efd54[];
extern char data_020efd60[];
extern char data_020efd6c[];
extern char data_020efd78[];
extern char data_020efd84[];

extern "C" float _fflt(int v);
extern "C" float _fsub(float a, float b);
extern "C" int _ffix(float v);

extern "C" void func_020a27b8(unsigned char* obj);
extern "C" int Camera_GetOrbitYaw(void* obj);
extern "C" void func_020a27ac(void* obj);
struct Struct_0203ca24;
extern "C" void func_0203cedc(struct Struct_0203ca24* obj, int b, int c);
struct Struct_0203ca24_2;
extern "C" void func_0203f1e4(struct Struct_0203ca24_2* obj, const char* name);

enum { Enum_0203ca24_m1 = -1 };

struct Obj0203ca24 {
    char pad0[0x4];
    int field4;
    char pad8[0x5c - 0x8];
    int unknown_5c_;
    char pad60[0x94 - 0x60];
    unsigned char field94;
    char unknown_95_[0x98 - 0x95];
    int field98;
};

// Main, originally func_0203ca24 (USA 0x0203ca24, EUR 0x0203ca34, JPN 0x0203cf5c)
extern "C" ARM void NpcWalker_UpdateTalkAnimation(struct Obj0203ca24* obj, void* p23c) {
    char buf[20];
    int a;
    int b;
    signed char v;

    func_020a27b8((unsigned char*)p23c);
    a = Camera_GetOrbitYaw(p23c);
    b = _ffix(_fsub(25736.0f, _fflt(1608)));
    memset(buf, 0, 19);

    v = data_020efc18;
    if (v > Enum_0203ca24_m1) {
        if (v == 0) {
            goto pathB;
        }
    }
    if (a >= 1608) {
        if (b > a) {
            goto pathC;
        }
    }

pathB:
    if (obj->field98 > obj->field4) {
        memcpy(buf, data_020efd54, 11);
    } else {
        memcpy(buf, data_020efd60, 11);
    }
    data_020efc18 = 0;
    goto tail;

pathC:
    if (v > Enum_0203ca24_m1) {
        if (v == 1) {
            goto path1;
        }
    }
    if (a >= 12868) {
        goto path2;
    }

path1:
    memcpy(buf, data_020efd6c, 11);
    data_020efc18 = 1;
    goto tail;

path2:
    memcpy(buf, data_020efd78, 11);
    data_020efc18 = 2;

tail:
    if (obj->unknown_5c_ & 0x20) {
        memcpy((char*)buf + 11, data_020efd84, 7);
        buf[19] = 0;
        obj->field94--;
        if (obj->field94 == 0) {
            func_0203cedc((struct Struct_0203ca24*)obj, 0, 0);
            obj->field94 = 0xf;
            func_020a27ac(p23c);
            data_020efc18 = -1;
        }
    }

    func_0203f1e4((struct Struct_0203ca24_2*)obj, buf);
}
