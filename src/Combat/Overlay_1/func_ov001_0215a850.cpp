#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

extern "C" void func_ov001_0215a79c(void);
extern "C" void func_ov001_0215a8dc(void);

struct Struct_ov001_02165880_2 { char pad0[4]; void* p4; void* p8; char pad1[0x1c - 0xc]; void* unknown_1c_; void* unknown_20_; void* unknown_24_; };
extern struct Struct_ov001_02165880_2 data_ov001_02165880;

// USA: func_ov001_0215a850
extern "C" ARM void func_ov001_0215a850(SafeAllocator* allocator) {
    void* p8 = allocator->Allocate(0x260);
    unsigned int var1 = 0xa28;
    data_ov001_02165880.p8 = p8;
    void* var2 = allocator->Allocate(var1);
    unsigned int var3 = 0x700;
    data_ov001_02165880.unknown_24_ = var2;
    void* var4 = allocator->Allocate(var3);
    unsigned int var5 = 0x84c0;
    data_ov001_02165880.unknown_20_ = var4;
    void* var6 = allocator->Allocate(var5);
    unsigned int var7 = 0x200;
    data_ov001_02165880.unknown_1c_ = var6;
    void* p4 = allocator->Allocate(var7);
    data_ov001_02165880.p4 = p4;
    memset(p4, 0, 0x200);
    func_ov001_0215a79c();
    func_ov001_0215a8dc();
}
