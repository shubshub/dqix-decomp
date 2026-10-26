#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

extern "C" void* func_ov011_021849c8(void* ctx);
extern "C" int func_ov023_021f6bb8(void* obj);
extern "C" void func_ov023_021f6bb0(void* obj, int v);

struct Struct_020534ac_2;

struct Struct_020534ac;

extern "C" void* func_ov011_021845f8(void* ctx, int v);
extern "C" ARM void func_ov023_021e133c(void* a, void* b, int c, int d, int e, short f);

struct Struct_ov023_021fc30c {
    char pad0[0x8];
    unsigned short field8;
    char unknown_a_[0x1c - 0xa];
    int field1c;
};

// USA: func_ov023_021fc30c
extern "C" ARM int func_ov023_021fc30c(struct Struct_ov023_021fc30c* obj, void* ctx) {
    void* node = func_ov011_021849c8(ctx);
    int var1 = (int)BackgroundLoader::GetInstance();
    int key = func_ov023_021f6bb8(node);
    if (((BackgroundLoader*)(var1))->GetTaskStatus((int)(key))) {
        if (((BackgroundLoader*)((struct Struct_020534ac_2*)var1))->GetDetailedTaskStatus((int)(key)) == 2) {
            int v1, v2;
            ((BackgroundLoader*)((struct Struct_020534ac*)var1))->GetLoadedFileByID((int)(key), (void**)(&v1), (unsigned int*)(&v2));
            void* something = func_ov011_021845f8(ctx, obj->field8);
            if (something == 0) {
                ((BackgroundLoader*)(var1))->RemoveTask((int)(key));
                func_ov023_021f6bb0(node, -1);
                return 2;
            }
            func_ov023_021e133c((char*)obj + 0x20, (char*)something + 4, v1, v2, 0, 0);
        }
        ((BackgroundLoader*)(var1))->RemoveTask((int)(key));
        func_ov023_021f6bb0(node, -1);
        return 2;
    }
    return obj->field1c;
}
