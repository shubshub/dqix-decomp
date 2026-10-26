#include <globaldefs.h>
#include "std_library_functions.h"

struct SearchStruct0202c1a4;

extern "C" void *LinkSession_GetInstance(int n);
extern "C" int LinkSession_IsActive(int *obj);
extern "C" signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4 *obj);
extern "C" void func_020962f4(void *g, struct Struct_020961b0 e);
extern "C" void func_0209609c(int unused, unsigned char *arr, int index);

struct Struct_020961b0 {
    unsigned int a : 9;
    unsigned int b : 1;
    unsigned int c : 1;
    unsigned int d : 3;
    unsigned int e : 2;
    unsigned int f : 1;
    unsigned int g : 15;
    unsigned int w4;
    unsigned int w8;
    unsigned int unknown_c_;
};

struct Struct_020961b0_2 {
    char pad0[2];
    unsigned short id : 9;
    unsigned short unknown_3_1_ : 1;
    unsigned short unknown_3_2_ : 3;
    unsigned short unknown_3_5_ : 1;
    unsigned short tail : 2;
    char pad4[8];
    struct Struct_020961b0_2 *next;
};

// USA: func_020961b0
extern "C" ARM int func_020961b0(void *g, int id) {
    int n = *(unsigned char *)g;
    if (n >= 8) {
        return 0;
    }
    void *p = LinkSession_GetInstance(n);
    struct Struct_020961b0_2 *node;
    for (node = (struct Struct_020961b0_2 *)*(void **)((char *)g + 0xa0); node != 0; node = node->next) {
        if (node->id != id) {
            continue;
        }
        struct Struct_020961b0 e;
        memset(&e, 0, sizeof(e));
        e.a = node->id;
        e.c = node->unknown_3_1_;
        e.f = node->unknown_3_5_;
        e.d = 1;
        if (LinkSession_IsActive((int *)p) && LinkSession_GetOwnSlot((struct SearchStruct0202c1a4 *)p)) {
            e.b = 1;
        } else {
            e.b = 0;
        }
        func_020962f4(g, e);
        func_0209609c((int)g, (unsigned char *)g + 0xa8 + 0x400, id);
        break;
    }
    if (node == 0) {
        return 0;
    }
    return 1;
}
