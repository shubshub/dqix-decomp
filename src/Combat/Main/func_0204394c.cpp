#include <globaldefs.h>
#include "std_library_functions.h"
#include "Graphics/VRAMStaging.h"

struct Struct_0204394c {
    unsigned char pad[0x50];
    unsigned int unknown_50_0_ : 16;
    unsigned int unknown_52_0_ : 16;
};

#if defined(jpn)
#define func_0204394c func_02044104
extern "C" ARM void func_02044104(struct Struct_0204394c* obj);
enum { Enum_0204394c_0 = 0x700 };
#else
enum { Enum_0204394c_0 = 0 };
#endif

// USA: func_0204394c
extern "C" ARM void func_0204394c(struct Struct_0204394c* obj) {
    void* buf = AllocateVRAMStagingMemory(0x3000);
    if (buf == NULL) {
        return;
    }

    int var1 = obj->unknown_50_0_ * 8;
    memset(buf, 0, 0x3000);
    StageMemoryToVRAM(VRAMSubregion_TextureImage, buf, var1 + Enum_0204394c_0, 0x3000, true, false);
    FreeVRAMStagingMemory(buf);
}
