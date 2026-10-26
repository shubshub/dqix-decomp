#include <globaldefs.h>
#include "Resource/MessageSystem.h"

struct Container020e0310;
extern "C" int MessageSystem_GetInstance();
extern "C" int KeyTable_Get(Container020e0310* container, int key);

// USA: func_ov013_02185774
extern "C" ARM void func_ov013_02185774(void* obj) {
    unsigned char* menu = (unsigned char*)obj;
    MessageSystem* messages = (MessageSystem*)MessageSystem_GetInstance();
#if defined(jpn)
    unsigned char mode = menu[0x5c8];
    if (mode == 4) {
        func_0204500c(messages, (const char*)KeyTable_Get((Container020e0310*)(menu + 0x5ac), 1000), 0);
    } else if (mode == 3) {
        func_0204500c(messages, (const char*)KeyTable_Get((Container020e0310*)(menu + 0x5ac), 1001), 0);
    } else if (mode == 2) {
        func_0204500c(messages, (const char*)KeyTable_Get((Container020e0310*)(menu + 0x5ac), 1002), 0);
    }
    messages->unknown_19b2_ = 0;
    messages->active = 1;
#else
    unsigned char mode = menu[0x63c];
    if (mode == 4) {
        func_0204500c(messages, (const char*)KeyTable_Get((Container020e0310*)(menu + 0x620), 1000), 0, 0xe3);
    } else if (mode == 3) {
        func_0204500c(messages, (const char*)KeyTable_Get((Container020e0310*)(menu + 0x620), 1001), 0, 0xe3);
    } else if (mode == 2) {
        func_0204500c(messages, (const char*)KeyTable_Get((Container020e0310*)(menu + 0x620), 1002), 0, 0xe3);
    }
    messages->unknown_19b2_ = 0;
    messages->active = 1;
#endif
}
