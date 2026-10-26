#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

extern "C" int GameState_GetStoryChapter(char* game);
extern "C" void* LinkSession_GetInstance(void);

struct TableA68 { struct Struct_02072a68* entries; short count; };
extern "C" void* func_02072a68(TableA68* table, int key);

struct Struct_ov023_021e66ac_3 {
    unsigned int unknown0 : 29;
    unsigned int unknown_3_5_ : 1;
    unsigned int unknown_3_6_ : 1;
    unsigned int unknown_3_7_ : 1;
    unsigned int unknown4 : 9;
    signed int title : 10;
    unsigned int unknown_6_3_ : 13;
};

struct Struct_ov023_021e66ac_4 {
#if defined(jpn)
    unsigned char unknown0[0x543c];
#else
    unsigned char unknown0[0x569c];
#endif
    Struct_ov023_021e66ac_3 profile;
};

struct Struct_ov023_021e66ac_5 {
#if defined(jpn)
    unsigned char unknown0[0x1314];
    TableA68 strings;
    unsigned char unknown_131c_[0x1458 - 0x131c];
#else
    unsigned char unknown0[0x133c];
    TableA68 strings;
    unsigned char unknown_1344_[0x1400 - 0x1344];
#endif
    char accoladeText[0x40];
    char titleText[0x40];
};

struct Struct_ov023_021e66ac {
    unsigned char unknown0[0x49c];
    unsigned char female : 1;
#if defined(jpn)
    unsigned char unknown_49d_[0x8b8 - 0x49d];
#else
    unsigned char unknown1_49d_[0x950 - 0x49d];
#endif
    int vocation;
};

struct Struct_ov023_021e66ac_2 {
#if defined(jpn)
    unsigned char unknown0[0x144];
#else
    unsigned char unknown0[0x150];
#endif
    Struct_ov023_021e66ac* unknown_150_;
};

// USA: func_ov023_021e66ac
extern "C" ARM void func_ov023_021e66ac(void* editor) {
    Struct_ov023_021e66ac_5* self = (Struct_ov023_021e66ac_5*)editor;
    GameState* game = GameState::GetInstance();
    Struct_ov023_021e66ac_3* profile = &((Struct_ov023_021e66ac_4*)game)->profile;

    if (!profile->unknown_3_5_) {
        memset(self->accoladeText, 0, sizeof(self->accoladeText));
        void* entry = func_02072a68(&self->strings, 0x6d);
        memcpy(self->accoladeText, entry, 7);
    } else if (profile->unknown_3_6_) {
        LinkSession_GetInstance();
        Struct_ov023_021e66ac_2* protagonist = (Struct_ov023_021e66ac_2*)game->GetProtagonist();
        int vocation = protagonist->unknown_150_->vocation;
        if (GameState_GetStoryChapter((char*)game) == 1) {
            vocation = 13;
        }
        int base = 0x50dc;
#if !defined(jpn)
        if (protagonist->unknown_150_->female == 1) {
            base += 0x32;
        }
#endif
        short key = (short)(base + vocation);
        char* entry = (char*)func_02072a68(&self->strings, key);
        memset(self->accoladeText, 0, sizeof(self->accoladeText));
        unsigned int length = strlen(entry);
        memcpy(self->accoladeText, entry, length);
    }

    if (profile->title != 300) {
        return;
    }

    memset(self->titleText, 0, sizeof(self->titleText));
    char* entry = (char*)func_02072a68(&self->strings, 0x6d);
    unsigned int length = strlen(entry);
    memcpy(self->titleText, entry, length);
}
