#include <globaldefs.h>

extern "C" void func_ov017_021bff2c(void*);
extern "C" void func_ov017_021bf490(void*);

// Overlay 17, originally CallTwoHelpersWithSelf_021bf5dc (USA/EUR 0x021bf5dc, JPN 0x021bfb88)
ARM void FieldTask_EndOpenCupboard(void* obj) {
    func_ov017_021bff2c(obj);
    func_ov017_021bf490(obj);
}
