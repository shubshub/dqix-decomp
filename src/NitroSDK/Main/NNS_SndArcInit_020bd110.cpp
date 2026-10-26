#include <globaldefs.h>
#include "NitroSDK/Filesystem/FileAccessor.h"
#include "NitroSDK/Filesystem/LowNitroHandle.h"

struct Holder020bd110
{
    char unknown_0_[0x30];
    int flag30;
    NitroVM unknown_34_;
    NitroFileAccessor unknown_7c_;
    void* unknown_84_;
    unsigned int unknown_88_;
    void* unknown_8c_;
    unsigned int f90;
};

extern struct Holder020bd110* data_02110370;
extern "C" int func_020bd190(struct Holder020bd110* obj, int arg1, int arg2);

// Main, originally InitStreamHolder020bd110 (USA 0x020bd110, EUR 0x020bd120, JPN 0x020bebdc)
extern "C" ARM int NNS_SndArcInit(struct Holder020bd110* obj, const char* path, int arg2, int arg3)
{
    obj->unknown_8c_ = 0;
    obj->unknown_84_ = 0;
    obj->unknown_88_ = 0;
    obj->f90 = 0;

    int ok = CreateFileAccessor(&obj->unknown_7c_, path);
    if (ok == 0)
        return ok;

    NitroVM_Initialize(&obj->unknown_34_);

    ok = NitroVM_PrepareReadFileByID(&obj->unknown_34_, obj->unknown_7c_);
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
