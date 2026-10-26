#include <globaldefs.h>

struct SearchStruct;
extern "C" struct SearchStruct* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsGuest(struct SearchStruct* obj);
extern "C" int LinkSession_IsSlotLost(struct SearchStruct* obj, int value);

// USA: func_ov017_021959b4
extern "C" ARM int func_ov017_021959b4(void) {
    struct SearchStruct* search = LinkSession_GetInstance();
    if (LinkSession_IsGuest(search)) {
        if (LinkSession_IsSlotLost(search, 0) != 0) return 1;
    }
    return 0;
}
