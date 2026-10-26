#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

extern int data_020f00cc;

struct Struct_02046c98 {
    unsigned char pad[0xe8];
    int unknown_e8_;   // 0xe8
    int unknown_ec_;   // 0xec
};

// USA: func_02046c98
extern "C" ARM void func_02046c98(struct Struct_02046c98* h) {
    if (h->unknown_e8_ != 0) return;
    h->unknown_ec_ = ((BackgroundLoader*)((int)BackgroundLoader::GetInstance()))->QueueLoadFile((const char*)((int)&data_020f00cc), (SafeAllocator*)(0));
}
