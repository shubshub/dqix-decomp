#include <globaldefs.h>

#include <World/Object3D.h>

struct AnimationPlayFlags {
    int values[12];
};

struct AnimationIdRemap {
    signed char values[12];
};

struct IdleAnimationMap {
    unsigned char values[2][7];
};

extern const AnimationPlayFlags data_020e77cc;
extern const AnimationIdRemap data_020e77b0;
extern const IdleAnimationMap data_020e77bc;
extern const char *const data_020ef978[7];
extern const char data_020efa40[];
extern const char *const data_020ef994[12];

struct GameObjectFields {
    Object3D object;
    unsigned char unknown_ac[0xc0 - 0xac];
    unsigned char animation;
    unsigned char c1_low : 4;
    unsigned char idlePose : 4;
    unsigned char unknown_c2[0xe0 - 0xc2];
    unsigned char e0_bit0 : 1;
    unsigned char enableObjectFlag18 : 1;
};

// Main, originally func_02033ba0 (USA 0x02033ba0, EUR 0x02033bb0, JPN 0x020336d8)
extern "C" ARM void GameObject_PlayAnimation(void *gameObject, int animation) {
    GameObjectFields *self = static_cast<GameObjectFields *>(gameObject);
    if (animation < 0) {
        return;
    }
    AnimationPlayFlags playFlags = data_020e77cc;
    AnimationIdRemap remap       = data_020e77b0;
    if (animation == 0) {
        unsigned int idlePose = self->idlePose;
        if (idlePose < 7) {
            IdleAnimationMap idle = data_020e77bc;
            int idleRow           = 0;
            if (self->object.actorIndex_ >= 0xc0 && self->object.actorIndex_ <= 0xc7) {
                idleRow = 1;
            }
            if (!self->object.SetAnimationByName(data_020ef978[idle.values[idleRow][idlePose]], 0x10)) {
                self->object.SetAnimationByName(data_020efa40, 0);
            }
            if (self->enableObjectFlag18) {
                self->object.EnableFlag(0x40000);
            }
        }
    } else {
        self->object.SetAnimationByName(data_020ef994[animation], playFlags.values[animation]);
        int storedAnimation = remap.values[animation];
        if (storedAnimation > -1) {
            animation = storedAnimation;
        }
    }
    self->animation = animation;
}
