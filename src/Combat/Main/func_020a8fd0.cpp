#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

struct Struct_020a8e9c;
struct Struct_020a8f70;
struct Struct_020a8fd0_2;
struct Struct_020a8e80;

struct Struct_020a9304 { unsigned char v[24]; };
struct Struct_020a9304_2 { unsigned short v[6]; };

struct Struct_020a8fd0_3 {
    unsigned short a;
    unsigned short b;
    unsigned short c;
    unsigned short d;
    unsigned short e;
    unsigned short f;
    unsigned int g;
    struct Struct_020a9304 arr1;
    unsigned int h;
    unsigned int i;
    unsigned char j;
    unsigned char k;
    struct Struct_020a9304_2 arr2;
};

typedef void (*Type_020a8f70)(void*, void*);
typedef int (*Type_020a8fd0)(void*);

extern "C" int func_020a8f60(struct Struct_020a8e9c* obj);
extern "C" int func_020a8f70(struct Struct_020a8f70* obj, Type_020a8f70 fn);
extern "C" void* func_020a9288(struct Struct_020a8fd0_2* obj, int key, Type_020a8fd0 arg2);
extern "C" struct Struct_020a8fd0_3* func_020a9304(struct Struct_020a8fd0_3* dst, struct Struct_020a8fd0_3* src);
extern "C" unsigned short func_020a8e80(struct Struct_020a8e80* obj);

struct Struct_020a8fd0 {
    unsigned int count : 12;
    unsigned int count2 : 19;
    unsigned int flag : 1;
    struct Struct_020a8fd0_3* elems;
    void* extra;
};

static inline void inline_020a8fd0(struct Struct_020a8fd0_3* a, struct Struct_020a8fd0_3* b) {
    struct Struct_020a8fd0_3 tmp = *a;
    func_020a9304(a, b);
    func_020a9304(b, &tmp);
}

// USA: func_020a8fd0
extern "C" ARM void func_020a8fd0(struct Struct_020a8fd0* obj, SafeAllocator* alloc, void* file, unsigned int size, short* ids, short count) {
    struct Struct_020a8fd0 src;
    int hi;
    int total;
    short* p;
    int n;
    int i;
    int num;
    struct Struct_020a8fd0_3* dst;
    int k;
    int j;
    struct Struct_020a8fd0_3* prev;
    struct Struct_020a8fd0_3* e;
    int var12;
    struct Struct_020a8fd0_3* f;
    int last;
    int m;
    int lo;
    if (alloc == 0 || file == 0 || size == 0 || ids == 0 || count <= 0) return;
    memset(obj, 0, sizeof(struct Struct_020a8fd0));
    memset(&src, 0, sizeof(struct Struct_020a8fd0));
    if (file != 0) {
        memcpy(&src, file, 4);
        src.elems = (struct Struct_020a8fd0_3*)((char*)file + 4);
        src.extra = (char*)file + (func_020a8f60((struct Struct_020a8e9c*)&src) + 4);
        if (!src.flag) {
            func_020a8f70((struct Struct_020a8f70*)&src, 0);
            src.flag = 1;
            ((struct Struct_020a8fd0*)file)->flag = 1;
        }
    }
    n = 0;
    p = ids;
    num = count;
    for (i = 0; i < num; i++, p++) {
        if (func_020a9288((struct Struct_020a8fd0_2*)&src, *p, (Type_020a8fd0)func_020a8e80) != 0) {
            n++;
        }
    }
    obj->elems = (struct Struct_020a8fd0_3*)alloc->Allocate(n * sizeof(struct Struct_020a8fd0_3));
    if (obj->elems != 0) {
        obj->count = n;
        p = ids;
        dst = obj->elems;
        for (k = 0; k < num; k++, p++) {
            void* found = func_020a9288((struct Struct_020a8fd0_2*)&src, *p, (Type_020a8fd0)func_020a8e80);
            if (found != 0) {
                memcpy(dst, found, sizeof(struct Struct_020a8fd0_3));
                dst++;
            }
        }
    }
    if (n < 2 || obj == 0) return;
    total = obj->count;
    if (obj->elems == 0 || total == 0) return;
    lo = 0;
    hi = total - 1;
    for (;;) {
        last = -1;
        e = obj->elems + lo;
        for (j = lo; j < hi; j++) {
            if (e[0].a > e[1].a) {
                last = j;
                inline_020a8fd0(&e[0], &e[1]);
            }
            e++;
        }
        if (last == -1) break;
        hi = last;
        var12 = -1;
        f = obj->elems + hi;
        for (m = hi; m > lo; m--) {
            prev = f - 1;
            if (prev->a > f->a) {
                var12 = m;
                struct Struct_020a8fd0_3 tmp = *f;
                func_020a9304(f, prev);
                func_020a9304(prev, &tmp);
            }
            f = prev;
        }
        if (var12 == -1) break;
        lo = var12;
    }
}
