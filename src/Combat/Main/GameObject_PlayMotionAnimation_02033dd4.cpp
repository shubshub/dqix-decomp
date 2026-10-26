#include <globaldefs.h>

enum { kMotionStateCount = 9, kAnimationCount = 12 };

struct GameObjectFields {
    char pad[0xbe];
    unsigned char motionState;
    unsigned char previousMotionState;
    unsigned char animation;
};

extern signed char data_020ef9c4[][kAnimationCount + 1];
extern "C" void GameObject_PlayAnimation(void* obj, int value);

// Main, originally ApplyStateTableValue02033dd4 (USA 0x02033dd4, EUR 0x02033de4, JPN 0x0203390c)
ARM void GameObject_PlayMotionAnimation(unsigned char* gameObject) {
    GameObjectFields* self = (GameObjectFields*)gameObject;
    if (self->motionState >= kMotionStateCount) return;
    if (self->animation >= kAnimationCount) self->animation = 0;
    GameObject_PlayAnimation(self, data_020ef9c4[self->motionState][self->animation]);
}
