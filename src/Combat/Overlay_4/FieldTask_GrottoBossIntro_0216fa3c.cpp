#include <globaldefs.h>

extern "C" void func_020e3f1c(void* a);

// Overlay 4, originally func_ov004_0216fa3c (USA/EUR 0x0216fa3c, JPN 0x021701cc)
extern "C" ARM void FieldTask_GrottoBossIntro(void* a) {
    func_020e3f1c(a);
}
