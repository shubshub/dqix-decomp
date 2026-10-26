#include <globaldefs.h>

extern "C" void* func_ov023_021e1604(void* a, int b, int c, int d);

// USA: func_ov023_021e1564
extern "C" ARM void func_ov023_021e1564(void* a, int b, int c, int d) {
    void* node = func_ov023_021e1604(a, b, c, d);
    if (node == NULL) return;
    *(void**)a = node;
    while (node != NULL) {
        void* next = func_ov023_021e1604(a, b, c, d);
        *(void**)node = next;
        node = next;
    }
}
