#include <globaldefs.h>

struct Struct_020beeac_2;
extern "C" void func_020bf2d4(void *obj);
extern "C" void func_020beeac(struct Struct_020beeac_2 *p);
struct SignedAllocatorList; struct SignedAllocatorHeader;
extern "C" void func_020bf358(SignedAllocatorList*, SignedAllocatorHeader*);

extern char data_02110a40;

struct Struct_021103b0_3 { int f0; unsigned char* f4; };
extern struct Struct_021103b0_3 data_021103b0;

struct Struct_020bf1a0 {
    char pad0[0x110];
    signed int unknown_110_0_ : 1;
    signed int unknown_110_1_ : 31;
    char pad1[0x54];
    void (*unknown_168_)(void*);
};

// USA: func_020bf238
extern "C" ARM void func_020bf238(struct Struct_020bf1a0 *obj) {
    if (!obj->unknown_110_0_) return;
    func_020bf2d4(obj);
    obj->unknown_168_(obj);
    func_020bf358((SignedAllocatorList*)&data_02110a40, (SignedAllocatorHeader*)obj);
    if (data_021103b0.f4 != 0) {
        func_020bf358((SignedAllocatorList*)(data_021103b0.f4 + 0x4e0), (SignedAllocatorHeader*)obj);
    }
    func_020beeac((struct Struct_020beeac_2*)obj);
}
