#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void func_ov023_021f6ed8(void* arg0);
extern "C" void func_0204c684(void* arg0);
extern "C" void* func_ov011_021845f8(void* arg0, int arg1);
extern "C" void* func_ov011_021849c8(void* arg0);
extern "C" void* func_ov023_021f6880(void* arg0, int arg1);

struct Struct_ov011_021844ec;
extern "C" int func_ov011_021844ec(struct Struct_ov011_021844ec* arg0);

extern "C" void* func_ov023_021f79e4(void* arg0);

struct Obj0204c7a8;
void WindowPane_AllocateBuffer(struct Obj0204c7a8* obj, SafeAllocator* alloc, int val, unsigned int len);

struct Struct_ov011_02185318_3 {
    char unknown_0_[4];
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    unsigned short unknown_8_;
    unsigned short unknown_a_;
    char unknown_c_[4];
    unsigned int unknown_10_;
    char unknown_14_[8];
    unsigned int unknown_1c_;
    void* unknown_20_;
    void* unknown_24_;
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
extern "C" ARM int func_ov023_021f7da0(struct Struct_ov011_02185318_3* arg0, void* arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8) {
    func_ov023_021f6ed8(arg0);
    arg0->unknown_4_ = 6;
    arg0->unknown_6_ = arg2;
    arg0->unknown_8_ = arg3;
    arg0->unknown_10_ = arg0->unknown_a_ = 0;
    arg0->unknown_1c_ = 2;
    arg0->unknown_106_ = 0;
    arg0->unknown_104_ = 0;
    arg0->unknown_10a_ = 0xf;
    arg0->unknown_10c_ = 0;
    arg0->unknown_10e_ = 1;
    func_0204c684(&arg0->unknown_20_);

    void* var0 = func_ov011_021845f8(arg1, arg0->unknown_8_);
    if (var0 == NULL) {
        return 0;
    }

    int var1 = func_ov011_021844ec((struct Struct_ov011_021844ec*)arg1);
    if (var1 == 0) {
        return 0;
    }

    unsigned int var2 = (unsigned int)(arg5 * arg6) * 2;
    SafeAllocator* var3 = (SafeAllocator*)((char*)var0 + 4);
    if (var3->GetMaxPossibleAllocation() < var2) {
        return 0;
    }

    WindowPane_AllocateBuffer((struct Obj0204c7a8*)&obj->f20, alloc, f9c, len);

    void* var4 = func_ov011_021849c8(arg1);
    void* var5 = func_ov023_021f6880(var4, arg4);
    if (var5 == NULL) {
        return 0;
    }
    arg0->unknown_24_ = func_ov023_021f79e4(var5);

    arg0->unknown_108_ = (unsigned char)arg7;
    void* var6 = func_ov023_021f6880(var4, arg8);
    if (var6 != NULL) {
        arg0->unknown_20_ = (char*)var6 + 0x20;
    }
    return 1;
}
