#include <globaldefs.h>

extern "C" unsigned short* Zone3D_GetInstance(void);

struct Obj0208b494 {
    char pad[0xac];
    int captured;   // 0xac
    int done;       // 0xb0
};

// USA: func_0208b494
ARM void CaptureValueOnce0208b494(struct Obj0208b494* obj) {
    if (obj->done == 0) {
        obj->done = 1;
        obj->captured = *Zone3D_GetInstance();
    }
}
