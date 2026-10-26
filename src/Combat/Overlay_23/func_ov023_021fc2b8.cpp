#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

extern "C" void* func_ov011_021849c8(void*);
extern "C" int func_ov023_021f6bb8(void*);
extern "C" void func_ov023_021f6bb0(void*, int);

extern char data_ov023_021ff480;
extern char data_ov023_021ff496;

struct Struct_ov023_021fc2b8 { char pad[0x1c]; int field1c; };

// USA: func_ov023_021fc2b8
#if defined(jpn)
extern char data_ov023_021fe718;

extern "C" ARM int func_ov023_021fc2b8(struct Struct_ov023_021fc2b8* self, void* arg1) {
    void* sub = func_ov011_021849c8(arg1);
    int v = func_ov023_021f6bb8(sub);
    if (v >= 0) {
        return self->field1c;
    }
    int var2 = (int)BackgroundLoader::GetInstance();
    int result = ((BackgroundLoader*)(var2))->QueueLoadFile((const char*)((int)&data_ov023_021fe718), (SafeAllocator*)(0));
    func_ov023_021f6bb0(sub, result);
    return 1;
}
#else
extern "C" ARM int func_ov023_021fc2b8(struct Struct_ov023_021fc2b8* self, void* arg1) {
    void* sub = func_ov011_021849c8(arg1);
    int v = func_ov023_021f6bb8(sub);
    if (v >= 0) {
        return self->field1c;
    }
    int var6 = (int)BackgroundLoader::GetInstance();
    int result = ((BackgroundLoader*)(var6))->QueueLoadFileInGP2((const char*)((int)&data_ov023_021ff480), (const char*)((int)&data_ov023_021ff496), (SafeAllocator*)(0));
    func_ov023_021f6bb0(sub, result);
    return 1;
}
#endif
