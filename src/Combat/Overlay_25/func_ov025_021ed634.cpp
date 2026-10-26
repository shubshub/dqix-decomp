#include "Resource/ActionDataTables.h"
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct Struct_ov025_021ed634 { char unknown_0_[0xc]; short unknown_c_; };
struct Struct_ov000_02159f7c;
struct Struct_020e4e38;
struct Struct_02054000;
struct Struct_020465c0;

struct Struct_ov000_0215440c {
    unsigned short unknown_0_;
    short unknown_2_;
    char unknown_4_[2];
    short unknown_6_;
    char unknown_8_;
    unsigned char unknown_9_;
};
struct Struct_ov000_0215440c_2;
struct Struct_ov000_0215440c_5 {
    char unknown_0_[0xe];
    short unknown_e_;
    char unknown_10_[8];
    unsigned char unknown_18_;
    char unknown_19_[4];
    unsigned char unknown_1d_0_ : 1;
};
struct Struct_ov000_0215440c_4 {
    char unknown_0_[0x18];
    float unknown_18_;
    char unknown_1c_[4];
    unsigned short unknown_20_;
};
struct Struct_ov025_021ebb90 {
    char unknown_0_[0x18];
    unsigned int unknown_18_0_ : 5;
    unsigned int unknown_18_5_ : 7;
};
struct Struct_ov025_021ed634_5 { char unknown_0_[0xc]; short unknown_c_; };
struct Struct_ov025_021ed634_6 { char unknown_0_[0x2c]; short unknown_2c_; };
struct Struct_ov025_021ed634_7 { char unknown_0_[0x18]; short unknown_18_; };
struct Struct_ov025_021ed634_8 { char unknown_0_[0x138]; unsigned char* unknown_138_; char unknown_13c_[0xc]; char* unknown_148_; char unknown_14c_[0x41]; unsigned char unknown_18d_; };

struct Struct_ov025_021e9fc4 {
    unsigned short unknown_0_[16];
    short unknown_20_[16];
    short unknown_40_[16];
    short unknown_60_[16];
    unsigned short unknown_80_[16];
    unsigned char unknown_a0_[16];
    Struct_ov025_021ed634* unknown_b0_[16];
    int unknown_f0_[16];
    char unknown_130_[0x24];
    short unknown_154_;
    char unknown_156_[2];
    int unknown_158_;
    char unknown_15c_[2];
    unsigned short unknown_15e_;
    unsigned short unknown_160_;
    unsigned short unknown_162_;
    Struct_ov000_0215440c* unknown_164_;
    void* unknown_168_;
    char unknown_16c_[0x40];
    unsigned short unknown_1ac_;
};

struct Struct_ov025_021ed634_2 {
    int unknown_0_;
    int unknown_4_;
    int unknown_8_;
    int unknown_c_;
    int unknown_10_;
    int unknown_14_;
    int unknown_18_;
    int unknown_1c_;
    int unknown_20_;
};
struct Struct_ov025_021ed634_3 { void* unknown_0_; void* unknown_4_; int unknown_8_; };
struct Struct_ov025_021ef020 { short unknown_0_[16]; };
struct Struct_ov025_021ed634_4 {
    unsigned char unknown_0_[0x30];
    unsigned char unknown_30_;
    unsigned char unknown_31_;
};

extern Struct_ov025_021ef020 data_ov025_021ef040;
extern Struct_ov025_021ef020 data_ov025_021ef060;
extern Struct_ov025_021ef020 data_ov025_021ef020;

int Check021ed2f4(void* obj);
void* MessageSystem_GetInstance(void);
extern "C" void func_02046380(void* obj);
extern "C" ARM void* __clear(void* dst, int count);
extern "C" void func_ov025_021ed1f0(void* self);
Node02160094* GetNodeAtIndex02160094(List02160094* list, int index);
Node021600f8* GetNodeAtIndex021600f8(List021600f8* list, int index);
void ShiftArrayDown_021ed2a0(char* self);
void* FindNodeAtDepth0215fff4(void* obj, int limit, int idx);
extern "C" short func_ov000_0215ffa0(void* obj);
void* GetField6b0_021b8470(void* obj);
int CheckAnyBitOrFlag_02159f7c(void* obj, Bits64_02159f7c* bits);
extern "C" int func_ov000_0215fd90(void* obj, int flag);
void StoreInArray0x8b0_020465c0(StoreStruct* base, int index, int value);
void NameText_InitFromPartyMember(void* obj, int id);
class GameObject;
GameObject* GetCombatantWithFlag0x400_0200fea4(GameState* gs, int id);
GameObject* GetCombatantWithFlag0x100_0200ff1c(GameState* gs, int id);
extern "C" void func_020e4ce8(void* dst, void* src, int flag);
void CopyStringToField0x3ac_02046504(char* g, char* s);
void SetByte0x1880_020464dc(void*, signed char);
void CopyStringToField042c_0204653c(void* g, char* s);
extern "C" int _Z22CheckKeyMatch_0215fb9cis(int obj, unsigned short id);
void BuildName020488ec(char* s);
void CopyStringToField046c_02046558(void* g, char* s);
Row02079e2c* SearchBothTables02079e2c(char* table, int key);
void InitObjFromPackedFields020e4e38(void* obj, Src020e4e38* src);
void CopyStringToField0x3ec_02046520(char* g, char* s);
void* GetActiveCombatWork_ov000_02160130(void);
char* GetOffsetPtr02160f08(void* w);
void* FindEntryById_021dafd0(char* obj, int id);
Sub18* GetActiveSub_02054000(Outer_02054000* o);
void NameText_Clear(void* p);
void DispatchIfCountPositive020dcf7c(int count, void* buf);
unsigned char GameState_GetPartyOrder(char*, void*);
extern "C" void* func_ov017_021b8478(void* obj);
int TestBitAt0x34_020a35e0(unsigned char* obj, unsigned char index);
char* GetFieldByKeyFromWork0x88_ov000_0216fcfc(void* work, int key);
extern "C" unsigned int strlen(const char* s);
extern "C" int sprintf(char* buf, const char* fmt, ...);
#if !defined(jpn)
extern "C" void func_0204500c(void* arg0, char* arg1, int arg2, int arg3);
#endif
extern "C" void func_02042b98(void* arg0, int arg1, int arg2, int arg3, int arg4);

#if defined(jpn)
extern "C" void func_020464e8(char*, char*);
extern "C" void func_02047410(void*, int);
extern "C" int func_ov025_021ed5a4(int, char*);
void* GetBoundedField156_02171674(void*, int);
void* GetBoundedField420_0217199c(void*, int);
struct Obj02046574;
void MessageSystem_SetStringArgument(Obj02046574*, int, char*);
extern "C" void func_020474a8(void*, int, char*, char*);
extern "C" void func_0204500c(void*, char*, int);
extern "C" void func_02043270(void*, int, int, int, int);
extern "C" char* strcpy(char*, const char*);
extern "C" char* strcat(char*, const char*);
extern char data_ov025_021efbfc[];
#endif

#if defined(jpn)
#define COPY_FIELD func_02046520
#define STATE_OFFSET 0x870
#else
#define COPY_FIELD func_0204653c
#define STATE_OFFSET 0x9a0
#endif

static inline int inline_ov025_021ed634(int arg0) { return arg0 >= 0 && arg0 <= 3; }
static inline int inline_ov025_021ed634_2(short arg0) { return arg0 >= 0 && arg0 <= 3; }
static inline int inline_ov025_021ed634_3(unsigned short arg0) { return arg0 >= 0 && arg0 <= 3; }

// USA: func_ov025_021ed634
extern "C" ARM void func_ov025_021ed634(Self021ed634* self) {
    if (Check021ed2f4(self) != 0) return;
    if (self->list == 0) return;
    GameState* gs = GameState::GetInstance();
    char* g = (char*)MessageSystem_GetInstance();
#if defined(jpn)

#else
    func_02046380(var1);
#endif
#if defined(jpn)
    char var2[0x100];
    char var8[0x100];
    Struct_ov025_021ef020 var13;
    Struct_ov025_021ef020 var14;
    Struct_ov025_021ef020 var15;
    char var3[0x40];
    char var4[0x40];
    char var5[0x24];
    char var17[1];
#else
    char var6[0x80];
    char var7[0x80];
    char var8[0x100];
    char var9[12];
    char var10[12];
    char var11[12];
    Struct_ov025_021ed634_3 var12;
    Struct_ov025_021ef020 var13;
    Struct_ov025_021ef020 var14;
    Struct_ov025_021ef020 var15;
    char var16[5];
    char var17[1];
#endif
    __clear(var17, 1);
    if (arg0->unknown_15e_ == 0) {
        int var18 = arg0->unknown_a0_[0];
        int var19 = arg0->unknown_0_[0];
        int var20 = arg0->unknown_20_[0];
        Struct_ov025_021ed634* var21 = arg0->unknown_b0_[0];
        short var22 = arg0->unknown_60_[0];
#if defined(jpn)
        int var23 = arg0->unknown_40_[0];
        int var24 = arg0->unknown_80_[0];
#else
        int var24 = arg0->unknown_80_[0];
        int var25 = arg0->unknown_40_[0];
#endif
        func_ov025_021ed1f0(arg0);
        if (var19 <= 0) return;
        Struct_ov000_0215440c_4* var26 = func_ov000_02160094((Struct_ov000_0215440c_2*)arg0->unknown_164_, 0);
        int var27 = 0;
        int var28 = 0;
        int var29 = 0;
        int var30 = 0;
        int var31 = 0;
        int var32 = inline_ov025_021ed634(var20) ? 1 : 0;
        var13 = data_ov025_021ef040;
        int var33[2];
        var33[0] = 0;
        var14 = data_ov025_021ef060;
        short var34;
        int var35 = 0;
        int var36 = 0;
        int var37 = arg0->unknown_164_->unknown_9_;
        if (arg0->unknown_164_->unknown_0_ == 0x61) {
            Struct_ov000_0215440c_5* var38 = func_ov000_021600f8(arg0->unknown_164_, 0);
            if (var38 != 0) {
                if (var38->unknown_1d_0_ == 0) var36 = 1;
            }
        }
        if (var36 != 0 || arg0->unknown_164_->unknown_0_ == 0x1b) {
            if (var21 != 0) var28 = var21->unknown_c_;
        } else if (var19 == 0x172) {
            var28 = arg0->unknown_f0_[0];
            func_ov025_021ed2a0((char*)arg0);
        } else if (arg0->unknown_164_->unknown_0_ == 0x3a6) {
            for (int var39 = 0; var39 < arg0->unknown_164_->unknown_9_; var39++) {
                Struct_ov000_0215440c_5* var40 = func_ov000_021600f8(arg0->unknown_164_, var39);
                if (var40 != 0 && var40->unknown_e_ == var20) {
                    for (int var41 = 0; var41 < var40->unknown_18_; var41++) {
                        Struct_ov025_021ed634* var42 = (Struct_ov025_021ed634*)func_ov000_0215fff4(var40, var41, 0);
                        if (var42 != 0 && var42->unknown_c_ >= 0) {
                            var28 = var42->unknown_c_;
                            var27++;
                            break;
                        }
                    }
                    if (var27 != 0) break;
                }
            }
        } else if (var18 == 3) {
            if (var21 != 0) {
                int var43 = var21->unknown_c_;
                if (var43 >= 0) { if (var43 > 0) var28 += var43; }
                else { var30 -= var43; var29++; }
            }
        } else {
            var15 = data_ov025_021ef020;
            var33[1] = 0;
            for (int var44 = 0; var44 < arg0->unknown_164_->unknown_9_; var44++) {
                Struct_ov000_0215440c_5* var45 = func_ov000_021600f8(arg0->unknown_164_, var44);
                if (var45 == 0) continue;
                var34 = func_ov000_0215ffa0(var45);
                if (inline_ov025_021ed634_2(var34) != 0) {
                    if (var32 == 0) continue;
                }
                if (inline_ov025_021ed634_2(var34) == 0) {
                    if (var32 != 0) continue;
                }
                for (int var46 = 0; var46 < var45->unknown_18_; var46++) {
                    Struct_ov025_021ed634* var47 = (Struct_ov025_021ed634*)func_ov000_0215fff4(var45, var46, 0);
                    if (var47 == 0) continue;
                    int var48 = var47->unknown_c_;
                    if (var48 >= 0) { if (var48 > 0) var28 += var48; }
                    else { var30 -= var48; var29++; }
                    void* var49 = func_ov017_021b8470(GetGameResources()->unknown_ptr_3718);
                    if (var47->unknown_c_ > 0) {
                        int var50 = 0;
                        for (int var51 = 0; var51 < var33[0]; var51++) {
                            if (var34 == var13.unknown_0_[var51]) { var50 = 1; break; }
                        }
                        if (var50 == 0) { var13.unknown_0_[var33[0]] = var34; var33[0]++; }
                    } else {
                        if (func_ov000_02159f7c(var49, (Struct_ov000_02159f7c*)var47) != 0 || func_ov000_0215fd90(var47, 4) != 0) {
                            int var52 = 0;
                            for (int var53 = 0; var53 < var35; var53++) {
                                if (var34 == var14.unknown_0_[var53]) { var52 = 1; break; }
                            }
                            if (var52 == 0) { var14.unknown_0_[var35] = var34; var35++; }
                        }
                    }
                    if (var32 == 0) {
                        if (func_ov000_0215fd90(var47, 2) != 0) {
                            int var54 = 0;
                            for (int var55 = 0; var55 < var33[1]; var55++) {
                                if (var34 == var15.unknown_0_[var55]) { var54 = 1; break; }
                            }
                            if (var54 == 0) { var15.unknown_0_[var33[1]] = var34; var33[1]++; var31++; }
                        }
                    }
                }
            }
        }
        if (var29 > 0) {
            int var56 = var30 / var29;
            if (var56 == 0 && var30 != 0) var56 = -1;
            #if defined(jpn)
func_02047410(var1, var56);
#else
func_020465c0((Struct_020465c0*)var1, 0, var56);
#endif
        } else if (var33[0] != 0) {
            int var57 = var28 / var33[0];
            if ((unsigned int)(var19 - 0x261) <= 1) var57 = var28;
            if (var57 == 0 && var28 != 0) var57 = 1;
            #if defined(jpn)
func_02047410(var1, var57);
#else
func_020465c0((Struct_020465c0*)var1, 0, var57);
#endif
        } else {
            #if defined(jpn)
func_02047410(var1, var28);
#else
func_020465c0((Struct_020465c0*)var1, 0, var28);
#endif
        }
        if (var18 == 5) {
            var20 = var13.unknown_0_[0];
            if (var20 < 0) {
                var20 = var14.unknown_0_[0];
                if (var20 < 0) {
                    Struct_ov000_0215440c_5* var58 = func_ov000_021600f8(arg0->unknown_164_, 0);
                    if (var58 != 0) var20 = func_ov000_0215ffa0(var58);
                }
            }
#if defined(jpn)
        }

#else
            if (IsValidId(v20)) {
                NameText_InitFromPartyMember(objA, v20);
            } else {
                GameObject* var59 = func_0200fea4(var0, var20);
                if (var59 != 0) {
                    func_020e4ce8(var10, var59, 1);
                    ((Struct_ov025_021ed634_2*)var1)->unknown_20_ = (int)var10;
                }
            }
            ((Struct_ov025_021ed634_2*)var1)->unknown_10_ = (int)var10;
        }

#endif
#if defined(jpn)
        func_020464e8((char*)var1, var17);
#else
        func_02046504((char*)var1, var17);
#endif
#if defined(jpn)
        if (var23 < 0) {
            if (var26 != 0) var23 = var26->unknown_20_;
        }
        if (var23 >= 0) {
            if (func_ov025_021ed5a4(var23, var3)) func_020464e8((char*)var1, var3);
            func_020464dc(var1, (signed char)var23);
        }

#else
        if (v40 < 0) {
            if (node != 0) v40 = node->s20;
            int b = IsValidId(v40) ? 1 : 0;
            if (b != 0) {
                NameText_InitFromPartyMember(objB, v40);
                ((Cur*)g)->f0 = (int)objB;
            } else {
                GameObject* var61 = func_0200fea4(var0, var25);
                if (var61 != 0) {
                    func_020e4ce8(var9, var61, 1);
                    ((Struct_ov025_021ed634_2*)var1)->unknown_0_ = (int)var9;
                }
            }
        }
        if (v40 >= 0) {
            SetByte0x1880_020464dc(g, (signed char)v40);
            int b = IsValidId(v40) ? 1 : 0;
            if (b != 0) {
                NameText_InitFromPartyMember(objB, v40);
                ((Cur*)g)->f0 = (int)objB;
            } else {
                GameObject* var63 = func_0200fea4(var0, var25);
                if (var63 != 0) {
                    func_020e4ce8(var9, var63, 1);
                    ((Struct_ov025_021ed634_2*)var1)->unknown_0_ = (int)var9;
                }
            }
        }

#endif
        if ((unsigned int)(var19 - 0xf1) <= 1) {
            int var64 = arg0->unknown_164_->unknown_6_;
            if (var64 >= 0) var20 = var64;
        }
        COPY_FIELD(var1, var17);
        if (func_ov000_0215fb9c((int)func_ov017_021b8470(GetGameResources()->unknown_ptr_3718), arg0->unknown_164_->unknown_0_) != 0) {
            Struct_ov025_021ed634_8* var65 = (Struct_ov025_021ed634_8*)func_0200fea4(var0, var20);
            if (var65 != 0) {
                var65->unknown_138_[0x25] = var65->unknown_18d_;
                func_020488ec((char*)var65);
                COPY_FIELD(var1, (char*)var65 + 0x14c);
            }
#if defined(jpn)

#else
            func_020e4ce8(var10, var65, 1);
            ((Struct_ov025_021ed634_2*)var1)->unknown_10_ = (int)var10;
#endif
        } else {
#if defined(jpn)
            if (func_ov025_021ed5a4(var20, var4)) func_02046520(var1, var4);
        }

#else
            if (IsValidId(v20)) {
                NameText_InitFromPartyMember(objA, v20);
            } else {
                GameObject* var66 = func_0200fea4(var0, var20);
                func_020e4ce8(var10, var66, 1);
            }
            if (var25 == var20) ((Struct_ov025_021ed634_2*)var1)->unknown_10_ = (int)var9;
            else ((Struct_ov025_021ed634_2*)var1)->unknown_10_ = (int)var10;
        }

#endif
        if (var19 == 0xf2 || var19 == 0x207) {
            Struct_ov025_021ed634_8* var67 = (Struct_ov025_021ed634_8*)func_0200fea4(var0, var20);
            if (var67 != 0 && var67->unknown_148_ != 0) COPY_FIELD(var1, var67->unknown_148_ + 0x2c);
        }
#if defined(jpn)
        func_0204653c(var1, var17);
#else
        func_02046558(var1, var17);
#endif
        Struct_02108e10* var68 = func_020797dc();
        Struct_ov000_0215440c* var69 = arg0->unknown_164_;
        Struct_ov025_021ebb90* var70;
        if (var69->unknown_0_ == 0x1f8 || var69->unknown_0_ == 0x3a9 || var69->unknown_0_ == 0x3a7 || var69->unknown_0_ == 0x3ac || var69->unknown_0_ == 0x3ad || var69->unknown_0_ == 0x392) {
            var70 = func_02079e2c((char*)var68, var69->unknown_2_);
        } else {
            var70 = func_02079e2c((char*)var68, (short)var69->unknown_0_);
        }
        if (var70 != 0) {
#if defined(jpn)
            func_0204653c(var1, *(char**)var70);
#else
            func_020e4e38(var11, (Struct_020e4e38*)var70);
            ((Struct_ov025_021ed634_2*)var1)->unknown_8_ = (int)var11;
            ((Struct_ov025_021ed634_2*)var1)->unknown_18_ = (int)var11;
#endif
        }
#if defined(jpn)
        func_02046504(var1, var17);
#else
        func_02046520(var1, var17);
#endif
#if defined(jpn)
        if (var26 != 0) {
            char* var71 = func_ov000_02160f08(func_ov000_02160130());
            int var72 = var26->unknown_20_;
            char* var73;
            if (inline_ov025_021ed634(var72)) {
                for (int var74 = 0; var74 < 4; var74++) {
                    if (*(int*)(var71 + 0x9a4 + var74 * 0x488) == var72) {
                        var73 = var71 + 0x958 + var74 * 0x488;
                        goto found_entry;
                    }
                }
            }
            var73 = 0;
found_entry:
            if (entry != 0) {
                void* a = GetBoundedField156_02171674(entry, *(signed char*)(entry + 0x20));
                void* b = GetBoundedField420_0217199c(entry, *(short*)(entry + 0x1e));
                if (*(signed char*)self->pad16c != 0) {
                    CopyStringToField0x3ac_02046504(g, self->pad16c);
                    if (*(short*)((char*)self->list + 4) != 0)
                        MessageSystem_SetStringArgument((Obj02046574*)g, 0, self->pad16c);
                } else if (a != 0) CopyStringToField0x3ac_02046504(g, *(char**)a);
                else if (b != 0) CopyStringToField0x3ac_02046504(g, *(char**)b);
            }
        }

#else
        if (var26 != 0) {
            char* var77 = func_ov000_02160f08(func_ov000_02160130());
            Struct_ov025_021ed634_6* var78 = (Struct_ov025_021ed634_6*)func_ov025_021dafd0(var77, var26->unknown_20_);
            if (inline_ov025_021ed634_3(var26->unknown_20_)) {
                int var79 = var78->unknown_2c_;
                if (arg0->unknown_1ac_ != 0) var79 = (short)arg0->unknown_1ac_;
                if (var19 == 0x257 || var19 == 0xc) {
                    GameObject* var80 = func_0200ff1c(var0, var26->unknown_20_);
                    if (var80 != 0) {
                        Struct_ov025_021ed634_7* var81 = func_02054000((Struct_02054000*)var80);
                        if (var81 != 0) var79 = var81->unknown_18_;
                    }
                }
                if (cnt > 0) {
                    NameText_Clear(&objD);
                    __clear(bufE, 0x80);
                    __clear(bufF, 0x80);
                    objD.a = bufE;
                    objD.b = bufF;
                    DispatchIfCountPositive020dcf7c(cnt, &objD);
                    ((Cur*)g)->f18 = (int)&objD;
                }
            }
        }

#endif
#if defined(jpn)
        if ((var19 == 9 && var31 >= 2) || (var19 == 4 && var35 >= 2) || (var19 == 7 && var35 >= 2)
            || (var70 != 0 && var70->unknown_18_5_ == 1 && var19 == 0x1b && var35 >= 2)) {
            strcpy(var5, var4);
            strcat(var5, data_ov025_021efbfc);
            func_02046520(var1, var5);
        }

#else
        if ((var19 == 9 && var31 >= 2) || (var19 == 4 && var35 >= 2) || (var19 == 7 && var35 >= 2)
            || ((var19 == 0xf0 || var19 == 0x209) && var37 >= 2)
            || (var70 != 0 && var70->unknown_18_5_ == 1 && (var19 == 0x20c || var19 == 0x11f || var19 == 0x11d || var19 == 0x20b) && var37 >= 2)
            || (var70 != 0 && var70->unknown_18_5_ == 1 && var19 == 0x1b && var35 >= 2)
            || (var70 != 0 && var70->unknown_18_5_ == 1 && var19 == 0x26d && var35 >= var37)) {
            *(var1 + 0x1000 + 0x9d7) = 1;
        }
        int n5 = GameState_GetPartyOrder((char*)gs, out);
        unsigned char positiveFlaggedEntries = 0;
        unsigned char flaggedEntries = 0;
        unsigned char* tb = (unsigned char*)func_ov017_021b8478(GetGameResources()->unknown_ptr_3718);
        char* ew = GetOffsetPtr02160f08(GetActiveCombatWork_ov000_02160130());
        for (int q = 0; q < n5; q++) {
            Entry021dafd0* e = (Entry021dafd0*)FindEntryById_021dafd0(ew, (unsigned char)out[q]);
            if (e != 0 && TestBitAt0x34_020a35e0(tb, out[q]) != 0) {
                ++flaggedEntries;
                if (e->v > 0) ++positiveFlaggedEntries;
            }
        }
        ((Struct_ov025_021ed634_4*)var1)->unknown_30_ = var84;
        ((Struct_ov025_021ed634_4*)var1)->unknown_31_ = var83;

#endif
        char* var89 = func_ov000_0216fcfc(arg0->unknown_168_, (short)var19);
        if (var89 == 0) return;
        if (strlen(var89) == 0) return;
#if defined(jpn)
        __clear(var2, 0x100);
#endif
        if (var19 == 0x205 || var19 == 0x1be || var19 == 0x1bf || var19 == 0x224 || var19 == 0x1c0 || var19 == 0x225 || var19 == 0x263
            || (unsigned int)(var19 - 0x266) <= 3) {
            __clear(var8, 0x100);
            void* var90 = func_ov017_021b8470(GetGameResources()->unknown_ptr_3718);
            if (var19 == 0x205) {
                sprintf(var8, var89, (double)var26->unknown_18_);
            } else if (var90 != 0) {
                sprintf(var8, var89, (double)*(float*)((char*)var90 + 0x8e3c));
            }
            if (var19 == 0x1bf || var19 == 0x224 || var19 == 0x1c0 || var19 == 0x225 || (unsigned int)(var19 - 0x264) <= 7) {
                Struct_ov025_021ed634_8* var91 = (Struct_ov025_021ed634_8*)func_0200fea4(var0, arg0->unknown_164_->unknown_6_);
                if (var91 != 0 && var91->unknown_148_ != 0) COPY_FIELD(var1, var91->unknown_148_ + 0x2c);
            }
#if defined(jpn)
            func_020474a8(var1, 0xc, var8, var2);
#else
            func_0204500c(var1, var8, 0, 0xe3);
#endif
        } else {
#if defined(jpn)
            func_020474a8(var1, 0xc, var89, var2);
#else
            func_0204500c(var1, var89, 0, 0xe3);
#endif
        }
#if defined(jpn)
        func_0204500c(var1, var2, 0);
        *(var1 + 0x17e1) = 0;
        *(int*)(var1 + 0x1730) = 0xc;
        *(int*)(var1 + 0x1734) = 0x12;
        func_02043270(var1, *(int*)(var1 + 0x1730), 0x92, 0x100, 0x30);
        *(var1 + 0x17e2) = 0;
        *(unsigned char*)(var1 + 0x1789) |= 2;
        *(var1 + 0x17f6) = 1;
        *(int*)(var1 + 0x868) = 1;
#else
        *(var1 + 0x1000 + 0x9b1) = 0;
        func_02042b98(var1, 2, 0x92, 0xfc, 0x4a);
        *(var1 + 0x1000 + 0x9b2) = 0;
        *(unsigned char*)(var1 + 0x1000 + 0x95b) |= 2;
        *(var1 + 0x1000 + 0x9c5) = 1;
        *(int*)(var1 + 0x998) = 1;
#endif
        arg0->unknown_160_ = arg0->unknown_162_;
        if (var24 != 0) arg0->unknown_160_ = var24;
        arg0->unknown_158_ = (int)var21;
        arg0->unknown_154_ = var22;
        arg0->unknown_15e_ = 1;
    } else if (arg0->unknown_15e_ == 1 && *(int*)(var1 + STATE_OFFSET) == 0) {
        unsigned int var92 = var0->GetEffectiveDeltaTime();
        unsigned int var93 = arg0->unknown_160_;
        if (var92 < var93) {
            arg0->unknown_160_ = var93 - var92;
        } else {
            arg0->unknown_160_ = 0;
            arg0->unknown_15e_ = 0;
            arg0->unknown_158_ = 0;
            arg0->unknown_154_ = 0;
        }
    }
}
