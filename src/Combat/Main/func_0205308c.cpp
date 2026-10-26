#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"
#include "World/Object3D.h"

#if defined(jpn)
#define data_020e7bf8 data_020e85d0
extern char data_020f04d0;
#endif

struct Field150Holder02052e2c;

struct Struct_0205308c {
#if defined(jpn)
    char pad[0x174];
#else
    char pad[0x180];
#endif
    int unknown_180_;
    char unknown_184_[0x194 - 0x184];
    int unknown_194_;
};

extern "C" short* func_02052e2c(struct Field150Holder02052e2c*);
extern "C" void* Zone3D_GetInstance(void);
extern "C" void VectorizedMemset(void* dst, int value, unsigned int size);

extern signed char data_020e7bf8[];
extern char data_020f0434;
extern char data_020f044c;
extern char data_020f045c;
extern char data_020f0467;

struct Struct_0205308c_2 {
    unsigned char unknown_0_0_ : 1;
    unsigned char rest : 7;
};

// USA: func_0205308c
extern "C" ARM void func_0205308c(void* obj, int val) {
    struct Struct_0205308c* self = (struct Struct_0205308c*)obj;
    char buf[0x50];
    short* entries = func_02052e2c((struct Field150Holder02052e2c*)obj);
    BackgroundLoader* loader;
    int flag;

    sprintf(buf, &data_020f0434, val, data_020e7bf8[((struct Struct_0205308c_2*)((char*)entries + 0x14))->unknown_0_0_]);

    loader = BackgroundLoader::GetInstance();
    if (self->unknown_180_ > BackgroundLoader::TaskStatus_Invalid) {
        loader->RemoveTask(self->unknown_180_);
        self->unknown_180_ = -1;
    }
    self->unknown_180_ = loader->QueueLoadFile(buf, 0);

    {
        unsigned short gid = *(unsigned short*)Zone3D_GetInstance();
        if (gid != ((Object3D*)obj)->GetField06()) {
            return;
        }
    }

#if defined(jpn)
    if (val != 0xc && val != 0xd && val != 0xe &&
        val != 0xf && val != 0x10 && val != 0x1e) {
        return;
    }
    VectorizedMemset(buf, 0, 0x50);
    sprintf(buf, &data_020f04d0, val);
#else
    flag = 0;
    switch (val) {
        case 0xc:
        case 0xd:
        case 0xe:
            VectorizedMemset(buf, 0, 0x50);
            sprintf(buf, &data_020f044c, val);
            flag = 1;
            break;
        case 0xf:
        case 0x10:
        case 0x1e:
            VectorizedMemset(buf, 0, 0x50);
            sprintf(buf, &data_020f045c, val);
            flag = 1;
            break;
    }

    if (flag == 0) {
        return;
    }
#endif
    if (self->unknown_194_ > BackgroundLoader::TaskStatus_Invalid) {
        loader->RemoveTask(self->unknown_194_);
        self->unknown_194_ = -1;
    }
#if defined(jpn)
    self->unknown_194_ = loader->QueueLoadFile(buf, 0);
#else
    self->unknown_194_ = loader->QueueLoadFileInGP2(&data_020f0467, buf, 0);
#endif
}
