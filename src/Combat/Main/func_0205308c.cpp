#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"
#include "World/Object3D.h"

#if defined(jpn)
#define data_020e7bf8 data_020e85d0
extern char data_020f04d0;
#endif

struct Struct_02052e2c;

struct Struct_0205308c {
#if defined(jpn)
    char unknown_0_[0x174];
#else
    char unknown1_0_[0x180];
#endif
    int unknown_180_;
    char unknown_184_[0x194 - 0x184];
    int unknown_194_;
};

short* GetField150Ptr0x488_02052e2c(struct Field150Holder02052e2c*);
extern "C" void* Zone3D_GetInstance(void);
extern "C" void VectorizedMemset(void* dst, int value, unsigned int size);

extern signed char data_020e7bf8[];
extern char data_020f0434;
extern char data_020f044c;
extern char data_020f045c;
extern char data_020f0467;

struct Struct_0205308c_2 {
    unsigned char unknown_0_0_ : 1;
    unsigned char unknown_0_1_ : 7;
};

// USA: func_0205308c
extern "C" ARM void func_0205308c(void* arg0, int arg1) {
    struct Struct_0205308c* var0 = (struct Struct_0205308c*)arg0;
    char var1[0x50];
    short* var2 = func_02052e2c((struct Struct_02052e2c*)arg0);
    BackgroundLoader* var3;
    int var4;

    sprintf(var1, &data_020f0434, arg1, data_020e7bf8[((struct Struct_0205308c_2*)((char*)var2 + 0x14))->unknown_0_0_]);

    var3 = BackgroundLoader::GetInstance();
    if (var0->unknown_180_ > BackgroundLoader::TaskStatus_Invalid) {
        var3->RemoveTask(var0->unknown_180_);
        var0->unknown_180_ = -1;
    }
    var0->unknown_180_ = var3->QueueLoadFile(var1, 0);

    {
        unsigned short gid = *(unsigned short*)Zone3D_GetInstance();
        if (gid != ((Object3D*)obj)->GetField06()) {
            return;
        }
    }

#if defined(jpn)
    if (arg1 != 0xc && arg1 != 0xd && arg1 != 0xe &&
        arg1 != 0xf && arg1 != 0x10 && arg1 != 0x1e) {
        return;
    }
    VectorizedMemset(var1, 0, 0x50);
    sprintf(var1, &data_020f04d0, arg1);
#else
    var4 = 0;
    switch (arg1) {
        case 0xc:
        case 0xd:
        case 0xe:
            VectorizedMemset(var1, 0, 0x50);
            sprintf(var1, &data_020f044c, arg1);
            var4 = 1;
            break;
        case 0xf:
        case 0x10:
        case 0x1e:
            VectorizedMemset(var1, 0, 0x50);
            sprintf(var1, &data_020f045c, arg1);
            var4 = 1;
            break;
    }

    if (var4 == 0) {
        return;
    }
#endif
    if (var0->unknown_194_ > BackgroundLoader::TaskStatus_Invalid) {
        var3->RemoveTask(var0->unknown_194_);
        var0->unknown_194_ = -1;
    }
#if defined(jpn)
    var0->unknown_194_ = var3->QueueLoadFile(var1, 0);
#else
    var0->unknown_194_ = var3->QueueLoadFileInGP2(&data_020f0467, var1, 0);
#endif
}
