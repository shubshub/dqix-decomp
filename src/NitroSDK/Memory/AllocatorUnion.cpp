#include "NitroSDK/Memory/AllocatorUnion.h"

// USA: func_020afe6c
// JPN: func_020b1938
void* AllocatorUnion::Allocate(unsigned int len)
{
    return versions.base.pVTable->allocate(&versions.base, len);
}

// USA: func_020afe80
// JPN: func_020b194c
void AllocatorUnion::Free(void* data)
{
    versions.base.pVTable->free(&versions.base, data);
}

// USA: func_020afe94
// JPN: func_020b1960
void AllocatorUnion::InitializeTypeB(HPXEAllocator* pAlloc, int align)
{
    versions.unknown2_0_.pVTable = &AllocatorTypeB::s_vtable;
    versions.unknown2_0_.pHPXEAllocator = pAlloc;
    versions.unknown2_0_.alignmentAndDir = align;
    versions.unknown2_0_.unknown = 0;
}

// USA: func_020afeac
// JPN: func_020b1978
void AllocatorUnion::InitializeTypeA(HMRFAllocator* pAlloc, int align)
{
    versions.unknown1_0_.pVTable = &AllocatorTypeA::s_vtable;
    versions.unknown1_0_.pHMRFAllocator = pAlloc;
    versions.unknown1_0_.alignmentAndDir = align;
    versions.unknown1_0_.unknown = 0;
}