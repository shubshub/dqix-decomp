#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "NitroSDK/Cache.h"
#include "NitroSDK/LoadToVRAM.h"
#include "NitroSDK/Matrix.h"
#include "Resource/GameResources.h"

class Struct_ov004_0215f0c0_5 {
public:
    virtual void inline_ov004_0215f0c0_25(); virtual void inline_ov004_0215f0c0_26(); virtual void inline_ov004_0215f0c0_27(); virtual void inline_ov004_0215f0c0_28();
    virtual void inline_ov004_0215f0c0_29(); virtual void inline_ov004_0215f0c0_30(); virtual void inline_ov004_0215f0c0_31();
    virtual void inline_ov004_0215f0c0_32(Vector3i* arg0);
    virtual Vector3i inline_ov004_0215f0c0_33();
    virtual void inline_ov004_0215f0c0_34(); virtual void inline_ov004_0215f0c0_35(); virtual void inline_ov004_0215f0c0_36(); virtual void inline_ov004_0215f0c0_37();
    virtual void inline_ov004_0215f0c0_38(); virtual void inline_ov004_0215f0c0_39(); virtual void inline_ov004_0215f0c0_40(); virtual void inline_ov004_0215f0c0_41();
    virtual void inline_ov004_0215f0c0_42(); virtual void inline_ov004_0215f0c0_43(); virtual void inline_ov004_0215f0c0_44(); virtual void inline_ov004_0215f0c0_45();
    virtual void inline_ov004_0215f0c0_46(); virtual void inline_ov004_0215f0c0_47(); virtual void inline_ov004_0215f0c0_48(); virtual void inline_ov004_0215f0c0_49();
    virtual void inline_ov004_0215f0c0_50(); virtual void inline_ov004_0215f0c0_51(); virtual void inline_ov004_0215f0c0_52(); virtual void inline_ov004_0215f0c0_53();
    virtual void inline_ov004_0215f0c0_54(); virtual void inline_ov004_0215f0c0_55(); virtual void inline_ov004_0215f0c0_56(); virtual void inline_ov004_0215f0c0_57();
    virtual void inline_ov004_0215f0c0(); virtual void inline_ov004_0215f0c0_2(); virtual void inline_ov004_0215f0c0_3(); virtual void inline_ov004_0215f0c0_4();
    virtual void inline_ov004_0215f0c0_5(); virtual void inline_ov004_0215f0c0_6(); virtual void inline_ov004_0215f0c0_7(); virtual void inline_ov004_0215f0c0_8();
    virtual void inline_ov004_0215f0c0_9(); virtual void inline_ov004_0215f0c0_10(); virtual void inline_ov004_0215f0c0_11(); virtual void inline_ov004_0215f0c0_12();
    virtual void inline_ov004_0215f0c0_13(); virtual void inline_ov004_0215f0c0_14(); virtual void inline_ov004_0215f0c0_15(); virtual void inline_ov004_0215f0c0_16();
    virtual void inline_ov004_0215f0c0_17(); virtual void inline_ov004_0215f0c0_18(); virtual void inline_ov004_0215f0c0_19(); virtual void inline_ov004_0215f0c0_20();
    virtual void inline_ov004_0215f0c0_21();
    virtual void inline_ov004_0215f0c0_22(int arg0);
    virtual void inline_ov004_0215f0c0_23();
    virtual void inline_ov004_0215f0c0_24(unsigned short arg0);

    unsigned char unknown_4_[8];
    unsigned char unknown_c_;
    unsigned char unknown_d_[0x13];
    void* unknown_20_;
    unsigned char unknown_24_[0x14];
    short unknown_38_;
    unsigned char unknown_3a_[0xa];
    unsigned char unknown_44_0_ : 4;
};

struct Struct_ov004_021707e8 {
    unsigned char unknown_0_[2];
    unsigned char unknown_2_;
    unsigned char unknown_3_[0x19];
    int unknown_1c_;
    unsigned char unknown_20_[8];
    char* unknown_28_;
};

struct Struct_ov004_0215f0c0 {
    unsigned char unknown_0_[4];
    unsigned short unknown_4_;
};

struct Struct_ov004_0215f0c0_2 {
    unsigned char unknown_0_[0x130];
    struct Struct_ov004_0215f0c0* unknown_130_;
    void* unknown_134_;
};

struct Struct_ov004_0215f0c0_3 {
    unsigned char unknown_0_[0x950];
    int unknown_950_;
};

struct Struct_ov004_0215f0c0_4 {
    unsigned char unknown_0_[0x150];
    struct Struct_ov004_0215f0c0_3* unknown_150_;
};

struct Struct_ov004_0215f0c0_6 {
    unsigned char unknown_0_[0x16c];
    unsigned short unknown_16c_[13];
    unsigned char unknown_186_[1];
};

struct Struct_ov004_0215f0c0_7 {
    unsigned char unknown_0_[4];
    unsigned short unknown_4_;
};

struct Struct_ov004_0215f0c0_8 {
    unsigned char unknown_0_[8];
    struct Struct_ov004_0215f0c0_7* unknown_8_;
};

struct Struct_ov004_0215f0c0_9 {
    int unknown_0_[3];
};

struct Struct_02000c9c_8;
struct Struct_02072a68_2;

int STD_GetStringLength(const char*);
unsigned char* GetFieldAt0x150_02053c6c(unsigned char* obj);
extern "C" HudNode* func_ov004_0215e47c(void* a, int key);
extern "C" void* func_ov023_021fad18(void* node);
struct PortraitEntry* GetArrayEntry_0215e438(void* arr, int idx);
extern "C" int func_ov017_021bdbcc(void* obj);
void* GetTableEntry020421b0(int idx);
unsigned char GameState_GetLanguage(struct Struct0200fb08* obj);
extern "C" void* func_ov011_021849c8(void* ctx);
extern "C" HudNode* func_ov023_021f6880(void* list, int key);
extern "C" int func_ov023_021f6f10(HudNode* node);
int IsValueEqual12_02042190(int x);
extern "C" int Font_GetTextWidth(void* p, int flag);
int StandardStrings_Get(int value);
int CheckAfterTwoCalls_0215e460(void);
void SetField38IfState8_0215e49c(void*, int, int);
extern "C" struct TableA68* func_ov023_021fa598(HudNode* node);
void NameText_InitFromPartyMember(void* obj, int combatantId);
int MessageSystem_GetInstance(void);
extern "C" void func_02046380(void* global);
void* FindEntryByKey_02072a68(struct TableA68* table, int key);
extern "C" void MessageSystem_FormatText(int a, int b, void* fmt, void* dst, int p4, int p5, int p6);
void* CheckNodeState6_0215e4c0(void* a, int key);
extern "C" void func_ov023_021f809c(void* obj, void* param2);

extern struct Struct_ov004_021707e8 data_ov004_021707e8;
extern int data_ov004_0216fe04[];
extern unsigned short data_ov004_0216fdd0[];

// JPN: func_ov004_0215f0c0 (0215fbc8)
// USA: func_ov004_0215f0c0
extern "C" ARM void func_ov004_0215f0c0(void* arg0) {
    GameState* var0 = GameState::GetInstance();
    struct Struct_ov004_0215f0c0_2* var1 = (struct Struct_ov004_0215f0c0_2*)func_0200ff1c(var0, data_ov004_021707e8.unknown_1c_);
    struct Struct_ov004_0215f0c0_6* var2 = (struct Struct_ov004_0215f0c0_6*)func_02053c6c((unsigned char*)var1);
    int var3 = 0;
    int var4 = 0xf;
    if ((int)var1->unknown_130_->unknown_4_ <= 0) {
        var3 = 1;
    }
    if (var3) {
        var4 = 9;
    }
#if !defined(jpn)
    Struct_ov004_0215f0c0_5* var5 = func_ov004_0215e47c(arg0, 0x1f5);
    if (!var3) {
        void* var6 = func_ov004_0215e47c(arg0, 0x1f4);
        if (var6 != 0) {
            int var7;
            void* var8 = func_ov023_021fad18(var6);
            int var9 = data_ov004_021707e8.unknown_1c_;
            if (var9 >= 0) {
                struct Struct_ov004_0215f0c0_4* var10 = (struct Struct_ov004_0215f0c0_4*)GameState::GetInstance()->GetPartyMemberByIndex(var9);
                if (var8 != 0 && var10 != 0) {
                    struct Struct_ov004_0215f0c0_8* var11 = func_ov004_0215e438(var8, 0);
                    struct Struct_ov004_0215f0c0_7* var12;
                    if (var11 != 0 && (var12 = var11->unknown_8_) != 0) {
                        var7 = var10->unknown_150_->unknown_950_;
                        int var13 = func_ov017_021bdbcc(GetGameResources());
                        if (var13 != 0) {
                            var7 = 0;
                        }
                        int var14;
                        unsigned int var15;
                        unsigned char var16 = var7 * 4 + 0x28;
                        var15 = (unsigned short)(var12->unknown_4_ & 0x3ff) << 5;
                        for (var14 = 0; var14 < 4; var14++, var16++) {
                            void* var17 = func_020421b0(var16);
                            CleanInvalidateCacheRange(var17, 0x20);
                            LoadToMainObjVRAM(var17, var15, 0x20);
                            CleanCacheRange(var17, 0x20);
                            var15 += 0x20;
                        }
                    }
                }
            }
        }
        if (var5 != 0) {
            var5->unknown_c_ &= ~8;
        }
    } else {
        if (var5 != 0) {
            var5->unknown_c_ |= 8;
        }
    }

    unsigned char level = GameState_GetLanguage((struct Struct0200fb08*)gs);
#endif
    void* var19 = func_ov011_021849c8(arg0);
    Struct_ov004_0215f0c0_5* var20 = func_ov023_021f6880(var19, 0x7f);
    if (var20 == 0) {
        return;
    }
    var20->inline_ov004_0215f0c0_24(var2->unknown_16c_[data_ov004_021707e8.unknown_2_]);

    {
        Struct_ov004_0215f0c0_5* var21 = func_ov023_021f6880(var19, 0x7b);
        if (func_ov023_021f6f10(var21) == 8) {
            void* var22 = var21->unknown_20_ = var1->unknown_134_;
            int var23 = 0;
            if (var22 != 0) {
#if defined(jpn)
                width = STD_GetStringLength((const char*)baseStats);
                width = (width * node->kind) >> 1;
#else
                width = Font_GetTextWidth(baseStats, IsValueEqual12_02042190(node->kind));
#endif
            }
            Vector3i var24;
            var24 = var21->inline_ov004_0215f0c0_33();
            var24.x = (0x23 - (var23 >> 1)) << 12;
#if !defined(jpn)
            var24.y = 0x2000;
#endif
            var21->inline_ov004_0215f0c0_32(&var24);
            var21->inline_ov004_0215f0c0_22(var4);
        }
    }
    int var25 = var2->unknown_186_[data_ov004_021707e8.unknown_2_];
    if (var25 != 0) {
        var20 = func_ov023_021f6880(var19, 0x7e);
        if (var20 == 0) {
            return;
        }
        if (func_ov023_021f6f10(var20) == 8) {
            var20->unknown_38_ = var25 + 0x1d3;
#if defined(jpn)
            Vector3i var26;
            var26 = var20->inline_ov004_0215f0c0_33();
#endif
            if (var25 == 10) {
                var20->inline_ov004_0215f0c0_22(0xd);
#if defined(jpn)
                var26.y = 0x6000;
#endif
            } else {
                var20->inline_ov004_0215f0c0_22(5);
#if defined(jpn)
                var26.y = 0x7000;
#endif
            }
#if defined(jpn)
            var20->inline_ov004_0215f0c0_32(&var26);
#endif
        }
#if defined(jpn)
        var20 = func_ov023_021f6880(var19, 0x7c);
        if (var20 != 0) {
            Vector3i var27;
            var27 = var20->inline_ov004_0215f0c0_33();
            var27.x = 0x42000;
            var20->inline_ov004_0215f0c0_32(&var27);
        }
        var20 = func_ov023_021f6880(var19, 0x7d);
        if (var20 != 0) {
            Vector3i var28;
            var28 = var20->inline_ov004_0215f0c0_33();
            var28.x = 0x5f000;
            var20->inline_ov004_0215f0c0_32(&var28);
        }
        var20 = func_ov023_021f6880(var19, 0x7f);
        if (var20 != 0) {
            Vector3i var29;
            var29 = var20->inline_ov004_0215f0c0_33();
            var29.x = 0x68000;
            var20->inline_ov004_0215f0c0_32(&var29);
        }
#else
        var20 = func_ov023_021f6880(var19, 0x7f);
        if (var20 != 0) {
            Vector3i var30;
            var30 = var20->inline_ov004_0215f0c0_33();
            var30.x = (data_ov004_0216fe04[var18] + 0x72) << 12;
            var20->inline_ov004_0215f0c0_32(&var30);
        }
        node = func_ov023_021f6880(list, 0x7d);
        if (node != 0) {
            node->data = (void*)StandardStrings_Get(0x3f3);
        }
#endif
    } else {
        var20 = func_ov023_021f6880(var19, 0x7e);
        if (var20 != 0) {
            if (func_ov023_021f6f10(var20) == 8) {
                var20->unknown_38_ = 0x3a;
            }
        }
#if defined(jpn)
        var20 = func_ov023_021f6880(var19, 0x7c);
        if (var20 != 0) {
            Vector3i var31;
            var31 = var20->inline_ov004_0215f0c0_33();
            var31.x = 0x46000;
            var20->inline_ov004_0215f0c0_32(&var31);
        }
        var20 = func_ov023_021f6880(var19, 0x7d);
        if (var20 != 0) {
            Vector3i var32;
            var32 = var20->inline_ov004_0215f0c0_33();
            var32.x = 0x5c000;
            var20->inline_ov004_0215f0c0_32(&var32);
        }
        var20 = func_ov023_021f6880(var19, 0x7f);
        if (var20 != 0) {
            Vector3i var33;
            var33 = var20->inline_ov004_0215f0c0_33();
            var33.x = 0x65000;
            var20->inline_ov004_0215f0c0_32(&var33);
        }
#else
        var20 = func_ov023_021f6880(var19, 0x7f);
        if (var20 != 0) {
            Vector3i var34;
            var34 = var20->inline_ov004_0215f0c0_33();
            var34.x = (data_ov004_0216fe04[var18] + 0x72) << 12;
            var20->inline_ov004_0215f0c0_32(&var34);
        }
        node = func_ov023_021f6880(list, 0x7d);
        if (node != 0) {
            node->data = (void*)StandardStrings_Get(0x3f3);
        }
#endif
    }

    if (func_ov004_0215e460() != 0) {
        func_ov004_0215e49c(arg0, 0x7c, 0x201);
    } else {
        func_ov004_0215e49c(arg0, 0x7c, data_ov004_021707e8.unknown_2_ + 0x1e4);
    }

#if !defined(jpn)
    char* var35 = data_ov004_021707e8.unknown_28_;
    memset(var35, 0, 0x80);
#endif
    unsigned short var36[3];
#if defined(jpn)
    var36[0] = data_ov004_0216fdd0[13];
    var36[1] = data_ov004_0216fdd0[14];
    var36[2] = data_ov004_0216fdd0[15];
#else
    var36[0] = data_ov004_0216fdd0[15];
    var36[1] = data_ov004_0216fdd0[16];
    var36[2] = data_ov004_0216fdd0[17];
#endif

    if (var3) {
        Struct_ov004_0215f0c0_5* var37 = func_ov023_021f6880(var19, 0x7c);
        if (var37 != 0) {
            Vector3i var38;
            var38 = var37->inline_ov004_0215f0c0_33();
            var38.x = 0x53000;
#if !defined(jpn)
            var38.y = 0x2000;
#endif
            var37->inline_ov004_0215f0c0_32(&var38);
            var37->inline_ov004_0215f0c0_22(var4);
        }
#if defined(jpn)
        func_ov004_0215e49c(arg0, 0x7c, 0x202);
#else
        HudNode* msg = func_ov023_021f6880(list, 6);
        if (msg != 0 && func_ov023_021f6f10(msg) == 4) {
            struct TableA68* table = func_ov023_021fa598(msg);
            struct CombatantName name;
            NameText_InitFromPartyMember(&name, data_ov004_021707e8.combatantId);
            int g = MessageSystem_GetInstance();
            func_02046380((void*)g);
            *(struct CombatantName**)g = &name;
            MessageSystem_FormatText(g, 0, FindEntryByKey_02072a68(table, 0x202), text, 0x1e, 0, 0);
            label->data = text;
        }
#endif
        for (int var43 = 0; var43 < 3; var43++) {
            Struct_ov004_0215f0c0_5* var44 = func_ov023_021f6880(var19, var36[var43]);
            if (var44 != 0) {
                var44->unknown_c_ |= 8;
            }
        }
    } else {
        Struct_ov004_0215f0c0_5* var45 = func_ov023_021f6880(var19, 0x7c);
        if (var45 != 0) {
            var45->inline_ov004_0215f0c0_22(var4);
        }
        for (int var46 = 0; var46 < 3; var46++) {
            Struct_ov004_0215f0c0_5* var47 = func_ov023_021f6880(var19, var36[var46]);
            if (var47 != 0) {
                var47->unknown_c_ &= ~8;
            }
        }
    }

    func_ov023_021f809c(func_ov004_0215e4c0(arg0, 5), arg0);
}
