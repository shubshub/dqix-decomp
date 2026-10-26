#include <globaldefs.h>
#include "Resource/GameResources.h"

struct Struct_020542b4;
struct ResourcePairTableStorage {
    unsigned char data[0x70];
};

extern "C" void func_020542b4(Struct_020542b4* entry, SafeAllocator* allocator, char* pairTables);

// USA: func_ov017_021a1178
extern "C" ARM void func_ov017_021a1178(GameResources* arg0, int slot) {
    GameResources* resources = arg0;
    GameResources::Substruct_12C8* entry = &resources->substruct_array_12c8[slot];
    int var2 = slot + 1;
    SafeAllocator* allocator = &resources->allocator_array_38[var2];
    ResourcePairTableStorage* pairTables = (ResourcePairTableStorage*)resources->vramStates_;
    func_020542b4((Struct_020542b4*)entry, allocator, (char*)&pairTables[var2]);
}
