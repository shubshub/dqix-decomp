#include <globaldefs.h>

void SoundPlayer_RestoreHeapState(void* obj, int arg2);
int SoundPlayer_SaveHeapState(void* obj);
int SoundPlayer_LoadGroup(void*, int);

struct Obj_0205ead0 {
    char pad0[0xb8];
    int fb8;
    short fbc;
    char pad1[0xc0 - 0xbe];
    int fc0;
};

// USA: func_0205ead0
ARM void UpdateDisplayTransform0205ead0(struct Obj_0205ead0* a, int b, int c) {
    SoundPlayer_RestoreHeapState(a, a->fb8);
    SoundPlayer_LoadGroup(a, b);
    a->fbc = c;
    a->fc0 = SoundPlayer_SaveHeapState(a);
}
