#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include <Filesystem/BackgroundLoader.h>
#include <Memory/SafeAllocator.h>
#include <GameState/GameState.h>
#include "Resource/GameResources.h"



struct GameResources;
struct Struct_02048150;
struct Struct_0205d6a0;
struct Struct_02072a68_2;
struct Struct_ov002_021682c0;
struct Struct_ov023_021eeaac_2;

struct Struct_ov023_021f1234_4 {
#if defined(jpn)
    char unknown_0_[0x868];
#else
    char unknown1_0_[0x998];
#endif

    int unknown_998_;
    char unknown_99c_[4];
    int unknown_9a0_;
#if defined(jpn)
    char unknown_874_[0x17df - 0x874];
#else
    char unknown_9a4_[0x19af - 0x9a4];
#endif

    unsigned char unknown_19af_;
#if defined(jpn)
    char unknown_17e0_[0x17e2 - 0x17e0];
#else
    char unknown_19b0_[0x19b2 - 0x19b0];
#endif

    unsigned char unknown_19b2_;
};

struct Struct_ov023_021f1234_5 {
    char unknown_0_[0x18];
    void* unknown_18_;
    short unknown_1c_;
#if defined(jpn)
    char unknown_1e_[0x5e4 - 0x1e];
#else
    char unknown1_1e_[0x65c - 0x1e];
#endif

    int unknown_65c_;
};

struct Struct_ov023_021f1234 {
#if defined(jpn)
    char unknown_0_[0x53];
#else
    char unknown1_0_[0x67];
#endif

    unsigned char unknown_67_;
};

struct Struct_ov023_021f1234_2 {
    int unknown_0_;
    char unknown_4_[0x18 - 4];
    int unknown_18_;
    char unknown_1c_[0x74 - 0x1c];
    unsigned short unknown_74_[55];
    unsigned char unknown_e2_;
    unsigned char unknown_e3_;
    char unknown_e4_[0xe8 - 0xe4];
    char unknown_e8_[8];
};

struct Struct_ov023_021f1234_3 {
    char unknown_0_[0x30];
    SafeAllocator unknown_30_;
#if defined(jpn)
    char unknown_44_[0xe28 - 0x44];
#else
    char unknown1_44_[0xeac - 0x44];
#endif

    int unknown_eac_;
#if defined(jpn)
    char unknown_e2c_[0x371c - 0xe2c];
#else
    char unknown_eb0_[0x3760 - 0xeb0];
#endif

#if defined(jpn)
    char unknown_3760_[0x52e4 - 0x371c];
#else
    char unknown_3760_[0x5228 - 0x3760];
#endif

    SafeAllocator unknown_5228_;
#if defined(jpn)
    char unknown_52f8_[0x5768 - 0x52f8];
#else
    char unknown_523c_[0x5574 - 0x523c];
#endif

    Struct_ov023_021f1234_5* unknown_5574_;
    Struct_ov023_021f1234* unknown_5578_;
#if defined(jpn)
    char unknown_5770_[0x5774 - 0x5770];
#else
    char unknown_557c_[0x5584 - 0x557c];
#endif

    unsigned char unknown_5584_;
    char unknown_5585_[3];
    void* unknown_5588_;
#if defined(jpn)
    char unknown_577c_[0x5af4 - 0x577c];
#else
    char unknown_558c_[0x5904 - 0x558c];
#endif

    char unknown_5904_[4];
};

extern "C" BattleEnd_021f1234* _ZZ17GetGlobal021ffefcvE1s;
extern char g_sePlayer[];

MessageSystem_021f1234* MessageSystem_GetInstance();
int ArrayContainsByte_02086ef0(ArrayContainsByteStruct* array, int id);
void InitCombatEntry_021d8b6c(void* window);
void Window_ClosePane(Entry_0205d6a0* window, int value);
int Scenario_TestFlag(int a, unsigned char* b, int flag);
extern "C" void Scenario_SetFlag(void* a, unsigned char* b, int flag, int value);
const char* FindEntryByKey_02072a68(TableA68* texts, int id);
void MessageSystem_Reset(char* messages);
void SetMainBrightness(GameResources* resources, int brightness, int duration);
int IsMainBrightnessTransitionActive(GameResources* resources);
void ZeroInit020de868(void* icons);
void InitAllocatorArray02186e74(Container02186e74* abilities, SafeAllocator* allocator);
void SePlayer_LoadArchive(void* sound, int mode);
unsigned char* GetFieldAt0x150_02053c6c(unsigned char* member);
void ResetFields_021eefac(Reset_021eefac* end);

extern "C" {
void* Scenario_GetInstance();
void func_ov023_021f1818(void* menu, int hidden);
void func_ov023_021d8af8(void* window);
void func_ov013_02184360(SkillPointMenu_021f1234* menu, void* parent);
void func_ov013_02184cf0(SkillPointMenu_021f1234* menu, SafeAllocator* allocator);
#if !defined(jpn)
void func_0204500c(Struct_ov023_021f1234_4* arg0, const char* arg1, int arg2, int arg3);
#endif
#if defined(jpn)
void func_0204500c(Struct_ov023_021f1234_4*,const char*,int);
#endif
int func_ov023_021f4fc8();
void func_ov013_02186eec(SkillAbilityList_021f1234* abilities, int a);
void func_ov013_02184b4c(SkillPointMenu_021f1234* menu, void* member);
int func_ov013_021870f0(SkillAbilityList_021f1234* abilities);
unsigned char func_ov013_021847c4(void* menu, int ticks);
void func_ov013_0218782c(SkillAbilityList_021f1234* abilities, int member, int skill);
void func_ov013_02186fa0(SkillAbilityList_021f1234* abilities);
void func_ov013_02184c8c(SkillPointMenu_021f1234* menu, void* member);
unsigned char func_0209a678(char* table, void* member, unsigned short* skills);
void PartyMember_RecalculateStats(unsigned char* data, int a);
void func_ov017_021cc730(int id, int a, int b, int c);
void func_ov017_021ccc34(int id);
void func_ov017_021c9e00(int id, int a, int b, int c);
void func_ov017_021cd0d8(int id, unsigned short* skills, int count);
}

// USA: func_ov023_021f1234
extern "C" ARM int func_ov023_021f1234(Struct_ov023_021f1234_3* arg0)
{
    GameState* gameState = GameState::GetInstance();
    BattleEnd_021f1234* end = _ZZ17GetGlobal021ffefcvE1s;
    GameResources* resources = GetGameResources();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    void* unk = Scenario_GetInstance();
    MessageSystem_021f1234* messages = MessageSystem_GetInstance();
    int id = end->current_;
    int inParty = ArrayContainsByte_02086ef0((ArrayContainsByteStruct*)GameState_GetParty(gameState), id);
    if (self->skillMenu_ == NULL)
    {
        if (arg0->unknown_5588_ != NULL)
        {
            func_ov023_021f1818(arg0->unknown_3760_, 1);
            func_ov023_021d8b6c(arg0->unknown_5588_);
            func_ov023_021d8af8(arg0->unknown_5588_);
            arg0->unknown_5588_ = NULL;
        }
        Window_ClosePane((Entry_0205d6a0*)&self->menu_[0x188], 1);
        self->allocator_.Reset();
#if defined(jpn)
        arg0->unknown_5574_ = (Struct_ov023_021f1234_5*)arg0->unknown_30_.Allocate(0x654);
#else
        arg0->unknown_5574_ = (Struct_ov023_021f1234_5*)arg0->unknown_30_.Allocate(0x6cc);
#endif
        func_ov013_02184360(arg0->unknown_5574_, arg0->unknown_3760_);
        func_ov013_02184cf0(arg0->unknown_5574_, &arg0->unknown_30_);
        Struct_ov023_021f1234_5* var8 = arg0->unknown_5574_;
        var8->unknown_18_ = &arg0->unknown_3760_[0x11c];
        var8->unknown_1c_ = 0;
        arg0->unknown_5584_ = 0;
    }
    else if (arg0->unknown_5574_ != NULL)
    {
        if (var1->unknown_0_ == 0)
        {
            if (!Scenario_TestFlag((int)unk, (unsigned char*)unk + 0x8c, 0x119c))
            {
                Scenario_SetFlag(unk, (unsigned char*)unk + 0x8c, 0x119c, 1);
                if (inParty)
                {
#if defined(jpn)
                    func_0204500c(var5, func_02072a68((Struct_02072a68_2*)arg0->unknown_5904_, 0x24), 1);
#else
                    func_0204500c(var5, func_02072a68((Struct_02072a68_2*)arg0->unknown_5904_, 0x24), 1, 0xe3);
#endif

                    var5->unknown_19b2_ = 0;
                    var5->unknown_998_ = 1;
                }
                var1->unknown_0_ = 100;
            }
            else
            {
                MessageSystem_Reset((char*)messages);
                SetMainBrightness(resources, -0x10, 0x10);
                end->step_++;
            }
        }
        else if (var1->unknown_0_ == 100)
        {
            if (var5->unknown_9a0_ == 3)
                var5->unknown_19af_ = 0;
            if (func_ov023_021f4fc8())
            {
                MessageSystem_Reset((char*)messages);
                SetMainBrightness(resources, -0x10, 0x10);
                end->step_ = 1;
            }
        }
        else if (var1->unknown_0_ == 1)
        {
            if (!IsMainBrightnessTransitionActive(var2))
            {
                end->step_++;
                MessageSystem_Reset((char*)messages);
                ZeroInit020de868(&self->menu_[0xd0]);
                SafeAllocator* allocator = &self->menuAllocator_;
                allocator->Reset();
#if defined(jpn)
                arg0->unknown_5578_ = (Struct_ov023_021f1234*)var9->Allocate(0x58);
#else
                arg0->unknown_5578_ = (Struct_ov023_021f1234*)var9->Allocate(0x6c);
#endif

                func_ov013_02186eec(arg0->unknown_5578_, 0);
                func_ov013_02186e74((Struct_ov002_021682c0*)arg0->unknown_5578_, var9);
                GameObject* var10 = func_0200ff1c(var0, var6);
                if (var10 != NULL)
                {
                    func_ov013_02184b4c(self->skillMenu_, member);
                    self->abilities_->member_ = member->obj3D_.actorIndex_;
                }
            }
        }
        else if (var1->unknown_0_ == 2)
        {
            if (func_ov013_021870f0(arg0->unknown_5578_))
                var1->unknown_0_++;
        }
        else if (var1->unknown_0_ == 3)
        {
            SetMainBrightness(var2, 0, 0x10);
            var1->unknown_0_++;
        }
        else if (var1->unknown_0_ == 4)
        {
            if (!IsMainBrightnessTransitionActive(var2))
            {
                SePlayer_LoadArchive(g_sePlayer, 100);
                end->step_++;
            }
        }
        else if (var1->unknown_0_ == 5)
        {
            GameObject* var11 = func_0200ff1c(var0, var6);
            if (func_ov013_021847c4(arg0->unknown_5574_, var0->GetTickCount()) == 6)
            {
                if (var3->GetNumQueuedTasks() > 0)
                    return arg0->unknown_eac_;
                var1->unknown_0_++;
                return arg0->unknown_eac_;
            }
            int skill = self->skillMenu_->selection_;
            if (member != NULL)
                func_ov013_0218782c(self->abilities_, (signed char)member->obj3D_.actorIndex_, (unsigned char)skill);
        }
        else if (var1->unknown_0_ == 6)
        {
            SetMainBrightness(var2, -0x10, 0);
            var1->unknown_0_++;
        }
        else if (var1->unknown_0_ == 7)
        {
            if (!IsMainBrightnessTransitionActive(var2))
                var1->unknown_0_++;
        }
        else if (var1->unknown_0_ == 8)
        {
            func_ov013_02186fa0(arg0->unknown_5578_);
            arg0->unknown_5578_ = NULL;
            var1->unknown_0_++;
        }
        else if (var1->unknown_0_ == 9)
        {
            SetMainBrightness(var2, 0, 0x10);
            var1->unknown_0_++;
        }
        else if (var1->unknown_0_ == 10)
        {
            if (!IsMainBrightnessTransitionActive(var2))
            {
                SePlayer_LoadArchive(g_sePlayer, 0x65);
                GetCombatantWithFlag0x100_0200ff1c(gameState, id);
                GameObject* member = GetCombatantWithFlag0x100_0200ff1c(gameState, id);
                if (member != NULL)
                {
                    func_ov013_02184c8c(self->skillMenu_, member);
                    end->newSkillCount_ = func_0209a678(end->skillTable_, member, end->newSkills_);
                    PartyMember_RecalculateStats(GetFieldAt0x150_02053c6c((unsigned char*)member), 0);
                }
                func_ov017_021cc730(var6, 0, 0, 1);
                func_ov017_021ccc34(var6);
                func_ov017_021c9e00(var6, 0, 0, 0);
                if (var1->unknown_e2_ != 0)
                {
                    arg0->unknown_5574_ = NULL;
                    func_ov023_021eefac((Struct_ov023_021eeaac_2*)var1);
                    var1->unknown_e3_ = 0;
                    func_ov017_021cd0d8(var6, var1->unknown_74_, var1->unknown_e2_);
                    return 9;
                }
                var1->unknown_0_++;
            }
        }
        else if (var1->unknown_0_ == 11)
        {
            FontBankLoader* music = FontBankLoader_GetInstance();
            BlankFunction02094b40(music);
            BlankFunction02094b34(music, 0x65, 500, 0, 0);
            end->step_++;
        }
        else if (var1->unknown_0_ == 12)
        {
            if (AlwaysTrue02094b4c(FontBankLoader_GetInstance()))
            {
                arg0->unknown_5574_ = NULL;
                func_ov023_021eefac((Struct_ov023_021eeaac_2*)var1);
                return 7;
            }
        }
    }
    return arg0->unknown_eac_;
}
