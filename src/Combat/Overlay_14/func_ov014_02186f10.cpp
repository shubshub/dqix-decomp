#if defined(jpn)
#define R(j,u) (j)
#define data_ov008_0218b490 data_ov008_0218c0f1
#define data_ov014_021896d4 data_ov014_0218a4e4
#define data_ov014_0218981c data_ov014_0218a5fc
#define data_ov015_02193d20 data_ov015_02194850
#define data_ov015_02193fe0 data_ov015_02194b20
#define data_ov015_02194052 data_ov015_02194b92
#define data_ov015_02194078 data_ov015_02194bb8
#define data_ov015_0219415c data_ov015_02194c9c
#define data_ov015_02194160 data_ov015_02194ca0
#define data_ov015_02194167 data_ov015_02194ca7
#define func_ov008_021895a8 func_ov008_0218a2b0
#define func_ov008_02189c70 func_ov008_0218a930
#define func_ov008_0218aee4 func_ov008_0218bb50
#define func_ov014_021886f8 func_ov014_021895c8
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "Input/Input.h"

extern "C" int func_02080dd4(void* obj, int p1, int arg2, int arg3, unsigned char* outFlag, unsigned char extra);
extern "C" void func_020813ec(void* obj, int key);

// USA: func_ov014_02186f10
extern "C" ARM int func_ov014_02186f10(char* self) {
    unsigned char flag = 0;

    if (g_keyManager.TestKeysPressed(0x401)) {
        flag = 1;
    }

    if (g_touchInput.pressed_ != 0 && *(short**)(self + 0xd0) != 0) {
        int a, b;
        g_touchInput.GetTouchPoint(&a, &b);
        int result = func_02080dd4(*(void**)(self + 0xc0), *(short*)(self + 0x170), (short)a, (short)b, &flag, 1);
        if (result < 0) {
            return 0;
        }
        *(*(short**)(self + 0xd0)) = (short)result;
        short cur = *(*(short**)(self + 0xd0));
        if (*(short*)(self + 0x178) != cur) {
            *(short*)(*(char**)(self + 0xc0) + R(0x2a, 0x36)) = cur;
            func_020813ec(*(void**)(self + 0xc0), *(short*)(self + 0x170));
        }
    }

    return flag;
}
