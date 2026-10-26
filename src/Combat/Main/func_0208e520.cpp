#include <globaldefs.h>
#include "std_library_functions.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "Resource/Script.h"

#if defined(jpn)
#define data_020f12bf data_020f138f
#define data_020f12d3 data_020f13a3
#define data_020f12e1 data_020f13b1
#define data_020f12fb data_020f13cb
#define data_020f1278 data_020f1348
#define data_020f1290 data_020f1360
#endif

extern "C" void __clear(void* buf, int count);
extern "C" int memcmp(const void* a, const void* b, unsigned int length);

extern char data_020f12b8[];
extern char data_020f12bf[];
extern char data_020f12d3[];
extern char data_020f12e1[];
extern char data_020f12fb[];
extern Script::OpcodeLookupEntry data_020f1278[];
extern Script::OpcodeLookupEntry data_020f1290[];

struct Struct_0208e4f8 {
    char field0[4];
    int field4;
    short field8;
    unsigned char fielda;
};

extern "C" void func_0208e4f8(struct Struct_0208e4f8*);

// USA: func_0208e520
extern "C" ARM void func_0208e520(struct Struct_0208e4f8* p, char* name) {
    char path[0x40];
    unsigned int len;
    char tag[4];
    unsigned int fileLen;
    const void* fileData;

    if (BackgroundLoader::GetInstance()->GetNumQueuedTasks() > 0) {
        return;
    }
    BackgroundLoader::AddLockGlobal();
    len = 0;
    if (memcmp(name, data_020f12b8, 6) == 0 && memcmp(name, p->field0, 3) != 0 &&
        LoadFileIntoMemory(data_020f12bf, g_fileLoadBuffer, &len)) {
        func_0208e4f8(p);
        Script scriptC;
        scriptC.Initialize();
        scriptC.SetOpcodeLookup(data_020f1278);
        scriptC.Load(g_fileLoadBuffer, len);
        scriptC.Execute();
        strncpy(p->field0, name, 3);
    }
    if (name[0] != 'F') {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    if (memcmp(name, p->field0, 3) == 0) {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    __clear(tag, 4);
    strncpy(tag, name, 3);
    __clear(path, 0x40);
    sprintf(path, data_020f12d3, tag);
    if (LoadFileIntoMemory(data_020f12e1, g_fileLoadBuffer, &len)) {
        if (p->fielda == 0 && GetFileInNarc(g_fileLoadBuffer, data_020f12fb, &fileData, &fileLen, 0)) {
            Script var6;
            var6.Initialize();
            var6.SetOpcodeLookup(data_020f1290);
            var6.Load(fileData, fileLen);
            var6.Execute();
            p->fielda = 1;
        }
        func_0208e4f8(p);
        if (GetFileInNarc(g_fileLoadBuffer, path, &fileData, &fileLen, 0)) {
            Script var7;
            var7.Initialize();
            var7.SetOpcodeLookup(data_020f1290);
            var7.Load(fileData, fileLen);
            var7.Execute();
        }
        strcpy(p->field0, tag);
    }
    BackgroundLoader::RemoveLockGlobal();
}
