#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"


struct Struct0205a198;
extern "C" void Sprite_Init(struct Struct0205a198* p);

extern "C" void SpriteContext_Init(char* obj);

struct Struct_020534ac;

struct PacRecord;
extern "C" int Pac_CountFiles(struct PacRecord* entry);

extern "C" void* Pac_GetFile(struct PacRecord* rec, int index, void** out, int* out44);

extern "C" void SpriteContext_LoadFile(void* a, void* ptr, int val, void* d);

// USA: func_ov012_021862fc
extern "C" ARM void func_ov012_021862fc(char* self) {
    int var0 = (int)BackgroundLoader::GetInstance();

    for (int i = 0; i < 3; i++) {
        Sprite_Init((struct Struct0205a198*)(*(char**)(self + 0x1000 + 0x36c) + i * 0x28));
    }

    SpriteContext_Init(*(char**)(self + 0x1000 + 0x368));

    *(unsigned char*)(*(char**)(self + 0x1000 + 0x368) + 0x50) = 1;

    char* p1 = *(char**)(self + 0x1000 + 0x368);
    *(int*)(p1 + 0x40) = *(int*)(self + 0x1000 + 0x36c);
    *(short*)(p1 + 0x4c) = 3;

    void* recOut;
    int out1;
    int out2;
    int fieldOut;
    ((BackgroundLoader*)((struct Struct_020534ac*)var0))->GetLoadedFileByID((int)(*(int*)(self + 0x1000 + 0x394)), (void**)(&out1), (unsigned int*)(&out2));

    int count = Pac_CountFiles((struct PacRecord*)out1);
    ((SafeAllocator*)(self + 0x98))->Reset();

    for (int i = 0; i < count; i++) {
        void* result = Pac_GetFile((struct PacRecord*)out1, i, &recOut, &fieldOut);
        SpriteContext_LoadFile(*(char**)(self + 0x1000 + 0x368), result, fieldOut, self + 0x98);
    }

    ((BackgroundLoader*)(var0))->RemoveTask((int)(*(int*)(self + 0x1000 + 0x394)));
    *(int*)(self + 0x1000 + 0x394) = -1;
}
