#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

int GameState_GetStoryChapter(char* game);
extern "C" void* LinkSession_GetInstance(void);

struct Struct_02072a68_2 { struct Struct_02072a68* unknown_0_; short unknown_4_; };
extern "C" void* func_02072a68(Struct_02072a68_2* arg0, int arg1);

struct Struct_ov023_021e66ac_3 {
    unsigned int unknown_0_0_ : 29;
    unsigned int unknown_3_5_ : 1;
    unsigned int unknown_3_6_ : 1;
    unsigned int unknown_3_7_ : 1;
    unsigned int unknown_4_0_ : 9;
    signed int unknown_5_1_ : 10;
    unsigned int unknown_6_3_ : 13;
};

struct Struct_ov023_021e66ac_4 {
#if defined(jpn)
    unsigned char unknown_0_[0x543c];
#else
    unsigned char unknown1_0_[0x569c];
#endif
    Struct_ov023_021e66ac_3 unknown_569c_;
};

struct Struct_ov023_021e66ac_5 {
#if defined(jpn)
    unsigned char unknown_0_[0x1314];
    Struct_02072a68_2 unknown_133c_;
    unsigned char unknown_131c_[0x1458 - 0x131c];
#else
    unsigned char unknown1_0_[0x133c];
    Struct_02072a68_2 unknown_133c_;
    unsigned char unknown_1344_[0x1400 - 0x1344];
#endif
    char unknown_1400_[0x40];
    char unknown_1440_[0x40];
};

struct Struct_ov023_021e66ac {
    unsigned char unknown_0_[0x49c];
    unsigned char unknown_49c_0_ : 1;
#if defined(jpn)
    unsigned char unknown_49d_[0x8b8 - 0x49d];
#else
    unsigned char unknown1_49d_[0x950 - 0x49d];
#endif
    int unknown_950_;
};

struct Struct_ov023_021e66ac_2 {
#if defined(jpn)
    unsigned char unknown_0_[0x144];
#else
    unsigned char unknown1_0_[0x150];
#endif
    Struct_ov023_021e66ac* unknown_150_;
};

// USA: func_ov023_021e66ac
extern "C" ARM void func_ov023_021e66ac(void* arg0) {
    Struct_ov023_021e66ac_5* var0 = (Struct_ov023_021e66ac_5*)arg0;
    GameState* var1 = GameState::GetInstance();
    Struct_ov023_021e66ac_3* var2 = &((Struct_ov023_021e66ac_4*)var1)->unknown_569c_;

    if (!profile->accoladeChosen) {
        memset(self->accoladeText, 0, sizeof(self->accoladeText));
        void* entry = FindEntryByKey_02072a68(&self->strings, 0x6d);
        memcpy(self->accoladeText, entry, 7);
    } else if (profile->vocationAccolade) {
        LinkSession_GetInstance();
        ProfileProtagonist* protagonist = (ProfileProtagonist*)game->GetProtagonist();
        int vocation = protagonist->partyData->vocation;
        if (GameState_GetStoryChapter((char*)game) == 1) {
            vocation = 13;
        }
        int var6 = 0x50dc;
#if !defined(jpn)
        if (var4->unknown_150_->unknown_49c_0_ == 1) {
            var6 += 0x32;
        }
#endif
        short var7 = (short)(var6 + var5);
        char* var8 = (char*)func_02072a68(&var0->unknown_133c_, var7);
        memset(var0->unknown_1400_, 0, sizeof(var0->unknown_1400_));
        unsigned int var9 = strlen(var8);
        memcpy(var0->unknown_1400_, var8, var9);
    }

    if (var2->unknown_5_1_ != 300) {
        return;
    }

    memset(var0->unknown_1440_, 0, sizeof(var0->unknown_1440_));
    char* var10 = (char*)func_02072a68(&var0->unknown_133c_, 0x6d);
    unsigned int var11 = strlen(var10);
    memcpy(var0->unknown_1440_, var10, var11);
}
