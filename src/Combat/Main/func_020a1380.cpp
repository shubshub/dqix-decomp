#include <globaldefs.h>

struct Struct_020a1180 {
    unsigned int f0 : 9;   // bits 0-8
    unsigned int f1 : 9;   // bits 9-17
    unsigned int f2 : 9;   // bits 18-26
    unsigned int f3 : 3;   // bits 27-29
    unsigned int f4 : 2;   // bits 30-31
    int next;   // 0x4
    int prev;   // 0x8
};

// USA: func_020a1380
extern "C" ARM void func_020a1380(struct Struct_020a1180* rec) {
    rec->f0 = 0;
    rec->f1 = 0;
    rec->f2 = 0;
    rec->f3 = 0;
    rec->f4 = 0;
    rec->next = 0;
    rec->prev = 0;
}
