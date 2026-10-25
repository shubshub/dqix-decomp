#include <globaldefs.h>
#include "Resource/MessageSystem.h"

int MessageSystem_GetInstance();
struct MessageOwner02159250 {
    char unknown0[0x5b1];
    unsigned char messageState;
    unsigned char messageFlag;
};

// USA: func_ov003_02159250  (semantic: SetGlobalFieldsFromObj_02159250)
extern "C" ARM void func_ov003_02159250(MessageOwner02159250* owner, const char* text) {
    if (text == 0) return;
    MessageSystem* window = (MessageSystem*)MessageSystem_GetInstance();
#if defined(jpn)
    func_0204500c(window, text, 0);
#else
    func_0204500c(window, text, 0, 0xe3);
#endif
    window->b19b2 = owner->messageFlag;
    window->state = owner->messageState;
}
