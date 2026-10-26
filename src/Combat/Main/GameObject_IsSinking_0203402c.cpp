#include <globaldefs.h>

// The bits GameObject_Draw and GameObject_FaceGameObject name: while sinkTimer runs (SetField0xc4Low15Bits_02034044 starts it
// at 5000), GameObject_Draw draws the object lowered by up to 2/3 of its height
struct BitField0203402c {
    char unknown0[0xc4];
    unsigned short sinkTimer : 15;
    unsigned short turningInPlace : 1;
};

// Main, originally CheckField0xc4Low15BitsNonZero (USA 0x0203402c, EUR 0x0203403c, JPN 0x02033b64)
ARM int GameObject_IsSinking(struct BitField0203402c* object) {
    return object->sinkTimer != 0;
}
