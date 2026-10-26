#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { Enum_ov017_021ce3ac_722 = 0x2c6 };
#else
enum { Enum_ov017_021ce3ac_722 = 0x2d2 };
#endif

extern "C" GameObject* func_0200ff58(GameState* battleStruct, int combatantId);
extern "C" void func_020546a0(void*, int);
extern "C" void func_020546b4(void*, int);
extern "C" void GameObject_SetFollowedMember(unsigned char*, int);
extern "C" void GameObject_SetLinePosition(unsigned char*, int);

struct Struct_ov017_021ce3ac {
    unsigned char pad0[4];
    unsigned short field4;
    signed char field6;
    signed char unknown_7_;
    signed char field8;
    signed char field9;
    unsigned char fielda;
};

// USA: func_ov017_021ce3ac
extern "C" ARM void func_ov017_021ce3ac(int unused0, Struct_ov017_021ce3ac* evt, GameState* battleStruct) {
    GameObject* c = func_0200ff58(battleStruct, evt->field4);
    if (c == NULL) {
        return;
    }
    func_020546a0(c, evt->field6);
    func_020546b4(c, evt->unknown_7_);
    GameObject_SetFollowedMember((unsigned char*)c, evt->field8);
    GameObject_SetLinePosition((unsigned char*)c, evt->field9);
    *((unsigned char*)c + Enum_ov017_021ce3ac_722) = evt->fielda;
}
