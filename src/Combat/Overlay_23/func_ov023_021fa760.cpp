#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_ov023_021fa760_2 {
    char pad0[4];
    unsigned short kind;
    unsigned short field6;
    unsigned short field8;
    unsigned short fielda;
    char unknown_c_[4];
    int field10;
    char unknown_14_[0xc];
    int field20;
    char pad24[0x50];
    unsigned char unknown_74_;
    char unknown_75_[3];
    char unknown_78_[0x10];
};

extern "C" void func_ov023_021f6ed8(void* obj);
extern "C" void func_ov023_021faa60(void* obj, int p1);
extern "C" void SpriteContext_Init(char* obj);

// USA: func_ov023_021fa760
#if defined(jpn)
struct Struct_ov023_021fa760 {
    char pad0[4];
    unsigned short kind;
    unsigned short field6;
    unsigned short field8;
    unsigned short fielda;
    char unknown_c_[4];
    int field10;
    char unknown_14_[0xc];
    char pad20[0x50];
    unsigned char unknown_70_;
    char unknown_71_[3];
    char unknown_74_[0x10];
};

extern "C" ARM int func_ov023_021fa760(struct Struct_ov023_021fa760* obj, int p1, int p2, int p3, int p4, int p5) {
    func_ov023_021f6ed8(obj);
    obj->kind = 0xa;
    obj->field6 = p2;
    obj->field8 = p3;
    obj->fielda = 0;
    obj->field10 = p4;
    SpriteContext_Init((char*)obj + 0x20);
    memset(obj->unknown_74_, 0, 0x10);
    obj->unknown_70_ = p5;
    func_ov023_021faa60(obj, p1);
    return 1;
}
#else
extern "C" ARM int func_ov023_021fa760(struct Struct_ov023_021fa760_2* obj, int p1, int p2, int p3, int p4, int p5, int p6) {
    func_ov023_021f6ed8(obj);
    obj->kind = 0xa;
    obj->field6 = p2;
    obj->field8 = p3;
    obj->fielda = 0;
    obj->field20 = p4;
    obj->field10 = p5;
    SpriteContext_Init((char*)obj + 0x24);
    memset(obj->unknown_78_, 0, 0x10);
    obj->unknown_74_ = p6;
    func_ov023_021faa60(obj, p1);
    return 1;
}
#endif
