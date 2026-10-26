#include <globaldefs.h>

extern "C" int func_0207964c(void* obj);

struct Obj02033b68 {
    char pad[0xbe];
    unsigned char unknown_be_;
    unsigned char unknown_bf_;
};
extern "C" void GameObject_SetMotionState(struct Obj02033b68* obj, int newVal);

// USA: func_0207872c
extern "C" ARM int func_0207872c(struct Obj02033b68* p) {
    if (p->unknown_be_ != 2) {
        GameObject_SetMotionState(p, 2);
    }
    return func_0207964c(p);
}
