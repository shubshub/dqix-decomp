#include <globaldefs.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif


struct Struct_020657c8 {
    unsigned char pad0[IS_JPN ? 0x789 : 0x95b];
    unsigned char unknown_95b_;
};

struct Struct_020657c8_2 {
    unsigned char pad0[IS_JPN ? 0x870 : 0x9a0];
    int unknown_9a0_;
    int unknown_9a4_;
    int unknown_9a8_;
    int unknown_9ac_;
    int unknown_9b0_;
    unsigned char pad1[0x1000 - (IS_JPN ? 0x884 : 0x9b4)];
    struct Struct_020657c8 sub;
};

// USA: func_020657c8
extern "C" ARM int func_020657c8(struct Struct_020657c8_2* obj, int step) {
    unsigned char flags = obj->sub.unknown_95b_;
    int ret = 0;
    if (flags & 4) {
        if (obj->unknown_9a0_ == 0) {
            if (flags & 8) {
                obj->unknown_9b0_ = obj->unknown_9b0_ + (IS_JPN ? 1 : step) * 0x8444;
                if (obj->unknown_9b0_ >= 0x1f0000) {
                    obj->unknown_9b0_ = 0x1f0000;
                    obj->unknown_9ac_ = 0;
                    obj->sub.unknown_95b_ &= ~8;
                    obj->sub.unknown_95b_ |= 0x10;
                }
            } else if (flags & 0x10) {
                obj->unknown_9ac_ = obj->unknown_9ac_ + step;
                if (obj->unknown_9a8_ <= obj->unknown_9ac_) {
                    obj->unknown_9ac_ = obj->unknown_9a8_;
                    obj->sub.unknown_95b_ &= ~0x10;
                    obj->sub.unknown_95b_ |= 0x20;
                }
            } else if (flags & 0x20) {
                #if defined(jpn)
                step = obj->unknown_9b0_ - 0x44;
                step -= 0x8400;
                obj->unknown_9b0_ = step;
#else
                obj->unknown_9b0_ = obj->unknown_9b0_ - step * 0x8444;
#endif
                if (obj->unknown_9b0_ <= 0) {
                    obj->unknown_9b0_ = 0;
                    obj->sub.unknown_95b_ = obj->sub.unknown_95b_ & ~0x20;
                }
            }
            ret = 1;
        }
    }
    return ret;
}