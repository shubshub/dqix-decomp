#include <globaldefs.h>

extern "C" void func_ov023_021f6ed8(void*);
extern "C" void* func_ov011_021845f8(void*, int);
extern "C" void func_ov023_021dc134(void*, int, int);
extern "C" void func_ov023_021dbfd0(void*, void*);

struct Struct_ov023_021fbd00 {
    char pad0[4];
    unsigned short f4;
    unsigned short unknown_6_;
    unsigned short f8;
    char unknown_a_[0x16];
    char unknown_20_[0x48];
    int f68;
#if defined(jpn)
    char pad6c[0x6a4];
#else
    char pad6c[0x728];
#endif
    unsigned short unknown_794_;
    char unknown_796_[2];
    unsigned char unknown_798_;
};

// USA: func_ov023_021fbd00
extern "C" ARM int func_ov023_021fbd00(Struct_ov023_021fbd00* obj, void* ctx, unsigned short arg2, unsigned short arg3, int arg4, int arg5, unsigned char arg6) {
    func_ov023_021f6ed8(obj);
    obj->f4 = 0x10;
    obj->unknown_6_ = arg2;
    obj->f8 = arg3;
    void* result = func_ov011_021845f8(ctx, obj->f8);
    if (result == NULL) return 0;
    func_ov023_021dc134(obj->unknown_20_, -1, 0);
    obj->unknown_794_ = obj->unknown_794_ | (unsigned short)(arg4 | 0x4000);
    func_ov023_021dbfd0(obj->unknown_20_, (char*)result + 4);
    obj->f68 = arg5;
    obj->unknown_798_ = arg6;
    return 1;
}
