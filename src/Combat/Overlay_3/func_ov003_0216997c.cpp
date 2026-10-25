#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_0216997c_228 = 0xe0 };
enum { Enum_ov003_0216997c_388 = 0x180 };
enum { Enum_ov003_0216997c_390 = 0x182 };
enum { Enum_ov003_0216997c_392 = 0x184 };
enum { Enum_ov003_0216997c_394 = 0x186 };
enum { Enum_ov003_0216997c_396 = 0x188 };
enum { Enum_ov003_0216997c_398 = 0x18a };
enum { Enum_ov003_0216997c_400 = 0x18c };
enum { Enum_ov003_0216997c_402 = 0x18e };
enum { Enum_ov003_0216997c_405 = 0x191 };
enum { Enum_ov003_0216997c_409 = 0x195 };
enum { Enum_ov003_0216997c_1261 = 0x4e9 };
enum { Enum_ov003_0216997c_2400 = 0x800 };
#else
enum { Enum_ov003_0216997c_228 = 0xe4 };
enum { Enum_ov003_0216997c_388 = 0x184 };
enum { Enum_ov003_0216997c_390 = 0x186 };
enum { Enum_ov003_0216997c_392 = 0x188 };
enum { Enum_ov003_0216997c_394 = 0x18a };
enum { Enum_ov003_0216997c_396 = 0x18c };
enum { Enum_ov003_0216997c_398 = 0x18e };
enum { Enum_ov003_0216997c_400 = 0x190 };
enum { Enum_ov003_0216997c_402 = 0x192 };
enum { Enum_ov003_0216997c_405 = 0x195 };
enum { Enum_ov003_0216997c_409 = 0x199 };
enum { Enum_ov003_0216997c_1261 = 0x4ed };
enum { Enum_ov003_0216997c_2400 = 0x960 };
#endif

#if defined(jpn)
extern "C" void Window_OpenPane(void*, void*, int, int, int, int, int);
#endif
#include "std_library_functions.h"

struct Struct_0205de24_2;
extern "C" ARM void func_0205de24(struct Struct_0205de24_2* arg0, unsigned char arg1, unsigned char arg2);

struct Container020e0310;
int KeyTable_Get(struct Container020e0310* c, int key);
extern "C" int Font_GetTextWidth(char* str, int id);
extern "C" void func_ov003_02169a84(char* base, char* dst, int flag);
#if !defined(jpn)
extern "C" void Window_OpenPane(void* a, void* b, int c, int d, int e, int f, int g, int h);
#endif

// USA: func_ov003_0216997c
extern "C" ARM void func_ov003_0216997c(void* arg0) {
    char* var0 = (char*)arg0;
    func_0205de24((struct Struct_0205de24_2*)(var0 + Enum_ov003_0216997c_228), 0, 2);

#if defined(jpn)
    int var6 = 8;
#else
    struct Container020e0310* c = (struct Container020e0310*)(obj + 0x64);
    short maxLen = 0;
    for (int i = 0; i < 3; i++) {
        int name = KeyTable_Get(c, (short)i);
        short len = (short)Font_GetTextWidth((char*)name, 0);
        if (maxLen < len) maxLen = len;
    }

    int var6 = ((var2 + 0x18) << 13) >> 16;
#endif
    *(short*)(var0 + Enum_ov003_0216997c_388) = var6;
    *(short*)(var0 + Enum_ov003_0216997c_390) = 6;
    *(short*)(var0 + Enum_ov003_0216997c_392) = 0x1f - var6;
    *(short*)(var0 + Enum_ov003_0216997c_394) = 2;
    *(short*)(var0 + Enum_ov003_0216997c_396) = 0xc;
    *(short*)(var0 + Enum_ov003_0216997c_398) = 8;
    *(short*)(var0 + Enum_ov003_0216997c_400) = 0xa;
    *(short*)(var0 + Enum_ov003_0216997c_402) = 0xe;

    *(unsigned char*)(var0 + Enum_ov003_0216997c_405) = 1;
    *(unsigned char*)(var0 + Enum_ov003_0216997c_409) = 1;
    *(unsigned char*)(var0 + Enum_ov003_0216997c_1261) = 0;

    memset(*(char**)(var0 + 0x7c), 0, Enum_ov003_0216997c_2400);
    func_ov003_02169a84(var0, *(char**)(var0 + 0x7c), 0);
#if defined(jpn)
    Window_OpenPane(obj + kRegione4, *(char**)(obj + 0x7c), 0, 1, 0, 1, 0);
#else
    Window_OpenPane(obj + kRegione4, *(char**)(obj + 0x7c), 0, 1, 0, 1, 0, 0);
#endif
}
