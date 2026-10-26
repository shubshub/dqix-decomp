#include <globaldefs.h>
void Camera_SetFieldOfView(struct AngleTrig0202e9a4*, int);

// Eases the camera's field of view to fieldOfView (+0x1f0) over duration (+0x1f4, counted down by Camera_UpdateFieldOfViewEase);
// a duration of 0 sets it at once.
// Main, originally SetFields0x1f0And0x1f4_0202f0c4 (USA 0x0202f0c4, EUR 0x0202f0d4, JPN 0x0202ec34)
ARM void Camera_EaseFieldOfViewTo(void* camera, int fieldOfView, int duration) {
    *(int*)((char*)camera + 0x1f0) = fieldOfView;
    *(int*)((char*)camera + 0x1f4) = duration;
    if (duration == 0) {
        Camera_SetFieldOfView((struct AngleTrig0202e9a4*)(camera), (int)(fieldOfView));
    }
}
