#include <globaldefs.h>

extern int data_02107800;

#if defined(jpn)
enum { Enum_020421a0_28 = 0x38 };
#else
enum { Enum_020421a0_28 = 0x1c };
#endif

// Main, originally GetGlobalField0x1c020421a0 (USA 0x020421a0, EUR 0x020421b0, JPN 0x02042940)
extern "C" ARM int MessageSystem_GetInstance() {
    return *(int*)((char*)&data_02107800 + Enum_020421a0_28);
}
