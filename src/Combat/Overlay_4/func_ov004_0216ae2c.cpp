#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

#if defined(jpn)
enum { Enum_ov004_0216ae2c_7 = 6 };
#define data_ov004_02170154 data_ov004_0217088c
#else
enum { Enum_ov004_0216ae2c_7 = 7 };
#endif

struct Struct_ov004_02170154 { unsigned int w[Enum_ov004_0216ae2c_7]; };
extern struct Struct_ov004_02170154 data_ov004_02170154;
extern "C" void func_ov011_02184a24(void*, void*, int);
extern "C" void func_ov011_02184c28(void*, void*);
extern "C" void func_ov004_0216acf8(void);

// USA: func_ov004_0216ae2c
extern "C" ARM void func_ov004_0216ae2c(SafeAllocator* a, void* target) {
    struct Struct_ov004_02170154 tmp = data_ov004_02170154;
    void* buf = a->Allocate(sizeof(Struct_ov004_02170154));
    memcpy(buf, &tmp, sizeof(Struct_ov004_02170154));
    func_ov011_02184a24(target, buf, Enum_ov004_0216ae2c_7);
#if !defined(jpn)
    func_ov011_02184c28(target, (void*)func_ov004_0216acf8);
#endif
}
