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

// data_020ef22c is "ARC:%s"; data_020ef251 and data_020ef260 are "T00GDS01.nsbmd" and "T00GDS02.nsbmd", the chest
// body and lid Zone3D_DrawChests draws; data_020ef233 and data_020ef242 are "T00GDS03.nsbmd" and "T00GDS04.nsbmd",
// loaded only for the body and lid palettes Zone3D_DrawChests' second pass uses
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
void Zone3D_ApplyChestDiffuseColor(unsigned char*);

// Main, originally func_02018d28 (USA 0x02018d28, EUR 0x02018d38, JPN 0x02018ac8)
extern "C" ARM void Zone3D_LoadChestModels(Zone3D* zone, SafeAllocator* allocator, void* archive, unsigned int archiveLength) {
    unsigned int size;
    int texVramState[10];
    Model3D* paletteModels[3];
    Model3D* chestModels[3];
    char path[0x50];
    Model3D bodyPaletteModel;
    Model3D lidPaletteModel;
    void* file;
    int* paletteOffset;
    Model3D** model;
    int* chestPaletteOffset;
    Model3D** chestModel;

    NNS_GfdGetFrmTexVramState(texVramState);
    _ZN7Model3DC1Ev(&bodyPaletteModel);
    bodyPaletteModel.Clear();
    sprintf(path, data_020ef22c, data_020ef233);
    if ((file = LoadFileIntoNewAllocation(path, *allocator, &size)) != 0) {
        bodyPaletteModel.SetAndProcessRawFile(file, size, Model3D::TextureStagingMode_Normal);
    }
    _ZN7Model3DC1Ev(&lidPaletteModel);
    lidPaletteModel.Clear();
    sprintf(path, data_020ef22c, data_020ef242);
    if ((file = LoadFileIntoNewAllocation(path, *allocator, &size)) != 0) {
        lidPaletteModel.SetAndProcessRawFile(file, size, Model3D::TextureStagingMode_Normal);
    }

    __clear(paletteModels, 0xc);
    paletteModels[0] = &bodyPaletteModel;
    paletteModels[1] = &lidPaletteModel;
    paletteOffset = &zone->chestPaletteOffsets_5f0_[2];
    model = paletteModels;
    while (*model != 0) {
        NSBXXTex* tex = (*model)->GetTEX0();
        if (tex != 0) {
            *paletteOffset = tex->block4VRAMLoadOffset_;
        }
        model++;
        paletteOffset++;
    }

    allocator->Reset();
    NNS_GfdSetFrmTexVramState(texVramState);
    sprintf(path, data_020ef22c, data_020ef251);
    if ((file = LoadFileIntoNewAllocation(path, *allocator, &size)) != 0) {
        zone->models_498_[0].SetAndProcessRawFile(file, size, Model3D::TextureStagingMode_Normal);
    }
    sprintf(path, data_020ef22c, data_020ef260);
    if ((file = LoadFileIntoNewAllocation(path, *allocator, &size)) != 0) {
        zone->models_498_[1].SetAndProcessRawFile(file, size, Model3D::TextureStagingMode_Normal);
    }

    __clear(chestModels, 0xc);
    chestModels[0] = &zone->models_498_[0];
    chestModels[1] = &zone->models_498_[1];
    chestPaletteOffset = zone->chestPaletteOffsets_5f0_;
    chestModel = chestModels;
    while (*chestModel != 0) {
        NSBXXTex* tex = (*chestModel)->GetTEX0();
        if (tex != 0) {
            *chestPaletteOffset = tex->block4VRAMLoadOffset_;
        }
        chestModel++;
        chestPaletteOffset++;
    }

    Zone3D_ApplyChestDiffuseColor((unsigned char*)zone);
    _ZN7Model3DD1Ev(&lidPaletteModel);
    _ZN7Model3DD1Ev(&bodyPaletteModel);
}
