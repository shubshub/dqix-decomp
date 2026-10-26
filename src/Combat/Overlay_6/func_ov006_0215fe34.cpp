#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"

struct Struct_02075cdc;
extern "C" void func_02075cdc(struct Struct_02075cdc* s);
extern "C" void* OamManager_GetInstance(void);
extern "C" void* OamManager_GetSubOamBuffer(void);
struct StructDE234_020de234;
extern "C" unsigned short ItemRecord_GetFileNumber(struct StructDE234_020de234* p, int preferMid);

extern char data_ov006_02160360[];

// USA: func_ov006_0215fe34
extern "C" ARM void func_ov006_0215fe34(char* self, struct StructDE234_020de234* info) {
    if (info == NULL) {
        return;
    }

    BackgroundLoader* loader = BackgroundLoader::GetInstance();

    func_02075cdc((struct Struct_02075cdc*)(self + 0x3b8));
    *(int*)(self + 0x3f4) = 5;
    *(unsigned char*)(self + 0x416) = 1;

    OamManager_GetInstance();
    void* p = OamManager_GetSubOamBuffer();
    *(char**)(self + 0x3cc) = (char*)p + 0x1b8;

    *(int*)(self + 0x3f0) = 0x10000;
    *(int*)(self + 0x3f8) = 0;

    unsigned short val = ItemRecord_GetFileNumber(info, 0);

    unsigned int var3 = *(unsigned int*)((char*)info + 0x10);
    int var4 = (var3 << 4) >> 0x18;

    char buf[0x40];
    sprintf(buf, data_ov006_02160360, var4, val);

    int r = loader->QueueLoadFile((const char*)buf, (SafeAllocator*)0);
    *(int*)(self + 0x428) = r;
}
