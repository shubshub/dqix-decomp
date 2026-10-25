#include <globaldefs.h>
#include "Graphics/Model3D.h"
#include "Memory/SafeAllocator.h"
#include "World/Zone3D.h"
#include "Filesystem/FileIO.h"

#if defined(jpn)
#define data_020ef22c data_020ef168
#define data_020ef233 data_020ef16f
#define data_020ef242 data_020ef17e
#define data_020ef251 data_020ef18d
#define data_020ef260 data_020ef19c
#endif

extern char data_020ef22c[];
extern char data_020ef233[];
extern char data_020ef242[];
extern char data_020ef251[];
extern char data_020ef260[];

void NNS_GfdGetFrmTexVramState(int*);
void NNS_GfdSetFrmTexVramState(int*);
extern "C" void __clear(void* buf, int len);
extern "C" void* _ZN7Model3DC1Ev(void*);
extern "C" void* _ZN7Model3DD1Ev(void*);
extern "C" void func_02018f30(unsigned char*);

// USA: func_02018d28
extern "C" ARM void func_02018d28(Zone3D* arg0, SafeAllocator* arg1, void* arg2, unsigned int arg3) {
    unsigned int var0;
    int var1[10];
    Model3D* var2[3];
    Model3D* var3[3];
    char var4[0x50];
    Model3D var5;
    Model3D var6;
    void* var7;
    int* var8;
    Model3D** var9;
    int* var10;
    Model3D** var11;

    NNS_GfdGetFrmTexVramState(backup);
    _ZN7Model3DC1Ev(&localB);
    localB.Clear();
    sprintf(path, data_020ef22c, data_020ef233);
    if ((data = LoadFileIntoNewAllocation(path, *alloc, &size)) != 0) {
        localB.SetAndProcessRawFile(data, size, Model3D::TextureStagingMode_Normal);
    }
    _ZN7Model3DC1Ev(&var6);
    var6.Clear();
    sprintf(var4, data_020ef22c, data_020ef242);
    if ((var7 = LoadFileIntoNewAllocation(var4, *arg1, &var0)) != 0) {
        var6.SetAndProcessRawFile(var7, var0, Model3D::TextureStagingMode_Normal);
    }

    __clear(var2, 0xc);
    var2[0] = &var5;
    var2[1] = &var6;
    var8 = &arg0->unknown_5f0_[2];
    var9 = var2;
    while (*var9 != 0) {
        NSBXXTex* var12 = (*var9)->GetTEX0();
        if (var12 != 0) {
            *var8 = var12->block4VRAMLoadOffset_;
        }
        var9++;
        var8++;
    }

    alloc->Reset();
    NNS_GfdSetFrmTexVramState(backup);
    sprintf(path, data_020ef22c, data_020ef251);
    if ((data = LoadFileIntoNewAllocation(path, *alloc, &size)) != 0) {
        self->models_498_[0].SetAndProcessRawFile(data, size, Model3D::TextureStagingMode_Normal);
    }
    sprintf(var4, data_020ef22c, data_020ef260);
    if ((var7 = LoadFileIntoNewAllocation(var4, *arg1, &var0)) != 0) {
        arg0->models_498_[1].SetAndProcessRawFile(var7, var0, Model3D::TextureStagingMode_Normal);
    }

    __clear(var3, 0xc);
    var3[0] = &arg0->models_498_[0];
    var3[1] = &arg0->models_498_[1];
    var10 = arg0->unknown_5f0_;
    var11 = var3;
    while (*var11 != 0) {
        NSBXXTex* var13 = (*var11)->GetTEX0();
        if (var13 != 0) {
            *var10 = var13->block4VRAMLoadOffset_;
        }
        var11++;
        var10++;
    }

    func_02018f30((unsigned char*)arg0);
    _ZN7Model3DD1Ev(&var6);
    _ZN7Model3DD1Ev(&var5);
}
