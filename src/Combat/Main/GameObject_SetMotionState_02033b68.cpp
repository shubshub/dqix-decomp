#include <globaldefs.h>

extern "C" void func_02033ce8(void*);

struct Obj02033b68 {
    char pad[0xbe];
    unsigned char fbe;
    unsigned char fbf;
};

// Main, originally SetByteIfChanged02033b68 (USA 0x02033b68, EUR 0x02033b78, JPN 0x020336a0)
ARM void GameObject_SetMotionState(struct Obj02033b68* obj, int newVal) {
    if (obj->fbe == newVal) return;
    obj->fbf = obj->fbe;
    obj->fbe = newVal;
    func_02033ce8(obj);
}
