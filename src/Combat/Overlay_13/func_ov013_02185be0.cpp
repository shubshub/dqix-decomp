#include <globaldefs.h>

#if defined(jpn)
#define func_02041d9c func_02042428
#endif

#if defined(jpn)
#define func_ov013_02185be0 func_ov013_02186db0
#endif

struct Struct_ov013_021846a0_2 {
#if defined(jpn)
    char unknown0[0x5ac];
#else
    char unknown0[0x620];
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
    unsigned char unknown_664_[4];
    int unknown_668_;
    int unknown_66c_;
    int unknown_670_;
    int skillPoints[5];
    int unknown_688_[5];
    unsigned char unknown_69c_[5];
    char unknown_6a1_[8];
    unsigned char unknown_6a9_[5];
};

struct Container020e0310;
extern "C" int Text_AppendFrameTag(char* dst, int a1, int a2, int a3, int a4, int a5);
extern "C" int Text_AppendCursorTag(char* dst, int cursor);
extern "C" void* __clear(void* dst, int count);
extern "C" int func_02041d9c(char* dst, int size);
extern "C" int KeyTable_Get(struct Container020e0310* c, int key);
extern "C" int Text_Append(char* dst, const char* src);
extern "C" int Text_AppendNTag(char* dst, int n, const char* name);

// USA: func_ov013_02185be0
extern "C" ARM void func_ov013_02185be0(Struct_ov013_021846a0_2* menu, char* dst) {
    char choiceText[0x20];
    int choice;

    if (menu->windowInput == 2) {
        Text_AppendFrameTag(dst, menu->confirmationChoice, 9, 3, 6, 2);
    }
    Text_AppendCursorTag(dst, menu->confirmationChoice);

    for (choice = 0; choice < 2; choice++) {
        __clear(choiceText, 0x20);
        func_02041d9c(choiceText, 0xc);
        Text_Append(choiceText, (const char*)KeyTable_Get((Container020e0310*)menu->texts, (short)(choice + 0xa)));
        Text_AppendNTag(dst, choice, choiceText);
        if (choice < 1) {
            Text_Append(dst, (const char*)KeyTable_Get((Container020e0310*)menu->texts, 0));
        }
    }
}
