#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

extern "C" int func_ov011_021849d8(void* p);

struct Struct_020534ac_2;

struct Struct_020534ac;

extern "C" char* func_020467c0(void* a, char* b, unsigned int* outSize);
extern "C" void func_ov023_021f7aac(void* obj, void* arg1, char* entry, unsigned int entryLength);

struct Struct_ov023_021f745c {
    char pad0[0x10];
    char* f10;
};

// USA: func_ov023_021f7a08
extern "C" ARM void func_ov023_021f7a08(struct Struct_ov023_021f745c* obj, void* keyObj) {
    void* var0 = (void*)(int)BackgroundLoader::GetInstance();
    int key = func_ov011_021849d8(keyObj);
    if (key < 0) {
        return;
    }
    if (!((BackgroundLoader*)(var0))->GetTaskStatus((int)(key))) {
        return;
    }
    if (((BackgroundLoader*)((struct Struct_020534ac_2*)var0))->GetDetailedTaskStatus((int)(key)) != 2) {
        return;
    }

    int out1, out2;
    ((BackgroundLoader*)((struct Struct_020534ac*)var0))->GetLoadedFileByID((int)(key), (void**)(&out1), (unsigned int*)(&out2));
    if (out1 == 0 || out2 == 0) {
        return;
    }

    unsigned int entryLength;
    char* entry = func_020467c0((void*)out1, obj->f10, &entryLength);
    if (entry == NULL) {
        return;
    }

    func_ov023_021f7aac(obj, keyObj, entry, entryLength);
}
