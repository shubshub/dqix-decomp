#include <globaldefs.h>

extern "C" void SoundPlayer_StopSeq(void* obj, void* target, int arg);

// USA: func_0205eb48
extern "C" ARM void func_0205eb48(void* obj, void* target, int arg) {
    SoundPlayer_StopSeq(obj, target, arg);
}
