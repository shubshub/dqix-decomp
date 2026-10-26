#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include <Filesystem/BackgroundLoader.h>
#include <Memory/SafeAllocator.h>
#include <GameState/GameState.h>
#include "Resource/GameResources.h"



struct GameResources;
struct ArrayContainsByteStruct;
struct Entry_0205d6a0;
struct TableA68;
struct Struct_ov002_021682c0;
struct Struct_ov023_021eeaac_2;

struct MessageSystem_021f1234 {
#if defined(jpn)
    char unk_0[0x868];
#else
    char unk_0[0x998];
#endif

    int busy_;
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
    char unk_0[0x18];
    void* spriteRenderer_;
    short unknown_1c_;
#if defined(jpn)
    char unknown_1e_[0x5e4 - 0x1e];
#else
    char unknown1_1e_[0x65c - 0x1e];
#endif

    int selection_;
};

struct Struct_ov023_021f1234 {
#if defined(jpn)
    char unk_0[0x53];
#else
    char unk_0[0x67];
#endif

    unsigned char member_;
};

struct Struct_ov023_021f1234_2 {
    int step_;
    char unk_4[0x18 - 4];
    int current_;
    char unk_1c[0x74 - 0x1c];
    unsigned short unknown_74_[55];
    unsigned char unknown_e2_;
    unsigned char unknown_e3_;
    char unknown_e4_[0xe8 - 0xe4];
    char skillTable_[8];
};

struct Struct_ov023_021f1234_3 {
    char unk_0[0x30];
    SafeAllocator allocator_;
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
    char menu_[0x52e4 - 0x371c];
#else
    char menu_[0x5228 - 0x3760];
#endif

    SafeAllocator menuAllocator_;
#if defined(jpn)
    char unknown_52f8_[0x5768 - 0x52f8];
#else
    char unknown_523c_[0x5574 - 0x523c];
#endif

    Struct_ov023_021f1234_5* unknown_5574_;
    Struct_ov023_021f1234* abilities_;
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

    char texts_[4];
};

extern "C" Struct_ov023_021f1234_2* _ZZ21inline_ov023_021f4c04vE1s;
extern char g_sePlayer[];

extern "C" MessageSystem_021f1234* MessageSystem_GetInstance();
extern "C" int func_02086ef0(ArrayContainsByteStruct* array, int id);
extern "C" void func_ov023_021d8b6c(void* window);
extern "C" void Window_ClosePane(Entry_0205d6a0* window, int value);
extern "C" int Scenario_TestFlag(int a, unsigned char* b, int flag);
extern "C" void Scenario_SetFlag(void* a, unsigned char* b, int flag, int value);
extern "C" const char* func_02072a68(TableA68* texts, int id);
extern "C" void MessageSystem_Reset(char* messages);
void SetMainBrightness(GameResources* resources, int brightness, int duration);
int IsMainBrightnessTransitionActive(GameResources* resources);
extern "C" void func_020de868(void* icons);
extern "C" void func_ov013_02186e74(Struct_ov002_021682c0* arg0, SafeAllocator* allocator);
extern "C" void SePlayer_LoadArchive(void* sound, int mode);
extern "C" unsigned char* func_02053c6c(unsigned char* member);
extern "C" void func_ov023_021eefac(Struct_ov023_021eeaac_2* end);

extern "C" {
void* Scenario_GetInstance();
void func_ov023_021f1818(void* menu, int hidden);
void func_ov023_021d8af8(void* window);
void func_ov013_02184360(Struct_ov023_021f1234_5* menu, void* parent);
void func_ov013_02184cf0(Struct_ov023_021f1234_5* menu, SafeAllocator* allocator);
#if !defined(jpn)
void func_0204500c(MessageSystem_021f1234* messages, const char* text, int a, int b);
#endif
#if defined(jpn)
void func_0204500c(MessageSystem_021f1234*,const char*,int);
#endif
int func_ov023_021f4fc8();
void func_ov013_02186eec(Struct_ov023_021f1234* arg0, int a);
void func_ov013_02184b4c(Struct_ov023_021f1234_5* menu, void* member);
int func_ov013_021870f0(Struct_ov023_021f1234* arg0);
unsigned char func_ov013_021847c4(void* menu, int ticks);
void func_ov013_0218782c(Struct_ov023_021f1234* arg0, int member, int skill);
void func_ov013_02186fa0(Struct_ov023_021f1234* arg0);
void func_ov013_02184c8c(Struct_ov023_021f1234_5* menu, void* member);
unsigned char func_0209a678(char* table, void* member, unsigned short* arg2);
void PartyMember_RecalculateStats(unsigned char* data, int a);
void func_ov017_021cc730(int id, int a, int b, int c);
void func_ov017_021ccc34(int id);
void func_ov017_021c9e00(int id, int a, int b, int c);
void func_ov017_021cd0d8(int id, unsigned short* arg1, int count);
}

// USA: func_ov023_021f1234
extern "C" ARM int func_ov023_021f1234(Struct_ov023_021f1234_3* self)
{
    GameState* gameState = GameState::GetInstance();
    Struct_ov023_021f1234_2* end = _ZZ21inline_ov023_021f4c04vE1s;
    GameResources* resources = GetGameResources();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    void* unk = Scenario_GetInstance();
    MessageSystem_021f1234* messages = MessageSystem_GetInstance();
    int id = end->current_;
    int inParty = func_02086ef0((ArrayContainsByteStruct*)GameState_GetParty(gameState), id);
    if (self->unknown_5574_ == NULL)
    {
        if (self->unknown_5588_ != NULL)
        {
            func_ov023_021f1818(self->menu_, 1);
            func_ov023_021d8b6c(self->unknown_5588_);
            func_ov023_021d8af8(self->unknown_5588_);
            self->unknown_5588_ = NULL;
        }
        Window_ClosePane((Entry_0205d6a0*)&self->menu_[0x188], 1);
        self->allocator_.Reset();
#if defined(jpn)
        self->unknown_5574_ = (Struct_ov023_021f1234_5*)self->allocator_.Allocate(0x654);
#else
        self->unknown_5574_ = (Struct_ov023_021f1234_5*)self->allocator_.Allocate(0x6cc);
#endif
        func_ov013_02184360(self->unknown_5574_, self->menu_);
        func_ov013_02184cf0(self->unknown_5574_, &self->allocator_);
        Struct_ov023_021f1234_5* menu = self->unknown_5574_;
        menu->spriteRenderer_ = &self->menu_[0x11c];
        menu->unknown_1c_ = 0;
        self->unknown_5584_ = 0;
    }
    else if (self->unknown_5574_ != NULL)
    {
        if (end->step_ == 0)
        {
            if (!Scenario_TestFlag((int)unk, (unsigned char*)unk + 0x8c, 0x119c))
            {
                Scenario_SetFlag(unk, (unsigned char*)unk + 0x8c, 0x119c, 1);
                if (inParty)
                {
#if defined(jpn)
                    func_0204500c(messages, func_02072a68((TableA68*)self->texts_, 0x24), 1);
#else
                    func_0204500c(messages, func_02072a68((TableA68*)self->texts_, 0x24), 1, 0xe3);
#endif

                    messages->unknown_19b2_ = 0;
                    messages->busy_ = 1;
                }
                end->step_ = 100;
            }
            else
            {
                MessageSystem_Reset((char*)messages);
                SetMainBrightness(resources, -0x10, 0x10);
                end->step_++;
            }
        }
        else if (end->step_ == 100)
        {
            if (messages->unknown_9a0_ == 3)
                messages->unknown_19af_ = 0;
            if (func_ov023_021f4fc8())
            {
                MessageSystem_Reset((char*)messages);
                SetMainBrightness(resources, -0x10, 0x10);
                end->step_ = 1;
            }
        }
        else if (end->step_ == 1)
        {
            if (!IsMainBrightnessTransitionActive(resources))
            {
                end->step_++;
                MessageSystem_Reset((char*)messages);
                func_020de868(&self->menu_[0xd0]);
                SafeAllocator* allocator = &self->menuAllocator_;
                allocator->Reset();
#if defined(jpn)
                self->abilities_ = (Struct_ov023_021f1234*)allocator->Allocate(0x58);
#else
                self->abilities_ = (Struct_ov023_021f1234*)allocator->Allocate(0x6c);
#endif

                func_ov013_02186eec(self->abilities_, 0);
                func_ov013_02186e74((Struct_ov002_021682c0*)self->abilities_, allocator);
                GameObject* member = func_0200ff1c(gameState, id);
                if (member != NULL)
                {
                    func_ov013_02184b4c(self->unknown_5574_, member);
                    self->abilities_->member_ = member->obj3D_.actorIndex_;
                }
            }
        }
        else if (end->step_ == 2)
        {
            if (func_ov013_021870f0(self->abilities_))
                end->step_++;
        }
        else if (end->step_ == 3)
        {
            SetMainBrightness(resources, 0, 0x10);
            end->step_++;
        }
        else if (end->step_ == 4)
        {
            if (!IsMainBrightnessTransitionActive(resources))
            {
                SePlayer_LoadArchive(g_sePlayer, 100);
                end->step_++;
            }
        }
        else if (end->step_ == 5)
        {
            GameObject* member = func_0200ff1c(gameState, id);
            if (func_ov013_021847c4(self->unknown_5574_, gameState->GetTickCount()) == 6)
            {
                if (loader->GetNumQueuedTasks() > 0)
                    return self->unknown_eac_;
                end->step_++;
                return self->unknown_eac_;
            }
            int skill = self->unknown_5574_->selection_;
            if (member != NULL)
                func_ov013_0218782c(self->abilities_, (signed char)member->obj3D_.actorIndex_, (unsigned char)skill);
        }
        else if (end->step_ == 6)
        {
            SetMainBrightness(resources, -0x10, 0);
            end->step_++;
        }
        else if (end->step_ == 7)
        {
            if (!IsMainBrightnessTransitionActive(resources))
                end->step_++;
        }
        else if (end->step_ == 8)
        {
            func_ov013_02186fa0(self->abilities_);
            self->abilities_ = NULL;
            end->step_++;
        }
        else if (end->step_ == 9)
        {
            SetMainBrightness(resources, 0, 0x10);
            end->step_++;
        }
        else if (end->step_ == 10)
        {
            if (!IsMainBrightnessTransitionActive(resources))
            {
                SePlayer_LoadArchive(g_sePlayer, 0x65);
                func_0200ff1c(gameState, id);
                GameObject* member = func_0200ff1c(gameState, id);
                if (member != NULL)
                {
                    func_ov013_02184c8c(self->unknown_5574_, member);
                    end->unknown_e2_ = func_0209a678(end->skillTable_, member, end->unknown_74_);
                    PartyMember_RecalculateStats(func_02053c6c((unsigned char*)member), 0);
                }
                func_ov017_021cc730(id, 0, 0, 1);
                func_ov017_021ccc34(id);
                func_ov017_021c9e00(id, 0, 0, 0);
                if (end->unknown_e2_ != 0)
                {
                    self->unknown_5574_ = NULL;
                    func_ov023_021eefac((Struct_ov023_021eeaac_2*)end);
                    end->unknown_e3_ = 0;
                    func_ov017_021cd0d8(id, end->unknown_74_, end->unknown_e2_);
                    return 9;
                }
                end->step_++;
            }
        }
        else if (end->step_ == 11)
        {
            FontBankLoader* music = FontBankLoader_GetInstance();
            func_02094b40(music);
            func_02094b34(music, 0x65, 500, 0, 0);
            end->step_++;
        }
        else if (end->step_ == 12)
        {
            if (func_02094b4c(FontBankLoader_GetInstance()))
            {
                self->unknown_5574_ = NULL;
                func_ov023_021eefac((Struct_ov023_021eeaac_2*)end);
                return 7;
            }
        }
    }
    return self->unknown_eac_;
}
