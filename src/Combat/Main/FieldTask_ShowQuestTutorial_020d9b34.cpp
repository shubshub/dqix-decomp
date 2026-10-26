#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"

#if defined(jpn)
#define REGION_VALUE(jpnValue, usaValue) jpnValue
extern const char data_020f2a18[];
extern "C" void func_020728ac(int, int, void*, int, int, unsigned short, unsigned char);
struct TableA68;
extern "C" void* func_02072a68(TableA68*, int);
extern "C" void func_0204500c(void*, void*, int);
#else
#define REGION_VALUE(jpnValue, usaValue) usaValue
#endif

extern AllocatorUnion g_mainAllocator;
extern const char data_020f2810[];
extern const char data_020f2826[];

struct Struct02012dd0;
extern "C" unsigned int AllocatorUnion_GetMaxPossibleAllocation(Struct02012dd0* self);
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern "C" void* GlobalFlags_GetInstance(void);
extern "C" void FlagWord_SetBits(unsigned int* obj, unsigned int mask);
struct Obj020397cc;
extern "C" void GameObject_DisableControl(struct Obj020397cc* obj, int arg1);
extern "C" int MessageSystem_GetInstance(void);
extern "C" void func_02046380(void* global);
#if !defined(jpn)
extern "C" void func_0204500c(void* global, void* entry, int a, int b);
#endif
extern "C" void KeyTable_Load(void* dest, void* allocator, void* fileData, unsigned int size);
struct Obj02046574;
extern "C" void MessageSystem_SetStringArgument(struct Obj02046574* obj, int index, char* name);
struct Container020e0310;
extern "C" int KeyTable_Get(struct Container020e0310* c, int key);

struct Struct_020d9b34 {
    char pad[REGION_VALUE(0x24, 0x58)];
    SafeAllocator allocator;
};
extern "C" void func_020d9d60(struct Struct_020d9b34* self);

struct Obj020d9b34 {
    unsigned char pad0[0x1];
    unsigned char field1;
    unsigned char pad1[0x8 - 0x2];
    signed char field8;
    unsigned char state;
    unsigned char pad2[0xc - 0xa];
    int taskId;
    char name[REGION_VALUE(0x1c, 0x40) - 0x10];
    char container[REGION_VALUE(0x24 - 0x1c, 0x58 - 0x40)];
    SafeAllocator allocator;
};

// Main, originally func_020d9b34 (USA 0x020d9b34, EUR 0x020d9b44, JPN 0x020db538)
extern "C" ARM void FieldTask_ShowQuestTutorial(struct Obj020d9b34* self) {
    if (self->state == 0) {
        if (AllocatorUnion_GetMaxPossibleAllocation((Struct02012dd0*)&g_mainAllocator) < 0x400) {
            self->field1 = 1;
            return;
        }
        GameObject_DisableControl((struct Obj020397cc*)GameState::GetInstance()->GetLeader(), 1);
        FlagWord_SetBits((unsigned int*)GlobalFlags_GetInstance(), 0xe);
        self->allocator.ResetAllocatorPointer();
        self->allocator.CreateTypeA(AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x400), 0x400);
        self->allocator.Reset();
#if defined(jpn)
        self->taskId = BackgroundLoader::GetInstance()->QueueLoadFile(data_020f2a18, NULL);
#else
        self->taskId = BackgroundLoader::GetInstance()->QueueLoadFileInGP2(data_020f2810, data_020f2826, NULL);
#endif
        self->state++;
    } else if (self->state == 1) {
        BackgroundLoader* var0 = BackgroundLoader::GetInstance();
        if (var0->GetTaskStatus(self->taskId) == 0) return;
        if (var0->GetDetailedTaskStatus(self->taskId) != 2) {
            var0->RemoveTask(self->taskId);
            self->taskId = -1;
            func_020d9d60((struct Struct_020d9b34*)self);
            self->field1 = 1;
        } else {
            void* fileData;
            unsigned int size;
            var0->GetLoadedFileByID(self->taskId, &fileData, &size);
#if defined(jpn)
            func_020728ac((int)&self->container, (int)&self->allocator, fileData, size, 0, 0, 0);
#else
            KeyTable_Load(&self->container, &self->allocator, fileData, size);
#endif
            var0->RemoveTask(self->taskId);
            self->taskId = -1;
            self->state++;
        }
    } else if (self->state == 2) {
        FontBankLoader* g = FontBankLoader_GetInstance();
        func_02094b40(g);
        FontBankLoader_CancelLoads(g);
        func_02094b30(g, 0x207, 0);
        self->state++;
    } else if (self->state == 3) {
        if (func_02094b4c(FontBankLoader_GetInstance()) == 0) return;
        void* g = (void*)MessageSystem_GetInstance();
        func_02046380(g);
        MessageSystem_SetStringArgument((struct Obj02046574*)g, 0, self->name);
#if defined(jpn)
        func_0204500c(g, func_02072a68((TableA68*)&self->container, self->field8), 0);
#else
        func_0204500c(g, (void*)KeyTable_Get((struct Container020e0310*)&self->container, self->field8), 0, 0xe3);
#endif
        *(int*)((char*)g + REGION_VALUE(0x868, 0x998)) = 1;
        self->state++;
    } else if (self->state == 4) {
        if (*(int*)((char*)MessageSystem_GetInstance() + REGION_VALUE(0x868, 0x998)) == 0) {
            func_020d9d60((struct Struct_020d9b34*)self);
            self->field1 = 1;
        }
    }
}
