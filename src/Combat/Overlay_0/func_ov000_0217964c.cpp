#include "Combat/TryApplyElemFields.h"
#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

#if defined(jpn)
enum { textOffset=0x28, textSize=0x800, width=12, height=7, xOffset=0x17, lineHeight=8 };
#else
enum { textOffset=0x5c, textSize=0x960, width=16, height=8, xOffset=0x10, lineHeight=5 };
#endif
extern "C" void func_020dcfc8(int id, char* buf);
struct GlobalText {
    char pad0[textOffset];
    char* textBuf;
};

struct Struct_ov000_02171ffc_5 {
    char pad0[0x18];
    short messageId;
};

struct Struct_ov000_0217964c_2 {
    char pad0[0x22];
    signed char unknown_22_;
    char unknown_23_[0x44 - 0x23];
    int x;
    int y;
    int combatantId;
};

struct Struct_0205d81c;
struct StructA0205d5d0;

struct MessageWindow {
    char pad0[0xa0];
    short width;
    short height;
    short posX;
    short unknown_a6_;
    short unknown_a8_;
    short unknown_aa_;
    short unknown_ac_;
    short unknown_ae_;
    char unknown_b0_;
    unsigned char kind;
};

struct BattleMenu {
    char pad0[0x188];
    struct MessageWindow window;
};

extern "C" GlobalText* MessageSystem_GetInstance();
extern "C" void* func_02053c6c(unsigned char* obj);
extern "C" Struct_ov000_02171ffc_5* func_ov000_02171b9c(void* obj, int idx);
extern "C" void MessageSystem_FormatText(GlobalText* g, int a, char* src, char* dst, int b, int c, int d);
extern "C" void* func_0205d81c(struct Struct_0205d81c* s, int key);
#if defined(jpn)
extern "C" void Window_OpenPane(void*, void*, int, int, int, int, int);
#define APPLY_TEXT(s,k,t) Window_SetPaneText(s,k,(int)t,1)
#define DRAW_TEXT(s,t) Window_OpenPane(s,t,0,0,0,1,0)
#else
extern "C" void Window_OpenPane(void* a, void* b, int c, int d, int e, int f, int g, int h);
#define APPLY_TEXT(s,k,t) Window_SetPaneText(s,k,(int)t,1,0)
#define DRAW_TEXT(s,t) Window_OpenPane(s,t,0,0,0,1,0,0)
#endif

// USA: func_ov000_0217964c
extern "C" ARM void func_ov000_0217964c(BattleMenu* menu, Struct_ov000_0217964c_2* actor) {
    char* msg;
    MessageWindow* window;
#if !defined(jpn)
    char buf[0x800];
#endif
    if (actor == NULL) {
        return;
    }
    char* text = MessageSystem_GetInstance()->textBuf;
    memset(text, 0, textSize);
    GameObject* combatant = func_0200ff1c(GameState::GetInstance(), actor->combatantId);
    if (combatant == NULL) {
        return;
    }
    func_02053c6c((unsigned char*)combatant);
    Struct_ov000_02171ffc_5* action = func_ov000_02171b9c(actor, actor->unknown_22_);
    if (action == NULL) {
        return;
    }
    if (action->messageId <= 0) {
        return;
    }
    func_020dcfc8(action->messageId, text);
#if !defined(jpn)
    MessageSystem_FormatText(MessageSystem_GetInstance(), 0xa, text, buf, 0x72, 0, 0);
#endif
    window = &menu->window;
#if defined(jpn)
    msg = text;
#else
    msg = buf;
#endif
    if (func_0205d81c((struct Struct_0205d81c*)window, 0x24) != NULL) {
        APPLY_TEXT((struct StructA0205d5d0*)window, 0x24, msg);
    } else {
        int x = actor->x;
        int y = actor->y;
        window->width = width;
        window->height = height;
        window->posX = (x >> 3) + xOffset;
        window->unknown_a6_ = y >> 3;
        window->unknown_a8_ = 7;
        window->unknown_aa_ = lineHeight;
        window->unknown_ac_ = 0xa;
        window->unknown_ae_ = 0xe;
        window->kind = 0x24;
        DRAW_TEXT(window, msg);
    }
}
