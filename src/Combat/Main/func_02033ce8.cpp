#include <globaldefs.h>
#include "World/Object3D.h"

struct Struct_02033b68 {
    char unknown_0_[4];
    short unknown_4_;
    char unknown_6_[0xbe - 6];
    unsigned char unknown_be_;
    unsigned char unknown_bf_;
    unsigned char unknown_c0_;
    unsigned char unknown_c1_0_ : 4;
    unsigned char unknown_c1_4_ : 4;
    unsigned char unknown_c2_0_ : 4;
    unsigned char unknown_c2_4_ : 1;
    unsigned char unknown_c2_5_ : 3;
    char unknown_c3_[0xe0 - 0xc3];
    unsigned char unknown_e0_;
};

extern "C" void func_02057924(void);
void ApplyStateTableValue02033dd4(unsigned char* obj);
void GameObject_SetMotionState(struct Obj02033b68* obj, int newVal);

// USA: func_02033ce8
extern "C" ARM void func_02033ce8(struct Struct_02033b68* arg0) {
    int var0;
    func_02057924();
    func_02033dd4((unsigned char*)arg0);

    if (p->fbe == 3 || p->fbe == 4) {
        if (p->fc0 == 7 || p->fc0 == 8) {
            if (p->fc0 != 7) return;
            if (p->fc1h == 0) return;
            GameObject_SetMotionState(p, 0);
        }
        return;
    }

    if (arg0->unknown_be_ == 6) {
        if (arg0->unknown_bf_ != 6) {
            var0 = (arg0->unknown_4_ >= 0 && arg0->unknown_4_ <= 3);
            if (!var0) {
                if (arg0->unknown_c2_4_ == 0) {
                    arg0->unknown_e0_ |= 8;
                }
            }
        }
        if (((Object3D*)arg0)->GetInheritedAlpha() > 0) return;
        ((Object3D*)arg0)->MakeHidden();
        return;
    }

    if (arg0->unknown_be_ == 5) {
        ((Object3D*)arg0)->SetInheritedAlpha(1);
        ((Object3D*)arg0)->TransitionInheritedAlpha(0x1f, 0xfa);
    }
}
