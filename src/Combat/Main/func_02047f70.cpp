#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include "Graphics/VRAMStaging.h"

extern "C" int NNS_GfdAllocFrmPlttVram(unsigned int size, int a, int b);

struct Struct_02047f70 {
    char pad0[0x10];
    int field10;
    char unknown_14_[0x84 - 0x14];
    unsigned char bit0 : 1;
    unsigned char unknown_84_1_ : 1;
    unsigned char bit2 : 1;
    unsigned char unknown_84_3_ : 1;
    unsigned char unknown_84_4_ : 1;
    unsigned char unknown_84_5_ : 1;
    unsigned char unknown_84_6_ : 1;
    unsigned char unknown_84_7_ : 1;
};

// USA: func_02047f70
extern "C" ARM void func_02047f70(struct Struct_02047f70* obj, void* buf, unsigned int size, SafeAllocator* allocator) {
    unsigned int computedSize = ((unsigned int)NNS_GfdAllocFrmPlttVram(size, 0, 0) << 16) >> 13;
    bool var1 = true;
    if (obj->bit2 && allocator != NULL) {
        void* var2 = allocator->Allocate(size);
        if (var2 != NULL) {
            memcpy(var2, buf, size);
            buf = var2;
            var1 = false;
        }
    }
    StageMemoryToVRAM(VRAMSubregion_TexturePalette, buf, computedSize, size, false, var1);
    obj->field10 = (int)computedSize;
}
