#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

extern "C" void func_ov011_021848a0(void* obj, int val);
int MessageSystem_GetInstance(void);

struct Struct_ov004_02171048_7 { char unknown_0_[0x4]; unsigned char* unknown_4_; };
extern Struct_ov004_02171048_7 data_ov004_02171048;

// USA: func_ov004_0216f788
extern "C" ARM int func_ov004_0216f788(void* arg0) {
#if defined(jpn)
    enum { Enum_ov004_0216f788_9088 = 0x120, Enum_ov004_0216f788_16384 = 0x6000, Enum_ov004_0216f788_712 = 0x218 };
#else
    enum { Enum_ov004_0216f788_9088 = 0x2380, Enum_ov004_0216f788_16384 = 0x4000, Enum_ov004_0216f788_712 = 0x2c8 };
#endif
    char* p = (char*)GameState::GetInstance() + stateLowOffset + stateHighOffset;
    char buf[0x40];
    memcpy(buf, p + 4, 0x40);
    if (data_ov004_02171048.ptr[0x32] == 0) {
        func_ov011_021848a0(obj, 0x65);
        data_ov004_02171048.ptr[0x31] = 1;
    } else if (data_ov004_02171048.ptr[0x33] == 0) {
        func_ov011_021848a0(obj, 0x66);
        *(int*)((char*)MessageSystem_GetInstance() + flagOffset) = 1;
    } else {
        func_ov011_021848a0(arg0, 0xc8);
    }
    return 0;
}
