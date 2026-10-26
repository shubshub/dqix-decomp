#if defined(jpn)
#define R(j,u) (j)
#define data_ov005_0215cbd4 data_ov005_0215dfb4
#define data_ov005_0215cd60 data_ov005_0215e140
#define data_ov014_02189480 data_ov014_0218a2c0
#define data_ov014_02189498 data_ov014_0218a2d8
#define data_ov015_02193fe0 data_ov015_02194b20
#define data_ov015_02194564 data_ov015_02195184
#define data_ov015_02194570 data_ov015_02195190
#define data_ov015_021945a0 data_ov015_021951c0
#define data_ov015_021945d0 data_ov015_021951f0
#define data_ov024_021ff17c data_ov023_021ff17c
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "NitroSDK/Matrix.h"
#include "NitroSDK/NSBXX/GeometryFifo.h"
#include "NitroSDK/NSBXX/RenderConfig.h"

struct Struct_ov015_0218bb3c_2;

struct Struct_ov015_02194564
{
#if defined(jpn)
    Matrix4x3* unknown_8_;
    Matrix4x3* position_;
    Matrix4x3* unknown_0_;
#else
    Matrix4x3* unknown_0_;
    Matrix4x3* position_;
    Matrix4x3* unknown_8_;
#endif
    Matrix4x3 unknown_c_;
    Matrix4x3 unknown_3c_;
    Matrix4x3 unknown_6c_;
};

extern "C" int func_ov015_0218bc9c(Struct_ov015_0218bb3c_2* s);

extern unsigned char data_ov015_02193fe0[];
extern Struct_ov015_02194564 data_ov015_02194564;

struct Struct_ov015_0218bb3c
{
    char unk_0[8];
    unsigned int flags_;
};

// USA: func_ov015_0218bb3c
extern "C" ARM void func_ov015_0218bb3c(Struct_ov015_0218bb3c* handler)
{
    if (!(handler->flags_ & 0x10))
        return;
    if (data_ov015_02193fe0[1] == func_ov015_0218bc9c((Struct_ov015_0218bb3c_2*)handler) && data_ov015_02194564.unknown_8_ != NULL)
    {
        GetCurrentPositionAndDirectionMatrices(data_ov015_02194564.unknown_8_, NULL);
        data_ov015_02194564.unknown_c_ = *data_ov015_02194564.unknown_8_;
        Mat4x3_Multiply(data_ov015_02194564.unknown_8_, RenderConfig::GetInverseViewMatrix(), data_ov015_02194564.unknown_8_);
    }
    if (data_ov015_02193fe0[R(0, 2)] == func_ov015_0218bc9c((Struct_ov015_0218bb3c_2*)handler) && data_ov015_02194564.unknown_0_ != NULL)
    {
        GetCurrentPositionAndDirectionMatrices(data_ov015_02194564.unknown_0_, NULL);
        data_ov015_02194564.unknown_3c_ = *data_ov015_02194564.unknown_0_;
        Mat4x3_Multiply(data_ov015_02194564.unknown_0_, RenderConfig::GetInverseViewMatrix(), data_ov015_02194564.unknown_0_);
    }
    if (data_ov015_02193fe0[R(2, 0)] != func_ov015_0218bc9c((Struct_ov015_0218bb3c_2*)handler))
        return;
    if (data_ov015_02194564.position_ == NULL)
        return;
    GetCurrentPositionAndDirectionMatrices(data_ov015_02194564.position_, NULL);
    data_ov015_02194564.unknown_6c_ = *data_ov015_02194564.position_;
    Mat4x3_Multiply(data_ov015_02194564.position_, RenderConfig::GetInverseViewMatrix(), data_ov015_02194564.position_);
}
