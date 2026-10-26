#include <globaldefs.h>
#include "Resource/ActionDataTables.h"

#if defined(jpn)
#define REGION_OFFSET_0 0xe44
#define REGION_OFFSET_1 0x58
#define REGION_OFFSET_2 0x371c
#define REGION_OFFSET_3 0x57bc
#define REGION_OFFSET_4 0x57c0
#define REGION_OFFSET_5 0x57e4
#define REGION_OFFSET_6 0x57e8
#define REGION_OFFSET_7 0x7901
#define REGION_ALLOCATOR_COUNT 4
#else
#define REGION_OFFSET_0 0xec8
#define REGION_OFFSET_1 0x6c
#define REGION_OFFSET_2 0x3760
#define REGION_OFFSET_3 0x55cc
#define REGION_OFFSET_4 0x55d0
#define REGION_OFFSET_5 0x55f4
#define REGION_OFFSET_6 0x55f8
#define REGION_OFFSET_7 0x7711
#define REGION_ALLOCATOR_COUNT 5
#endif

#include "Memory/SafeAllocator.h"

extern "C" void SePlayer_UnloadExtraArchiveA(void* obj);
extern "C" void Zone3D_Unload(void* obj, int flag);
extern "C" void func_ov000_02172720(void* obj);

extern "C" void func_02079f9c(char* obj);
extern "C" void* func_02057924(void);
extern "C" void func_02057f00(void* obj, int index);
extern "C" void func_ov023_021eb26c(void* obj);

extern char g_sePlayer[];
extern int data_ov000_02182fe0[];

struct Struct_ov000_021604f0 {
    char pad0[8];
    SafeAllocator allocators[REGION_ALLOCATOR_COUNT];
    char pad6c[REGION_OFFSET_0 - REGION_OFFSET_1];
    char zone[REGION_OFFSET_2 - REGION_OFFSET_0];
    char unknown_3760_[REGION_OFFSET_3 - REGION_OFFSET_2];
    void* scene;
    char unknown_55d0_[REGION_OFFSET_5 - REGION_OFFSET_4];
    int flags;
    char unknown_55f8_[REGION_OFFSET_7 - REGION_OFFSET_6];
    unsigned char unknown_7711_;
};

// USA: func_ov000_021604f0
extern "C" ARM void func_ov000_021604f0(struct Struct_ov000_021604f0* work) {
    if (work->unknown_7711_) {
        SePlayer_UnloadExtraArchiveA(g_sePlayer);
        work->unknown_7711_ = 0;
    }
    Zone3D_Unload(work->zone, 1);
    if (!(work->flags & 0x800)) {
        func_ov000_02172720(work->unknown_3760_);
    }
    func_02079f9c((char*)func_020797dc());
    void* slots = func_02057924();
    for (int* p = data_ov000_02182fe0; *p >= 0; p++) {
        func_02057f00(slots, *p);
    }
    if (work->scene != NULL) {
        func_ov023_021eb26c(work->scene);
    }
    for (int i = 0; i < REGION_ALLOCATOR_COUNT; i++) {
        if (work->allocators[i].GetSignedAllocator() != NULL) {
            work->allocators[i].Destroy();
        }
    }
}
