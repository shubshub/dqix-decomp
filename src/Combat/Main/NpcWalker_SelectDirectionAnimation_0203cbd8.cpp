#include <globaldefs.h>
#include "NitroSDK/Matrix.h"

// A facing table entry: an animation of data_020efd00, and whether the sprite is flipped
struct Struct_020e7918 { unsigned char unknown_0_, mirrored_; };
// An NpcWalker: its sprite flags and rotation, then its walking state
struct DirectionObject {
    char pad0[0x50]; int flags_, rotation_, unknown_58_, motionFlags_, angle_;
    char unknown_64_[0x90 - 0x64]; int angleOffset_;
    unsigned char talkReturnFrames_, fourDirections_;
};
struct Struct_0203ca24_2;
extern "C" int Camera_GetOrbitYaw(void*);
extern "C" void func_0203f1e4(Struct_0203ca24_2*, const char*);
// Facing tables, indexed by the camera-relative angle: four-direction sprites {stand_down, stand_left flipped,
// stand_up, stand_left}; walking {walk_down, walk_right, walk_up, walk_left}; standing, 8 directions from
// stand_down; lying, 8 directions from sleep_down (the left ones flipped)
extern Struct_020e7918 data_020e7920[4], data_020e7918[4], data_020e7938[8], data_020e7928[8];
// The animation names: stand_up ... stand_r_down, walk_up ... walk_r_down, sleep_down ... sleep_r_up
extern const char* data_020efd00[];
static inline Struct_020e7918* DirectionAt(Struct_020e7918* table, int index) { return &table[index]; }
static inline Struct_020e7918* RotatedDirection(Struct_020e7918* table, int index, DirectionObject* self, int rotation) {
    self->rotation_ = rotation;
    return &table[index];
}

enum {
    kSpriteFlipped = 2,     // flags_
    kLyingDown = 8,         // flags_: sleep animations, angleOffset_ added
    kWalking = 1,           // motionFlags_ (NpcWalker flags)
    kWalkInPlace = 8        // motionFlags_: the walk animations without walking (func_0203cec4)
};

// Main, originally func_0203cbd8 (USA 0x0203cbd8, EUR 0x0203cbe8, JPN 0x0203d110)
extern "C" ARM void NpcWalker_SelectDirectionAnimation(DirectionObject* self, void* camera) {
    int angle = self->angle_ - Camera_GetOrbitYaw(camera);
    int lyingDown = self->flags_ & kLyingDown;
    if (lyingDown) angle += self->angleOffset_;
    while (angle < 0) angle += FIX_2PI;
    while (angle >= FIX_2PI) angle -= FIX_2PI;
    Struct_020e7918* entry;
    if (self->fourDirections_) {
        entry = DirectionAt(data_020e7920, (fix32_Divide((angle + FIX_2PI) * 4 + FIX_2PI / 2, FIX_2PI) >> 12) & 3);
    } else if (!lyingDown) {
        if ((self->motionFlags_ & kWalking) || (self->motionFlags_ & kWalkInPlace)) {
            entry = DirectionAt(data_020e7918, (fix32_Divide((angle + FIX_2PI) * 4 + FIX_2PI / 2, FIX_2PI) >> 12) & 3);
        } else {
            entry = DirectionAt(data_020e7938, (fix32_Divide((angle + FIX_2PI) * 8 + FIX_2PI / 2, FIX_2PI) >> 12) & 7);
        }
    } else {
        entry = RotatedDirection(data_020e7928, (fix32_Divide((angle + FIX_2PI) * 8 + FIX_2PI / 2, FIX_2PI) >> 12) & 7, self, -angle);
    }
    if (!entry) return;
    if (entry->mirrored_) self->flags_ |= kSpriteFlipped;
    else self->flags_ &= ~kSpriteFlipped;
    func_0203f1e4((Struct_0203ca24_2*)self, data_020efd00[entry->unknown_0_]);
}
