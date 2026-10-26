#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct0205de24;

extern "C" void func_0205de24(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);
extern "C" void func_ov002_0215be00(void* obj, int val, int a2, int a3);
extern "C" void func_ov002_021607cc(void* obj, void* ptr, int flag);
#if defined(jpn)
extern "C" void Window_OpenPane(void* ptr, int val, int a2, int a3, int s0, int s1, int s2);
#else
extern "C" void Window_OpenPane(void* ptr, int val, int a2, int a3, int s0, int s1, int s2, int s3);
#endif

// USA: func_ov002_02160734
#if defined(jpn)
extern "C" ARM void func_ov002_02160734(unsigned char* obj) {
    func_0205de24((struct Struct0205de24*)(obj + 0xe20), 0, 2);

    func_ov002_0215be00(obj, (*(int*)(obj + 0x1a80)) & 0xff, 1, 1);

    memset(*(void**)(obj + 0x1a98), 0, 0x800);

    func_ov002_021607cc(obj, *(void**)(obj + 0x1a98), 0);

    Window_OpenPane(obj + 0xe20, *(int*)(obj + 0x1a98), 0, 0, 0, 1, 0);
}
#else
extern "C" ARM void func_ov002_02160734(unsigned char* obj) {
    func_0205de24((struct Struct0205de24*)(obj + 0x2c8 + 0xc00), 0, 2);

    func_ov002_0215be00(obj, (*(int*)(obj + 0x1000 + 0xbb8)) & 0xff, 1, 1);

    memset(*(void**)(obj + 0x1000 + 0xbd0), 0, 0x960);

    func_ov002_021607cc(obj, *(void**)(obj + 0x1000 + 0xbd0), 0);

    Window_OpenPane(obj + 0x2c8 + 0xc00, *(int*)(obj + 0x1000 + 0xbd0), 0, 0, 0, 1, 0, 0);
}
#endif
