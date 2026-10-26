#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"

extern "C" int func_ov011_021849d8(void* p);

struct Struct_020534ac_2;

struct Struct_020534ac;

extern "C" char* func_020467c0(void* a, char* b, unsigned int* outSize);

extern "C" void func_ov023_021fb9c4(void* obj, void* keyObj, int out1, int out2);

struct Struct_ov023_021fb534 {
    char pad0[0x10];
    char* f10;
    char unknown_14_[0x1c - 0x14];
    int field1c;
};

// USA: func_ov023_021fb8dc
extern "C" ARM void func_ov023_021fb8dc(struct Struct_ov023_021fb534* obj, void* keyObj) {
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

    void* p;
    unsigned int n;
    if (GetFileInNarc((void*)out1, obj->f10, (const void**)&p, &n, 0)) {
        func_ov023_021fb9c4(obj, keyObj, out1, out2);
        obj->field1c = 2;
        return;
    }

    p = func_020467c0((void*)out1, obj->f10, &n);
    if (p == NULL) {
        return;
    }

    func_ov023_021fb9c4(obj, keyObj, out1, out2);
    obj->field1c = 2;
}
