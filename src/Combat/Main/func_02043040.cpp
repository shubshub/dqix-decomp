#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "Resource/MessageUpdate.h"

#if defined(jpn)
extern "C" void func_02041bbc(Struct_0204166c* slot);
#define func_020416c0 func_02041bbc
enum { Enum_02043040_0 = 14 };
#else
extern "C" void func_020416c0(Struct_0204166c* slot);
enum { Enum_02043040_0 = 0 };
#endif

// USA: func_02043040
extern "C" ARM void func_02043040(MessageSystem* window) {
    memset(window->unknown_2cc_, 0, sizeof(window->unknown_2cc_));
    window->unknown_9b4_ = Enum_02043040_0;
    for (int index = Enum_02043040_0; index < 0x80; ++index) {
        func_020416c0(&window->glyphs[index]);
        window->unknown_17b8_[index] = 0;
    }
    window->unknown_1868_ = 0;
    window->mode = 0;
    window->unknown_19b2_ = 0;
    window->unknown_19b4_ = 0;
}
