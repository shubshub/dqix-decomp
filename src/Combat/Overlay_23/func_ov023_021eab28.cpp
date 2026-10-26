#include <globaldefs.h>

extern "C" int func_020ac4c0(void* dst);
extern "C" void func_ov017_021d6134(void*, int);

struct Struct_ov023_021eab28 { unsigned short v0; unsigned char v2; };

// USA: func_ov023_021eab28
extern "C" ARM int func_ov023_021eab28(void* obj) {
    char buf[0xb0];
    func_020ac4c0(buf);
    struct Struct_ov023_021eab28* p = (struct Struct_ov023_021eab28*)(buf + 0x90);
    func_ov017_021d6134(obj, p->v0);
    func_ov017_021d6134((char*)obj + 0x8, p->v2);
    return 1;
}
