#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Combat/Main/BattleList.h"
#include "std_library_functions.h"

#if defined(jpn)
enum { Field29c = 0x218, Field55d8 = 0x57c8, Field18c = 0x180, Fielde78 = 0xdf4 };
#else
enum { Enum_ov025_021e0638_668 = 0x29c, Enum_ov025_021e0638_21976 = 0x55d8, Enum_ov025_021e0638_396 = 0x18c, Enum_ov025_021e0638_3704 = 0xe78 };
#endif

struct Struct_0203d028_2 {
    int unknown_0_;
    int unknown_4_;
    struct Struct_0203d028_3* unknown_8_[0xe9];
};
struct Struct_0203d028_3 {
    unsigned short unknown_0_;
    char unknown_2_[0x132];
    struct BaseCombatStats* unknown_134_;
    struct ModifiableCombatStats* unknown_138_;
};

struct Struct_02048c90;
struct Struct_02049410;
struct Struct_02048f64;
struct Struct_02048f64_2;
struct Struct_ov000_0215440c_2;
struct Struct_ov000_0215440c;

struct Struct_ov025_021e0638_11 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    char unknown_2_[6];
    unsigned char* unknown_8_;
};

struct Struct_ov025_021e0638_12 {
    unsigned char unknown_0_[12];
    Struct_ov025_021e0638_12* unknown_c_;
};

struct Struct_ov025_021e0638 {
    unsigned char unknown_0_[16];
    unsigned char unknown_10_[16];
    unsigned char unknown_20_;
};

struct Struct_ov025_021e0638_2 {
    void* unknown_0_;
    int unknown_4_;
    unsigned char unknown_8_[12];
    unsigned char unknown_14_;
};

struct Struct_ov025_021e0638_3 {
    unsigned char unknown_0_[6];
};

struct Struct_ov025_021e0638_4 { int unknown_0_; int unknown_4_; int unknown_8_; };
struct Struct_ov025_021e0638_5 { int unknown_0_[2]; };

struct Struct_ov025_021e0638_6 {
    char unknown_0_[8];
    unsigned char unknown_8_;
    unsigned char unknown_9_;
    char unknown_a_[6];
    unsigned char* unknown_10_;
    unsigned char* unknown_14_;
    char unknown_18_[0x10];
};

struct Struct_ov025_021e0638_7 {
    char unknown_0_[0x8000];
    Struct_ov025_021e0638_6 unknown_8000_[77];
};

struct Struct_ov025_021e0638_8 {
    char unknown_0_[0x21c];
    Struct_ov025_021e0638_7 unknown_21c_;
    int unknown_8e24_;
};

static inline Struct_ov025_021e0638_7* inline_ov025_021e0638(Struct_ov025_021e0638_8* arg0) { return &arg0->unknown_21c_; }
static inline Struct_ov025_021e0638_6* inline_ov025_021e0638_2(Struct_ov025_021e0638_7* arg0) { return arg0->unknown_8000_; }

struct Struct_ov025_021e0638_9 {
    char unknown_0_[0x10];
    unsigned int unknown_10_;
};

struct Struct_ov025_021e0638_10 {
    Struct_ov025_021e0638_4 unknown_0_;
    Struct_ov025_021e0638_4 unknown_c_;
    int unknown_18_;
    unsigned char unknown_1c_;
};

extern "C" int func_ov025_021e1048(void* world, void* out);
extern "C" void func_ov025_021e20ec(void* tbl, SafeAllocator* alloc);
extern "C" int func_ov025_021e2148(void* tbl, int a, int b, void* out, int n);
extern "C" void func_ov025_021e120c(void* buf, int id, int a, int b, int c);
extern "C" void HaltSystem(void);
extern "C" void func_ov000_0216f82c(B6_021e0638* out, const int* cell);
extern "C" void func_ov000_0216f74c(Pos2_021e0638* out, const int* cell);
struct Vector3i;
extern "C" void __clear(void* arg0, int arg1);

extern "C" void func_ov025_021e20d8(void* arg0);
extern "C" void func_02048c90(Struct_02048c90*);
extern "C" int func_020493a4(unsigned char*);
extern "C" int func_020493c8(unsigned char*);
extern "C" int func_02049444(unsigned char*);
extern "C" int func_02049ee8(unsigned char*);
extern "C" void func_ov025_021e2114(unsigned char*, void*, int);
extern "C" void func_02049410(Struct_02049410*, void*, int);
extern "C" void func_02049a74(Struct_02048f64*);
extern "C" void func_02049ae4(unsigned char*);
extern "C" void func_0204950c(unsigned char*);
extern "C" void func_020494f8(unsigned char*);
extern "C" void func_02048994(void);
extern "C" Struct_ov025_021e0638_10* func_020489b0(void);
extern "C" int func_02049ec0(unsigned char*);
extern "C" int func_02048c10(unsigned char*);
extern "C" void func_020494c0(Struct_02048f64_2*);
extern "C" unsigned char* func_ov000_02160094(Struct_ov000_0215440c_2*, int);
extern "C" unsigned char* func_ov000_021600f8(Struct_ov000_0215440c*, int);

static inline Struct_ov025_021e0638_12* inline_01ff8b48_2(Struct_ov025_021e0638_12* arg0, int arg1) {
    if (arg1 == 0) {
        return arg0;
    }
    Struct_ov025_021e0638_12* var0 = arg0->unknown_c_;
    for (int var1 = 0; var1 < arg1 - 1; var1++) {
        if (var0 == 0) {
            return 0;
        }
        var0 = var0->unknown_c_;
    }
    return var0;
}

// USA: func_ov025_021e0638
extern "C" ARM void func_ov025_021e0638(unsigned char* arg0) {
    int var0;
    Struct_ov025_021e0638_12* var1;
    GameState* var2 = GameState::GetInstance();
    Struct_ov025_021e0638_8* var3 = *(Struct_ov025_021e0638_8**)(arg0 + Enum_ov025_021e0638_668);
    Struct_ov025_021e0638_6* var4 = &var3->unknown_21c_.unknown_8000_[*(int*)(arg0 + Enum_ov025_021e0638_21976)];
    Struct_ov025_021e0638_11 var5[12];
    int var6[60];
    unsigned char var7[0x51];
    Struct_ov025_021e0638_12 var8;
    Struct_ov025_021e0638_2 var9;
    unsigned char var10[12];
    unsigned char var11[16];
    unsigned char var12[32];
    unsigned char var13[6];
    Struct_ov025_021e0638_5 var14;
    Struct_ov025_021e0638_5 var15;
    int var16;
    int var17;
    Struct_ov025_021e0638_3 var18;
    int var19;
    Struct_ov025_021e0638_3 var20;
    Struct_ov025_021e0638_3 var21;
    Struct_ov025_021e0638_3 var22;
    SafeAllocator* var23 = (SafeAllocator*)(arg0 + 0x30);

    var23->Reset();
    var0 = func_ov025_021e1048(var3, var5);
    var8.unknown_c_ = 0;
    Struct_ov025_021e0638* var24 = (Struct_ov025_021e0638*)var23->Allocate(var0 * 33);
    if (var24 == 0) {
        return;
    }
    for (int var25 = 0; var25 < var0; var25++) {
        func_02048c90((Struct_02048c90*)var5[var25].unknown_8_);
        var8.unknown_0_[var25] = func_020493a4(var5[var25].unknown_8_);
        var24[var25].unknown_20_ = 0;
        memset(var24[var25].unknown_10_, 0, 0x10);
    }
    func_ov025_021e20d8(&var9);
    func_ov025_021e20ec(&var9, var23);
    int var26;
    int var27;
    int var28;
    int var29;
    var28 = 0;
    var29 = 0;
    var27 = 1;
    var1 = &var8;
    for (var26 = *(int*)(arg0 + Enum_ov025_021e0638_21976); var26 < var3->unknown_8e24_; var26++) {
        unsigned char* var30 = inline_ov025_021e0638_2(inline_ov025_021e0638(var3))[var26].unknown_10_;
        if (var30 != 0) {
            var6[var29++] = *(unsigned short*)(var30 + 0x20);
        }
    }
    Struct_ov025_021e0638_7* var31 = &var3->unknown_21c_;
    for (int var32 = 0; var32 < *(int*)(arg0 + Enum_ov025_021e0638_21976); var32++) {
        Struct_ov025_021e0638_6* var33 = &var31->unknown_8000_[var32];
        if (var33->unknown_10_ != 0) {
            var6[var29++] = *(unsigned short*)(var33->unknown_10_ + 0x20);
        }
    }
    while (var27) {
        var27 = 0;
        for (int var34 = 0; var34 < var29; var34++) {
            int var35 = var6[var34];
            int var36;
            for (var36 = 0; var36 < var0; var36++) {
                if (var35 == var5[var36].unknown_0_) {
                    goto found;
                }
            }
            var36 = -1;
found:
            if (var36 < 0 || var0 <= var36) {
                continue;
            }
            unsigned char* var37 = var5[var36].unknown_8_;
            int var38;
            int var39 = var36 * 33;
            unsigned char* var40 = (unsigned char*)var24 + var39;
            unsigned char var41 = (&var24->unknown_20_)[var39];
            if (var41 >= 0x10) {
                continue;
            }
            int var42;
            if (var41 != 0) {
                var42 = var40[var41 - 1];
            } else {
                var42 = func_020493a4(var37);
            }
            var38 = func_020493c8(var37);
            if (var42 == var38) {
                continue;
            }
            unsigned char var43 = 0;
            for (int var44 = 0; var44 < var0; var44++) {
                unsigned char var45 = var1->unknown_0_[var44];
                if (var38 != var45) {
                    var10[var43++] = var45;
                }
            }
            func_ov025_021e2114((unsigned char*)&var9, var10, var43);
            __clear(var11, 0x10);
            unsigned char var46 = func_ov025_021e2148(&var9, var42, var38, var11, 0x10);
            if (var46 < 2) {
                continue;
            }
            if (var41 == 0) {
                var40[var41++] = var1->unknown_0_[var36];
            }
            if (len >= 0x10) {
                HaltSystem();
            }
            unsigned char var47 = var11[var46 - 2];
            unsigned char var48 = var41 + 1;
            var40[var41] = var47;
            (&var24->unknown_20_)[var39] = var48;
            var1->unknown_0_[var36] = var47;
            if (var48 > 2 && var28 > 0) {
                unsigned char var49;
                unsigned char var50 = var40[var48 - 1];
                unsigned char var51 = var40[var48 - 3];
                int var52;
                int var53;
                int var54;
                unsigned char var55;
                unsigned char var56;
                int var57;
                int var58;
                int var59;
                int var60;
                Struct_ov025_021e0638_12* var61;
                var19 = var51;
                func_ov000_0216f82c(&var20, &var19);
                var22 = var20;
                var17 = var50;
                func_ov000_0216f82c(&var18, &var17);
                var21 = var18;
                var54 = 0;
                for (var53 = 0; var53 < 6; var53++) {
                    var55 = var22.unknown_0_[var53];
                    if (var55 == 0xff) {
                        continue;
                    }
                    for (var52 = 0; var52 < 6; var52++) {
                        unsigned char var62 = var21.unknown_0_[var52];
                        if (var62 == 0xff) {
                            continue;
                        }
                        if (var55 == var62) {
                            var13[var54] = var55;
                            var54++;
                        }
                    }
                }
                var56 = var54;
                if (var28 - 1 == 0) {
                    var61 = &var8;
                } else {
                    var61 = var8.unknown_c_;
                    for (var58 = 0; var58 < var28 - 2; var58++) {
                        if (var61 == 0) {
                            var61 = 0;
                            break;
                        }
                        var61 = var61->unknown_c_;
                    }
                }
                var57 = 0;
                for (var59 = 0; var59 < var56; var59++) {
                    var57 = 1;
                    var60 = 0;
                    var49 = var13[var59];
                    for (; var60 < var0; var60++) {
                        if (var60 == var34) {
                            continue;
                        }
                        if (var49 == var61->unknown_0_[var60]) {
                            var57 = 0;
                            break;
                        }
                    }
                    if (var57 == 0) {
                        break;
                    }
                }
                if (var57 != 0) {
                    unsigned char* var63 = (unsigned char*)((unsigned int)var24 + var39);
                    var63 += var48 - 2;
                    var63[0x10] = 1;
                }
            }
            var27 = 1;
        }
        Struct_ov025_021e0638_12* var64 = (Struct_ov025_021e0638_12*)var23->Allocate(0x10);
        if (var64 == 0) {
            break;
        }
        memcpy(var64, var1, 0x10);
        var64->unknown_c_ = 0;
        Struct_ov025_021e0638_12* var65 = var1->unknown_c_;
        if (var65 == 0) {
            var1->unknown_c_ = var64;
        } else {
            while (var65->unknown_c_ != 0) {
                var65 = var65->unknown_c_;
            }
            var65->unknown_c_ = var64;
        }
        var28++;
        var1 = var64;
    }
    for (int var66 = 0; var66 < var0; var66++) {
        unsigned char var67 = 0;
        for (int var68 = 0; var68 < var24[var66].unknown_20_; var68++) {
            if (var24[var66].unknown_10_[var68] == 0) {
                var12[var67++] = var24[var66].unknown_0_[var68];
            }
        }
        func_02049410((Struct_02049410*)var5[var66].unknown_8_, var12, var67);
    }
    for (int var69 = 0; var69 < var0; var69++) {
        int var70 = 0;
        unsigned char* var71 = (unsigned char*)(Struct_0203d028_3*)func_0200ff1c(var2, *(short*)(var5[var69].unknown_8_ + 4));
        if (var71 != 0 && (*(unsigned int*)(var71 + Enum_ov025_021e0638_396) & 1)) {
            var70 = 1;
        }
        if (func_02049ee8(var5[var69].unknown_8_) != 0 && var70 == 0 && arg0[Enum_ov025_021e0638_3704] != 0) {
            func_02049a74((Struct_02048f64*)var5[var69].unknown_8_);
        } else {
            func_02049ae4(var5[var69].unknown_8_);
        }
        func_0204950c(var5[var69].unknown_8_);
    }
    for (int var72 = 0; var72 < var29; var72++) {
        unsigned char* var73 = (unsigned char*)var2->GetCombatantByIndex(var6[var72]);
        if (var73 != 0 && func_02049444(var73) != 0) {
            func_02049ae4(var73);
            func_020494f8(var73);
        }
    }
    for (int var74 = 0; var74 < var4->unknown_8_; var74++) {
        if (var4->unknown_10_ != 0) {
            unsigned char* var75 = (unsigned char*)var2->GetCombatantByIndex(*(unsigned short*)(var4->unknown_10_ + var74 * 0x34 + 0x20));
            if (var75 != 0) {
                func_02049ae4(var75);
                func_0204950c(var75);
            }
        }
    }
    for (int var76 = 0; var76 < var4->unknown_9_; var76++) {
        if (var4->unknown_14_ != 0) {
            unsigned char* var77 = (unsigned char*)var2->GetCombatantByIndex(*(short*)(var4->unknown_14_ + var76 * 0x24 + 0xe));
            if (var77 != 0) {
                func_02049ae4(var77);
                func_0204950c(var77);
            }
        }
    }
    for (int var78 = 0; var78 < var4->unknown_9_; var78++) {
        if (var4->unknown_14_ != 0) {
            unsigned char* var79 = (unsigned char*)var2->GetCombatantByIndex(*(short*)(var4->unknown_14_ + var78 * 0x24 + 0xe));
            if (var79 != 0) {
                memset(var7, 0, 0x51);
                Struct_ov025_021e0638_9* var80 = 0;
                int var81 = 1;
                if (*(unsigned short*)var79 & 0x400) {
                    var80 = *(Struct_ov025_021e0638_9**)(var79 + 0x148);
                }
                if (var80 != 0) {
                    unsigned int var82 = (var80->unknown_10_ << 1) >> 0x1e;
                    if (var82 != 0) {
                        var81 += var82;
                    }
                }
                func_ov025_021e120c(var7, func_020493a4(var79), 1, var81 & 0xff, 0);
                for (int var83 = 0; var83 < var0; var83++) {
                    int var84 = func_020493c8(var5[var83].unknown_8_);
                    if (var84 < 0x51 && var7[var84] == 1) {
                        func_02049ae4(var79);
                        func_0204950c(var79);
                    }
                }
            }
        }
    }
    func_02048994();
    unsigned char* var85 = func_ov000_02160094((Struct_ov000_0215440c_2*)var4, 0);
    unsigned char* var86 = func_ov000_021600f8((Struct_ov000_0215440c*)var4, 0);
    if (var85 != 0 && var86 != 0) {
        unsigned char* var87 = (unsigned char*)var2->GetCombatantByIndex(*(unsigned short*)(var85 + 0x20));
        unsigned char* var88 = (unsigned char*)var2->GetCombatantByIndex(*(short*)(var86 + 0xe));
        if (var87 != 0 && var88 != 0) {
            unsigned int var89 = func_020493c8(var87);
            if (var89 >= 0x51) {
                var89 = func_020493a4(var87);
            }
            if (var89 < 0x51) {
                var16 = var89;
                func_ov000_0216f74c(&var15, &var16);
                var14 = var15;
                Struct_ov025_021e0638_4 var90;
                __clear(&var90, 0xc);
                var90.unknown_0_ = var14.unknown_0_[0];
                var90.unknown_8_ = var14.unknown_0_[1];
                Struct_ov025_021e0638_4 var91 = *(Struct_ov025_021e0638_4*)(var88 + 0x44);
                var91.unknown_4_ = 0;
                Struct_ov025_021e0638_10* var92 = func_020489b0();
                *(Vector3i*)&var92->unknown_0_ = *(Vector3i const*)&var90;
                *(Vector3i*)&var92->unknown_c_ = *(Vector3i const*)&var91;
                var92->unknown_18_ = ((Object3D*)var87)->GetRadius() >> 1;
                var92->unknown_1c_ = 1;
            }
        }
    }
    for (int var93 = 0; var93 < var0; var93++) {
        unsigned char* var94 = var5[var93].unknown_8_;
        if (func_02049ee8(var94) != 0 && func_02049444(var94) == 0 && func_02049ec0(var94) != 0
            && (*(unsigned int*)(*(unsigned char**)(var94 + 0x138) + 0x14) & 1) == 0 && arg0[Enum_ov025_021e0638_3704] != 0
            && func_02048c10(var94) == 0) {
            func_020494c0((Struct_02048f64_2*)var94);
        }
    }
}
