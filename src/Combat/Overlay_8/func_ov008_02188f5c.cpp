#include <globaldefs.h>
#include <std_library_functions.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"

#define REG_DISPCNT (*(volatile unsigned int*)0x04000000)

struct InitTarget0205cfd4;
struct BackgroundGraphics;
struct List020727d8;
struct Struct020dfc40;

struct Struct_ov005_0215840c_2
{
    char unknown_0_[0x3c];
    char unknown_3c_[0xc];
};

struct Struct_ov008_02188f5c
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
    char unknown_8_[0x74];
};

struct Struct_ov008_02188f5c_4
{
    unsigned char unknown_0_[6];
    char unknown_6_[0xb];
    unsigned char unknown_11_;
    unsigned short unknown_12_0_ : 14;
    unsigned short unknown_13_6_ : 1;
    unsigned short unknown_13_7_ : 1;
    char unknown_14_[0x18];
};

struct Struct_ov008_02188f5c_2
{
    char unknown_0_[0x6c];
    Struct_ov008_02188f5c unknown_6c_;
};

extern "C" void __clear(void* arg0, unsigned long arg1);
extern "C" void* func_0202ae18();
extern "C" void func_02074af4(void* state);
extern "C" void WindowPane_Init(void* canvas);
extern "C" void Font_EncodeText(const char* name, char* codes, int);
extern "C" void func_ov008_021843f8(void* records);
extern "C" void func_ov017_021d1014(signed char member, int, int);
extern "C" void func_ov017_021d1118(signed char member, int, int, int);
void Window_Init(InitTarget0205cfd4* window);
void Background_Init(BackgroundGraphics* background);
void ResetListHeader020727d8(List020727d8* texts);
void KeyTable_Reset(Struct020dfc40* texts);
void ResetSubStruct02189228(void* entry);
PartyMemberData* GetFieldAt0x150_02053c6c(unsigned char* member);
int CheckField0NonZero_0202b7d8(int*);

struct Struct_ov008_02188f5c_3
{
    char unknown_0_[0x10];
    unsigned char unknown_10_;
    unsigned char unknown_11_;
    unsigned int unknown_14_;
    char unknown_18_[0xbc];
    char unknown_d4_[2][0x20];
    char unknown_114_[0xe0];
    void* unknown_1f4_;
    void* unknown_1f8_;
    void* unknown_1fc_;
    SafeAllocator unknown_200_;
    SafeAllocator unknown_214_;
    SafeAllocator unknown_228_;
    SafeAllocator unknown_23c_;
    SafeAllocator unknown_250_;
    SafeAllocator unknown_264_;
    char unknown_278_[8];
    char unknown_280_[8];
    char unknown_288_[0x18];
    char* unknown_2a0_;
    void* unknown_2a4_;
#if defined(jpn)
    char unknown_2a8_[0xb44];
#else
    char unknown_2a8_[0xb48];
#endif
    Struct_ov008_02188f5c_4 unknown_df0_;
    Struct_ov008_02188f5c unknown_e1c_;
    unsigned char unknown_e98_;
    signed char unknown_e99_;
    signed char unknown_e9a_;
    signed char unknown_e9b_;
    signed char unknown_e9c_;
#if defined(jpn)
    int unknown1_e9c_[5];
#else
    int unknown_ea0_;
    int unknown_ea4_;
    int unknown_ea8_;
    int unknown_eac_;
    int unknown_eb0_;
    int unknown_eb4_;
#endif
    unsigned char unknown_eb8_;
    signed char unknown_eb9_;
    unsigned char unknown_eba_;
    unsigned char unknown_ebb_;
    Struct_ov008_02188f5c_2* unknown_ebc_;
    unsigned char unknown_ec0_0_ : 1;
    unsigned char unknown_ec0_1_ : 1;
    unsigned char unknown_ec0_2_ : 1;
    unsigned char unknown_ec0_3_ : 1;
    unsigned char unknown_ec0_4_ : 4;
    void* unknown_ec4_;
    unsigned int unknown_ec8_;
};

// USA: func_ov008_02188f5c
extern "C" ARM void func_ov008_02188f5c(Struct_ov008_02188f5c_3* arg0, signed char arg1, Struct_ov008_02188f5c_2* arg2)
{
    GameState* var0 = GameState::GetInstance();
    func_0202ae18();
    arg0->unknown_10_ = 0;
    arg0->unknown_11_ = 0;
    func_02074af4(arg0);
    arg0->unknown_14_ = (REG_DISPCNT & 0x1f00) >> 8;
    REG_DISPCNT = (REG_DISPCNT & ~0x1f00) | 0x100;
    Window_Init((InitTarget0205cfd4*)&self->window_);
    Background_Init((BackgroundGraphics*)&self->backgrounds_[0]);
    Background_Init((BackgroundGraphics*)&self->backgrounds_[1]);
    WindowPane_Init(&self->canvas_);
    ResetListHeader020727d8((List020727d8*)&self->texts_);
    ResetListHeader020727d8((List020727d8*)&self->profileTexts_);
    KeyTable_Reset((Struct020dfc40*)&self->titles_);
    self->renderer_ = NULL;
    self->sprites_ = NULL;
    self->animations_ = NULL;
    self->allocator_.ResetAllocatorPointer();
    self->textAllocator_.ResetAllocatorPointer();
    self->recordsAllocator_.ResetAllocatorPointer();
    self->spriteAllocator_.ResetAllocatorPointer();
    self->profileAllocator_.ResetAllocatorPointer();
    self->titleAllocator_.ResetAllocatorPointer();
    self->text_ = NULL;
    self->pixels_ = NULL;
    func_ov008_021843f8(&self->records_);
    ResetSubStruct02189228(&self->entry_);
    self->profile_.year_ = 2000;
    self->profile_.month_ = 1;
    self->profile_.day_ = 1;
    self->profile_.birthdayChosen_ = 0;
    self->profile_.unk_0_21 = 0;
    self->profile_.designChosen_ = 0;
    self->profile_.female_ = 0;
    self->profile_.initialized_ = 0;
    self->profile_.accoladeChosen_ = 0;
    self->profile_.vocationAccolade_ = 1;
    self->profile_.showBirthday_ = 0;
    self->profile_.unk_4_0 = 0x1ff;
    self->profile_.edited_ = 0;
    self->profile_.title_ = 300;
    self->profile_.accolade_ = 706;
    self->profile_.unk_8[0] = 0;
    self->unk_e98 = 0;
    self->state_ = 0;
    self->step_ = 0;
    self->recordsState_ = 0;
    self->recordsStep_ = 0;
#if defined(jpn)
    arg0->unknown1_e9c_[0] = -1;
    arg0->unknown1_e9c_[1] = -1;
    arg0->unknown1_e9c_[2] = -1;
    arg0->unknown1_e9c_[3] = -1;
    arg0->unknown1_e9c_[4] = -1;
#else
    arg0->unknown_ea0_ = -1;
    arg0->unknown_ea4_ = -1;
    arg0->unknown_ea8_ = -1;
    arg0->unknown_eac_ = -1;
    arg0->unknown_eb0_ = -1;
    arg0->unknown_eb4_ = -1;
#endif
    arg0->unknown_ec4_ = NULL;
    arg0->unknown_ec8_ = 0;
    arg0->unknown_eb8_ = 0;
    arg0->unknown_eba_ = 0;
    arg0->unknown_ebb_ = 0;
    arg0->unknown_ebc_ = arg2;
    arg0->unknown_ec0_0_ = 1;
    arg0->unknown_ec0_1_ = 0;
    arg0->unknown_ec0_2_ = 0;
    arg0->unknown_ec0_3_ = 0;
    arg0->unknown_eb9_ = arg1;
    if (arg0->unknown_ebc_ == NULL)
    {
        GameObject* var1 = var0->GetPartyMemberByIndex(arg1);
        if (var1 != NULL)
        {
            Struct_ov005_0215840c_2* var2 = func_02053c6c((unsigned char*)var1);
            if (var2 != NULL)
            {
                func_ov008_02189228(&arg0->unknown_df0_);
#if defined(jpn)
                memcpy(arg0->unknown_df0_.unknown_6_, var2->unknown_3c_, sizeof(arg0->unknown_df0_.unknown_6_));
#else
                char name[0xc];
                __clear(name, sizeof(name));
                Font_EncodeText(data->name_, name, 1);
                memcpy(self->entry_.name_, name, sizeof(self->entry_.name_));
#endif
                arg0->unknown_df0_.unknown_13_6_ = 1;
                if (func_0202b7d8((int*)func_0202ae18()))
                {
                    func_ov017_021d1014(arg1, 0, 0);
                    func_ov017_021d1118(arg1, 1, 1, 0);
                }
            }
        }
    }
    else
    {
        arg0->unknown_e98_ = 0xff;
        memcpy(&arg0->unknown_e1c_, &arg0->unknown_ebc_->unknown_6c_, sizeof(Struct_ov008_02188f5c));
    }
}
