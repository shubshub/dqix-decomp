#include <globaldefs.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif
#if defined(jpn)
#define func_02052bfc func_02053fd8
#endif

int fix32abs(int x);
extern "C" void func_0205416c(void* obj);

extern "C" {
    void _ZN8Object3D14AdvanceEffectsEv(void* obj);
    void func_02053634(void* obj);
    void func_020489e8(void* obj);
    void func_02052bfc(void* obj);
}

struct Obj02052ae8 {
    char pad0[IS_JPN ? 0x170 : 0x17c];
    signed char unknown_17c_;
    char pad1[0x1b4 - 0x17d];
    int unknown_1b4_;
    int unknown_1b8_;
    int unknown_1bc_;
};

// USA: func_02052ae8
extern "C" ARM void func_02052ae8(struct Obj02052ae8* obj) {
    int cond = obj->unknown_17c_ > 0;
    if (cond) {
        _ZN8Object3D14AdvanceEffectsEv(obj);
        func_02053634(obj);
    } else {
        func_020489e8(obj);
        func_02052bfc(obj);
    }

    if (obj->unknown_1b4_ > 0 || obj->unknown_1b8_ > 0) {
        int step = fix32abs((int)((float)(obj->unknown_1b4_ - obj->unknown_1b8_) * 0.1f));
        if (step == 0) {
            obj->unknown_1b8_ = obj->unknown_1b4_;
        }
        if (step < obj->unknown_1bc_) {
            obj->unknown_1bc_ = step;
        } else if (obj->unknown_1bc_ < step) {
            obj->unknown_1bc_ += 0x14;
            if (step < obj->unknown_1bc_) {
                obj->unknown_1bc_ = step;
            }
            if (obj->unknown_1bc_ > 0x199) {
                obj->unknown_1bc_ = 0x199;
            }
            step = obj->unknown_1bc_;
        }

        if (obj->unknown_1b4_ < obj->unknown_1b8_) {
            obj->unknown_1b8_ = obj->unknown_1b8_ - step;
            if (obj->unknown_1b8_ < obj->unknown_1b4_) {
                obj->unknown_1b8_ = obj->unknown_1b4_;
            }
        } else if (obj->unknown_1b8_ < obj->unknown_1b4_) {
            obj->unknown_1b8_ = obj->unknown_1b8_ + step;
            if (obj->unknown_1b4_ < obj->unknown_1b8_) {
                obj->unknown_1b8_ = obj->unknown_1b4_;
            }
        }
    }

    func_0205416c(obj);
}
