#include <globaldefs.h>

extern "C" int func_ov031_02207180(void* v);
extern "C" ARM int func_ov031_02205814(void* obj);

struct Struct_ov031_022056bc {
    char pad0[0x70];
    short unknown_70_;
    char unknown_72_;
    signed char unknown_73_;
    short unknown_74_;
};

// USA: func_ov031_022056bc
extern "C" ARM int func_ov031_022056bc(Struct_ov031_022056bc* obj, int val) {
    if (func_ov031_02207180(obj)) {
        return ~0x1b;
    }
    int flag = 0;
    if (obj == NULL) goto checkFlag;
    if (!(obj->unknown_70_ & 1)) goto checkFlag;
    flag = 1;
checkFlag:
    if (!flag) {
        return ~0x26;
    }
    if (obj->unknown_70_ & 2) {
        return ~6;
    }
    obj->unknown_74_ = (short)val;
    if (obj->unknown_73_ != 1) {
        return 0;
    }
    return func_ov031_02205814(obj);
}
