#if defined(jpn)
enum { Enum_ov017_021bbae4_204 = 0xc8 };
#else
enum { Enum_ov017_021bbae4_204 = 0xcc };
#endif

#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

extern "C" int GameState_GetStoryChapter(char* obj);
extern "C" int GameState_GetStoryPart(char* obj);
extern "C" void func_ov017_021baedc(void* self, int flag);

extern char data_ov017_021d7d8a[0xc];
extern char data_ov017_021d7d96[7];

struct Struct_ov017_021bbae4 {
    unsigned char pad0[2];
    unsigned char unknown_2_;
    char pad1[0xc - 3];
    unsigned char f0xc;
    unsigned char f0xd;
    unsigned char f0xe;
    unsigned char f0xf;
    unsigned char unknown_10_;
    unsigned char unknown_11_;
    unsigned char unknown_12_;
    unsigned char unknown_13_;
    char pad2[0x16 - 0x14];
    short unknown_16_;
    char pad3[0x1a - 0x18];
    short unknown_1a_;
    char pad4[0x1e - 0x1c];
    char unknown_1e_[7];
    char pad5[0x3e - 0x25];
    char unknown_3e_[0xc];
    short unknown_4a_;
    short unknown_4c_;
    short unknown_4e_;
    short unknown_50_;
    short unknown_52_;
    char unknown_54_[0xc];
    short unknown_60_;
    char unknown_62_[7];
    char unknown_69_[Enum_ov017_021bbae4_204 - 0x69];
    unsigned char unknown_cc_;
};

// USA: func_ov017_021bbae4
extern "C" ARM void func_ov017_021bbae4(struct Struct_ov017_021bbae4* self, unsigned char* arg1, unsigned char arg2) {
    if (self->unknown_2_ != 0) {
        return;
    }
    func_ov017_021baedc(self, 1);
    self->unknown_cc_ = arg2;

    GameState* bs = GameState::GetInstance();
    char* b = (char*)bs;
    self->f0xc = (unsigned char)GameState_GetStoryChapter(b);
    self->f0xe = (unsigned char)GameState_GetStoryChapter(b);
    self->f0xd = (unsigned char)GameState_GetStoryPart(b);
    self->f0xf = (unsigned char)GameState_GetStoryPart(b);

    self->unknown_16_ = 1;
    self->unknown_10_ = 1;
    self->unknown_11_ = 0;

    self->unknown_1a_ = *(unsigned short*)arg1;
    memcpy(self->unknown_1e_, arg1 + 5, 7);

    memcpy(self->unknown_3e_, data_ov017_021d7d8a, 0xc);

    self->unknown_4a_ = 100;
    self->unknown_4c_ = 200;
    self->unknown_4e_ = 300;
    short v = 0x10;
    self->unknown_50_ = v;
    self->unknown_52_ = v - 0x11;

    self->unknown_12_ = 0;
    memset(self->unknown_54_, 0, 0xc);

    self->unknown_60_ = 0;
    self->unknown_13_ = 1;
    memcpy(self->unknown_62_, data_ov017_021d7d96, 7);
}
