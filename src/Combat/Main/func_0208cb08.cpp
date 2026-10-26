#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "Resource/Brightness.h"

#define REG_SUB_BG_0208cb08 (*(volatile Struct_0208cb08_2*)0x04001000)
struct Struct_0208cb08_2 {
    unsigned int display;
    unsigned int unknown_4_;
    unsigned short backgrounds[4];
};
struct HeadNode02046b24;
struct Struct_02074b64 { unsigned char unknown_0_[0x14]; };
struct BackgroundGraphics;
struct PacRecord;
struct Struct_0208cb08_3 {
    unsigned char padding[0x1c];
    unsigned char flags;
    unsigned char unknown_1d_[3];
};
struct Struct_0208cb08_4 {
    SafeAllocator fileAllocator;
    SafeAllocator inputAllocator;
    unsigned char padding[0x14];
    SafeAllocator resourceAllocator;
};
struct Struct_0208cb08_5 {
    Struct_0208cb08_4* arena;
    unsigned char container[0x28];
    Struct_02074b64 backup;
    Struct_0208cb08_3 input;
    unsigned char resource[0x40];
    void* source;
    unsigned char unknown_a4_[8];
    unsigned short format;
    unsigned char unknown_ae_[2];
    unsigned char pending;
    unsigned char unknown_b1_[3];
    char* filename;
    unsigned int unknown_b8_;
    int taskId;
    unsigned char unknown_c0_[0x12];
    short target;
    unsigned char unknown_d4_, state, mode;
    unsigned char unknown_d7_[3];
    unsigned short flags;
};
extern "C" unsigned int* GlobalFlags_GetInstance();
extern "C" void FlagWord_SetBits(unsigned int*, unsigned int);
extern "C" int FieldTaskQueue_GetCurrentKind(HeadNode02046b24**);
extern "C" void func_02074b64(Struct_02074b64*);
extern "C" void func_020dc2bc();
void SetSubBrightness(GameResources*, int, int);
int IsSubBrightnessTransitionActive(GameResources*);
extern "C" void Background_SetMapSize(unsigned char*, int);
extern "C" void Background_AllocateMap(BackgroundGraphics*, SafeAllocator*);
extern "C" void Background_AllocateScreens(BackgroundGraphics*, int, SafeAllocator*);
extern "C" void Background_SetScroll(BackgroundGraphics*, int, int);
extern "C" void func_0208c9cc(int, int, int, int, int);
extern "C" int Pac_CountFiles(PacRecord*);
extern "C" void* Pac_GetFile(PacRecord*, int, void**, int*);
extern "C" void func_0205aed0(void*, char*, unsigned int, int);
extern "C" void Background_SetPriority(void*, int);
extern "C" int SpriteContext_LoadFile(void*, void*, int, int);
extern "C" void KeyTable_Load(void*, SafeAllocator*, void*, unsigned int);
extern "C" void func_0208bf78(Struct_0208cb08_5*);
extern char data_020f11a2[], data_020f11b3[], data_020f11c0[], data_020f11da[];

#if defined(jpn)
extern char data_020f129e[], data_020f12b2[];
#endif

// USA: func_0208cb08
extern "C" ARM void func_0208cb08(Struct_0208cb08_5* object) {
    if (object->target < 0) return;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    GameResources* resources = GameState::GetInstance()->GetResources();
    if (object->state == 0) {
        SetFlags00(resources, 0x6000);
        FlagWord_SetBits(GlobalFlags_GetInstance(), 1);
        FontBankLoader* global = FontBankLoader_GetInstance();
        int var3 = 0x67;
        if (FieldTaskQueue_GetCurrentKind((HeadNode02046b24**)resources->fieldTaskQueue_) != 0x2d) {
            if (object->target < 0) var3 = 0x32;
            else {
                int level = object->target / 20;
                if (level > 9) level = 9;
                var3 = level + 0x32;
            }
        }
        func_02094b30(global, var3, 0);
        ++object->state;
    } else if (object->state == 1) {
        if (func_02094b4c(FontBankLoader_GetInstance())) ++object->state;
    } else if (object->state == 2) {
        func_02074b64(&object->backup);
        func_020dc2bc();
        if (!(object->flags & 0x10)) SetSubBrightness(resources, -16, 8);
        ++object->state;
    } else if (object->state == 3) {
        if (IsSubBrightnessTransitionActive(resources)) return;
        Struct_0208cb08_4* arena = object->arena;
        arena->inputAllocator.Reset();
        Background_SetMapSize((unsigned char*)&object->input, 0);
        object->input.flags = (object->input.flags & ~0xf) | 1;
        object->input.flags &= ~0xf0;
        Background_SetPriority(&object->input, 0);
        Background_AllocateMap((BackgroundGraphics*)&object->input, &arena->inputAllocator);
        Background_AllocateScreens((BackgroundGraphics*)&object->input, 1, &arena->inputAllocator);
        Background_SetScroll((BackgroundGraphics*)&object->input, 0, 0);
        func_0208c9cc(0, 0, 15, 0, 0);
        object->pending = 1;
        object->source = object->filename;
        object->format = 3;
#if defined(jpn)
        object->taskId = loader->QueueLoadFile(data_020f129e, 0);
#else
        object->taskId = loader->QueueLoadFileInGP2(data_020f11a2, data_020f11b3, 0);
#endif
        ++object->state;
    } else if (object->state == 4) {
        if (!loader->GetTaskStatus(object->taskId)) return;
        Struct_0208cb08_4* arena = object->arena;
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
        func_0205aed0(object->resource, object->filename, 3, 0x40);
        loader->RemoveTask(object->taskId);
        object->taskId = -1;
        ++object->state;
    } else if (object->state == 5) {
#if defined(jpn)
        object->taskId = loader->QueueLoadFile(data_020f12b2, 0);
#else
        object->taskId = loader->QueueLoadFileInGP2(data_020f11c0, data_020f11da, 0);
#endif
        ++object->state;
    } else if (object->state == 6) {
        if (!loader->GetTaskStatus(object->taskId)) return;
        Struct_0208cb08_4* arena = object->arena;
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
            if (FieldTaskQueue_GetCurrentKind((HeadNode02046b24**)resources->fieldTaskQueue_) == 0x2d) {
                if (!IsSubBrightnessTransitionActive(resources)) SetSubBrightness(resources, 0, 25);
            } else if (!(object->flags & 0x10)) SetSubBrightness(resources, 0, 8);
            ++object->state;
        } else func_0208bf78(object);
    } else if (object->state == 9) {
        if (!IsSubBrightnessTransitionActive(resources)) {
            object->unknown_d4_ = 1;
            object->state = 0;
        }
    }
}
