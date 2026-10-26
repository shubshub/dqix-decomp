#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

#if defined(jpn)
enum { Enum_ov004_02165df4_38 = 36 };
#define data_ov004_0216ff00 data_ov004_02170668
#else
enum { Enum_ov004_02165df4_38 = 38 };
#endif

struct Struct_ov004_0216ff00 { unsigned int w[Enum_ov004_02165df4_38]; };
extern struct Struct_ov004_0216ff00 data_ov004_0216ff00;
extern "C" void func_ov011_02184a24(void*, void*, int);
extern "C" void func_ov011_02184c28(void*, void*);
extern "C" void func_ov004_02165be4(void);

// USA: func_ov004_02165df4
extern "C" ARM void func_ov004_02165df4(SafeAllocator* a, void* target) {
    struct Struct_ov004_0216ff00 tmp = data_ov004_0216ff00;
    void* buf = a->Allocate(sizeof(Struct_ov004_0216ff00));
    memcpy(buf, &tmp, sizeof(Struct_ov004_0216ff00));
    func_ov011_02184a24(target, buf, Enum_ov004_02165df4_38);
    func_ov011_02184c28(target, (void*)func_ov004_02165be4);
}
