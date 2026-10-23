#include <globaldefs.h>

struct Vec3PairRecord020a0db8;
int InitVec3PairRecordType2(struct Vec3PairRecord020a0db8*, int*, int*, int);

// Main, originally CallFunc020a0db8AtField0x16c_0202ee38 (USA 0x0202ee38, EUR 0x0202ee48, JPN 0x0202e9a8)
ARM int Camera_EasePositionTo(char* obj, int a, int b) {
    return InitVec3PairRecordType2((struct Vec3PairRecord020a0db8*)(obj + 0x16c), (int*)(obj + 0x4), (int*)a, b);
}
