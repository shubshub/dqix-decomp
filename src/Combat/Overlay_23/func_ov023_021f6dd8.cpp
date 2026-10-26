#include <globaldefs.h>

struct Struct_ov023_021f6dd8 { int f0; int f4; int pad8; Struct_ov023_021f6dd8* next; };

// USA: func_ov023_021f6dd8
extern "C" ARM int func_ov023_021f6dd8(void* obj, int arg1) {
    Struct_ov023_021f6dd8* node = *(Struct_ov023_021f6dd8**)((char*)obj + 0x28);
    while (node != NULL) {
        int v = node->f4;
        Struct_ov023_021f6dd8* next = node->next;
        int sum = v + arg1;
        node = next;
        if (node == NULL) {
            return v;
        }
        if ((unsigned int)sum <= (unsigned int)node->f0) {
            return v;
        }
    }
    return 0;
}
