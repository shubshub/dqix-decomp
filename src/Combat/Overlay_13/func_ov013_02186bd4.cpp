#include "Combat/TryApplyElemFields.h"
#include <globaldefs.h>

#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif

#include "std_library_functions.h"

struct StructA0205d5d0;
extern "C" void func_ov013_02185424(void*, void*);

struct Struct_ov013_021846a0_2 {
#if defined(jpn)
    char unknown0[0x34];
    unsigned char window[0xbc];
    char unknown_f0_[0x5ac - 0xf0];
#else
    char unknown0[0x38];
    unsigned char window[0xbc];
    char unknown_f4_[0x620 - 0xf4];
#endif
    char texts[0x18];
    unsigned char unknown_638_[4];
    unsigned char state;
    unsigned char unknown_63d_;
    unsigned char step;
    bool stateChanged;
    bool subScreen;
    unsigned int ticks;
    int windowInput;
#if !defined(jpn)
    int unknown_64c_;
#endif
    int task;
    void* unknown_654_;
    char* text;
    int selectedSkill;
    int confirmationChoice;
    unsigned char unknown_664_;
    unsigned char unknown_665_;
    char unknown_666_[2];
    int unknown_668_;
    int unknown_66c_;
    int unknown_670_;
    int skillPoints[5];
    int unknown_688_[5];
    unsigned char unknown_69c_[5];
    char unknown_6a1_[8];
    unsigned char unknown_6a9_[5];
    char unknown_6ae_[0xe];
    unsigned char flags;
};

// USA: func_ov013_02186bd4
extern "C" ARM void func_ov013_02186bd4(Struct_ov013_021846a0_2* menu) {
    memset(menu->text, 0, LOW_REGION(0x800, 0x960));
    func_ov013_02185424(menu, menu->text);
#if defined(jpn)
    Window_SetPaneText((StructA0205d5d0*)menu->window, 0, (int)menu->text, 1);
#else
    Window_SetPaneText((StructA0205d5d0*)menu->window, 0, (int)menu->text, 1, 0);
#endif
}
