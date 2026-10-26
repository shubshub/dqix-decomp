#include <globaldefs.h>

extern "C" void func_ov031_022393e4(int v);
extern "C" ARM void func_ov031_02239368(int val);
extern "C" ARM void func_ov031_02239518(void* info);
extern "C" int func_020d68dc(int cb, unsigned int v, void* ctx);

struct Struct_ov031_022394b4 {
    unsigned char pad[0x13ac];
    int (*unknown_13ac_)(void*, void*);
    unsigned char pad2[0x10];
    void* arg;
};
struct Struct_ov031_02290d18_8 { void* unk0; Struct_ov031_022394b4* field4; };
extern struct Struct_ov031_02290d18_8 data_ov031_02290d18;

// USA: func_ov031_022394b4
extern "C" ARM int func_ov031_022394b4(void) {
    func_ov031_02239368(3);
    Struct_ov031_022394b4* c = data_ov031_02290d18.field4;
    unsigned int r = c->unknown_13ac_((void*)((char*)c + 0x13c0), c);
    int res = func_020d68dc((int)func_ov031_02239518, r,
                                          (void*)((char*)data_ov031_02290d18.field4 + 0x13c0));
    if (res == 2) {
        return 1;
    }
    func_ov031_022393e4(res);
    func_ov031_02239368(9);
    return 0;
}
