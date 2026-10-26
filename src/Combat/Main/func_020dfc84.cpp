#include <globaldefs.h>
#include "Resource/KeyTable.h"

extern "C" int KeyTable_EndLoad(struct Struct020dfc40* table);
extern "C" void KeyTable_Reset(struct Struct020dfc40* p);
extern "C" int func_020e05f8(char*, char const*, short);
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

    if (n >= 0) {
        func_020e05f8(buf + 0x20, fmt, n);
        if (ext != 0) {
            func_020e05f8(buf, ext, n);
            func_020dfd40(self, buf + 0x20, buf);
        } else {
            func_020dfd40(self, buf + 0x20, 0);
        }
        return;
    }

    if (ext != 0) {
        func_020dfd40(self, fmt, ext);
    } else {
        func_020dfd40(self, fmt, 0);
    }
}
