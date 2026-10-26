#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

#if defined(jpn)
enum { Enum_ov004_02156dc8_8 = 7 };
#define data_ov004_0216faec data_ov004_02170278
#else
enum { Enum_ov004_02156dc8_8 = 8 };
#endif

struct Struct_ov004_0216faec { unsigned int v[Enum_ov004_02156dc8_8]; };

extern Struct_ov004_0216faec data_ov004_0216faec;

extern "C" int func_ov011_02184a24(int, void*, int);

// USA: func_ov004_02156dc8
extern "C" ARM int func_ov004_02156dc8(SafeAllocator* alloc, int arg) {
    Struct_ov004_0216faec local = data_ov004_0216faec;
    void* buf = alloc->Allocate(sizeof(Struct_ov004_0216faec));
    memcpy(buf, &local, sizeof(Struct_ov004_0216faec));
    return func_ov011_02184a24(arg, buf, Enum_ov004_02156dc8_8);
}
