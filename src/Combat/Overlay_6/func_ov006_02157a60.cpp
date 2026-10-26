#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "Graphics/Background.h"



struct BackgroundGraphics;
struct Struct_ov006_021536e0;
struct Struct_02081ee4;
struct Struct_02081ee4_2;
struct Struct_02071be8;
struct Struct020dfc40;
struct Struct_ov006_02157a60_2;

extern "C" void* Scenario_GetInstance();
extern "C" int Scenario_TestFlag(int, unsigned char*, int);
extern "C" void Scenario_SetFlag(void*, unsigned char*, int, int);
extern "C" void Background_Init(BackgroundGraphics*);
extern "C" void func_ov006_021536e0(Struct_ov006_021536e0*);
extern "C" void func_02081ee4(Struct_02081ee4*, Struct_02081ee4_2*);
extern "C" void SpriteContext_Init(char*);
extern "C" void func_ov023_021e20c0(void*);
extern "C" void func_02071be8(Struct_02071be8*);
extern "C" void KeyTable_Reset(Struct020dfc40*);
extern "C" void func_ov006_02157c78(Struct_ov006_02157a60_2*);

struct PartyMemberData {
    char unk_0[0x49c];
    unsigned char female_ : 1;
};

class GameObject {
public:
    char unk_0[R(0x144, 0x150)];
    PartyMemberData* unknown_150_;
};

class GameState {
public:
    static GameState* GetInstance();
    GameObject* GetProtagonist();
};


struct Struct_ov006_02156f04 {
    int unk_0[0x74 / 4];
};

struct Struct_ov006_02157a60 {
#if !defined(jpn)
    int unknown_0_;
    char** texts_;
#endif
    void* canvasBuffer_;
    void* allocators_;
    void* pot_;
    void* menu_;
    void* choice_;
    void* backgrounds_;
    void* canvases_;
    void* sprites_;
    void* animations_;
    void* unknown_2c_;
    void* unknown_30_;
    void* unknown_34_;
    void* unknown_38_;
    char unknown_3c_[8];
    short* cursor_;
    short** items_;
    unsigned char** unknown_4c_;
    unsigned short* sizes_;
    BackgroundGraphics subBackground_;
    int ingredients_[0x28 / 4];
    int unknown_9c_[0xc / 4];
    unsigned short unknown_a8_;
    unsigned char unknown_aa_;
    int renderer_[0x54 / 4];
    int layout_[R(0x48, 0x4c) / 4];
    int table_[0xc / 4];
    int menuTexts_[0x18 / 4];
    char itemNames_[R(0x18, 0xc)];
    Struct_ov006_02156f04 results_[4];
    int ticks_;
    int menuResult_;
    int task_;
    int unknown_358_;
    short unknown_35c_;
    short unknown_35e_;
    short unknown_360_;
    short unknown_362_;
    short unknown_364_;
    short unknown_366_;
    short unknown_368_;
    short unknown_36a_;
    short unknown_36c_;
    short unknown_36e_;
    short item_;
    unsigned short unknown_372_[3];
    short unknown_378_[3];
    short message_;
    unsigned short unknown_380_;
    short unknown_382_;
    signed char unknown_384_;
    signed char unknown_385_;
    unsigned char unknown_386_;
    unsigned char unknown_387_;
    unsigned char page_;
    unsigned char pages_;
    unsigned char category_;
    unsigned char count_;
    unsigned char unknown_38c_[3];
    unsigned char state_;
    unsigned char step_;
    unsigned char unknown_391_;
    unsigned char unknown_392_;
    unsigned char unknown_393_;
    unsigned short flags_;
    unsigned char female_;
    unsigned char background_;
    unsigned char unknown_398_[3];
    int unknown_39c_;
    int unknown_3a0_;
    int unknown_3a4_;
    unsigned int unknown_3a8_;
    int unknown_3ac_;
    int unknown_3b0_;
    int unknown_3b4_;
    int unknown_3b8_[0x70 / 4];
    int unknown_428_;
    signed char unknown_42c_;
    unsigned char unknown_42d_;
    unsigned char unknown_42e_;
    unsigned char unknown_42f_;
    unsigned char unknown_430_;
    unsigned char unknown_431_;
    unsigned char unknown_432_;
    unsigned char unknown_433_;
    unsigned char unknown_434_;
};

// USA: func_ov006_02157a60
extern "C" ARM void func_ov006_02157a60(Struct_ov006_02157a60* self)
{
    char* flags = (char*)Scenario_GetInstance();
    if (!Scenario_TestFlag((int)flags, (unsigned char*)(flags + 0x8c), 0x777))
        Scenario_SetFlag(flags, (unsigned char*)(flags + 0x8c), 0x777, 1);
#if !defined(jpn)
    self->unknown_0_ = 0;
#endif
    self->unknown_3b4_ = 0;
    self->unknown_428_ = -1;
    self->unknown_42d_ = 0;
    self->unknown_42e_ = 0;
    self->canvasBuffer_ = 0;
    self->allocators_ = 0;
    self->pot_ = 0;
    self->menu_ = 0;
    self->choice_ = 0;
    self->backgrounds_ = 0;
    self->canvases_ = 0;
    self->sprites_ = 0;
    self->animations_ = 0;
    self->unknown_2c_ = 0;
    self->unknown_30_ = 0;
    self->unknown_34_ = 0;
    self->unknown_38_ = 0;
    self->cursor_ = 0;
    self->items_ = 0;
    self->unknown_4c_ = 0;
    self->sizes_ = 0;
    Background_Init((BackgroundGraphics*)&self->subBackground_);
    func_ov006_021536e0((Struct_ov006_021536e0*)self->ingredients_);
    func_02081ee4((Struct_02081ee4*)self->unknown_9c_, (Struct_02081ee4_2*)&self->unknown_a8_);
    SpriteContext_Init((char*)self->renderer_);
    func_ov023_021e20c0(self->layout_);
    func_02071be8((Struct_02071be8*)self->table_);
    KeyTable_Reset((Struct020dfc40*)self->menuTexts_);
    for (unsigned char i = 0; i < 4; i++)
        func_ov006_02157c78((Struct_ov006_02157a60_2*)&self->results_[i]);
    self->menuResult_ = 0;
    self->task_ = -1;
    self->unknown_358_ = -1;
    self->unknown_35c_ = 0;
    self->unknown_35e_ = -1;
    self->unknown_360_ = -1;
    self->unknown_362_ = -1;
    self->unknown_364_ = -1;
    self->unknown_366_ = -1;
    self->unknown_368_ = -1;
    self->unknown_36a_ = -1;
    self->unknown_36c_ = -1;
    self->unknown_36e_ = -1;
    self->item_ = -1;
    self->unknown_372_[2] = 0;
    self->unknown_372_[1] = 0;
    self->unknown_372_[0] = 0;
    self->unknown_378_[2] = -1;
    self->unknown_378_[1] = self->unknown_378_[2];
    self->unknown_378_[0] = self->unknown_378_[1];
    self->message_ = -1;
    self->unknown_380_ = 0;
    self->unknown_382_ = 0;
    self->unknown_384_ = -1;
    self->unknown_385_ = -1;
    self->unknown_386_ = 0;
    self->unknown_387_ = 0;
    self->page_ = 0;
    self->pages_ = 0;
    self->category_ = 0;
    self->count_ = 0;
    self->unknown_38c_[2] = 0;
    self->unknown_38c_[1] = 0;
    self->unknown_38c_[0] = 0;
    self->state_ = 0;
    self->step_ = 0;
    self->unknown_391_ = 0;
    self->unknown_392_ = 0;
    self->unknown_393_ = 0;
    self->flags_ = 0;
    self->female_ = 0;
    self->background_ = 0;
    self->female_ = GameState::GetInstance()->GetProtagonist()->unknown_150_->female_;
    self->unknown_39c_ = 0;
    self->unknown_3a4_ = 1;
    self->unknown_3a8_ = 0;
    self->unknown_3ac_ = 0;
    self->unknown_3b0_ = -1;
    self->unknown_42f_ = 0;
    self->unknown_430_ = self->unknown_431_ = 0;
    self->unknown_432_ = 0;
    self->unknown_433_ = 0;
    self->unknown_434_ = 0;
    self->unknown_42c_ = 0;
}
