#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "NitroSDK/Graphics.h"
#include "Resource/Brightness.h"

void* GlobalFlags_GetInstance(void);
void FlagWord_SetBits(unsigned int* field, unsigned int bits);
void OrGlobalFlag0x40_020dc2bc(void);
void Background_SetMapSize(unsigned char* obj, int value);
extern "C" void Background_SetPriority(void* obj, int value);
struct BackgroundGraphics;
void Background_SetScroll(struct BackgroundGraphics* obj, int a, int b);
void Background_AllocateScreens(struct BackgroundGraphics* obj, int count, SafeAllocator* alloc);
void Background_AllocateMap(struct BackgroundGraphics* obj, SafeAllocator* alloc);
void Background_ClearMap(struct BackgroundGraphics* obj, void* p);
struct Obj0204b988;
void DispatchIndexedEntry0204b988(struct Obj0204b988* obj, unsigned int a, int b, int c, unsigned short d);
void Background_UploadMap(struct BackgroundGraphics* list, void* p);
struct PacRecord;
int Pac_CountFiles(struct PacRecord* entries);
void* Pac_GetFile(struct PacRecord* table, int index, void** outPtr, int* outCount);
extern "C" void Background_LoadFile(void* obj, void* rec, SafeAllocator* alloc, int count);

extern char data_ov003_0217fcb5[];
extern char data_ov003_0217fcc7[];

struct Struct_ov003_021541b0 {
    SafeAllocator* unknown_0_;
    char unknown_4_[0x18 - 0x04];
    char unknown_18_[0x34 - 0x18];
    unsigned char unknown_34_0_ : 4;
    unsigned char unknown_34_4_ : 4;
    char unknown_35_[0x50 - 0x35];
    int unknown_50_;
    int unknown_54_;
    unsigned char unknown_58_;
    signed char unknown_59_;
    unsigned char unknown_5a_;
    unsigned char unknown_5b_;
    unsigned char unknown_5c_;
    unsigned char unknown_5d_;

    bool inline_ov003_021541b0() const { return unknown_59_ >= 0 && unknown_59_ <= 3; }
};

// USA: func_ov003_021541b0
extern "C" ARM void func_ov003_021541b0(struct SubScreenBackground* self) {
    GameResources* resources = GameState::GetInstance()->GetResources();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();

    if (arg0->unknown_5b_ == 0) {
        if (arg0->inline_ov003_021541b0()) {
            arg0->unknown_58_ = 1;
            SetSubBrightness(var0, -16, 1);
            arg0->unknown_5b_++;
        }
    } else if (self->loadState == 1) {
        if (IsSubBrightnessTransitionActive(resources) == 0) {
            FlagWord_SetBits((unsigned int*)GlobalFlags_GetInstance(), 1);
            OrGlobalFlag0x40_020dc2bc();
            self->loadState++;
        }
    } else if (arg0->unknown_5b_ == 2) {
        BG0CNTSUB = (BG0CNTSUB & 0x43) | 0xf00;
        BG0CNTSUB &= ~3;
        BG1CNTSUB = (BG1CNTSUB & ~3) | 1;
        BG2CNTSUB = (BG2CNTSUB & ~3) | 2;
        BG3CNTSUB = (BG3CNTSUB & ~3) | 3;
        DISPCNTSUB = (DISPCNTSUB & ~0x1f00) | 0x1100;

        SafeAllocator* alloc = self->allocator;
        alloc->Reset();
        self->bits34Lo = 1;
        self->bits34Hi = 0;
        Background_SetMapSize((unsigned char*)self->backgrounds, 0);
        Background_SetPriority(self->backgrounds, 0);
        Background_SetScroll((struct BackgroundGraphics*)self->backgrounds, 0, 0);
        Background_AllocateScreens((struct BackgroundGraphics*)self->backgrounds, 14, alloc);
        Background_AllocateMap((struct BackgroundGraphics*)self->backgrounds, alloc);
#if defined(jpn)
        arg0->unknown_50_ = var1->QueueLoadFile(data_ov003_0217fcb5, 0);
#else
        arg0->unknown_50_ = var1->QueueLoadFileInGP2(data_ov003_0217fcb5, data_ov003_0217fcc7, 0);
#endif
        self->loadState++;
    } else if (self->loadState == 3) {
        if (loader->GetTaskStatus(self->taskId) != 0) {
            SafeAllocator* alloc = self->allocator;
            void* ent;
            void* file;
            unsigned int len;
            loader->GetLoadedFileByID(self->taskId, &file, &len);
            int count = Pac_CountFiles((struct PacRecord*)file);
            for (int i = 0; i < count; i++) {
                int n;
                void* rec = Pac_GetFile((struct PacRecord*)file, i, &ent, &n);
                Background_LoadFile(self->backgrounds, rec, alloc, n);
            }
            loader->RemoveTask(self->taskId);
            self->taskId = -1;
            Background_ClearMap((struct BackgroundGraphics*)self->backgrounds, 0);
            DispatchIndexedEntry0204b988((struct Obj0204b988*)self->backgrounds, 0, 0, 0, 0xffff);
            Background_UploadMap((struct BackgroundGraphics*)self->backgrounds, 0);
            self->ready = 1;
            self->loadState = 0;
            self->flags |= 2;
        }
    }
}
