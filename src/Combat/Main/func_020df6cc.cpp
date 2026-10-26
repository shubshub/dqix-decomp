#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_020def98_2 {
    void *name;
    void *desc;
    unsigned char data[0x20 - 8];
};

struct Struct_020df6cc {
    unsigned short counter : 15;
    unsigned short flag : 1;
};

// USA: func_020df6cc
extern "C" ARM int func_020df6cc(void *a, Struct_020def98_2 *b, int unused, Struct_020def98_2 *d)
{
    void *var0 = b->desc;
    void *savedName = b->name;
    memcpy(b, d, sizeof(Struct_020def98_2));
    b->desc = var0;
    b->name = savedName;

    {
        void *var2 = b->desc;
        void *var3 = d->desc;
        if (var2 != NULL) {
            if (var3 == NULL) {
                *(char*)var2 = 0;
            } else {
                strcpy((char*)var2, (char*)var3);
            }
        }
    }

    if (b->name != NULL && d->name != NULL) {
        memcpy(b->name, d->name, 0x20);
        ((Struct_020df6cc*)((char*)a + 2))->counter++;
    }

    return 1;
}
