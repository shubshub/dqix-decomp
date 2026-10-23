#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"


struct Struct0205a198;
void Sprite_Init(struct Struct0205a198* p);

void SpriteContext_Init(char* obj);

struct Struct_020534ac;

struct ActiveEntry02046900;
int Pac_CountFiles(struct ActiveEntry02046900* entry);

struct Rec020467f0;
void* Pac_GetFile(struct Rec020467f0* rec, int index, void** out, int* out44);

extern "C" void SpriteContext_LoadFile(void* a, void* ptr, int val, void* d);

// USA: func_ov012_021862fc
extern "C" ARM void func_ov012_021862fc(char* arg0) {
    int var0 = (int)BackgroundLoader::GetInstance();

    for (int i = 0; i < 3; i++) {
        Sprite_Init((struct Struct0205a198*)(*(char**)(self + 0x1000 + 0x36c) + i * 0x28));
    }

    SpriteContext_Init(*(char**)(self + 0x1000 + 0x368));

    *(unsigned char*)(*(char**)(arg0 + 0x1000 + 0x368) + 0x50) = 1;

    char* var2 = *(char**)(arg0 + 0x1000 + 0x368);
    *(int*)(var2 + 0x40) = *(int*)(arg0 + 0x1000 + 0x36c);
    *(short*)(var2 + 0x4c) = 3;

    void* var3;
    int var4;
    int var5;
    int var6;
    ((BackgroundLoader*)((struct Struct_020534ac*)var0))->GetLoadedFileByID((int)(*(int*)(arg0 + 0x1000 + 0x394)), (void**)(&var4), (unsigned int*)(&var5));

    int count = Pac_CountFiles((struct ActiveEntry02046900*)out1);
    ((SafeAllocator*)(self + 0x98))->Reset();

    for (int i = 0; i < count; i++) {
        void* result = Pac_GetFile((struct Rec020467f0*)out1, i, &recOut, &fieldOut);
        SpriteContext_LoadFile(*(char**)(self + 0x1000 + 0x368), result, fieldOut, self + 0x98);
    }

    ((BackgroundLoader*)(var0))->RemoveTask((int)(*(int*)(arg0 + 0x1000 + 0x394)));
    *(int*)(arg0 + 0x1000 + 0x394) = -1;
}
