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
    SafeAllocator* unknown_44_;
    char unknown_48_[REGION(0x128,0x12c) - 0x48];
    Struct_0205ac40 unknown_12c_;
    char unknown_17d_[REGION(0x6f9,0x77d) - REGION(0x128,0x12c) - sizeof(Struct_0205ac40)];
    signed char unknown_77d_;
    signed char unknown_77e_;
    int unknown_780_;
};

struct PacRecord;
int Pac_CountFiles(PacRecord* entry);
void* Pac_GetFile(PacRecord* rec, int index, void** out, int* out44);
extern "C" int SpriteContext_LoadFile(void* renderer, void* data, int kind, int allocator);

// USA: func_ov023_021ddae4
extern "C" ARM void func_ov023_021ddae4(void* arg0) {
    Struct_ov023_021ddae4* var0 = (Struct_ov023_021ddae4*)arg0;
    if (var0->unknown_780_ < 0) return;
    BackgroundLoader* var1 = BackgroundLoader::GetInstance();
    if (!var1->GetTaskStatus(var0->unknown_780_)) return;
    var0->unknown_44_->Reset();
    void* var2;
    void* var3;
    unsigned int var4;
    int var5;
    var1->GetLoadedFileByID(var0->unknown_780_, &var3, &var4);
#if !defined(jpn)
    if (var3 != 0 && var4 != 0)
#endif
    {
        int count = Pac_CountFiles((PacRecord*)file);
        for (int i = 0; i < count; i++) {
            void* data = Pac_GetFile((PacRecord*)file, i, &record, &kind);
            SpriteContext_LoadFile(&view->renderer, data, kind, (int)view->allocator);
        }
    }
    var0->unknown_77d_ = var0->unknown_77e_;
    var1->RemoveTask(var0->unknown_780_);
    var0->unknown_780_ = -1;
}
