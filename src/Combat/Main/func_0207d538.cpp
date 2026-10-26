#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct Struct_0207d538 { int data[3]; };
struct Struct_0207d538_2 { char* first; char* second; int flags; };
struct StoreStruct {
    Struct_0207d538* combatant;
    char pad4[0x18 - 4];
    Struct_0207d538_2* number;
};
extern "C" int func_0207d300(void*, int, int, int);
extern "C" void func_0207d2c4(void*, int);
extern "C" void func_02046380(StoreStruct*);
extern "C" void MessageSystem_FormatText(StoreStruct*, int, const char*, char*, int, int, int);
extern "C" StoreStruct* MessageSystem_GetInstance();
extern "C" unsigned char GameState_GetLeaderIndex(GameState*);
extern "C" void NameText_InitFromPartyMember(void*, int);
extern "C" void* NameText_Clear(void*);
extern "C" void func_020dcf7c(int, void*);
extern "C" char* StandardStrings_Get(int);
extern "C" void func_020465c0(StoreStruct*, int, int);

#if defined(jpn)
extern "C" void func_020de968(int, char*);
extern char data_020f1050;
extern char data_020f106e;
extern char data_020f1094;
#endif

// USA: func_0207d538
#if defined(jpn)
extern "C" ARM int func_0207d538(void* owner, int type, int value, char* output, unsigned char arg4) {
#else
extern "C" ARM int func_0207d538(void* owner, int type, int value, char* output) {
#endif
    if (type == 2) {
#if defined(jpn)
        int amount = (short)value;
#else
        short amount = value;
#endif
        int result = func_0207d300(owner, amount, 1, 0);
        switch (result) {
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
                func_020de968(amount, var2);
                sprintf(output, &data_020f1050, var2);
            } else {
                sprintf(output, &data_020f1050, *(char**)((char*)owner + 0x30));
            }
#else
            StoreStruct* formatter = MessageSystem_GetInstance();
            func_02046380(formatter);
            Struct_0207d538 combatant;
            NameText_InitFromPartyMember(&combatant, GameState_GetLeaderIndex(GameState::GetInstance()));
            formatter->combatant = &combatant;
            char first[0x80] = {};
            char second[0x80] = {};
            Struct_0207d538_2 number;
            NameText_Clear(&number);
            number.first = first;
            number.second = second;
            func_020dcf7c(amount, &number);
            formatter->number = &number;
            char* message = StandardStrings_Get(0x54);
            MessageSystem_FormatText(formatter, 12, message, output, 0xe3, 0, 1);
#endif
            break;
        }
        }
        if (result == -2) return 0;
        return 1;
    } else if (type == 1) {
        func_0207d2c4(owner, value);
#if defined(jpn)
        sprintf(output, &data_020f106e, value);
#else
        StoreStruct* formatter = MessageSystem_GetInstance();
        func_02046380(formatter);
        func_020465c0(formatter, 0, value);
        char* message = StandardStrings_Get(0x3f4);
        MessageSystem_FormatText(formatter, 12, message, output, 0xe3, 0, 1);
#endif
        return 1;
    } else {
#if defined(jpn)
        sprintf(output, &data_020f1094);
#else
        sprintf(output, StandardStrings_Get(0x2d));
#endif
        return 0;
    }
}
