#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

struct Struct_020df850;
struct Struct_020dfa68;

struct Struct_020df850_2 {
    short a;
    short b;
    int c;
};

struct Struct_020df850_3 {
    unsigned short count;
    unsigned short pad2;
    unsigned int unknown_4_0_ : 15;
    unsigned int unknown_5_7_ : 1;
    unsigned int unknown_6_0_ : 16;
    void *elements;
    void *end;
};

struct Struct_020df850_4;

typedef int (*Type_020df850)(struct Struct_020df850 *, struct Struct_020dfa68 *);

extern "C" int func_020dfbc0(struct Struct_020df850_4 *);
extern "C" int func_020df77c(struct Struct_020df850 *, struct Struct_020dfa68 *);
extern "C" int func_020dfa68(struct Struct_020df850 *, Type_020df850);
extern "C" int func_020dfabc(struct Struct_020df850_3 *, struct Struct_020df850_3 *, char *, Type_020df850);

struct Struct_020df850_5;
typedef int (*Type_020df850_2)(void *);
extern "C" void *func_020dfb48(struct Struct_020df850_5 *, int, Type_020df850_2);

extern "C" char *func_020da150(SafeAllocator *, const char *);
extern "C" short func_020df774(short *);

// USA: func_020df850
extern "C" ARM int func_020df850(struct Struct_020df850_3 *self, SafeAllocator *alloc,
                                 struct Struct_020df850_3 *src, void *unused, short mode) {
    struct Struct_020df850_3 local;
    char flag;
    struct Struct_020df850_2 *elem;
    struct Struct_020df850_2 *dst;
    struct Struct_020df850_2 *var4;
    struct Struct_020df850_2 *var5;
    int size;
    int mask;
    int n;
    int i;

    if (alloc == NULL || src == NULL || unused == NULL) return 0;
    if (mode < 0) {
        if (alloc != NULL && src != NULL) {
            memcpy(self, src, 8);
            size = func_020dfbc0((struct Struct_020df850_4 *)self);
            mask = self->unknown_4_0_;
            if (size)
                self->elements = alloc->Allocate(size);
            else
                self->elements = NULL;
            self->end = mask ? alloc->Allocate(mask) : NULL;
            if (self->elements != NULL) memcpy(self->elements, (char *)src + 8, size);
            if (self->end != NULL)
                memcpy(self->end, (char *)src + (func_020dfbc0((struct Struct_020df850_4 *)self) + 8), mask);
            if ((Type_020df850)func_020df77c) func_020dfa68((struct Struct_020df850 *)self, (Type_020df850)func_020df77c);
            self->unknown_5_7_ = 1;
        }
    } else {
        memset(&local, 0, 0x10);
        func_020dfabc(&local, src, &flag, func_020df77c);
        elem = (struct Struct_020df850_2 *)func_020dfb48(
            (struct Struct_020df850_5 *)&local, mode, (Type_020df850_2)func_020df774);
        if (elem != NULL) {
            memset(self, 0, 0x10);
            self->count = 1;
            self->pad2 = elem->b;
            self->elements = alloc->Allocate(func_020dfbc0((struct Struct_020df850_4 *)self));
            if (self->elements != NULL) {
                memcpy(self->elements, elem, 8);
                dst = (struct Struct_020df850_2 *)self->elements;
                n = dst->b;
                if (dst->b == 0 || dst->c == -1 || elem->c == 0) {
                    dst->b = 0;
                    ((struct Struct_020df850_2 *)self->elements)->c = 0;
                } else {
                    dst->c = (int)(dst + 1);
                    var4 = (struct Struct_020df850_2 *)elem->c;
                    var5 = (struct Struct_020df850_2 *)((struct Struct_020df850_2 *)self->elements)->c;
                    memcpy(var5, var4, n * 8);
                    for (i = 0; i < n; i++, var5++, var4++) {
                        var5->c = (int)func_020da150(alloc, (const char *)var4->c);
                    }
                }
            }
        }
    }
    return 1;
}
