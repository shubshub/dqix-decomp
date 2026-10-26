#include <globaldefs.h>
#include "std_library_functions.h"

unsigned long long GetCurrentTimestamp(void);
extern "C" unsigned long long _ll_udiv(unsigned long long arg0, unsigned int arg1, unsigned int flag);
extern "C" int _s32_div_f(int, int);
extern "C" int abs(int x);

struct Struct_ov023_021db110 {
    short timer;
    short duration;
    short unknown_4_;
    short unknown_6_;
};

struct Struct_ov023_021db110_2 {
    struct Struct_ov023_021db110 unknown_0_[3];
    unsigned long long unknown_18_;
    short unknown_20_;
    short unknown_22_;
    unsigned char active;
};

// USA: func_ov023_021db110
extern "C" ARM void func_ov023_021db110(struct Struct_ov023_021db110_2* obj) {
    if (obj->active == 0) return;

    unsigned long long var0 = _ll_udiv(GetCurrentTimestamp() << 6, 0x82ea, 0);
    if (var0 - obj->unknown_18_ > 30) {
        obj->unknown_18_ = var0;
    } else {
        return;
    }

    int i;
    for (i = 0; i < 3; i++) {
        obj->unknown_0_[i].timer--;
        if (obj->unknown_0_[i].timer <= 0) obj->unknown_0_[i].timer = 0;
    }

    obj->unknown_22_--;
    if (obj->unknown_22_ <= 0) {
        obj->unknown_22_ = 0;
        for (int j = 0; j < 3; j++) {
            struct Struct_ov023_021db110* p = &obj->unknown_0_[j];
            if (p->timer > 0) continue;
            if (rand() % 5 != 0) continue;

            p->timer = p->duration;
            p->unknown_4_ = (short)(rand() % 50);
            p->unknown_6_ = (short)(rand() % 15);

            for (int k = 0; k < 3; k++) {
                if (j == k) continue;
                if (obj->unknown_0_[k].timer <= 0) continue;
                if (abs(p->unknown_4_ - obj->unknown_0_[k].unknown_4_) > 12) continue;
                if (abs(p->unknown_6_ - obj->unknown_0_[k].unknown_6_) <= 12) {
                    p->timer = 0;
                    break;
                }
            }
            obj->unknown_22_ = 2;
            break;
        }
    }

    obj->unknown_20_++;
    if (obj->unknown_20_ >= 0x28) obj->unknown_20_ = 0;
}
