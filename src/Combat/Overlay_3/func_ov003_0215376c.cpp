#include <globaldefs.h>

struct BackgroundGraphics;
extern "C" void Background_Init(struct BackgroundGraphics* obj);
struct Struct_02074b64;
extern "C" void func_02074b64(struct Struct_02074b64* obj);

// USA: func_ov003_0215376c
extern "C" ARM void func_ov003_0215376c(char* obj) {
    *(int*)(obj + 0x0) = 0;
    *(int*)(obj + 0x4) = 0;
    *(int*)(obj + 0x8) = 0;
    *(int*)(obj + 0xc) = 0;
    *(int*)(obj + 0x14) = 0;
    *(int*)(obj + 0x10) = 0;
    Background_Init((struct BackgroundGraphics*)(obj + 0x18));
    int var0;
    *(unsigned char*)(obj + 0x48) = 0;
    *(unsigned char*)(obj + 0x49) = 0;
    var0 = *(unsigned char*)(obj + 0x49) - 1;
    *(int*)(obj + 0x4c) = var0;
    *(int*)(obj + 0x50) = var0;
    *(int*)(obj + 0x54) = var0;
    *(unsigned char*)(obj + 0x59) = var0;
    *(unsigned char*)(obj + 0x5a) = 0;
    *(unsigned char*)(obj + 0x5b) = 0;
    *(unsigned char*)(obj + 0x5d) = 0;
    *(unsigned char*)(obj + 0x58) = 0;
    func_02074b64((struct Struct_02074b64*)(obj + 0x38));
}
