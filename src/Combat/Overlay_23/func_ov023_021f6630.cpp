#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(int a);
extern "C" void* func_ov023_021f6880(void* thing, int b);
extern "C" int func_ov023_021f6f10(void);
extern "C" void func_ov023_021f809c(void* node, int a);

// USA: func_ov023_021f6630
extern "C" ARM void func_ov023_021f6630(int a, int b, short c, short d) {
    void* thing = func_ov011_021849c8(a);
    void* node = func_ov023_021f6880(thing, b);
    if (node == NULL) {
        return;
    }
    int r = func_ov023_021f6f10();
    if (r != 6) {
        return;
    }
    short* p = (short*)((char*)node + 0x100);
    p[2] = c;
    p[3] = d;
    func_ov023_021f809c(node, a);
}
