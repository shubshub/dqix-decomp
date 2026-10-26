#include <globaldefs.h>
#include "NitroSDK/Cache.h"

typedef char* Type_02001bdc;
#define __va_align(size) ((((unsigned long)(size)) + 3U) & ~3U)
#define va_start(ap, parm) ((ap) = (Type_02001bdc)((char*)((unsigned long)&(parm) & ~3U) + __va_align(sizeof(parm))))
#define va_arg(ap, type) (*(type*)(((ap) += __va_align(sizeof(type))) - __va_align(sizeof(type))))
#define va_end(ap) ((void)0)
#include "NitroSDK/IPC.h"

extern "C" void* func_020d4064();
extern "C" int func_020c7e0c(void* queue, void* message, int flags);

extern int data_021142e8;

// USA: func_020d40bc
extern "C" ARM int func_020d40bc(int id, unsigned short arg1, ...)
{
    Type_02001bdc args;
    int i;
    int result;
    unsigned long* buffer;
    buffer = (unsigned long*)func_020d4064();
    if (buffer == NULL)
        return 8;
    *(unsigned short*)buffer = id;
    va_start(args, arg1);
    for (i = 0; i < arg1; i++)
        buffer[i + 1] = va_arg(args, unsigned long);
    va_end(args);
    CleanCacheRange(buffer, 0x100);
    result = SendCommandToArm7(10, (int)buffer, false);
    func_020c7e0c(&data_021142e8, buffer, 1);
    if (result < 0)
        return 8;
    return 2;
}
