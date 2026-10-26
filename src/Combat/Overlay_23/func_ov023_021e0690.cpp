#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"

struct Struct_020534ac;
struct Container020e0310;
extern "C" int KeyTable_Get(struct Container020e0310*, int);
extern "C" char* func_020e046c(char* buf, void* b, void* c, int idx);
extern "C" void func_020df83c(void* p);
struct Struct020dfc40;
extern "C" void KeyTable_Destroy(struct Struct020dfc40* p);

extern "C" {
    void func_ov023_021ddf5c(void* obj);
    void func_ov023_021df218(void* obj);
    void func_ov023_021df558(void* obj);
}

struct Struct_ov023_021ff9e0_14 {
    unsigned char pad[0x14];
    struct Container020e0310* field14;
};
extern struct Struct_ov023_021ff9e0_14 data_ov023_021ff9e0;

struct Struct_ov023_021e0690 {
    unsigned int unknown_0_0_ : 4;
};

#if defined(jpn)
extern char data_ov023_021fcf09[];
#endif
// USA: func_ov023_021e0690
extern "C" ARM int func_ov023_021e0690(void* obj_) {
#if defined(jpn)
 enum {regionalOffset0=0x6f0, regionalOffset1=0x62c, regionalOffset2=0x80, regionalOffset3=0x6bc, regionalOffset4=0x6ec};
#else
 enum {regionalOffset0=0x774, regionalOffset1=0x630, regionalOffset2=0x100, regionalOffset3=0x740, regionalOffset4=0x770};
#endif
#if defined(jpn)
    int var1 = (int)BackgroundLoader::GetInstance();
    char* obj = (char*)obj_;
#else
    char* obj = (char*)obj_;
    int var1 = (int)BackgroundLoader::GetInstance();
#endif

    unsigned short flags = *(unsigned short*)(obj + regionalOffset0);
    if ((flags & 0x1000) || ((BackgroundLoader*)(var1))->GetTaskStatus((int)(*(int*)(obj + regionalOffset3)))) {
        memset(obj + regionalOffset1, 0, regionalOffset2);
        flags = *(unsigned short*)(obj + regionalOffset0);
        if (flags & 0x1000) {
#if defined(jpn)
            strcpy(obj + regionalOffset1, data_ov023_021fcf09);
#else
            char* s = (char*)KeyTable_Get(data_ov023_021ff9e0.field14, 0x29);
            strcpy(obj + regionalOffset1, s);
#endif

        } else {
            int out1, out2;
            ((BackgroundLoader*)((struct Struct_020534ac*)var1))->GetLoadedFileByID((int)(*(int*)(obj + regionalOffset3)), (void**)(&out1), (unsigned int*)(&out2));
#if defined(jpn)
            {
#else
            if (out1 != 0 && out2 != 0) {
#endif

                int v = *(short*)(obj + regionalOffset4);
                func_020e046c(obj + regionalOffset1, (void*)out1, (void*)out2, v);
            }
            ((BackgroundLoader*)(var1))->RemoveTask((int)(*(int*)(obj + regionalOffset3)));
            *(int*)(obj + regionalOffset3) = -1;
        }

        func_020df83c(obj + 0x6c);
        KeyTable_Destroy((struct Struct020dfc40*)(obj + 0x8c));
        func_020df83c(obj + 0x7c);
        KeyTable_Destroy((struct Struct020dfc40*)(obj + 0xa4));

        void* p = *(void**)(obj + 0x4c);
        if (p == NULL) {
            return -1;
        }

        struct Struct_ov023_021e0690* var8 = (struct Struct_ov023_021e0690*)((char*)p + 8);
        int cond = (var8->unknown_0_0_ <= 7) ? 1 : 0;
        if (cond) {
            func_ov023_021ddf5c(obj);
            func_ov023_021df218(obj);
            func_ov023_021df558(obj);
            return -1;
        }

        func_ov023_021df558(obj);
        flags = *(unsigned short*)(obj + regionalOffset0);
        return (flags & 0x400) ? -1 : 9;
    }

    return (*(int*)(obj + regionalOffset3) != -1) ? 7 : -1;
}
