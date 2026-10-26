#include <globaldefs.h>

extern "C" unsigned short* Zone3D_GetInstance(void);

struct Struct_0208b494 {
    char pad[0xac];
    int captured;   // 0xac
    int done;       // 0xb0
};

// USA: func_0208b494
extern "C" ARM void func_0208b494(struct Struct_0208b494* obj) {
    if (obj->done == 0) {
        obj->done = 1;
        obj->captured = *Zone3D_GetInstance();
    }
}
