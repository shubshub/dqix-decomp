#include <globaldefs.h>

#if defined(jpn)
#define REGION_VALUE(jpnValue, usaValue) jpnValue
extern "C" void func_02022da0(void*);
#else
#define REGION_VALUE(jpnValue, usaValue) usaValue
#endif
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "Resource/Script.h"
#include "Combat/CombatScriptContext.h"
#include "World/Zone3D.h"
#include "Combat/MapDisplay.h"
#include "Resource/Brightness.h"
#include "NitroSDK/Memory.h"

extern "C" Zone3D* Zone3D_GetInstance(void);
extern "C" void* func_0203bd08(void);
extern "C" void* func_0203b628(void);
extern "C" void func_02021428(void* arg0, int arg1);

extern "C" int Font_GetTextWidth(void* p, int flag);

void TailForward0203b66c(char* obj);
void InitSubObject0203bd78(char* obj);
void InitBattleContext0203bd24(char* obj);
void SetArraySlotFlag0203b718(void* objPtr, int mode, int idx, int fillByte);
extern "C" void func_0203ba74(void* obj);
struct Struct0205a198;
void Sprite_Init(struct Struct0205a198* p);
void SpriteContext_Init(char* obj);

extern "C" int func_02020b98(void* arg0);
extern "C" void func_02026644(char* arg0);
#if defined(jpn)
extern "C" void func_020211b0(char* arg0, int arg1);
#else
extern "C" void func_020211b0(char* arg0, int* arg1);
#endif
#if defined(jpn)
#else
#endif
extern "C" int func_02023330(void* arg0, int arg1);
extern "C" void func_02020aa0(void* arg0);
#if defined(jpn)
extern "C" void func_02020fc4(void* arg0, int arg1, SafeAllocator* arg2);
#else
extern "C" void func_02020fc4(void* arg0, int* arg1, SafeAllocator* arg2);
#endif
extern "C" void func_020210f8(char* arg0, int* arg1, SafeAllocator* arg2);
extern "C" void func_0202445c(void* arg0);
extern "C" void func_ov017_02191234(void* arg0);
extern "C" void func_020c9820(void);
extern "C" void func_0202343c(void* arg0);
extern "C" void func_02026b7c(unsigned char* arg0);
extern "C" void func_02026bdc(void* arg0, int arg1);

extern const char* data_020ef460[];
extern char data_020ef598;
extern char data_020ef5a5;
extern Script::OpcodeLookupEntry data_020ef4e8[];
extern char data_020ef5b9;

static inline SafeAllocator* inline_02021578(GameResources* arg0, int arg1) {
    return &arg0->allocator_array_38[arg1];
}

// USA: func_02021578
extern "C" ARM void func_02021578(Struct_02020554* arg0) {
    void* var0;
    unsigned int var1;
    char var2[0x40];
    Script var3;

    BackgroundLoader* var4;
    GameResources* var5;
    int var6;
    int var7;
    int var8;
    Zone3D_StructPtr_8* var9;
    char* var10;
    char* var11;
    SafeAllocator* var12;
    int var13;

    GameState::GetInstance();
    loader = BackgroundLoader::GetInstance();
    modes = Zone3D_GetInstance()->pUnknownStruct_8_;
    axis = GetGameResources();
    battleCtx = (char*)func_0203bd08();
    table = (char*)GetData02105254_0203b628();
    state = self->loadStage;
    alloc = GetResourceAllocator(axis, 12);

    if (var13 == 0) {
        arg0->unknown_9c7_ = 0;
        func_02021428(arg0, 0x19);
#if !defined(jpn)
        var4->AddFence();
        arg0->unknown_9f8_ = var4->QueueLoadFileInGP2(
            data_020ef460[1],
            data_020ef460[0], (SafeAllocator*)0);
#endif
        var4->AddFence();
        arg0->unknown_9d0_ = func_02020b98(arg0);
        arg0->unknown_a30_ = var4->QueueLoadFileInGP2(
            data_020ef460[REGION_VALUE(1, 2)],
            &data_020ef598, (SafeAllocator*)0);
        arg0->unknown_9cc_ = var4->QueueLoadFile(&data_020ef5a5, (SafeAllocator*)0);
        arg0->unknown_9c2_ = arg0->unknown_9c2_ + 1;
#if !defined(jpn)
    } else if (state == 1) {
        if (loader->GetTaskStatus(self->scriptTask) == 0) return;
        VectorizedMemset(self->scriptName, 0, 0x40);
        data_020fdc4c.nameOverride = 0;
        self->scriptNameWidth = 0;
        self->fieldb3c = 0;
        self->fieldb40 = 0;
        self->fieldb42 = 0;
        loader->GetLoadedFileByID(self->scriptTask, &fileData, &fileLength);
        script.Initialize();
        script.SetOpcodeLookup(data_020ef4e8);
        script.Load(fileData, fileLength);
        script.Execute();
        const char* name = data_020fdc4c.nameOverride;
        if (name != 0) {
            memcpy(self->scriptName, name, strlen(name));
            self->scriptNameWidth = Font_GetTextWidth(self->scriptName, 0);
        }
        BackgroundLoader::GetInstance()->RemoveTask(arg0->unknown_9f8_);
        arg0->unknown_9f8_ = -1;
        arg0->unknown_9c2_ = arg0->unknown_9c2_ + 1;
#endif
    } else if (state == REGION_VALUE(1, 2)) {
        func_02021428(self, 0x19);
        if (IsBrightnessWithinValidRange((GameResources*)axis, true) != 0) return;
        func_02020720(self);
        func_02020838(self);
        TailForward0203b66c(table);
        alloc->Reset();
        InitSubObject0203bd78(battleCtx);
        InitBattleContext0203bd24(battleCtx);
        SetArraySlotFlag0203b718(table, 1, 0, 0);
        SetArraySlotFlag0203b718(table, 1, 1, 0);
        func_0203ba74(table);
        for (i0 = 0; i0 < 0x1c; i0++) {
            Sprite_Init(&self->records[i0]);
        }
        SpriteContext_Init((char*)&self->entryList);
        self->entryList.active = 1;
        self->entryList.records = self->records;
        self->entryList.count = 0x1c;
        int mode = modes->unknown_c_low_;
        if (mode == 0) {
            self->displayMode = 3;
        } else if (mode == 7) {
            self->displayMode = 1;
        } else {
            arg0->unknown_14_ = 0;
        }
        arg0->unknown_9c2_ = arg0->unknown_9c2_ + 1;
#if defined(jpn)
    }
    if (arg0->unknown_9c2_ == 2) {
#else
    } else if (var13 == 3) {
#endif
        int var16 = var4->GetTaskStatus(arg0->unknown_9d0_);
        if (var16 == 0) return;
        arg0->unknown_24_ = 0;
        arg0->unknown_30_ = 0;
        if (var16 == -1) {
            arg0->unknown_9c2_ = 0x64;
            BackgroundLoader::GetInstance()->RemoveTask(arg0->unknown_9d0_);
            arg0->unknown_9d0_ = -1;
            BackgroundLoader::GetInstance()->RemoveTask(arg0->unknown_a30_);
            arg0->unknown_a30_ = -1;
            BackgroundLoader::GetInstance()->RemoveTask(arg0->unknown_9cc_);
            arg0->unknown_9cc_ = -1;
            arg0->unknown_9c7_ = 1;
            return;
        }
#if defined(jpn)
        func_02020c18(arg0, arg0->unknown_9d0_, var12);
#else
        func_02020c18(arg0, &arg0->unknown_9d0_, var12);
#endif
        if (arg0->unknown_779_ != 0) {
            arg0->unknown_9b8_ = 1;
            arg0->unknown_9b9_ = 0;
            func_02026644((char*)arg0);
        }
        var4->AddFence();
        sprintf(var2, &data_020ef5b9, arg0->unknown_548_);
        arg0->unknown_9d4_ = var4->QueueLoadFileInGP2(
            data_020ef460[REGION_VALUE(1, 2)], var2, (SafeAllocator*)0);
        for (var7 = 0; var7 < arg0->unknown_24_; var7++) {
            sprintf(var2, &data_020ef5b9,
                    (arg0->unknown_20_)[var7].unknown_4_);
            arg0->unknown_9d8_[var7] = var4->QueueLoadFileInGP2(
                data_020ef460[REGION_VALUE(1, 2)], var2, (SafeAllocator*)0);
        }
        arg0->unknown_9c2_ = arg0->unknown_9c2_ + 1;
    }

    if (arg0->unknown_9c2_ == REGION_VALUE(3, 4)) {
        if (var4->GetTaskStatus(arg0->unknown_a30_) == 0) return;
#if defined(jpn)
        func_020211b0((char*)arg0, arg0->unknown_a30_);
#else
        func_020211b0((char*)arg0, &arg0->unknown_a30_);
#endif
        arg0->unknown_9c2_ = arg0->unknown_9c2_ + 1;
    }
    if (arg0->unknown_9c2_ == REGION_VALUE(4, 5)) {
        if (var4->GetTaskStatus(arg0->unknown_9cc_) == 0) return;
#if defined(jpn)
        func_02020aec(arg0, arg0->unknown_9cc_, var12);
#else
        func_02020aec(arg0, &arg0->unknown_9cc_, var12);
#endif
#if defined(jpn)
        func_02022da0(arg0);
#else
        char* var17 = (char*)0x6600000;
        memcpy(arg0->unknown_bf0_, var17 + 0x2c20, 0x40);
        func_02023330(arg0, 1);
#endif
        func_02020aa0(arg0);
        arg0->unknown_9c2_ = arg0->unknown_9c2_ + 1;
    }
    if (arg0->unknown_9c2_ == REGION_VALUE(5, 6)) {
        if (var4->GetTaskStatus(arg0->unknown_9d4_) == 0) return;
#if defined(jpn)
        func_02020fc4((char*)arg0, arg0->unknown_9d4_, var12);
#else
        func_02020fc4((char*)arg0, &arg0->unknown_9d4_, var12);
#endif
        arg0->unknown_9c2_ = arg0->unknown_9c2_ + 1;
    }
    if (arg0->unknown_9c2_ == REGION_VALUE(6, 7)) {
        for (var8 = 0; var8 < arg0->unknown_24_; var8++) {
            if (var4->GetTaskStatus(arg0->unknown_9d8_[var8]) == 0) return;
        }
        func_020210f8((char*)arg0, arg0->unknown_9d8_, var12);
        func_0202445c(arg0);
        func_ov017_02191234(var5);
        arg0->unknown_55c_ = 1;
        arg0->unknown_9c4_ = 1;
        arg0->unknown_9c8_ = 0;
        arg0->unknown_9c3_ = 0;
        arg0->unknown_9c2_ = arg0->unknown_9c2_ + 1;
        func_020c9820();
        func_0202343c(arg0);
        func_0202445c(arg0);
        func_02026b7c((unsigned char*)arg0);
        func_02026bdc(arg0, 0);
    }
}
