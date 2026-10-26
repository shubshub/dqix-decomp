#include <globaldefs.h>

extern "C" void func_ov031_02239368(int val);
extern "C" ARM void func_ov031_022393e4(int v);

struct Struct_ov031_02239b10 { unsigned char pad[2]; unsigned short field2; };

// USA: func_ov031_02239b10
extern "C" ARM void func_ov031_02239b10(Struct_ov031_02239b10* obj) {
    unsigned short v = obj->field2;
    if (v != 0) {
        func_ov031_022393e4(v);
        return;
    }
    func_ov031_02239368(1);
}
