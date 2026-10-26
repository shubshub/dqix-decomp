#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"

extern "C" void* func_ov011_021849c8(void* ctx);
extern "C" int func_ov023_021f6bb8(void* obj);
extern "C" void func_ov023_021f6bb0(void* obj, int v);

extern char data_ov023_021fe5ec;

struct Struct_ov023_021f75d0 {
    char pad0[0x10];
    char* field10;
    char pad1[8];
    int field1c;
    char pad2[4];
    char* field24;
};

// USA: func_ov023_021f75d0
#if defined(jpn)
extern char data_ov023_021fd8b8;

extern "C" ARM int func_ov023_021f75d0(struct Struct_ov023_021f75d0* obj, void* ctx) {
    void* node = func_ov011_021849c8(ctx);
    if (obj->field10 == 0) return 1;
    if (func_ov023_021f6bb8(node) >= 0) {
        return obj->field1c;
    }
    int var1 = (int)BackgroundLoader::GetInstance();
    char buf[0x50];
    sprintf(buf, &data_ov023_021fd8b8, obj->field10);
    int result = ((BackgroundLoader*)(var1))->QueueLoadFile((const char*)((int)buf), (SafeAllocator*)(0));
    func_ov023_021f6bb0(node, result);
    return 1;
}
#else
extern "C" ARM int func_ov023_021f75d0(struct Struct_ov023_021f75d0* obj, void* ctx) {
    void* node = func_ov011_021849c8(ctx);
    if (obj->field10 == 0) return 1;
    int key = func_ov023_021f6bb8(node);
    if (key < 0) {
        int var6 = (int)BackgroundLoader::GetInstance();
        char buf[0x50];
        int result;
        if (obj->field24 != 0) {
            sprintf(buf, &data_ov023_021fe5ec, obj->field24);
        } else {
            sprintf(buf, &data_ov023_021fe5ec, obj->field10);
        }
        if (obj->field24 != 0) {
            result = ((BackgroundLoader*)(var6))->QueueLoadFileInGP2((const char*)((int)buf), (const char*)((int)obj->field10), (SafeAllocator*)(0));
        } else {
            result = ((BackgroundLoader*)(var6))->QueueLoadFile((const char*)((int)buf), (SafeAllocator*)(0));
        }
        func_ov023_021f6bb0(node, result);
        return 1;
    }
    return obj->field1c;
}
#endif
