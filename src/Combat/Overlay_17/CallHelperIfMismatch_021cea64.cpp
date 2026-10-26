#include <globaldefs.h>

struct SearchStruct0202c1a4;
signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);

struct SearchStruct;
void LinkSession_MarkSlotLost(struct SearchStruct* obj, int value);

// USA: func_ov017_021cea64
ARM void CallHelperIfMismatch_021cea64(int unused0, int* p, int unused2, int unused3, struct SearchStruct0202c1a4* extra) {
    int field = p[1];
    int val = LinkSession_GetOwnSlot(extra);
    if (field == val) return;
    LinkSession_MarkSlotLost((struct SearchStruct*)extra, field);
}
