#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct Struct_0207d538 { int unknown_0_[3]; };
struct Struct_0207d538_2 { char* unknown_0_; char* unknown_4_; int unknown_8_; };
struct Struct_020465c0 {
    Struct_0207d538* unknown_0_;
    char unknown_4_[0x18 - 4];
    Struct_0207d538_2* unknown_18_;
};
extern "C" int func_0207d300(void*, int, int, int);
extern "C" void func_0207d2c4(void*, int);
extern "C" void func_02046380(StoreStruct*);
extern "C" void MessageSystem_FormatText(StoreStruct*, int, const char*, char*, int, int, int);
StoreStruct* MessageSystem_GetInstance();
unsigned char GameState_GetLeaderIndex(GameState*);
void NameText_InitFromPartyMember(void*, int);
void* NameText_Clear(void*);
void DispatchIfCountPositive020dcf7c(int, void*);
char* StandardStrings_Get(int);
void StoreInArray0x8b0_020465c0(StoreStruct*, int, int);

#if defined(jpn)
extern "C" void func_020de968(int, char*);
extern char data_020f1050;
extern char data_020f106e;
extern char data_020f1094;
#endif

// USA: func_0207d538
#if defined(jpn)
extern "C" ARM int func_0207d538(void* arg0, int arg1, int arg2, char* arg3, unsigned char arg4) {
#else
extern "C" ARM int func_0207d538(void* arg0, int arg1, int arg2, char* arg3) {
#endif
    if (arg1 == 2) {
#if defined(jpn)
        int var0 = (short)arg2;
#else
        short var0 = arg2;
#endif
        int var1 = func_0207d300(arg0, var0, 1, 0);
        switch (var1) {
        case -1:
            return 0;
        case 0:
        case 1:
        case 2:
        case 3:
        case 5:
        {
#if defined(jpn)
            if (arg4) {
                char var2[0x30] = {};
                func_020de968(var0, var2);
                sprintf(arg3, &data_020f1050, var2);
            } else {
                sprintf(arg3, &data_020f1050, *(char**)((char*)arg0 + 0x30));
            }
#else
            StoreStruct* formatter = MessageSystem_GetInstance();
            func_02046380(formatter);
            CombatantText combatant;
            NameText_InitFromPartyMember(&combatant, GameState_GetLeaderIndex(GameState::GetInstance()));
            formatter->combatant = &combatant;
            char first[0x80] = {};
            char second[0x80] = {};
            NumberText number;
            NameText_Clear(&number);
            number.first = first;
            number.second = second;
            DispatchIfCountPositive020dcf7c(amount, &number);
            formatter->number = &number;
            char* message = StandardStrings_Get(0x54);
            MessageSystem_FormatText(formatter, 12, message, output, 0xe3, 0, 1);
#endif
            break;
        }
        }
        if (var1 == -2) return 0;
        return 1;
    } else if (arg1 == 1) {
        func_0207d2c4(arg0, arg2);
#if defined(jpn)
        sprintf(arg3, &data_020f106e, arg2);
#else
        StoreStruct* formatter = MessageSystem_GetInstance();
        func_02046380(formatter);
        StoreInArray0x8b0_020465c0(formatter, 0, value);
        char* message = StandardStrings_Get(0x3f4);
        MessageSystem_FormatText(formatter, 12, message, output, 0xe3, 0, 1);
#endif
        return 1;
    } else {
#if defined(jpn)
        sprintf(arg3, &data_020f1094);
#else
        sprintf(output, StandardStrings_Get(0x2d));
#endif
        return 0;
    }
}
