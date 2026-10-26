#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
extern "C" unsigned short func_ov023_021f6f10(void*);

struct Struct_ov004_0216aed0 {
    char pad0[0x38];
    short field38;
    char unknown_3a_[8];
    short unknown_42_;
    char unknown_44_[1];
    unsigned char unknown_45_;
};

// USA: func_ov004_0216aed0
extern "C" ARM int func_ov004_0216aed0(void* a, int b, int c, int d) {
    Struct_ov004_0216aed0* obj = (Struct_ov004_0216aed0*)func_ov023_021f6880(func_ov011_021849c8(a), b);
    if (!obj) return (int)obj;
    int type = func_ov023_021f6f10(obj);
    if (type == 8 && (obj->field38 = (short)c, d == 1)) {
    } else {
        return type;
    }
    obj->unknown_45_ = (obj->unknown_45_ & ~0x7e) | 4;
    obj->unknown_42_ = 0;
    return 0;
}
