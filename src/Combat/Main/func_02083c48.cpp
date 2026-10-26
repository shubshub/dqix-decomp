#include <globaldefs.h>
#include "Resource/GameResources.h"

extern "C" void func_ov017_02191aac(char* obj, int mode, int idx, unsigned char mask);
extern "C" void func_ov017_021ce014(int a, unsigned short b, unsigned short c, unsigned short d);

// USA: func_02083c48
extern "C" ARM void func_02083c48(char* obj, int arg1, int arg2) {
    obj[0x56c] = 0;
    if (arg2) {
        short v = *(short*)(obj + 0x568);
        func_ov017_02191aac((char*)GetGameResources(), 0, v, 2);
    }
    if (arg1) {
        unsigned short v = *(unsigned short*)(obj + 0x568);
        func_ov017_021ce014(0, 1, 0, v);
    }
}
