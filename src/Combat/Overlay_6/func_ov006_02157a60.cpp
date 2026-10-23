#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

#if defined(jpn)
#define func_0205ec34 func_0205ff20
#endif

#if defined(jpn)
#define func_0206df6c func_0206f0c0
#endif

struct Struct_02020cb8;
struct Struct_ov006_021536e0;
struct Struct_02081ee4;
struct Struct_02081ee4_2;
struct Struct_02071be8;
struct Struct_0201099c_14;
struct Struct_ov006_02157a60_2;

extern "C" void* func_0205ec34();
extern "C" int func_0206dfb0(int, unsigned char*, int);
extern "C" void func_0206df6c(void*, unsigned char*, int, int);
void Background_Init(List0204af64*);
void InitStruct_021536e0(StructInit36e0*);
void InitWithSub02081ee4(Obj02081ee4*, Sub02081ee4*);
void SpriteContext_Init(char*);
void ClearFields_021e20c0(void*);
void ClearListHeader(Struct02071be8*);
void KeyTable_Reset(Struct020dfc40*);
void InitObj_02157c78(Obj02157c78*);

struct Struct_ov005_0215840c_2 {
    char unknown_0_[0x49c];
    unsigned char unknown_49c_0_ : 1;
};

class GameObject {
public:
    char unknown_0_[R(0x144, 0x150)];
    Struct_ov005_0215840c_2* unknown_150_;
};

class GameState {
public:
    static GameState* GetInstance();
    GameObject* GetProtagonist();
};

struct Struct_ov003_021594c4 {
    int unknown_0_[0x20 / 4];
};

struct Struct_ov006_02156f04 {
    int unknown_0_[0x74 / 4];
};

struct Struct_ov006_02157a60 {
#if !defined(jpn)
    int unknown_0_;
    char** unknown_4_;
#endif
    void* unknown_8_;
    void* unknown_c_;
    void* unknown_10_;
    void* unknown_14_;
    void* unknown_18_;
    void* unknown_1c_;
    void* unknown_20_;
    void* unknown_24_;
    void* unknown_28_;
    void* unknown_2c_;
    void* unknown_30_;
    void* unknown_34_;
    void* unknown_38_;
    char unknown_3c_[8];
    short* unknown_44_;
    short** unknown_48_;
    unsigned char** unknown_4c_;
    unsigned short* unknown_50_;
    Struct_ov003_021594c4 unknown_54_;
    int unknown_74_[0x28 / 4];
    int unknown_9c_[0xc / 4];
    unsigned short unknown_a8_;
    unsigned char unknown_aa_;
    int unknown_ac_[0x54 / 4];
    int unknown_100_[R(0x48, 0x4c) / 4];
    int unknown_14c_[0xc / 4];
    int unknown_158_[0x18 / 4];
    char unknown_170_[R(0x18, 0xc)];
    Struct_ov006_02156f04 unknown_17c_[4];
    int unknown_34c_;
    int unknown_350_;
    int unknown_354_;
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
    short unknown_370_;
    unsigned short unknown_372_[3];
    short unknown_378_[3];
    short unknown_37e_;
    unsigned short unknown_380_;
    short unknown_382_;
    signed char unknown_384_;
    signed char unknown_385_;
    unsigned char unknown_386_;
    unsigned char unknown_387_;
    unsigned char unknown_388_;
    unsigned char unknown_389_;
    unsigned char unknown_38a_;
    unsigned char unknown_38b_;
    unsigned char unknown_38c_[3];
    unsigned char unknown_38f_;
    unsigned char unknown_390_;
    unsigned char unknown_391_;
    unsigned char unknown_392_;
    unsigned char unknown_393_;
    unsigned short unknown_394_;
    unsigned char unknown_396_;
    unsigned char unknown_397_;
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
extern "C" ARM void func_ov006_02157a60(Struct_ov006_02157a60* arg0)
{
    char* var0 = (char*)func_0205ec34();
    if (!func_0206dfb0((int)var0, (unsigned char*)(var0 + 0x8c), 0x777))
        func_0206df6c(var0, (unsigned char*)(var0 + 0x8c), 0x777, 1);
#if !defined(jpn)
    arg0->unknown_0_ = 0;
#endif
    self->showResult_ = 0;
    self->resultTask_ = -1;
    self->fadeTimer_ = 0;
    self->nextStep_ = 0;
    self->canvasBuffer_ = 0;
    self->allocators_ = 0;
    self->pot_ = 0;
    self->menu_ = 0;
    self->choice_ = 0;
    self->backgrounds_ = 0;
    self->canvases_ = 0;
    self->sprites_ = 0;
    self->animations_ = 0;
    self->recipes_ = 0;
    self->pageStart_ = 0;
    self->recipe_ = 0;
    self->records_ = 0;
    self->cursor_ = 0;
    self->items_ = 0;
    self->counts_ = 0;
    self->sizes_ = 0;
    Background_Init((List0204af64*)&self->subBackground_);
    InitStruct_021536e0((StructInit36e0*)self->ingredients_);
    InitWithSub02081ee4((Obj02081ee4*)self->repeat_, (Sub02081ee4*)&self->buttons_);
    SpriteContext_Init((char*)self->renderer_);
    ClearFields_021e20c0(self->layout_);
    ClearListHeader((Struct02071be8*)self->table_);
    KeyTable_Reset((Struct020dfc40*)self->menuTexts_);
    for (unsigned char i = 0; i < 4; i++)
        InitObj_02157c78((Obj02157c78*)&self->results_[i]);
    self->menuResult_ = 0;
    self->task_ = -1;
    self->unk_358 = -1;
    self->unk_35c = 0;
    self->previousCursor_ = -1;
    self->mainCursor_ = -1;
    self->categoryCursor_ = -1;
    self->itemCursor_ = -1;
    self->bookCursor_ = -1;
    self->filterCursor_ = -1;
    self->recipeCursor_ = -1;
    self->choiceCursor_ = -1;
    self->group_ = -1;
    self->item_ = -1;
    self->categories_[2] = 0;
    self->categories_[1] = 0;
    self->categories_[0] = 0;
    self->chosenItems_[2] = -1;
    self->chosenItems_[1] = self->chosenItems_[2];
    self->chosenItems_[0] = self->chosenItems_[1];
    self->message_ = -1;
    self->messageLength_ = 0;
    self->successRate_ = 0;
    self->filterCategory_ = -1;
    self->filterKind_ = -1;
    self->sort_ = 0;
    self->times_ = 0;
    self->page_ = 0;
    self->pages_ = 0;
    self->category_ = 0;
    self->count_ = 0;
    self->chosenCounts_[2] = 0;
    self->chosenCounts_[1] = 0;
    self->chosenCounts_[0] = 0;
    self->state_ = 0;
    self->step_ = 0;
    self->unk_391 = 0;
    self->messageStep_ = 0;
    self->repeatDelay_ = 0;
    self->flags_ = 0;
    self->female_ = 0;
    self->background_ = 0;
    self->female_ = GameState::GetInstance()->GetProtagonist()->partyData_->female_;
    self->textSound_ = 0;
    self->textSoundOn_ = 1;
    self->textSoundTimer_ = 0;
    self->textSoundPlaying_ = 0;
    self->textSoundState_ = -1;
    self->saved_ = 0;
    self->arrowUp_ = self->arrowDown_ = 0;
    self->resetBlend_ = 0;
    self->closing_ = 0;
    self->closeRequested_ = 0;
    self->arrowTimer_ = 0;
}
