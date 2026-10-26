#include <globaldefs.h>

extern "C" void* func_ov031_022133f8(int flags);
extern "C" void func_ov031_02213694(int);

struct Struct_ov031_02213c10 { short field0; short field2; int field4; int field8; };

// USA: func_ov031_02213c10
extern "C" ARM void func_ov031_02213c10(Struct_ov031_02213c10* obj) {
    void* handler = func_ov031_022133f8(0x10);
    if (obj->field0 == 5) {
        if (obj->field2 == 0) return;
        switch (obj->field8) {
        case 0xd: *((unsigned char*)handler + 0xd14) = 1; return;
        case 0xf: *((unsigned char*)handler + 0xd14) = 2; return;
        case 0x11: *((unsigned char*)handler + 0xd14) = 3; return;
        default: *((unsigned char*)handler + 0xd14) = 4; return;
        }
    }
    if (obj->field0 != 7) return;
    func_ov031_02213694(obj->field4);
}
