#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

extern "C" int func_ov004_0216aa10(void);
#if defined(jpn)
enum { Enum_ov004_0216aa70_19 = 18 };
#define data_ov004_021700ec data_ov004_02170844
#else
enum { Enum_ov004_0216aa70_19 = 19 };
#endif

struct Struct_ov004_021700ec { unsigned int w[Enum_ov004_0216aa70_19]; };
extern struct Struct_ov004_021700ec data_ov004_021700ec;
extern "C" void func_ov011_02184a24(void*, void*, int);
extern "C" void func_ov011_02184c28(void*, void*);

// USA: func_ov004_0216aa70
extern "C" ARM void func_ov004_0216aa70(SafeAllocator* a, void* target) {
    struct Struct_ov004_021700ec tmp = data_ov004_021700ec;
    void* buf = a->Allocate(sizeof(Struct_ov004_021700ec));
    memcpy(buf, &tmp, sizeof(Struct_ov004_021700ec));
    func_ov011_02184a24(target, buf, Enum_ov004_0216aa70_19);
    func_ov011_02184c28(target, (void*)func_ov004_0216aa10);
}
