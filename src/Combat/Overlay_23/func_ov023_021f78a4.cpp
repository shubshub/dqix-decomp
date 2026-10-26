#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

extern "C" void* func_ov011_021849c8(void* ctx);
extern "C" int func_ov023_021f6bb8(void* obj);
extern "C" void func_ov023_021f6bb0(void* obj, int v);

struct Struct_020534ac_2;

struct Struct_020534ac;

extern "C" void func_ov023_021f7b98(void* obj, void* ctx, int flag, int v1, unsigned int entryLength);
extern "C" void Background_TransferMap(void* p, int flag);

struct Struct_ov023_021f78a4 {
    char pad0[0xc];
    unsigned char unknown_c_;
    char pad0d[0x1c - 0xd];
    int field1c;
    void* field20;
};

// USA: func_ov023_021f78a4
extern "C" ARM void func_ov023_021f78a4(struct Struct_ov023_021f78a4* obj) {
#if defined(jpn)
 enum {regionalOffset=0x24};
#else
 enum {regionalOffset=0x28};
#endif
    if (obj->unknown_c_ & 0x2) {
        void* ctx = obj->field20;
        void* node = func_ov011_021849c8(ctx);
        int var2 = (int)BackgroundLoader::GetInstance();
        int key = func_ov023_021f6bb8(node);
        if (((BackgroundLoader*)(var2))->GetTaskStatus((int)(key))) {
            if (((BackgroundLoader*)((struct Struct_020534ac_2*)var2))->GetDetailedTaskStatus((int)(key)) == 2) {
                int v1, v2;
                ((BackgroundLoader*)((struct Struct_020534ac*)var2))->GetLoadedFileByID((int)(key), (void**)(&v1), (unsigned int*)(&v2));
                if (v1 != 0 && v2 != 0) {
                    func_ov023_021f7b98(obj, ctx, 0, v1, v2);
                }
            }
            ((BackgroundLoader*)(var2))->RemoveTask((int)(key));
            func_ov023_021f6bb0(node, -1);
            obj->field1c = 2;
        }
    }

    if (!(obj->unknown_c_ & 0x1)) {
        Background_TransferMap((char*)obj + regionalOffset, 0);
    }
}
