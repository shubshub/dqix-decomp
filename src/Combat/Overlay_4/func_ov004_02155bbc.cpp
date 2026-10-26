#include <globaldefs.h>


extern "C" int func_ov004_021551a8(void* a);
extern "C" int func_ov004_02155b6c(void* a);
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
extern "C" int func_ov023_021f6f10(void*);
extern "C" int func_ov023_021f98e0(void*, void*);
extern "C" unsigned int func_ov023_021f9bb0(struct Struct_ov004_021549e4_2* obj);
extern "C" unsigned short func_ov023_021f9bc0(struct Struct_ov004_021549e4_4* o);
extern "C" unsigned int func_ov023_021f9b6c(struct Struct_ov004_021549e4_3* obj, unsigned int a, unsigned int b);
extern "C" void* func_ov023_021f9cb8(void* unused, void* other, void* node);
extern "C" void func_ov023_021f88b8(void* obj, void* param1, int id);
extern "C" void func_ov004_0215534c(void*);
struct SePlayer;
extern "C" void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern struct SePlayer g_sePlayer;

struct Struct_ov004_02155bbc_3 { char pad[0x10]; unsigned char toggle; };
extern struct Struct_ov004_02155bbc_3* data_ov004_021707c4;

class Struct_ov004_02155bbc {
public:
    virtual void v00(); virtual void inline_ov004_02155bbc_2(); virtual void inline_ov004_02155bbc_3(); virtual void inline_ov004_02155bbc_4();
    virtual void v04(); virtual void inline_ov004_02155bbc_6(); virtual void inline_ov004_02155bbc_7(); virtual void inline_ov004_02155bbc_8();
    virtual void v08(); virtual void inline_ov004_02155bbc_10(); virtual void v10(); virtual void inline_ov004_02155bbc_12();
    virtual void inline_ov004_02155bbc_13(); virtual void inline_ov004_02155bbc_14(); virtual void v14(); virtual void inline_ov004_02155bbc_16();
    virtual void inline_ov004_02155bbc_17(); virtual void inline_ov004_02155bbc_18(); virtual void v18(); virtual void inline_ov004_02155bbc_20();
    virtual void v20(); virtual void inline_ov004_02155bbc_22(); virtual void inline_ov004_02155bbc_23(); virtual void inline_ov004_02155bbc_24();
    virtual void v24(); virtual void inline_ov004_02155bbc_26(); virtual void inline_ov004_02155bbc_27(); virtual void inline_ov004_02155bbc_28();
    virtual void v28(); virtual void inline_ov004_02155bbc_30(); virtual void v30(); virtual void inline_ov004_02155bbc_32();
    virtual void inline_ov004_02155bbc_33(); virtual void inline_ov004_02155bbc_34(); virtual void v34(); virtual void inline_ov004_02155bbc_36();
    virtual void inline_ov004_02155bbc_37(); virtual void inline_ov004_02155bbc_38(); virtual void v38(); virtual void inline_ov004_02155bbc_40();
    virtual void v40(); virtual void inline_ov004_02155bbc_42(); virtual void inline_ov004_02155bbc_43(); virtual void inline_ov004_02155bbc_44();
    virtual void v44(); virtual void inline_ov004_02155bbc_46(); virtual void inline_ov004_02155bbc_47(); virtual void inline_ov004_02155bbc_48();
    virtual void v48(); virtual void inline_ov004_02155bbc_50(); virtual void v50(); virtual void inline_ov004_02155bbc_52();
    virtual void inline_ov004_02155bbc_53(); virtual void inline_ov004_02155bbc_54(); virtual void v54(); virtual void inline_ov004_02155bbc_56();
    virtual void inline_ov004_02155bbc_57(); virtual void inline_ov004_02155bbc_58(); virtual void v58();
    virtual void* inline_ov004_02155bbc_60();
};

struct Struct_ov004_021549e4 { void* first; };
extern "C" short func_ov023_021e1da4(struct Struct_ov004_021549e4* head, int val);

struct Struct_ov004_021549e4_5;
extern "C" void func_ov023_021f9bdc(struct Struct_ov004_021549e4_5* o, int arg1);

struct Struct_ov004_02155bbc_2 {
    char pad[0x5c];
    short unknown_5c_;
    short unknown_5e_;
};

// USA: func_ov004_02155bbc
extern "C" ARM int func_ov004_02155bbc(void* a1) {
    void* r4 = (void*)func_ov004_021551a8(a1);
    if (!r4) return 0;

    data_ov004_021707c4->toggle++;
    data_ov004_021707c4->toggle &= 1;

    func_ov004_02155b6c(a1);

    void* base = func_ov011_021849c8(a1);
    void* node = func_ov023_021f6880(base, 0x39);
    if (!node) return 0;

    void* listHead = ((Struct_ov004_02155bbc*)node)->inline_ov004_02155bbc_60();
    if (!listHead) return 0;

    short idx = func_ov023_021e1da4((struct Struct_ov004_021549e4*)listHead, *(short*)((char*)r4 + 0x18));
    if (idx < 0) return 0;

    void* base2 = func_ov011_021849c8(a1);
    void* node2 = func_ov023_021f6880(base2, 0x2c);
    if (!node2) return 0;
    if (func_ov023_021f6f10(node2) != 7) return 0;

    struct Struct_ov004_02155bbc_2* e = (struct Struct_ov004_02155bbc_2*)node2;
    short var8 = e->unknown_5e_;
    e->unknown_5c_ = (short)(idx / 16);
    e->unknown_5e_ = var8;
    short var9 = (short)(idx % 16);
    unsigned short var10 = (unsigned short)var9;
    func_ov023_021f9bdc((struct Struct_ov004_021549e4_5*)node2, var10);

    func_ov023_021f98e0(node2, a1);

    unsigned int v1 = func_ov023_021f9bb0((struct Struct_ov004_021549e4_2*)node2);
    unsigned short v2 = func_ov023_021f9bc0((struct Struct_ov004_021549e4_4*)node2);
    unsigned int entry = func_ov023_021f9b6c((struct Struct_ov004_021549e4_3*)node2, v1, v2);

    void* base3 = func_ov011_021849c8(a1);
    void* node3 = func_ov023_021f6880(base3, entry);
    if (node3) {
        if (func_ov023_021f6f10(node3) == 8) {
            void* res = func_ov023_021f9cb8(node2, a1, node3);
            if (res) {
                func_ov023_021f88b8(res, a1, 0x8000);
            }
        }
    }

    func_ov004_0215534c(a1);
    SePlayer_Play(&g_sePlayer, 1, 0);
    return 0;
}
