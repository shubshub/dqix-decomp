#include <globaldefs.h>
#include "Memory/SafeAllocator.h"


extern "C" void HaltSystem(void);
extern "C" void func_ov017_021d4c04(void*, int, void*, int, void*, int);
extern "C" void func_ov023_021eb000(void*);

extern void* data_02109d8c;

struct Struct_0209fee4 {
    char pad0[0x4];
    int field4;
    int field8;
    char unknown_c_[0x1000];
};

// USA: func_0209fee4
extern "C" ARM void func_0209fee4(struct Struct_0209fee4* obj, struct SafeAllocator* alloc, int a2, int a3) {
    data_02109d8c = obj;
    obj->field4 = a2;
    obj->field8 = a3;

    void* buf1 = alloc->Allocate(0x400);
    void* buf2 = alloc->Allocate(0x1800);
    if (buf1 == NULL || buf2 == NULL) {
        HaltSystem();
    }

    func_ov017_021d4c04(&obj->unknown_c_, obj->field4, buf1, 0x80, buf2, 0x200);
    func_ov023_021eb000(&obj->unknown_c_);
}
