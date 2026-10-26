#include <globaldefs.h>

struct Struct_ov023_021f68b8 { void* first; };

// USA: func_ov023_021f68b8
extern "C" ARM void* func_ov023_021f68b8(struct Struct_ov023_021f68b8* head, int n) {
    void* node = head->first;
    while (node != NULL && n > 0) {
        node = *(void**)((char*)node + 0x18);
        n--;
    }
    return node;
}
