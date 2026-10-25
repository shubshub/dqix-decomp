#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

struct Struct_02072a68_2;
struct Struct_020465c0;
struct Struct_ov004_021549e4_3;
struct Struct_02046574_2;
#if defined(jpn)
extern "C" void* func_ov004_02168f08(void* arg0, int arg1);
extern "C" void func_020474a8(void* arg0, int arg1, char* arg2, char* arg3);
#else
extern "C" void* func_ov023_021f6524(void* arg0, int arg1);
#endif
#if defined(jpn)
extern "C" struct Struct_02072a68_2* func_ov004_02169040(void* arg0, int arg1);
#else
extern "C" struct Struct_02072a68_2* func_ov004_02168b08(void* arg0, int arg1);
#endif
int MessageSystem_GetInstance(void);
void* GetFieldAt0x150_02053c6c(unsigned char* obj);
extern "C" void* Scenario_GetInstance(void* obj);
extern "C" int func_ov023_021f9bc8(char* obj);
unsigned int GetTableEntry_021f9b6c(struct Obj9b6c* obj, unsigned int a, unsigned int b);
extern "C" void __clear(void* buf, int len);
extern "C" void Font_DecodeText(const char* name, char* dest, int flag);
void* GetNodeIfType8_02168a6c(void* a, int id);
void* FindEntryByKey_02072a68(struct TableA68* table, int key);
extern "C" void func_02046380(void* global);
void MessageSystem_SetStringArgument(struct Obj02046574* obj, int index, char* str);
extern "C" void MessageSystem_FormatText(void* a, int b, char* c, char* d, int e, int f, int g);
char* FindSubstring_020d2f88(char* haystack, char* needle);
int LoadBattleBlock020ac4c0(void* dst);
void StoreInArray0x8b0_020465c0(struct StoreStruct* base, int index, int value);
int Scenario_TestFlag(int unused, unsigned char* arr, int index);
void SetByteInRange_020465f0(unsigned char* base, int index, unsigned char value);
void SetByteAtIndex_020465d8(unsigned char* base, int index, unsigned char value);
#if defined(jpn)
extern "C" void* func_ov004_02168fa4(void*, int);
extern "C" void func_ov023_021f809c(void*, void*);
#else
extern "C" int func_ov023_021f6680(void* arg0, int arg1);
#endif

struct Struct_ov004_02169b4c {
    unsigned int unknown_0_0_ : 14;
    unsigned int unknown_1_6_ : 17;
    unsigned int unknown_3_7_ : 1;
    unsigned int unknown_4_0_ : 14;
    unsigned int unknown_5_6_ : 17;
    unsigned int unknown_7_7_ : 1;
    unsigned int unknown_8_0_ : 7;
    unsigned int unknown_8_7_ : 7;
    unsigned int unknown_9_6_ : 7;
    unsigned int unknown_a_5_ : 7;
    unsigned int unknown_b_4_ : 4;
    unsigned int unknown_c_0_ : 10;
    unsigned int unknown_d_2_ : 14;
    unsigned int unknown_f_0_ : 7;
    unsigned int unknown_f_7_ : 1;
    unsigned int unknown_10_0_ : 9;
    unsigned int unknown_11_1_ : 14;
    unsigned int unknown_12_7_ : 7;
    unsigned int unknown_13_6_ : 2;
    short unknown_14_;
    unsigned char unknown_16_0_ : 1;
};

struct Struct_ov004_02169b4c_2 {
    char unknown_0_[6];
    char unknown_6_[0xe];
    struct Struct_ov004_02169b4c unknown_14_;
};

struct Struct_ov004_02169b4c_3 {
    unsigned short unknown_0_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
    unsigned short unknown_4_;
    unsigned char unknown_6_;
    unsigned char unknown_7_;
    unsigned int unknown_8_0_ : 24;
    unsigned int unknown_b_0_ : 8;
    unsigned int unknown_c_0_ : 14;
    unsigned int unknown_d_6_ : 14;
    unsigned int unknown_f_4_ : 4;
    char unknown_10_[0xb0 - 0x10];
};

struct Struct_ov004_02169b4c_4 {
#if defined(jpn)
    char unknown_0_[0x10];
#else
    char unknown1_0_[0x190];
#endif
    char* unknown_190_;
    struct Struct_ov004_02169b4c* unknown_194_;
    unsigned char unknown_198_;
    char unknown_199_[3];
    char* unknown_19c_;
};

struct Struct_ov004_02169b4c_5 { char unknown_0_[0x5c]; short unknown_5c_; };
struct Struct_ov004_02169b4c_6 { int unknown_0_, unknown_4_, unknown_8_; };

class Struct_ov004_02169b4c_7 {
public:
    virtual void inline_ov004_02169b4c();
    virtual void inline_ov004_02169b4c_2();
    virtual void inline_ov004_02169b4c_3();
    virtual void inline_ov004_02169b4c_4();
    virtual void inline_ov004_02169b4c_5();
    virtual void inline_ov004_02169b4c_6();
    virtual void inline_ov004_02169b4c_7();
    virtual void inline_ov004_02169b4c_8(struct Struct_ov004_02169b4c_6* arg0);
    virtual struct Struct_ov004_02169b4c_6 inline_ov004_02169b4c_9();
    char unknown_4_[8];
    unsigned char unknown_c_0_ : 3;
    unsigned char unknown_c_3_ : 1;
    char unknown_d_[0x20 - 0xd];
    char* unknown_20_;
    char unknown_24_[0x45 - 0x24];
    unsigned char unknown_45_0_ : 1;
    unsigned char unknown_45_1_ : 6;
};

extern struct Struct_ov004_02169b4c_4* data_ov004_02171030;
extern char data_ov004_02170704[];

// JPN: func_ov004_02169b4c (0216a044)
// USA: func_ov004_02169b4c
extern "C" ARM int func_ov004_02169b4c(void* arg0) {
    char* var0 = data_ov004_02171030->unknown_190_;
    if (!var0) return 0;

#if defined(jpn)
    struct Struct_ov004_02169b4c_5* var1 = static_cast<Struct_ov004_02169b4c_5*>(func_ov004_02168f08(arg0, 0x64));
#else
    struct Struct_ov004_02169b4c_5* var1 = static_cast<Struct_ov004_02169b4c_5*>(func_ov023_021f6524(arg0, 0x64));
#endif
#if defined(jpn)
    struct Struct_02072a68_2* var2 = func_ov004_02169040(arg0, 3);
#else
    struct Struct_02072a68_2* var2 = func_ov004_02168b08(arg0, 3);
#endif
    void* g = (void*)MessageSystem_GetInstance();
    unsigned char* prot = (unsigned char*)GetFieldAt0x150_02053c6c((unsigned char*)GameState::GetInstance()->GetProtagonist());
    unsigned char* flags = (unsigned char*)Scenario_GetInstance(prot);
#if defined(jpn)
    struct Struct_02072a68_2* var6 = func_ov004_02169040(arg0, 9);
#else
    struct Struct_02072a68_2* var6 = func_ov004_02168b08(arg0, 9);
#endif
#if defined(jpn)
    struct Struct_02072a68_2* var7 = func_ov004_02169040(arg0, 6);
#else
    struct Struct_02072a68_2* var7 = func_ov004_02168b08(arg0, 6);
#endif
#if defined(jpn)
    struct Struct_02072a68_2* var8 = func_ov004_02169040(arg0, 7);
#else
    struct Struct_02072a68_2* var8 = func_ov004_02168b08(arg0, 7);
#endif
    short var9 = var1->unknown_5c_;
    int var10 = func_ov023_021f9bc8((char*)var1);
    int var11 = var10 + var9 * 8;
    if (!func_ov023_021f9b6c((struct Struct_ov004_021549e4_3*)var1, (unsigned short)var10, 0)) return 0;

    struct Struct_ov004_02169b4c_2* var12 = (struct Struct_ov004_02169b4c_2*)(var0 + 4) + var11;
#if !defined(jpn)
    char var13[0x30];
    __clear(var13, 0x30);
#endif
    char* var14;
    struct Struct_ov004_02169b4c* var15;
    if (data_ov004_02171030->unknown_198_) {
        var14 = (char*)(var4 + 0x3c);
        var15 = data_ov004_02171030->unknown_194_;
    } else {
        var15 = &var12->unknown_14_;
#if defined(jpn)
        var14 = var12->unknown_6_;
#else
        Font_DecodeText(area->name, buf, 1);
        name = buf;
#endif
    }

    char* var16 = data_ov004_02171030->unknown_19c_;
    memset(var16, 0, 4);
    Struct_ov004_02169b4c_7* var17;

#if defined(jpn)
    func_02046380(var3);
    char* var18 = static_cast<char*>(func_02072a68(var2, 0x23));
    func_020465c0(static_cast<Struct_020465c0*>(var3), 0, var15->unknown_0_0_);
    func_020465f0(static_cast<unsigned char*>(var3), 0, 4);
    func_020465d8(static_cast<unsigned char*>(var3), 0, 1);
    func_020465c0(static_cast<Struct_020465c0*>(var3), 1, var15->unknown_8_0_);
    func_020465f0(static_cast<unsigned char*>(var3), 1, 2);
    func_020465d8(static_cast<unsigned char*>(var3), 1, 1);
    func_020474a8(var3, 8, var18, var16);
    var17 = static_cast<Struct_ov004_02169b4c_7*>(func_ov004_02168a6c(arg0, 0x190));
    var17->unknown_20_ = var16;
    var16 += strlen(var16) + 1;

    func_02046380(var3);
    func_020465c0(static_cast<Struct_020465c0*>(var3), 0, var15->unknown_4_0_);
    func_020465f0(static_cast<unsigned char*>(var3), 0, 4);
    func_020465d8(static_cast<unsigned char*>(var3), 0, 1);
    func_020465c0(static_cast<Struct_020465c0*>(var3), 1, var15->unknown_8_7_);
    func_020465f0(static_cast<unsigned char*>(var3), 1, 2);
    func_020465d8(static_cast<unsigned char*>(var3), 1, 1);
    func_020474a8(var3, 8, static_cast<char*>(func_02072a68(var2, 0x23)), var16);
    var17 = static_cast<Struct_ov004_02169b4c_7*>(func_ov004_02168a6c(arg0, 0x191));
    var17->unknown_20_ = var16;
    var16 += strlen(var16) + 1;

#else
    var17 = static_cast<Struct_ov004_02169b4c_7*>(func_ov004_02168a6c(arg0, 0x190));
    var17->unknown_45_1_ = 2;
    sprintf(var16, static_cast<char*>(func_02072a68(var2, 0x23)), var15->unknown_0_0_);
    var17->unknown_20_ = var16;
    var16 += strlen(var16) + 1;

    var17 = static_cast<Struct_ov004_02169b4c_7*>(func_ov004_02168a6c(arg0, 0x1c2));
    var17->unknown_45_1_ = 2;
    sprintf(var16, static_cast<char*>(func_02072a68(var2, 0x23)), var15->unknown_8_0_);
    var17->unknown_20_ = var16;
    var16 += strlen(var16) + 1;

    var17 = static_cast<Struct_ov004_02169b4c_7*>(func_ov004_02168a6c(arg0, 0x191));
    var17->unknown_45_1_ = 2;
    sprintf(var16, static_cast<char*>(func_02072a68(var2, 0x23)), var15->unknown_4_0_);
    var17->unknown_20_ = var16;
    var16 += strlen(var16) + 1;

    var17 = static_cast<Struct_ov004_02169b4c_7*>(func_ov004_02168a6c(arg0, 0x1c3));
    var17->unknown_45_1_ = 2;
    sprintf(var16, static_cast<char*>(func_02072a68(var2, 0x23)), var15->unknown_8_7_);
    var17->unknown_20_ = var16;
    var16 += strlen(var16) + 1;

#endif
    func_02046380(var3);
    char* var19;
    if (var15->unknown_14_ >= 700) {
        var19 = static_cast<char*>(func_02072a68(var6, (short)(var15->unknown_14_ + 20000)));
    } else if (var15->unknown_16_0_) {
        var19 = static_cast<char*>(func_02072a68(var8, var15->unknown_14_));
    } else {
        var19 = static_cast<char*>(func_02072a68(var7, var15->unknown_14_));
    }
    MessageSystem_SetStringArgument((struct Obj02046574*)g, 0, title);
    MessageSystem_SetStringArgument((struct Obj02046574*)g, 1, name);
#if defined(jpn)
    func_020474a8(var3, 0xa, static_cast<char*>(func_02072a68(var2, 0x22)), var16);
#else
    MessageSystem_FormatText(g, 0xa, static_cast<char*>(FindEntryByKey_02072a68(tblA, 0x22)), out, 0xf0, 1, 0);
#endif

    var17 = static_cast<Struct_ov004_02169b4c_7*>(func_ov004_02168a6c(arg0, 0x192));
    var17->unknown_20_ = var16;
#if !defined(jpn)
    struct Struct_ov004_02169b4c_6 var20 = var17->inline_ov004_02169b4c_9();
    var20.unknown_4_ = 0x7000;
    if (func_020d2f88(var16, data_ov004_02170704)) var20.unknown_4_ = 0x2000;
    var17->inline_ov004_02169b4c_8(&var20);
#endif
    var16 += strlen(var16) + 1;

    func_02046380(g);
    unsigned char count = 0;
    unsigned char mask = 0;
    struct Blk02169b4c blk;
    LoadBattleBlock020ac4c0(&blk);
    mask |= 1;
    StoreInArray0x8b0_020465c0(static_cast<StoreStruct*>(g), count++, rec->w4B);
    if (Scenario_TestFlag((int)flags, flags + 0x8c, 0x1198)) {
        mask |= 2;
        StoreInArray0x8b0_020465c0(static_cast<StoreStruct*>(g), count++, rec->w0B);
    }
    var22 |= 4;
    func_020465c0(static_cast<Struct_020465c0*>(var3), var21++, var15->unknown_c_0_);
    if (var23.unknown_b_0_) {
        var22 |= 8;
        func_020465c0(static_cast<Struct_020465c0*>(var3), var21++, var15->unknown_10_0_);
    }
    if (var23.unknown_d_6_) {
        var22 |= 0x10;
        func_020465c0(static_cast<Struct_020465c0*>(var3), var21++, var15->unknown_d_2_);
    }
    if (Scenario_TestFlag((int)flags, flags + 0x8c, 0x1199)) {
        mask |= 0x20;
        StoreInArray0x8b0_020465c0(static_cast<StoreStruct*>(g), count++, rec->w10B);
    }

    unsigned char var24 = 0;
    int var25;
    for (var25 = 0; var25 < 6; var25++) {
        if (var22 & (1 << var25)) {
            func_020465f0(static_cast<unsigned char*>(var3), var24, 5);
            func_020465d8(static_cast<unsigned char*>(var3), var24, 1);
            strcpy(var16, static_cast<char*>(func_02072a68(var2, (short)(var25 + 0x28))));
            int var26 = var24 * 3;
            var17 = static_cast<Struct_ov004_02169b4c_7*>(func_ov004_02168a6c(arg0, var26 + 0x1f4));
            if (!var17) continue;
            var17->unknown_20_ = var16;
            var16 += strlen(var16) + 1;
#if defined(jpn)
            func_020474a8(var3, 8, static_cast<char*>(func_02072a68(var2, (short)(var24 + 0x14))), var16);
#else
            MessageSystem_FormatText(g, 8, static_cast<char*>(FindEntryByKey_02072a68(tblA, (short)(k + 0x14))), out, 0x100, 0, 0);
#endif
            var17 = static_cast<Struct_ov004_02169b4c_7*>(func_ov004_02168a6c(arg0, var26 + 0x1f5));
            if (!var17) continue;
            var17->unknown_20_ = var16;
            var16 += strlen(var16) + 1;
            int var27;
            if (var25 == 5) {
                var27 = 0x30;
            } else if ((var25 == 2) | (var25 == 3)) {
                var27 = 0x2f;
            } else {
                var27 = 0x2e;
            }
            strcpy(var16, static_cast<char*>(func_02072a68(var2, var27)));
            var17 = static_cast<Struct_ov004_02169b4c_7*>(func_ov004_02168a6c(arg0, var26 + 0x1f6));
            if (!var17) continue;
            var17->unknown_20_ = var16;
            var16 += strlen(var16) + 1;
            var24++;
        }
    }
    for (int var28 = var24; var28 < 6; var28++) {
        int var29 = var28 * 3;
        (static_cast<Struct_ov004_02169b4c_7*>(func_ov004_02168a6c(arg0, var29 + 0x1f4)))->unknown_c_3_ = 1;
        (static_cast<Struct_ov004_02169b4c_7*>(func_ov004_02168a6c(arg0, var29 + 0x1f5)))->unknown_c_3_ = 1;
        (static_cast<Struct_ov004_02169b4c_7*>(func_ov004_02168a6c(arg0, var29 + 0x1f6)))->unknown_c_3_ = 1;
    }

    func_02046380(var3);
    func_020465c0(static_cast<Struct_020465c0*>(var3), 0, var15->unknown_9_6_);
    func_020465f0(static_cast<unsigned char*>(var3), 0, 3);
    func_020465d8(static_cast<unsigned char*>(var3), 0, 1);
    func_020465c0(static_cast<Struct_020465c0*>(var3), 1, var15->unknown_f_0_);
    func_020465f0(static_cast<unsigned char*>(var3), 1, 3);
    func_020465d8(static_cast<unsigned char*>(var3), 1, 1);
    func_020465c0(static_cast<Struct_020465c0*>(var3), 2, var15->unknown_a_5_);
    func_020465f0(static_cast<unsigned char*>(var3), 2, 3);
    func_020465d8(static_cast<unsigned char*>(var3), 2, 1);
    func_020465c0(static_cast<Struct_020465c0*>(var3), 3, var15->unknown_12_7_);
    func_020465f0(static_cast<unsigned char*>(var3), 3, 3);
    func_020465d8(static_cast<unsigned char*>(var3), 3, 1);

    int var30 = (var22 & 2) ? 4 : 3;
    for (int var31 = 0; var31 < var30; var31++) {
#if defined(jpn)
        func_020474a8(var3, 8, static_cast<char*>(func_02072a68(var2, (short)(var31 + 0x1e))), var16);
#else
        MessageSystem_FormatText(g, 8, static_cast<char*>(FindEntryByKey_02072a68(tblA, (short)(r + 0x1e))), out, 0x100, 0, 0);
#endif
        (static_cast<Struct_ov004_02169b4c_7*>(func_ov004_02168a6c(arg0, var31 * 2 + 6 + 0x200)))->unknown_20_ = var16;
        var16 += strlen(var16) + 1;
    }
    if (var30 == 3) {
        (static_cast<Struct_ov004_02169b4c_7*>(func_ov004_02168a6c(arg0, 0x19c)))->unknown_c_3_ = 1;
        (static_cast<Struct_ov004_02169b4c_7*>(func_ov004_02168a6c(arg0, 0x20c)))->unknown_c_3_ = 1;
        (static_cast<Struct_ov004_02169b4c_7*>(func_ov004_02168a6c(arg0, 0x20d)))->unknown_c_3_ = 1;
    }

#if defined(jpn)
    {
        void* var32 = func_ov004_02168fa4(arg0, 0x18);
        if (var32 != 0) func_ov023_021f809c(var32, arg0);
    }
    {
        void* var33 = func_ov004_02168fa4(arg0, 0x19);
        if (var33 != 0) func_ov023_021f809c(var33, arg0);
    }
    {
        void* var34 = func_ov004_02168fa4(arg0, 0x1c);
        if (var34 != 0) func_ov023_021f809c(var34, arg0);
    }
    {
        void* var35 = func_ov004_02168fa4(arg0, 0x1a);
        if (var35 != 0) func_ov023_021f809c(var35, arg0);
    }
    {
        void* var36 = func_ov004_02168fa4(arg0, 0x1d);
        if (var36 != 0) func_ov023_021f809c(var36, arg0);
    }
    {
        void* var37 = func_ov004_02168fa4(arg0, 0x1b);
        if (var37 != 0) func_ov023_021f809c(var37, arg0);
    }
#else
    func_ov023_021f6680(arg0, 0x18);
    func_ov023_021f6680(arg0, 0x19);
    func_ov023_021f6680(arg0, 0x1c);
    func_ov023_021f6680(arg0, 0x1a);
    func_ov023_021f6680(arg0, 0x1d);
    func_ov023_021f6680(arg0, 0x1b);
#endif
    return 0;
}
