#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void func_ov023_021f6ed8(void* obj);
extern "C" void WindowPane_Init(void* obj);
extern "C" void* func_ov011_021845f8(void* ctx, int v);
extern "C" void* func_ov011_021849c8(void* ctx);
extern "C" void* func_ov023_021f6880(void* list, int value);

struct Struct_ov011_021844ec;
extern "C" int func_ov011_021844ec(struct Struct_ov011_021844ec* obj);

extern "C" void* func_ov023_021f79e4(void* obj);

struct WindowPane;
extern "C" void WindowPane_AllocateBuffer(struct WindowPane* obj, SafeAllocator* alloc, int val, unsigned int len);

struct Struct_ov011_02185318_3 {
    char pad0[4];
    unsigned short f4;
    unsigned short unknown_6_;
    unsigned short f8;
    unsigned short fa;
    char unknown_c_[4];
    unsigned int f10;
    char unknown_14_[8];
    unsigned int f1c;
    void* f20;
    void* f24;
    char unknown_28_[0x104 - 0x28];
    unsigned short unknown_104_;
    unsigned short unknown_106_;
    unsigned char unknown_108_;
    char unknown_109_[1];
    unsigned char unknown_10a_;
    char unknown_10b_[1];
    unsigned short unknown_10c_;
    unsigned short unknown_10e_;
};

// USA: func_ov023_021f7da0
extern "C" ARM int func_ov023_021f7da0(struct Struct_ov011_02185318_3* obj, void* ctx, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8) {
    func_ov023_021f6ed8(obj);
    obj->f4 = 6;
    obj->unknown_6_ = arg2;
    obj->f8 = arg3;
    obj->f10 = obj->fa = 0;
    obj->f1c = 2;
    obj->unknown_106_ = 0;
    obj->unknown_104_ = 0;
    obj->unknown_10a_ = 0xf;
    obj->unknown_10c_ = 0;
    obj->unknown_10e_ = 1;
    WindowPane_Init(&obj->f20);

    void* p = func_ov011_021845f8(ctx, obj->f8);
    if (p == NULL) {
        return 0;
    }

    int f9c = func_ov011_021844ec((struct Struct_ov011_021844ec*)ctx);
    if (f9c == 0) {
        return 0;
    }

    unsigned int len = (unsigned int)(arg5 * arg6) * 2;
    SafeAllocator* alloc = (SafeAllocator*)((char*)p + 4);
    if (alloc->GetMaxPossibleAllocation() < len) {
        return 0;
    }

    WindowPane_AllocateBuffer((struct WindowPane*)&obj->f20, alloc, f9c, len);

    void* list = func_ov011_021849c8(ctx);
    void* node = func_ov023_021f6880(list, arg4);
    if (node == NULL) {
        return 0;
    }
    obj->f24 = func_ov023_021f79e4(node);

    obj->unknown_108_ = (unsigned char)arg7;
    void* node2 = func_ov023_021f6880(list, arg8);
    if (node2 != NULL) {
        obj->f20 = (char*)node2 + 0x20;
    }
    return 1;
}
