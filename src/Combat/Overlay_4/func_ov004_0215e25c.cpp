#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

#if defined(jpn)
enum { Enum_ov004_0215e25c_100 = 99 };
#define data_ov004_0216fc40 data_ov004_021703c8
#else
enum { Enum_ov004_0215e25c_100 = 100 };
#endif

struct Struct_ov004_0216fc40 { unsigned int words[Enum_ov004_0215e25c_100]; };
extern Struct_ov004_0216fc40 data_ov004_0216fc40;

extern "C" void func_ov011_02184a24(void* obj, void* data, int size);
extern "C" void func_ov011_02184c28(void* obj, void* arg1);
extern "C" void func_ov004_0215e148(void);

// USA: func_ov004_0215e25c
extern "C" ARM void func_ov004_0215e25c(void* allocator, void* obj) {
    Struct_ov004_0216fc40 local = data_ov004_0216fc40;
    void* block = ((SafeAllocator*)allocator)->Allocate(sizeof(Struct_ov004_0216fc40));
    memcpy(block, &local, sizeof(Struct_ov004_0216fc40));
    func_ov011_02184a24(obj, block, Enum_ov004_0215e25c_100);
    func_ov011_02184c28(obj, (void*)func_ov004_0215e148);
}
