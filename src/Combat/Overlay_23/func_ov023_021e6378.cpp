#include <globaldefs.h>

struct Struct_0205d81c;
extern "C" void Window_SetPanePalette(struct Struct_0205d81c* s, int key, int value);

// USA: func_ov023_021e6378
extern "C" ARM void func_ov023_021e6378(void* obj, int a, int b, int c, unsigned char d) {
    *((unsigned char*)obj + 0x1371) = (unsigned char)a;
    Window_SetPanePalette((struct Struct_0205d81c*)((char*)obj + 0xac), 7, b);
    Window_SetPanePalette((struct Struct_0205d81c*)((char*)obj + 0xac), 8, c);
    Window_SetPanePalette((struct Struct_0205d81c*)((char*)obj + 0xac), 9, d);
}
