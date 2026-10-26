#include <globaldefs.h>
#include "NitroSDK/Matrix.h"

struct Vec3PairRecord020a0db8 {
    int type;
    Vector3i from;
    Vector3i to;
    int pad;
    int f20;
    int f24;
};

// Main, originally InitVec3PairRecordType2 (USA 0x020a0db8, EUR 0x020a0dc8, JPN 0x020a2b30)
ARM void Vec3Ease_StartProportional(struct Vec3PairRecord020a0db8* rec, int* from, int* to, int a3) {
    rec->from = *(const Vector3i*)from;
    rec->to = *(const Vector3i*)to;
    rec->f24 = a3;
    rec->type = 2;
}
