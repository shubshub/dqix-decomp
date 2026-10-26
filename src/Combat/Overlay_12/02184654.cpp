#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct Struct_ov012_02184654 {
    unsigned int unknown_0_0_ : 12;
    unsigned int unknown_1_4_ : 4;
    unsigned int unknown_2_0_ : 5;
    unsigned int unknown_2_5_ : 4;
    unsigned int unknown_3_1_ : 1;
    unsigned int unknown_3_2_ : 1;
    unsigned int unknown_3_3_ : 1;
    unsigned int unknown_3_4_ : 1;
    unsigned int unknown_3_5_ : 1;
    unsigned int unknown_3_6_ : 1;
    unsigned int unknown_3_7_ : 1;
    unsigned int unknown_4_0_ : 9;
    int unknown_5_1_ : 10;
    int unknown_6_3_ : 11;
    int unknown_7_6_ : 1;
    unsigned int unknown_7_7_ : 1;
    signed char unknown_8_[116];
};
struct AppearanceFlags02184654 {
    unsigned char female : 1;
    unsigned char skinColor : 3;
    unsigned char eyeColor : 4;
};
struct Struct_ov012_02184654_9 {
    short unknown_0_[10];
    Struct_ov012_02184654_8 unknown_14_;
};
struct TableA68;
struct Container020e0310;
extern "C" void* LinkSession_GetInstance();
unsigned char* GetFieldAt0x150_02053c6c(unsigned char*);
int CalculateAge_02098f20(int, int, int);
void* FindEntryByKey_02072a68(TableA68*, int);
int KeyTable_Get(Container020e0310*, int);
extern "C" void func_ov023_021e66ac(void*);

static inline Struct_ov012_02184654* inline_ov012_02184654(GameState* arg0) {
    return (Struct_ov012_02184654*)((char*)arg0 + 0x543c);
}

// USA: func_ov012_02184654
extern "C" ARM void func_ov012_02184654(char* editor) {
    GameState* gameState = GameState::GetInstance();
    ProfileHeader02184654* profile = GetProfile02184654(gameState);
    signed char padding[3];
    memcpy(padding, FindEntryByKey_02072a68((TableA68*)(editor + 0x1314), 113), 3);
    LinkSession_GetInstance();
    unsigned char* characterData = 0;
    GameObject* protagonist = gameState->GetProtagonist();
    if (protagonist)
        characterData = GetFieldAt0x150_02053c6c((unsigned char*)protagonist);
    if (!characterData) return;
    *(void**)(editor + 0x1408) = characterData + 0x3c;

    if (!var1->unknown_3_2_) {
        var1->unknown_0_0_ = 2000;
        var1->unknown_1_4_ = 1;
        var1->unknown_2_0_ = 1;
        var1->unknown_3_7_ = 1;
        Struct_ov012_02184654_9* var5 = (Struct_ov012_02184654_9*)(var3 + 0x488);
        var1->unknown_3_1_ = var5->unknown_14_.unknown_0_0_;
        var1->unknown_2_5_ = var5->unknown_14_.unknown_0_0_;
        var1->unknown_5_1_ = 300;
        char* var6 = *(char**)((char*)var4 + 0x144);
        var1->unknown_6_3_ = *(int*)(var6 + 0x8b8) + 700;
        int var7;
        signed char* var8 = var1->unknown_8_;
        for (var7 = 0; var7 < 57; var7++, var8 += 2) {
            memcpy(var8, var2, 2);
        }
        var1->unknown_3_2_ = 1;
    }
    var1->unknown_4_0_ = func_02098f20(var1->unknown_0_0_, var1->unknown_1_4_, var1->unknown_2_0_);
    signed char* var9 = var1->unknown_8_;
    while (*(unsigned char*)(arg0 + 0x1375) < 114) {
        if (var9[0] == var2[0] && var9[1] == var2[1]) break;
        *(unsigned char*)(arg0 + 0x1375) += 2;
        var9 += 2;
    }
    const char* label = (const char*)FindEntryByKey_02072a68((TableA68*)(editor + 0x1314), (short)(profile->title + 10000));
    memcpy(editor + 0x1498, label, strlen(label));
    if (profile->accolade < 700)
        label = (const char*)KeyTable_Get((Container020e0310*)(editor + 0x131c), (short)profile->accolade);
    else
        var10 = (const char*)func_02072a68((Struct_02072a68_2*)(arg0 + 0x1314), (short)(var1->unknown_6_3_ + 20000));
    memcpy(arg0 + 0x1458, var10, strlen(var10));
    func_ov023_021e66ac(arg0);
}
#else
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct Struct_ov012_02184654_2
{
    unsigned int unknown_0_0_ : 12;
    unsigned int unknown_1_4_ : 4;
    unsigned int unknown_2_0_ : 5;
    unsigned int unknown_2_5_ : 4;
    unsigned int unknown_3_1_ : 1;
    unsigned int unknown_3_2_ : 1;
    unsigned int unknown_3_3_ : 1;
    unsigned int unknown_3_4_ : 1;
    unsigned int unknown_3_5_ : 1;
    unsigned int unknown_3_6_ : 1;
    unsigned int unknown_3_7_ : 1;
    unsigned int unknown_4_0_ : 9;
    int unknown_5_1_ : 10;
    int unknown_6_3_ : 11;
    int unknown_7_6_ : 1;
    unsigned int unknown_7_7_ : 1;
};

struct Struct_01ff8b48_4
{
    char unknown_0_[0x5400];
    Struct_ov012_02184654_2 unknown_5400_;
};

struct Struct_01ff8b48_5
{
    char unknown_0_[0x29c];
    Struct_01ff8b48_4 unknown_29c_;
};

struct Struct_ov012_02184654_3
{
    char pad0[0x14];
    unsigned char female_ : 1;
    unsigned char skinColor_ : 3;
    unsigned char eyeColor_ : 4;
    char pad1[0x488 - 0x15];
};

struct Struct_ov012_02184654_4
{
    Struct_ov012_02184654_3 unknown_0_[2];
};

struct Struct_ov012_02184654_5
{
    char unknown_0_[0x49c];
    unsigned char unknown_49c_0_ : 1;
    char unknown_49d_[0x950 - 0x49d];
    int unknown_950_;
};

struct Struct_ov012_02184654_6
{
    char unknown_0_[0x150];
    Struct_ov012_02184654_5* unknown_150_;
};

struct Struct_02072a68_2;
struct Struct_0201099c_3;

struct Struct_ov012_02184654_7
{
    char unknown_0_[0x133c];
    char unknown_133c_[8];
    char unknown_1344_[0x13b0 - 0x1344];
    void* unknown_13b0_;
    char unknown_13b4_[0x1400 - 0x13b4];
    char unknown_1400_[0x40];
    char unknown_1440_[0x40];
};

extern "C" void* LinkSession_GetInstance();
unsigned char* GetFieldAt0x150_02053c6c(unsigned char* obj);
int CalculateAge_02098f20(int year, int month, int day);
void* FindEntryByKey_02072a68(struct TableA68* table, int key);
int KeyTable_Get(struct Container020e0310* texts, int key);
extern "C" void func_ov023_021e66ac(ProfileEditor02184654* self);

static inline Struct_ov012_02184654_2* inline_ov012_02184654(GameState* arg0)
{
    return &((Struct_01ff8b48_5*)arg0)->unknown_29c_.unknown_5400_;
}

static inline Struct_ov012_02184654_3* inline_ov012_02184654_2(Struct_ov012_02184654_4* arg0, int arg1)
{
    return (Struct_ov012_02184654_3*)(void*)arg0->unknown_0_ + arg1;
}

// USA: func_ov012_02184654
extern "C" ARM void func_ov012_02184654(Struct_ov012_02184654_7* arg0)
{
    GameState* gameState = GameState::GetInstance();
    Profile02184654* profile = GetProfile02184654(gameState);
    LinkSession_GetInstance();
    Field02184654* field = 0;
    Member02184654* protagonist = (Member02184654*)gameState->GetProtagonist();
    if (protagonist != 0)
        field = (Field02184654*)GetFieldAt0x150_02053c6c((unsigned char*)protagonist);
    if (field == 0)
        return;

    arg0->unknown_13b0_ = (char*)var13 + 0x3c;

    void* var15;
    if (!var12->unknown_3_2_)
    {
        var12->unknown_0_0_ = 2000;
        var12->unknown_1_4_ = 1;
        var12->unknown_2_0_ = 1;
        var12->unknown_3_7_ = 1;
        Struct_ov012_02184654_3* var16 = inline_ov012_02184654_2(var13, 1);
        int var17 = 0x50dc;
        var12->unknown_3_1_ = var16->unknown_14_0_;
        var12->unknown_2_5_ = var16->unknown_14_0_;
        var12->unknown_5_1_ = 300;
        Struct_ov012_02184654_5* var18 = var14->unknown_150_;
        if (var18->unknown_49c_0_ == 1)
            var17 += 0x32;
        var12->unknown_6_3_ = var17 + var18->unknown_950_ - 0x4e20;
        memset((char*)var12 + 8, 0, 0x74);
        var12->unknown_3_2_ = 1;
    }

    var12->unknown_4_0_ = func_02098f20(var12->unknown_0_0_, var12->unknown_1_4_, var12->unknown_2_0_);

    var15 = func_02072a68((struct Struct_02072a68_2*)arg0->unknown_133c_, (short)(var12->unknown_5_1_ + 10000));
    memcpy(arg0->unknown_1440_, var15, strlen((char*)var15));

    if (profile->accolade_ < 700)
        name2 = (void*)KeyTable_Get((struct Container020e0310*)self->texts_, (short)profile->accolade_);
    else
        var15 = func_02072a68((struct Struct_02072a68_2*)arg0->unknown_133c_, (short)(var12->unknown_6_3_ + 20000));
    memcpy(arg0->unknown_1400_, var15, strlen((char*)var15));

    func_ov023_021e66ac(arg0);
}
#endif
