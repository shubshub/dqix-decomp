#include <globaldefs.h>
#include "World/Object3D.h"

struct Struct_020794f8 {
    Object3D obj3D_;
    char unknown_ac_[0xae - 0xac];
    short unknown_ae_;
};

extern "C" void func_ov017_021c95ec(int id, int arg1, int unused, int kind, int arg4,
                                    Vector3fix v, int field8, int arg7, int flag7);

// USA: func_020794f8
extern "C" ARM void func_020794f8(struct Struct_020794f8* self, int arg1, int flag7) {
    int id = self->obj3D_.GetField06();
    int rem = self->obj3D_.actorIndex_ - 0x70;
    int v2 = self->obj3D_.unknown_2_;
    Vector3fix v = self->obj3D_.position_;
    short field8 = self->unknown_ae_;
    rem %= 12;
    if (rem < 0 || rem >= 12) {
        return;
    }
    func_ov017_021c95ec(id, rem, v2, 1, -1, v, field8, arg1, flag7);
}
