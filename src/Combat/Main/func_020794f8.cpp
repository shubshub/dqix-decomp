#include <globaldefs.h>
#include "World/Object3D.h"

struct Struct_020794f8 {
    Object3D unknown_0_;
    char unknown_ac_[0xae - 0xac];
    short unknown_ae_;
};

extern "C" void func_ov017_021c95ec(int arg0, int arg1, int arg2, int arg3, int arg4,
                                    Vector3fix arg5, int arg6, int arg7, int arg8);

// USA: func_020794f8
extern "C" ARM void func_020794f8(struct Obj020794f8* self, int flag6, int flag7) {
    int id = self->obj3D_.GetField06();
    int rem = self->obj3D_.actorIndex_ - 0x70;
    int v2 = self->obj3D_.unknown_2_;
    Vector3fix v = self->obj3D_.position_;
    short field8 = self->field_ae;
    rem %= 12;
    if (rem < 0 || rem >= 12) {
        return;
    }
    func_ov017_021c95ec(var0, var1, var2, 1, -1, var3, var4, arg1, arg2);
}
