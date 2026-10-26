#include <globaldefs.h>
#include "GameState/GameState.h"
#if defined(jpn)
#define func_ov023_021f6524 func_ov004_02168f08
#define func_ov023_021f6600 func_ov004_02168ed8
#define func_ov023_021f6680 func_ov004_02168fa4
#endif

struct Struct_ov004_02153e20;
struct Struct_ov004_021700e0 { int a, b, c; };

class Struct_ov004_02169658_3 {
public:
    char pad04[0x8];
    unsigned char flags;
    char pad0d[0x13];
    void* f20;

    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void Apply(struct Struct_ov004_021700e0* t);
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44(int v);
    virtual void v48();
    virtual void inline_ov004_02169658_31(int v);
    virtual void v50();
    virtual void inline_ov004_02169658(int v);
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c(int v);
};

struct Struct_ov004_02169658 {
    #if defined(jpn)
 char pad[0x18];
#else
 char pad[0x198];
#endif
    unsigned char unknown_198_;
};

struct Struct_ov004_02169658_2 {
    char pad[0x1be];
    short unknown_1be_;
};

extern "C" unsigned char* func_02053c6c(unsigned char* obj);
extern "C" Struct_ov004_02169658_3* func_ov023_021f6524(void* ctx, int value);
extern "C" Struct_ov004_02169658_3* func_ov004_02168a6c(void* a, int id);
extern "C" Struct_ov004_02169658_3* func_ov004_02168a38(void* a, int id);
extern "C" Struct_ov004_02169658_3* func_ov004_02168ad4(void* a, int id);
extern "C" int func_ov023_021f9b30(struct Struct_ov004_02153e20* self, unsigned short val, unsigned int x, unsigned int y);
#if defined(jpn)
extern "C" void func_ov004_02168ed8(void* obj, int id, int mask);
#else
extern "C" void func_ov023_021f6600(void* obj, int id, int mask);
#endif
extern "C" void func_ov023_021f9ba8(void* obj, int v);
#if defined(jpn)
extern "C" void* func_ov004_02168fa4(void*, int);
extern "C" void func_ov023_021f809c(void*, void*);
#else
extern "C" int func_ov023_021f6680(void* obj, int id);
#endif
extern "C" void func_ov004_02169b4c(void* obj);

extern struct Struct_ov004_021700e0 data_ov004_021700e0;
extern struct Struct_ov004_02169658* data_ov004_02171030;

// USA: func_ov004_02169658
extern "C" ARM int func_ov004_02169658(struct Struct_ov004_02169658_2* scene) {
    unsigned char* base = func_02053c6c((unsigned char*)GameState::GetInstance()->GetLeader()) + 0x3c;
    Struct_ov004_02169658_3* grid = func_ov023_021f6524(scene, 0x64);
    int i;
    for (i = 0; i < 8; i++) {
        Struct_ov004_02169658_3* a = func_ov004_02168a6c(scene, i + 0xc8);
        Struct_ov004_02169658_3* b = func_ov004_02168a6c(scene, i + 0xd8);
        Struct_ov004_02169658_3* c = func_ov004_02168a38(scene, i + 0xd0);
        Struct_ov004_02169658_3* d = func_ov004_02168a38(scene, i + 0xe0);
        if (i == 0) {
            a->f20 = base;
            a->flags &= ~8;
            func_ov023_021f9b30((struct Struct_ov004_02153e20*)grid, (unsigned short)(i + 0xc8), (unsigned short)i, 0);
            a->inline_ov004_02169658_31(0);
        } else {
            a->flags |= 8;
            func_ov023_021f9b30((struct Struct_ov004_02153e20*)grid, 0, (unsigned short)i, 0);
            a->inline_ov004_02169658_31(0);
        }
        b->flags |= 8;
        c->flags |= 8;
        d->flags |= 8;
    }
    func_ov023_021f6600(scene, 2, 8);
    func_ov023_021f9ba8(grid, 0);
    func_ov023_021f6600(scene, 0x14, 4);
#if defined(jpn)
    void* selected = func_ov004_02168fa4(scene, 0x14);
    if (selected) func_ov023_021f809c(selected, scene);
#else
    func_ov023_021f6680(scene, 0x14);
#endif
    grid->inline_ov004_02169658(0);
    Struct_ov004_02169658_3* first = func_ov004_02168a6c(scene, 0xc8);
    first->v44(0);
    first->v7c(0);
    Struct_ov004_02169658_3* n = func_ov004_02168ad4(scene, 2);
    struct Struct_ov004_021700e0 t = data_ov004_021700e0;
    n->Apply(&t);
    data_ov004_02171030->unknown_198_ = 1;
    func_ov004_02169b4c(scene);
    scene->unknown_1be_ = 0;
    return 0;
}
