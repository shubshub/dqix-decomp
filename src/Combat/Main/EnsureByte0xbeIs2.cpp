#include <globaldefs.h>

extern "C" int func_0207964c(void* obj);

struct Obj02033b68 {
    char pad[0xbe];
    unsigned char fbe;
    unsigned char fbf;
};
void GameObject_SetMotionState(struct Obj02033b68* obj, int newVal);

// USA: func_0207872c
ARM int EnsureByte0xbeIs2_0207872c(struct Obj02033b68* p) {
    if (p->fbe != 2) {
        GameObject_SetMotionState(p, 2);
    }
    return func_0207964c(p);
}
