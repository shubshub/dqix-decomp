#include <globaldefs.h>

struct Struct_ov017_021d82fc_6 {
    unsigned char pad[0xd];
    unsigned char flags;
};

extern "C" void func_020da8e0(Struct_ov017_021d82fc_6*);
extern "C" void func_020da31c(Struct_ov017_021d82fc_6*);

// USA: func_020da2fc
extern "C" ARM void func_020da2fc(Struct_ov017_021d82fc_6* e) {
    if (e->flags & 1) {
        func_020da8e0(e);
        return;
    }
    func_020da31c(e);
}
