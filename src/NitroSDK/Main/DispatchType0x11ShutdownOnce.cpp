#include <globaldefs.h>


extern "C" void HaltSystem(void);
void SpinDrainAfterWait_020d192c(void);

struct ShutdownGuard020d18d0 {
    int _pad0[3];
    int done;
    int _pad1[2];
    int (*callback)(void);
};
extern "C" ShutdownGuard020d18d0 _ZZ20GetInitFlags020d16b0vE1s;

// USA: func_020d18d0
ARM void DispatchType0x11ShutdownOnce_020d18d0(int context, int code) {
    if ((code & 0x3f) == 0x11) {
        if (_ZZ20GetInitFlags020d16b0vE1s.done != 0) return;
        {
            int (*cb)(void) = _ZZ20GetInitFlags020d16b0vE1s.callback;
            int r = 0;
            if (cb != 0) r = cb();
            if (r != 0) SpinDrainAfterWait_020d192c();
        }
        _ZZ20GetInitFlags020d16b0vE1s.done = 1;
        return;
    }
    HaltSystem();
}
