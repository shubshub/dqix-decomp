#if defined(jpn)
enum { Enum_ov017_021bba08_156 = 0x98 };
#else
enum { Enum_ov017_021bba08_156 = 0x9c };
#endif

#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

int GameState_GetStoryChapter(char* obj);
int GameState_GetStoryPart(char* obj);
extern "C" void func_ov017_021baedc(void* self, int flag);

extern char data_ov017_021d7d7e[0xc];

struct Struct_ov017_021bba08 {
    char unknown_0_[0xc];
    unsigned char unknown_c_;
    unsigned char unknown_d_;
    unsigned char unknown_e_;
    unsigned char unknown_f_;
    unsigned char unknown_10_;
    unsigned char unknown_11_;
    unsigned char unknown_12_;
    char unknown_13_[0x16 - 0x13];
    short unknown_16_;
    char unknown_18_[0x1a - 0x18];
    short unknown_1a_;
    char unknown_1c_[0x1e - 0x1c];
    char unknown_1e_[7];
    char unknown_25_[0x3e - 0x25];
    char unknown_3e_[0xc];
    short unknown_4a_;
    short unknown_4c_;
    short unknown_4e_;
    short unknown_50_;
    short unknown_52_;
    char unknown_54_[0xc];
    short unknown_60_;
    char unknown_62_[Enum_ov017_021bba08_156 - 0x62];
    unsigned char unknown_9c_;
};

// USA: func_ov017_021bba08
extern "C" ARM void func_ov017_021bba08(struct Struct_ov017_021bba08* arg0, unsigned char* arg1) {
    func_ov017_021baedc(arg0, 1);
    arg0->unknown_9c_ = 1;

    GameState* bs = GameState::GetInstance();
    char* b = (char*)bs;
    obj->f0xc = (unsigned char)GameState_GetStoryChapter(b);
    obj->f0xe = (unsigned char)GameState_GetStoryChapter(b);
    obj->f0xd = (unsigned char)GameState_GetStoryPart(b);
    obj->f0xf = (unsigned char)GameState_GetStoryPart(b);

    arg0->unknown_16_ = 3;
    arg0->unknown_10_ = 1;
    arg0->unknown_11_ = 0;

    arg0->unknown_1a_ = *(unsigned short*)arg1;
    memcpy(arg0->unknown_1e_, arg1 + 5, 7);

    memcpy(arg0->unknown_3e_, data_ov017_021d7d7e, 0xc);

    arg0->unknown_4a_ = 100;
    arg0->unknown_4c_ = 200;
    arg0->unknown_4e_ = 300;
    short var2 = 0x40;
    arg0->unknown_50_ = var2;
    arg0->unknown_52_ = var2 - 0x41;

    arg0->unknown_12_ = 0;
    memset(arg0->unknown_54_, 0, 0xc);

    arg0->unknown_60_ = 0;
}
