#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Main/BattleList.h"
#include "GameState/GameState.h"

struct Struct_ov000_021784d4 {
    char unknown_0_[0xa0];
    short unknown_a0_;
    short unknown_a2_;
    short unknown_a4_;
    short unknown_a6_;
    short unknown_a8_;
    short unknown_aa_;
    short unknown_ac_;
    short unknown_ae_;
    char unknown_b0_;
    unsigned char unknown_b1_;
};

struct Struct_ov000_021784d4_2 {
    char unknown_0_[0x79];
    unsigned char unknown_79_;
    char unknown_7a_[0x10e];
    struct Struct_ov000_021784d4 unknown_188_;
};

struct Struct_ov000_021784d4_3 {
    char unknown_0_[0x44];
    int unknown_44_;
    int unknown_48_;
};

struct Struct_ov000_02178074_4 {
#if defined(jpn)
    char unknown_0_[0x28];
#else
    char unknown1_0_[0x5c];
#endif
    char* unknown_5c_;
};

TextWorkspace* MessageSystem_GetInstance();

extern "C" void func_ov000_0217c638(struct Struct_ov000_021784d4_2* arg0, int arg1, int arg2);
extern "C" void func_ov000_02178648(struct Struct_ov000_021784d4_2* arg0, void* arg1);
#if defined(jpn)
extern "C" void Window_OpenPane(struct Panel_021784d4* panel, void* textBuffer, int a, int b, int c, int d, int e);
#else
extern "C" void Window_OpenPane(struct Panel_021784d4* panel, void* textBuffer, int a, int b, int c, int d, int e, int f);
#endif

// USA: func_ov000_021784d4
extern "C" ARM void func_ov000_021784d4(struct Struct_ov000_021784d4_2* arg0, struct Struct_ov000_021784d4_3* arg1, int arg2, int arg3) {
    if (arg1 == 0) {
        return;
    }
    int x = in->x;
    int y = in->y;
    GameState_GetParty(GameState::GetInstance());
    unsigned char memberCount = obj->memberCount;
    func_ov000_0217c638(obj, arg2, arg3);
    struct Panel_021784d4* panel = &obj->panel;
#if defined(jpn)
    var3->unknown_a0_ = 0xa;
#else
    var3->unknown_a0_ = 0x10;
#endif
    var3->unknown_a2_ = 1;
    var3->unknown_a4_ = (var0 >> 3) + 9;
    var3->unknown_a6_ = (var1 >> 3) + 1;
    var3->unknown_a8_ = 0xc;
    var3->unknown_aa_ = 0xa;
    var3->unknown_ac_ = 0xa;
    var3->unknown_ae_ = 0xd;
    if (var2 == 2) {
        var3->unknown_a8_ = 0xc;
        var3->unknown_aa_ = 0xa;
    }
    if (var2 == 3) {
        var3->unknown_a8_ = 0xc;
        var3->unknown_aa_ = 8;
    }
    if (var2 == 4) {
        var3->unknown_a8_ = 0xc;
        var3->unknown_aa_ = 4;
        var3->unknown_ac_ = 0xa;
        var3->unknown_ae_ = 0xb;
    }
    panel->field_0xb1 = 8;
    char* textBuffer = MessageSystem_GetInstance()->textBuffer;
#if defined(jpn)
    memset(var4, 0, 0x800);
#else
    memset(var4, 0, 0x960);
#endif
    func_ov000_02178648(arg0, var4);
#if defined(jpn)
    Window_OpenPane(&obj->panel, textBuffer, 0, 1, 0, 1, 0);
#else
    Window_OpenPane(panel, textBuffer, 0, 1, 0, 1, 0, 0);
#endif
}
