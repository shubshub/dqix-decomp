#include <globaldefs.h>
#include <std_library_functions.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"

#define REG_DISPCNT (*(volatile unsigned int*)0x04000000)

struct InitTarget0205cfd4;
struct BackgroundGraphics;
struct Struct_020727d8;
struct Struct020dfc40;

struct PartyMemberData
{
    char unk_0[0x3c];
    char name_[0xc];
};

struct Struct_ov008_02188f5c
{
    unsigned int unknown_0_0_ : 12;
    unsigned int unknown_1_4_ : 4;
    unsigned int unknown_2_0_ : 5;
    unsigned int unknown_2_5_ : 4;
    unsigned int female_ : 1;
    unsigned int unknown_3_2_ : 1;
    unsigned int unknown_3_3_ : 1;
    unsigned int unknown_3_4_ : 1;
    unsigned int unknown_3_5_ : 1;
    unsigned int unknown_3_6_ : 1;
    unsigned int unknown_3_7_ : 1;
    unsigned int unknown_4_0_ : 9;
    int unknown_5_1_ : 10;
    int accolade_ : 11;
    int unknown_7_6_ : 1;
    unsigned int unknown_7_7_ : 1;
    char unk_8[0x74];
};

struct Struct_ov008_02188f5c_4
{
    unsigned char id_[6];
    char name_[0xb];
    unsigned char unknown_11_;
    unsigned short unknown_12_0_ : 14;
    unsigned short unknown_13_6_ : 1;
    unsigned short unknown_13_7_ : 1;
    char unknown_14_[0x18];
};

struct Struct_ov008_02188f5c_2
{
    char unk_0[0x6c];
    Struct_ov008_02188f5c unknown_6c_;
};

extern "C" void __clear(void* buffer, unsigned long size);
extern "C" void* LinkSession_GetInstance();
extern "C" void func_02074af4(void* state);
extern "C" void WindowPane_Init(void* canvas);
extern "C" void Font_EncodeText(const char* name, char* codes, int);
extern "C" void func_ov008_021843f8(void* records);
extern "C" void func_ov017_021d1014(signed char member, int, int);
extern "C" void func_ov017_021d1118(signed char member, int, int, int);
extern "C" void Window_Init(InitTarget0205cfd4* window);
extern "C" void Background_Init(BackgroundGraphics* background);
extern "C" void func_020727d8(Struct_020727d8* texts);
extern "C" void KeyTable_Reset(Struct020dfc40* texts);
extern "C" void func_ov008_02189228(void* entry);
extern "C" PartyMemberData* func_02053c6c(unsigned char* member);
extern "C" int LinkSession_IsActive(int*);

struct Struct_ov008_02188f5c_3
{
    char unk_0[0x10];
    unsigned char unk_10;
    unsigned char unknown_11_;
    unsigned int layers_;
    char window_[0xbc];
    char backgrounds_[2][0x20];
    char canvas_[0xe0];
    void* renderer_;
    void* sprites_;
    void* animations_;
    SafeAllocator allocator_;
    SafeAllocator textAllocator_;
    SafeAllocator unknown_228_;
    SafeAllocator spriteAllocator_;
    SafeAllocator unknown_250_;
    SafeAllocator titleAllocator_;
    char texts_[8];
    char unknown_280_[8];
    char titles_[0x18];
    char* text_;
    void* pixels_;
#if defined(jpn)
    char unknown_2a8_[0xb44];
#else
    char unknown_2a8_[0xb48];
#endif
    Struct_ov008_02188f5c_4 entry_;
    Struct_ov008_02188f5c unknown_e1c_;
    unsigned char unknown_e98_;
    signed char state_;
    signed char step_;
    signed char unknown_e9b_;
    signed char unknown_e9c_;
#if defined(jpn)
    int tasks_[5];
#else
    int unknown_ea0_;
    int unknown_ea4_;
    int unknown_ea8_;
    int unknown_eac_;
    int unknown_eb0_;
    int unknown_eb4_;
#endif
    unsigned char unknown_eb8_;
    signed char member_;
    unsigned char unknown_eba_;
    unsigned char unknown_ebb_;
    Struct_ov008_02188f5c_2* unknown_ebc_;
    unsigned char active_ : 1;
    unsigned char unknown_ec0_1_ : 1;
    unsigned char unknown_ec0_2_ : 1;
    unsigned char unknown_ec0_3_ : 1;
    unsigned char unknown_ec0_4_ : 4;
    void* unknown_ec4_;
    unsigned int unknown_ec8_;
};

// USA: func_ov008_02188f5c
extern "C" ARM void func_ov008_02188f5c(Struct_ov008_02188f5c_3* self, signed char member, Struct_ov008_02188f5c_2* arg2)
{
    GameState* gameState = GameState::GetInstance();
    LinkSession_GetInstance();
    self->unk_10 = 0;
    self->unknown_11_ = 0;
    func_02074af4(self);
    self->layers_ = (REG_DISPCNT & 0x1f00) >> 8;
    REG_DISPCNT = (REG_DISPCNT & ~0x1f00) | 0x100;
    Window_Init((InitTarget0205cfd4*)&self->window_);
    Background_Init((BackgroundGraphics*)&self->backgrounds_[0]);
    Background_Init((BackgroundGraphics*)&self->backgrounds_[1]);
    WindowPane_Init(&self->canvas_);
    func_020727d8((Struct_020727d8*)&self->texts_);
    func_020727d8((Struct_020727d8*)&self->unknown_280_);
    KeyTable_Reset((Struct020dfc40*)&self->titles_);
    self->renderer_ = NULL;
    self->sprites_ = NULL;
    self->animations_ = NULL;
    self->allocator_.ResetAllocatorPointer();
    self->textAllocator_.ResetAllocatorPointer();
    self->unknown_228_.ResetAllocatorPointer();
    self->spriteAllocator_.ResetAllocatorPointer();
    self->unknown_250_.ResetAllocatorPointer();
    self->titleAllocator_.ResetAllocatorPointer();
    self->text_ = NULL;
    self->pixels_ = NULL;
    func_ov008_021843f8(&self->unknown_2a8_);
    func_ov008_02189228(&self->entry_);
    self->unknown_e1c_.unknown_0_0_ = 2000;
    self->unknown_e1c_.unknown_1_4_ = 1;
    self->unknown_e1c_.unknown_2_0_ = 1;
    self->unknown_e1c_.unknown_3_4_ = 0;
    self->unknown_e1c_.unknown_2_5_ = 0;
    self->unknown_e1c_.unknown_3_3_ = 0;
    self->unknown_e1c_.female_ = 0;
    self->unknown_e1c_.unknown_3_2_ = 0;
    self->unknown_e1c_.unknown_3_5_ = 0;
    self->unknown_e1c_.unknown_3_6_ = 1;
    self->unknown_e1c_.unknown_3_7_ = 0;
    self->unknown_e1c_.unknown_4_0_ = 0x1ff;
    self->unknown_e1c_.unknown_7_6_ = 0;
    self->unknown_e1c_.unknown_5_1_ = 300;
    self->unknown_e1c_.accolade_ = 706;
    self->unknown_e1c_.unk_8[0] = 0;
    self->unknown_e98_ = 0;
    self->state_ = 0;
    self->step_ = 0;
    self->unknown_e9b_ = 0;
    self->unknown_e9c_ = 0;
#if defined(jpn)
    self->tasks_[0] = -1;
    self->tasks_[1] = -1;
    self->tasks_[2] = -1;
    self->tasks_[3] = -1;
    self->tasks_[4] = -1;
#else
    self->unknown_ea0_ = -1;
    self->unknown_ea4_ = -1;
    self->unknown_ea8_ = -1;
    self->unknown_eac_ = -1;
    self->unknown_eb0_ = -1;
    self->unknown_eb4_ = -1;
#endif
    self->unknown_ec4_ = NULL;
    self->unknown_ec8_ = 0;
    self->unknown_eb8_ = 0;
    self->unknown_eba_ = 0;
    self->unknown_ebb_ = 0;
    self->unknown_ebc_ = arg2;
    self->active_ = 1;
    self->unknown_ec0_1_ = 0;
    self->unknown_ec0_2_ = 0;
    self->unknown_ec0_3_ = 0;
    self->member_ = member;
    if (self->unknown_ebc_ == NULL)
    {
        GameObject* object = gameState->GetPartyMemberByIndex(member);
        if (object != NULL)
        {
            PartyMemberData* data = func_02053c6c((unsigned char*)object);
            if (data != NULL)
            {
                func_ov008_02189228(&self->entry_);
#if defined(jpn)
                memcpy(self->entry_.name_, data->name_, sizeof(self->entry_.name_));
#else
                char name[0xc];
                __clear(name, sizeof(name));
                Font_EncodeText(data->name_, name, 1);
                memcpy(self->entry_.name_, name, sizeof(self->entry_.name_));
#endif
                self->entry_.unknown_13_6_ = 1;
                if (LinkSession_IsActive((int*)LinkSession_GetInstance()))
                {
                    func_ov017_021d1014(member, 0, 0);
                    func_ov017_021d1118(member, 1, 1, 0);
                }
            }
        }
    }
    else
    {
        self->unknown_e98_ = 0xff;
        memcpy(&self->unknown_e1c_, &self->unknown_ebc_->unknown_6c_, sizeof(Struct_ov008_02188f5c));
    }
}
