#if defined(jpn)

#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include <globaldefs.h>

#if defined(jpn)
#define func_ov012_0218adac func_ov012_0218bba0
#endif
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct Struct_ov008_02188f5c {
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
    char unknown_4_[0x78];
};

struct Struct_ov012_0218adac_2 {
    char unknown0[LOW_REGION(0x543c, 0x569c)];
    Struct_ov008_02188f5c profile;
};

struct Struct_ov012_02185ab8 {
    char unknown0[LOW_REGION(0xd0c, 0xd28)];
#if defined(jpn)
    char controller[0x608];
    char unknown_1314_[0x1344 - 0x1314];
#else
    char controller[0x60c];
    unsigned char unknown_1334_;
    char unknown_1335_[0x1374 - 0x1335];
#endif
    char* text;
    char unknown_1378_[LOW_REGION(0x1408 - 0x1348, 0x13b0 - 0x1378)];
    const char* playerName;
    void* unknown_13b4_;
    unsigned int unknown_13b8_;
    char* unknown_13bc_;
    char unknown_13c0_[LOW_REGION(0x1458 - 0x1418, 0x1400 - 0x13c0)];
    char accoladeText[0x40];
    char titleText[0x40];
#if !defined(jpn)
    char unknown_1480_[0x14bd - 0x1480];
    unsigned char unknown_14bd_;
#endif
};

extern "C" void func_ov023_021e6594(Struct_ov012_02185ab8* obj);
extern "C" void func_ov023_021e66ac(void* obj);

class Struct_ov002_021650d4;
class Struct_ov012_0218adac;
extern "C" void func_ov023_021e7bc4(Struct_ov002_021650d4* obj, unsigned int selector, int idx);
extern "C" void func_ov023_021e7c58(Struct_ov012_0218adac* obj, unsigned int selector, int idx);

#if !defined(jpn)
extern "C" int func_ov012_0218ae74(Struct_ov012_02185ab8* self, const Struct_ov008_02188f5c* profile);
#endif

#if defined(jpn)
extern "C" void func_02042428(char*, int);
extern "C" int func_02099304(const Struct_ov008_02188f5c*, const char*, const void*, unsigned int, char*, unsigned int, unsigned char, const char*, const char*);
#endif

// USA: func_ov012_0218adac
#if defined(jpn)
extern "C" ARM void func_ov012_0218adac(Struct_ov012_02185ab8* self, int arg1, int arg2) {
#else
extern "C" ARM void func_ov012_0218adac(Struct_ov012_02185ab8* self, int arg1, int arg2, int flag) {
#endif
    GameState* battle = GameState::GetInstance();
    func_ov023_021e6594(self);

    Struct_ov008_02188f5c var1;
    const Struct_ov008_02188f5c* profile;

    if (arg2 == -1) {
        profile = &((Struct_ov012_0218adac_2*)battle)->profile;
    } else {
        memcpy(&var1, &((Struct_ov012_0218adac_2*)battle)->profile, sizeof(var1));
        var1.unknown_2_5_ = arg2;
        profile = &var1;
    }

#if defined(jpn)
    memset(self->text, 0, 0x800);
    func_02042428(self->text, 12);
    char* text = self->text;
    unsigned int length = strlen(text);
    func_02099304(profile, self->playerName, self->unknown_13b4_, self->unknown_13b8_, text + length, 0x800 - length, 0, self->titleText, self->accoladeText);
    memset(self->unknown_13bc_, 0, 0xf2);
    const char* var5 = self->text;
    memcpy(self->unknown_13bc_, var5, strlen(var5));
    {
#else
    if (flag == 0) {
        self->unknown_14bd_ = 0;
        self->unknown_1334_ = 0;
    }

    int result = func_ov012_0218ae74(self, profile);

    if (result != 0 || flag == 0) {
#endif
        if (arg1 != 0) {
            func_ov023_021e7bc4((Struct_ov002_021650d4*)self->controller, 2, 0);
        } else {
            func_ov023_021e7c58((Struct_ov012_0218adac*)self->controller, 2, 0);
        }
    }

    func_ov023_021e66ac(self);
}
