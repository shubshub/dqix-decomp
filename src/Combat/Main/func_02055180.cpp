#include <globaldefs.h>

struct Struct_020546c8;

extern "C" void* func_02055080(struct Struct_020546c8* obj);
extern "C" void* func_02055090(struct Struct_020546c8* obj);
extern "C" void* func_020550a8(struct Struct_020546c8* p);
extern "C" void* func_020550c0(struct Struct_020546c8* obj);
extern "C" void* func_020550d8(struct Struct_020546c8* obj);
extern "C" void* func_02055120(struct Struct_020546c8* obj);
extern "C" void* func_02055138(struct Struct_020546c8* arg0);
extern "C" void* func_02055150(struct Struct_020546c8* arg0);
extern "C" void* func_02055168(struct Struct_020546c8* arg0);
extern "C" void func_020546c8(struct Struct_020546c8* sl);

struct Struct_020546c8 {
    void* alloc;
    void* unknown_4_;
};

struct Struct_02055180 {
    void* a[9];
};

struct Struct_02055180_2 {
    void* a[2];
};

struct Struct_02055180_3 {
    void* a[1];
};

struct Struct_02055180_4 {
    void* a[4];
};

struct Struct_02055180_5 {
    void* a[3];
    void* b[3];
    void* c[3];
};

#define RELOCATE(slot) (slot) = (char*)sl->unknown_4_ + (int)(slot)

// USA: func_02055180
extern "C" ARM int func_02055180(struct Struct_020546c8* sl, void* arg1, void* arg2, void* arg3) {
    if (arg1 == 0) {
        return 0;
    }
    if (arg2 == 0) {
        return 0;
    }
    if (arg3 == 0) {
        return 0;
    }

    sl->alloc    = arg1;
    sl->unknown_4_ = arg2;

    struct Struct_02055180* var0 = (struct Struct_02055180*)func_02055080(sl);
    if (var0 == 0) {
        return 0;
    }
    for (int i = 0; i < 9; i++) {
        RELOCATE(var0->a[i]);
    }

    struct Struct_02055180_2* g2 = (struct Struct_02055180_2*)func_02055090(sl);
    if (g2 == 0) {
        return 0;
    }
    RELOCATE(g2->a[0]);
    RELOCATE(g2->a[1]);

    struct Struct_02055180_5* var3 = (struct Struct_02055180_5*)func_020550a8(sl);
    if (var3 == 0) {
        return 0;
    }
    for (int i = 0; i < 3; i++) {
        RELOCATE(var3->a[i]);
        RELOCATE(var3->b[i]);
        RELOCATE(var3->c[i]);
    }

    struct Struct_02055180_3* var5 = (struct Struct_02055180_3*)func_020550c0(sl);
    if (var5 == 0) {
        return 0;
    }
    RELOCATE(var5->a[0]);

    struct Struct_02055180_4* var6 = (struct Struct_02055180_4*)func_020550d8(sl);
    if (var6 == 0) {
        return 0;
    }
    for (int i = 0; i < 4; i++) {
        RELOCATE(var6->a[i]);
    }

    struct Struct_02055180_2* var8 = (struct Struct_02055180_2*)func_02055120(sl);
    if (var8 == 0) {
        return 0;
    }
    for (int i = 0; i < 2; i++) {
        RELOCATE(var8->a[i]);
    }

    struct Struct_02055180_2* g6 = (struct Struct_02055180_2*)func_02055138(sl);
    if (g6 == 0) {
        return 0;
    }
    for (int i = 0; i < 2; i++) {
        RELOCATE(g6->a[i]);
    }

    struct Struct_02055180_2* var12 = (struct Struct_02055180_2*)func_02055150(sl);
    if (var12 == 0) {
        return 0;
    }
    RELOCATE(var12->a[1]);

    struct Struct_02055180_4* var13 = (struct Struct_02055180_4*)func_02055168(sl);
    if (var13 == 0) {
        return 0;
    }
    for (int i = 0; i < 4; i++) {
        RELOCATE(var13->a[i]);
    }

    func_020546c8(sl);
    return 1;
}
