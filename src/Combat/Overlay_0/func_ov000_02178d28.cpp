#include "Combat/TryApplyElemFields.h"
#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov000_0215767c {
    char pad0[4];
    unsigned int kind : 12;
    unsigned int pad4 : 20;
    unsigned int unknown_8_0_ : 8;
};

struct Struct_ov000_02178d28 {
    char pad0[0xe];
    short power;
    char pad10[0x20 - 0x10];
    signed char cursor;
    char pad21[0x44 - 0x21];
    int x;
    int y;
    int combatantId;
};

struct Window {
    char pad0[0xa0];
    short left;
    short top;
    short x;
    short y;
    short width;
    short height;
    short unknown_ac_;
    short unknown_ae_;
    char unknown_b0_;
    unsigned char id;
};

struct Struct_ov000_02178d28_2 {
    char pad0[0x188];
    Window window;
};

struct GlobalData {
#if defined(jpn)
    char pad0[0x28];
#else
    char pad0[0x5c];
#endif
    char* workBuffer;
};

struct StoreStruct;

extern "C" GlobalData* MessageSystem_GetInstance(void);
extern "C" void* memset(void* dst, int c, unsigned int n);
extern "C" Struct_ov000_0215767c* func_ov000_02171674(void*, int);
extern "C" GameObject* func_0200ff1c(GameState* gs, int id);
extern "C" void func_020dd040(int id, char* buf);
extern "C" void MessageSystem_FormatText(GlobalData* messages, int a, const char* input, char* output, int b, int c, int d);
extern "C" void func_02046380(GlobalData* messages);
extern "C" int func_ov000_02153a8c(GameObject* obj);
extern "C" int func_020dd290(void*, unsigned int);
extern "C" void func_020465c0(StoreStruct*, int, int);
extern "C" const char* StandardStrings_Get(int key);
extern "C" int Text_Append(char* dst, const char* src);
struct Struct_0205d81c;
extern "C" void* func_0205d81c(Struct_0205d81c*, int);
#if defined(jpn)
extern "C" void Window_OpenPane(Window* window, char* text, int a, int b, int c, int d, int e);
extern "C" void func_020465f0(unsigned char*, int, unsigned char);
extern "C" void func_020465d8(unsigned char*, int, unsigned char);
extern char data_ov000_02185169[];
#else
extern "C" void Window_OpenPane(Window* window, char* text, int a, int b, int c, int d, int e, int f);
#endif

// USA: func_ov000_02178d28
extern "C" ARM void func_ov000_02178d28(Struct_ov000_02178d28_2* menu, Struct_ov000_02178d28* entry) {
    char* text;
    GameObject* combatant;
    Struct_ov000_0215767c* skill;
    GameObject* target;
    GlobalData* messages;
    if (entry == NULL) {
        return;
    }
    int cursor = entry->cursor;
    char* buf = MessageSystem_GetInstance()->workBuffer;
#if defined(jpn)
    memset(buf, 0, 0x800);
#else
    memset(buf, 0, 0x960);
#endif
    GameState* gs = GameState::GetInstance();
    skill = func_ov000_02171674(entry, cursor);
    if (skill == NULL) {
        return;
    }
    combatant = gs->GetCombatantByIndex(entry->combatantId);
    if (combatant == NULL) {
        return;
    }
    target = func_0200ff1c(gs, entry->combatantId);
    if (target == NULL) {
        return;
    }
#if !defined(jpn)
    char textBuf[0x800];
#endif
    func_020dd040(skill->kind, buf);
#if defined(jpn)
    text = buf;
#else
    MessageSystem_FormatText(MessageSystem_GetInstance(), 10, buf, textBuf, 0x72, 0, 0);
    text = textBuf;
#endif
    messages = MessageSystem_GetInstance();
    func_02046380(messages);
    int value;
    if (func_ov000_02153a8c(combatant)) {
        value = 0;
    } else if (skill->kind == 0x28 && entry->power < 0x14) {
        value = 0x14;
    } else if (skill->unknown_8_0_ >= 0xff) {
        value = entry->power;
    } else {
        value = func_020dd290(target, skill->unknown_8_0_);
    }
    func_020465c0((StoreStruct*)messages, 0, value);
    func_020465c0((StoreStruct*)messages, 1, entry->power);
#if defined(jpn)
    func_020465f0((unsigned char*)messages, 0, 3);
    func_020465f0((unsigned char*)messages, 1, 3);
    func_020465d8((unsigned char*)messages, 0, 1);
    func_020465d8((unsigned char*)messages, 1, 1);
    Text_Append(text, data_ov000_02185169);
#else
    Text_Append(text, StandardStrings_Get(0x3ec));
#endif
    Window* window = &menu->window;
    if (func_0205d81c((Struct_0205d81c*)window, 0x22) != NULL) {
#if defined(jpn)
        Window_SetPaneText((StructA0205d5d0*)window, 0x22, (int)text, 1);
#else
        Window_SetPaneText((StructA0205d5d0*)window, 0x22, (int)text, 1, 0);
#endif
        return;
    }
    int x = entry->x;
    int y = entry->y;
#if defined(jpn)
    window->left = 0xc;
#else
    window->left = 0x10;
#endif
#if defined(jpn)
    window->top = 6;
#else
    window->top = 10;
#endif
#if defined(jpn)
    window->x = (x >> 3) + 0x16;
#else
    window->x = (x >> 3) + 0x10;
#endif
    window->y = y >> 3;
    window->width = 7;
#if defined(jpn)
    window->height = 8;
#else
    window->height = 6;
#endif
    window->unknown_ac_ = 10;
    window->unknown_ae_ = 0xe;
    window->id = 0x22;
#if defined(jpn)
    Window_OpenPane(window, text, 0, 0, 0, 1, 0);
#else
    Window_OpenPane(window, text, 0, 0, 0, 1, 0, 0);
#endif
}
