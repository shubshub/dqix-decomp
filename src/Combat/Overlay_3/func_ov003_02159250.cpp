#include <globaldefs.h>
#include "Resource/MessageSystem.h"

extern "C" int MessageSystem_GetInstance();
struct Struct_ov003_02159250 {
    char unknown0[0x5b1];
    unsigned char unknown_5b1_;
    unsigned char unknown_5b2_;
};

// USA: func_ov003_02159250
extern "C" ARM void func_ov003_02159250(Struct_ov003_02159250* owner, const char* text) {
    if (text == 0) return;
    MessageSystem* window = (MessageSystem*)MessageSystem_GetInstance();
#if defined(jpn)
    func_0204500c(window, text, 0);
#else
    func_0204500c(window, text, 0, 0xe3);
#endif
    window->unknown_19b2_ = owner->unknown_5b2_;
    window->state = owner->unknown_5b1_;
}
