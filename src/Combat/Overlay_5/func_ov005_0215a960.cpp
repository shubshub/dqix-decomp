#include <globaldefs.h>
#include "Resource/MessageSystem.h"

struct Struct_ov005_02153954 {
    #if defined(jpn)
    char unknown_0_[0x3d84];
#else
    char unknown1_0_[0x3e0c];
#endif
    unsigned short unknown_3e0c_[20][3];
};

extern "C" char data_ov005_0215ce05[];

extern "C" int sprintf(char* out, const char* format, ...);
int MessageSystem_GetInstance();
#if defined(jpn)
extern "C" unsigned short func_020469b0(Struct_02021b84* arg0, const char* arg1, unsigned short* arg2, int);
#endif
extern "C" unsigned short func_02045d14(Struct_02021b84* arg0, const char* arg1, unsigned short* arg2, int arg3);
extern "C" void func_020439b0(Struct_02021b84* arg0, int arg1);

// USA: func_ov005_0215a960
extern "C" ARM void func_ov005_0215a960(EquipmentMenu* self) {
    MessageSystem* messages = (MessageSystem*)MessageSystem_GetInstance();
#if !defined(jpn)
    var0->unknown_195b_ &= ~0x80;
#endif
    for (int var1 = 0; var1 < 20; var1++) {
        for (int var2 = 0; var2 < 3; var2++)
            arg0->unknown_3e0c_[var1][var2] = 0xffff;
#if defined(jpn)
        char var3[3];
        var3[2] = 0;
        if (var1 < 10) {
            var3[0] = '\x82';
            var3[1] = '\x4f';
        } else {
            var3[0] = '\xea';
            var3[1] = '\x40';
        }
        int var4 = var1 % 10;
        var3[1] += var4;
        func_020469b0(var0, var3, arg0->unknown_3e0c_[var1], 8);
#else
        int var4 = var1 % 10;
        char var5[2];
        sprintf(var5, data_ov005_0215ce05, var4);
        func_02045d14(var0, var5, arg0->unknown_3e0c_[var1], 0);
#endif
        if (var4 == 9) {
            func_020439b0(var0, 0);
#if !defined(jpn)
            var0->unknown_195b_ |= 0x80;
#endif
        }
    }
#if !defined(jpn)
    var0->unknown_195b_ &= ~0x80;
#endif
}
