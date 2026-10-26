#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"

#if defined(jpn)
enum { Enum_ov012_021861e0_19 = 17, kWidgetArrayOffset = 0x133c, Enum_ov012_021861e0_4960 = 0x1338, kContainerOffset = 0x1334, Enum_ov012_021861e0_5008 = 0x135c, kAllocatorOffset = 0x54 };
#else
enum { Enum_ov012_021861e0_19 = 19, kWidgetArrayOffset = 0x1364, Enum_ov012_021861e0_4960 = 0x1360, kContainerOffset = 0x135c, Enum_ov012_021861e0_5008 = 0x1390, kAllocatorOffset = 0x5c };
#endif

struct Struct0205a198;
extern "C" void Sprite_Init(Struct0205a198*);
struct ClearTarget0205a234;
extern "C" void func_0205a234(ClearTarget0205a234*);
extern "C" void SpriteContext_Init(char*);
struct PacRecord;
extern "C" int Pac_CountFiles(PacRecord*);
extern "C" void* Pac_GetFile(PacRecord*, int, void**, int*);
extern "C" void SpriteContext_LoadFile(void*, void*, int, void*);

// USA: func_ov012_021861e0
extern "C" ARM void func_ov012_021861e0(char* editor) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    for (unsigned char i = 0; i < Enum_ov012_021861e0_19; ++i)
        Sprite_Init((Struct0205a198*)(*(char**)(editor + kWidgetArrayOffset) + i * 0x28));
    func_0205a234(*(ClearTarget0205a234**)(editor + Enum_ov012_021861e0_4960));
    SpriteContext_Init(*(char**)(editor + kContainerOffset));
    *(unsigned char*)(*(char**)(editor + kContainerOffset) + 0x50) = 0;
    char* container = *(char**)(editor + kContainerOffset);
    *(void**)(container + 0x40) = *(void**)(editor + kWidgetArrayOffset);
    *(short*)(container + 0x4c) = Enum_ov012_021861e0_19;
    void* target = *(void**)(editor + Enum_ov012_021861e0_4960);
    char* var4 = *(char**)(editor + kContainerOffset);
    *(void**)(var4 + 0x3c) = target;

    void* recordOut;
    void* fileData;
    unsigned int fileSize;
    int fieldOut;
    loader->GetLoadedFileByID(*(int*)(editor + Enum_ov012_021861e0_5008), &fileData, &fileSize);
    int count = Pac_CountFiles((PacRecord*)fileData);
    ((SafeAllocator*)(editor + kAllocatorOffset))->Reset();
    for (int i = 0; i < count; ++i) {
        void* record = Pac_GetFile((PacRecord*)fileData, i, &recordOut, &fieldOut);
        SpriteContext_LoadFile(*(char**)(editor + kContainerOffset), record, fieldOut, editor + kAllocatorOffset);
    }
    loader->RemoveTask(*(int*)(editor + Enum_ov012_021861e0_5008));
    *(int*)(editor + Enum_ov012_021861e0_5008) = -1;
}
