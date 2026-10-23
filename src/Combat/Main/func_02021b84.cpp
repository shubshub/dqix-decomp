#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Combat/MapDisplay.h"
#if defined(jpn)
#include "Resource/MessageSystem.h"
#include "NitroSDK/Memory.h"
#include "NitroSDK/Cache.h"
#include "NitroSDK/LoadToVRAM.h"
extern "C" int func_020421a0(void);
extern "C" void func_02023218(Struct_02020554* arg0, void* arg1, int arg2, unsigned int arg3);
extern char data_020ef4b1[], data_020ef4c9[], data_020ef4d0[];
#endif
#include "Resource/GameResources.h"
#include "Resource/Brightness.h"

extern "C" void* func_02012fe4(void);
extern "C" void* func_0203bd08(void);
extern "C" void* func_0203b628(void);
extern "C" void func_02021428(void* arg0, int arg1);

extern "C" void func_020209d0(void* arg0);
extern "C" void func_0203b66c(char* arg0);
extern "C" void func_0203bd78(char* arg0);
extern "C" void func_0203bd24(char* arg0);
extern "C" void func_0203b718(void* arg0, int arg1, int arg2, int arg3);
extern "C" void func_0203ba74(void* arg0);
extern "C" void func_020c9820(void);
#if defined(jpn)
extern "C" void func_02020cb8(void* arg0, int arg1);
extern "C" void func_02020e58(void* arg0, int arg1);
#else
extern "C" void func_02020cb8(void* arg0, int* arg1);
extern "C" void func_02020e58(void* arg0, int* arg1);
#endif
void CopyStringOrDefault02026428(void* obj, const char* name);
void SetEventStringAndAccumulateLength02026470(void* obj, int flag);
struct Struct0205a198;
void Sprite_Init(struct Struct0205a198* p);
void SpriteContext_Init(char* obj);
struct Rec020467f0;
int ProcessRecords0205a498(void* a, struct Rec020467f0* b, int flag, void* d);
void SetBitfieldStoreBytes0205af38(int a, char* obj, int c, int d);
void* GetGlobalPtr02105244_0203bd14();
int InitAndCopyBuffer020233b8(void* arg0, int flag1);
extern "C" void* func_0203be4c(void);
extern "C" void func_02020aa0(void* arg0);
#if defined(jpn)
extern "C" void func_02026898(void* arg0);
#else
extern "C" void func_02026f34(void* arg0);
#endif
extern "C" void func_ov017_02191234(void* arg0);
extern "C" void func_0202343c(void* arg0);
extern "C" void func_02026b7c(unsigned char* arg0);
extern "C" void func_02026bdc(void* arg0, int arg1);
extern "C" int func_02020b98(void* arg0);

extern char data_020ef5c0[];
extern char data_020ef5d8[];
extern int data_020ef460;
extern char data_020ef5df[];

static inline SafeAllocator* inline_02021b84(GameResources* arg0, int arg1) {
    return &arg0->allocator_array_38[arg1];
}

// USA: func_02021b84
extern "C" ARM void func_02021b84(Struct_02020554* arg0) {
    char var0[0x18];
    void* var1;
    unsigned int var2;

    GameState* var3;
    BackgroundLoader* var4;
    GameResources* var5;
    char* var6;
    char* var7;
    SafeAllocator* var8;
    GrottoStruct* var9;
    int var10;

    var3 = GameState::GetInstance();
    var4 = BackgroundLoader::GetInstance();
    func_02012fe4();
    var5 = GetGameResources();
    var6 = (char*)func_0203bd08();
    var7 = (char*)func_0203b628();
    var8 = inline_02021b84(var5, 12);
    var9 = var3->GetGrottoStruct();
    var10 = arg0->unknown_9c2_;

    if (var10 == 0) {
        func_02021428(arg0, 0x19);
        var4->AddFence();
        arg0->unknown_9fc_ = var4->QueueLoadFile(
#if defined(jpn)
            data_020ef4b1,
#else
            data_020ef5c0,
#endif
            (SafeAllocator*)0);
        sprintf(var0,
#if defined(jpn)
            data_020ef4c9,
#else
            data_020ef5d8,
#endif
            var9->activeMapImageName);
        arg0->unknown_a00_ = var4->QueueLoadFileInGP2(

#if defined(jpn)
            *(const char**)&data_020ef460,
#else
            *(const char**)((char*)&data_020ef460 + 0xc),
#endif
            var0, (SafeAllocator*)0);
        strcpy((char*)arg0->unknown_a45_, var9->activeMapImageName);
        arg0->unknown_9d0_ = func_02020b98(arg0);
        arg0->unknown_a04_ = var4->QueueLoadFile(
#if defined(jpn)
            data_020ef4d0,
#else
            data_020ef5df,
#endif
            (SafeAllocator*)0);
        arg0->unknown_9c2_ = arg0->unknown_9c2_ + 1;
    } else if (var10 == 1) {
        func_02021428(arg0, 0x19);
        if (IsBrightnessWithinValidRange((GameResources*)var5, true) != 0) return;
        if (var4->GetTaskStatus(arg0->unknown_9fc_) == 0) return;
        if (var4->GetTaskStatus(arg0->unknown_a00_) == 0) return;
        func_02020720(arg0);
        func_020209d0(arg0);
        var8->Reset();
        func_0203b66c(var7);
        func_0203bd78(var6);
        func_0203bd24(var6);
        func_0203b718(var7, 1, 0, 0);
        func_0203b718(var7, 1, 1, 0);
        func_0203ba74(var7);
        func_020c9820();
#if defined(jpn)
        func_02020cb8(arg0, arg0->unknown_9fc_);
#else
        func_02020cb8(arg0, &arg0->unknown_9fc_);
#endif
#if defined(jpn)
        func_02020e58(arg0, arg0->unknown_a00_);
#else
        func_02020e58(arg0, &arg0->unknown_a00_);
#endif
        arg0->unknown_9c2_ = arg0->unknown_9c2_ + 1;
    } else if (var10 == 2) {
        int var11 = var4->GetTaskStatus(arg0->unknown_9d0_);
        if (var11 == 0) return;
        if (var11 > 0) {
            func_02020c18(arg0,
#if defined(jpn)
                arg0->unknown_9d0_,
#else
                &arg0->unknown_9d0_,
#endif
                var8);
        } else {
            BackgroundLoader::GetInstance()->RemoveTask(arg0->unknown_9d0_);
            arg0->unknown_9d0_ = -1;
        }
        arg0->unknown_14_ = 1;
        arg0->unknown_9c2_ = arg0->unknown_9c2_ + 1;
    } else if (var10 == 3) {
        if (var4->GetTaskStatus(arg0->unknown_a04_) == 0) return;
 #if !defined(jpn)
        arg0->unknown_be4_ = 0;
        arg0->unknown_be8_ = 0;
        arg0->unknown_bec_ = 0;
        arg0->unknown_bee_ = 0;
#endif
        CopyStringOrDefault02026428(self, grotto->activeMapNameNoLevel);
        SetEventStringAndAccumulateLength02026470(self, grotto->activeMapLevel);
        strcpy((char*)self->bytesa55, grotto->activeMapNameNoLevel);
        self->fielda95 = grotto->activeMapLevel;
        fileData = 0;
        fileLength = 0;
        loader->GetLoadedFileByID(self->taska04, &fileData, &fileLength);
        for (int i = 0; i < 0x1c; i++) {
            Sprite_Init(&self->records[i]);
        }
        SpriteContext_Init((char*)&self->entryList);
        self->entryList.active = 1;
        self->entryList.records = self->records;
        self->entryList.count = 0x18;
        ProcessRecords0205a498((char*)&self->entryList, (struct Rec020467f0*)fileData, fileLength, alloc);
        SetBitfieldStoreBytes0205af38((int)((char*)&self->entryList), (char*)&self->records[9], 1, 1);
        SetBitfieldStoreBytes0205af38((int)((char*)&self->entryList), (char*)&self->records[11], 1, 1);
        *(int*)((char*)GetGlobalPtr02105244_0203bd14() +
#if defined(jpn)
                0x608
#else
                0x508
#endif
        ) = 0x2000;
#if defined(jpn)
        Struct_02021b84* var13 = (Struct_02021b84*)func_020421a0();
        char* var14 = var13->unknown_2c_;
        char* var15 = (char*)0x06600000;
        VectorizedInvertedMemcpy(var15 + 0x2bc0, var14, 0x540);
        func_02023218(arg0, var14, 0, 0x540);
        func_020c9820();
        CleanInvalidateCacheRange(var14, 0x540);
        LoadToSubObjVRAM(var14, 0x2bc0, 0x540);
#else
        char* var16 = (char*)0x06600000;
        memcpy(arg0->unknown_bf0_, var16 + 0x2c00, 0x40);
        func_020233b8(arg0, 1);
#endif
        func_0203bd08();
        char* var17 = (char*)func_0203be4c() + 0x2e8;
        *(char**)func_0203bd14() = var17;
        BackgroundLoader::GetInstance()->RemoveTask(arg0->unknown_a04_);
        arg0->unknown_a04_ = -1;
        func_02020aa0(arg0);
#if defined(jpn)
        func_02026898(arg0);
#else
        func_02026f34(arg0);
#endif
        func_ov017_02191234(var5);
        arg0->unknown_9c4_ = 1;
        arg0->unknown_9c8_ = 0;
        arg0->unknown_9c3_ = 0;
        arg0->unknown_9c2_ = arg0->unknown_9c2_ + 1;
        func_020c9820();
        func_0202343c(arg0);
        func_02026b7c((unsigned char*)arg0);
        func_02026bdc(arg0, 0);
    }
}
