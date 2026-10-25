#if defined(jpn)
enum { Enum_02077500_24 = 0x14 };
#else
enum { Enum_02077500_24 = 0x18 };
#endif

#include <globaldefs.h>
#include "World/Object3D.h"

struct Struct_020fdd44;
struct Struct_0201a300_11;
struct Struct_02039df4;
struct Struct_02037d88_9;

struct Struct_02077500 {
    int unknown_0_;
    int unknown_4_;
    int unknown_8_;
};

struct Struct_02077500_2 {
    char unknown_0_[4];
    short unknown_4_;
    short unknown_6_;
    short unknown_8_;
};

struct Struct_02077500_3 {
    char unknown_0_[2];
    short unknown_2_;
    short unknown_4_;
    char unknown_6_[0xa8];
    short unknown_ae_;
    char unknown_b0_[2];
    short unknown_b2_;
    char unknown_b4_[0xa4];
    Struct_02077500 unknown_158_;
    unsigned short unknown_164_;
};

extern Entry_02028bd0* ZoneRecords_GetInstance();
extern Entry_02028bd0* FindInlineEntryById(Entry_02028bd0* table, int id);
extern TableEntry_02077500* FindListEntryById(List_020283c0* list, int id);
extern "C" void func_0202ae18();
extern "C" int func_0202c508();
extern "C" void func_ov017_021c927c(int arg0, int arg1, int arg2, Struct_02077500 arg3, int arg4, int arg5, int arg6);

// USA: func_02077500
extern "C" ARM int func_02077500(Actor_02077500* obj) {
    Entry_02028bd0* table = ZoneRecords_GetInstance();
    if (table == 0) {
        return 0;
    }
    Struct_020fdd44* var1 = func_02028bd0(var0, ((Object3D*)((Struct_02039df4*)arg0))->GetField06());
    if (var1 == 0) {
        return 0;
    }
    Struct_0201a300_11* var2 = (Struct_0201a300_11*)((char*)var1 + Enum_02077500_24);
    if (var2 == 0) {
        return 0;
    }
    arg0->unknown_b2_ = 0;
    ((Object3D*)((Struct_02037d88_9*)arg0))->TransitionInheritedAlpha(0, 0xfa);
    ((Object3D*)((unsigned char*)arg0))->EnableFlag(0x80);
    func_0202ae18();
    if (func_0202c508() != 0) {
        Struct_02077500_2* var3 = func_020283c0(var2, arg0->unknown_164_);
        if (var3 == 0) {
            return 0;
        }
        arg0->unknown_158_.unknown_0_ = var3->unknown_4_ << 0xc;
        arg0->unknown_158_.unknown_4_ = var3->unknown_6_ << 0xc;
        arg0->unknown_158_.unknown_8_ = var3->unknown_8_ << 0xc;
        int var4 = ((Object3D*)((Struct_02039df4*)arg0))->GetField06();
        int var5 = arg0->unknown_4_ - 0x70;
        int var6 = arg0->unknown_2_;
        Struct_02077500* var7 = &arg0->unknown_158_;
        int var8 = arg0->unknown_ae_;
        int var9 = var5 % 0xc;
        if (var9 >= 0 && var9 < 0xc) {
            func_ov017_021c927c(var4, var9, var6, *var7, var8, 3, -1);
        }
    }
    return 1;
}
