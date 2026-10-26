#include <globaldefs.h>

enum {
    GameObject_timerBitsOffset = 0xc4,  // sinkTimer : 15, then turningInPlace : 1 (GameObject_UpdateMovement, GameObject_FaceGameObject)
    TimerBits_TurningInPlace = 0x8000,
};

// Main, originally ClearField0xc4KeepBit0x8000_0203409c (USA 0x0203409c, EUR 0x020340ac, JPN 0x02033bd4)
ARM void GameObject_StopSinking(unsigned char* object) {
    *(unsigned short*)(object + GameObject_timerBitsOffset) &= 0xFFFF0000 | TimerBits_TurningInPlace;  // sinkTimer = 0
}
