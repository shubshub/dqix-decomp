#include <globaldefs.h>
extern "C" void WindowFrame_LoadPieces(char*, void*, void*);

// USA: func_020440b8
extern "C" ARM void func_020440b8(char* base, void* arg, void* data) {
#if defined(jpn)
    WindowFrame_LoadPieces((char*)(base + 0x1804), (void*)(arg), data);
#else
    WindowFrame_LoadPieces((char*)(base + 0x19e0), (void*)(arg), data);
#endif
}
