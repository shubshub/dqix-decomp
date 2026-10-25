#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { Enum_ov000_0217dcf0_7520 = 0x1f98, Enum_ov000_0217dcf0_7528 = 0x1fa0,
       Enum_ov000_0217dcf0_7531 = 0x1fa3, Enum_ov000_0217dcf0_7538 = 0x1faa };
#else
enum { Enum_ov000_0217dcf0_7520 = 0x1d60, Enum_ov000_0217dcf0_7528 = 0x1d68,
       Enum_ov000_0217dcf0_7531 = 0x1d6b, Enum_ov000_0217dcf0_7538 = 0x1d72 };
#endif

struct Struct_0205c570;
struct Entry_0205d6a0;
struct SePlayer;

int Window_GetSelectedIndex(struct Struct_0205c570* s);
void SePlayer_Play(struct SePlayer* obj, int a, int b);
void Window_ClosePane(struct Entry_0205d6a0* a, int flag);
int CheckFlagsOrField_0217c5f4_0217c5f4(void* obj);
extern "C" int func_ov000_0217c594(void* obj, int limit);
extern "C" void func_ov000_02176e3c(void* obj, int zero, int val, int arg1, int arg2, int one);
extern "C" void func_ov000_0217c638(void* obj, int arg1, int arg2);
extern "C" void func_ov017_021c847c(void);

extern char g_sePlayer[];

struct Struct_ov000_0217dcf0 {
    char unknown_0_[0x3c];
    unsigned int unknown_3c_0_ : 30;
    unsigned int unknown_3f_6_ : 1;
    unsigned int unknown_3f_7_ : 1;
};

struct Struct_ov000_0217dcf0_2 {
    char unknown_0_[0x4c];
    int unknown_4c_;
#if defined(jpn)
    char unknown_50_[0x488 - 0x50];
#else
    char unknown1_50_[0x448 - 0x50];
#endif
};

// USA: func_ov000_0217dcf0
extern "C" ARM void func_ov000_0217dcf0(char* obj, int arg1, int arg2) {
    *(unsigned short*)(obj + MenuFlagsOffset0217dcf0) |= 0x100;
    *(unsigned char*)(obj + ActiveSelectionOffset0217dcf0) = Window_GetSelectedIndex((struct Struct_0205c570*)(obj + 0x188));
    if (func_ov000_0217c594(obj, 0)) {
        SePlayer_Play((struct SePlayer*)g_sePlayer, 1, 0);
        GameState* gs = GameState::GetInstance();
        unsigned char* field2a04 = (unsigned char*)GameState_GetParty(gs);
        signed char cursor = *(signed char*)(obj + ActiveSelectionOffset0217dcf0);
        if (cursor < field2a04[0xf7c]) {
            struct Entry0217dcf0* entry = &((struct Entry0217dcf0*)(obj + 0x958))[*(signed char*)(obj + cursor + 0x70)];
            GameObject* member = gs->GetPartyMemberByIndex((signed char)entry->field4c);
            if (member != NULL) {
                struct MemberInfo0217dcf0* info = (struct MemberInfo0217dcf0*)member->baseStats_;
                unsigned short v = info->flag30;
                v++;
                v %= 2;
                info->flag30 = v;
                func_ov000_02176e3c(obj, 0, *(signed char*)(obj + *(signed char*)(obj + CommandDepthOffset0217dcf0) + CommandStackOffset0217dcf0), arg1, arg2, 0);
                func_ov017_021c847c();
            }
        }
    } else if (CheckFlagsOrField_0217c5f4_0217c5f4(obj)) {
        Window_ClosePane((struct Entry_0205d6a0*)(obj + 0x188), 0);
        *(unsigned char*)(obj + *(signed char*)(obj + CommandDepthOffset0217dcf0) + CommandStackOffset0217dcf0) = 0;
        *(signed char*)(obj + CommandDepthOffset0217dcf0) = *(signed char*)(obj + CommandDepthOffset0217dcf0) - 1;
        func_ov000_0217c638(obj, arg1, arg2);
    }
}
