#include <globaldefs.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif

#include "std_library_functions.h"

extern "C" void func_0204f0ec(char* obj);
struct BackgroundScreen;
extern "C" void ClearRecordFields(struct BackgroundScreen* rec);

struct Struct_0204c684 {
    unsigned char flagA : 1;
    unsigned char unknown_0_1_ : 1;
#if defined(jpn)
    unsigned char unknown_0_3_ : 6;
#else
    unsigned char flagC : 1;
    unsigned char unknown_0_3_ : 5;
#endif
};

// Main, originally func_0204c684 (USA 0x0204c684, EUR 0x0204c694, JPN 0x0204d4a4)
extern "C" ARM void WindowPane_Init(char* obj) {
    *(int*)(obj + 0x0) = 0;
    *(int*)(obj + 0x4) = 0;
    *(int*)(obj + 0x8) = 0;
    func_0204f0ec(obj);

    *(int*)(obj + 0x9c) = 0;
    *(int*)(obj + 0xa0) = 0;
    *(int*)(obj + 0xa4) = 0;
    *(short*)(obj + 0xac) = 0;
    *(short*)(obj + 0xae) = 0;
    *(short*)(obj + 0xa8) = 0;
    *(short*)(obj + 0xaa) = 0;
    *(short*)(obj + 0xb0) = 4;
    *(short*)(obj + 0xb2) = 4;
    *(short*)(obj + 0xb4) = 0xa;
    *(short*)(obj + 0xb6) = 0xb;
    *(short*)(obj + 0xb8) = 0;
    *(short*)(obj + 0xba) = 0;
    *(short*)(obj + 0xbc) = 0;
    *(short*)(obj + 0xbe) = 0;
    *(short*)(obj + 0xc0) = 0;
    *(short*)(obj + 0xc2) = 0;
    *(unsigned char*)(obj + 0xc5) = 0;
    *(unsigned char*)(obj + 0xc4) = 0xff;
    *(unsigned char*)(obj + 0xc6) = 2;
    *(unsigned char*)(obj + 0xc7) = 0xa;

    ClearRecordFields((struct BackgroundScreen*)(obj + 0xc8));

    Struct_0204c684* bits = (Struct_0204c684*)(obj + 0xd8);
    bits->flagA = 0;
    bits->unknown_0_3_ = 0;
    *(unsigned char*)(obj + 0xd9) = 0;
    *(unsigned char*)(obj + 0xda) = 0;

    bits->unknown_0_1_ = 1;
#if !defined(jpn)
    bits->flagC = 0;
#endif

    memset(obj + 0xdb, 0, 4);
}
