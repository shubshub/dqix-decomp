#include <globaldefs.h>

extern "C" void func_ov017_021bb27c(void*);
extern "C" void func_ov017_021bb108(void*);

// Overlay 17, originally CallTwoHelpers_021bb8d8 (USA/EUR 0x021bb8d8, JPN 0x021bbed0)
ARM void FieldTask_EndScriptedEvent(void* obj) {
    func_ov017_021bb27c(obj);
    func_ov017_021bb108(obj);
}
