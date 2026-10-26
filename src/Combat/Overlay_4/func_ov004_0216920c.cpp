#include <globaldefs.h>

struct Struct_ov004_0216920c_7;

class Struct_ov004_0216920c_8 {
public:
    char pad04[0x8];
    unsigned char flags;
    char pad0d[0x13];
    void* f20;
    char pad24[0x19];
    unsigned char unknown_3d_;
    char unknown_3e_[0x1e];
    short unknown_5c_;
    short unknown_5e_;

    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void inline_ov004_0216920c_37();
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
    virtual void inline_ov004_0216920c_49(int v);
    virtual void v50();
    virtual void inline_ov004_0216920c_51(int v);
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
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void inline_ov004_0216920c_27();
    virtual void vdc();
    virtual void inline_ov004_0216920c_29(int v);
};

struct Struct_ov004_0216920c {
    char unknown_0_[6];
    char name[11];
    unsigned char unknown_11_;
    unsigned short value : 14;
    unsigned short active : 1;
    char unknown_14_[0x2c - 0x14];
};

struct Struct_ov004_0216920c_2 {
    unsigned char count;
    char unknown_1_[3];
    struct Struct_ov004_0216920c entries[16];
};

struct Struct_ov004_0216920c_3 { char pad[0x30]; };

struct Struct_ov004_0216920c_4 {
#if defined(jpn)
    char unknown_0_[0x10];
#else
    struct Struct_ov004_0216920c_3 slots[8];
    char unknown_180_[0x10];
#endif
    struct Struct_ov004_0216920c_2* table;
    char unknown_194_[4];
    unsigned char unknown_198_;
};

struct Struct_ov004_0216920c_5 {
    char pad[0x1b4];
    int unknown_1b4_;
    unsigned int unknown_1b8_;
    char unknown_1bc_[2];
    short unknown_1be_;
};

extern "C" Struct_ov004_0216920c_8* func_ov023_021f6524(void* ctx, int value);
extern "C" void func_ov023_021f6600(void*, int, int);
extern "C" Struct_ov004_0216920c_8* func_ov004_02168a6c(void* a, int id);
extern "C" Struct_ov004_0216920c_8* func_ov004_02168a38(void* a, int id);
extern "C" void Font_DecodeText(void*, void*, int);
extern "C" int func_ov023_021f9b30(struct Struct_ov004_0216920c_7* self, unsigned short val, unsigned int x, unsigned int y);
extern "C" void func_ov023_021f65d4(void*, int, int);
extern "C" void func_ov023_021f9da0(void*, unsigned char);
extern "C" void func_ov004_02169b4c(void*);
extern "C" void func_ov023_021f6630(int, int, short, short);

extern struct Struct_ov004_0216920c_4* data_ov004_02171030;

#if defined(jpn)
extern "C" Struct_ov004_0216920c_8* func_ov004_02168f08(void*, int);
extern "C" void func_ov004_02168ed8(void*, int, int);
extern "C" void func_ov004_02168eac(void*, int, int);
struct Struct_ov004_0216920c_6 {
    char unknown_0_[0x104];
    short page;
    short column;
};
extern "C" Struct_ov004_0216920c_6* func_ov004_02168fa4(void*, int);
extern "C" void func_ov023_021f809c(void*, void*);
#define func_ov023_021f6524 func_ov004_02168f08
#define func_ov023_021f6600 func_ov004_02168ed8
#define func_ov023_021f65d4 func_ov004_02168eac
#endif

// USA: func_ov004_0216920c
extern "C" ARM int func_ov004_0216920c(struct Struct_ov004_0216920c_5* scene) {
    struct Struct_ov004_0216920c_2* table = data_ov004_02171030->table;
    if (!table) return 0;
    Struct_ov004_0216920c_8* node = func_ov023_021f6524(scene, 0x64);
    short page = node->unknown_5c_;
    int hidden = 0;
    short col = node->unknown_5e_;
    func_ov023_021f6600(scene, 2, 8);
    int i;
    for (i = 0; i < 8; i++) {
        Struct_ov004_0216920c_8* a = func_ov004_02168a6c(scene, i + 0xc8);
        Struct_ov004_0216920c_8* b = func_ov004_02168a6c(scene, i + 0xd8);
        Struct_ov004_0216920c_8* c = func_ov004_02168a38(scene, i + 0xd0);
        Struct_ov004_0216920c_8* d = func_ov004_02168a38(scene, i + 0xe0);
        struct Struct_ov004_0216920c* e = &table->entries[page * 8 + i];
        if (e->active) {
#if defined(jpn)
            a->f20 = e->name;
#else
            struct Struct_ov004_0216920c_3* slot = &data_ov004_02171030->slots[i];
            Font_DecodeText(e->name, slot, 1);
            a->f20 = slot;
#endif
            c->inline_ov004_0216920c_29(e->value);
            d->inline_ov004_0216920c_29(e->unknown_11_);
            d->unknown_3d_ = 1;
            a->flags &= ~8;
            b->flags &= ~8;
            c->flags &= ~8;
            d->flags &= ~8;
            func_ov023_021f9b30((struct Struct_ov004_0216920c_7*)node, (unsigned short)(i + 0xc8), (unsigned short)i, 0);
            a->inline_ov004_0216920c_49(3);
        } else {
            a->flags |= 8;
            b->flags |= 8;
            c->flags |= 8;
            d->flags |= 8;
            func_ov023_021f9b30((struct Struct_ov004_0216920c_7*)node, 0, (unsigned short)i, 0);
            a->inline_ov004_0216920c_49(3);
            hidden++;
        }
    }
    if (hidden == 8) {
        func_ov023_021f65d4(scene, 2, 8);
        func_ov023_021f9da0(node, 0);
    }
    func_ov023_021f65d4(scene, 0x14, 4);
    data_ov004_02171030->unknown_198_ = 0;
    func_ov004_02169b4c(scene);
    node->inline_ov004_0216920c_51(3);
    Struct_ov004_0216920c_8* first = func_ov004_02168a6c(scene, 0xc8);
    first->v44(0xd);
    first->v7c(0xd);
#if defined(jpn)
    Struct_ov004_0216920c_6* dispatch = func_ov004_02168fa4(scene, 0x14);
    if (dispatch) {
        dispatch->page = page;
        dispatch->column = col;
        func_ov023_021f809c(dispatch, scene);
    }
#else
    func_ov023_021f6630((int)scene, 0x14, page, col);
#endif
    if (scene->unknown_1b4_ != 0 && scene->unknown_1b8_ > 0xf) {
        scene->unknown_1be_ = 0xf;
    }
    return 0;
}
