#if defined(jpn)
#define R(j,u) (j)
#define data_ov006_0215ffb4 data_ov006_02161318
#define data_ov006_0215ffc0 data_ov006_0216131b
#define data_ov006_0215ffc4 data_ov006_02161328
#define data_ov006_0215ffca data_ov006_02161336
#define data_ov006_0215ffe2 data_ov006_0216132e
#define data_ov006_0215fff4 data_ov006_02161346
#define func_ov006_021547c8 func_ov006_02155f30
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Filesystem/BackgroundLoader.h"

struct Struct_ov006_021536e0;
struct Struct_ov006_02154614;

extern "C" void func_ov006_021547c8(AlchemyPot*);
void TailCallInitStruct_02153730(StructInit36e0*);
char* MessageSystem_GetInstance();

struct Struct_ov006_02157a60 {
#if !defined(jpn)
    int unknown_0_;
    char** unknown_4_;
#endif
    void* unknown_8_;
    SafeAllocator* unknown_c_;
    Struct_ov006_02154614* unknown_10_;
    void* unknown_14_;
    void* unknown_18_;
    void* unknown_1c_;
    void* unknown_20_;
    void* unknown_24_;
    void* unknown_28_;
    void* unknown_2c_;
    void* unknown_30_;
    void* unknown_34_;
    void* unknown_38_;
    char unknown_3c_[8];
    short* unknown_44_;
    short** unknown_48_;
    unsigned char** unknown_4c_;
    unsigned short* unknown_50_;
    int unknown_54_[0x20 / 4];
    int unknown_74_[0x28 / 4];
    int unknown_9c_[0xc / 4];
    unsigned short unknown_a8_;
    unsigned char unknown_aa_;
    int unknown_ac_[0x54 / 4];
    int unknown_100_[0x4c / 4];
    int unknown_14c_[0xc / 4];
    int unknown_158_[0x18 / 4];
    char unknown_170_[0xc];
    int unknown_17c_[4][0x74 / 4];
#if defined(jpn)
    char unknown_344_[8];
#endif
    int unknown_34c_;
    int unknown_350_;
    int unknown_354_;
    int unknown_358_;
};

// USA: func_ov006_02157cc0
extern "C" ARM void func_ov006_02157cc0(Struct_ov006_02157a60* arg0)
{
    if (arg0->unknown_10_ != 0)
    {
        func_ov006_021547c8(arg0->unknown_10_);
        arg0->unknown_10_ = 0;
    }
    BackgroundLoader* var0 = BackgroundLoader::GetInstance();
    if (arg0->unknown_354_ >= 0)
    {
        var0->RemoveTask(arg0->unknown_354_);
        arg0->unknown_354_ = -1;
    }
    if (arg0->unknown_358_ >= 0)
    {
        var0->RemoveTask(arg0->unknown_358_);
        arg0->unknown_358_ = -1;
    }
    TailCallInitStruct_02153730((StructInit36e0*)self->ingredients_);
    *(int*)(MessageSystem_GetInstance() + R(0x228, 0x2d8)) = 0;
    if (self->allocators_ == 0)
        return;
    for (unsigned char var1 = 0; var1 < 10; var1++)
    {
        if (arg0->unknown_c_[var1].GetSignedAllocator() != 0)
            arg0->unknown_c_[var1].Destroy();
    }
}
