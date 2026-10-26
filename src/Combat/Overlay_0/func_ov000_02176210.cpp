#include <globaldefs.h>

struct Struct_0205d81c;

struct Elem_0205d81c {
    char pad0[0xa8];
    short width;
    short height;
    short x;
    short y;
};

extern "C" struct Elem_0205d81c* func_0205d81c(struct Struct_0205d81c* s, int key);
extern "C" void func_0205d904(unsigned char* obj);

// USA: func_ov000_02176210
extern "C" ARM void func_ov000_02176210(struct Struct_0205d81c* s, int key1, int key2) {
    struct Elem_0205d81c* first = func_0205d81c(s, key1);
    struct Elem_0205d81c* second = func_0205d81c(s, key2);
    if (first == NULL || second == NULL) return;

    short var2 = first->y;
    short var3 = first->height;
    short var4 = second->width;
    short var5 = first->width;
    short var6 = second->height;
    first->x = 0x20 - var5;
    first->y = var2;
    short var7 = 0x20 - var4;
    short var8 = var2 + var3;
    if (var8 + var6 > 0x18) var8 = var2 - var6;
    second->x = var7;
    second->y = var8;
    func_0205d904((unsigned char*)s);
}
