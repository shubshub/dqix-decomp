#include "Resource/ActionDataTables.h"
#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"
#include "Graphics/LightingManager.h"
#include "NitroSDK/Matrix.h"
#include "Resource/GameResources.h"

#if defined(jpn)
enum { Enum_ov025_021d8c30_336 = 0x144, Enum_ov025_021d8c30_2540 = 0x968, Enum_ov025_021d8c30_2528 = 0x95c, Enum_ov025_021d8c30_2086 = 0x7a2, Enum_ov025_021d8c30_1224 = 0x444, Enum_ov025_021d8c30_1220 = 0x440, Enum_ov025_021d8c30_3768 = 0xe34, Enum_ov025_021d8c30_3752 = 0xe24, Enum_ov025_021d8c30_1232 = 0x44c, Enum_ov025_021d8c30_1226 = 0x446, Enum_ov025_021d8c30_672 = 0x21c, Enum_ov025_021d8c30_1132 = 0x3e8, Enum_ov025_021d8c30_396 = 0x180, Enum_ov025_021d8c30_3208 = 0xc04, Enum_ov025_021d8c30_14176 = 0x371c, Enum_ov025_021d8c30_28238 = 0x703e, Enum_ov025_021d8c30_28414 = 0x70ee, Enum_ov025_021d8c30_28632 = 0x71c8, Enum_ov025_021d8c30_28648 = 0x71d8, Enum_ov025_021d8c30_30532 = 0x7934, Enum_ov025_021d8c30_30533 = 0x7935, Enum_ov025_021d8c30_30534 = 0x7936, Enum_ov025_021d8c30_28636 = 0x71cc, Enum_ov025_021d8c30_28668 = 0x71ec, Enum_ov025_021d8c30_680 = 0x224, Enum_ov025_021d8c30_2192 = 0x80c, Enum_ov025_021d8c30_3096 = 0xb94, Enum_ov025_021d8c30_3640 = 0xdb4 };
#else
enum { Enum_ov025_021d8c30_336 = 0x150, Enum_ov025_021d8c30_2540 = 0x9ec, Enum_ov025_021d8c30_2528 = 0x9e0, Enum_ov025_021d8c30_2086 = 0x826, Enum_ov025_021d8c30_1224 = 0x4c8, Enum_ov025_021d8c30_1220 = 0x4c4, Enum_ov025_021d8c30_3768 = 0xeb8, Enum_ov025_021d8c30_3752 = 0xea8, Enum_ov025_021d8c30_1232 = 0x4d0, Enum_ov025_021d8c30_1226 = 0x4ca, Enum_ov025_021d8c30_672 = 0x2a0, Enum_ov025_021d8c30_1132 = 0x46c, Enum_ov025_021d8c30_396 = 0x18c, Enum_ov025_021d8c30_3208 = 0xc88, Enum_ov025_021d8c30_14176 = 0x3760, Enum_ov025_021d8c30_28238 = 0x6e4e, Enum_ov025_021d8c30_28414 = 0x6efe, Enum_ov025_021d8c30_28632 = 0x6fd8, Enum_ov025_021d8c30_28648 = 0x6fe8, Enum_ov025_021d8c30_30532 = 0x7744, Enum_ov025_021d8c30_30533 = 0x7745, Enum_ov025_021d8c30_30534 = 0x7746, Enum_ov025_021d8c30_28636 = 0x6fdc, Enum_ov025_021d8c30_28668 = 0x6ffc, Enum_ov025_021d8c30_680 = 0x2a8, Enum_ov025_021d8c30_2192 = 0x890, Enum_ov025_021d8c30_3096 = 0xc18, Enum_ov025_021d8c30_3640 = 0xe38 };
#endif

struct Struct_ov000_0215440c_2;
struct Struct_ov000_02160094 {
    char unknown_0_[0x20];
    unsigned short unknown_20_;
};

struct Struct_ov000_0215440c;
struct Struct_ov000_021600f8 {
    char unknown_0_[0xe];
    short unknown_e_[3];
    unsigned char unknown_14_[3];
    unsigned char unknown_17_;
    unsigned char unknown_18_[4];
    unsigned char unknown_1c_0_ : 7;
    unsigned char unknown_1c_7_ : 1;
};

struct Struct_ov000_0215feb4;

struct Struct_ov025_021d8c30 {
    unsigned long long unknown_0_;
    char unknown_8_[4];
    short unknown_c_;
    short unknown_e_;
    short unknown_10_;
    short unknown_12_;
    short unknown_14_;
    char unknown_16_[2];
    unsigned int unknown_18_;
    unsigned char unknown_1c_;
    unsigned char unknown_1d_;
    unsigned char unknown_1e_;
};

struct Struct_ov025_021d8c30_2 {
    char unknown_0_[0xc];
    short unknown_c_;
    char unknown_e_[0x12];
    struct Struct_ov025_021d8c30_2* unknown_20_;
};

struct Struct_ov025_021d8c30_3 {
    struct Struct_ov025_021d8c30_2* unknown_0_[3];
    char unknown_c_[0xc];
    unsigned char unknown_18_[3];
    char unknown_1b_[5];
    struct Struct_ov025_021d8c30_3* unknown_20_;
};

struct Struct_ov025_021d8c30_4 {
    unsigned short unknown_0_;
    char unknown_2_[7];
    unsigned char unknown_9_;
    char unknown_a_;
    unsigned char unknown_b_0_ : 3;
    unsigned char unknown_b_3_ : 1;
    unsigned char unknown_b_4_ : 1;
    unsigned char unknown_b_5_ : 3;
    char unknown_c_[8];
    struct Struct_ov025_021d8c30_3* unknown_14_;
    char unknown_18_[0xa];
    unsigned short unknown_22_;
    unsigned short unknown_24_;
};

struct Struct_ov025_021d8c30_5 {
    char unknown_0_[0x14];
    unsigned int unknown_14_0_ : 28;
    unsigned int unknown_17_4_ : 4;
    unsigned int unknown_18_0_ : 12;
    unsigned int unknown_19_4_ : 4;
    unsigned int unknown_1a_0_ : 16;
};

struct Struct_ov025_021d8c30_6 {
    char unknown_0_[0x10];
    unsigned int unknown_10_0_ : 31;
    unsigned int unknown_13_7_ : 1;
    char unknown_14_[0x10];
    unsigned int unknown_24_0_ : 28;
    unsigned int unknown_27_4_ : 1;
    unsigned int unknown_27_5_ : 3;
};

struct Struct_ov025_021d8c30_7 {
    unsigned char unknown_0_0_ : 4;
    unsigned char unknown_0_4_ : 4;
};

struct Struct_ov025_021d8c30_8 {
    unsigned short unknown_0_;
    short unknown_2_;
};

struct Struct_ov025_021d8c30_9 {
    void* unknown_0_;
    int unknown_4_;
    int unknown_8_;
    int unknown_c_;
    int unknown_10_;
    unsigned char unknown_14_;
    unsigned char unknown_15_[3];
    short unknown_18_;
    short unknown_1a_;
    int unknown_1c_;
};

struct Struct_ov025_021d8c30_10 {
    unsigned int unknown_0_;
    unsigned int unknown_4_;
    unsigned int unknown_8_;
    unsigned int unknown_c_;
    unsigned int unknown_10_;
    unsigned char unknown_14_;
    unsigned char unknown_15_[3];
    short unknown_18_;
    short unknown_1a_;
};

struct Struct_ov025_021d8c30_11 {
    unsigned int unknown_0_;
    unsigned int unknown_4_;
    unsigned int unknown_8_;
    unsigned int unknown_c_;
    unsigned int unknown_10_;
    unsigned char unknown_14_;
};

struct Struct_02078398_2 {
    unsigned char unknown_0_;
    unsigned char unknown_1_[0xf];
    unsigned char unknown_10_;
    unsigned char unknown_11_;
    short unknown_12_;
    short unknown_14_;
    short unknown_16_;
    short unknown_18_;
    short unknown_1a_;
    short unknown_1c_;
    short unknown_1e_;
    int unknown_20_;
    int unknown_24_;
    int unknown_28_;
    Vector3fix unknown_2c_;
    Vector3fix unknown_38_;
    Vector3fix unknown_44_;
};

struct SePlayer;
struct Obj0203a48c;
struct Vec3Int0203a48c;
struct Obj0203a588;
struct ShortPair0xba0xbc;
struct Struct5e00;
struct Bytes02033b88;
struct Obj02176134;
struct Obj02176150;

extern "C" void* LinkSession_GetInstance(void);
struct Obj0203a588* NumberPopups_GetInstance(void);
int GetField02163524(void* obj);
void* SearchBothTables02079e2c(char* p, int key);
unsigned char GetByte_021dcc64_021dcc64(void* obj);
ListNode021600f8* GetNodeAtIndex021600f8(List021600f8* list, int index);
void AppendRow_021dcc70(char* obj, char* src);
void AppendSlotEntry_021dcde8(unsigned char* obj, struct FiveWordsAndByte_021dcd28* src);
ListNode02160094* GetNodeAtIndex02160094(List02160094* list, int index);
struct ListNode0215feb4* GetNodeAtIndex0215feb4(char* base, int threshold, int slot);
extern "C" int func_ov000_0215ffa0(void* node);
void* FindNodeAtDepth0215fff4(void* obj, int limit, int idx);
void SetOrInitField_02182498(void* objRaw, int flag);
extern "C" int strcmp(const char* a, const char* b);
extern "C" void func_ov025_021eaf48(unsigned char* obj, int idx, int category, int entry);
extern "C" void func_ov025_021ea604(unsigned char* obj, int idx, int category, int entry);
extern "C" void func_ov000_02162dc4(unsigned char* sl, GameObject* lead, GameObject* actor, unsigned int flags,
                                    int b1d, int b1e, unsigned long long mask, int zero);
void ClearSubstructFlag0x4_02049ae4(unsigned char* obj);
void SetPosAndFields0216f1e4(void* obj, int* srcVec3, int a, int b);
void Camera_Shake(unsigned char* obj, int a, int b);
void SetShortTriple0x6e44_ov000_02163440(void* obj, short a, unsigned short b, unsigned short c);
void Forward0205ec20(void* obj, void* target, int arg);
void SePlayer_Play(struct SePlayer* obj, int a, int b);
GameObject* GetCombatantWithFlag0x400_0200fea4(GameState* battleStruct, int combatantId);
extern "C" int func_ov025_021ed444(char* obj, int id, int val2, int type, int val3, short val4, unsigned short val5);
extern "C" int func_ov025_021ed380(char* obj, int id, int val2, int type, int val3, short val4, unsigned short val5);
extern "C" void* func_02057924(void);
void InitStruct02078484(struct InitStruct02078484Struct* p);
void FindNodeAndProcess02057fb4(void* list, int id, void* config);
int TestBit0At0x2f4_02085078(unsigned char* obj);
int TestBit1At0x2f4_020850a4(unsigned char* obj);
extern "C" int func_ov000_0215fd90(void* entry, int effect);
void GameObject_Shake(ShortPair0xba0xbc* obj, short a, unsigned short b);
void* GetActiveCombatWork_ov000_02160130(void);
void* GetOffsetPtr02160f08(void* obj);
void* FindEntryById_021dafd0(char* obj, int id);
extern "C" void func_ov000_0217616c(void* p);
void SetSubstructWord0x68_0204a00c(unsigned char* obj, int value);
void NumberPopups_Add(Obj0203a48c*, int, Vec3Int0203a48c*, int, int, int);
void SetSubstructByte0x56_02049f28(unsigned char* obj);
void CopyObjectFields02048588(unsigned char* self, unsigned char* dst);
void AllocateSlotAndConfigureField02166784(struct Struct5e00* obj1, unsigned char* obj2, unsigned char* obj3);
extern "C" void func_ov000_021677fc(void* p);
int GameObject_ForceMotionState(struct Bytes02033b88* p, int val);
int GetSubstructByte0x56_02049ee8(unsigned char* obj);
void ResetCombatantSlot020d7334(unsigned char* base, int index);
void ClearSubstructByte0x56_02049f3c(unsigned char* obj);
void ClearBitIfValueFound02167434(unsigned char* obj, int value);
extern "C" void func_ov017_02191aac(char* obj, int mode, int idx, unsigned char mask);
extern "C" void func_02054028(void* obj, int n);
void SetMainBrightness(GameResources* resources, int brightness, int duration);
void SePlayer_PlayExtra(void* obj, int a, int b);
extern "C" void func_ov000_021823dc(unsigned char* obj, int val);
int IsCombatantStateSpecial02163c0c(void* unused, int id);
extern "C" void* __clear(void* dst, int count);
void SetShortField0xC02176134(struct Obj02176134* obj, short val);
void SetShortField0xE02176150(struct Obj02176150* obj, short val);
void SetByteField37_0216ff20(char* obj, unsigned char val);
int GameState_GetProtagonistIndex(GameState* battleStruct);
extern "C" void func_ov017_021c9d2c(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8);

extern struct SePlayer g_sePlayer;
extern char data_ov025_021ef3d0[];
extern char data_ov025_021ef3d5[];
extern char data_ov025_021ef3e0[];
extern char data_ov025_021ef3e8[];
extern char data_ov025_021ef3ef[];
extern char data_ov025_021ef3f5[];
extern char data_ov025_021ef3fc[];
extern const int data_ov025_021eeea4[];
extern const int data_ov025_021eeebc[];

static inline int inline_ov000_02169850(int arg0) {
    return arg0 >= 0 && arg0 <= 3;
}

static inline int inline_ov000_02156cc4_2(unsigned short arg0) {
    return arg0 <= 3;
}

static inline unsigned char* inline_01ff91ac_3(Struct_ov000_021600f8* arg0) {
    return arg0->unknown_14_;
}

static inline int inline_ov025_021d8c30(int arg0) {
    return data_ov025_021eeea4[arg0];
}

static inline int inline_ov025_021d8c30_2(int arg0) {
    return data_ov025_021eeebc[arg0];
}

static inline fix32_t inline_ov025_021d8c30_3(fix32_t arg0, fix32_t arg1) {
    return FIX32_MULTIPLY(arg0, arg1);
}

static inline Vector3fix inline_ov025_021d8c30_4(void* arg0) {
    return *(Vector3fix*)((unsigned char*)arg0 + Enum_ov025_021d8c30_28636);
}

// USA: func_ov025_021d8c30
extern "C" ARM int func_ov025_021d8c30(unsigned char* arg0, struct Struct_ov025_021d8c30_4* arg1, int arg2, int arg3,
                                        int arg4, int arg5, unsigned char arg6) {
    Struct_ov000_02160094* var0;
    GameState* var1;
    char* var2;
    unsigned char* var3;
    struct Struct_0203a48c_3* var4;
    int var5;
    struct Struct_ov025_021d8c30_5* var6;
    int var7;
    int var8;
    int var9;
    int var10;
    int var11;
    int var12;
    GameObject* var13;
    Struct_ov000_02160094* var14;
    int var15;
    int var16;
    GameObject* var17;
    unsigned char var18;
    int var19;
    int var20;
    int var21;
    int var22;
    int var23;
    int var24;
    GameObject* var25;
    int var26;
    int var27;
    void* var28;
    int var29;
    unsigned char var30;
    int var31;
    unsigned char var32;
    unsigned char var33;
    unsigned char var34;
    int var35;
    void* var36;
    int var37;
    int var38;
    int var39;
    int var40;
    int var41;
    struct Struct_ov025_021d8c30_8* var42;
    int var43;
    int var44;
    int var45;
    unsigned char var46;
    bool var47;

    battle = GameState::GetInstance();
    ov17 = (char*)GetGameResources();
    LinkSession_GetInstance();
    camera = (unsigned char*)battle->GetCamera();
    popups = (struct Obj0203a48c*)NumberPopups_GetInstance();
    slotBase = GetField02163524(sl);
    entry = (struct TableEntry_021d8c30*)SearchBothTables02079e2c((char*)GetData02108e10_020797dc(), *(short*)sb);
    entryIsKind2 = 0;
    if (entry != 0 && entry->kind18 == 2) {
        entryIsKind2 = 1;
    }

    if (arg2 == 0 && arg0[Enum_ov025_021d8c30_28238] == 6) return 0;
    if (arg2 == 1 && arg0[Enum_ov025_021d8c30_28238] == 4) return 0;

    *(unsigned short*)(arg0 + Enum_ov025_021d8c30_2540) = arg0[Enum_ov025_021d8c30_2528];

    int var48 = -1;
    var8 = 0;
    struct Struct_ov025_021d8c30* var49 = 0;
    Struct_ov000_021600f8* var50 = 0;
    const char* var51;
    int var52;

    if (arg6 == 0) {
        if (func_ov025_021dcc64(arg0) != 0) {
            Struct_ov000_021600f8* var53 = func_ov000_021600f8((Struct_ov000_0215440c*)arg1, arg4);
            struct Struct_ov025_021d8c30_9 var54;
            if (var53) {
                var54.unknown_18_ = var53->unknown_e_[1];
                var54.unknown_1a_ = var53->unknown_e_[0];
            }
            var54.unknown_8_ = arg3;
            var54.unknown_0_ = arg1;
            var54.unknown_4_ = arg2;
            var54.unknown_c_ = arg4;
            var54.unknown_10_ = arg5;
            var54.unknown_14_ = 1;
            func_ov025_021dcc70((char*)arg0, (char*)&var54);
            return 0;
        }
        int var55 = arg0[Enum_ov025_021d8c30_28414];
        if (var55 > 0) {
            struct Struct_ov025_021d8c30_10 var56;
            var56.unknown_8_ = arg3;
            var56.unknown_0_ = (unsigned int)arg1;
            var56.unknown_4_ = arg2;
            var56.unknown_c_ = arg4;
            var56.unknown_10_ = arg5;
            var56.unknown_14_ = 1;
            func_ov025_021dcde8(arg0, (struct Struct_ov025_021d8c30_11*)&var56);
            return var8;
        }
    }

    var9 = 0;
    if (arg2 == 0) {
        Struct_ov000_02160094* var57 = func_ov000_02160094((Struct_ov000_0215440c_2*)arg1, arg4);
        if (var57) {
            var48 = var57->unknown_20_;
            if (arg3 == 0) {
                var8 = (int)func_ov000_0215feb4((char*)var57, arg5, 0);
            } else if (arg3 == 1) {
                var8 = (int)func_ov000_0215feb4((char*)var57, arg5, 2);
            } else if (arg3 == 2) {
                var8 = (int)func_ov000_0215feb4((char*)var57, arg5, 3);
            } else if (arg3 == 3) {
                var8 = (int)func_ov000_0215feb4((char*)var57, arg5, 5);
            } else if (arg3 == 4) {
                var8 = (int)func_ov000_0215feb4((char*)var57, arg5, 4);
            } else if (arg3 == 5) {
                var8 = (int)func_ov000_0215feb4((char*)var57, arg5, 1);
            }
        }
    } else if ((unsigned int)(arg2 - 1) <= 2) {
        Struct_ov000_021600f8* var58 = func_ov000_021600f8((Struct_ov000_0215440c*)arg1, arg4);
        if (var58) {
            var50 = var58;
            var48 = func_ov000_0215ffa0(var58);
            if (arg3 == 0) {
                var8 = (int)func_ov000_0215fff4(var58, arg5, 0);
            } else if (arg3 == 1) {
                var8 = (int)func_ov000_0215fff4(var58, arg5, 1);
            } else if (arg3 == 2) {
                var8 = (int)func_ov000_0215fff4(var58, arg5, 2);
            }
            var9 = 1;
        }
    }
    if (arg1->unknown_b_3_) {
        func_ov000_02182498(arg0 + Enum_ov025_021d8c30_28668, 1);
    }

    GameObject* var59 = var1->GetCombatantByIndex(var48);
    if (var8 != 0) var49 = (struct Struct_ov025_021d8c30*)var8;
    if (var48 < 0 || var59 == 0 || var49 == 0) {
        return var8;
    }

    var10 = 0;
    var11 = 0;
    var51 = (const char*)var59->obj3D_.activeAnimationRecord_;
    if (var51 != 0 && strcmp(var51, data_ov025_021ef3d0) == 0) {
        var10 = 1;
        var11 = var59->obj3D_.GetCurrentAnimationTime();
    }

    var0 = func_ov000_02160094((Struct_ov000_0215440c_2*)arg1, 0);
    var12 = -1;
    var13 = 0;
    var14 = 0;
    if (var0) {
        var12 = var0->unknown_20_;
        var13 = var1->GetCombatantByIndex(var12);
        var14 = var0;
    }

    var42 = (struct Struct_ov025_021d8c30_8*)(arg0 + Enum_ov025_021d8c30_2086);
    var15 = 0;
    var31 = *(short*)(arg0 + Enum_ov025_021d8c30_1224);
    var17 = var59;
    var16 = *(unsigned short*)(arg0 + Enum_ov025_021d8c30_1220);
    var19 = var18 = var15;
    if (var50 != 0 && (var50->unknown_14_[1] == 8 || var50->unknown_14_[1] == 7 || var50->unknown_14_[1] == 6) && var50->unknown_14_[2] == 3) {
        var16 = 1;
        var31 = 0x1e;
        var19 = var16;
    }

    if (arg2 == 0) {
        func_ov025_021eaf48(arg0 + Enum_ov025_021d8c30_680, arg4, arg3, var8);
    } else if (arg2 == 1) {
        func_ov025_021ea604(arg0 + Enum_ov025_021d8c30_680, arg4, arg3, var8);
    } else if (arg2 == 3) {
        func_ov025_021ea604(arg0 + Enum_ov025_021d8c30_680, arg4, arg3, var8);
    }
    if (arg2 != 2) {
        func_ov000_02162dc4(arg0, var13, var59, var49->unknown_18_, var49->unknown_1d_, var49->unknown_1e_, var49->unknown_0_, 0);
    }
    if (var59) {
        func_02049ae4((unsigned char*)var59);
    }

    var20 = 0;
    var21 = 0;
    var22 = 0;
    var46 = 0;
    var23 = 0;
    var24 = 0;
    var45 = arg2 - 1;

    if ((unsigned int)var45 <= 1) {
        for (var44 = 1; var44 < var50->unknown_17_; var44++) {
            var43 = var44 - 1;
            int var60 = var50->unknown_e_[var43];
            var25 = var1->GetCombatantByIndex(var60);
            if (var25 == 0) continue;

            if (row->codes[i] == 3 && kind == 2) {
                Vector3fix pos = *(Vector3fix*)(sl + CameraPosition);
                fix32_t q = fix32_Divide(0x6000, pos.z);
                pos.y = FIX32_MULTIPLY(pos.y, q);
                pos.z = 0x7000;
                SetPosAndFields0216f1e4(sl + CameraBase, &pos.x, 0xb33, 0);
                Camera_Shake(sl + CameraBase, 0xcc, 0x3e8);
                if (kind != 2) {
                    SetShortTriple0x6e44_ov000_02163440(sl, 0x199, 0x258, 0x32);
                }
                if (sl[Field6fd8]) {
                    Forward0205ec20(&g_sePlayer, 0, 0);
                }
                SePlayer_Play(&g_sePlayer, 0x44, 0);
                skipSe = 1;
                sfx = -1;
                if (!slotObj->obj3D_.SetAnimationByName(data_ov025_021ef3d5, 9)) {
                    slotObj->obj3D_.SetAnimationByName(data_ov025_021ef3e0, 9);
                }
                var10 = 0;
                if (!inline_ov000_02169850(var60)) {
                    GameObject* var63 = func_0200fea4(var1, var60);
                    if (var63 && var63->obj3D_.unknown_2_ == 0xf4) {
                        var17 = var25;
                        var15 = 1;
                        var16 = 0x1a;
                        var46 |= 3;
                    }
                } else {
                    var17 = var25;
                    var15 = 1;
                    var16 = 0x22;
                }
                if ((row->codes[slot] == 8 || row->codes[slot] == 7 || row->codes[slot] == 6) && kind != 2) continue;
                if (sl[Field7744] == slotId) continue;
                func_ov025_021ed444((char*)(sl + MessageQueue), 0x1b8, slotId, 0, 0, -1, 0);
                sl[Field7744] = slotId;
            } else if (row->codes[i] == 1 || row->codes[i] == 2) {
                if (kind != 2) continue;
                didAnim = 1;
                soundId = 0xe;
                animObj = slotObj;
                critical = 0;
                if (row->codes[i] == 2) critical = 1;
                if (critical) soundId = 0x20;
                void* list = func_02057924();
                struct InitStruct02078484Struct req;
                InitStruct02078484(&req);
                Vector3fix off;
                Vector3fix pos = slotObj->obj3D_.position_;
                off.x = 0;
                off.y = pos.y + (slotObj->obj3D_.GetHeight() >> 1);
                off.z = slotObj->obj3D_.GetRadius() >> 1;
                req.offset = off;
                req.objectId = slotObj->obj3D_.actorIndex_;
                FindNodeAndProcess02057fb4(list, soundId, &req);
                int text;
                if (critical) {
                    text = IsPartyMember(slotId) ? 0x28 : 0x29;
                } else {
                    var68 = inline_ov000_02169850(var60) ? 0xa9 : 0xaa;
                }
                func_ov025_021ed444((char*)(arg0 + Enum_ov025_021d8c30_2192), var68, var60, 0, 0, -1, 0);
            } else if (var50->unknown_14_[var44] == 8 || var50->unknown_14_[var44] == 7 || var50->unknown_14_[var44] == 6) {
                var21 = 1;
                if (var50->unknown_14_[2] == 1 || var50->unknown_14_[2] == 2) continue;
                var27 = 0;
                if (var14 && inline_ov000_02156cc4_2(var14->unknown_20_)) {
                    GameObject* var69 = func_0200ff1c(var1, var14->unknown_20_);
                    if (var69 && (func_02085078(*(unsigned char**)((unsigned char*)var69 + Enum_ov025_021d8c30_336)) ||
                                 func_020850a4(*(unsigned char**)((unsigned char*)var69 + Enum_ov025_021d8c30_336)))) {
                        if (var6 && var6->unknown_17_4_ != 2) var27 = 1;
                    }
                }
                if (!var27) {
                    if (var6 == 0) continue;
                    if (var6->unknown_17_4_ != 3 && var6->unknown_17_4_ != 4) continue;
                }
                if (sl[Field7745] == row->ids[i] && sl[Field7746] == row->ids[slot]) continue;
                int msgId = 0x7f;
                int slotParty = 0;
                if (row->ids[slot] >= 0 && row->ids[slot] <= 3) slotParty = 1;
                if (slotParty) msgId = 0x7e;
                idx = i - 1;
                func_ov025_021ed444((char*)(sl + MessageQueue), msgId, row->ids[slot], 0, 0, row->ids[i], 0);
                sl[Field7745] = row->ids[i];
                sl[Field7746] = row->ids[idx];
            } else if (row->codes[i] == 0xa) {
                if (sl[Field7744] == slotId) continue;
                func_ov025_021ed444((char*)(sl + MessageQueue), 0x143, slotId, 0, 0, -1, 0);
                sl[Field7744] = slotId;
            } else if (row->codes[i] == 4 || row->codes[i] == 5) {
                if (sl[Field7744] == slotId) continue;
                if (sl[Field6fd8]) {
                    Forward0205ec20(&g_sePlayer, 0, 0);
                }
                SePlayer_Play(&g_sePlayer, 0x44, 0);
                func_ov025_021ed444((char*)(sl + MessageQueue), 0x142, slotId, 0, 0, -1, 0);
                sl[Field7744] = slotId;
                if (IsPartyMember(slotId)) {
                    animObj = slotObj;
                    didAnim = 1;
                    soundId = 0x23;
                } else {
                    GameObject* f = GetCombatantWithFlag0x400_0200fea4(battle, slotId);
                    if (f && (f->obj3D_.unknown_2_ == 0x3c || f->obj3D_.unknown_2_ == 0x3d)) {
                        slotObj->obj3D_.SetAnimationByName(data_ov025_021ef3e8, 0x19);
                    }
                    var17 = var25;
                    var15 = 1;
                    var16 = 0x23;
                }
            }
        }
    }

    if (kind == 2) {
        if (soundId == 0x22 || soundId == 0x1a || soundId == 0x21 || soundId == 0x23) {
            void* list = func_02057924();
            struct InitStruct02078484Struct req;
            InitStruct02078484(&req);
            Vector3fix off;
            off.x = 0;
            off.y = animObj->obj3D_.position_.y + (animObj->obj3D_.GetHeight() >> 1);
            off.z = animObj->obj3D_.GetRadius();
            req.objectId = animObj->obj3D_.actorIndex_;
            if (flags & 2) {
                off.z = 0;
                off.y = 0;
                off.x = 0;
            }
            if (var16 == 0x21 || var16 == 0x23) var75.z = 0xb33;
            var74.unknown_2c_ = var75;
            func_02057fb4(var73, var16, &var74);
        }
        if (arg1->unknown_22_) {
            func_ov025_021ed444((char*)(arg0 + Enum_ov025_021d8c30_2192), arg1->unknown_22_, -1, 0, 0, -1, 0);
            arg1->unknown_22_ = 0;
        }
        if (arg1->unknown_24_) {
            if (var16 == 0xe) {
                if (var50->unknown_1c_7_) {
                    short var76 = -1;
                    for (int var77 = 1; var77 < var50->unknown_17_; var77++) {
                        if (var50->unknown_14_[var77] == 1) {
                            var76 = var50->unknown_e_[var77 - 1];
                            break;
                        }
                    }
                    func_ov025_021ed380((char*)(arg0 + Enum_ov025_021d8c30_2192), arg1->unknown_24_, -1, 0, 0, var76, 0);
                }
            } else {
                func_ov025_021ed380((char*)(arg0 + Enum_ov025_021d8c30_2192), arg1->unknown_24_, -1, 0, 0, -1, 0);
                arg1->unknown_24_ = 0;
            }
        }
        return var8;
    }

    if (var49->unknown_1c_) {
        if (!var7) {
            var16 = 3;
            var18 = 1;
            int var78 = 0;
            if (!inline_ov000_02169850(var12)) {
                var78 = 1;
                var16 = 1;
            }
            if (var50->unknown_14_[1] == 3 || var50->unknown_14_[1] == 4 || var50->unknown_14_[1] == 5) {
                int var79 = 0;
                if (var50->unknown_e_[0] >= 0 && var50->unknown_e_[0] <= 3) var79 = 1;
                if (!var79) {
                    var78 = 1;
                } else {
                    var78 = 0;
                    var16 = 3;
                    var18 = 1;
                }
            } else if (var50->unknown_14_[2] == 3) {
                var78 = 0;
                var16 = 3;
                var18 = 1;
            }
            if (var78) {
                if (arg1->unknown_0_ == 0xf4 || arg1->unknown_0_ == 0xf5 || arg1->unknown_0_ == 0x48 || arg1->unknown_0_ == 0x70) {
                    var16 = 0x24;
                    var18 = 2;
                }
            }
        }
        var23 = 1;
    }

    if (func_ov000_0215fd90(target, 0xc)) {
        if (sb->type != 0x150) {
            didAnim = 1;
            soundId = 0x19;
            flags |= 3;
            SePlayer_Play(&g_sePlayer, 0x3b, 0);
        }
    } else if (func_ov000_0215fd90(var49, 9) || func_ov000_0215fd90(var49, 0xa)) {
        if (func_ov000_0215fd90(var49, 9)) {
            int var80 = 0;
            struct Struct_ov025_021d8c30_3* var81 = arg1->unknown_14_;
            for (int var82 = 0; var82 < arg1->unknown_9_; var82++) {
                if (var81 == 0) break;
                for (int var83 = 0; var83 < 3; var83++) {
                    struct Struct_ov025_021d8c30_2* var84 = var81->unknown_0_[var83];
                    if (var84 == 0) continue;
                    for (int var85 = 0; var85 < var81->unknown_18_[var83]; var85++) {
                        if (var84 == 0) break;
                        short var86 = var84->unknown_c_;
                        var84 = var84->unknown_20_;
                        if (var86 > 0) var80 += var86;
                    }
                }
                var81 = var81->unknown_20_;
            }
            if (total == 0) {
                GameObject_Shake((struct ShortPair0xba0xbc*)actor, 0x800, 0x1f4);
            }
        }
        SePlayer_Play(&g_sePlayer, 0x3a, 0);
    } else if (func_ov000_0215fd90(target, 6)) {
        if (sb->type != 0x1df) {
            didAnim = 1;
            soundId = 0x1c;
        }
        SePlayer_Play(&g_sePlayer, 0x39, 0);
        actor->obj3D_.SetAnimationByName(data_ov025_021ef3ef, 0x10);
        animSaved = 0;
        hadTarget = 1;
    } else if (func_ov000_0215fd90(target, 4) || func_ov000_0215fd90(target, 5) || func_ov000_0215fd90(target, 0x26)) {
        if (!func_ov000_0215fd90(target, 0xd)) {
            if (IsPartyMember(id)) {
                SePlayer_Play(&g_sePlayer, 0x36, 0);
            } else {
                SePlayer_Play(&g_sePlayer, 0x37, 0);
            }
            if (func_ov000_0215fd90(target, 5)) {
                if (!animSaved) {
                    actor->obj3D_.SetAnimationByName(data_ov025_021ef3d0, 1);
                }
            } else {
                GameObject_Shake((struct ShortPair0xba0xbc*)actor, 0xcc, 0x12c);
            }
        }
    }

    if (func_ov000_0215fd90(target, 0x2b)) {
        actor->obj3D_.SetAnimationByName(data_ov025_021ef3f5, 1);
    }

    var28 = func_ov000_02160130();
    void* var87 = 0;
    void* var88 = 0;
    if (var28) var87 = func_ov000_02160f08(var28);
    if (var87) var88 = func_ov025_021dafd0((char*)var87, var48);
    if (func_ov000_0215fd90(var49, 0x2d) && var88) {
        *(unsigned int*)((unsigned char*)var88 + 0x28) &= ~0x100;
        func_ov000_0217616c(var88);
    }
    if (func_ov000_0215fd90(var49, 0x27)) {
        func_0204a00c((unsigned char*)var59, (int)var49);
    }
    if ((var49->unknown_18_ & 0x80000) && var49->unknown_1d_ == 0xa) {
        func_0204a00c((unsigned char*)var59, (int)var49);
    }
    if (func_ov000_0215fd90(var49, 0x23) || func_ov000_0215fd90(var49, 7)) {
        int var89 = 0;
        if (func_ov000_0215fd90(var49, 7)) {
            var89 = 0x64;
        } else if (var49->unknown_c_ == 1) {
            var89 = 5;
        } else if (var49->unknown_c_ == 2) {
            var89 = 0x14;
        } else if (var49->unknown_c_ == 3) {
            var89 = 0x32;
        }
        Vector3fix pos = actor->obj3D_.position_;
        pos.y += actor->obj3D_.GetHeight();
        NumberPopups_Add(popups, popupId, (Vec3Int0203a48c*)&pos, 4, 0, 0);
    }

    if (func_ov000_0215fd90(var49, 3)) {
        func_02049f28((unsigned char*)var59);
        var59->obj3D_.MakeVisible();
        var59->obj3D_.SetInheritedAlpha(0x1f);
        if (var59->obj3D_.unknown_0_ & 0x100) {
            *(unsigned int*)((unsigned char*)var59 + Enum_ov025_021d8c30_396) &= ~1;
        } else {
            unsigned char* var91 = 0;
            for (int var92 = 0; var92 < 4; var92++) {
                unsigned char* var93 = ((unsigned char**)(arg0 + Enum_ov025_021d8c30_3768))[var92];
                if (var93 && *(short*)(var93 + 2) == var59->obj3D_.unknown_2_) {
                    var91 = var93;
                    break;
                }
            }
            if (var91) {
                if (var59->obj3D_.pModel_ == 0) {
                    func_02048588(var91, (unsigned char*)var59);
                }
                func_ov000_02166784((struct Struct_ov000_02161c0c_3*)arg0, var91, (unsigned char*)var59);
                func_ov000_021677fc(arg0);
            }
        }
        GameObject_ForceMotionState((struct Bytes02033b88*)actor, 0);
        actor->obj3D_.SkipAnimationTransition();
    } else if (func_ov000_0215fd90(target, 0xd)) {
        if (GetSubstructByte0x56_02049ee8((unsigned char*)actor)) {
            GameObject_ForceMotionState((struct Bytes02033b88*)actor, 4);
        }
        func_020d7334((unsigned char*)var5, var48);
        func_02049f3c((unsigned char*)var59);
        func_ov000_02167434(arg0, var59->obj3D_.GetTexturePaletteOffset());
        func_ov017_02191aac(var2, 0, var48, 2);
        func_ov017_02191aac(var2, 0, var48, 4);
        if (!var7 && arg2 != 0) {
            LightingManager::GetInstance()->BeginFade(0x800, 0x12c);
            SetShortTriple0x6e44_ov000_02163440(sl, 0x199, 0x258, 0x96);
            didAnim = 1;
            soundId = 0x1b;
            flags |= 1;
            SePlayer_Play(&g_sePlayer, 0x42, 0);
        }
        cleared = 1;
    } else if (func_ov000_0215fd90(target, 0x24)) {
        actor->obj3D_.SetAnimationByName(data_ov025_021ef3fc, 0);
        actor->obj3D_.TransitionInheritedAlpha(0, 0x1f4);
        ClearBitIfValueFound02167434(sl, actor->obj3D_.GetTexturePaletteOffset());
        SePlayer_Play(&g_sePlayer, 9, 0);
    }

    if (var23) {
        if (!var21 && (*(int*)(arg0 + Enum_ov025_021d8c30_3752) != 8 || *(int*)(arg0 + Enum_ov025_021d8c30_1232) == 0) &&
            (arg1->unknown_0_ == 1 || arg1->unknown_0_ == 2)) {
            LightingManager::GetInstance()->BeginFade(0x800, 0x12c);
            Vector3fix pos = *(Vector3fix*)(sl + CameraPosition);
            pos.z = FIX32_MULTIPLY(pos.z, 0xe66);
            SetPosAndFields0216f1e4(sl + CameraBase, &pos.x, 0xccc, 0);
            Camera_Shake(sl + CameraBase, 0xcc, 0x3e8);
        }
        if (!((unsigned char*)battle->GetCamera() == sl + CameraBase && sl[ModeByte] == 2) &&
            *(int*)(sl + Field4d0) == 0) {
            SetShortTriple0x6e44_ov000_02163440(sl, 0x199, 0x2bc, 0x96);
        }
    }

    if ((unsigned int)var45 <= 2 && arg1->unknown_22_) {
        func_ov025_021ed444((char*)(arg0 + Enum_ov025_021d8c30_2192), arg1->unknown_22_, -1, 0, 0, -1, 0);
        arg1->unknown_22_ = 0;
    }
    if (func_ov000_0215fd90(target, 8)) {
        func_ov017_02191aac(ov17, 0, actor->obj3D_.actorIndex_, 4);
        if (!fromRow) wantAlt = 1;
    }
    if (func_ov000_0215fd90(target, 0x2c)) {
        func_ov017_02191aac(ov17, 1, actor->obj3D_.actorIndex_, 2);
    }
    if (func_ov000_0215fd90(target, 0x28)) {
        func_ov017_02191aac(ov17, 0, actor->obj3D_.actorIndex_, 2);
    }

    var52 = 0;
    if ((arg1->unknown_0_ == 1 || arg1->unknown_0_ == 2 || arg1->unknown_0_ == 0xdb) && func_ov000_0215fd90(var49, 0x2a)) {
        var52 = 1;
    }

    if (func_ov000_0215fd90(target, 1) && !func_ov000_0215fd90(target, 0x29)) {
        amount = target->amount;
        if (func_ov000_0215fd90(target, 2)) {
            GameObject_ForceMotionState((struct Bytes02033b88*)actor, 4);
            ResetCombatantSlot020d7334((unsigned char*)slotBase, id);
            ClearSubstructByte0x56_02049f3c((unsigned char*)actor);
            ClearBitIfValueFound02167434(sl, actor->obj3D_.GetTexturePaletteOffset());
            func_ov017_02191aac(ov17, 0, id, 2);
            func_ov017_02191aac(ov17, 0, id, 4);
            cleared = 1;
        } else {
            GameState* gs = GameState::GetInstance();
            if (actor->obj3D_.unknown_0_ & 0x400) {
                GameObject* f = GetCombatantWithFlag0x400_0200fea4(gs, actor->obj3D_.actorIndex_);
                unsigned char* info;
                if (f && (info = *(unsigned char**)((unsigned char*)f + 0x144)) != 0) {
                    short k = *(short*)(info + 8);
                    if (k == 0x2d || k == 0x2e || k == 0x2f || k == 0x11b) goto skipFlash;
                }
            }
            if (var59->obj3D_.unknown_0_ & 0x100) {
                func_02054028(var59, 0x64);
            } else {
                var59->obj3D_.SetNoTextureTimer(2);
            }
        skipFlash:
            if (((struct Nibbles_021d8c30*)((unsigned char*)actor + 0xc1))->hi != 1 && !animSaved &&
                GetSubstructByte0x56_02049ee8((unsigned char*)actor)) {
                actor->obj3D_.SetAnimationByName(data_ov025_021ef3f5, 9);
            }
        }

        var30 = 0;
        var32 = 0;
        var33 = var30;
        var34 = inline_ov000_02169850(var48);
        if (!var34) {
            GameObject* var99 = func_0200fea4(var1, var48);
            struct Struct_ov025_021d8c30_6* var100;
            if (var99 && (var100 = *(struct Struct_ov025_021d8c30_6**)((unsigned char*)var99 + 0x148)) != 0) {
                var32 = var100->unknown_27_4_;
                var33 = var100->unknown_13_7_;
            }
            if (deadly) {
                if (cleared) {
                    sfx = 0x25;
                    GameResources* res = battle->GetResources();
                    if (res) {
                        SetMainBrightness(res, 0x10, 0);
                        SetMainBrightness(res, 0, 0x1e);
                        SetShortTriple0x6e44_ov000_02163440(sl, 0x199, 0x3e8, 0x96);
                    }
                } else if (var31 >= 0) {
                    var31 = 0x24;
                }
            }
        }
        if (var31 >= 0) {
            if (var31 != 0x25) {
                if (var22) {
                    if (var34) {
                        var31 = 0x27;
                    } else {
                        var31 = 0x26;
                    }
                } else if (var34) {
                    if (var31 < 0x3c || var31 > 0x41) var31 = 0x1f;
                } else if (var33 && !var32) {
                    if (var31 < 0x3c || var31 > 0x41) var31 = 0x20;
                }
                if (var49->unknown_1c_) {
                    if (var50 && (var50->unknown_14_[1] == 3 || var50->unknown_14_[1] == 4 || var50->unknown_14_[1] == 5)) {
                        int var102 = 0;
                        if (var50->unknown_e_[0] >= 0 && var50->unknown_e_[0] <= 3) var102 = 1;
                        if (!var102 && var16 == 1) var31 = 0x1f;
                    }
                    if (var18 == 1) {
                        var31 = 0x26;
                    } else if (var18 == 2) {
                        var31 = 0x27;
                    }
                }
            }
            if (!skipSe) {
                if (!quiet) {
                    SePlayer_Play(&g_sePlayer, sfx, 0);
                }
                var30 = 1;
            }
        }
        if (!played && (textKind == 1 || textKind == 2)) {
            int se = 0x26;
            if (textKind == 2) se = 0x27;
            SePlayer_Play(&g_sePlayer, se, 0);
        } else if (*(short*)(sl + Field4ca) >= 0 && !keepDefault) {
            SePlayer_PlayExtra(&g_sePlayer, *(short*)(sl + Field4ca), 0);
        }
        if (msg->duration) {
            if (!quiet) {
                Camera_Shake(camera, msg->strength, msg->duration);
            }
        } else if (target->show) {
            Camera_Shake(camera, 0x333, 0x1f4);
        }
        Vector3fix pos = actor->obj3D_.position_;
        pos.y += actor->obj3D_.GetHeight();
        int big = 0;
        if (func_ov000_0215fd90(target, 0x2a)) big = 1;
        NumberPopups_Add(popups, amount, (Vec3Int0203a48c*)&pos, big, PopupDelay(inner), PopupColor(inner));
        if (!sb->queued && sl[Field6e4e] != 4) {
            func_ov000_021823dc(sl + PendingState, sb->group);
            sb->queued = 1;
        }
        var15 = 1;
    }

    if (func_ov000_0215fd90(target, 0x25) || func_ov000_0215fd90(target, 0x22)) {
        int style = 2;
        if (func_ov000_0215fd90(target, 0x22)) style = 3;
        negAmount = -target->amount;
        Vector3fix pos = actor->obj3D_.position_;
        if (kind == 0) {
            SePlayer_Play(&g_sePlayer, 0x65, 0);
        }
        pos.y += actor->obj3D_.GetHeight();
        NumberPopups_Add(popups, negAmount, (Vec3Int0203a48c*)&pos, style, 0, 0);
    }

    if (var15 && var13 && var16 > 0) {
        if (var49->unknown_0_ == 1 && arg2 == 2 && var59 == var13) var46 |= 1;
        var36 = func_02057924();
        struct Struct_02078398_2 var108;
        func_02078484(&var108);
        if (arg2 == 3) {
            for (int var109 = 1; var109 < var50->unknown_17_; var109++) {
                if (var50->unknown_14_[var109] == 3) var13 = var1->GetCombatantByIndex(var50->unknown_e_[var109 - 1]);
            }
        }
        Vector3fix var110;
        Vector3fix var111;
        Vector3fix var112 = var13->obj3D_.position_;
        Vector3fix var113 = var17->obj3D_.position_;
        var37 = var17->obj3D_.rotation_.y;
        int var114;
        if (arg0[Enum_ov025_021d8c30_3640] == 1 || arg0[Enum_ov025_021d8c30_3640] == 2) {
            var114 = 1;
        } else {
            var114 = 0;
        }
        var47 = var114 | !var13->obj3D_.IsVisible();
        var38 = var17->obj3D_.GetRadius() >> 1;
        int var115 = var17->obj3D_.GetHeight();
        var39 = var13->obj3D_.GetHeight();
        var40 = var13->obj3D_.GetRadius() >> 1;
        int var116 = Vector3fix_Distance(&var112, &var113);
        if (var47) {
            fix32_t var117 = fix32cos(var37);
            fix32_t var118 = fix32sin(var37);
            Matrix3x3 var119;
            Mat3x3_WriteRotationY(&var119, var118, var117);
            var111.x = 0;
            var111.y = 0;
            var111.z = 0x1000;
            Mat3x3_ApplyToVector(&var111, &var119, &var111);
            Vector3fixMultiplyScalar(&var111, var38, &var111);
            Vector3fix var120 = var17->obj3D_.position_;
            Vector3fix_Add(&var120, &var111, &var110);
        } else {
            int var121 = 0;
            var112.y = 0;
            var113.y = 0;
            if (inline_ov000_02169850(var12)) {
                if (var116 < var38) var121 = 1;
            }
            if (!var121) {
                Vector3fix_Subtract(&var112, &var113, &var111);
                Vector3fix_Normalize(&var111, &var111);
                Vector3fixMultiplyScalar(&var111, var38, &var111);
                Vector3fix var122 = var17->obj3D_.position_;
                Vector3fix_Add(&var122, &var111, &var110);
            } else {
                Vector3fix_Subtract(&var113, &var112, &var111);
                Vector3fix_Normalize(&var111, &var111);
                Vector3fixMultiplyScalar(&var111, var40 + 0x4cc, &var111);
                Vector3fix var123 = var13->obj3D_.position_;
                Vector3fix_Add(&var123, &var111, &var110);
            }
        }

        var41 = 0;
        if (inline_ov000_02169850(var48)) {
            int var124 = inline_ov025_021d8c30_3(var115, 0x999);
            var110.y += var124;
        } else if (*((unsigned char*)var28 + Enum_ov025_021d8c30_28648) == 0) {
            if (var16 == 0x1c) {
                int var125 = inline_ov025_021d8c30_3(var115, 0x999);
                var110.y += var125;
            } else {
                var110.y += (var39 + var115) >> 2;
                if (func_ov000_02163c0c(arg0, var48)) {
                    var41 = 1;
                    var110.y += 0x800;
                }
            }
        } else {
            Vector3fix var126 = inline_ov025_021d8c30_4(var28);
            var110.x += var126.x;
            var110.y = var126.y;
            var110.z += var126.z;
            Vector3fix var127;
            __clear(&var127, sizeof(var127));
            *(Vector3fix*)(arg0 + Enum_ov025_021d8c30_28636) = var127;
            arg0[Enum_ov025_021d8c30_28648] = 0;
        }
        if (0.8f * var39 < var110.y && !var41) {
            var110.y = 0.8f * var39;
        }
        if (flags & 1) {
            out.x = 0;
            out.z = animObj->obj3D_.GetRadius() >> 1;
            req.objectId = animObj->obj3D_.actorIndex_;
        } else {
            var108.unknown_38_ = var17->obj3D_.rotation_;
            var108.unknown_44_ = var13->obj3D_.GetScale();
        }
        if (var46 & 2) {
            var110.z = 0;
            var110.y = 0;
            var110.x = 0;
        }
        var108.unknown_2c_ = var110;
        func_02057fb4(var36, var16, &var108);
    }

    if (inline_ov000_02169850(var48)) {
        unsigned char* var128 = (unsigned char*)func_ov025_021dafd0((char*)(arg0 + Enum_ov025_021d8c30_14176), var48);
        if (var128) {
            if (arg3 != 1 || arg2 == 0) {
                if (arg1->unknown_0_ != 0x3af && arg1->unknown_0_ != 0x39a && arg1->unknown_0_ != 0x3a0) {
                    short var129 = var49->unknown_e_;
                    func_ov000_02176134((struct Struct_ov000_02176134*)var128, var129);
                    *(short*)(var128 + 0xc) = var129;
                }
            }
            if (var50 && (var50->unknown_14_[1] == 8 || var50->unknown_14_[1] == 7 || var50->unknown_14_[1] == 6)) {
                if (var49 && (func_ov000_0215fd90(var49, 0x22) || func_ov000_0215fd90(var49, 0x2a))) {
                    short var130 = var49->unknown_10_;
                    func_ov000_02176150((struct Struct_ov000_021537b8_6*)var128, var130);
                    *(short*)(var128 + 0xe) = var130;
                }
            } else {
                short var131 = var49->unknown_10_;
                func_ov000_02176150((struct Struct_ov000_021537b8_6*)var128, var131);
                *(short*)(var128 + 0xe) = var131;
            }
            *(short*)(var128 + 8) = var49->unknown_12_;
            *(short*)(var128 + 0xa) = var49->unknown_14_;
            *(unsigned int*)(var128 + 0x28) = var49->unknown_18_;
            func_ov000_0217616c(var128);
            func_ov000_0216ff20((char*)var128, var49->unknown_1d_);
            var128[0x2f] = var49->unknown_1e_;
        }
    }

    if ((*(signed char**)(sl + Field2a0))[0x2a] == GameState_GetProtagonistIndex(battle) && IsPartyMember(id) &&
        GetCombatantWithFlag0x100_0200ff1c(battle, id)) {
        func_ov017_021c9d2c(id, target->s0e, target->s12, target->s10, target->s14, target->flags18, 0, 0, 0);
    }

    *(unsigned int*)(sl + Field46c) |= 0x10;
    if (animSaved && !cleared) {
        actor->obj3D_.SetAnimationByName(data_ov025_021ef3d0, 1);
        actor->obj3D_.SetCurrentAnimationTime(savedAnimTime);
    }
    if (var20) {
        ((struct Struct_ov025_021d8c30_7*)((unsigned char*)var59 + 0xc1))->unknown_0_4_ = 0;
    }
end:
    return var8;
}
