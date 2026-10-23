#include <globaldefs.h>

struct Vec3PairRecord020a0db8;
int InitVec3PairRecordType2(struct Vec3PairRecord020a0db8*, int*, int*, int);

// Main, originally CallFunc020a0db8AtField0x194AndClearFlag2_0202ee58 (USA 0x0202ee58, EUR 0x0202ee68, JPN 0x0202e9c8)
ARM void Camera_EaseTargetTo(char* obj, int a, int b) {
    InitVec3PairRecordType2((struct Vec3PairRecord020a0db8*)(obj + 0x194), (int*)(obj + 0x10), (int*)a, b);
    *(int*)(obj + 0x168) &= ~0x2;
}
