#if defined(jpn)
enum { Enum_ov017_021bba08_156 = 0x98 };
#else
enum { Enum_ov017_021bba08_156 = 0x9c };
#endif

#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

extern "C" int GameState_GetStoryChapter(char* obj);
extern "C" int GameState_GetStoryPart(char* obj);
extern "C" void func_ov017_021baedc(void* self, int flag);

extern char data_ov017_021d7d7e[0xc];

struct Struct_ov017_021bba08 {
    char pad0[0xc];
    unsigned char f0xc;
    unsigned char f0xd;
    unsigned char f0xe;
    unsigned char f0xf;
    unsigned char unknown_10_;
    unsigned char unknown_11_;
    unsigned char unknown_12_;
    char pad1[0x16 - 0x13];
    short unknown_16_;
    char pad2[0x1a - 0x18];
    short unknown_1a_;
    char pad3[0x1e - 0x1c];
    char unknown_1e_[7];
    char pad4[0x3e - 0x25];
    char unknown_3e_[0xc];
    short unknown_4a_;
    short unknown_4c_;
    short unknown_4e_;
    short unknown_50_;
    short unknown_52_;
    char unknown_54_[0xc];
    short unknown_60_;
    char pad6[Enum_ov017_021bba08_156 - 0x62];
    unsigned char unknown_9c_;
};

// USA: func_ov017_021bba08
extern "C" ARM void func_ov017_021bba08(struct Struct_ov017_021bba08* obj, unsigned char* arg1) {
    func_ov017_021baedc(obj, 1);
    obj->unknown_9c_ = 1;

    GameState* bs = GameState::GetInstance();
    char* b = (char*)bs;
    obj->f0xc = (unsigned char)GameState_GetStoryChapter(b);
    obj->f0xe = (unsigned char)GameState_GetStoryChapter(b);
    obj->f0xd = (unsigned char)GameState_GetStoryPart(b);
    obj->f0xf = (unsigned char)GameState_GetStoryPart(b);

    obj->unknown_16_ = 3;
    obj->unknown_10_ = 1;
    obj->unknown_11_ = 0;

    obj->unknown_1a_ = *(unsigned short*)arg1;
    memcpy(obj->unknown_1e_, arg1 + 5, 7);

    memcpy(obj->unknown_3e_, data_ov017_021d7d7e, 0xc);

    obj->unknown_4a_ = 100;
    obj->unknown_4c_ = 200;
    obj->unknown_4e_ = 300;
    short v = 0x40;
    obj->unknown_50_ = v;
    obj->unknown_52_ = v - 0x41;

    obj->unknown_12_ = 0;
    memset(obj->unknown_54_, 0, 0xc);

    obj->unknown_60_ = 0;
}
