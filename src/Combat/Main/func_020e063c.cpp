#include <globaldefs.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif

#include "Filesystem/BackgroundLoader.h"

extern "C" void MapDisplay_RemoveTask(void* owner, int* handle);

struct Struct_020dc3d4 {
    unsigned char pad0[IS_JPN ? 0x919 : 0x9c5];
    unsigned char unknown_9c5_;
    unsigned char pad1[0xa0c - 0x9c6];
    int handle_a0c;
};

// USA: func_020e063c
extern "C" ARM void func_020e063c(struct Struct_020dc3d4* self, int b, int c) {
    int h = (int)BackgroundLoader::GetInstance();
    self->unknown_9c5_ = 1;
    MapDisplay_RemoveTask(self, &self->handle_a0c);
    self->handle_a0c = ((BackgroundLoader*)(h))->QueueLoadFileInGP2((const char*)(b), (const char*)(c), (SafeAllocator*)(0));
}
