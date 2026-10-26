#include <globaldefs.h>

struct SearchStruct0202c1a4;
extern "C" signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);

struct SearchStruct;
extern "C" void LinkSession_MarkSlotLost(struct SearchStruct* obj, int value);

// USA: func_ov017_021cea64
extern "C" ARM void func_ov017_021cea64(int unused0, int* p, int arg2, int arg3, struct SearchStruct0202c1a4* extra) {
    int field = p[1];
    int val = LinkSession_GetOwnSlot(extra);
    if (field == val) return;
    LinkSession_MarkSlotLost((struct SearchStruct*)extra, field);
}
