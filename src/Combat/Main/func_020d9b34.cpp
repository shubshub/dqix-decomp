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

extern AllocatorUnion data_02114e20;
extern const char data_020f2810[];
extern const char data_020f2826[];

struct Struct_02114e20;
extern "C" unsigned int func_02012dd0(Struct_02114e20* arg0);
extern "C" void* func_02012d88(AllocatorUnion* arg0, unsigned int arg1);
extern "C" void* func_020d6c00(void);
extern "C" void func_020466e4(unsigned int* arg0, unsigned int arg1);
struct Struct_02018300_3;
extern "C" void func_020397cc(struct Struct_02018300_3* arg0, int arg1);
extern "C" int func_020421a0(void);
extern "C" void func_02046380(void* arg0);
#if !defined(jpn)
extern "C" void func_0204500c(void* arg0, void* arg1, int arg2, int arg3);
#endif
extern "C" void KeyTable_Load(void* dest, void* allocator, void* fileData, unsigned int size);
struct Obj02046574;
void SetIndexedName02046574(struct Obj02046574* obj, int index, char* name);
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

// USA: func_020d9b34
extern "C" ARM void func_020d9b34(struct Struct_020d9b34_2* arg0) {
    if (arg0->unknown_9_ == 0) {
        if (func_02012dd0((Struct_02114e20*)&data_02114e20) < 0x400) {
            arg0->unknown_1_ = 1;
            return;
        }
        func_020397cc((struct Struct_02018300_3*)GameState::GetInstance()->GetUnknownGameObject(), 1);
        func_020466e4((unsigned int*)func_020d6c00(), 0xe);
        arg0->unknown_58_.ResetAllocatorPointer();
        arg0->unknown_58_.CreateTypeA(func_02012d88(&data_02114e20, 0x400), 0x400);
        arg0->unknown_58_.Reset();
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
    } else if (arg0->unknown_9_ == 2) {
        Struct_0208cb08* var3 = func_02094a00();
        func_02094b40(var3);
        func_02094ab0(var3);
        func_02094b30(var3, 0x207, 0);
        arg0->unknown_9_++;
    } else if (arg0->unknown_9_ == 3) {
        if (func_02094b4c(func_02094a00()) == 0) return;
        void* var4 = (void*)func_020421a0();
        func_02046380(var4);
        func_02046574((struct Struct_02046574_2*)var4, 0, arg0->unknown_10_);
#if defined(jpn)
        func_0204500c(var4, func_02072a68((Struct_02072a68_2*)&arg0->unknown_40_, arg0->unknown_8_), 0);
#else
        func_0204500c(g, (void*)KeyTable_Get((struct Container020e0310*)&self->container, self->field8), 0, 0xe3);
#endif
        *(int*)((char*)var4 + REGION_VALUE(0x868, 0x998)) = 1;
        arg0->unknown_9_++;
    } else if (arg0->unknown_9_ == 4) {
        if (*(int*)((char*)func_020421a0() + REGION_VALUE(0x868, 0x998)) == 0) {
            func_020d9d60((struct Struct_020d9b34*)arg0);
            arg0->unknown_1_ = 1;
        }
    }
}
