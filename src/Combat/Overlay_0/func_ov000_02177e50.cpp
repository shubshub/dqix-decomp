#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x28
#define REGION_OFFSET_1 0x800
#else
#define REGION_OFFSET_0 0x5c
#define REGION_OFFSET_1 0x960
#endif

#include "std_library_functions.h"

extern "C" int MessageSystem_GetInstance();

extern "C" void func_ov000_0217c638(void* obj, int a, int b);
extern "C" void func_ov000_02177f74(void* obj, void* buf);
#if defined(jpn)
extern "C" void Window_OpenPane(void* s, void* buf, int a, int b, int c, int d, int e);
#else
extern "C" void Window_OpenPane(void* s, void* buf, int a, int b, int c, int d, int e, int f);
#endif

struct Struct_ov000_02177e50 {
    char pad[0x44];
    int x;
    int y;
};

// USA: func_ov000_02177e50
extern "C" ARM void func_ov000_02177e50(void* objRaw, struct Struct_ov000_02177e50* in, int arg2, int arg3) {
    char* obj = (char*)objRaw;
    if (in == 0) {
        return;
    }
    int x = in->x;
    int y = in->y;
    func_ov000_0217c638(obj, arg2, arg3);
    char* s = obj + 0x188;
#if defined(jpn)
    *(short*)(s + 0xa0) = 9;
#else
    *(short*)(s + 0xa0) = 0xb;
#endif
    *(short*)(s + 0xa2) = 9;
    *(short*)(s + 0xa4) = (x >> 3) + 9;
    *(short*)(s + 0xa6) = y >> 3;
    *(short*)(s + 0xa8) = 0xc;
    *(short*)(s + 0xaa) = 8;
    *(short*)(s + 0xac) = 0xa;
    *(short*)(s + 0xae) = 0xd;
    *(unsigned char*)(s + 0xb1) = 6;
    void* buf;
    int var5 = *(int*)(s + 0x58);
    buf = *(void**)((char*)MessageSystem_GetInstance() + REGION_OFFSET_0);
    memset(buf, 0, REGION_OFFSET_1);
    func_ov000_02177f74(obj, buf);
    int flag = (var5 > 1) ? 1 : 0;
#if defined(jpn)
    Window_OpenPane(obj + 0x188, buf, 0, 0, flag, 1, 0);
#else
    Window_OpenPane(s, buf, 0, 0, flag, 1, 0, 0);
#endif
}
