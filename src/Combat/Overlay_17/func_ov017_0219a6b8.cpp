#include <globaldefs.h>
#include "GameState/GameState.h"
#include "World/Zone3D.h"
#include "Input/Input.h"

struct FlagWord02046708;
struct HeadNode02046b24;
struct PointerField32c_ffc0;
struct Obj020397cc;
struct BitField0203402c;
void* MessageSystem_GetInstance();
extern "C" Zone3D* Zone3D_GetInstance();
FlagWord02046708* GlobalFlags_GetInstance();
int IsField0Null_02046b08(void**);
int GetHeadNodeIdOrMinusOne(HeadNode02046b24**);
int TestFlags02046708(FlagWord02046708*, unsigned int);
unsigned char* GetPointerAt0x32c_0200ffc0(PointerField32c_ffc0*);
int CheckSubstructByte0x7cPositive_020535c8(signed char*);
int CheckField0xc4Low15BitsNonZero(BitField0203402c*);
unsigned char GetByte0x26c_02039d7c(char*);
extern "C" void __clear(void*, int);
void GameObject_DisableControl(Obj020397cc*, int);
void ClearByteFlagAt0x154_020a7f40(unsigned char*);
void SetByteFlagAt0x154_020a7f34(unsigned char*);
void GameObject_EnableControl(void*);

// USA: func_ov017_0219a6b8
extern "C" ARM void func_ov017_0219a6b8(GameResources* self) {
    GameState* game = GameState::GetInstance();
    unsigned char* other;
    MessageSystem_GetInstance();
    unsigned short zone = Zone3D_GetInstance()->currentZoneID_;
    FlagWord02046708* flags = GlobalFlags_GetInstance();
    if (!IsField0Null_02046b08((void**)self->fieldTaskQueue_)) return;
    if (GetHeadNodeIdOrMinusOne((HeadNode02046b24**)(void**)self->fieldTaskQueue_) == 2) return;
    if (TestFlags02046708(flags, 0x800)) return;
    GameObject* actor = game->GetUnknownGameObject();
    if (!actor) return;
    other = GetPointerAt0x32c_0200ffc0((PointerField32c_ffc0*)game);
    if (CheckSubstructByte0x7cPositive_020535c8((signed char*)actor)) return;
    if (g_keyManager.TestKeysHeld(2) && !self->fieldButtonState[0]) return;
    if (CheckField0xc4Low15BitsNonZero((BitField0203402c*)actor)) return;
    if (GetByte0x26c_02039d7c((char*)actor)) return;
    if (zone == 0x2774) return;
    int indices[1];
    __clear(indices, sizeof(indices));
    for (int i = 0; i < 1; ++i) {
        int index = indices[i];
        int width = 24;
        int height = 24;
        if (index == 0) { width = 32; height = 32; }
        if (g_touchInput.pressed_) {
            int x, y;
            g_touchInput.GetTouchPoint(&x, &y);
            if (self->fieldButtonX[index] < x && x < self->fieldButtonX[index] + width && self->fieldButtonY[index] < y && y < self->fieldButtonY[index] + height) {
                GameObject_DisableControl((Obj020397cc*)actor, 1);
                if (other && zone == 0x2710) ClearByteFlagAt0x154_020a7f40(other);
                self->fieldButtonState[index] = 1;
            }
        } else if (g_touchInput.isRepeatValid_ && (g_touchInput.currentReading_.isHeld)) {
            int var12, var13;
            g_touchInput.GetTouchPoint(&var12, &var13);
            if (arg0->unknown_3658_[var7] == 1) {
                if (!(arg0->unknown_3634_[var7] < var12 && var12 < arg0->unknown_3634_[var7] + var8 && arg0->unknown_3646_[var7] < var13 && var13 < arg0->unknown_3646_[var7] + var9)) arg0->unknown_3658_[var7] = 2;
            } else if (arg0->unknown_3658_[var7] == 2) {
                int var14 = (var12 - 12 + arg0->unknown_3634_[var7]) / 2;
                int var15 = (var13 - 12 + arg0->unknown_3646_[var7]) / 2;
                if (var14 < 0) var14 = 0;
                if (256 - var8 < var14) var14 = 256 - var8;
                if (var15 < 0) var15 = 0;
                if (192 - var9 < var15) var15 = 192 - var9;
                arg0->unknown_3634_[var7] = var14;
                arg0->unknown_3646_[var7] = var15;
            }
        } else if (g_touchInput.released_) {
            if (self->fieldButtonState[index]) {
                GameObject_EnableControl(actor);
                if (other && zone == 0x2710) SetByteFlagAt0x154_020a7f34(other);
            }
            if (self->fieldButtonState[index] == 1) {
                self->unknown_42e3[1] = 1;
                GameObject_EnableControl(actor);
                if (other && zone == 0x2710) SetByteFlagAt0x154_020a7f34(other);
            }
            self->fieldButtonState[index] = 0;
        } else if (self->fieldButtonState[index]) {
            GameObject_EnableControl(actor);
            if (other && zone == 0x2710) SetByteFlagAt0x154_020a7f34(other);
            self->fieldButtonState[index] = 0;
        }
        if (arg0->unknown_3658_[var7]) return;
    }
}
