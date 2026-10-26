#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct Struct_ov012_02188640 {
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
struct TableA68;
struct SePlayer;
struct Obj021e6e20;
struct Struct0205de24;
struct Struct_0205c570;
extern "C" void func_0205de24(Struct_0205de24_2*, unsigned char, unsigned char);
extern "C" void func_ov023_021e6e60(void*);
void SetupBattleTag0218a574(char*);
int Window_GetSelectedIndex(Struct_0205c570*);
extern "C" int func_ov023_021e6448(void*);
extern "C" int func_ov023_021e7148(void*);
void SePlayer_Play(SePlayer*, int, int);
extern "C" void LinkSession_GetInstance();
int GameState_GetStoryChapter(char*);
const char* FindEntryByKey_02072a68(TableA68*, int);
extern "C" void func_ov012_0218bba0(void*, int, int);
extern "C" void func_ov012_02189be8(void*, int);
int TestFlagsAndActiveElement2_021e6e20(Obj021e6e20*);
extern "C" char g_sePlayer[];

static inline Struct_ov012_02188640* inline_ov012_02188640(GameState* arg0) {
    return (Struct_ov012_02188640*)((char*)arg0 + 0x543c);
}

extern "C" ARM void func_ov012_02188640(char* arg0) {
    if (*(unsigned char*)(arg0 + 0x1340) == 0) {
        *(unsigned char*)(arg0 + 0x1368) = 0;
        GameState* var0 = GameState::GetInstance();
        Struct_ov012_02188640* var1 = inline_ov012_02188640(var0);
        unsigned int var2;
        if (!var1->unknown_3_6_ && var1->unknown_6_3_ >= 800 && var1->unknown_6_3_ < 860)
            var2 = var1->unknown_6_3_ - 799;
        else
            var2 = 0;
        *(unsigned int*)(arg0 + 0x1444) = var2;
        func_0205de24((Struct_0205de24_2*)(arg0 + 0x90), 0, 3);
        func_ov023_021e6e60(arg0);
        func_ov012_0218a574(arg0);
        ++*(unsigned char*)(arg0 + 0x1340);
        return;
    } else if (*(unsigned char*)(editor + 0x1340) == 1) {
        *(unsigned char*)(editor + 0x1368) = 1;
        *(int*)(editor + 0x1444) = Window_GetSelectedIndex((Struct_0205c570*)(editor + 0x90));
        if (func_ov023_021e6448(editor))
            *(int*)(editor + 0x1444) = Window_GetSelectedIndex((Struct_0205c570*)(editor + 0x90));
        if (func_ov023_021e7148(editor)) {
            SePlayer_Play((SePlayer*)g_sePlayer, 1, 0);
            ProfileAccolade* profile = GetProfileAccolade(GameState::GetInstance());
            GameState* state = GameState::GetInstance();
            LinkSession_GetInstance();
            if (*(int*)(editor + 0x1444) == 0) {
                char* character = *(char**)((char*)state->GetProtagonist() + 0x144);
                int vocation = *(int*)(character + 0x8b8);
                profile->vocationAccolade = 1;
                profile->accolade = vocation + 700;
                if (GameState_GetStoryChapter((char*)state) == 1)
                    profile->accolade = 713;
            } else {
                var3->unknown_6_3_ = *(int*)(arg0 + 0x1444) + 799;
                var3->unknown_3_6_ = 0;
            }
            const char* var7 = func_02072a68((Struct_02072a68_2*)(arg0 + 0x1314), (short)(var3->unknown_6_3_ + 20000));
            memset(arg0 + 0x1458, 0, 0x40);
            memcpy(arg0 + 0x1458, var7, strlen(var7));
            var3->unknown_3_5_ = 1;
            func_ov012_0218bba0(arg0, 0, -1);
            func_ov012_02189be8(arg0, 0);
            return;
        }
        if (func_ov023_021e6e20((Struct_ov012_02186a7c*)arg0))
            func_ov012_02189be8(arg0, 1);
        return;
    }
}

#else
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct Struct_ov012_02188640_2
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

struct Struct_ov012_02188640_3
{
    short models_[10];
    unsigned char female_ : 1;
    unsigned char skinColor_ : 3;
    unsigned char eyeColor_ : 4;
    char unk_15[0x1c - 0x15];
};

struct Struct_ov012_02188640_4
{
    char unknown_0_[0x488];
    Struct_ov012_02188640_3 unknown_488_;
    char unknown_4a4_[0x950 - 0x4a4];
    int unknown_950_;
};

struct Struct_ov012_02188640_5
{
    char unknown_0_[0x150];
    Struct_ov012_02188640_4* unknown_150_;
};

struct Struct_ov012_02188640_6
{
    char unknown_0_[0xac];
    char unknown_ac_[0x133c - 0xac];
    char unknown_133c_[0x1370 - 0x133c];
    unsigned char unknown_1370_;
    unsigned char unknown_1371_;
    char unknown_1372_[0x13a0 - 0x1372];
    unsigned char unknown_13a0_;
    char unknown_13a1_[0x13d8 - 0x13a1];
    int unknown_13d8_[6];
    char unknown_13f0_[0x1400 - 0x13f0];
    char unknown_1400_[0x40];
};

struct TableA68;
struct SePlayer;
struct Obj021e6e20;
struct Struct0205de24;
struct Struct_0205c570;

void FindAndLinkMatchingEntry0205de24(Struct0205de24* window, unsigned char a, unsigned char b);
extern "C" void func_ov023_021e6e60(ProfileEditor02188640* self);
void SetupBattleTag0218a574(char* self);
int Window_GetSelectedIndex(Struct_0205c570* window);
extern "C" int func_ov023_021e6448(ProfileEditor02188640* self);
extern "C" int func_ov023_021e6de4(ProfileEditor02188640* self);
void SePlayer_Play(SePlayer* sound, int effect, int a);
extern "C" void LinkSession_GetInstance();
int GameState_GetStoryChapter(char* gameState);
const char* FindEntryByKey_02072a68(TableA68* table, int key);
extern "C" void func_ov012_0218adac(ProfileEditor02188640* self, int animate, int design, int keepPage);
extern "C" void func_ov012_0218930c(ProfileEditor02188640* self, int cancel);
int TestFlagsAndActiveElement2_021e6e20(Obj021e6e20* self);

extern "C" char g_sePlayer[];

static inline Struct_ov012_02188640_2* inline_ov012_02188640_2(GameState* arg0)
{
    return (Struct_ov012_02188640_2*)((char*)arg0 + 0x569c);
}

// USA: func_ov012_02188640
extern "C" ARM void func_ov012_02188640(Struct_ov012_02188640_6* arg0)
{
    if (arg0->unknown_1370_ == 0)
    {
        arg0->unknown_13a0_ = 0;
        GameState* var8 = GameState::GetInstance();
        unsigned int var9;
        if (!inline_ov012_02188640_2(var8)->unknown_3_6_)
        {
            int var10 = inline_ov012_02188640_2(var8)->unknown_6_3_;
            if (var10 >= 800 && var10 < 900)
            {
                var9 = var10 - 799;
                goto found;
            }
            if (var10 >= 900 && var10 < 1000)
            {
                var9 = var10 - 899;
                goto found;
            }
        }
        var9 = 0;
    found:
        arg0->unknown_13d8_[5] = var9;
        func_0205de24((Struct_0205de24_2*)arg0->unknown_ac_, 0, 3);
        func_ov023_021e6e60(arg0);
        func_ov012_0218a574((char*)arg0);
        arg0->unknown_1370_++;
        return;
    }
    else if (arg0->unknown_1370_ == 1)
    {
        self->unk_13a0 = 1;
        self->selections_[5] = Window_GetSelectedIndex((Struct_0205c570*)self->window_);
        if (func_ov023_021e6448(self))
            self->selections_[5] = Window_GetSelectedIndex((Struct_0205c570*)self->window_);
        if (func_ov023_021e6de4(self))
        {
            SePlayer_Play((SePlayer*)g_sePlayer, 1, 0);
            Profile02188640* profile = GetProfile02188640(GameState::GetInstance());
            GameState* gameState = GameState::GetInstance();
            LinkSession_GetInstance();
            Member02188640* protagonist = (Member02188640*)gameState->GetProtagonist();
            if (self->selections_[5] == 0)
            {
                Party02188640* data = protagonist->partyData_;
                int accolade = 0x50dc;
                if (data->appearance_.female_ == 1)
                    accolade = 0x510e;
                int vocation = data->vocation_;
                profile->vocationAccolade_ = 1;
                profile->accolade_ = accolade + vocation - 0x4e20;
                if (GameState_GetStoryChapter((char*)gameState) == 1)
                    profile->accolade_ = accolade + 13 - 0x4e20;
            }
            else
            {
                int var17 = 0x5140;
                if (var13->unknown_150_->unknown_488_.unknown_14_0_ == 1)
                    var17 = 0x51a4;
                var11->unknown_6_3_ = var17 + arg0->unknown_13d8_[5] - 0x4e21;
                var11->unknown_3_6_ = 0;
            }
            const char* var18 = func_02072a68((Struct_02072a68_2*)arg0->unknown_133c_, (short)(var11->unknown_6_3_ + 20000));
            memset(arg0->unknown_1400_, 0, sizeof(arg0->unknown_1400_));
            memcpy(arg0->unknown_1400_, var18, strlen(var18));
            var11->unknown_3_5_ = 1;
            func_ov012_0218adac(arg0, 0, -1, 0);
            func_ov012_0218930c(arg0, 0);
            return;
        }
        if (func_ov023_021e6e20((Struct_ov012_02186a7c*)arg0))
            func_ov012_0218930c(arg0, 1);
        return;
    }
}

#endif
