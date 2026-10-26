#include <globaldefs.h>

void SoundPlayer_StopSeq(void* obj, void* target, int arg);

// USA: func_0205eabc
ARM void ForwardToTargetOrDefault0205eabc(void* obj, void* target, int arg) {
    SoundPlayer_StopSeq(obj, target, arg);
}
