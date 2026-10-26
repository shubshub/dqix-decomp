#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct Struct_020dbdc0;
extern "C" void func_020dbf70(struct Struct_020dbdc0* o);

struct Struct_020dbf18 {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
};

// USA: func_020dbf18
extern "C" ARM int func_020dbf18(struct Struct_020dbf18* a, int b, int c, int d, int e) {
    int handle = (int)BackgroundLoader::GetInstance();
    func_020dbf70((struct Struct_020dbdc0*)a);
    a->f0 = c;
    a->f4 = d;
    a->f8 = e;
    a->fc = ((BackgroundLoader*)(handle))->QueueLoadFile((const char*)(b), (SafeAllocator*)(0));
    a->f10 = 1;
    return 0;
}
