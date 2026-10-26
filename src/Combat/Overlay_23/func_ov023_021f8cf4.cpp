#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

extern "C" void func_ov023_021f6ed8(void* obj);
extern "C" void* func_ov011_021845f8(void* ctx, int v);

extern int data_ov023_021fff24;

struct Struct_ov023_021f8cf4 {
    char pad0[0x4];
    unsigned short f4;
    unsigned short unknown_6_;
    unsigned short f8;
    unsigned short fa;
    char unknown_c_[0x10 - 0xc];
    unsigned int f10;
    char unknown_14_[0x1c - 0x14];
    unsigned int f1c;
    void* f20;
    unsigned short f24;
    unsigned short unknown_26_;
    unsigned short f28;
    unsigned short unknown_2a_;
    unsigned int unknown_2c_;
    unsigned int unknown_30_;
    unsigned int f34;
    unsigned int unknown_38_;
    char unknown_3c_[0x5e - 0x3c];
    unsigned short unknown_5e_;
    unsigned char f60;
    unsigned char unknown_61_;
    unsigned char unknown_62_;
};

// USA: func_ov023_021f8cf4
extern "C" ARM int func_ov023_021f8cf4(struct Struct_ov023_021f8cf4* obj, void* ctx, int arg2, int arg3, int arg4, int arg5) {
    func_ov023_021f6ed8(obj);
    obj->f4 = 7;
    obj->unknown_6_ = arg2;
    obj->f8 = arg3;
    obj->fa = 0;
    obj->f10 = 0;
    obj->f24 = arg4;
    obj->unknown_26_ = arg5;
    obj->f28 = 0;
    obj->unknown_2a_ = 0;
    obj->unknown_2c_ = 0;
    obj->unknown_30_ = 0;
    obj->f34 = 0;
    obj->unknown_38_ = 1;
    obj->f1c = 2;

    void* p = func_ov011_021845f8(ctx, obj->f8);
    if (p == NULL) {
        return 0;
    }

    int size = arg5 * (arg4 * 2);
    SafeAllocator* alloc = (SafeAllocator*)((char*)p + 4);
    obj->f20 = alloc->Allocate(size);
    if (obj->f20 == NULL) {
        return 0;
    }
    memset(obj->f20, 0, size);

    unsigned short* arr = (unsigned short*)((char*)obj + 0x3c);
    arr[0] = 0;
    arr[1] = 0;
    arr[2] = 0;
    arr[3] = 0;
    arr[4] = 0;
    arr[5] = 0;
    arr[6] = 0;
    arr[7] = 0;
    arr[8] = 0;
    arr[9] = 0;
    arr[10] = 0;
    arr[11] = 0;
    arr[12] = 0;
    arr[13] = 0;
    arr[14] = 0;
    arr[15] = 0;

    data_ov023_021fff24 = 0x1f4;

    arr[16] = 0;

    obj->unknown_5e_ = 1;
    obj->f60 = 1;
    obj->unknown_61_ = 1;
    obj->unknown_62_ = 0;
    return 1;
}
