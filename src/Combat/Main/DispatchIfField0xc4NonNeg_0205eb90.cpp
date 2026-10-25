#include <globaldefs.h>

extern "C" void SePlayer_PlayArchiveEntry(void*, int, int, int);

// USA: func_0205eb90
ARM void DispatchIfField0xc4NonNeg_0205eb90(void* obj, int a, int b) {
    short s = *(short*)((char*)obj + 0xc4);
    if (s >= 0) {
        SePlayer_PlayArchiveEntry(obj, s, a, b);
    }
}
