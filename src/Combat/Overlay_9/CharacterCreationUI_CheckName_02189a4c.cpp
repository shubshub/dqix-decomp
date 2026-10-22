#include <globaldefs.h>
#include <std_library_functions.h>
extern unsigned char data_0211e33c[0x30000] __attribute__((aligned(4)));
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"

struct Struct_ov009_02189a4c_2;
struct Struct_ov009_02189a4c_3;
extern "C" int func_ov009_0218a420(Struct_ov009_02189a4c_2*, Struct_ov009_02189a4c_3*);

struct Struct_ov009_02189a4c_3 {
    char* unknown_0_[5];
    signed char unknown_14_[5];
    unsigned char unknown_19_[5];
    unsigned char unknown_1e_;
    char unknown_1f_;
};
struct Struct_ov009_02189a4c_4 {
    unsigned int unknown_0_0_ : 12;
    unsigned int unknown_1_4_ : 19;
    unsigned int unknown_3_7_ : 1;
};
static inline unsigned int inline_ov009_02189a4c_4(unsigned int arg0, unsigned int arg1) {
    unsigned int var0 = arg1 - 1;
    return (arg0 + var0) & ~var0;
}
struct Struct_ov009_02189a4c_2 {
    Struct_ov009_02189a4c_4 unknown_0_;
    Struct_ov009_02189a4c_3* unknown_4_;
    char* unknown_8_;
};
struct Struct_ov009_02186e00 {
    char* unknown_0_;
    signed char unknown_4_;
    signed char unknown_5_0_ : 6;
    signed char unknown_5_6_ : 1;
    signed char unknown_5_7_ : 1;
    char unknown_6_[2];
};
struct Struct_020e0424 { unsigned int unknown_0_0_ : 12; unsigned int unknown_1_4_ : 20; };
struct Struct_01ff8b48_27 { int unknown_0_; char* unknown_4_; };
struct Struct_0201099c_3 : Struct_020e0424 { Struct_01ff8b48_27* unknown_4_; char* unknown_8_; };
struct Struct_0201099c_14 : Struct_0201099c_3 { short unknown_c_; short unknown_e_; int unknown_10_; void* unknown_14_; };
struct Struct_ov009_02189a4c_5 {
    Struct_0201099c_14 unknown_0_;
    Struct_ov009_02189a4c_2 unknown_18_;
    void* unknown_24_;
    unsigned short unknown_28_;
    char unknown_2a_[4];
    unsigned char unknown_2e_, unknown_2f_, unknown_30_, unknown_31_, unknown_32_;
    unsigned char unknown_33_, unknown_34_, unknown_35_, unknown_36_, unknown_37_, unknown_38_;
    unsigned char unknown_39_[3];
    inline Struct_ov009_02189a4c_2* inline_ov009_02189a4c_5() { return &unknown_18_; }
};
struct Struct_ov009_021842a0_2 {
    char unknown_0_[0xfc];
    Struct_ov009_02189a4c_5 unknown_fc_;
    char unknown_138_[0xd9c - 0x138];
    unsigned int unknown_d9c_;
    char unknown_da0_[3];
    unsigned char unknown_da3_;
    char unknown_da4_[0xc];
    char** unknown_db0_;
    char unknown_db4_[4];
};
struct Struct_ov009_02189a4c {
    short unknown_0_;
    short unknown_2_;
    unsigned char unknown_4_;
    unsigned char unknown_5_;
};
extern const char* data_020f285c;
extern const char* data_020f2858;
extern char data_ov009_0218aca0[];
extern "C" void func_ov009_021847ec(Struct_ov009_02189a4c_5*);
extern "C" void func_020dfc40(Struct_0201099c_14*);
extern "C" int func_020e038c(void*, void*, int);
extern "C" int func_ov009_0218a420(Struct_ov009_02189a4c_2*, Struct_ov009_02189a4c_3*);
extern "C" void __clear(void*, unsigned int);
CharacterInfo* Font_FindCharacter(int, int);
void ToUpperCopy0218a484(int, char*, char*);
unsigned int GetLow12Bits020e0424(Header020e0424*);
int GetFieldByKey020e0434(Container020e0310*, int);
int FindEntryIndexByKey020424e4(int, int);
CharacterInfo* GetBoundedEntry020425b4(int, int);
extern "C" int func_020426bc(const char*, unsigned char*, int);
extern "C" int func_ov009_0218a4c8(int, int, int, int, int);
extern "C" int func_ov009_0218a518(Struct_ov009_02189a4c_5*, const unsigned char*, const unsigned char*, int, int);

static inline Struct_ov009_02189a4c_3* inline_ov009_02189a4c(const Struct_ov009_02189a4c_2* arg0) { return arg0->unknown_4_; }
static inline int inline_ov009_02189a4c_2(const Struct_ov009_02189a4c_2* arg0) { return arg0->unknown_0_.unknown_0_0_; }

static inline unsigned int inline_ov009_02189a4c_3(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3) {
    unsigned int var0 = inline_ov009_02189a4c_4(arg2, arg3);
    unsigned int var1 = arg1 * var0;
    return arg0 + var1;
}

// Overlay 9, originally func_ov009_02189a4c (USA/EUR 0x02189a4c; JPN not identified)
extern "C" ARM void CharacterCreationUI_CheckName(CharacterCreation* self) {
    int i;
    ForbiddenWordPattern* headerPattern;
    int headerCount;
    NameSpan work_spans_[30];
    char work_normalized_[512];
    unsigned char work_tokens_[128];
    unsigned char work_patterns_[5][64];
    char work_exactName_[64];
    char work_exactCharacter_[12];
    char work_character_[12];
    unsigned int work_fileSize_[2];
    char* name = self->names_[self->sex_];
    if (!*name) return;
    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();
        func_ov009_021847ec((&arg0->unknown_fc_));
    var10[0] = 0;
    var10[1] = 0;
    LoadFileIntoMemory(data_020f285c, data_0211e33c, &var10[0]);
    unsigned int var12 = (var10[0] + 511) & ~511;
    LoadFileIntoMemory(data_020f2858, data_0211e33c + var12, &var10[1]);
    func_020dfc40(&arg0->unknown_fc_.unknown_0_);
    func_020e038c((&arg0->unknown_fc_), data_0211e33c + var12, var10[1]);
    memset((&arg0->unknown_fc_.unknown_18_), 0, 12);
    unsigned char* var13 = data_0211e33c;
    if (var13) {
        memcpy((&arg0->unknown_fc_.unknown_18_), data_0211e33c, 4);
        unsigned int var14 = inline_ov009_02189a4c_4(sizeof(Struct_ov009_02189a4c_4), 4);
        unsigned char* var15 = data_0211e33c;
        arg0->unknown_fc_.unknown_18_.unknown_4_ = (Struct_ov009_02189a4c_3*)(var15 + var14);
        unsigned int var16 = inline_ov009_02189a4c_3(0, arg0->unknown_fc_.unknown_18_.unknown_0_.unknown_0_0_, sizeof(Struct_ov009_02189a4c_3), 4);
        arg0->unknown_fc_.unknown_18_.unknown_8_ = (char*)(var15 + (var14 + var16));
        unsigned int var17 = (&arg0->unknown_fc_.unknown_18_)->unknown_0_.unknown_3_7_;
        if (!var17) {
            const Struct_ov009_02189a4c_2* var18 = &arg0->unknown_fc_.unknown_18_;
            var1 = inline_ov009_02189a4c(var18);
            if (var1) {
                var2 = inline_ov009_02189a4c_2(var18);
                int (*var19)(Struct_ov009_02189a4c_2*, Struct_ov009_02189a4c_3*);
                if (var2 && (var19 = func_ov009_0218a420) != 0) {
                    for (var0 = 0; var0 < var2; ++var0, ++var1) func_ov009_0218a420(arg0->unknown_fc_.inline_ov009_02189a4c_5(), var1);
                }
            }
            (&arg0->unknown_fc_.unknown_18_)->unknown_0_.unknown_3_7_ = 1;
            ((Struct_ov009_02189a4c_4*)data_0211e33c)->unknown_3_7_ = 1;
        }
    }
    (&arg0->unknown_fc_)->unknown_24_ = 0;
    (&arg0->unknown_fc_)->unknown_28_ = 0;
    if (var10[1]) {
        (&arg0->unknown_fc_)->unknown_24_ = data_0211e33c + var12;
        (&arg0->unknown_fc_)->unknown_28_ = var10[1];
    }
    int var20;
    int var21;
    {
__clear(var7, 64);
    char* var22 = var7;
    char* var23 = var11;
    for (;;) {
        if (!*in) break;
        CharacterInfo* entry = Font_FindCharacter((int)in, 1);
        __clear(work_exactCharacter_, 12);
        int length = entry->length_;
        char* text = entry->text_;
        if (entry->uppercase_) {
            ToUpperCopy0218a484((int)(&self->syntax_), text, work_exactCharacter_);
            text = work_exactCharacter_;
        }
        memcpy(var22, var26, var25);
        var23 += var25;
        var22 += var25;
    }
    int var27 = strlen(var7);
    int var28;
    int var29 = func_020e0424(&arg0->unknown_fc_.unknown_0_);
    for (var28 = 0; var28 < var29; ++var28) {
        char* var30 = (char*)func_020e0434(&arg0->unknown_fc_.unknown_0_, (short)var28);
        if (var30 && *var30) {
            int var31 = strlen(var30);
            if (var31 == var27 && strcmp(var30, var7) == 0) { var21 = 1; goto exact_done; }
        }
    }
    var21 = 0;

    }
exact_done:
    if (var21) {
        var20 = 1;
        goto finished;
    }
    int var32;
    Struct_ov009_02189a4c* var33;
    int var34;
    __clear(var3, 180);
    __clear(var4, 512);
    __clear(var5, 128);
    {
    int var35;
    int var36;
    unsigned char var37;
    unsigned char var38;
    unsigned char var39;
    unsigned char var40;
    var40 = arg0->unknown_fc_.unknown_32_;
    var39 = arg0->unknown_fc_.unknown_33_;
    var38 = arg0->unknown_fc_.unknown_34_;
    var37 = arg0->unknown_fc_.unknown_35_;
    var36 = arg0->unknown_fc_.unknown_38_;
    var35 = arg0->unknown_fc_.unknown_37_;
    char* var41 = var4;
    for (;;) {
        if (!*var11) break;
        int var42 = func_020424e4((int)var11, 1);
        Struct_ov009_02186e00* var43 = func_020425b4(var42, 1);
        if (!var43) goto fallback_character;
        if (((var42 >= 8 && var42 <= 69) || var42 == 77 || var42 == 83 ||
                      (var42 >= 120 && var42 <= 169) || var42 == var40 || var42 == var38 ||
                      var42 == var37 || var42 == 107 || var42 == var36)) {
            int var44 = var43->unknown_5_0_;
            if (var42 == 107) var43 = func_020425b4(var39, 1);
            __clear(var9, 12);
            int var45 = var43->unknown_5_0_;
            char* var46 = var43->unknown_0_;
            if (var43->unknown_5_7_) {
                func_ov009_0218a484((int)(&arg0->unknown_fc_), var46, var9);
                var46 = var9;
            }
            if (var42 >= 120 && var42 <= 169) {
                int var47 = var46[1];
                if ((var47 >= 'A' && var47 <= 'Z') || (var47 >= 'a' && var47 <= 'z')) {
                    if (var47 != 's') goto copy_character;
                }
                var47 = var46[2];
                if (var47 >= 'a' && var47 <= 'z') var47 = (char)(var47 - 32);
                memset(var9, 0, 12);
                var9[0] = var47;
                var46 = var9;
                var45 = 1;
            }
        copy_character:
            memcpy(var41, var46, var45);
            var11 += var44;
            var41 += var45;
        } else if (var42 == var35) {
            int var48 = var43->unknown_5_0_;
            memcpy(var41, data_ov009_0218aca0, 1);
            var11 += var48;
            var41++;
        } else {
        fallback_character:
            int var49 = 1;
            if (var43) {
                var49 = var43->unknown_5_0_;
                *var41 = ',';
            } else *var41 = ' ';
            var11 += var49;
            ++var41;
        }
    }
    }
    short var50;
    Struct_ov009_02189a4c_3* var51;
    int var52;
    Struct_ov009_02189a4c* var53;
    int var54;
    func_020426bc(var4, var5, 1);
    var54 = 0;
    unsigned int var55;
    Struct_ov009_02189a4c* var56;
    unsigned char* var57;
    int var58;
    int var59;
    var56 = var3;
    var59 = (&arg0->unknown_fc_)->unknown_36_;
    var57 = var5;
    var58 = var54;
    var52 = var54;
    for (;;) {
        var55 = *var57;
        if (var56->unknown_5_) {
            if (var55 == 0 || var55 == 255 || var55 == var59) {
                var52++;
                var56->unknown_2_ = var58 - var56->unknown_0_;
                var56->unknown_4_ = var55 == 255 ? 1 : 0;
                var56->unknown_5_ = 0;
                var56++;
            }
        } else {
            if (var55 != 0 && var55 < 255 && var55 != var59) {
                var56->unknown_0_ = var58;
                var56->unknown_5_ = 1;
            }
            if (var55 == var59 && var52 != 0) (var3 + (var52 - 1))->unknown_4_ = 0;
        }
        if (var56->unknown_5_ && var54 == 18) {
            var52++;
            var56->unknown_2_ = var58 - var56->unknown_0_ + 1;
            var56->unknown_4_ = 1;
            var56++;
        }
        if (!var55) break;
        var54++;
        var57++;
        var58++;
        if (var54 == 19) var54 = 0;
    }
    int var60;
    Struct_ov009_02189a4c* var61 = var3;
    var60 = (&arg0->unknown_fc_)->unknown_36_;
    for (int var62 = 0; var62 < var52 - 1; ++var62, ++var61) {
        unsigned char* var63;
        int var64 = var61->unknown_0_ + var61->unknown_2_;
        var54 = var61[1].unknown_0_;
        var61->unknown_4_ = 1;
        var63 = var5 + var64;
        while (var64 < var54) {
            if (var60 == *var63) { var61->unknown_4_ = 0; break; }
            ++var64;
            ++var63;
        }
    }
    int var65 = (signed char)(&arg0->unknown_fc_)->unknown_36_;
    for (int var66 = 0; var66 < 128; ++var66) {
        if (var65 == (signed char)var5[var66]) ((char*)var5)[var66] = -1;
    }
    var32 = (short)arg0->unknown_fc_.unknown_18_.unknown_0_.unknown_0_0_;
    for (var50 = 0; var50 < var32; ++var50) {
        var51 = (&arg0->unknown_fc_.unknown_18_)->unknown_4_ + var50;
        var33 = var3;
        __clear(var6, 320);
        for (int var67 = 0; var67 < var51->unknown_1e_; ++var67) {
            func_020426bc(var51->unknown_0_[var67], var6[var67], 1);
            var51->unknown_0_[var67] = (char*)var6[var67];
        }
        var34 = var52 - var51->unknown_1e_ + 1;
        for (int var68 = 0; var68 < var34; ++var68, ++var33) {
            int var69;
            {
                var53 = var33;
                unsigned char* var70 = var5;
int var71 = var51->unknown_1e_;
    int var72 = var71 - 1;
    for (var54 = 0; var54 < var71; ++var54, ++var53) {
        if (var54 < var72 && !var53->unknown_4_) { var69 = 0; goto match_done; }
        int var73;
        int var74 = var51->unknown_14_[var54];
        int var75 = var53->unknown_2_;
        int var76 = var75 - var74 + 1;
        var73 = var51->unknown_19_[var54];
        int var77 = (int)var51->unknown_0_[var54];
        switch (var73) {
        case 0:
            if (var74 != var75) { var69 = 0; goto match_done; }
            if (!func_ov009_0218a4c8((int)(&arg0->unknown_fc_), var77, (int)(var70 + var53->unknown_0_), var74, 1)) { var69 = 0; goto match_done; }
            break;
        case 3:
            if (var75 < var74) { var69 = 0; goto match_done; }
            if (!func_ov009_0218a4c8((int)(&arg0->unknown_fc_), var77, (int)(var70 + var53->unknown_0_), var74, 1)) { var69 = 0; goto match_done; }
            break;
        case 2:
            if (var75 < var74) { var69 = 0; goto match_done; }
            if (!func_ov009_0218a4c8((int)(&arg0->unknown_fc_), var77, (int)(var70 + (var53->unknown_0_ + var53->unknown_2_ - var74)), var74, 1)) { var69 = 0; goto match_done; }
            break;
        case 1:
            if (var75 < var74) { var69 = 0; goto match_done; }
            if (!func_ov009_0218a4c8((int)(&arg0->unknown_fc_), var77, (int)(var70 + var53->unknown_0_), var74, var76)) { var69 = 0; goto match_done; }
            break;
        case 4:
            if (var74 != var75) { var69 = 0; goto match_done; }
            if (!func_ov009_0218a518((&arg0->unknown_fc_), (unsigned char*)var77, var70 + var53->unknown_0_, var74, 1)) { var69 = 0; goto match_done; }
            break;
        case 7:
            if (var75 < var74) { var69 = 0; goto match_done; }
            if (!func_ov009_0218a518((&arg0->unknown_fc_), (unsigned char*)var77, var70 + var53->unknown_0_, var74, 1)) { var69 = 0; goto match_done; }
            break;
        case 6:
            if (var75 < var74) { var69 = 0; goto match_done; }
            if (!func_ov009_0218a518((&arg0->unknown_fc_), (unsigned char*)var77, var70 + (var53->unknown_0_ + var53->unknown_2_ - var74), var74, 1)) { var69 = 0; goto match_done; }
            break;
        case 5:
            if (var75 < var74) { var69 = 0; goto match_done; }
            if (!func_ov009_0218a518((&arg0->unknown_fc_), (unsigned char*)var77, var70 + var53->unknown_0_, var74, var76)) { var69 = 0; goto match_done; }
            break;
        }
    }
    var69 = 1;

            }
match_done:
            if (var69) {
                var20 = 1;
                goto finished;
            }
        }
    }
    var20 = 0;
finished:
    BackgroundLoader::RemoveLockGlobal();
    if (var20) arg0->unknown_d9c_ |= 0x400000;
    else arg0->unknown_d9c_ |= 0x800;
}
