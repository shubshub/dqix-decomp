#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#if defined(jpn)
enum { kRegioncc = 0xc8 };
#else
enum { kRegioncc = 0xcc };
#endif

int MessageSystem_GetInstance();
struct Container020e0310;
int KeyTable_Get(struct Container020e0310* c, int key);

// USA: func_ov003_0217dd10
ARM void SetupField0217dd10(char* obj, int key) {
    MessageSystem* window = (MessageSystem*)MessageSystem_GetInstance();
    const char* text = (const char*)KeyTable_Get((struct Container020e0310*)(obj + kRegioncc), (short)key);
#if defined(jpn)
    func_0204500c(window, text, 0);
#else
    func_0204500c(window, text, 0, 0xe3);
#endif
    window->b19b2 = 1;
    window->state = 2;
}
