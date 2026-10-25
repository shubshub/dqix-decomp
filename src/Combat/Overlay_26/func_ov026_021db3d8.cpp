#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Matrix.h"

struct Struct_0203d028 {
    unsigned int unknown_0_[10];
    unsigned int unknown_28_[10];
    unsigned int unknown_50_;
    unsigned int unknown_54_;
    unsigned int unknown_58_[2];
    unsigned int unknown_60_[2];
};

struct Struct_ov000_02161e30 {
    char unknown_0_[0x8e49];
    unsigned char unknown_8e49_;
};

struct Struct_ov023_021f4c04 {
#if defined(jpn)
    char unknown_0_[0x870];
#else
    char unknown1_0_[0x9a0];
#endif

    int unknown_9a0_;
};

struct Struct_02078398_2 {
    unsigned char unknown_0_;
    unsigned char unknown_1_[0xf];
    unsigned char unknown_10_;
    unsigned char unknown_11_0_ : 1;
    unsigned char unknown_11_1_ : 1;
    unsigned char unknown_11_2_ : 1;
    unsigned char unknown_11_3_ : 1;
    unsigned char unknown_11_4_ : 1;
    unsigned char unknown_11_5_ : 1;
    unsigned char unknown_11_6_ : 1;
    unsigned char unknown_11_7_ : 1;
    short unknown_12_;
    short unknown_14_;
    short unknown_16_;
    short unknown_18_;
    short unknown_1a_;
    short unknown_1c_;
    short unknown_1e_;
    int unknown_20_;
    int unknown_24_;
    int unknown_28_;
    Vector3fix unknown_2c_;
    Vector3fix unknown_38_;
    Vector3fix unknown_44_;
};

struct Struct_ov000_02160da0 {
#if defined(jpn)
    char unknown_0_[0x218];
#else
    char unknown1_0_[0x29c];
#endif

    Struct_ov000_02161e30* unknown_29c_;
#if defined(jpn)
    char unknown_21c_[0x76fc];
#else
    char unknown_2a0_[0x7488];
#endif

    signed char unknown_7728_;
    char unknown_7729_[0x1];
    short unknown_772a_;
    short unknown_772c_;
    signed char unknown_772e_;
    char unknown_772f_[0x1d];
    SafeAllocator unknown_774c_;
    Struct_0203d028 unknown_7760_;
};

MessageWork* MessageSystem_GetInstance();
void VramState_Rewind(Foo0207df50* p);
void InitStruct02078484(InitStruct02078484Struct* req);
int FindNodeAndProcess02057fb4(void* list, int id, void* req);

extern "C" {
void* func_02057924();
int func_02057e6c(void* arg0, int arg1, SafeAllocator* arg2, void* arg3, unsigned int arg4, Struct_0203d028* arg5);
}

extern char data_ov026_021dedf0[];

// USA: func_ov026_021db3d8
extern "C" ARM void func_ov026_021db3d8(Struct_ov000_02160da0* arg0) {
    if (arg0->unknown_29c_->unknown_8e49_ == 2) {
        BackgroundLoader* var0 = BackgroundLoader::GetInstance();
        void* var1 = func_02057924();

        if (self->effectTrigger == 0) {
            if (MessageSystem_GetInstance()->phase == 4) {
                self->effectTrigger = 1;
            }
        } else if (self->effectTrigger == 1) {
            if (MessageSystem_GetInstance()->phase == 5) {
                self->effectTrigger = 2;
            }
        }

        if (self->effectLoadState == 0) {
            self->cmdAlloc.Reset();
            VramState_Rewind(&self->stateB);
            self->effectTaskId = loader->QueueLoadFile(data_ov026_021dedf0, &self->cmdAlloc);
            self->effectLoadState = 1;
        } else if (self->effectLoadState == 1) {
            if (loader->GetTaskStatus(self->effectTaskId)) {
                void* data;
                unsigned int size;
                loader->GetLoadedFileByID(self->effectTaskId, &data, &size);
                func_02057e6c(list, 0x13, &self->cmdAlloc, data, size, &self->stateB);
                loader->RemoveTask(self->effectTaskId);
                self->effectLoadState = 2;
            }
        } else if (arg0->unknown_7728_ == 2 && arg0->unknown_772e_ == 2) {
            Struct_02078398_2 var4;
            func_02078484(&var4);
            var4.unknown_11_1_ = 1;
            var4.unknown_10_ = 0;
            var4.unknown_2c_.z = -0x3000;
            var4.unknown_44_.x = 0x10a;
            var4.unknown_44_.y = 0x10a;
            var4.unknown_44_.z = 0x10a;
            arg0->unknown_772c_ = func_02057fb4(var1, 0x13, &var4);
            arg0->unknown_772e_ = -1;
            arg0->unknown_7728_ = -1;
        }
    }
}
