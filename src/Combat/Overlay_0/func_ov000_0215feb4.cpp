#include <globaldefs.h>

struct Struct_ov000_0215feb4 {
    char pad[0x20];
    struct Struct_ov000_0215feb4* next;
};

// USA: func_ov000_0215feb4
extern "C" ARM struct Struct_ov000_0215feb4* func_ov000_0215feb4(char* base, int threshold, int slot) {
    struct Struct_ov000_0215feb4* node;
    int i;
    if (*(unsigned char*)(base + slot + 0x26) <= threshold) return 0;
    node = *(struct Struct_ov000_0215feb4**)(base + slot * 4);
    i = 0;
    while (i < threshold && node != 0) {
        node = node->next;
        i++;
    }
    return node;
}
