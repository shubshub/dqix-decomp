#include <globaldefs.h>
#include "Resource/MessageSystem.h"

extern "C" int MessageSystem_GetInstance();
struct Struct_ov003_0215cab0 {
#if defined(jpn)
    char unknown0[0x406];
#else
    char unknown0[0x3ee];
#endif
    unsigned char unknown_3ee_;
    unsigned char unknown_3ef_;
};

// USA: func_ov003_0215cab0
extern "C" ARM void func_ov003_0215cab0(Struct_ov003_0215cab0* owner, const char* text) {
    if (text == 0) return;
    MessageSystem* window = (MessageSystem*)MessageSystem_GetInstance();
#if defined(jpn)
    func_0204500c(window, text, 0);
#else
    func_0204500c(window, text, 0, 0xe3);
#endif
    window->unknown_19b2_ = owner->unknown_3ef_;
    window->state = owner->unknown_3ee_;
}
