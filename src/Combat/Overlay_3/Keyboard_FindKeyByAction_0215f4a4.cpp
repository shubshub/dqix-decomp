#include <globaldefs.h>

struct Elem0215f4a4 {
    char pad0[0xd];
    unsigned char key;
    char pad1[0x14 - 0xd - 1];
};

struct Header0215f4a4 {
    struct Elem0215f4a4* base;
    char pad4[2];
    short count;
};

struct Obj0215f4a4 {
    char pad0[4];
    struct Header0215f4a4* header;
};

// USA: func_ov003_0215f4a4  (semantic: FindElementByFieldD_0215f4a4)
extern "C" ARM struct Elem0215f4a4* func_ov003_0215f4a4(struct Obj0215f4a4* obj, int key) {
    struct Header0215f4a4* h = obj->header;
    short count = h->count;
    struct Elem0215f4a4* e = h->base;
    short i = 0;
    while (i < count) {
        if (e->key == key) return e;
        i = (short)(i + 1);
        e = (struct Elem0215f4a4*)((char*)e + 0x14);
    }
    return 0;
}
