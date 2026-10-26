#include <globaldefs.h>
#include "World/Object3D.h"

struct Obj02033b68 {
    char pad0[4];
    short actorIndex;
    char pad[0xbe - 6];
    unsigned char motionState;
    unsigned char previousMotionState;
    unsigned char animation;
    unsigned char c1_low : 4;
    unsigned char idlePose : 4;
    unsigned char c2_low : 4;
    unsigned char c2_bit4 : 1;
    unsigned char c2_high : 3;
    char pad2[0xe0 - 0xc3];
    unsigned char e0Flags;
};

extern "C" void func_02057924(void);
extern "C" void GameObject_PlayMotionAnimation(unsigned char* obj);
extern "C" void GameObject_SetMotionState(struct Obj02033b68* obj, int newVal);

// Main, originally func_02033ce8 (USA 0x02033ce8, EUR 0x02033cf8, JPN 0x02033820)
extern "C" ARM void GameObject_ApplyMotionState(struct Obj02033b68* self) {
    int isPartyMember;
    func_02057924();
    GameObject_PlayMotionAnimation((unsigned char*)self);

    if (self->motionState == 3 || self->motionState == 4) {
        if (self->animation == 7 || self->animation == 8) {
            if (self->animation != 7) return;
            if (self->idlePose == 0) return;
            GameObject_SetMotionState(self, 0);
        }
        return;
    }

    if (self->motionState == 6) {
        if (self->previousMotionState != 6) {
            isPartyMember = (self->actorIndex >= 0 && self->actorIndex <= 3);
            if (!isPartyMember) {
                if (self->c2_bit4 == 0) {
                    self->e0Flags |= 8;
                }
            }
        }
        if (((Object3D*)self)->GetInheritedAlpha() > 0) return;
        ((Object3D*)self)->MakeHidden();
        return;
    }

    if (self->motionState == 5) {
        ((Object3D*)self)->SetInheritedAlpha(1);
        ((Object3D*)self)->TransitionInheritedAlpha(0x1f, 0xfa);
    }
}
