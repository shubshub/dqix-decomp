#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/OverlayId.h"

struct AllocatorUnion;
struct Struct_020979c0;

extern "C" void func_020a0cc4(unsigned int size);
extern "C" void ROMFilesystem_InitFileTables(void);
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern "C" void func_020979c0(Struct_020979c0* obj, unsigned char flag);
extern "C" void Overlay_Load(unsigned int id);
extern "C" void func_020a1ef0(int value);
extern "C" void func_020a1f4c(int value);
extern "C" void func_ov014_02186a70(void* obj);
extern "C" void func_ov014_021868b8(void* obj, SafeAllocator* allocator);
extern "C" int func_ov014_02186bc8(void* obj, unsigned int tick);
extern "C" void func_ov014_02186b30(void* obj);
extern "C" int func_02097a04(void* obj);
extern "C" void func_02097b34(void* obj);
extern char g_mainAllocator;

struct Task021c03a4 {
    char pad0;
    unsigned char failed;
    char pad1[8 - 2];
    SafeAllocator allocator;
    void* f1c;
    void* f20;
    unsigned char step;
};

extern "C" void func_ov017_021c0364(Task021c03a4* task);

// Overlay 17, originally func_ov017_021c03a4 (USA/EUR 0x021c03a4, JPN 0x021c094c)
extern "C" ARM void FieldTask_OpenMonsterList(Task021c03a4* task) {
    if (task->step == 0) {
        *(unsigned short*)0x4000304 |= 0x8000;
        func_020a0cc4(0x3f000);
        void* buffer = AllocatorUnion_AllocateRounded((AllocatorUnion*)&g_mainAllocator, 0x3f000);
        if (buffer == NULL) {
            ROMFilesystem_InitFileTables();
            task->failed = 1;
            return;
        }
        task->allocator.CreateTypeA(buffer, 0x3f000);
        task->allocator.Reset();
        task->f1c = task->allocator.Allocate(0x20);
        task->f20 = task->allocator.Allocate(0x194);
        if (task->f1c == NULL || task->f20 == NULL) {
            ROMFilesystem_InitFileTables();
            task->failed = 1;
            return;
        }
        func_020979c0((Struct_020979c0*)task->f1c, 1);
        Overlay_Load(OVERLAY_ID(14));
        func_020a1ef0(1);
        func_ov014_02186a70(task->f20);
        func_ov014_021868b8(task->f20, &task->allocator);
        task->step++;
        return;
    }
    if (task->step == 1) {
        if (func_02097a04(task->f1c)) {
            task->step++;
        }
        return;
    }
    if (task->step == 2) {
        if (func_ov014_02186bc8(task->f20, GameState::GetInstance()->GetTickCount())) {
            task->step++;
        }
        return;
    }
    if (task->step != 3) {
        return;
    }
    func_ov014_02186b30(task->f20);
    func_02097b34(task->f1c);
    func_ov017_021c0364(task);
    ROMFilesystem_InitFileTables();
    func_020a1f4c(1);
    task->failed = 1;
}
