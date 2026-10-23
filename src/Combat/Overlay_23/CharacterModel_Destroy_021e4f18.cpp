#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"

extern "C" void func_ov023_021e61a0(void* obj);

// Overlay 23, originally DestroyTenAndOne_021e4f18 (USA/EUR 0x021e4f18, JPN 0x021e50fc)
ARM void CharacterModel_Destroy(void* obj) {
    func_ov023_021e61a0(obj);
    for (int i = 0; i < 10; i++) {
        ((Object3D*)((char*)obj + i * 0xac))->Initialize();
        ((SafeAllocator*)((char*)obj + 0x6b8 + i * 0x14))->Destroy();
    }
    ((SafeAllocator*)((char*)obj + 0x780))->Destroy();
}
