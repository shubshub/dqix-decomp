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

void SetByte0x5cdaAndClearField0xa_020120d4(unsigned char* obj, unsigned char value);
extern "C" void func_0208ec04(struct Struct0208e9f4*);
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
    unsigned int unknown_3_1_ : 4;
    unsigned int unknown_3_5_ : 2;
    unsigned int unknown_3_7_ : 1;
};

struct Struct_0208ea10 {
    union {
        unsigned int unknown_0_;
        struct Struct_0208ea10_3 unknown1_0_;
    } unknown_0_;
};

// USA: func_0208ea10
extern "C" ARM void func_0208ea10(void* arg0, int arg1) {
    char var0[0x430];
    char var1[0x430];
    char var2[0x40];
    unsigned int var3;
    unsigned int var4;
    const void* var5;

    unsigned char* var6 = (unsigned char*)GameState::GetInstance();

    if (var6[Enum_0208ea10_23770] == 8) {
        func_0208e9f4((struct Struct_0208e9f4*)arg0);
        func_020120d4(var6, rand() % 8);
    } else {
        func_0208ec04((struct Struct_0208e9f4*)arg0);
        return;
    }

    BackgroundLoader::AddLockGlobal();
    __clear(var2, 0x40);
    var3 = 0;

    if (LoadFileIntoMemory(data_020f1330, g_fileLoadBuffer, &fileLen) != 0) {
        if (GetFileInNarc(g_fileLoadBuffer, data_020f134a, &ptr, &size, 0) != 0) {
            ((Script*)((struct ResetStruct0208ea10*)scriptFirst))->Initialize();
            ((Script*)((struct ResetStruct0208ea10*)scriptFirst))->SetOpcodeLookup((Script::OpcodeLookupEntry*)&data_020f1308);
            ((Script*)((struct ResetStruct0208ea10*)scriptFirst))->Load(ptr, size);
            ((Script*)((struct ResetStruct0208ea10*)scriptFirst))->Execute();
            ((unsigned char*)LootPointList_GetInstance())[0xa] = 1;
        }

        int i;
        for (i = 1; i <= 0x3f; i++) {
            sprintf(name, data_020f1356, i);
            fileLen = 0;
            if (GetFileInNarc(g_fileLoadBuffer, name, &ptr, &size, 0) != 0) {
                ((Script*)((struct ResetStruct0208ea10*)scriptLoop))->Initialize();
                ((Script*)((struct ResetStruct0208ea10*)scriptLoop))->SetOpcodeLookup((Script::OpcodeLookupEntry*)&data_020f1308);
                ((Script*)((struct ResetStruct0208ea10*)scriptLoop))->Load(ptr, size);
                ((Script*)((struct ResetStruct0208ea10*)scriptLoop))->Execute();
            }
        }

        int var8;
        for (var8 = 0; var8 < 2; var8++) {
            struct Struct_0208ea10* var9 = &((struct Struct_0208ea10*)(var6 + Enum_0208ea10_23772))[var8 + 0x62];
            var9->unknown_0_.unknown1_0_.unknown_3_7_ = 1;
            var9->unknown_0_.unknown1_0_.unknown_3_1_ = 2;
            var9->unknown_0_.unknown1_0_.unknown_1_1_ = 1;
            var9->unknown_0_.unknown1_0_.unknown_1_5_ = 1;
            var9->unknown_0_.unknown1_0_.unknown_3_5_ = 1;
            var9->unknown_0_.unknown1_0_.unknown_0_0_ = 0;
            var9->unknown_0_.unknown_0_ &= 0xfe01ffff;
        }
    }

    BackgroundLoader::RemoveLockGlobal();
}
