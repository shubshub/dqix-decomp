#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

#if defined(jpn)
#define RG(u, j) (j)
#else
#define RG(u, j) (u)
#endif

struct Pair0209a338;

extern const char* data_020f2a0c;
extern const char* data_020f2a18;
extern char data_ov002_0216cf21[];
extern char data_ov002_0216cf39[];
extern "C" void func_0209a804(int*);
extern "C" void func_0209a338(Pair0209a338*);
#if defined(jpn)
extern "C" int func_020e12ec(char* destination, const char* source);
extern char data_ov002_0216d539[];
#endif

// USA: func_ov002_02156bc8
extern "C" ARM void func_ov002_02156bc8(char* self) {
    if (*(unsigned int*)(self + RG(0x247c, 0x22ac)) & 0x10) {
        return;
    }
#if defined(jpn)
    char path[0x40];
    func_020e12ec(path, data_ov002_0216d539);
#endif
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    loader->AddFence();
#if defined(jpn)
    *(int*)(self + 0x1a6c) = loader->QueueLoadGP1(path, 0);
#else
    *(int*)(self + 0x1ba4) = loader->QueueLoadFileInGP2(data_020f2a18, data_020f2a0c, 0);
#endif
    *(int*)(self + RG(0x1ba8, 0x1a70)) = loader->QueueLoadFile(data_ov002_0216cf21, 0);
    *(int*)(self + RG(0x1bac, 0x1a74)) = loader->QueueLoadFile(data_ov002_0216cf39, 0);
    func_0209a804((int*)(self + RG(0x2444, 0x227c)));
    func_0209a338((Pair0209a338*)(self + RG(0x243c, 0x2274)));
    *(unsigned int*)(self + RG(0x247c, 0x22ac)) |= 0x10;
}
