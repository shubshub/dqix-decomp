#include <globaldefs.h>
#include "Memory/SafeAllocator.h"


extern "C" void HaltSystem(void);
extern "C" void func_ov017_021d4c04(void*, int, void*, int, void*, int);
extern "C" void func_ov011_021888ec(void* obj);

struct Struct_ov011_02184550 {
    char pad0[0xa8];
    int unknown_a8_;
    int unknown_ac_;
};

// USA: func_ov011_02184550
extern "C" ARM void func_ov011_02184550(struct Struct_ov011_02184550* obj, SafeAllocator* alloc, int a2, int a3) {
    obj->unknown_a8_ = a2;
    obj->unknown_ac_ = a3;
    void* buf1 = alloc->Allocate(0x400);
    void* buf2 = alloc->Allocate(0x1800);
    if (buf1 == 0 || buf2 == 0) {
        HaltSystem();
    }
    func_ov017_021d4c04((char*)obj + 0xb8, obj->unknown_a8_, buf1, 0x80, buf2, 0x200);
    func_ov011_021888ec((char*)obj + 0xb8);
}
