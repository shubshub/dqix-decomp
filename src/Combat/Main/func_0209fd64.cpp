#include <globaldefs.h>
#include "Memory/SafeAllocator.h"


extern "C" void HaltSystem(void);
extern "C" void func_ov017_021d4c04(void*, int, void*, int, void*, int);
extern "C" void func_0209dc4c(void* obj);

extern void* data_02109d88;

struct Struct_0209fd64 {
    char pad0[0x8];
    int field8;
    int unknown_c_;
    char unknown_10_[0x1000];
};

// USA: func_0209fd64
extern "C" ARM void func_0209fd64(struct Struct_0209fd64* obj, struct SafeAllocator* alloc, int a2, int a3) {
    data_02109d88 = obj;
    obj->field8 = a2;
    obj->unknown_c_ = a3;

    void* buf1 = alloc->Allocate(0x400);
    void* buf2 = alloc->Allocate(0x1800);
    if (buf1 == NULL || buf2 == NULL) {
        HaltSystem();
    }

    func_ov017_021d4c04(&obj->unknown_10_, obj->field8, buf1, 0x80, buf2, 0x200);
    func_0209dc4c(&obj->unknown_10_);
}
