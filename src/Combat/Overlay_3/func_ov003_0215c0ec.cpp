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
    int unknown_0_;
    char unknown_4_[0x30 - 0x4];
    int unknown_30_;
};

struct Struct_ov003_0215c0ec_2 {
    char unknown_0_[0xf6c];
    int unknown_f6c_;
};

struct Struct_ov003_0215c0ec_3 {
    char unknown_0_[0x7c];
    char* unknown_7c_;
    char unknown_80_[0xf4 - 0x80];
    char unknown_f4_[0x1a4 - 0xf4];
    unsigned char unknown_1a4_;
    char unknown_1a5_[0x582 - 0x1a5];
    unsigned char unknown_582_;
    unsigned char unknown_583_;
};

struct Struct_0205d5d0;
struct Struct_020465c0;

extern "C" void func_ov003_0215b6f0(struct BattleMenu0215c0ec* self, char* dst, int flag);
extern "C" void func_ov003_0215b964(struct BattleMenu0215c0ec* self, char* dst, int flag);
extern "C" void func_ov003_0215be70(struct BattleMenu0215c0ec* self, char* dst, int flag);
int MessageSystem_GetInstance();
extern "C" void func_02046380(void* obj);
int StandardStrings_Get(int value);
int Text_Append(char* dst, const char* src);
void StoreInArray0x8b0_020465c0(struct StoreStruct* base, int index, int value);
void SetByteInRange_020465f0(unsigned char* base, int index, unsigned char value);
void SetByteAtIndex_020465d8(unsigned char* base, int index, unsigned char value);

// USA: func_ov003_0215c0ec
extern "C" ARM void func_ov003_0215c0ec(struct Struct_ov003_0215c0ec_3* arg0) {
    if (arg0->unknown_582_ != 0) {
        int var0 = 0;
        if (arg0->unknown_582_ == 2 && g_touchInput.isRepeatValid_ != 0 && g_touchInput.currentReading_.isHeld != 0) {
            struct Struct_ov003_0215c0ec* var1 = (struct Struct_ov003_0215c0ec*)((char*)arg0->unknown_f4_ + 4);
            if (!var0 && var1->unknown_30_ < 0) {
                return;
            }
            var0 = 1;
        }
        memset(arg0->unknown_7c_, 0, Enum_ov003_0215c0ec_2400);
        unsigned char var2 = arg0->unknown_1a4_;
        switch (var2) {
        case 1:
            func_ov003_0215b6f0(arg0, arg0->unknown_7c_, var0);
            break;
        case 2:
            func_ov003_0215b964(arg0, arg0->unknown_7c_, var0);
            break;
        case 3:
            func_ov003_0215be70(arg0, arg0->unknown_7c_, var0);
            break;
        }
#if defined(jpn)
        Window_SetPaneText((struct StructA0205d5d0*)self->menu, mode, (int)self->text, 1);
#else
        Window_SetPaneText((struct StructA0205d5d0*)self->menu, mode, (int)self->text, 1, 0);
#endif
    }
    if (self->refresh != 0) {
        GameState* game = GameState::GetInstance();
        int messages = MessageSystem_GetInstance();
        memset(self->text, 0, kTextSize);
#if defined(jpn)
        func_02042428(self->text, 8);
        Text_Append(self->text, data_ov003_0217e68e);
        func_02042158(self->text, 2);
        Text_Append(self->text, data_ov003_0217e696);
#else
        Text_Append(self->text, (const char*)StandardStrings_Get(0x3f1));
#endif
        func_02046380((void*)messages);
        StoreInArray0x8b0_020465c0((struct StoreStruct*)messages, 0,
                          ((struct BattleData0215c0ec*)GameState_GetParty(game))->field_0xf6c);
        SetByteInRange_020465f0((unsigned char*)messages, 0, 7);
        SetByteAtIndex_020465d8((unsigned char*)messages, 0, 1);
#if defined(jpn)
        Window_SetPaneText((struct StructA0205d5d0*)self->menu, 0, (int)self->text, 1);
#else
        Window_SetPaneText((struct StructA0205d5d0*)self->menu, 0, (int)self->text, 1, 0);
#endif
        arg0->unknown_583_ = 0;
    }
}
