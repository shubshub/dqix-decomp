#if defined(jpn)
#define R(j,u) (j)
#define data_ov006_0215ffb4 data_ov006_02161318
#define data_ov006_0215ffc0 data_ov006_0216131b
#define data_ov006_0215ffc4 data_ov006_02161328
#define data_ov006_0215ffca data_ov006_02161336
#define data_ov006_0215ffe2 data_ov006_0216132e
#define data_ov006_0215fff4 data_ov006_02161346
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Filesystem/BackgroundLoader.h"

struct Struct_ov006_021536e0;
struct Struct_ov006_02154614;

extern "C" void func_ov006_021547c8(Struct_ov006_02154614*);
extern "C" void func_ov006_02153730(Struct_ov006_021536e0*);
extern "C" char* MessageSystem_GetInstance();

struct Struct_ov006_02157a60 {
#if !defined(jpn)
    int unknown_0_;
    char** texts_;
#endif
    void* canvasBuffer_;
    SafeAllocator* allocators_;
    Struct_ov006_02154614* pot_;
    void* menu_;
    void* choice_;
    void* backgrounds_;
    void* canvases_;
    void* sprites_;
    void* animations_;
    void* unknown_2c_;
    void* unknown_30_;
    void* unknown_34_;
    void* unknown_38_;
    char unknown_3c_[8];
    short* cursor_;
    short** items_;
    unsigned char** unknown_4c_;
    unsigned short* sizes_;
    int subBackground_[0x20 / 4];
    int ingredients_[0x28 / 4];
    int unknown_9c_[0xc / 4];
    unsigned short unknown_a8_;
    unsigned char unknown_aa_;
    int renderer_[0x54 / 4];
    int layout_[0x4c / 4];
    int table_[0xc / 4];
    int menuTexts_[0x18 / 4];
    char itemNames_[0xc];
    int results_[4][0x74 / 4];
#if defined(jpn)
    char unknown_344_[8];
#endif
    int ticks_;
    int menuResult_;
    int task_;
    int unknown_358_;
};

// USA: func_ov006_02157cc0
extern "C" ARM void func_ov006_02157cc0(Struct_ov006_02157a60* self)
{
    if (self->pot_ != 0)
    {
        func_ov006_021547c8(self->pot_);
        self->pot_ = 0;
    }
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (self->task_ >= 0)
    {
        loader->RemoveTask(self->task_);
        self->task_ = -1;
    }
    if (self->unknown_358_ >= 0)
    {
        loader->RemoveTask(self->unknown_358_);
        self->unknown_358_ = -1;
    }
    func_ov006_02153730((Struct_ov006_021536e0*)self->ingredients_);
    *(int*)(MessageSystem_GetInstance() + R(0x228, 0x2d8)) = 0;
    if (self->allocators_ == 0)
        return;
    for (unsigned char i = 0; i < 10; i++)
    {
        if (self->allocators_[i].GetSignedAllocator() != 0)
            self->allocators_[i].Destroy();
    }
}
