#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct Struct_020941f8_2 {
#if defined(jpn)
    char pad0[0x100];
#else
    char pad0[0x340];
#endif
    int unknown_340_;
#if defined(jpn)
    char pad1[0x138 - 0x104];
#else
    char pad1[0x3c8 - 0x344];
#endif
    unsigned char unknown_3c8_0_ : 7;
    unsigned char unknown_3c8_7_ : 1;
    char pad2[0x3cb - 0x3c9];
    char unknown_3cb_;
    char pad3;
    unsigned char unknown_3cd_;
};

struct Struct_020941f8 {
    char pad0[0x44];
    int field44;
    char pad1[0x50 - 0x48];
    unsigned char unknown_50_;
};

struct PacRecord;

extern "C" int Pac_CountFiles(struct PacRecord* entry);
extern "C" void* Pac_GetFile(struct PacRecord* rec, int index, void** out, int* out44);
extern "C" unsigned char func_020938cc();
extern "C" ARM void SpriteContext_Init(char* obj);
extern "C" ARM void SpriteContext_Destroy(void* obj);
extern "C" ARM int SpriteContext_LoadFile(void* obj, void* data, int arg2, int arg3);
extern "C" int func_020937f0(int a);
extern const char data_020f1394[];

// USA: func_020941f8
extern "C" ARM int func_020941f8(struct Struct_020941f8_2* p) {
    if ((p->unknown_3cd_ & 8) == 0 && (p->unknown_3cd_ & 2) == 0) {
        return 0;
    }
    BackgroundLoader* var0 = BackgroundLoader::GetInstance();
    unsigned int n = p->unknown_3c8_0_;
    if (n == 0) {
        if (p->unknown_340_ >= 0) {
            var0->RemoveTask(p->unknown_340_);
            p->unknown_340_ = -1;
        }
        p->unknown_340_ = var0->QueueLoadFile(data_020f1394, 0);
        p->unknown_3cd_ &= ~8;
        p->unknown_3cd_ |= 2;
        p->unknown_3c8_0_ = p->unknown_3c8_0_ + 1;
    } else {
        void* out1;
        void* file;
        unsigned int length;
        int size;
        if (n == 1 && var0->GetTaskStatus(p->unknown_340_) != 0) {
            var0->GetLoadedFileByID(p->unknown_340_, &file, &length);
            int count = Pac_CountFiles((struct PacRecord*)file);
            p->unknown_3c8_7_ = func_020938cc();
            int value = func_020937f0(p->unknown_3c8_7_);
            if (value != 0) {
                struct Struct_020941f8 ctx;
                int i;
                SpriteContext_Init((char*)&ctx);
                SpriteContext_Init((char*)&ctx);
                ctx.unknown_50_ = (unsigned char)p->unknown_3c8_7_;
                ctx.field44 = value - 0xa00;
                for (i = 0; i < count; i++) {
                    void* rec;
                    size = 0;
                    rec = Pac_GetFile((struct PacRecord*)file, i, &out1, &size);
                    SpriteContext_LoadFile(&ctx, rec, size, 0);
                }
                SpriteContext_Destroy(&ctx);
            }
            var0->RemoveTask(p->unknown_340_);
            p->unknown_340_ = -1;
            p->unknown_3cd_ &= ~2;
            p->unknown_3c8_0_ = 0;
            if (p->unknown_3cb_ > 0) {
                p->unknown_3cd_ |= 1;
            }
        }
    }
    return 1;
}
