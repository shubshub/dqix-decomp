#include "Combat/TryApplyElemFields.h"
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"
#include "Input/Input.h"

#if defined(jpn)
#define MENU_SHIFT 4
#define TEXT_BYTES 0x800
extern "C" void func_02042428(char*, int);
#else
#define MENU_SHIFT 0
#define TEXT_BYTES 0x960
#endif
struct Struct_ov003_0216aa28 {
    char pad0[0x30];
    int cursor;
    char unknown_34_[0x50 - 0x34];
};

struct Struct_02000c9c_86 {
    int header;
    struct Struct_ov003_0216aa28 grids[2];
};

struct Container020e0310;
struct StructA0205d5d0;

struct Struct_ov003_0216aa28_2 {
    char pad0[0x64];
    char names[0x7c - 0x64];
    char* textBuf;
    char unknown_80_[0xe4 - MENU_SHIFT - 0x80];
    struct Struct_02000c9c_86 list;
    char unknown_188_[0x194 - 0x188];
    unsigned char layout;
    char unknown_195_[0x4ea - 0x195];
    unsigned char unknown_4ea_;
    unsigned char unknown_4eb_;
    char unknown_4ec_[0x56c - 0x4ec];
    int selection;
};

struct Ptr2a04_0216aa28 {
    char pad0[0xf6c];
    int value;
};

struct StoreStruct;

extern "C" const char* KeyTable_Get(struct Container020e0310* c, int key);
extern "C" int Text_Append(char* dst, const char* src);
#if defined(jpn)
#define APPLY_MENU(a,b,c,d,e) Window_SetPaneText(a,b,c,d)
#else
#define APPLY_MENU(a,b,c,d,e) Window_SetPaneText(a,b,c,d,e)
#endif
extern "C" void func_ov003_02169a84(struct Struct_ov003_0216aa28_2* menu, char* dst, int flag);
extern "C" void func_ov003_02169d10(struct Struct_ov003_0216aa28_2* menu, char* dst, int flag);
extern "C" struct StoreStruct* MessageSystem_GetInstance();
extern "C" void func_02046380(struct StoreStruct* g);
extern "C" void func_020465c0(struct StoreStruct* base, int index, int value);
extern "C" void func_020465f0(unsigned char* base, int index, unsigned char value);
extern "C" void func_020465d8(unsigned char* base, int index, unsigned char value);

static inline struct Struct_ov003_0216aa28* GetGrid(void* list) { SDK_NULL_ASSERT(list); return ((struct Struct_02000c9c_86*)list)->grids; }

// USA: func_ov003_0216aa28
extern "C" ARM void func_ov003_0216aa28(struct Struct_ov003_0216aa28_2* menu) {
    unsigned char mode = menu->unknown_4ea_;
    if (mode != 0) {
        int flag = 0;
        if (mode == 2) {
            if (g_touchInput.isRepeatValid_ != 0 && g_touchInput.currentReading_.isHeld != 0) {
                if (GetGrid(&menu->list)->cursor >= 0) {
                    flag = 1;
                } else if (menu->selection >= 0) {
                    flag = 1;
                } else {
                    return;
                }
            }
        } else if (mode == 4) {
            flag = 1;
        }
        memset(menu->textBuf, 0, TEXT_BYTES);
        unsigned char layout = menu->layout;
        switch (layout) {
        case 1:
            func_ov003_02169a84(menu, menu->textBuf, flag);
            break;
        case 2:
            func_ov003_02169d10(menu, menu->textBuf, flag);
            break;
        }
#if defined(jpn)
        APPLY_MENU((struct StructA0205d5d0*)&menu->list, layout, (int)menu->textBuf, 1, 0);
#else
        if (layout == 2) {
            APPLY_MENU((struct StructA0205d5d0*)&menu->list, layout, (int)menu->textBuf, 0, 1);
        } else {
            APPLY_MENU((struct StructA0205d5d0*)&menu->list, layout, (int)menu->textBuf, 1, 0);
        }
#endif
    }
    if (menu->unknown_4eb_ == 0) {
        return;
    }
    GameState* gs = GameState::GetInstance();
    struct StoreStruct* g = MessageSystem_GetInstance();
    struct Ptr2a04_0216aa28* p = (struct Ptr2a04_0216aa28*)GameState_GetParty(gs);
    memset(menu->textBuf, 0, TEXT_BYTES);
#if defined(jpn)
    func_02042428(menu->textBuf, 8);
#endif
    Text_Append(menu->textBuf, KeyTable_Get((struct Container020e0310*)menu->names, 0x65));
    func_02046380(g);
    func_020465c0(g, 0, p->value);
    func_020465f0((unsigned char*)g, 0, 7);
    func_020465d8((unsigned char*)g, 0, 1);
    APPLY_MENU((struct StructA0205d5d0*)&menu->list, 0, (int)menu->textBuf, 1, 0);
    menu->unknown_4eb_ = 0;
}
