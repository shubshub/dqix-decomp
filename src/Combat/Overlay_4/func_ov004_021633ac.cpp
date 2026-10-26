#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov004_021633ac_96 = 0x5c, Enum_ov004_021633ac_24 = 0x17 };
#else
enum { Enum_ov004_021633ac_96 = 0x60, Enum_ov004_021633ac_24 = 0x18 };
#endif

#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

extern "C" void func_ov011_02184a24(void* obj, void* v1, int v2);
extern unsigned char data_ov004_02170444;

// USA: func_ov004_021633ac
extern "C" ARM void func_ov004_021633ac(SafeAllocator* a, void* obj) {
    void* buf = a->Allocate(Enum_ov004_021633ac_96);
    memcpy(buf, &data_ov004_02170444, Enum_ov004_021633ac_96);
    func_ov011_02184a24(obj, buf, Enum_ov004_021633ac_24);
}
