#include <globaldefs.h>

struct Struct_0205d81c;
struct Elem_0205d81c;
extern "C" Elem_0205d81c* func_0205d81c(struct Struct_0205d81c* s, int key);
struct Struct_0205e00c;
extern "C" Struct_0205e00c* func_0205e00c(struct Struct_0205d81c* s, int key);
extern "C" void func_02050400(unsigned char* obj, int value);
extern "C" void WindowPane_SetIndicatorPage(unsigned char* obj, unsigned char value);
extern "C" void WindowPane_SetIndicatorPageCount(unsigned char* obj, int val);

// USA: func_ov012_021842a0
extern "C" ARM void func_ov012_021842a0(void* obj, int key, int p3, int p4) {
    void* e = func_0205d81c((struct Struct_0205d81c*)((char*)obj + 0xac), key);
    if (e == 0) {
        e = func_0205e00c((struct Struct_0205d81c*)((char*)obj + 0xac), key);
        if (e == 0) return;
    }
    if (p4 != 0) {
        func_02050400((unsigned char*)e, 1);
        WindowPane_SetIndicatorPage((unsigned char*)e, (unsigned char)p3);
        WindowPane_SetIndicatorPageCount((unsigned char*)e, (unsigned char)p4);
    } else {
        func_02050400((unsigned char*)e, 0);
        WindowPane_SetIndicatorPage((unsigned char*)e, 0);
        WindowPane_SetIndicatorPageCount((unsigned char*)e, 0);
    }
}
