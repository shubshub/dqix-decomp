#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_02161438_1024 = 0x200 };
enum { Enum_ov003_02161438_140 = 0xb4 };
enum { Enum_ov003_02161438_159 = 0xc7 };
enum { Enum_ov003_02161438_792 = 0x200 };
#else
enum { Enum_ov003_02161438_1024 = 0x400 };
enum { Enum_ov003_02161438_140 = 0x8c };
enum { Enum_ov003_02161438_159 = 0x9f };
enum { Enum_ov003_02161438_792 = 0x318 };
#endif

extern "C" void* func_ov003_02160bd0(void* unused, int index);
extern "C" void func_ov003_02167a5c(void* p, int type, int val);

// USA: func_ov003_02161438
extern "C" ARM void func_ov003_02161438(void* obj) {
    char* p = (char*)obj + Enum_ov003_02161438_1024;
    short v = *(short*)(p + Enum_ov003_02161438_140);
    signed char b = *(signed char*)(p + Enum_ov003_02161438_159);
    int idx = (v - 0x15) + (b << 2);
    int val = -1;
    void* e = func_ov003_02160bd0(obj, idx);
    if (e != NULL) {
        signed char c = *(signed char*)e;
        val = (c << 26) >> 26;
    }
    func_ov003_02167a5c(*(void**)((char*)obj + Enum_ov003_02161438_792), 6, val);
}
