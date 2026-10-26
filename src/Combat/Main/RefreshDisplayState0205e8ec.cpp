#include <globaldefs.h>

void SoundPlayer_RestoreHeapState(void* obj, int arg2);
extern "C" void func_0205e944(void*, int);
extern "C" void func_020bbd9c(void);

struct Obj_0205e8ec {
    char pad0[0xb8];
    int fb8;
    short fbc;
    char pad1[0xc0 - 0xbe];
    int fc0;
    short fc4;
};

// USA: func_0205e8ec
ARM void RefreshDisplayState0205e8ec(struct Obj_0205e8ec* a) {
    if (a->fb8 != 0) {
        SoundPlayer_RestoreHeapState(a, a->fb8);
        a->fc0 = a->fb8;
        a->fbc = -1;
        a->fc4 = -1;
    }
    func_0205e944(a, 0x7f);
    func_020bbd9c();
}
