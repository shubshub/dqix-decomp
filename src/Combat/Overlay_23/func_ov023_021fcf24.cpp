#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

extern "C" void* func_ov011_021849c8(void* ctx);

struct Struct_020534ac_2;

struct Struct_020534ac;

extern "C" {
    int func_ov023_021f6bb8(void* obj);
    void func_ov023_021f6bb0(void* obj, int v);
    void func_ov023_021fd120(void* obj, void* ctx, int p2, int p3);
}

struct Struct_ov023_021fcf24 {
    char pad[0x1c];
    int field1c;
};

// USA: func_ov023_021fcf24
extern "C" ARM int func_ov023_021fcf24(struct Struct_ov023_021fcf24* obj, void* ctx) {
    void* node = func_ov011_021849c8(ctx);
    int var1 = (int)BackgroundLoader::GetInstance();
    int key = func_ov023_021f6bb8(node);
    if (((BackgroundLoader*)(var1))->GetTaskStatus((int)(key))) {
        if (((BackgroundLoader*)((struct Struct_020534ac_2*)var1))->GetDetailedTaskStatus((int)(key)) == 2) {
            int v1, v2;
            ((BackgroundLoader*)((struct Struct_020534ac*)var1))->GetLoadedFileByID((int)(key), (void**)(&v1), (unsigned int*)(&v2));
            func_ov023_021fd120(obj, ctx, v1, v2);
        }

        ((BackgroundLoader*)(var1))->RemoveTask((int)(key));
        func_ov023_021f6bb0(node, -1);
        return 2;
    }
    return obj->field1c;
}
