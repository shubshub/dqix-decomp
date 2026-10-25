#include <globaldefs.h>
#include "Resource/KeyTable.h"

int KeyTable_EndLoad(struct Struct020dfc40* table);
void KeyTable_Reset(struct Struct020dfc40* p);
int ReplaceBinExtensionWithNat020e05f8(char*, char const*, short);
extern "C" int func_020dfd40(void* self, char* a, char* b);

// USA: func_020dfc84
extern "C" ARM int func_020dfc84(void* self, void* allocator, char* fmt, char* ext, short n, short singleKey) {
    char buf[0x60];
    struct Struct020dfc40* p;

    p = (struct Struct020dfc40*)self;
    KeyTable_EndLoad((struct Struct020dfc40*)self);
    KeyTable_Reset(p);
    p->allocator = allocator;
    p->singleKey = singleKey;
    p->loadStep = KeyTableLoadStep_Queue;

    if (arg4 >= 0) {
        func_020e05f8(var0 + 0x20, arg2, arg4);
        if (arg3 != 0) {
            func_020e05f8(var0, arg3, arg4);
            func_020dfd40(arg0, var0 + 0x20, var0);
        } else {
            func_020dfd40(arg0, var0 + 0x20, 0);
        }
        return;
    }

    if (arg3 != 0) {
        func_020dfd40(arg0, arg2, arg3);
    } else {
        func_020dfd40(arg0, arg2, 0);
    }
}
