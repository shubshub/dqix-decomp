#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

extern "C" void* func_ov011_021849c8(void* ctx);
extern "C" int func_ov023_021f6bb8(void* obj);
extern "C" void func_ov023_021f6bb0(void* obj, int v);
struct Struct_020534ac_2;
struct Struct_020534ac;
extern "C" void func_ov023_021fa644(void* obj, void* arg1, char* entry, void* next);

struct Struct_ov023_021fa4c8 {
    char pad[0x1c];
    int field1c;
};

// USA: func_ov023_021fa4c8
extern "C" ARM int func_ov023_021fa4c8(struct Struct_ov023_021fa4c8* obj, void* ctx) {
    void* node = func_ov011_021849c8(ctx);
    int var1 = (int)BackgroundLoader::GetInstance();
    int key = func_ov023_021f6bb8(node);
    if (((BackgroundLoader*)(var1))->GetTaskStatus((int)(key))) {
        if (((BackgroundLoader*)((struct Struct_020534ac_2*)var1))->GetDetailedTaskStatus((int)(key)) == 2) {
            int v1, v2;
            ((BackgroundLoader*)((struct Struct_020534ac*)var1))->GetLoadedFileByID((int)(key), (void**)(&v1), (unsigned int*)(&v2));
            if (v1 != 0 && v2 != 0) {
                func_ov023_021fa644(obj, ctx, (char*)v1, (void*)v2);
            }
        }
        ((BackgroundLoader*)(var1))->RemoveTask((int)(key));
        func_ov023_021f6bb0(node, -1);
        return 2;
    }
    return obj->field1c;
}
