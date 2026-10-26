#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Matrix.h"

struct Foo0207df50 {
    unsigned int a[10];
    unsigned int b[10];
    unsigned int c;
    unsigned int d;
    unsigned int p1[2];
    unsigned int p2[2];
};

struct Struct_ov000_02161e30 {
    char pad0[0x8e49];
    unsigned char kind;
};

struct MessageWork {
#if defined(jpn)
    char pad0[0x870];
#else
    char pad0[0x9a0];
#endif

    int phase;
};

struct Struct_02078398_2 {
    unsigned char unknown_0_;
    unsigned char unknown_1_[0xf];
    unsigned char f10;
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
    unsigned char unknown_11_4_ : 1;
    unsigned char unknown_11_5_ : 1;
    unsigned char unknown_11_6_ : 1;
    unsigned char unknown_11_7_ : 1;
    short f12;
    short objectId;
    short unknown_16_;
    short f18;
    short unknown_1a_;
    short f1c;
    short pad1e;
    int f20;
    int f24;
    int f28;
    Vector3fix offset;
    Vector3fix rotation;
    Vector3fix scale;
};

struct Struct_ov000_02160da0 {
#if defined(jpn)
    char pad0[0x218];
#else
    char pad0[0x29c];
#endif

    Struct_ov000_02161e30* battle;
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
    Foo0207df50 stateB;
};

extern "C" MessageWork* MessageSystem_GetInstance();
extern "C" void VramState_Rewind(Foo0207df50* p);
extern "C" void func_02078484(Struct_02078398_2* req);
extern "C" int func_02057fb4(void* list, int id, void* req);

extern "C" {
void* func_02057924();
int func_02057e6c(void* list, int kind, SafeAllocator* alloc, void* data, unsigned int size, Foo0207df50* state);
}

extern char data_ov026_021dedf0[];

// USA: func_ov026_021db3d8
extern "C" ARM void func_ov026_021db3d8(Struct_ov000_02160da0* self) {
    if (self->battle->kind == 2) {
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        void* list = func_02057924();

        if (self->unknown_772e_ == 0) {
            if (MessageSystem_GetInstance()->phase == 4) {
                self->unknown_772e_ = 1;
            }
        } else if (self->unknown_772e_ == 1) {
            if (MessageSystem_GetInstance()->phase == 5) {
                self->unknown_772e_ = 2;
            }
        }

        if (self->unknown_7728_ == 0) {
            self->unknown_774c_.Reset();
            VramState_Rewind(&self->stateB);
            self->unknown_772a_ = loader->QueueLoadFile(data_ov026_021dedf0, &self->unknown_774c_);
            self->unknown_7728_ = 1;
        } else if (self->unknown_7728_ == 1) {
            if (loader->GetTaskStatus(self->unknown_772a_)) {
                void* data;
                unsigned int size;
                loader->GetLoadedFileByID(self->unknown_772a_, &data, &size);
                func_02057e6c(list, 0x13, &self->unknown_774c_, data, size, &self->stateB);
                loader->RemoveTask(self->unknown_772a_);
                self->unknown_7728_ = 2;
            }
        } else if (self->unknown_7728_ == 2 && self->unknown_772e_ == 2) {
            Struct_02078398_2 req;
            func_02078484(&req);
            req.b1 = 1;
            req.f10 = 0;
            req.offset.z = -0x3000;
            req.scale.x = 0x10a;
            req.scale.y = 0x10a;
            req.scale.z = 0x10a;
            self->unknown_772c_ = func_02057fb4(list, 0x13, &req);
            self->unknown_772e_ = -1;
            self->unknown_7728_ = -1;
        }
    }
}
