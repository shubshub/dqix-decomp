#include <globaldefs.h>
#include "Memory/SafeAllocator.h"


#if defined(jpn)
enum { Enum_ov003_0215c568_16384 = 0x3000 };
enum { Enum_ov003_0215c568_124 = 0x94 };
enum { kRegionValue5C_28 = 0x28 };
#else
enum { Enum_ov003_0215c568_16384 = 0x4000 };
enum { Enum_ov003_0215c568_124 = 0x7c };
enum { kRegionValue5C_28 = 0x5c };
#endif


extern "C" void HaltSystem(void);
extern "C" int MessageSystem_GetInstance(void);

// USA: func_ov003_0215c568
extern "C" ARM void func_ov003_0215c568(void* arg0, SafeAllocator* arg1) {
    if (arg1 == 0) return;

    void* arenaBuffer = arg1->Allocate(0x2000);
    if (arenaBuffer == 0) HaltSystem();
    ((SafeAllocator*)arg0)->CreateTypeA(arenaBuffer, 0x2000);

    arenaBuffer = arg1->Allocate(0x800);
    if (arenaBuffer == 0) HaltSystem();
    ((SafeAllocator*)((char*)arg0 + 0x14))->CreateTypeA(arenaBuffer, 0x800);

    arenaBuffer = arg1->Allocate(Enum_ov003_0215c568_16384);
    if (arenaBuffer == 0) HaltSystem();
    ((SafeAllocator*)((char*)arg0 + 0x28))->CreateTypeA(arenaBuffer, Enum_ov003_0215c568_16384);

    arenaBuffer = arg1->Allocate(0x400);
    if (arenaBuffer == 0) HaltSystem();
    ((SafeAllocator*)((char*)arg0 + 0x3c))->CreateTypeA(arenaBuffer, 0x400);

    arenaBuffer = arg1->Allocate(0x2000);
    if (arenaBuffer == 0) HaltSystem();
    ((SafeAllocator*)((char*)arg0 + 0x50))->CreateTypeA(arenaBuffer, 0x2000);

    int fieldSourceAddress = MessageSystem_GetInstance();
    *(int*)((char*)arg0 + Enum_ov003_0215c568_124) = *(int*)(fieldSourceAddress + kRegionValue5C_28);
}
