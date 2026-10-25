#include <globaldefs.h>

struct Struct_0205d81c;
struct Elem_0205d81c;
Elem_0205d81c* FindElementByC40205d81c(struct Struct_0205d81c* s, int key);
struct Elem_0205e00c;
Elem_0205e00c* GetElementByB4IfAbsent_0205e00c(struct Struct_0205d81c* s, int key);
void SetField0xd8State_02050400(unsigned char* obj, int value);
void WindowPane_SetIndicatorPage(unsigned char* obj, unsigned char value);
void WindowPane_SetIndicatorPageCount(unsigned char* obj, int val);

// USA: func_ov012_021842a0  (semantic: ApplyElemState_021842a0)
extern "C" ARM void func_ov012_021842a0(void* obj, int key, int p3, int p4) {
    void* e = FindElementByC40205d81c((struct Struct_0205d81c*)((char*)obj + 0xac), key);
    if (e == 0) {
        e = GetElementByB4IfAbsent_0205e00c((struct Struct_0205d81c*)((char*)obj + 0xac), key);
        if (e == 0) return;
    }
    if (p4 != 0) {
        SetField0xd8State_02050400((unsigned char*)e, 1);
        WindowPane_SetIndicatorPage((unsigned char*)e, (unsigned char)p3);
        WindowPane_SetIndicatorPageCount((unsigned char*)e, (unsigned char)p4);
    } else {
        SetField0xd8State_02050400((unsigned char*)e, 0);
        WindowPane_SetIndicatorPage((unsigned char*)e, 0);
        WindowPane_SetIndicatorPageCount((unsigned char*)e, 0);
    }
}
