#include <globaldefs.h>

extern "C" void Background_CopyScreenRect(void*, void*, int, int, int, int, int, int, int, int);

struct Struct_0204b938 { short x; short y; };

// USA: func_0204b938
extern "C" ARM void func_0204b938(void* obj, void* p, int a3, int a4, unsigned short a5) {
    struct Struct_0204b938* pt = (struct Struct_0204b938*)p;
    void* field14;
    short x, y;
    if (p == NULL) return;
    field14 = *(void**)((char*)obj + 0x14);
    x = pt->x;
    y = pt->y;
    if (field14 == NULL) return;
    Background_CopyScreenRect(obj, field14, (int)p, 0, 0, a3, a4, x, y, a5);
}
