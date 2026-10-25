#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"

struct Struct_02075cdc;
extern "C" void func_02075cdc(struct Struct_02075cdc* arg0);
extern "C" void* func_0203bd08(void);
extern "C" void* func_0203be4c(void);
struct StructDE234_020de234;
unsigned short ItemRecord_GetFileNumber(struct StructDE234_020de234* p, int preferMid);

extern char data_ov006_02160360[];

// USA: func_ov006_0215fe34
extern "C" ARM void func_ov006_0215fe34(char* arg0, struct Struct_02015ef4_4* arg1) {
    if (arg1 == NULL) {
        return;
    }

    BackgroundLoader* var0 = BackgroundLoader::GetInstance();

    func_02075cdc((struct Struct_02075cdc*)(arg0 + 0x3b8));
    *(int*)(arg0 + 0x3f4) = 5;
    *(unsigned char*)(arg0 + 0x416) = 1;

    func_0203bd08();
    void* var1 = func_0203be4c();
    *(char**)(arg0 + 0x3cc) = (char*)var1 + 0x1b8;

    *(int*)(arg0 + 0x3f0) = 0x10000;
    *(int*)(arg0 + 0x3f8) = 0;

    unsigned short val = ItemRecord_GetFileNumber(info, 0);

    unsigned int var3 = *(unsigned int*)((char*)arg1 + 0x10);
    int var4 = (var3 << 4) >> 0x18;

    char var5[0x40];
    sprintf(var5, data_ov006_02160360, var4, var2);

    int var6 = var0->QueueLoadFile((const char*)var5, (SafeAllocator*)0);
    *(int*)(arg0 + 0x428) = var6;
}
