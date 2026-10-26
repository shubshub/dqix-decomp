#include <globaldefs.h>

struct SearchStruct0202c1a4;
signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);
extern "C" void func_ov017_021cf730(int a, int b);

// USA: func_ov017_021cf704
ARM void DispatchIfNoCurrentArrEntry_021cf704(int a0, int unused1, int unused2, int unused3, struct SearchStruct0202c1a4* search) {
    signed char cur = LinkSession_GetOwnSlot(search);
    if (cur != 0) return;
    func_ov017_021cf730((signed char)a0, 0);
}
