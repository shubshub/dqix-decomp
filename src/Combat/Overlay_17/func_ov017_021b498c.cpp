#if defined(jpn)
enum { RegionOffset18 = 0x14 };
#else
enum { RegionOffset18 = 0x18 };
#endif

#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Filesystem/FileIO.h"

struct Struct_020534ac_2;
struct Struct_020534ac;
struct InitStruct;
extern "C" ARM void NodeGraph_Reset(struct InitStruct* s);
struct Struct_02028104;
extern "C" void func_02028104(struct Struct_02028104* s, int b, int c, int d);
extern "C" void func_02028214(void* a, int b);

extern char data_ov017_021d7b4f;
extern char data_ov017_021d7b3a;

struct Struct_ov017_021b498c {
    char pad0[8];
    void* sub;
    int key;
    unsigned char field10;
    char pad1[3];
    int field14;
};

// USA: func_ov017_021b498c
extern "C" ARM void func_ov017_021b498c(struct Struct_ov017_021b498c* obj) {
    GameState::GetInstance();
    int list = (int)BackgroundLoader::GetInstance();
    if (!((BackgroundLoader*)(list))->GetTaskStatus((int)(obj->key))) {
        return;
    }

    if (((BackgroundLoader*)((struct Struct_020534ac_2*)list))->GetDetailedTaskStatus((int)(obj->key)) == 2) {
        int out2, out1;
        ((BackgroundLoader*)((struct Struct_020534ac*)list))->GetLoadedFileByID((int)(obj->key), (void**)(&out1), (unsigned int*)(&out2));
        if (out1 != 0) {
            unsigned int fileSize;
            const void* filePtr;
            FindFilesInNarcBySubstring((const void*)out1, &data_ov017_021d7b4f, &filePtr, &fileSize, 1);
            if (filePtr != 0) {
                char* sub = (char*)obj->sub;
                NodeGraph_Reset((struct InitStruct*)(sub + RegionOffset18));
                func_02028104((struct Struct_02028104*)(sub + RegionOffset18), *(int*)((char*)obj->sub + 0x10), (int)filePtr, (int)fileSize);
                func_02028214(sub + RegionOffset18, *(int*)((char*)obj->sub + 0x10));
                sub[0xc] = 1;
            }
        }
    }

    ((BackgroundLoader*)(list))->RemoveTask((int)(obj->key));
    obj->key = -1;
    obj->key = ((BackgroundLoader*)(list))->QueueLoadFile((const char*)((int)&data_ov017_021d7b3a), (SafeAllocator*)(0));
    obj->field10 = 3;
}
