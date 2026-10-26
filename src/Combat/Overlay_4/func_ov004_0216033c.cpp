#include <globaldefs.h>
#include "NitroSDK/Matrix.h"
#include "GameState/GameState.h"

#if defined(jpn)
enum { Enum_ov004_0216033c_7=6,fieldB=8,field6=4,field8=7,Enum_ov004_0216033c_336=0x144,Enum_ov004_0216033c_2128=0x7b8 };
#else
enum { Enum_ov004_0216033c_7=7,fieldB=0xb,field6=6,field8=8,Enum_ov004_0216033c_336=0x150,Enum_ov004_0216033c_2128=0x850 };
#endif

extern "C" void func_ov004_0215f6f4(void* a, short v1, short v2, int flag);
extern "C" int func_02053c6c(unsigned char* obj);
extern "C" void* func_ov011_021849c8(void* p);
extern "C" int func_02085fb4(unsigned char* actor);
extern "C" int func_02086020(unsigned char* actor);
extern "C" int func_0208608c(unsigned char* actor);
extern "C" int func_020860f8(unsigned char* actor);
extern "C" int func_02086164(unsigned char* actor);
extern "C" int func_020861d0(unsigned char* actor);
extern "C" int func_0208623c(unsigned char* arg0);
extern "C" int func_020862a8(unsigned char* arg0);
extern "C" int func_02086314(unsigned char* arg0);
extern "C" void func_ov004_0215e49c(void*, int, int);
extern "C" extern int func_ov023_021f6f10(void* self);
extern "C" int func_ov004_0215e460(void);
extern "C" int func_ov004_0215e4e8(void* a, int key);
extern "C" int func_020dd11c(unsigned int a, unsigned int b);

typedef Vector3i Type_02000c9c_18;
class Struct_ov004_0215fdfc_4 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6();
    virtual void inline_ov004_0216033c(const Type_02000c9c_18& v);
    virtual Type_02000c9c_18 inline_ov004_0216033c_2();
};
extern "C" Struct_ov004_0215fdfc_4* func_ov004_0215e47c(void* a, int key);

extern "C" void* func_ov004_0215e4c0(void* a, int key);
struct Struct_ov004_0215f6f4;
extern "C" void func_ov023_021f8944(struct Struct_ov004_0215f6f4* obj, int a1, int a2, int a3);

extern unsigned char data_ov004_021707e8;
extern int data_ov004_02170854[];
#define D0 (&data_ov004_021707e8)
#define D1 (data_ov004_02170854)

class Struct_ov004_0216033c {
public:
    virtual void inline_ov004_0216033c_3();
    virtual void inline_ov004_0216033c_4();
    virtual void inline_ov004_0216033c_5();
    virtual void inline_ov004_0216033c_6();
    virtual void inline_ov004_0216033c_7();
    virtual void inline_ov004_0216033c_8();
    virtual void inline_ov004_0216033c_9();
    virtual void inline_ov004_0216033c_10();
    virtual void inline_ov004_0216033c_11();
    virtual void inline_ov004_0216033c_12();
    virtual void inline_ov004_0216033c_13();
    virtual void inline_ov004_0216033c_14();
    virtual void inline_ov004_0216033c_15();
    virtual void inline_ov004_0216033c_16();
    virtual void inline_ov004_0216033c_17();
    virtual void inline_ov004_0216033c_18();
    virtual void inline_ov004_0216033c_19();
    virtual void inline_ov004_0216033c_20();
    virtual void inline_ov004_0216033c_21();
    virtual void inline_ov004_0216033c_22();
    virtual void inline_ov004_0216033c_23();
    virtual void inline_ov004_0216033c_24();
    virtual void inline_ov004_0216033c_25();
    virtual void inline_ov004_0216033c_26();
    virtual void inline_ov004_0216033c_27();
    virtual void inline_ov004_0216033c_28();
    virtual void inline_ov004_0216033c_29();
    virtual void inline_ov004_0216033c_30();
    virtual void inline_ov004_0216033c_31();
    virtual void inline_ov004_0216033c_32();
    virtual void inline_ov004_0216033c_33();
    virtual void inline_ov004_0216033c_34();
    virtual void inline_ov004_0216033c_35();
    virtual void inline_ov004_0216033c_36();
    virtual void inline_ov004_0216033c_37();
    virtual void inline_ov004_0216033c_38();
    virtual void inline_ov004_0216033c_39();
    virtual void inline_ov004_0216033c_40();
    virtual void inline_ov004_0216033c_41();
    virtual void inline_ov004_0216033c_42();
    virtual void inline_ov004_0216033c_43();
    virtual void inline_ov004_0216033c_44();
    virtual void inline_ov004_0216033c_45();
    virtual void inline_ov004_0216033c_46();
    virtual void inline_ov004_0216033c_47();
    virtual void inline_ov004_0216033c_48();
    virtual void inline_ov004_0216033c_49();
    virtual void inline_ov004_0216033c_50();
    virtual void inline_ov004_0216033c_51();
    virtual void inline_ov004_0216033c_52();
    virtual void inline_ov004_0216033c_53();
    virtual void inline_ov004_0216033c_54();
    virtual void inline_ov004_0216033c_55();
    virtual void inline_ov004_0216033c_56();
    virtual void inline_ov004_0216033c_57(int arg);
    virtual void inline_ov004_0216033c_58();
    virtual void inline_ov004_0216033c_59(int arg);
    unsigned char pad0[0xc - 4];
    unsigned char unknown_c_;
    char pad1[0x20 - 0xd];
    int unknown_20_;
    char pad2[0x38 - 0x24];
    short field0x38;
};
extern "C" Struct_ov004_0216033c* func_ov023_021f6880(void* obj, int key);

struct Struct_02000c9c_90 {
    char pad[0x30];
    unsigned short unknown_30_, unknown_32_, unknown_34_, unknown_36_;
};

struct Struct_ov004_0216033c_2 {
    char pad[0x49c];
    unsigned char bit0 : 1;
};

struct Struct_ov003_021539a0_3 {
    unsigned int a : 10;
    unsigned int b : 10;
    unsigned int c : 10;
    unsigned int pad : 2;
};

// USA: func_ov004_0216033c
extern "C" ARM int func_ov004_0216033c(void* a) {
    int i;
    Struct_ov003_021539a0_3* rowBase;
    Struct_ov004_0216033c* node;
    unsigned char* base150;
    unsigned char* combatant;
    *(unsigned char*)((char*)D0 + Enum_ov004_0216033c_7) = 0x64;
    short v1 = *(signed char*)((char*)D0 + fieldB);
    short v2 = *(signed char*)((char*)D0 + field6);
    func_ov004_0215f6f4(a, v1, v2, 0);

    int combatantId = *(int*)((char*)D0 + 0x1c);
    unsigned char sb = *(unsigned char*)((char*)D0 + field8);
    GameState* bs = GameState::GetInstance();
    combatant = (unsigned char*)func_0200ff1c(bs, combatantId);
    if (!combatant) goto stats_done;
    base150 = (unsigned char*)func_02053c6c(combatant);
    if (!base150) goto stats_done;
    {

    short var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20;
    void* var21 = func_ov011_021849c8(a);

    int var22 = D1[sb];
    int var23 = combatantId * 0xc + (var22 - 1);
    rowBase = (Struct_ov003_021539a0_3*)(*(int*)((char*)D0 + 0x14) + var23 * 0x18);

    for (i = 0; i < 0xe; i++) {
        node = func_ov023_021f6880(var21, i + 0x51);
        if (!node) continue;

        int t2 = D1[sb];
        if (*(unsigned char*)((char*)D0 + 2) == t2) {
            Struct_ov003_021539a0_3* f150;
            unsigned short var26;
            switch (i) {
            case 0: f150 = *(Struct_ov003_021539a0_3**)((char*)combatant + Enum_ov004_0216033c_336); var26 = f150[0].a; node->inline_ov004_0216033c_59(var26); break;
            case 1: f150 = *(Struct_ov003_021539a0_3**)((char*)combatant + Enum_ov004_0216033c_336); var26 = f150[0].b; node->inline_ov004_0216033c_59(var26); break;
            case 2: f150 = *(Struct_ov003_021539a0_3**)((char*)combatant + Enum_ov004_0216033c_336); var26 = f150[0].c; node->inline_ov004_0216033c_59(var26); break;
            case 3: f150 = *(Struct_ov003_021539a0_3**)((char*)combatant + Enum_ov004_0216033c_336); var26 = f150[1].a; node->inline_ov004_0216033c_59(var26); break;
            case 4: f150 = *(Struct_ov003_021539a0_3**)((char*)combatant + Enum_ov004_0216033c_336); var26 = f150[1].b; node->inline_ov004_0216033c_59(var26); break;
            case 5: f150 = *(Struct_ov003_021539a0_3**)((char*)combatant + Enum_ov004_0216033c_336); var26 = f150[1].c; node->inline_ov004_0216033c_59(var26); break;
            case 6: f150 = *(Struct_ov003_021539a0_3**)((char*)combatant + Enum_ov004_0216033c_336); var26 = f150[2].a; node->inline_ov004_0216033c_59(var26); break;
            case 7: var26 = *(unsigned short*)((char*)*(void**)((char*)combatant + 0x134) + 0x30); node->inline_ov004_0216033c_59(var26); break;
            case 8: var26 = *(unsigned short*)((char*)*(void**)((char*)combatant + 0x134) + 0x32); node->inline_ov004_0216033c_59(var26); break;
            case 9: var26 = *(unsigned short*)((char*)*(void**)((char*)combatant + 0x134) + 0x34); node->inline_ov004_0216033c_59(var26); break;
            case 10: var26 = *(unsigned short*)((char*)*(void**)((char*)combatant + 0x134) + 0x36); node->inline_ov004_0216033c_59(var26); break;
            case 11: f150 = *(Struct_ov003_021539a0_3**)((char*)combatant + Enum_ov004_0216033c_336); var26 = f150[3].a; node->inline_ov004_0216033c_59(var26); break;
            case 12: var26 = *(unsigned short*)(base150 + 0x100 + t2 * 2 + 0x6c); node->inline_ov004_0216033c_59(var26); break;
            case 13: { int var27 = *(int*)(base150 + t2 * 4 + 0x138); node->inline_ov004_0216033c_59(var27); } break;
            default: break;
            }
            node->inline_ov004_0216033c_57(0xf);
        } else {
            int var28 = func_02053c6c(combatant) + Enum_ov004_0216033c_2128;
            int var29 = D1[sb];
            int var30 = (var29 & 0xff) * 0xc;
            Struct_ov003_021539a0_3* entryBase = (Struct_ov003_021539a0_3*)(var28 + var30);

            var20 = (func_02085fb4(base150) + rowBase[0].a + entryBase[0].a);
            var19 = (func_02086020(base150) + rowBase[0].b + entryBase[0].b);
            var18 = (func_0208608c(base150) + rowBase[0].c + entryBase[0].c);
            var17 = (func_020860f8(base150) + rowBase[1].a + entryBase[1].a);
            var16 = (func_02086164(base150) + rowBase[1].b + entryBase[1].b);
            var15 = (func_020861d0(base150) + rowBase[1].c + entryBase[1].c);
            var14 = (func_0208623c(base150) + rowBase[2].a + entryBase[2].a);
            var13 = (func_020862a8(base150) + rowBase[2].b + entryBase[2].b);
            var12 = (func_02086314(base150) + rowBase[2].c + entryBase[2].c);
            var11 = var20;
            var10 = var18;
            int var32 = (short)(func_02086164(base150) + rowBase[3].a + entryBase[1].b);

            enum { Enum_ov004_0216033c_999 = 999 };
            if (var20 > Enum_ov004_0216033c_999) var20 = Enum_ov004_0216033c_999;
            if (var19 > Enum_ov004_0216033c_999) var19 = Enum_ov004_0216033c_999;
            if (var18 > Enum_ov004_0216033c_999) var18 = Enum_ov004_0216033c_999;
            if (var17 > Enum_ov004_0216033c_999) var17 = Enum_ov004_0216033c_999;
            if (var16 > Enum_ov004_0216033c_999) var16 = Enum_ov004_0216033c_999;
            if (var15 > Enum_ov004_0216033c_999) var15 = Enum_ov004_0216033c_999;
            if (var14 > Enum_ov004_0216033c_999) var14 = Enum_ov004_0216033c_999;
            if (var13 > Enum_ov004_0216033c_999) var13 = Enum_ov004_0216033c_999;
            if (var12 > Enum_ov004_0216033c_999) var12 = Enum_ov004_0216033c_999;
            if (var11 > Enum_ov004_0216033c_999) var11 = Enum_ov004_0216033c_999;
            if (var10 > Enum_ov004_0216033c_999) var10 = Enum_ov004_0216033c_999;
            if (var32 > Enum_ov004_0216033c_999) var32 = Enum_ov004_0216033c_999;

            switch (i) {
            case 0: node->inline_ov004_0216033c_59(var20); break;
            case 1: node->inline_ov004_0216033c_59(var19); break;
            case 2: node->inline_ov004_0216033c_59(var18); break;
            case 3: node->inline_ov004_0216033c_59(var17); break;
            case 4: node->inline_ov004_0216033c_59(var16); break;
            case 5: node->inline_ov004_0216033c_59(var15); break;
            case 6: node->inline_ov004_0216033c_59(var14); break;
            case 7: node->inline_ov004_0216033c_59(var13); break;
            case 8: node->inline_ov004_0216033c_59(var12); break;
            case 9: node->inline_ov004_0216033c_59(var11); break;
            case 10: node->inline_ov004_0216033c_59(var10); break;
            case 11: node->inline_ov004_0216033c_59(var32); break;
            case 12: { unsigned short var33 = *(unsigned short*)(base150 + 0x100 + D1[sb] * 2 + 0x6c); node->inline_ov004_0216033c_59(var33); } break;
            case 13: { int var34 = *(int*)(base150 + D1[sb] * 4 + 0x138); node->inline_ov004_0216033c_59(var34); } break;
            default: break;
            }
            node->inline_ov004_0216033c_57(3);
        }
    }

    {
        if (!(*(Struct_ov004_0216033c_2**)(combatant + Enum_ov004_0216033c_336))->bit0) {
            func_ov004_0215e49c(a, 0xe, 2);
        } else {
            func_ov004_0215e49c(a, 0xe, 3);
        }
    }

    {
        Struct_ov004_0216033c* node = func_ov023_021f6880(var21, 0xe);
        if (node) {
            if (*(unsigned char*)((char*)D0 + 2) == D1[sb]) {
                node->inline_ov004_0216033c_57(0xf);
            } else {
                node->inline_ov004_0216033c_57(3);
            }
        }
    }

    {
        Struct_ov004_0216033c* node = func_ov023_021f6880(var21, 0xc);
        if (node) {
            if (func_ov023_021f6f10(node) == 8) {
                node->unknown_20_ = *(int*)((char*)combatant + 0x134);
                Struct_ov004_0216033c* node2 = func_ov023_021f6880(var21, 0xe);
                if (node2) {
                    if (*(unsigned char*)((char*)D0 + 2) == D1[sb]) {
                        node2->inline_ov004_0216033c_57(0xf);
                    } else {
                        node2->inline_ov004_0216033c_57(3);
                    }
                }
            }
        }
    }

    {
        for (int j = 0; j < 0x13; j++) {
            Struct_ov004_0216033c* node = func_ov023_021f6880(var21, j + 0x12c);
            if (node && func_ov023_021f6f10(node) == 8) {
                if (*(unsigned char*)((char*)D0 + 2) == D1[sb]) {
                    node->inline_ov004_0216033c_57(0xf);
                } else {
                    node->inline_ov004_0216033c_57(3);
                }
            }
        }
    }

    {
        int var40 = D1[sb];
        unsigned char var41 = *(unsigned char*)(base150 + var40 + 0x186);
        Struct_ov004_0216033c* node = func_ov023_021f6880(var21, 0xc8);
        if (node) {
            if (var41 != 0) {
                node->unknown_c_ &= ~8;
                node->field0x38 = var41 + 0x1d3;
                if (var41 == 0xa) {
                    node->inline_ov004_0216033c_57(0xd);
                } else {
                    node->inline_ov004_0216033c_57(5);
                }
            } else {
                node->unknown_c_ |= 8;
            }
        }
    }

    }
stats_done:

    int r4 = 0;
    switch (D1[*(unsigned char*)((char*)D0 + field8)]) {
    case 0: r4 = 4; break;
    case 1: r4 = 5; break;
    case 2: r4 = 6; break;
    case 3: r4 = 7; break;
    case 4: r4 = 8; break;
    case 5: r4 = 9; break;
    case 6: r4 = 0xa; break;
    case 7: r4 = 0xb; break;
    case 9: r4 = 0xd; break;
    case 8: r4 = 0xc; break;
    case 12: r4 = 0x10; break;
    case 10: r4 = 0xe; break;
    case 11: r4 = 0xf; break;
    }
    if (func_ov004_0215e460() != 0) r4 = 4;
    func_ov004_0215e49c(a, 0xf, r4);

    int var44 = func_ov004_0215e4e8(a, 0xf);
    Struct_ov004_0215fdfc_4* var45 = func_ov004_0215e47c(a, 0xf);
    if (var45) {
        const Vector3i& var46 = var45->inline_ov004_0216033c_2();
        Vector3i v2;
        v2 = var46;
        v2.x = ((0x80 - var44) >> 1) << 12;
        var45->inline_ov004_0216033c(v2);
        int var48 = v2.x + ((var44 + 2) << 12);
        v2.x = var48;
#if defined(jpn)
        v2.y += 0x2000;
#endif
        Struct_ov004_0215fdfc_4* var49 = func_ov004_0215e47c(a, 0xc8);
        if (var49) {
            var49->inline_ov004_0216033c(v2);
        }
    }

    int var50 = *(int*)((char*)D0 + 0x1c);
    unsigned char var51 = *(unsigned char*)((char*)D0 + field8);
    GameState* bs2 = GameState::GetInstance();
    unsigned char* combatant2 = (unsigned char*)func_0200ff1c(bs2, var50);
    Struct_ov004_0216033c* var54;
    int tv;
    Struct_ov004_0216033c* var56;
    int k;
    int idx;
    Struct_ov004_0216033c* var59;
    int hidden;
    int msgId;
    void* var62 = func_ov011_021849c8(a);
    idx = 0;
    msgId = 0;
    hidden = 0;
    if (func_ov004_0215e460() != 0) hidden = 1;

    for (k = 0; k < 5; k++) {
        tv = func_020dd11c(D1[var51] & 0xff, k & 0xff);
        switch (tv) {
        case 1: msgId = 0x12; break;
        case 2: msgId = 0x13; break;
        case 3: msgId = 0x14; break;
        case 4: msgId = 0x15; break;
        case 5: msgId = 0x16; break;
        case 6: msgId = 0x17; break;
        case 7: msgId = 0x18; break;
        case 8: msgId = 0x19; break;
        case 9: msgId = 0x1a; break;
        case 10: msgId = 0x1b; break;
        case 11: msgId = 0x1c; break;
        case 12: msgId = 0x1d; break;
        case 13: msgId = 0x1e; break;
        case 14: msgId = 0x1f; break;
        case 15: msgId = 0x20; break;
        case 16: msgId = 0x21; break;
        case 17: msgId = 0x22; break;
        case 18: msgId = 0x23; break;
        case 19: msgId = 0x24; break;
        case 20: msgId = 0x25; break;
        case 21: msgId = 0x26; break;
        case 22: msgId = 0x27; break;
        case 23: msgId = 0x28; break;
        case 24: msgId = 0x29; break;
        case 25: msgId = 0x2a; break;
        case 26: msgId = 0x2b; break;
        }
        func_ov004_0215e49c(a, idx + 0x2a, msgId);

        var59 = func_ov023_021f6880(var62, k + 0x5f);
        if (var59) {
            var59->inline_ov004_0216033c_59(*(unsigned char*)(*(unsigned char**)(combatant2 + Enum_ov004_0216033c_336) + tv + 0x464));
            if (*(unsigned char*)((char*)D0 + 2) != D1[var51]) {
                var59->inline_ov004_0216033c_57(3);
            } else if (*(unsigned char*)(*(unsigned char**)(combatant2 + Enum_ov004_0216033c_336) + tv + 0x464) >= 100) {
                var59->inline_ov004_0216033c_57(0xd);
            } else {
                var59->inline_ov004_0216033c_57(0xf);
            }

            var56 = 0;
            Struct_ov004_0216033c* tmp = func_ov023_021f6880(var62, idx + 0x2a);
            if (tmp && func_ov023_021f6f10(tmp) == 8) var56 = tmp;
            var54 = 0;
            Struct_ov004_0216033c* var64 = func_ov023_021f6880(var62, k + 0x13a);
            if (var64 && func_ov023_021f6f10(var64) == 8) var54 = var64;

            if (hidden != 0) {
                var59->unknown_c_ |= 8;
                if (var56) var56->unknown_c_ |= 8;
                if (var54) var54->unknown_c_ |= 8;
            } else {
                var59->unknown_c_ &= ~8;
                if (var56) var56->unknown_c_ &= ~8;
                if (var54) var54->unknown_c_ &= ~8;
            }

            idx += 2;
        }
    }

    unsigned char var65 = *(unsigned char*)((char*)D0 + field8);
    int kind;
    int var67;
    void* var68 = func_ov011_021849c8(a);
    var67 = 0;
    kind = 0xf;
    if (*(unsigned char*)((char*)D0 + 2) == D1[var65]) {
        for (int m = 0; m < 0x28; m++) {
            Struct_ov004_0216033c* n2 = func_ov023_021f6880(var68, m + 0xc);
            if (n2) n2->inline_ov004_0216033c_57(kind);
        }
        for (int m = 0; m < 3; m++) {
            Struct_ov004_0216033c* n2 = func_ov023_021f6880(var68, m + 0x64);
            if (n2) n2->inline_ov004_0216033c_57(kind);
        }
    } else {
        for (var67 = 0; var67 < 0x28; var67++) {
            Struct_ov004_0216033c* n2 = func_ov023_021f6880(var68, var67 + 0xc);
            if (n2) n2->inline_ov004_0216033c_57(3);
        }
        for (var67 = 0; var67 < 3; var67++) {
            Struct_ov004_0216033c* n2 = func_ov023_021f6880(var68, var67 + 0x64);
            if (n2) n2->inline_ov004_0216033c_57(3);
        }
        var67 = 1;
        kind = 3;
    }
    void* var75 = func_ov004_0215e4c0(a, 3);
    if (var75) {
        *(unsigned char*)((char*)var75 + 0x10a) = (unsigned char)kind;
        func_ov023_021f8944((struct Struct_ov004_0215f6f4*)var75, (int)(long)a, var67, 1);
    }

    return 0;
}
