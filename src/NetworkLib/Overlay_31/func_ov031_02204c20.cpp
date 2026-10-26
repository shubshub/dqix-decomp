#include <globaldefs.h>

extern "C" void func_ov031_0220321c(void);
extern "C" void func_ov031_02203190(void);
extern "C" void func_ov031_02203250(void);
extern "C" void func_ov031_022031bc(int a, unsigned short b, unsigned int c);
extern "C" int func_ov031_022048a8(void* obj, int flag, void* arg2, int arg3, int arg4);

// USA: func_ov031_02204c20
extern "C" ARM int func_ov031_02204c20(void* obj, unsigned int session, void* arg2) {
    if (session == 0) return -1;
    func_ov031_0220321c();
    func_ov031_02203190();
    func_ov031_022031bc(0, 0x35, session);
    int result = func_ov031_022048a8(obj, 1, arg2, 0, 0);
    func_ov031_02203250();
    return result;
}
