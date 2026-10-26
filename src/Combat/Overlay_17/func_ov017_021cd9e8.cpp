#include <globaldefs.h>
#include "GameState/GameState.h"

struct SearchStruct0202c1a4;
extern "C" signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);
extern "C" void func_ov017_021cf730(int a, int b);
extern "C" void func_ov017_021c4fa0(int a, int b);
struct U16Field0x6_020375f8;
extern "C" void func_ov017_021cdaa0(void);

struct Struct_ov017_021cd9e8 {
    unsigned char pad0[4];
    unsigned char unknown_4_0_ : 4;
    unsigned char unknown_4_4_ : 4;
    unsigned char pad5[3];
    int unknown_8_;
};

// USA: func_ov017_021cd9e8
extern "C" ARM void func_ov017_021cd9e8(int p0, struct Struct_ov017_021cd9e8* evt, GameState* battleStruct, int p3, struct SearchStruct0202c1a4* search) {
    signed char cur = LinkSession_GetOwnSlot(search);
    if (evt->unknown_4_0_ != cur) return;

    if (evt->unknown_8_ & 0x1) {
        func_ov017_021cdaa0();
    }
    if (evt->unknown_8_ & 0x20) {
        func_ov017_021cf730((signed char)evt->unknown_4_4_, 0);
    }

    int val = -1;
    if (evt->unknown_8_ & 0x10) {
        signed char idx = LinkSession_GetOwnSlot(search);
        GameObject* combatant = battleStruct->GetGameObjectByIndex(idx);
        if (combatant != NULL) {
            val = ((Object3D*)((struct U16Field0x6_020375f8*)combatant))->GetField06();
        }
    }

    if (!(evt->unknown_8_ & 0x4)) return;
    func_ov017_021c4fa0(evt->unknown_4_4_, val);
}
