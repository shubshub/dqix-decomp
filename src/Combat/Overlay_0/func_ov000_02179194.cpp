#include "Combat/TryApplyElemFields.h"
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct Struct_ov000_02179194 {
    unsigned int unknown_0_;
    unsigned int skill : 12;
    unsigned int unknown_5_4_ : 20;
    unsigned int unknown_8_0_ : 8;
    unsigned int unknown_9_0_ : 24;
};
struct Struct_ov000_02179194_2 {
    unsigned char unknown_0_[0xe];
    short unknown_e_;
    unsigned char unknown_10_[0xe];
    short cursor;
    unsigned char unknown_20_[0x24];
    int width;
    int height;
    int combatant;
};
struct SkillTextWindow {
    unsigned char unknown_0_[0xa0];
    short x;
    short y;
    short width;
    short height;
    short left;
    short top;
    short right;
    short bottom;
    unsigned char unknown_b0_;
    unsigned char id;
};
struct Struct_ov000_02179194_4 {
    unsigned char unknown_0_[0x188];
    SkillTextWindow window;
};
struct TextResources {
#if defined(jpn)
    unsigned char unknown_0_[0x28];
#else
    unsigned char unknown1_0_[0x5c];
#endif
    char* scratch;
};
struct StoreStruct;
struct Struct_0205d81c;
struct StructA0205d5d0;
extern "C" TextResources* MessageSystem_GetInstance();
extern "C" Struct_ov000_02179194* func_ov000_0217199c(void*, int);
extern "C" void func_020dd040(int, char*);
extern "C" void MessageSystem_FormatText(TextResources*, int, char*, char*, int, int, int);
extern "C" void func_02046380(TextResources*);
extern "C" int func_ov000_02153a8c(GameObject*);
extern "C" unsigned int func_020dd290(void*, unsigned int);
extern "C" void func_020465c0(StoreStruct*, int, int);
extern "C" const char* StandardStrings_Get(int);
extern "C" int Text_Append(char*, const char*);
extern "C" void* func_0205d81c(Struct_0205d81c*, int);
#if defined(jpn)
extern "C" void Window_OpenPane(SkillTextWindow*, char*, int, int, int, int, int);
extern "C" void func_020465f0(unsigned char*, int, unsigned char);
extern "C" void func_020465d8(unsigned char*, int, unsigned char);
extern char data_ov000_02185169[];
#else
extern "C" void Window_OpenPane(SkillTextWindow*, char*, int, int, int, int, int, int);
#endif

// USA: func_ov000_02179194
extern "C" ARM void func_ov000_02179194(Struct_ov000_02179194_4* display, Struct_ov000_02179194_2* menu) {
    char* destination;
    TextResources* resources;
#if !defined(jpn)
    char text[0x800];
#endif
    if (!menu) return;
    int cursor = menu->cursor;
    char* scratch = MessageSystem_GetInstance()->scratch;
#if defined(jpn)
    memset(scratch, 0, 0x800);
#else
    memset(scratch, 0, 0x960);
#endif
    GameState* game = GameState::GetInstance();
    Struct_ov000_02179194* skill = func_ov000_0217199c(menu, cursor);
    if (!skill) return;
    GameObject* combatant = game->GetCombatantByIndex(menu->combatant);
    if (!combatant) return;
    GameObject* partyMember = func_0200ff1c(game, menu->combatant);
    if (!partyMember) return;
    func_020dd040(skill->skill, scratch);
#if defined(jpn)
    destination = scratch;
#else
    MessageSystem_FormatText(MessageSystem_GetInstance(), 10, scratch, text, 0x72, 0, 0);
    destination = text;
#endif
    resources = MessageSystem_GetInstance();
    func_02046380(resources);
    int var9;
    if (func_ov000_02153a8c(combatant)) var9 = 0;
    else {
        unsigned int value = skill->unknown_8_0_;
        if (value >= 0xff) var9 = menu->unknown_e_;
        else var9 = func_020dd290(partyMember, value);
    }
    func_020465c0((StoreStruct*)resources, 0, var9);
    func_020465c0((StoreStruct*)resources, 1, menu->unknown_e_);
#if defined(jpn)
    func_020465f0((unsigned char*)resources, 0, 3);
    func_020465f0((unsigned char*)resources, 1, 3);
    func_020465d8((unsigned char*)resources, 0, 1);
    func_020465d8((unsigned char*)resources, 1, 1);
    Text_Append(destination, data_ov000_02185169);
#else
    Text_Append(destination, StandardStrings_Get(0x3ec));
#endif
    SkillTextWindow* window = &display->window;
    if (func_0205d81c((Struct_0205d81c*)window, 0x23)) {
#if defined(jpn)
        Window_SetPaneText((StructA0205d5d0*)window, 0x23, (int)destination, 1);
#else
        Window_SetPaneText((StructA0205d5d0*)window, 0x23, (int)destination, 1, 0);
#endif
    } else {
        int width = menu->width;
        int height = menu->height;
#if defined(jpn)
        window->x = 12;
#else
        window->x = 16;
#endif
#if defined(jpn)
        window->y = 6;
#else
        window->y = 10;
#endif
#if defined(jpn)
        window->width = (width >> 3) + 22;
#else
        window->width = (width >> 3) + 16;
#endif
        window->height = height >> 3;
        window->left = 7;
#if defined(jpn)
        window->top = 8;
#else
        window->top = 6;
#endif
        window->right = 10;
        window->bottom = 14;
        window->id = 0x23;
#if defined(jpn)
        Window_OpenPane(window, destination, 1, 0, 0, 1, 0);
#else
        Window_OpenPane(window, destination, 1, 0, 0, 1, 0, 0);
#endif
    }
}
