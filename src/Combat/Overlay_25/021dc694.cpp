#include "Resource/ActionDataTables.h"
#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "std_library_functions.h"

#if defined(jpn)
enum { Enum_ov025_021dc694_680 = 0x224, Enum_ov025_021dc694_332 = 0x138, Enum_ov025_021dc694_668 = 0x218, Enum_ov025_021dc694_3756 = 0xe28, Enum_ov025_021dc694_22308 = 0x5914 };
#else
enum { Enum_ov025_021dc694_680 = 0x2a8, Enum_ov025_021dc694_332 = 0x14c, Enum_ov025_021dc694_668 = 0x29c, Enum_ov025_021dc694_3756 = 0xeac, Enum_ov025_021dc694_22308 = 0x5724 };
#endif

extern "C" void* func_ov000_02160f20(void* obj);
extern "C" void* func_02079e2c(char* p, int key);
extern "C" void func_ov025_021e88d8(void* obj);
extern "C" void func_ov025_021e8a40(char* obj, int a, int b);
extern "C" void func_ov025_021e8a4c(char* obj, int v);
extern "C" void func_ov025_021e8d20(void* obj, int v);
extern "C" void func_ov025_021db8d8(void* obj);
extern "C" void* func_ov000_02169a58(char* node, int value);

struct StreamHeader;
extern "C" ARM void func_ov000_0216d1c4(int arg0, struct StreamHeader* buffer, int length, int* out);

extern int data_ov025_021ef404;
extern char data_ov025_021ef454[];
extern "C" char _ZZ21inline_ov025_021dcf14vE1s[];

struct Struct_ov025_021dc694 {
    char pad0[4];
    unsigned int key : 12;
    char pad1[0x18 - 0x8];
    unsigned int : 5;
    unsigned int unknown_16_5_ : 7;
};

// USA: func_ov025_021dc694
extern "C" ARM void func_ov025_021dc694(void* arg) {
    char* obj = (char*)arg;
    void* slot = func_ov000_02160f20(obj);
    BackgroundLoader* loader = BackgroundLoader::GetInstance();

    if (loader->GetTaskStatus(data_ov025_021ef404) == 0) {
        return;
    }

    void* filePtr = 0;
    unsigned int fileLen = 0;
    loader->GetLoadedFileByID(data_ov025_021ef404, &filePtr, &fileLen);

    ActionDataTables* table = func_020797dc();
    struct Struct_ov025_021dc694* entry = (struct Struct_ov025_021dc694*)func_02079e2c((char*)table, *(short*)slot);

    if (filePtr != 0 && fileLen != 0 && entry != 0) {
        char pathBuf[0x50];
        sprintf(pathBuf, data_ov025_021ef454, entry->key);

        const void* var8 = 0;
        unsigned int var9 = 0;
        if (GetFileInNarc(filePtr, pathBuf, &var8, &var9, 0)) {
            int var10 = 0;
            func_ov000_0216d1c4((int)(obj + 0x30), (struct StreamHeader*)var8, var9, &var10);
            if (var10 != 0) {
                func_ov025_021e88d8(obj + Enum_ov025_021dc694_680);
                func_ov025_021e8a40(obj + Enum_ov025_021dc694_680, (int)(obj + 0x30), (int)(obj + Enum_ov025_021dc694_332));
                func_ov025_021e8a4c(obj + Enum_ov025_021dc694_680, *(int*)(obj + Enum_ov025_021dc694_668));
                func_ov025_021e8d20(obj + Enum_ov025_021dc694_680, var10);
                func_ov025_021db8d8(obj);
            }
        }
    }

    int status = *(int*)(obj + Enum_ov025_021dc694_3756);
    if (status != 3 && status != 2 && status != 6) {
        int var12 = entry->unknown_16_5_;
        int val = entry->key;
        if (var12 == 0xc) {
            val = 0x158;
        }
        char* node = *(char**)(obj + Enum_ov025_021dc694_22308);
        int var15 = (int)func_ov000_02169a58(node, val);
        if (var15 != 0) {
            func_ov025_021e88d8(obj + Enum_ov025_021dc694_680);
            func_ov025_021e8a40(obj + Enum_ov025_021dc694_680, (int)(obj + 0x30), (int)(obj + Enum_ov025_021dc694_332));
            func_ov025_021e8a4c(obj + Enum_ov025_021dc694_680, *(int*)(obj + Enum_ov025_021dc694_668));
            func_ov025_021e8d20(obj + Enum_ov025_021dc694_680, var15);
            func_ov025_021db8d8(obj);
        } else {
            *(int*)(obj + Enum_ov025_021dc694_3756) = 5;
            *(int*)(_ZZ21inline_ov025_021dcf14vE1s + 0x10) = 0;
            *(int*)(_ZZ21inline_ov025_021dcf14vE1s + 8) = 0;
        }
    }

    loader->RemoveTask(data_ov025_021ef404);
    data_ov025_021ef404 = -1;
}
