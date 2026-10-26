#include <globaldefs.h>
#include "NitroSDK/Filesystem/FileAccessor.h"
#include "NitroSDK/Filesystem/LowNitroHandle.h"

struct Holder020bd110
{
    char _pad0[0x30];
    int flag30;
    NitroVM vm34;
    NitroFileAccessor accessor7c;
    void* list84;
    unsigned int f88;
    void* f8c;
    unsigned int f90;
};

extern struct Holder020bd110* data_02110370;
extern "C" int func_020bd190(struct Holder020bd110* obj, int arg2, int arg3);

// Main, originally InitStreamHolder020bd110 (USA 0x020bd110, EUR 0x020bd120, JPN 0x020bebdc)
ARM int NNS_SndArcInit(struct Holder020bd110* obj, const char* path, int arg2, int arg3)
{
    obj->f8c = 0;
    obj->list84 = 0;
    obj->f88 = 0;
    obj->f90 = 0;

    int ok = CreateFileAccessor(&obj->accessor7c, path);
    if (ok == 0)
        return ok;

    NitroVM_Initialize(&obj->vm34);

    ok = NitroVM_PrepareReadFileByID(&obj->vm34, obj->accessor7c);
    if (ok == 0)
        return ok;

    obj->flag30 = 1;

    int result = func_020bd190(obj, arg2, arg3);
    if (result != 0)
    {
        data_02110370 = obj;
        return (int)&data_02110370;
    }

    return result;
}
