#include <globaldefs.h>


extern "C" void func_020c6914(int cmd);

// Main, originally func_020c51a4 (USA 0x020c51a4, EUR 0x020c51b4, JPN 0x020c6c70)
extern "C" ARM void G3_MultMtx43(int cmd) {
    *(int*)0x4000400 = 0x19;
    func_020c6914(cmd);
}
