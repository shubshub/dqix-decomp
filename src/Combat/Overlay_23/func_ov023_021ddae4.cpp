#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "Graphics/SpriteAffineTransform.h"

#if defined(jpn)
#define REGION(j,u) (j)
#else
#define REGION(j,u) (u)
#endif

struct Struct_ov023_021ddae4 {
    char unknown_0_[0x44];
    SafeAllocator* allocator;
    char unknown_48_[REGION(0x128,0x12c) - 0x48];
    SpriteContext0205ac40 renderer;
    char unknown_17d_[REGION(0x6f9,0x77d) - REGION(0x128,0x12c) - sizeof(SpriteContext0205ac40)];
    signed char displayState;
    signed char unknown_77e_;
    int task;
};

struct PacRecord;
extern "C" int Pac_CountFiles(PacRecord* entry);
extern "C" void* Pac_GetFile(PacRecord* rec, int index, void** out, int* out44);
extern "C" int SpriteContext_LoadFile(void* renderer, void* data, int kind, int allocator);

// USA: func_ov023_021ddae4
extern "C" ARM void func_ov023_021ddae4(void* obj) {
    Struct_ov023_021ddae4* view = (Struct_ov023_021ddae4*)obj;
    if (view->task < 0) return;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (!loader->GetTaskStatus(view->task)) return;
    view->allocator->Reset();
    void* record;
    void* file;
    unsigned int length;
    int kind;
    loader->GetLoadedFileByID(view->task, &file, &length);
#if !defined(jpn)
    if (file != 0 && length != 0)
#endif
    {
        int count = Pac_CountFiles((PacRecord*)file);
        for (int i = 0; i < count; i++) {
            void* data = Pac_GetFile((PacRecord*)file, i, &record, &kind);
            SpriteContext_LoadFile(&view->renderer, data, kind, (int)view->allocator);
        }
    }
    view->displayState = view->unknown_77e_;
    loader->RemoveTask(view->task);
    view->task = -1;
}
