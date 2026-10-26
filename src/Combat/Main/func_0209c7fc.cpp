#include <globaldefs.h>

extern "C" void SoundPlayer_StopSeqOnHandle(void*, void*, int);

// USA: func_0209c7fc
extern "C" ARM void func_0209c7fc(void* obj) {
    if (*(short*)((char*)obj + 0xce) < 0) return;
    SoundPlayer_StopSeqOnHandle(obj, (char*)obj + 0xc4, 0);
    *(short*)((char*)obj + 0xce) = -1;
    *(short*)((char*)obj + 0xca) = 0;
}
