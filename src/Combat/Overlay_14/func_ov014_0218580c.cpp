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
    short id_;
    unsigned short count_;
    short* items_;
    short x_;
    short y_;
    short unknown_c_;
    short unknown_e_;
    short previous_;
    short unknown_12_;
    short unk_14;
    unsigned char flags_;
    unsigned char unknown_17_;
};

struct Sprite {
    char unk_0[0x14];
    int x_;
    int y_;
    char unk_1c[6];
    unsigned char unk_22;
    char unknown_23_[2];
    unsigned char unknown_25_;
    unsigned char unknown_26_;
    char unknown_27_;
};

struct SpriteRenderer;
struct PacRecord;

struct Struct_ov014_02184dcc {
    void** unknown_0_;
    SpriteRenderer* spriteRenderer_;
    Sprite* sprites_;
    char unk_c[0x3c - 0xc];
    SafeAllocator* allocators_;
    void* model_;
    void* camera_;
    char unknown_48_[0x58 - 0x48];
    void* layout_;
    char unk_5c[0x6c - 0x5c];
    int unknown_6c_;
    int unknown_70_;
    int unknown_74_;
    int unknown_78_;
    unsigned char state_;
    unsigned char unknown_7d_;
    unsigned char unknown_7e_;
    unsigned char unknown_7f_;
    unsigned char page_;
    unsigned char flags_;
};

struct Struct_ov014_02189800 {
    char unk_0[0xc];
    void* previousCamera;
};
extern Struct_ov014_02189800 data_ov014_02189800;
extern char data_ov014_02189692[];
extern char data_ov014_021896a7[];

extern "C" void func_ov023_021e20c0(void* layout);
extern "C" int func_ov023_021e20f0(void* layout, SafeAllocator* allocator, void* file, unsigned int size);
extern "C" Struct_ov006_0215b7e8* func_ov014_021842a0(void* layout, short id);
extern "C" int Pac_CountFiles(PacRecord* pac);
extern "C" void* Pac_GetFile(PacRecord* pac, int index, void** outName, int* outSize);
extern "C" void SpriteContext_LoadFile(SpriteRenderer* renderer, void* file, unsigned int size, SafeAllocator* allocator);
extern "C" void func_ov023_021e2bdc(void* layout, int id, short* x, short* y);
extern "C" void* GameState_GetFollowCamera(char* gameState);
extern "C" void func_020a2010(void* camera);
extern "C" void Camera_SetTarget(struct Camera* camera, int x, int y, int z);
extern "C" void Camera_SetOrbit(void* camera, int x, int y, int z);
extern "C" void Camera_Update(void* camera);
extern "C" void FollowCamera_DisableFollow(void* camera);
extern "C" void GameState_SetCamera(GameState* gameState, int camera);
extern "C" void func_020c54a4(int, unsigned int, unsigned int, unsigned short);
extern "C" void Set3DClearColor(int, int, int, int, int);

#define HIDE_ELEMENT(layout, id)                                        \
    {                                                                   \
        Struct_ov006_0215b7e8* element = func_ov014_021842a0(layout, id);       \
        if (element != NULL)                                            \
            element->flags_ &= ~1;                                      \
    }

// USA: func_ov014_0218580c
extern "C" ARM void func_ov014_0218580c(Struct_ov014_02184dcc* self) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (self->unknown_7d_ == 0) {
        BG1CNT = (BG1CNT & (BGCNT_MASK_PRIORITY | BGCNT_MASK_MOSAIC)) | (0x1f << 8);
        self->flags_ |= 0x10;
        self->unknown_7d_++;
    }

    if (self->unknown_7d_ == 1) {
        func_ov023_021e20c0(self->layout_);
        self->unknown_6c_ = loader->QueueLoadFile(data_ov014_02189692, NULL);
        self->unknown_7d_++;
    }

    if (self->unknown_7d_ == 2 && loader->GetTaskStatus(self->unknown_6c_)) {
        void* file;
        unsigned int size;
        loader->GetLoadedFileByID(self->unknown_6c_, &file, &size);
        if (file != NULL) {
            SafeAllocator* allocators = self->allocators_;
            allocators[3].Reset();
            func_ov023_021e20f0(self->layout_, &allocators[3], file, size);
            HIDE_ELEMENT(self->layout_, 1);
        }
        loader->RemoveTask(self->unknown_6c_);
        self->unknown_6c_ = -1;
        self->unknown_6c_ = loader->QueueLoadFile(data_ov014_021896a7, NULL);
        self->unknown_7d_++;
    }

    if (self->unknown_7d_ == 3 && loader->GetTaskStatus(self->unknown_6c_)) {
        void* name;
        void* file;
        unsigned int size;
        int cellsSize;
        loader->GetLoadedFileByID(self->unknown_6c_, &file, &size);
        int numFiles = Pac_CountFiles((PacRecord*)file);
        self->allocators_[5].Reset();
        for (int i = 0; i < numFiles; i++) {
            void* cells = Pac_GetFile((PacRecord*)file, i, &name, &cellsSize);
            if (cells != NULL)
                SpriteContext_LoadFile(self->spriteRenderer_, cells, cellsSize, &self->allocators_[5]);
        }

        short x = 0;
        short y = 0;
        Sprite* sprite;
        HIDE_ELEMENT(self->layout_, 0x1a);
        func_ov023_021e2bdc(self->layout_, 0x1a, &x, &y);
        sprite = &self->sprites_[0];
        sprite->x_ = x << 12;
        sprite->y_ = y << 12;
        sprite->unk_22 = 0x21;
        sprite->unknown_26_ = 0;
        HIDE_ELEMENT(self->layout_, 0x1b);
        func_ov023_021e2bdc(self->layout_, 0x1b, &x, &y);
        sprite = &self->sprites_[1];
        sprite->x_ = x << 12;
        sprite->y_ = y << 12;
        sprite->unk_22 = 0x22;
        sprite->unknown_26_ = 0;
        func_ov023_021e2bdc(self->layout_, 0x14, &x, &y);
        sprite = &self->sprites_[2];
        sprite->x_ = x << 12;
        sprite->y_ = y << 12;
        sprite->unk_22 = 0x20;
        sprite->unknown_26_ = 0;
        loader->RemoveTask(self->unknown_6c_);
        self->unknown_6c_ = -1;
        self->unknown_7d_++;
    }

    if (self->unknown_7d_ == 4) {
        BG0CNT = (BG0CNT & ~BGCNT_MASK_PRIORITY);
        BG1CNT = (BG1CNT & ~BGCNT_MASK_PRIORITY) | 1;
        BG2CNT = (BG2CNT & ~BGCNT_MASK_PRIORITY) | 2;
        BG3CNT = (BG3CNT & ~BGCNT_MASK_PRIORITY) | 3;
        DISPCNT = (DISPCNT & ~0x1f00) | (0x13 << 8);
        GameState* gameState = GameState::GetInstance();
        data_ov014_02189800.previousCamera = GameState_GetFollowCamera((char*)gameState);
        func_020a2010(self->camera_);
        Camera_SetTarget((struct Camera*)self->camera_, 0, 0, 0);
        Camera_SetOrbit(self->camera_, 0, 0, 0xa000);
        Camera_Update(self->camera_);
        FollowCamera_DisableFollow(self->camera_);
        GameState_SetCamera(gameState, (int)self->camera_);
        GameResources* resources = GetGameResources();
        SetFlags04(resources, 0x6093e);
        ClearFlags04(resources, 0x20);
        func_020c54a4(0, 0, 0, 0);
        Set3DClearColor(0, 0, 0x7fff, 0, 0);
        LightingManager::GetInstance()->fogEnabled_ = false;
        self->state_ = 1;
        self->unknown_7d_ = 0;
    }
}
