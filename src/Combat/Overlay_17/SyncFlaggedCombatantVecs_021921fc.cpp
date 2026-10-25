#include <globaldefs.h>
#include "GameState/GameState.h"

void* GameState_GetParty(GameState* battleStruct);
struct Vector3i;
struct Obj02033874;
void SetVecYFromValue02033874(struct Obj02033874* obj, int arg);
struct Bytes02033b88;
int SetByte0xbeShiftPrev(struct Bytes02033b88* p, int val);
void ClearBytesAndZeroBlock02039d24(unsigned char* obj);
unsigned char GameState_GetLeaderIndex(GameState* battleStruct);
void SetFlag0x1ceBit0x4_02039d48(unsigned char* obj);

// USA: func_ov017_021921fc  (semantic: SyncFlaggedCombatantVecs_021921fc)
extern "C" ARM void func_ov017_021921fc(int* vec, int angle, int resetFlag) {
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
            SetVecYFromValue02033874((struct Obj02033874*)c, angle);
            if (resetFlag != 0) {
                SetByte0xbeShiftPrev((struct Bytes02033b88*)c, 0);
                *(unsigned short*)((char*)c + 0xb2) = 0;
                ClearBytesAndZeroBlock02039d24((unsigned char*)c);
            }
            if (keys[i] != GameState_GetLeaderIndex(bs)) {
                SetFlag0x1ceBit0x4_02039d48((unsigned char*)c);
            }
        }
    }
}
