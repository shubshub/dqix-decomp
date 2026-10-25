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
struct Struct_02072a68_2;
extern "C" void* func_02072a68(Struct_02072a68_2*, int);
extern "C" void func_0204500c(void*, void*, int);
#else
#define REGION_VALUE(jpnValue, usaValue) usaValue
#endif

extern AllocatorUnion g_mainAllocator;
extern const char data_020f2810[];
extern const char data_020f2826[];

struct Struct02012dd0;
unsigned int GetMaxAlloc02012dd0(Struct02012dd0* self);
void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
void* GlobalFlags_GetInstance(void);
void FlagWord_SetBits(unsigned int* obj, unsigned int mask);
struct Obj020397cc;
void GameObject_DisableControl(struct Obj020397cc* obj, int arg1);
int MessageSystem_GetInstance(void);
extern "C" void func_02046380(void* global);
#if !defined(jpn)
extern "C" void func_0204500c(void* arg0, void* arg1, int arg2, int arg3);
#endif
extern "C" void KeyTable_Load(void* dest, void* allocator, void* fileData, unsigned int size);
struct Obj02046574;
void MessageSystem_SetStringArgument(struct Obj02046574* obj, int index, char* name);
struct Container020e0310;
int KeyTable_Get(struct Container020e0310* c, int key);

struct Struct_020d9b34 {
    char unknown_0_[REGION_VALUE(0x24, 0x58)];
    SafeAllocator unknown_58_;
};
extern "C" void func_020d9d60(struct Struct_020d9b34* arg0);

struct Struct_020d9b34_2 {
    unsigned char unknown_0_[0x1];
    unsigned char unknown_1_;
    unsigned char unknown_2_[0x8 - 0x2];
    signed char unknown_8_;
    unsigned char unknown_9_;
    unsigned char unknown_a_[0xc - 0xa];
    int unknown_c_;
    char unknown_10_[REGION_VALUE(0x1c, 0x40) - 0x10];
    char unknown_40_[REGION_VALUE(0x24 - 0x1c, 0x58 - 0x40)];
    SafeAllocator unknown_58_;
};

// Main, originally func_020d9b34 (USA 0x020d9b34, EUR 0x020d9b44, JPN 0x020db538)
extern "C" ARM void FieldTask_ShowQuestTutorial(struct Obj020d9b34* self) {
    if (self->state == 0) {
        if (GetMaxAlloc02012dd0((Struct02012dd0*)&g_mainAllocator) < 0x400) {
            self->field1 = 1;
            return;
        }
        GameObject_DisableControl((struct Obj020397cc*)GameState::GetInstance()->GetUnknownGameObject(), 1);
        FlagWord_SetBits((unsigned int*)GlobalFlags_GetInstance(), 0xe);
        self->allocator.ResetAllocatorPointer();
        self->allocator.CreateTypeA(AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x400), 0x400);
        self->allocator.Reset();
#if defined(jpn)
        arg0->unknown_c_ = BackgroundLoader::GetInstance()->QueueLoadFile(data_020f2a18, NULL);
#else
        arg0->unknown_c_ = BackgroundLoader::GetInstance()->QueueLoadFileInGP2(data_020f2810, data_020f2826, NULL);
#endif
        arg0->unknown_9_++;
    } else if (arg0->unknown_9_ == 1) {
        BackgroundLoader* var0 = BackgroundLoader::GetInstance();
        if (var0->GetTaskStatus(arg0->unknown_c_) == 0) return;
        if (var0->GetDetailedTaskStatus(arg0->unknown_c_) != 2) {
            var0->RemoveTask(arg0->unknown_c_);
            arg0->unknown_c_ = -1;
            func_020d9d60((struct Struct_020d9b34*)arg0);
            arg0->unknown_1_ = 1;
        } else {
            void* var1;
            unsigned int var2;
            var0->GetLoadedFileByID(arg0->unknown_c_, &var1, &var2);
#if defined(jpn)
            func_020728ac((int)&arg0->unknown_40_, (int)&arg0->unknown_58_, var1, var2, 0, 0, 0);
#else
            KeyTable_Load(&self->container, &self->allocator, fileData, size);
#endif
            var0->RemoveTask(arg0->unknown_c_);
            arg0->unknown_c_ = -1;
            arg0->unknown_9_++;
        }
    } else if (self->state == 2) {
        FontBankLoader* g = FontBankLoader_GetInstance();
        BlankFunction02094b40(g);
        FontBankLoader_CancelLoads(g);
        BlankFunction02094b30(g, 0x207, 0);
        self->state++;
    } else if (self->state == 3) {
        if (AlwaysTrue02094b4c(FontBankLoader_GetInstance()) == 0) return;
        void* g = (void*)MessageSystem_GetInstance();
        func_02046380(g);
        MessageSystem_SetStringArgument((struct Obj02046574*)g, 0, self->name);
#if defined(jpn)
        func_0204500c(var4, func_02072a68((Struct_02072a68_2*)&arg0->unknown_40_, arg0->unknown_8_), 0);
#else
        func_0204500c(g, (void*)KeyTable_Get((struct Container020e0310*)&self->container, self->field8), 0, 0xe3);
#endif
        *(int*)((char*)g + REGION_VALUE(0x868, 0x998)) = 1;
        self->state++;
    } else if (self->state == 4) {
        if (*(int*)((char*)MessageSystem_GetInstance() + REGION_VALUE(0x868, 0x998)) == 0) {
            ShutdownObject020d9d60((struct Obj020d9d60*)self);
            self->field1 = 1;
        }
    }
}
