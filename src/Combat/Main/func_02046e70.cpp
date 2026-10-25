#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "World/Object3D.h"

extern "C" void NSBXX_Model_SetPolygonID(void* obj, unsigned int value);

struct Struct_02040774_2;
extern "C" void func_020407b4(struct Struct_02040774_2* arg0, int arg1, int arg2, int arg3);

void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern AllocatorUnion g_mainAllocator;

// USA: func_02046e70
extern "C" ARM void func_02046e70(void* arg0, void* arg1, Object3D* arg2) {
    *(int*)((char*)arg0 + 0x4) = *(int*)((char*)arg0 + 0x0) = 0;
    *(int*)((char*)arg0 + 0x20) = 0;
    *(int*)((char*)arg0 + 0x8) = 0;
    *(int*)((char*)arg0 + 0xc) = 0x41700000;
    *(int*)((char*)arg0 + 0xec) = -1;
    *(unsigned char*)((char*)arg0 + 0x1c) = 1;
    *(unsigned char*)((char*)arg0 + 0x1d) = 1;

    GameState::GetInstance();
    ((Object3D*)((char*)arg0 + 0x3c))->Initialize();
    ((SafeAllocator*)((char*)arg0 + 0x24))->ResetAllocatorPointer();

    *(Object3D**)((char*)self + 0xe8) = a2;
    if (a2 != NULL) {
        NSBXX_Model_SetPolygonID(*(void**)(*(char**)((char*)a2 + 8) + 0x54), 0x3d);
        Object3D* o1 = *(Object3D**)((char*)self + 0xe8);
        o1->SetScale(0x1000, 0x1000, 0x1000);
        Object3D* o2 = *(Object3D**)((char*)self + 0xe8);
        SetFields0x44((struct Fields020407b4*)o2, 0, -0xa000, 0x1000);
        Object3D* o3 = *(Object3D**)((char*)self + 0xe8);
        o3->SetAnimationByIndex(0, 0);
    }

    *(void**)((char*)arg0 + 0x38) = arg1;
    if (arg1 != NULL) {
        return;
    }
    void* buf = AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x301c);
    if (buf != NULL) {
        SafeAllocator* alloc = (SafeAllocator*)((char*)self + 0x24);
        alloc->ResetAllocatorPointer();
        alloc->CreateTypeA(buf, 0x301c);
        alloc->Reset();
        return;
    }

    *(unsigned char*)((char*)arg0 + 0x1d) = 0;
    ((SafeAllocator*)((char*)arg0 + 0x24))->ResetAllocatorPointer();
    *(int*)((char*)arg0 + 0x0) = -1;
}
