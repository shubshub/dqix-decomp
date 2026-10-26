#include <globaldefs.h>
#include "NitroSDK/ProcessorContext.h"
#include "NitroSDK/Memory.h"
#include "std_library_functions.h"

enum Enum_020019c8 {
    Enum_020019c8_0,
    Enum_020019c8_1,
    Enum_020019c8_2,
    Enum_020019c8_3,
    Enum_020019c8_4,
    Enum_020019c8_5,
    Enum_020019c8_6,
    Enum_020019c8_7,
    Enum_020019c8_8,
    Enum_020019c8_9
};
enum Enum_020019c8_B {
    Enum_020019c8_B_0,
    Enum_020019c8_B_1,
    Enum_020019c8_B_2,
    Enum_020019c8_B_3,
    Enum_020019c8_B_4
};
typedef void (*Type_ov031_02212ab4)(Enum_020019c8_B, Enum_020019c8, int);
typedef void (*Type_020019c8)(void);

struct Struct_ov031_02212ab4 {
    Type_ov031_02212ab4 callback;
    Type_020019c8 unknown_4_;
    char unknown_8_[32];
    char unknown_28_[32];
    int unknown_48_;
    unsigned char unknown_4c_[0x9c0 - 0x4c];
    ProcessorContext context;
};
extern Struct_ov031_02212ab4* data_ov031_0224e5c0;
extern char data_ov031_02249ab4[];
extern "C" int func_ov031_02211aec();
extern "C" void* func_ov031_02212790(void*, int);
extern "C" void* func_ov031_022127a8(void*);
extern "C" int func_ov031_02212524(char*, void*);
extern "C" void func_ov031_022128fc();

// USA: func_ov031_02212ab4
extern "C" ARM int func_ov031_02212ab4(Type_ov031_02212ab4 callback, char* arg1, char* arg2) {
    if (func_ov031_02211aec()) return 0;
    data_ov031_0224e5c0 = (Struct_ov031_02212ab4*)func_ov031_02212790((void*)0xa80, 32);
    data_ov031_0224e5c0->unknown_48_ = 0;
    VectorizedMemset(data_ov031_0224e5c0, 0, 0xa80);
    data_ov031_0224e5c0->callback = callback;
    strncpy(data_ov031_0224e5c0->unknown_8_, arg1, 31);
    strncpy(data_ov031_0224e5c0->unknown_28_, arg2, 31);
    if (!func_ov031_02212524(data_ov031_02249ab4, data_ov031_0224e5c0->unknown_4c_)) {
        func_ov031_022127a8(data_ov031_0224e5c0);
        data_ov031_0224e5c0 = 0;
        return 0;
    }
    PopulateContext(&data_ov031_0224e5c0->context, (unsigned int)func_ov031_022128fc, 0, (unsigned int)&data_ov031_0224e5c0->context, 0x800, 16);
    MarkContextReadyAndSwitch(&data_ov031_0224e5c0->context);
    return 1;
}
