#include <globaldefs.h>


extern "C" void SePlayer_PlayArchiveEntry(void* obj, int x, int y, int z);

// USA: func_0203aa08
ARM void ResetXYField0203aa08(void* obj) {
    short x;
    if (*(void**)obj == NULL) return;
    x = *(short*)((char*)obj + 0xac);
    if (x < 0) return;
    SePlayer_PlayArchiveEntry(obj, x, *(short*)((char*)obj + 0xae), 0);
    *(short*)((char*)obj + 0xac) = -1;
    *(short*)((char*)obj + 0xae) = -1;
}
