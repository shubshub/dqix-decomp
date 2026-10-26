#include <globaldefs.h>

extern "C" void* NNS_SndArcSetCurrent(void*);
extern "C" int NNS_SndArcLoadSeqEx(void*, int, int);

// USA: func_0203ab6c
extern "C" ARM int func_0203ab6c(void* obj, void* arg1) {
    char* p = (char*)obj;
    if (*(void**)p == NULL) return 0;
    NNS_SndArcSetCurrent(p + 0x4);
    NNS_SndArcLoadSeqEx(arg1, 6, *(int*)p);
    return 1;
}
