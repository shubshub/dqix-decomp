#include <globaldefs.h>
#include "std_library_functions.h"
#include "Resource/CharacterCreationUI.h"

#if defined(jpn)
enum { WindowOffset = 0xe20, TextOffset = 0x1a98, Enum_ov002_0215c028_2400 = 0x800, Enum_ov002_0215c028_40 = 43 };
#else
enum { WindowOffset = 0xec8, TextOffset = 0x1bd0, Enum_ov002_0215c028_2400 = 0x960, Enum_ov002_0215c028_40 = 40 };
#endif

namespace {
struct Struct_ov002_0215c028 {
    unsigned char unknown0[WindowOffset];
    CreationWindow window;
    unsigned char unknown_f84_[TextOffset - WindowOffset - sizeof(CreationWindow)];
    char* text;
};
}

extern "C" void func_ov002_0215be00(void*, int, short, short);
extern "C" int MessageSystem_GetInstance();
extern "C" void Window_Update(void*, int);
struct Struct_0205def8;
extern "C" void func_0205def8(Struct_0205def8*, int, int);
#if defined(jpn)
extern const char data_ov002_0216d91f[];
extern "C" void func_020474a8(void*, unsigned char, const char*, char*);
extern "C" int func_0204234c(char*, int);
#else
extern const char data_ov002_0216d26c[];
extern "C" void MessageSystem_FormatText(void*, int, int, int, int, int, int);
extern "C" int func_02041cc0(char*, int);
#endif
extern "C" void Window_OpenPane(void*, const char*, int, unsigned char, unsigned char, unsigned char, void*
#if !defined(jpn)
                            , unsigned char
#endif
);

// USA: func_ov002_0215c028
// JPN: func_ov002_0215d12c
extern "C" ARM void func_ov002_0215c028(char* base) {
    Struct_ov002_0215c028* state = ((Struct_ov002_0215c028*)(base));
    func_ov002_0215be00(state, Enum_ov002_0215c028_40, 0x15, 0x13);
    void* messages = ((void*)(MessageSystem_GetInstance()));
    memset(state->text, 0, Enum_ov002_0215c028_2400);
#if defined(jpn)
    func_020474a8(messages, 8, data_ov002_0216d91f, state->text);
    func_0204234c(state->text, 0x11);
#else
    MessageSystem_FormatText(messages, 8, ((int)(data_ov002_0216d26c)), ((int)(state->text)), 0x100, 0, 0);
    func_02041cc0(state->text, 0x11);
#endif
    Window_OpenPane(&state->window, state->text, 0, 0, 0, 1, 0
#if !defined(jpn)
                 , 0
#endif
    );
    Window_Update(&state->window, 4);
    func_0205def8(((Struct_0205def8*)(&state->window)), 0, Enum_ov002_0215c028_40);
}
