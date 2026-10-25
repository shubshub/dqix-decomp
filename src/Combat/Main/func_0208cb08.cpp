#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "Resource/Brightness.h"

#define REG_SUB_BG_0208cb08 (*(volatile Struct_0208cb08_2*)0x04001000)
struct Struct_0208cb08_2 {
    unsigned int unknown_0_;
    unsigned int unknown_4_;
    unsigned short unknown_8_[4];
};
struct HeadNode02046b24;
struct SubBgControlBackup02074b64 { unsigned char registers[0x14]; };
struct BackgroundGraphics;
struct PacRecord;
struct Input_0208cb08 {
    unsigned char padding[0x1c];
    unsigned char flags;
    unsigned char padding_0x1d[3];
};
struct Struct_0208cb08_4 {
    SafeAllocator unknown_0_;
    SafeAllocator unknown_14_;
    unsigned char unknown_28_[0x14];
    SafeAllocator unknown_3c_;
};
struct Struct_0208cb08_5 {
    Struct_0208cb08_4* unknown_0_;
    unsigned char unknown_4_[0x28];
    Struct_02074b64 unknown_2c_;
    Struct_0208cb08_3 unknown_40_;
    unsigned char unknown_60_[0x40];
    void* unknown_a0_;
    unsigned char unknown_a4_[8];
    unsigned short unknown_ac_;
    unsigned char unknown_ae_[2];
    unsigned char unknown_b0_;
    unsigned char unknown_b1_[3];
    char* unknown_b4_;
    unsigned int unknown_b8_;
    int unknown_bc_;
    unsigned char unknown_c0_[0x12];
    short unknown_d2_;
    unsigned char unknown_d4_, unknown_d5_, unknown_d6_;
    unsigned char unknown_d7_[3];
    unsigned short unknown_da_;
};
unsigned int* GlobalFlags_GetInstance();
void FlagWord_SetBits(unsigned int*, unsigned int);
int GetHeadNodeIdOrMinusOne(HeadNode02046b24**);
void BackupSubBgControlRegisters(SubBgControlBackup02074b64*);
void OrGlobalFlag0x40_020dc2bc();
void SetSubBrightness(GameResources*, int, int);
int IsSubBrightnessTransitionActive(GameResources*);
void Background_SetMapSize(unsigned char*, int);
void Background_AllocateMap(BackgroundGraphics*, SafeAllocator*);
void Background_AllocateScreens(BackgroundGraphics*, int, SafeAllocator*);
void Background_SetScroll(BackgroundGraphics*, int, int);
void SetSubBg0Control0208c9cc(int, int, int, int, int);
int Pac_CountFiles(PacRecord*);
void* Pac_GetFile(PacRecord*, int, void**, int*);
void WrapAddByteField0x22_0205aed0(void*, char*, unsigned int, int);
extern "C" void Background_SetPriority(void*, int);
extern "C" int SpriteContext_LoadFile(void*, void*, int, int);
extern "C" void KeyTable_Load(void*, SafeAllocator*, void*, unsigned int);
extern "C" void func_0208bf78(Object_0208cb08*);
extern char data_020f11a2[], data_020f11b3[], data_020f11c0[], data_020f11da[];

#if defined(jpn)
extern char data_020f129e[], data_020f12b2[];
#endif

// USA: func_0208cb08
extern "C" ARM void func_0208cb08(Object_0208cb08* object) {
    if (object->target < 0) return;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    GameResources* resources = GameState::GetInstance()->GetResources();
    if (object->state == 0) {
        SetFlags00(resources, 0x6000);
        FlagWord_SetBits(GlobalFlags_GetInstance(), 1);
        FontBankLoader* global = FontBankLoader_GetInstance();
        int notification = 0x67;
        if (GetHeadNodeIdOrMinusOne((HeadNode02046b24**)resources->fieldTaskQueue_) != 0x2d) {
            if (object->target < 0) notification = 0x32;
            else {
                int var4 = arg0->unknown_d2_ / 20;
                if (var4 > 9) var4 = 9;
                var3 = var4 + 0x32;
            }
        }
        BlankFunction02094b30(global, notification, 0);
        ++object->state;
    } else if (object->state == 1) {
        if (AlwaysTrue02094b4c(FontBankLoader_GetInstance())) ++object->state;
    } else if (object->state == 2) {
        BackupSubBgControlRegisters(&object->backup);
        OrGlobalFlag0x40_020dc2bc();
        if (!(object->flags & 0x10)) SetSubBrightness(resources, -16, 8);
        ++object->state;
    } else if (object->state == 3) {
        if (IsSubBrightnessTransitionActive(resources)) return;
        Arena_0208cb08* arena = object->arena;
        arena->inputAllocator.Reset();
        Background_SetMapSize((unsigned char*)&object->input, 0);
        object->input.flags = (object->input.flags & ~0xf) | 1;
        object->input.flags &= ~0xf0;
        Background_SetPriority(&object->input, 0);
        Background_AllocateMap((BackgroundGraphics*)&object->input, &arena->inputAllocator);
        Background_AllocateScreens((BackgroundGraphics*)&object->input, 1, &arena->inputAllocator);
        Background_SetScroll((BackgroundGraphics*)&object->input, 0, 0);
        SetSubBg0Control0208c9cc(0, 0, 15, 0, 0);
        object->pending = 1;
        object->source = object->filename;
        object->format = 3;
#if defined(jpn)
        arg0->unknown_bc_ = var0->QueueLoadFile(data_020f129e, 0);
#else
        arg0->unknown_bc_ = var0->QueueLoadFileInGP2(data_020f11a2, data_020f11b3, 0);
#endif
        ++object->state;
    } else if (object->state == 4) {
        if (!loader->GetTaskStatus(object->taskId)) return;
        Arena_0208cb08* arena = object->arena;
        arena->resourceAllocator.Reset();
        void* record;
        void* file;
        unsigned int length;
        loader->GetLoadedFileByID(object->taskId, &file, &length);
        int count = Pac_CountFiles((PacRecord*)file);
        int index = 0;
        int size;
        for (; index < count; ++index) {
            void* data = Pac_GetFile((PacRecord*)file, index, &record, &size);
            SpriteContext_LoadFile(object->resource, data, size, (int)&arena->resourceAllocator);
        }
        func_0205aed0(arg0->unknown_60_, arg0->unknown_b4_, 3, 0x40);
        var0->RemoveTask(arg0->unknown_bc_);
        arg0->unknown_bc_ = -1;
        ++arg0->unknown_d5_;
    } else if (arg0->unknown_d5_ == 5) {
#if defined(jpn)
        arg0->unknown_bc_ = var0->QueueLoadFile(data_020f12b2, 0);
#else
        arg0->unknown_bc_ = var0->QueueLoadFileInGP2(data_020f11c0, data_020f11da, 0);
#endif
        ++object->state;
    } else if (object->state == 6) {
        if (!loader->GetTaskStatus(object->taskId)) return;
        Arena_0208cb08* arena = object->arena;
        void* file;
        unsigned int length;
        loader->GetLoadedFileByID(object->taskId, &file, &length);
        if (arena) {
            arena->fileAllocator.Reset();
            KeyTable_Load(object->container, &arena->fileAllocator, file, length);
        }
        loader->RemoveTask(object->taskId);
        object->taskId = -1;
        ++object->state;
    } else if (object->state == 7) {
        func_0208bf78(object);
        ++object->state;
    } else if (object->state == 8) {
        if (!object->mode) {
            REG_SUB_BG_0208cb08.backgrounds[0] &= ~3;
            REG_SUB_BG_0208cb08.backgrounds[1] = (REG_SUB_BG_0208cb08.backgrounds[1] & ~3) | 2;
            REG_SUB_BG_0208cb08.backgrounds[2] = (REG_SUB_BG_0208cb08.backgrounds[2] & ~3) | 3;
            REG_SUB_BG_0208cb08.backgrounds[3] = (REG_SUB_BG_0208cb08.backgrounds[3] & ~3) | 1;
            REG_SUB_BG_0208cb08.display = (REG_SUB_BG_0208cb08.display & ~0x1f00) | 0x1900;
            if (GetHeadNodeIdOrMinusOne((HeadNode02046b24**)resources->fieldTaskQueue_) == 0x2d) {
                if (!IsSubBrightnessTransitionActive(resources)) SetSubBrightness(resources, 0, 25);
            } else if (!(object->flags & 0x10)) SetSubBrightness(resources, 0, 8);
            ++object->state;
        } else func_0208bf78(object);
    } else if (object->state == 9) {
        if (!IsSubBrightnessTransitionActive(resources)) {
            object->complete = 1;
            object->state = 0;
        }
    }
}
