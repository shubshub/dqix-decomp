#include <globaldefs.h>

struct Struct_ov023_021e257c_3;

struct Struct_ov023_021e2868 {
    char pad0[8];
    int f8;
    int fc;
    char pad10[4];
    unsigned short f14;
    unsigned short unknown_16_;
};

extern "C" ARM void* func_ov023_021e2450(void* obj, int val);
extern "C" ARM void* func_ov023_021e27f8(struct Struct_ov023_021e257c_3* obj, int key);
extern "C" void func_ov023_021e2acc(void* obj, int val, short* out1, short* out2);

// USA: func_ov023_021e2b5c
extern "C" ARM void func_ov023_021e2b5c(struct Struct_ov023_021e2868* obj, int key, short* out1, short* out2) {
    if (obj->f8 == 0 || obj->f14 == 0 || obj->fc == 0 || obj->unknown_16_ == 0) return;
    void* e = func_ov023_021e2450(obj, key);
    if (!e) return;
    *out1 = *(short*)((char*)e + 4);
    *out2 = *(short*)((char*)e + 6);
    void* e2 = func_ov023_021e27f8((struct Struct_ov023_021e257c_3*)obj, key);
    if (!e2) return;
    short v = *(short*)e2;
    func_ov023_021e2acc(obj, v, out1, out2);
}
