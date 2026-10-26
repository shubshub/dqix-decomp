#include <globaldefs.h>

extern "C" void SoundPlayer_StopSeq(void* obj, void* target, int arg);

// USA: func_0205eabc
extern "C" ARM void func_0205eabc(void* obj, void* target, int arg) {
    SoundPlayer_StopSeq(obj, target, arg);
}
