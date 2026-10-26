#include "Combat/TryApplyElemFields.h"
#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_0215c0ec_2400=0x800 };
extern "C" void func_02042428(char*, int);
extern "C" void func_02042158(char*, int);
extern char data_ov003_0217e68e[];
extern char data_ov003_0217e696[];
#else
enum { Enum_ov003_0215c0ec_2400=0x960 };
#endif
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Input/Input.h"

struct Struct_ov003_0215c0ec {
    int count;
    char pad4[0x30 - 0x4];
    int selected;
};

struct BattleData0215c0ec {
    char pad0[0xf6c];
    int field_0xf6c;
};

struct Struct_ov003_0215c0ec_3 {
    char pad0[0x7c];
    char* text;
    char unknown_80_[0xf4 - 0x80];
    char menu[0x1a4 - 0xf4];
    unsigned char mode;
    char unknown_1a5_[0x582 - 0x1a5];
    unsigned char state;
    unsigned char unknown_583_;
};

struct StructA0205d5d0;
struct StoreStruct;

extern "C" void func_ov003_0215b6f0(struct Struct_ov003_0215c0ec_3* self, char* dst, int flag);
extern "C" void func_ov003_0215b964(struct Struct_ov003_0215c0ec_3* self, char* dst, int flag);
extern "C" void func_ov003_0215be70(struct Struct_ov003_0215c0ec_3* self, char* dst, int flag);
extern "C" int MessageSystem_GetInstance();
extern "C" void func_02046380(void* obj);
extern "C" int StandardStrings_Get(int value);
extern "C" int Text_Append(char* dst, const char* src);
extern "C" void func_020465c0(struct StoreStruct* base, int index, int value);
extern "C" void func_020465f0(unsigned char* base, int index, unsigned char value);
extern "C" void func_020465d8(unsigned char* base, int index, unsigned char value);

// USA: func_ov003_0215c0ec
extern "C" ARM void func_ov003_0215c0ec(struct Struct_ov003_0215c0ec_3* self) {
    if (self->state != 0) {
        int flag = 0;
        if (self->state == 2 && g_touchInput.isRepeatValid_ != 0 && g_touchInput.currentReading_.isHeld != 0) {
            struct Struct_ov003_0215c0ec* list = (struct Struct_ov003_0215c0ec*)((char*)self->menu + 4);
            if (!flag && list->selected < 0) {
                return;
            }
            flag = 1;
        }
        memset(self->text, 0, Enum_ov003_0215c0ec_2400);
        unsigned char mode = self->mode;
        switch (mode) {
        case 1:
            func_ov003_0215b6f0(self, self->text, flag);
            break;
        case 2:
            func_ov003_0215b964(self, self->text, flag);
            break;
        case 3:
            func_ov003_0215be70(self, self->text, flag);
            break;
        }
#if defined(jpn)
        Window_SetPaneText((struct StructA0205d5d0*)self->menu, mode, (int)self->text, 1);
#else
        Window_SetPaneText((struct StructA0205d5d0*)self->menu, mode, (int)self->text, 1, 0);
#endif
    }
    if (self->unknown_583_ != 0) {
        GameState* game = GameState::GetInstance();
        int messages = MessageSystem_GetInstance();
        memset(self->text, 0, Enum_ov003_0215c0ec_2400);
#if defined(jpn)
        func_02042428(self->text, 8);
        Text_Append(self->text, data_ov003_0217e68e);
        func_02042158(self->text, 2);
        Text_Append(self->text, data_ov003_0217e696);
#else
        Text_Append(self->text, (const char*)StandardStrings_Get(0x3f1));
#endif
        func_02046380((void*)messages);
        func_020465c0((struct StoreStruct*)messages, 0,
                          ((struct BattleData0215c0ec*)GameState_GetParty(game))->field_0xf6c);
        func_020465f0((unsigned char*)messages, 0, 7);
        func_020465d8((unsigned char*)messages, 0, 1);
#if defined(jpn)
        Window_SetPaneText((struct StructA0205d5d0*)self->menu, 0, (int)self->text, 1);
#else
        Window_SetPaneText((struct StructA0205d5d0*)self->menu, 0, (int)self->text, 1, 0);
#endif
        self->unknown_583_ = 0;
    }
}
