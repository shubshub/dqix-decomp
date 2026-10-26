#include <globaldefs.h>

struct SearchStruct0202c1a4;
extern "C" signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);
extern "C" void func_ov017_021cf730(int a, int b);

// USA: func_ov017_021cf704
extern "C" ARM void func_ov017_021cf704(int a0, int unused1, int arg2, int arg3, struct SearchStruct0202c1a4* search) {
    signed char cur = LinkSession_GetOwnSlot(search);
    if (cur != 0) return;
    func_ov017_021cf730((signed char)a0, 0);
}
