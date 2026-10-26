#include <globaldefs.h>

void SoundPlayer_StopSeq(void* obj, void* target, int arg);

// USA: func_0205ebb4
ARM void ForwardToTargetOrDefault0205ebb4(void* obj, void* target, int arg) {
    SoundPlayer_StopSeq(obj, target, arg);
}
