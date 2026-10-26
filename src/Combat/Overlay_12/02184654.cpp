#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct Struct_ov012_02184654 {
    unsigned int year : 12;
    unsigned int month : 4;
    unsigned int day : 5;
    unsigned int unknown_2_5_ : 4;
    unsigned int female : 1;
    unsigned int initialized : 1;
    unsigned int unknown_3_3_ : 1;
    unsigned int unknown_3_4_ : 1;
    unsigned int unknown_3_5_ : 1;
    unsigned int unknown_3_6_ : 1;
    unsigned int unknown_3_7_ : 1;
    unsigned int age : 9;
    int title : 10;
    int accolade : 11;
    int unknown_7_6_ : 1;
    unsigned int unknown_7_7_ : 1;
    signed char profileText[116];
};
struct Struct_ov012_02184654_8 {
    unsigned char female : 1;
    unsigned char skinColor : 3;
    unsigned char eyeColor : 4;
};
struct Struct_ov012_02184654_9 {
    short models[10];
    Struct_ov012_02184654_8 flags;
};
struct TableA68;
struct Container020e0310;
extern "C" void* LinkSession_GetInstance();
extern "C" unsigned char* func_02053c6c(unsigned char*);
extern "C" int func_02098f20(int, int, int);
extern "C" void* func_02072a68(TableA68*, int);
extern "C" int KeyTable_Get(Container020e0310*, int);
extern "C" void func_ov023_021e66ac(void*);

static inline Struct_ov012_02184654* inline_ov012_02184654(GameState* state) {
    return (Struct_ov012_02184654*)((char*)state + 0x543c);
}

// USA: func_ov012_02184654
extern "C" ARM void func_ov012_02184654(char* editor) {
    GameState* gameState = GameState::GetInstance();
    Struct_ov012_02184654* profile = inline_ov012_02184654(gameState);
    signed char padding[3];
    memcpy(padding, func_02072a68((TableA68*)(editor + 0x1314), 113), 3);
    LinkSession_GetInstance();
    unsigned char* characterData = 0;
    GameObject* protagonist = gameState->GetProtagonist();
    if (protagonist)
        characterData = func_02053c6c((unsigned char*)protagonist);
    if (!characterData) return;
    *(void**)(editor + 0x1408) = characterData + 0x3c;

    if (!profile->initialized) {
        profile->year = 2000;
        profile->month = 1;
        profile->day = 1;
        profile->unknown_3_7_ = 1;
        Struct_ov012_02184654_9* appearance = (Struct_ov012_02184654_9*)(characterData + 0x488);
        profile->female = appearance->flags.female;
        profile->unknown_2_5_ = appearance->flags.female;
        profile->title = 300;
        char* var6 = *(char**)((char*)protagonist + 0x144);
        profile->accolade = *(int*)(var6 + 0x8b8) + 700;
        int i;
        signed char* text = profile->profileText;
        for (i = 0; i < 57; i++, text += 2) {
            memcpy(text, padding, 2);
        }
        profile->initialized = 1;
    }
    profile->age = func_02098f20(profile->year, profile->month, profile->day);
    signed char* text = profile->profileText;
    while (*(unsigned char*)(editor + 0x1375) < 114) {
        if (text[0] == padding[0] && text[1] == padding[1]) break;
        *(unsigned char*)(editor + 0x1375) += 2;
        text += 2;
    }
    const char* label = (const char*)func_02072a68((TableA68*)(editor + 0x1314), (short)(profile->title + 10000));
    memcpy(editor + 0x1498, label, strlen(label));
    if (profile->accolade < 700)
        label = (const char*)KeyTable_Get((Container020e0310*)(editor + 0x131c), (short)profile->accolade);
    else
        label = (const char*)func_02072a68((TableA68*)(editor + 0x1314), (short)(profile->accolade + 20000));
    memcpy(editor + 0x1458, label, strlen(label));
    func_ov023_021e66ac(editor);
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
};

struct Struct_01ff8b48_4
{
    char unk_0[0x5400];
    Struct_ov012_02184654_2 unknown_5400_;
};

struct Struct_01ff8b48_5
{
    char unk_0[0x29c];
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
    Struct_ov012_02184654_3 slots_[2];
};

struct Struct_ov012_02184654_5
{
    char unk_0[0x49c];
    unsigned char female_ : 1;
    char unknown_49d_[0x950 - 0x49d];
    int vocation_;
};

struct Struct_ov012_02184654_6
{
    char unk_0[0x150];
    Struct_ov012_02184654_5* unknown_150_;
};

struct TableA68;
struct Container020e0310;

struct Struct_ov012_02184654_7
{
    char unk_0[0x133c];
    char strings_[8];
    char texts_[0x13b0 - 0x1344];
    void* unknown_13b0_;
    char unknown_13b4_[0x1400 - 0x13b4];
    char unknown_1400_[0x40];
    char unknown_1440_[0x40];
};

extern "C" void* LinkSession_GetInstance();
extern "C" unsigned char* func_02053c6c(unsigned char* obj);
extern "C" int func_02098f20(int year, int month, int day);
extern "C" void* func_02072a68(struct TableA68* table, int key);
extern "C" int KeyTable_Get(struct Container020e0310* texts, int key);
extern "C" void func_ov023_021e66ac(Struct_ov012_02184654_7* self);

static inline Struct_ov012_02184654_2* inline_ov012_02184654(GameState* gameState)
{
    return &((Struct_01ff8b48_5*)gameState)->unknown_29c_.unknown_5400_;
}

static inline Struct_ov012_02184654_3* inline_ov012_02184654_2(Struct_ov012_02184654_4* field, int i)
{
    return (Struct_ov012_02184654_3*)(void*)field->slots_ + i;
}

// USA: func_ov012_02184654
extern "C" ARM void func_ov012_02184654(Struct_ov012_02184654_7* self)
{
    GameState* gameState = GameState::GetInstance();
    Struct_ov012_02184654_2* profile = inline_ov012_02184654(gameState);
    LinkSession_GetInstance();
    Struct_ov012_02184654_4* field = 0;
    Struct_ov012_02184654_6* protagonist = (Struct_ov012_02184654_6*)gameState->GetProtagonist();
    if (protagonist != 0)
        field = (Struct_ov012_02184654_4*)func_02053c6c((unsigned char*)protagonist);
    if (field == 0)
        return;

    self->unknown_13b0_ = (char*)field + 0x3c;

    void* name2;
    if (!profile->unknown_3_2_)
    {
        profile->unknown_0_0_ = 2000;
        profile->unknown_1_4_ = 1;
        profile->unknown_2_0_ = 1;
        profile->unknown_3_7_ = 1;
        Struct_ov012_02184654_3* flags = inline_ov012_02184654_2(field, 1);
        int accolade = 0x50dc;
        profile->female_ = flags->female_;
        profile->unknown_2_5_ = flags->female_;
        profile->unknown_5_1_ = 300;
        Struct_ov012_02184654_5* party = protagonist->unknown_150_;
        if (party->female_ == 1)
            accolade += 0x32;
        profile->accolade_ = accolade + party->vocation_ - 0x4e20;
        memset((char*)profile + 8, 0, 0x74);
        profile->unknown_3_2_ = 1;
    }

    profile->unknown_4_0_ = func_02098f20(profile->unknown_0_0_, profile->unknown_1_4_, profile->unknown_2_0_);

    name2 = func_02072a68((struct TableA68*)self->strings_, (short)(profile->unknown_5_1_ + 10000));
    memcpy(self->unknown_1440_, name2, strlen((char*)name2));

    if (profile->accolade_ < 700)
        name2 = (void*)KeyTable_Get((struct Container020e0310*)self->texts_, (short)profile->accolade_);
    else
        name2 = func_02072a68((struct TableA68*)self->strings_, (short)(profile->accolade_ + 20000));
    memcpy(self->unknown_1400_, name2, strlen((char*)name2));

    func_ov023_021e66ac(self);
}
#endif
