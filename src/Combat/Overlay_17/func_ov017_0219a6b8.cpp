#include <globaldefs.h>
#include "GameState/GameState.h"
#include "World/Zone3D.h"
#include "Input/Input.h"

struct FlagWord02046708;
struct HeadNode02046b24;
struct PointerField32c_ffc0;
struct Obj020397cc;
struct BitField0203402c;
extern "C" void* MessageSystem_GetInstance();
extern "C" Zone3D* Zone3D_GetInstance();
extern "C" FlagWord02046708* GlobalFlags_GetInstance();
extern "C" int FieldTaskQueue_IsEmpty(void**);
extern "C" int FieldTaskQueue_GetCurrentKind(HeadNode02046b24**);
extern "C" int FlagWord_TestBits(FlagWord02046708*, unsigned int);
extern "C" unsigned char* GameState_GetShip(PointerField32c_ffc0*);
extern "C" int GameObject_IsGesturing(signed char*);
extern "C" int GameObject_IsSinking(BitField0203402c*);
extern "C" unsigned char GameObject_IsClimbingLadder(char*);
extern "C" void __clear(void*, int);
extern "C" void GameObject_DisableControl(Obj020397cc*, int);
extern "C" void func_020a7f40(unsigned char*);
extern "C" void func_020a7f34(unsigned char*);
extern "C" void GameObject_EnableControl(void*);

// USA: func_ov017_0219a6b8
extern "C" ARM void func_ov017_0219a6b8(GameResources* self) {
    GameState* game = GameState::GetInstance();
    unsigned char* other;
    MessageSystem_GetInstance();
    unsigned short zone = Zone3D_GetInstance()->currentZoneID_;
    FlagWord02046708* flags = GlobalFlags_GetInstance();
    if (!FieldTaskQueue_IsEmpty((void**)self->fieldTaskQueue_)) return;
    if (FieldTaskQueue_GetCurrentKind((HeadNode02046b24**)(void**)self->fieldTaskQueue_) == 2) return;
    if (FlagWord_TestBits(flags, 0x800)) return;
    GameObject* actor = game->GetLeader();
    if (!actor) return;
    other = GameState_GetShip((PointerField32c_ffc0*)game);
    if (GameObject_IsGesturing((signed char*)actor)) return;
    if (g_keyManager.TestKeysHeld(2) && !self->fieldButtonState[0]) return;
    if (GameObject_IsSinking((BitField0203402c*)actor)) return;
    if (GameObject_IsClimbingLadder((char*)actor)) return;
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
                if (other && zone == 0x2710) func_020a7f40(other);
                self->fieldButtonState[index] = 1;
            }
        } else if (g_touchInput.isRepeatValid_ && (g_touchInput.currentReading_.isHeld)) {
            int x, y;
            g_touchInput.GetTouchPoint(&x, &y);
            if (self->fieldButtonState[index] == 1) {
                if (!(self->fieldButtonX[index] < x && x < self->fieldButtonX[index] + width && self->fieldButtonY[index] < y && y < self->fieldButtonY[index] + height)) self->fieldButtonState[index] = 2;
            } else if (self->fieldButtonState[index] == 2) {
                int var14 = (x - 12 + self->fieldButtonX[index]) / 2;
                int var15 = (y - 12 + self->fieldButtonY[index]) / 2;
                if (var14 < 0) var14 = 0;
                if (256 - width < var14) var14 = 256 - width;
                if (var15 < 0) var15 = 0;
                if (192 - height < var15) var15 = 192 - height;
                self->fieldButtonX[index] = var14;
                self->fieldButtonY[index] = var15;
            }
        } else if (g_touchInput.released_) {
            if (self->fieldButtonState[index]) {
                GameObject_EnableControl(actor);
                if (other && zone == 0x2710) func_020a7f34(other);
            }
            if (self->fieldButtonState[index] == 1) {
                self->unknown_42e3[1] = 1;
                GameObject_EnableControl(actor);
                if (other && zone == 0x2710) func_020a7f34(other);
            }
            self->fieldButtonState[index] = 0;
        } else if (self->fieldButtonState[index]) {
            GameObject_EnableControl(actor);
            if (other && zone == 0x2710) func_020a7f34(other);
            self->fieldButtonState[index] = 0;
        }
        if (self->fieldButtonState[index]) return;
    }
}
