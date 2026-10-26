#include <globaldefs.h>

struct Struct_ov014_02187228 { Struct_ov014_02187228* next; };

extern "C" int func_02080468(void* a, int b);

// USA: func_ov014_02187228
extern "C" ARM void func_ov014_02187228(char* obj, Struct_ov014_02187228* target) {
    *(Struct_ov014_02187228**)(obj + 0xbc) = *(Struct_ov014_02187228**)(obj + 0xb8);
    *(short*)(obj + 0x176) = 0x1b;
    void* src = *(void**)(obj + 0xc0);
    if (src != 0) {
        *(short*)(obj + 0x176) = (short)func_02080468(src, 5);
    }
    if (target == 0) return;

    Struct_ov014_02187228* node = *(Struct_ov014_02187228**)(obj + 0xb8);
    Struct_ov014_02187228* var2 = node;
    short idx = 0;
    Struct_ov014_02187228* head = *(Struct_ov014_02187228**)(obj + 0xb8);
    while (node != 0) {
        if (idx % 16 == 0) { var2 = node; idx = 0; }
        if (node == target) break;
        idx = (short)(idx + 1);
        node = node->next;
    }
    if (node == 0) { idx = 0; var2 = head; }
    *(short*)(obj + 0x176) = *(short*)(obj + 0x176) + idx;
    *(Struct_ov014_02187228**)(obj + 0xbc) = var2;
}
