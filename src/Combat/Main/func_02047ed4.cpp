#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include "Graphics/VRAMStaging.h"

extern "C" int NNS_GfdAllocFrmTexVram(unsigned int size, int a, int b);

struct Struct_02047b40_4 {
    unsigned char pad[0x84];
    unsigned char bit0 : 1;
    unsigned char unknown_84_1_ : 1;
    unsigned char bit2 : 1;
    unsigned char unknown_84_3_ : 1;
    unsigned char unknown_84_4_ : 1;
    unsigned char unknown_84_5_ : 1;
    unsigned char unknown_84_6_ : 1;
    unsigned char unknown_84_7_ : 1;
};

// USA: func_02047ed4
extern "C" ARM void func_02047ed4(struct Struct_02047b40_4* obj, int* outSize, void* buf, unsigned int size, SafeAllocator* allocator) {
    int bits = NNS_GfdAllocFrmTexVram(size, 0, 0);
    unsigned int computedSize = ((unsigned int)bits << 16) >> 13;
    bool var2 = true;
    if (obj->bit2 && allocator != NULL) {
        void* var3 = allocator->Allocate(size);
        if (var3 != NULL) {
            memcpy(var3, buf, size);
            buf = var3;
            var2 = false;
        }
    }
    StageMemoryToVRAM(VRAMSubregion_TextureImage, buf, computedSize, size, false, var2);
    *outSize = (int)computedSize;
}
