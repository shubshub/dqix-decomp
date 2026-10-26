#if defined(jpn)
enum { Enum_ov017_021b6f9c_17408 = 0x4100, Enum_ov017_021b6f9c_174 = 0xfe, RegionOffset6fc = 0x4ec, Enum_ov017_021b6f9c_2908 = 0x93c };
#else
enum { Enum_ov017_021b6f9c_17408 = 0x4400, Enum_ov017_021b6f9c_174 = 0xae, RegionOffset6fc = 0x6fc, Enum_ov017_021b6f9c_2908 = 0xb5c };
#endif

#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

extern "C" void func_ov000_021604f0(void);
extern "C" void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
extern "C" void func_020a1e54(int flag);
extern "C" void func_020a1f4c(int flag);
extern "C" void GameObject_EnableControl(void* obj);
struct Struct_02053f7c_3;
extern "C" void func_02053f7c(Struct_02053f7c_3* obj, unsigned short a, int b);
extern "C" ARM void func_ov017_021c3f70(unsigned short tag);
extern "C" void ROMFilesystem_InitFileTables(void);
struct ListHead02046b60;
extern "C" int func_02046b60(ListHead02046b60* list, int id);
extern "C" void* Zone3D_GetInstance(void);
extern "C" void func_02017d68(void* obj);
extern "C" void* GlobalFlags_GetInstance(void);
struct FlagWord020466f4;
extern "C" void FlagWord_ClearBits(FlagWord020466f4* word, unsigned int mask);
struct Struct_020a3578;
extern "C" void func_020a3578(Struct_020a3578* s);

extern AllocatorUnion g_mainAllocator;

// USA: func_ov017_021b6f9c
extern "C" ARM void func_ov017_021b6f9c(char* self) {
    char* ov = (char*)GetGameResources();
    unsigned short var1 = *(unsigned short*)(self + 0x600 + 0xb6);
    int f28 = *(int*)(self + 0x28);
    unsigned int var3 = var1 & 0x2000;

    unsigned short var4 = *(unsigned short*)(ov + Enum_ov017_021b6f9c_17408 + Enum_ov017_021b6f9c_174);
    unsigned short* var5 = (unsigned short*)(ov + Enum_ov017_021b6f9c_174 + Enum_ov017_021b6f9c_17408);
    if (var4 == *(unsigned short*)(self + 0x24)) {
        var5[0] = 0;
        var5[1] = 0;
    }

    if (*(int*)(self + 0x6ac) != 0) {
        func_ov000_021604f0();
    }

    SafeAllocator* alloc = (SafeAllocator*)(self + 0x8);
    void* p = alloc->GetSignedAllocator();
    if (p) {
        alloc->Destroy();
        AllocatorUnion_Free(&g_mainAllocator, p);
    }

    if (*(unsigned short*)(self + 0x600 + 0xb6) & 0x800) {
        func_020a1e54(1);
        func_020a1f4c(1);
    }

    GameObject* combatant = GameState::GetInstance()->GetLeader();
    GameObject_EnableControl(combatant);
    func_02053f7c((Struct_02053f7c_3*)combatant, 0, 0);
    func_ov017_021c3f70(0);

    alloc->ResetAllocatorPointer();
    func_020a3578((Struct_020a3578*)(self + 0x1c));

    *(int*)(self + 0x6ac) = 0;
    *(int*)(self + 0x6b0) = 0;
    *(unsigned short*)(self + 0x600 + 0xb4) = 1;
    *(unsigned short*)(self + 0x600 + 0xb6) = 0;
    *(int*)(self + 0x6b8) = 0;

    ClearFlags00((GameResources*)ov, 0x800);
    ROMFilesystem_InitFileTables();

    int* var9 = *(int**)(ov + 0x3000 + RegionOffset6fc);
    char* var10 = *(char**)(ov + 0x3000 + Enum_ov017_021b6f9c_2908);
    int var11;
    if (f28 < 0 || func_02046b60((ListHead02046b60*)var9, 4) == 0) {
        var11 = 1;
    } else {
        var11 = 0;
    }

    void* ret = Zone3D_GetInstance();
    if (var11 != 0 && var3 == 0 && *(unsigned char*)(var10 + 8) != 0) {
        func_02017d68(ret);
    }

    FlagWord_ClearBits((FlagWord020466f4*)GlobalFlags_GetInstance(), 0x40000);
}
