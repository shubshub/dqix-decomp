#include <globaldefs.h>

struct Struct_0205d81c;
struct Elem_0205d81c;

extern "C" struct Elem_0205d81c* func_0205d81c(struct Struct_0205d81c* s, int key);
extern "C" struct Elem_0205d81c* func_0205e00c(struct Struct_0205d81c* s, int key);
extern "C" void func_02050400(unsigned char* obj, int value);
extern "C" void WindowPane_SetIndicatorPage(unsigned char* obj, unsigned char value);
extern "C" void WindowPane_SetIndicatorPageCount(unsigned char* obj, int val);

// USA: func_ov002_0215b918
extern "C" ARM void func_ov002_0215b918(unsigned char* obj, int key, int b, int c) {
    struct Struct_0205d81c* s = (struct Struct_0205d81c*)(obj + 0x2c8 + 0xc00);
    struct Elem_0205d81c* elem = func_0205d81c(s, key);
    if (elem == 0) {
        elem = func_0205e00c(s, key);
        if (elem == 0) return;
    }
    if (c != 0) {
        func_02050400((unsigned char*)elem, 1);
        WindowPane_SetIndicatorPage((unsigned char*)elem, b & 0xff);
        WindowPane_SetIndicatorPageCount((unsigned char*)elem, c & 0xff);
    } else {
        func_02050400((unsigned char*)elem, 0);
        WindowPane_SetIndicatorPage((unsigned char*)elem, 0);
        WindowPane_SetIndicatorPageCount((unsigned char*)elem, 0);
    }
}
