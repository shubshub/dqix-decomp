#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "Resource/Script.h"

#if defined(jpn)
enum { Enum_0208ea10_23770 = 0x5a7a, Enum_0208ea10_23772 = 0x5a7c };
#else
enum { Enum_0208ea10_23770 = 0x5cda, Enum_0208ea10_23772 = 0x5cdc };
#endif

struct Struct_0208e9f4;
extern "C" void func_0208e9f4(struct Struct_0208e9f4*);

extern "C" void func_020120d4(unsigned char* obj, unsigned char value);
extern "C" void func_0208ec04(struct Struct_0208e9f4*);
extern "C" void* LootPointList_GetInstance(void);
extern "C" int rand(void);

struct Struct_0208ea10_2;

extern "C" void __clear(void*, int);
extern "C" int sprintf(char*, const char*, ...);

extern int data_020f1308;
extern char data_020f1330[];
extern char data_020f134a[];
extern char data_020f1356[];

struct Struct_0208ea10_3 {
    unsigned int unknown_0_0_ : 9;
    unsigned int unknown_1_1_ : 4;
    unsigned int unknown_1_5_ : 4;
    unsigned int unknown_2_1_ : 8;
    unsigned int type4 : 4;
    unsigned int kind : 2;
    unsigned int flag : 1;
};

struct Struct_0208ea10 {
    union {
        unsigned int raw;
        struct Struct_0208ea10_3 b;
    } u;
};

// USA: func_0208ea10
extern "C" ARM void func_0208ea10(void* p0, int a1) {
    char var0[0x430];
    char var1[0x430];
    char name[0x40];
    unsigned int fileLen;
    unsigned int size;
    const void* ptr;

    unsigned char* gs = (unsigned char*)GameState::GetInstance();

    if (gs[Enum_0208ea10_23770] == 8) {
        func_0208e9f4((struct Struct_0208e9f4*)p0);
        func_020120d4(gs, rand() % 8);
    } else {
        func_0208ec04((struct Struct_0208e9f4*)p0);
        return;
    }

    BackgroundLoader::AddLockGlobal();
    __clear(name, 0x40);
    fileLen = 0;

    if (LoadFileIntoMemory(data_020f1330, g_fileLoadBuffer, &fileLen) != 0) {
        if (GetFileInNarc(g_fileLoadBuffer, data_020f134a, &ptr, &size, 0) != 0) {
            ((Script*)((struct Struct_0208ea10_2*)var0))->Initialize();
            ((Script*)((struct Struct_0208ea10_2*)var0))->SetOpcodeLookup((Script::OpcodeLookupEntry*)&data_020f1308);
            ((Script*)((struct Struct_0208ea10_2*)var0))->Load(ptr, size);
            ((Script*)((struct Struct_0208ea10_2*)var0))->Execute();
            ((unsigned char*)LootPointList_GetInstance())[0xa] = 1;
        }

        int i;
        for (i = 1; i <= 0x3f; i++) {
            sprintf(name, data_020f1356, i);
            fileLen = 0;
            if (GetFileInNarc(g_fileLoadBuffer, name, &ptr, &size, 0) != 0) {
                ((Script*)((struct Struct_0208ea10_2*)var1))->Initialize();
                ((Script*)((struct Struct_0208ea10_2*)var1))->SetOpcodeLookup((Script::OpcodeLookupEntry*)&data_020f1308);
                ((Script*)((struct Struct_0208ea10_2*)var1))->Load(ptr, size);
                ((Script*)((struct Struct_0208ea10_2*)var1))->Execute();
            }
        }

        int j;
        for (j = 0; j < 2; j++) {
            struct Struct_0208ea10* e = &((struct Struct_0208ea10*)(gs + Enum_0208ea10_23772))[j + 0x62];
            e->u.b.flag = 1;
            e->u.b.type4 = 2;
            e->u.b.unknown_1_1_ = 1;
            e->u.b.unknown_1_5_ = 1;
            e->u.b.kind = 1;
            e->u.b.unknown_0_0_ = 0;
            e->u.raw &= 0xfe01ffff;
        }
    }

    BackgroundLoader::RemoveLockGlobal();
}
