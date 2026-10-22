#include <globaldefs.h>

struct Struct_ov024_021fd858_2 {
    char unknown_0_[0x18];
    unsigned int unknown_18_0_ : 5;
    unsigned int unknown_18_5_ : 27;
};

class Struct_ov024_021fd858 {
public:
    char unknown_0_[0x64c];
    Struct_ov024_021fd858_2* unknown_64c_;
    char unknown_650_[0x665 - 0x650];
    unsigned char unknown_665_;
};

typedef void (Struct_ov024_021fd858::*Type_ov024_021fb490)();

struct InitGuard_021fd858 { char pad0[8]; unsigned int flags; };
extern InitGuard_021fd858 data_ov024_02200150;
extern Handler_021fd858 data_ov024_021ffcec[23];
extern const Handler_021fd858 __ptmf_null;

// USA: func_ov024_021fd858
extern "C" ARM void func_ov024_021fd858(Obj_021fd858* obj) {
    Action_021fd858* action = obj->action;
    obj->flags665 |= 0x80;
    unsigned int guard = data_ov024_02200150.flags;
    if (!(guard & 1)) {
        data_ov024_021ffcec[0] = __ptmf_null;
        data_ov024_021ffcec[3] = __ptmf_null;
        data_ov024_021ffcec[12] = __ptmf_null;
        data_ov024_021ffcec[13] = __ptmf_null;
        data_ov024_021ffcec[14] = __ptmf_null;
        data_ov024_021ffcec[15] = __ptmf_null;
        data_ov024_021ffcec[16] = __ptmf_null;
        data_ov024_021ffcec[17] = __ptmf_null;
        data_ov024_021ffcec[18] = __ptmf_null;
        data_ov024_021ffcec[21] = __ptmf_null;
        data_ov024_021ffcec[22] = __ptmf_null;
        data_ov024_02200150.flags = guard | 1;
    }
    unsigned int var2 = var0->unknown_18_0_;
    if (var2 < 23 && data_ov024_021ffcec[var2] != 0) {
        (arg0->*data_ov024_021ffcec[var2])();
    }
}
