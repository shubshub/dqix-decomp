#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov003_021672e4_96 = 0x30 };
#else
enum { Enum_ov003_021672e4_96 = 0x60 };
#endif


extern "C" unsigned short GetSubBGVRAMBanks(void);
extern "C" unsigned short GetSubObjVRAMBanks(void);

struct Struct_02074b64;
extern "C" void func_02074b64(struct Struct_02074b64* obj);

struct Struct_ov003_021672e4 {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    char unknown_1c_[Enum_ov003_021672e4_96 - 0x1c];
    int f60;
    int f64;
    int f68;
    int f6c;
    int unknown_70_;
    unsigned char unknown_74_;
    unsigned char unknown_75_;
    unsigned char unknown_76_;
};

// USA: func_ov003_021672e4
extern "C" ARM void func_ov003_021672e4(struct Struct_ov003_021672e4* obj, int p1, int p2) {
    obj->f0 = 0;
    obj->f4 = 0;
    obj->f8 = 0;
    obj->fc = 0;
    obj->f10 = 0;
    obj->f14 = GetSubBGVRAMBanks();
    obj->f18 = GetSubObjVRAMBanks();
    *((unsigned char*)obj + 0x2c) = 0;
    *((unsigned char*)obj + 0x2d) = 0;
    func_02074b64((struct Struct_02074b64*)((char*)obj + 0x1c));
    obj->f60 = (*(volatile unsigned int*)0x4001000 & 0x1f00) >> 8;
    obj->f64 = -1;
    obj->f68 = obj->f6c = 0;
    obj->unknown_70_ = p1;
    obj->unknown_74_ = 0;
    obj->unknown_75_ = 0;
    obj->unknown_76_ = (unsigned char)p2;
}
