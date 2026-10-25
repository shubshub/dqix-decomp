#include <globaldefs.h>

extern "C" ARM void SearchPotTask_Release(void* obj);

// Overlay 17, originally TailCall_021b5a24 (USA/EUR 0x021b5a24, JPN 0x021b5fd8)
ARM void FieldTask_EndSearchPot(void* obj) {
    SearchPotTask_Release(obj);
}
