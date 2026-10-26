#include <globaldefs.h>

struct Struct_ov024_021fd858_2 {
    char pad0[0x18];
    unsigned int kind : 5;
    unsigned int rest18 : 27;
};

class Struct_ov024_021fd858 {
public:
    char pad0[0x64c];
    Struct_ov024_021fd858_2* action;
    char unknown_650_[0x665 - 0x650];
    unsigned char unknown_665_;
};

typedef void (Struct_ov024_021fd858::*Type_ov024_021fb490)();

struct Struct_ov024_02200150 { char pad0[8]; unsigned int flags; };
extern Struct_ov024_02200150 data_ov024_02200150;
extern Type_ov024_021fb490 data_ov024_021ffcec[23];
extern const Type_ov024_021fb490 __ptmf_null;

// USA: func_ov024_021fd858
extern "C" ARM void func_ov024_021fd858(Struct_ov024_021fd858* obj) {
    Struct_ov024_021fd858_2* action = obj->action;
    obj->unknown_665_ |= 0x80;
    unsigned int var1 = data_ov024_02200150.flags;
    if (!(var1 & 1)) {
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
        data_ov024_02200150.flags = var1 | 1;
    }
    unsigned int kind = action->kind;
    if (kind < 23 && data_ov024_021ffcec[kind] != 0) {
        (obj->*data_ov024_021ffcec[kind])();
    }
}
