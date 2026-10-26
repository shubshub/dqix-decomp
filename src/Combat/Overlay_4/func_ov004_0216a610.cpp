#include <globaldefs.h>
#if defined(jpn)
#define func_ov023_021f6524 func_ov004_02168f08
extern "C" void* func_ov004_02168fa4(void*, int);
extern "C" void func_ov023_021f809c(void*, void*);
#endif

struct Struct_ov004_02153e20 {
    char pad[0x20];
    short* cells;
    unsigned short width;
    unsigned short height;
    char pad28[0x34];
    short page;
    short unknown_5e_;
};

class Struct_ov004_0216a610_4 {
public:
    virtual void v00(); virtual void inline_ov004_0216a610_32(); virtual void inline_ov004_0216a610_33(); virtual void inline_ov004_0216a610_34();
    virtual void v04(); virtual void inline_ov004_0216a610_36(); virtual void inline_ov004_0216a610_37(); virtual void inline_ov004_0216a610_38();
    virtual void v08(); virtual void inline_ov004_0216a610_40(); virtual void v10(); virtual void inline_ov004_0216a610_42();
    virtual void inline_ov004_0216a610_43(); virtual void inline_ov004_0216a610_44(); virtual void v14(); virtual void inline_ov004_0216a610_46();
    virtual void inline_ov004_0216a610_47(); virtual void inline_ov004_0216a610_48(); virtual void v18(); virtual void inline_ov004_0216a610_50();
    virtual void v20(); virtual void inline_ov004_0216a610_52(); virtual void inline_ov004_0216a610_53(); virtual void inline_ov004_0216a610_54();
    virtual void v24(); virtual void inline_ov004_0216a610_56(); virtual void inline_ov004_0216a610_57(); virtual void inline_ov004_0216a610();
    virtual void v28(); virtual void inline_ov004_0216a610_3(); virtual void v30(); virtual void inline_ov004_0216a610_5();
    virtual void inline_ov004_0216a610_6(); virtual void inline_ov004_0216a610_7(); virtual void v34(); virtual void inline_ov004_0216a610_9();
    virtual void inline_ov004_0216a610_10(); virtual void inline_ov004_0216a610_11(); virtual void v38(); virtual void inline_ov004_0216a610_13();
    virtual void v40(); virtual void inline_ov004_0216a610_15(); virtual void inline_ov004_0216a610_16(); virtual void inline_ov004_0216a610_17();
    virtual void v44(); virtual void inline_ov004_0216a610_19(); virtual void inline_ov004_0216a610_20(); virtual void inline_ov004_0216a610_21();
    virtual void v48(); virtual void inline_ov004_0216a610_23(); virtual void v50(); virtual void inline_ov004_0216a610_25();
    virtual void inline_ov004_0216a610_26(); virtual void inline_ov004_0216a610_27(); virtual void v54(); virtual void inline_ov004_0216a610_29();
    virtual void inline_ov004_0216a610_30(int value);

    char pad4[8];
    unsigned char flags;
    char unknown_d_[0x13];
    char* text;
};

struct Struct_ov004_0216a610 {
    char pad0[6];
    char name[0xb];
    unsigned char level;
    unsigned short id : 14;
    unsigned short used : 1;
    unsigned short unknown_13_7_ : 1;
    char unknown_14_[0x18];
};

struct Struct_ov004_0216a610_2 {
    unsigned char count;
    char pad1[3];
    struct Struct_ov004_0216a610 entries[1];
};

struct Struct_ov004_0216a610_3 {
#if !defined(jpn)
    char names[8][0x30];
#endif
    char unknown_180_[0x10];
    struct Struct_ov004_0216a610_2* table;
};

extern "C" struct Struct_ov004_02153e20* func_ov023_021f6524(void* ctx, int value);
extern "C" Struct_ov004_0216a610_4* func_ov004_02168a6c(void* a, int id);
extern "C" Struct_ov004_0216a610_4* func_ov004_02168a38(void* a, int id);
extern "C" void Font_DecodeText(void* src, void* dst, int flag);
extern "C" int func_ov023_021f9b30(struct Struct_ov004_02153e20* self, unsigned short val, unsigned int x, unsigned int y);
extern "C" void func_ov023_021f6630(int a, int b, short c, short d);

extern struct Struct_ov004_0216a610_3* data_ov004_02171030;

// USA: func_ov004_0216a610
extern "C" ARM int func_ov004_0216a610(void* a) {
    struct Struct_ov004_0216a610_2* table = data_ov004_02171030->table;
    if (table == 0) {
        return 0;
    }
    struct Struct_ov004_02153e20* grid = func_ov023_021f6524(a, 0x64);
    short page = grid->page;
    short var3 = grid->unknown_5e_;
    int i;
    for (i = 0; i < 8; i++) {
        Struct_ov004_0216a610_4* label = func_ov004_02168a6c(a, i + 0xc8);
        Struct_ov004_0216a610_4* var6 = func_ov004_02168a6c(a, i + 0xd8);
        Struct_ov004_0216a610_4* var7 = func_ov004_02168a38(a, i + 0xd0);
        Struct_ov004_0216a610_4* var8 = func_ov004_02168a38(a, i + 0xe0);
        struct Struct_ov004_0216a610* e = &table->entries[i + page * 8];
        if (e->used) {
#if defined(jpn)
            label->text = e->name;
#else
            char* name = data_ov004_02171030->names[i];
            Font_DecodeText(e->name, name, 1);
            label->text = name;
#endif
            var7->inline_ov004_0216a610_30(e->id);
            var8->inline_ov004_0216a610_30(e->level);
            label->flags &= ~8;
            var6->flags &= ~8;
            var7->flags &= ~8;
            var8->flags &= ~8;
            func_ov023_021f9b30(grid, i + 0xc8, (unsigned short)i, 0);
        } else {
            label->flags |= 8;
            var6->flags |= 8;
            var7->flags |= 8;
            var8->flags |= 8;
            func_ov023_021f9b30(grid, 0, (unsigned short)i, 0);
        }
    }
#if defined(jpn)
    void* selected = func_ov004_02168fa4(a, 0x14);
    if(selected) {
        *(short*)((char*)selected+0x104)=page;
        *(short*)((char*)selected+0x106)=var3;
        func_ov023_021f809c(selected,a);
    }
#else
    func_ov023_021f6630((int)a, 0x14, page, var3);
#endif
    return 0;
}
