#include <globaldefs.h>

void SoundPlayer_StopSeq(void* obj, void* target, int arg);

// USA: func_0205eb48
ARM void ForwardToTargetOrDefault0205eb48(void* obj, void* target, int arg) {
    SoundPlayer_StopSeq(obj, target, arg);
}
