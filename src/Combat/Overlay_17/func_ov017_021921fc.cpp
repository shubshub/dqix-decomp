#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* GameState_GetParty(GameState* battleStruct);
struct Vector3i;
struct Obj02033874;
extern "C" void GameObject_SnapFacing(struct Obj02033874* obj, int arg);
struct Bytes02033b88;
extern "C" int GameObject_ForceMotionState(struct Bytes02033b88* p, int val);
extern "C" void GameObject_ResetTrail(unsigned char* obj);
extern "C" unsigned char GameState_GetLeaderIndex(GameState* battleStruct);
extern "C" void func_02039d48(unsigned char* obj);

// USA: func_ov017_021921fc
extern "C" ARM void func_ov017_021921fc(int* vec, int angle, int arg2) {
    unsigned char* keys;
    GameState* bs = GameState::GetInstance();
    unsigned char* base = (unsigned char*)GameState_GetParty(bs);
    keys = base + 0x378;
    int i = 0;
    keys = keys + 0xc00;
    for (; i < base[0xf7c]; i++) {
        GameObject* c = bs->GetPartyMemberByIndex(keys[i]);
        if (c != NULL) {
            *(Vector3i*)(&c->obj3D_.position_.x) = *(Vector3i const*)vec;
            GameObject_SnapFacing((struct Obj02033874*)c, angle);
            if (arg2 != 0) {
                GameObject_ForceMotionState((struct Bytes02033b88*)c, 0);
                *(unsigned short*)((char*)c + 0xb2) = 0;
                GameObject_ResetTrail((unsigned char*)c);
            }
            if (keys[i] != GameState_GetLeaderIndex(bs)) {
                func_02039d48((unsigned char*)c);
            }
        }
    }
}
