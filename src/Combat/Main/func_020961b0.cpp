#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_0202c1a4;

extern "C" void *LinkSession_GetInstance(int n);
int LinkSession_IsActive(int *obj);
signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4 *obj);
extern "C" void func_020962f4(void *g, struct Entry020961b0 e);
void SetBitInArrayGuarded_0209609c(int unused, unsigned char *arr, int index);

struct Struct_020961b0 {
    unsigned int unknown_0_0_ : 9;
    unsigned int unknown_1_1_ : 1;
    unsigned int unknown_1_2_ : 1;
    unsigned int unknown_1_3_ : 3;
    unsigned int unknown_1_6_ : 2;
    unsigned int unknown_2_0_ : 1;
    unsigned int unknown_2_1_ : 15;
    unsigned int unknown_4_;
    unsigned int unknown_8_;
    unsigned int unknown_c_;
};

struct Struct_020961b0_2 {
    char unknown_0_[2];
    unsigned short unknown_2_0_ : 9;
    unsigned short unknown_3_1_ : 1;
    unsigned short unknown_3_2_ : 3;
    unsigned short unknown_3_5_ : 1;
    unsigned short unknown_3_6_ : 2;
    char unknown_4_[8];
    struct Struct_020961b0_2 *unknown_c_;
};

// USA: func_020961b0
extern "C" ARM int func_020961b0(void *arg0, int arg1) {
    int var0 = *(unsigned char *)arg0;
    if (var0 >= 8) {
        return 0;
    }
    void *p = LinkSession_GetInstance(n);
    struct Node020961b0 *node;
    for (node = (struct Node020961b0 *)*(void **)((char *)g + 0xa0); node != 0; node = node->next) {
        if (node->id != id) {
            continue;
        }
        struct Entry020961b0 e;
        memset(&e, 0, sizeof(e));
        e.a = node->id;
        e.c = node->f9;
        e.f = node->f13;
        e.d = 1;
        if (LinkSession_IsActive((int *)p) && LinkSession_GetOwnSlot((struct SearchStruct0202c1a4 *)p)) {
            e.b = 1;
        } else {
            var3.unknown_1_1_ = 0;
        }
        func_020962f4(arg0, var3);
        func_0209609c((int)arg0, (unsigned char *)arg0 + 0xa8 + 0x400, arg1);
        break;
    }
    if (var2 == 0) {
        return 0;
    }
    return 1;
}
