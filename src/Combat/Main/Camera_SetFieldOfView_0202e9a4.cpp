#include <globaldefs.h>

short fix32sin(int x);
short fix32cos(int x);

struct AngleTrig0202e9a4;

// Sets the camera's field of view: +0x58 holds it in degrees (fx32), +0x5c/+0x60 (Camera::frustum[0], [1]) its
// sine and cosine. x 0x47 / 0x1000 (~pi/180) turns degrees into the radians fix32sin takes.
// Main, originally SetAngleAndTrigTable0202e9a4 (USA 0x0202e9a4, EUR 0x0202e9b4, JPN 0x0202e514)
extern "C" ARM void Camera_SetFieldOfView(struct AngleTrig0202e9a4* camera, int fieldOfView) {
    *(int*)((char*)camera + 0x58) = fieldOfView;
    *(int*)((char*)camera + 0x5c) = fix32sin((int)(((long long)fieldOfView * 0x47 + 0x800) >> 12));
    *(int*)((char*)camera + 0x60) = fix32cos((int)(((long long)fieldOfView * 0x47 + 0x800) >> 12));
}
