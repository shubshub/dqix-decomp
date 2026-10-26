#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Main/BattleList.h"
#include "GameState/GameState.h"

struct Panel_021784d4 {
    char unknown_0_[0xa0];
    short width;
    short height;
    short tileX;
    short tileY;
    short unknown_a8_;
    short unknown_aa_;
    short unknown_ac_;
    short unknown_ae_;
    char unknown_b0_;
    unsigned char unknown_b1_;
};

struct Struct_ov000_021784d4_2 {
    char unknown_0_[0x79];
    unsigned char memberCount;
    char unknown_7a_[0x10e];
    struct Panel_021784d4 panel;
};

struct Struct_ov000_021784d4_3 {
    char pad[0x44];
    int x;
    int y;
};

struct TextWorkspace {
#if defined(jpn)
    char unknown0[0x28];
#else
    char unknown0[0x5c];
#endif
    char* textBuffer;
};

extern "C" TextWorkspace* MessageSystem_GetInstance();

extern "C" void func_ov000_0217c638(struct Struct_ov000_021784d4_2* obj, int a, int b);
extern "C" void func_ov000_02178648(struct Struct_ov000_021784d4_2* obj, void* textBuffer);
#if defined(jpn)
extern "C" void Window_OpenPane(struct Panel_021784d4* panel, void* textBuffer, int a, int b, int c, int d, int e);
#else
extern "C" void Window_OpenPane(struct Panel_021784d4* panel, void* textBuffer, int a, int b, int c, int d, int e, int f);
#endif

// USA: func_ov000_021784d4
extern "C" ARM void func_ov000_021784d4(struct Struct_ov000_021784d4_2* obj, struct Struct_ov000_021784d4_3* in, int arg2, int arg3) {
    if (in == 0) {
        return;
    }
    int x = in->x;
    int y = in->y;
    GameState_GetParty(GameState::GetInstance());
    unsigned char memberCount = obj->memberCount;
    func_ov000_0217c638(obj, arg2, arg3);
    struct Panel_021784d4* panel = &obj->panel;
#if defined(jpn)
    panel->width = 0xa;
#else
    panel->width = 0x10;
#endif
    panel->height = 1;
    panel->tileX = (x >> 3) + 9;
    panel->tileY = (y >> 3) + 1;
    panel->unknown_a8_ = 0xc;
    panel->unknown_aa_ = 0xa;
    panel->unknown_ac_ = 0xa;
    panel->unknown_ae_ = 0xd;
    if (memberCount == 2) {
        panel->unknown_a8_ = 0xc;
        panel->unknown_aa_ = 0xa;
    }
    if (memberCount == 3) {
        panel->unknown_a8_ = 0xc;
        panel->unknown_aa_ = 8;
    }
    if (memberCount == 4) {
        panel->unknown_a8_ = 0xc;
        panel->unknown_aa_ = 4;
        panel->unknown_ac_ = 0xa;
        panel->unknown_ae_ = 0xb;
    }
    panel->unknown_b1_ = 8;
    char* textBuffer = MessageSystem_GetInstance()->textBuffer;
#if defined(jpn)
    memset(textBuffer, 0, 0x800);
#else
    memset(textBuffer, 0, 0x960);
#endif
    func_ov000_02178648(obj, textBuffer);
#if defined(jpn)
    Window_OpenPane(&obj->panel, textBuffer, 0, 1, 0, 1, 0);
#else
    Window_OpenPane(panel, textBuffer, 0, 1, 0, 1, 0, 0);
#endif
}
