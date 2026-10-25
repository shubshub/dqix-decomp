#if defined(jpn)
#define R(j,u) (j)
#define data_ov014_02189692 data_ov014_0218a4a3
#define data_ov014_021896a7 data_ov014_0218a4b8
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Graphics/LightingManager.h"
#include "Resource/Brightness.h"

#define BG0CNT (*(volatile unsigned short*)(0x04000008))
#define BG1CNT (*(volatile unsigned short*)(0x0400000a))
#define BG2CNT (*(volatile unsigned short*)(0x0400000c))
#define BG3CNT (*(volatile unsigned short*)(0x0400000e))
#define DISPCNT (*(volatile unsigned int*)0x04000000)
#define BGCNT_MASK_PRIORITY 3
#define BGCNT_MASK_MOSAIC 0x40

struct Struct_ov006_0215b7e8 {
    short unknown_0_;
    unsigned short unknown_2_;
    short* unknown_4_;
    short unknown_8_;
    short unknown_a_;
    short unknown_c_;
    short unknown_e_;
    short unknown_10_;
    short unknown_12_;
    short unknown_14_;
    unsigned char unknown_16_;
    unsigned char unknown_17_;
};

struct Struct_ov006_021580b8 {
    char unknown_0_[0x14];
    int unknown_14_;
    int unknown_18_;
    char unknown_1c_[6];
    unsigned char unknown_22_;
    char unknown_23_[2];
    unsigned char unknown_25_;
    unsigned char unknown_26_;
    char unknown_27_;
};

struct SpriteRenderer;
struct PacRecord;

struct Struct_ov014_02184dcc {
    void** unknown_0_;
    Struct_ov008_02188d74* unknown_4_;
    Struct_ov006_021580b8* unknown_8_;
    char unknown_c_[0x3c - 0xc];
    SafeAllocator* unknown_3c_;
    void* unknown_40_;
    void* unknown_44_;
    char unknown_48_[0x58 - 0x48];
    void* unknown_58_;
    char unknown_5c_[0x6c - 0x5c];
    int unknown_6c_;
    int unknown_70_;
    int unknown_74_;
    int unknown_78_;
    unsigned char unknown_7c_;
    unsigned char unknown_7d_;
    unsigned char unknown_7e_;
    unsigned char unknown_7f_;
    unsigned char unknown_80_;
    unsigned char unknown_81_;
};

struct Struct_ov014_02189800 {
    char unknown_0_[0xc];
    void* unknown_c_;
};
extern Struct_ov014_02189800 data_ov014_02189800;
extern char data_ov014_02189692[];
extern char data_ov014_021896a7[];

void ClearFields_021e20c0(void* layout);
extern "C" int func_ov023_021e20f0(void* layout, SafeAllocator* allocator, void* file, unsigned int size);
extern "C" LayoutElement* func_ov014_021842a0(void* layout, short id);
int Pac_CountFiles(PacRecord* pac);
void* Pac_GetFile(PacRecord* pac, int index, void** outName, int* outSize);
extern "C" void SpriteContext_LoadFile(SpriteRenderer* renderer, void* file, unsigned int size, SafeAllocator* allocator);
void ComputeShortPair_021e2bdc(void* layout, int id, short* x, short* y);
void* GetFieldIfFlag4_020100f8(char* gameState);
void InitCombatController020a2010(void* camera);
void Camera_SetTarget(struct Camera* camera, int x, int y, int z);
extern "C" void func_0202e5d8(void* camera, int x, int y, int z);
extern "C" void Camera_Update(void* camera);
void FollowCamera_DisableFollow(void* camera);
void GameState_SetCamera(GameState* gameState, int camera);
void SetFogState_020c54a4(int, unsigned int, unsigned int, unsigned short);
void Set3DClearColor_020c5588(int, int, int, int, int);

#define HIDE_ELEMENT(layout, id)                                        \
    {                                                                   \
        Struct_ov006_0215b7e8* element = func_ov014_021842a0(layout, id);       \
        if (element != NULL)                                            \
            element->unknown_16_ &= ~1;                                      \
    }

// USA: func_ov014_0218580c
extern "C" ARM void func_ov014_0218580c(Struct_ov014_02184dcc* arg0) {
    BackgroundLoader* var0 = BackgroundLoader::GetInstance();
    if (arg0->unknown_7d_ == 0) {
        BG1CNT = (BG1CNT & (BGCNT_MASK_PRIORITY | BGCNT_MASK_MOSAIC)) | (0x1f << 8);
        arg0->unknown_81_ |= 0x10;
        arg0->unknown_7d_++;
    }

    if (arg0->unknown_7d_ == 1) {
        func_ov023_021e20c0(arg0->unknown_58_);
        arg0->unknown_6c_ = var0->QueueLoadFile(data_ov014_02189692, NULL);
        arg0->unknown_7d_++;
    }

    if (arg0->unknown_7d_ == 2 && var0->GetTaskStatus(arg0->unknown_6c_)) {
        void* var1;
        unsigned int var2;
        var0->GetLoadedFileByID(arg0->unknown_6c_, &var1, &var2);
        if (var1 != NULL) {
            SafeAllocator* var3 = arg0->unknown_3c_;
            var3[3].Reset();
            func_ov023_021e20f0(arg0->unknown_58_, &var3[3], var1, var2);
            HIDE_ELEMENT(arg0->unknown_58_, 1);
        }
        var0->RemoveTask(arg0->unknown_6c_);
        arg0->unknown_6c_ = -1;
        arg0->unknown_6c_ = var0->QueueLoadFile(data_ov014_021896a7, NULL);
        arg0->unknown_7d_++;
    }

    if (self->initStep_ == 3 && loader->GetTaskStatus(self->taskID_)) {
        void* name;
        void* file;
        unsigned int size;
        int cellsSize;
        loader->GetLoadedFileByID(self->taskID_, &file, &size);
        int numFiles = Pac_CountFiles((PacRecord*)file);
        self->allocators_[5].Reset();
        for (int i = 0; i < numFiles; i++) {
            void* cells = Pac_GetFile((PacRecord*)file, i, &name, &cellsSize);
            if (cells != NULL)
                SpriteContext_LoadFile(self->spriteRenderer_, cells, cellsSize, &self->allocators_[5]);
        }

        short var11 = 0;
        short var12 = 0;
        Struct_ov006_021580b8* var13;
        HIDE_ELEMENT(arg0->unknown_58_, 0x1a);
        func_ov023_021e2bdc(arg0->unknown_58_, 0x1a, &var11, &var12);
        var13 = &arg0->unknown_8_[0];
        var13->unknown_14_ = var11 << 12;
        var13->unknown_18_ = var12 << 12;
        var13->unknown_22_ = 0x21;
        var13->unknown_26_ = 0;
        HIDE_ELEMENT(arg0->unknown_58_, 0x1b);
        func_ov023_021e2bdc(arg0->unknown_58_, 0x1b, &var11, &var12);
        var13 = &arg0->unknown_8_[1];
        var13->unknown_14_ = var11 << 12;
        var13->unknown_18_ = var12 << 12;
        var13->unknown_22_ = 0x22;
        var13->unknown_26_ = 0;
        func_ov023_021e2bdc(arg0->unknown_58_, 0x14, &var11, &var12);
        var13 = &arg0->unknown_8_[2];
        var13->unknown_14_ = var11 << 12;
        var13->unknown_18_ = var12 << 12;
        var13->unknown_22_ = 0x20;
        var13->unknown_26_ = 0;
        var0->RemoveTask(arg0->unknown_6c_);
        arg0->unknown_6c_ = -1;
        arg0->unknown_7d_++;
    }

    if (arg0->unknown_7d_ == 4) {
        BG0CNT = (BG0CNT & ~BGCNT_MASK_PRIORITY);
        BG1CNT = (BG1CNT & ~BGCNT_MASK_PRIORITY) | 1;
        BG2CNT = (BG2CNT & ~BGCNT_MASK_PRIORITY) | 2;
        BG3CNT = (BG3CNT & ~BGCNT_MASK_PRIORITY) | 3;
        DISPCNT = (DISPCNT & ~0x1f00) | (0x13 << 8);
        GameState* gameState = GameState::GetInstance();
        data_ov014_02189800.previousCamera = GetFieldIfFlag4_020100f8((char*)gameState);
        InitCombatController020a2010(self->camera_);
        Camera_SetTarget((struct Camera*)self->camera_, 0, 0, 0);
        func_0202e5d8(self->camera_, 0, 0, 0xa000);
        Camera_Update(self->camera_);
        FollowCamera_DisableFollow(self->camera_);
        GameState_SetCamera(gameState, (int)self->camera_);
        GameResources* resources = GetGameResources();
        SetFlags04(resources, 0x6093e);
        ClearFlags04(resources, 0x20);
        SetFogState_020c54a4(0, 0, 0, 0);
        Set3DClearColor_020c5588(0, 0, 0x7fff, 0, 0);
        LightingManager::GetInstance()->fogEnabled_ = false;
        arg0->unknown_7c_ = 1;
        arg0->unknown_7d_ = 0;
    }
}
