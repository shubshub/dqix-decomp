#include <globaldefs.h>

extern "C" int func_020ac4c0(void* dst);
extern "C" void func_ov017_021d6134(void*, unsigned int);

struct Struct_ov023_021ea344 { unsigned int v : 24; };

// USA: func_ov023_021ea344
extern "C" ARM int func_ov023_021ea344(void* obj) {
    unsigned char buf[0xb0];
    func_020ac4c0(buf);
    struct Struct_ov023_021ea344* var1 = (struct Struct_ov023_021ea344*)(buf + 0x88);
    func_ov017_021d6134(obj, var1->v);
    return 1;
}
