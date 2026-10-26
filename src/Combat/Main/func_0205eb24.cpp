#include <globaldefs.h>

extern "C" void SoundPlayer_PlayArchiveEntry(void*, int, int, int);

// USA: func_0205eb24
extern "C" ARM void func_0205eb24(void* obj, int a, int b) {
    short s = *(short*)((char*)obj + 0xbc);
    if (s >= 0) {
        SoundPlayer_PlayArchiveEntry(obj, s, a, b);
    }
}
