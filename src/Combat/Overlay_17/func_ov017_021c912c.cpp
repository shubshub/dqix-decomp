#include <globaldefs.h>

extern int data_ov017_021d8498;
extern "C" void func_ov017_021d451c(void* a, void* b);
extern "C" void func_ov017_021d45e0(void* a, void* b);

struct Struct_ov017_021c912c { unsigned char unknown_0_0_ : 2; unsigned char rest : 6; };
struct Struct_ov017_021c912c_2 { unsigned char pad[4]; Struct_ov017_021c912c field4; };

// USA: func_ov017_021c912c
extern "C" ARM void func_ov017_021c912c(void* unused, Struct_ov017_021c912c_2* obj) {
    void* base = &data_ov017_021d8498;
    unsigned int sub = obj->field4.unknown_0_0_;
    if (sub == 0) {
        func_ov017_021d451c(base, (char*)obj + 6);
        return;
    }
    if (sub != 1) return;
    func_ov017_021d45e0(base, (char*)obj + 6);
}
