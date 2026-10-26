#include <globaldefs.h>


extern "C" void HaltSystem(void);
extern "C" void func_020d192c(void);

struct Struct_020d18d0 {
    int unknown_0_[3];
    int done;
    int unknown_10_[2];
    int (*callback)(void);
};
extern "C" Struct_020d18d0 _ZZ15inline_020d16b0vE1s;

// USA: func_020d18d0
extern "C" ARM void func_020d18d0(int context, int code) {
    if ((code & 0x3f) == 0x11) {
        if (_ZZ15inline_020d16b0vE1s.done != 0) return;
        {
            int (*cb)(void) = _ZZ15inline_020d16b0vE1s.callback;
            int r = 0;
            if (cb != 0) r = cb();
            if (r != 0) func_020d192c();
        }
        _ZZ15inline_020d16b0vE1s.done = 1;
        return;
    }
    HaltSystem();
}
