#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct Struct_020941f8_2 {
#if defined(jpn)
    char unknown_0_[0x100];
#else
    char unknown1_0_[0x340];
#endif
    int unknown_340_;
#if defined(jpn)
    char unknown_104_[0x138 - 0x104];
#else
    char unknown_344_[0x3c8 - 0x344];
#endif
    unsigned char unknown_3c8_0_ : 7;
    unsigned char unknown_3c8_7_ : 1;
    char unknown_3c9_[0x3cb - 0x3c9];
    char unknown_3cb_;
    char unknown_3cc_;
    unsigned char unknown_3cd_;
};

struct Struct_020941f8 {
    char unknown_0_[0x44];
    int unknown_44_;
    char unknown_48_[0x50 - 0x48];
    unsigned char unknown_50_;
};

struct PacRecord;

int Pac_CountFiles(struct PacRecord* entry);
extern void* Pac_GetFile(struct PacRecord* rec, int index, void** out, int* out44);
unsigned char IsPowCnt1Bit15Clear020938cc();
ARM void SpriteContext_Init(char* obj);
ARM void SpriteContext_Destroy(void* obj);
extern "C" ARM int SpriteContext_LoadFile(void* obj, void* data, int arg2, int arg3);
extern "C" int func_020937f0(int a);
extern const char data_020f1394[];

// USA: func_020941f8
extern "C" ARM int func_020941f8(struct Struct_020941f8_2* arg0) {
    if ((arg0->unknown_3cd_ & 8) == 0 && (arg0->unknown_3cd_ & 2) == 0) {
        return 0;
    }
    BackgroundLoader* var0 = BackgroundLoader::GetInstance();
    unsigned int var1 = arg0->unknown_3c8_0_;
    if (var1 == 0) {
        if (arg0->unknown_340_ >= 0) {
            var0->RemoveTask(arg0->unknown_340_);
            arg0->unknown_340_ = -1;
        }
        arg0->unknown_340_ = var0->QueueLoadFile(data_020f1394, 0);
        arg0->unknown_3cd_ &= ~8;
        arg0->unknown_3cd_ |= 2;
        arg0->unknown_3c8_0_ = arg0->unknown_3c8_0_ + 1;
    } else {
        void* out1;
        void* file;
        unsigned int length;
        int size;
        if (n == 1 && bgl->GetTaskStatus(p->handle340) != 0) {
            bgl->GetLoadedFileByID(p->handle340, &file, &length);
            int count = Pac_CountFiles((struct PacRecord*)file);
            p->flag3c8 = IsPowCnt1Bit15Clear020938cc();
            int value = func_020937f0(p->flag3c8);
            if (value != 0) {
                struct Ctx020941f8 ctx;
                int i;
                SpriteContext_Init((char*)&ctx);
                SpriteContext_Init((char*)&ctx);
                ctx.field50 = (unsigned char)p->flag3c8;
                ctx.field44 = value - 0xa00;
                for (i = 0; i < count; i++) {
                    void* rec;
                    size = 0;
                    rec = Pac_GetFile((struct PacRecord*)file, i, &out1, &size);
                    SpriteContext_LoadFile(&ctx, rec, size, 0);
                }
                SpriteContext_Destroy(&ctx);
            }
            var0->RemoveTask(arg0->unknown_340_);
            arg0->unknown_340_ = -1;
            arg0->unknown_3cd_ &= ~2;
            arg0->unknown_3c8_0_ = 0;
            if (arg0->unknown_3cb_ > 0) {
                arg0->unknown_3cd_ |= 1;
            }
        }
    }
    return 1;
}
