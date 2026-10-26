#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#if defined(jpn)
enum { kRegioncc = 0xc8 };
#else
enum { kRegioncc = 0xcc };
#endif

extern "C" int MessageSystem_GetInstance();
struct Container020e0310;
extern "C" int KeyTable_Get(struct Container020e0310* c, int key);

// USA: func_ov003_0217dd10
extern "C" ARM void func_ov003_0217dd10(char* obj, int key) {
    MessageSystem* window = (MessageSystem*)MessageSystem_GetInstance();
    const char* text = (const char*)KeyTable_Get((struct Container020e0310*)(obj + kRegioncc), (short)key);
#if defined(jpn)
    func_0204500c(window, text, 0);
#else
    func_0204500c(window, text, 0, 0xe3);
#endif
    window->unknown_19b2_ = 1;
    window->state = 2;
}
