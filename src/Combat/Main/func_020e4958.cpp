#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct0200fb08;
int GameState_GetLanguage(Struct0200fb08*);
int STD_GetStringLength(const char*);
extern "C" int memcmp(const char*, const char*, unsigned int);
extern "C" int sprintf(char*, const char*, ...);
extern "C" void* memset(void*, int, unsigned int);
extern "C" void* memcpy(void*, const void*, unsigned int);
extern "C" void __clear(void*, unsigned int);
extern "C" void func_020e4864(char*, char*, int, int, int, int);
extern void (*data_020ee9f0[])(char*, int);
struct Struct_020eea50 {
    signed char unknown_0_[4];
    const char* unknown_4_;
    signed char unknown_8_;
    char unknown_9_[3];
};
extern Struct_020eea50 data_020eea50[];
struct Struct_020eea08 { char unknown_0_[6]; };
extern Struct_020eea08 data_020eea08[];
extern char data_020f2dcf[];

// USA: func_020e4958
extern "C" ARM void func_020e4958(char** destination, int value, int inputMode, int kind, int group, int choice) {
    int mode;
    char source[0x100] = {0};
    mode = 1 - inputMode;
    if (inputMode == -1) mode = 0;
    int selection = group;
    if (selection == -1) selection = 0;
    selection = selection * 3;
    data_020ee9f0[selection + (mode + kind)](source, value);
    char expanded[0x100];
    mode = 1 - mode;
    __clear(expanded, 0x100);
    if (choice == -1 && GameState_GetLanguage((Struct0200fb08*)GameState::GetInstance()) == 3) choice = 0;
    char* input;
    char* output = expanded;
    input = source;
    for (;;) {
        if (*input == 0) break;
        if (*input == '[') {
            int replaced = 0;
            TextToken020e4958* token = data_020eea50;
            int length;
            while ((length = token->length) != 0) {
                if (memcmp(input + 1, token->name, length) == 0) {
                    if (choice != -1) {
                        output += sprintf(output, data_020eea08[token->choices[choice]].text);
                        input += token->length + 1;
                        if (*input != ' ') output += sprintf(output, data_020f2dcf);
                    } else {
                        if (*(var4 += var8 + 1) == ' ') var4++;
                    }
                    var6 = 1;
                    break;
                }
                var7++;
            }
            if (var6) continue;
        }
        *var5 = *var4;
        var4++;
        var5++;
    }
    *output = *input;
    memset(source, 0, 0x100);
    func_020e4864(expanded, source, mode, kind, selection, choice);
    int length = STD_GetStringLength(source);
    memcpy(*destination, source, length);
    *destination += length;
}
