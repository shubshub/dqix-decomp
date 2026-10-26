#include <globaldefs.h>

extern "C" void func_ov003_02168324(int val);
extern "C" void func_ov003_0217e36c(void* obj);

struct Obj0217e5b0 {
    unsigned char f0;
    unsigned char f1;
    char pad2[0x1e];
    int f20;
};

// Overlay 3, originally InitObj_0217e5b0 (USA/EUR 0x0217e5b0, JPN 0x0217d2b8)
extern "C" ARM void FieldTask_EndBank(struct Obj0217e5b0* obj) {
    if (obj->f20 != 0) {
        func_ov003_02168324(obj->f20);
    }
    func_ov003_0217e36c(obj);
    obj->f1 = 1;
}
