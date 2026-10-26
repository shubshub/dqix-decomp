#include <globaldefs.h>
#include "NitroSDK/Filesystem/NitroVM.h"
#include "NitroSDK/Filesystem/LowNitroHandle.h"
#include "NitroSDK/Filesystem/FileAccessor.h"

struct Struct_ov027_021d989c_2 {
    unsigned int start;
    unsigned int len;
    void* dst;
    int status;
};

struct Struct_ov027_021d989c_3 {
    char pad0[0x10];
    char sig[4];
    int unknown_14_;
    unsigned int unknown_18_;
};

struct Struct_ov027_021d989c {
    char pad0[0x10];
    Struct_ov027_021d989c_2* req;
    Struct_ov027_021d989c_3* unknown_14_;
};

#pragma optimize_for_size off

// USA: func_ov027_021d989c
extern "C" ARM void func_ov027_021d989c(Struct_ov027_021d989c* p)
{
    Struct_ov027_021d989c_3* hi = p->unknown_14_;
    Struct_ov027_021d989c_2* req = p->req;

    NitroHandle* handle = NitroHandle_FindBySignature(hi->sig, hi->unknown_14_);
    if (handle == NULL)
        handle = (NitroHandle*)hi->unknown_18_;

    NitroVM vm;
    NitroVM_Initialize(&vm);

    unsigned int start = req->start;
    unsigned int end = start + req->len;
    if (NitroVM_PrepareRead(&vm, handle, start, end, 0xFFFFFFFF))
    {
        int n = NitroVM_ReadSync(&vm, req->dst, req->len);
        if (req->len == (unsigned int)n)
            req->status = 2;
        NitroVM_FinishRead(&vm);
    }

    if (req->status != 2)
    {
        req->start = 0;
        req->status = 2;
    }
}
