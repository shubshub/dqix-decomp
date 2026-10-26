#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void*);
extern "C" void* func_ov001_0215905c(int type, int val);

struct Struct_ov001_02165880_28 { char pad[0x24]; int field24; };
extern Struct_ov001_02165880_28 data_ov001_02165880;

// USA: func_ov001_0215d784
extern "C" ARM int func_ov001_0215d784(void* self) {
    int val = func_ov017_021d60f4(self);
    func_ov001_0215905c(data_ov001_02165880.field24, val);
    return 1;
}
