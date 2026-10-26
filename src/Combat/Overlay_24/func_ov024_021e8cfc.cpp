#include <globaldefs.h>

extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void func_ov000_0215a88c(void* objRaw, void* arg1, int c);
extern "C" void func_ov000_0215ffc4(void* obj, void* node, int idx);
extern "C" void func_ov000_02159eac(void* a0, void* buf, int a2);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, unsigned long long arg4, int g);

struct Struct_ov024_021ddc80_5 { char unknown_0_[0xc]; void* unknown_c_; void* unknown_10_; };

// USA: func_ov024_021e8cfc
extern "C" ARM void* func_ov024_021e8cfc(struct Struct_ov024_021ddc80_5* obj, void* c, int kind, int arg3) {
    void* entry = func_ov000_0215e958(obj->unknown_10_);
    if (!entry) return 0;
    if (arg3) {
        func_ov000_0215a88c(obj->unknown_10_, entry, 0xf1);
    }
    func_ov000_0215a88c(obj->unknown_10_, entry, 0x25c);
    func_ov000_0215ffc4(obj->unknown_c_, entry, 1);
    ((unsigned char*)obj->unknown_10_)[0x8e02] = ((unsigned char*)obj->unknown_10_)[0x8e02] + 1;
    union { struct { int lo; int hi; }; unsigned long long v; } local;
    local.lo = 0;
    local.hi = 0;
    func_ov000_02159eac(obj->unknown_10_, &local, (unsigned char)kind);
    func_ov000_0215cd44(obj->unknown_10_, entry, c, 0, local.v, 0);
    return entry;
}
