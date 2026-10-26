#include <globaldefs.h>

struct ShortPair0xba0xbc {
    char pad[0xba];
    short shakeAmplitude;
    short shakeTimeLeft;
};

// Main, originally SetFields0xbaAnd0xbc_02032fd0 (USA 0x02032fd0, EUR 0x02032fe0, JPN 0x02032b08)
extern "C" ARM void GameObject_Shake(ShortPair0xba0xbc* object, short amplitude, unsigned short duration) {
    object->shakeAmplitude = amplitude;
    object->shakeTimeLeft = duration;
}
