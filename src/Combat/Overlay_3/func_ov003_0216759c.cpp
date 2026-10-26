#include "Combat/MenuNodeChain.h"
#include "Combat/MapDisplay.h"
#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"

struct View6759c {
    int value; SafeAllocator* alloc; BackgroundGraphics* lists; Node0207f7f0* objects; Manager0207f7f0* manager;
#if defined(jpn)
    char unknown_14_[0x34-0x14];
#else
    char unknown1_14_[0x64-0x14];
#endif
    int unknown_64_; char unknown_68_[8]; int unknown_70_; unsigned char unknown_74_; unsigned char unknown_75_; signed char unknown_76_;
};
struct Struct_ov003_0216759c_2 { char unknown_0_[8]; unsigned int unknown_8_; void* unknown_c_; };
extern "C" {
void* __clear(void*, int);
void _Z15Background_InitP18BackgroundGraphics(void*);
void _Z21Background_SetMapSizePhi(void*, int);
void Background_SetPriority(void*, int);
void _Z22Background_AllocateMapP18BackgroundGraphicsP13SafeAllocator(void*,SafeAllocator*);
void _Z20Background_SetScrollP18BackgroundGraphicsii(void*,int,int);
void _Z26Background_AllocateScreensP18BackgroundGraphicsiP13SafeAllocator(void*,int,SafeAllocator*);
void DisableSubBGVRAMBanks();
void MapVRAMBanksToSubBG(int);
int _Z14Pac_CountFilesP9PacRecord(void*);
void* _Z11Pac_GetFileP9PacRecordiPPvPi(void*,int,void**,int*);
void Background_LoadFile(void*,void*,SafeAllocator*,int);
void Background_FillRect(void*,int,int,int,int,int,int);
void _Z20Background_UploadMapP18BackgroundGraphicsPv(void*,void*);
Entry6759c* _Z20Background_GetScreenP18BackgroundGraphicsj(void*,unsigned int);
void _Z25CleanInvalidateCacheRangePKvj(const void*,unsigned int);
void LoadToSubBG1ScreenData(void*,int,unsigned int);
void WindowPane_Init(void*);
void _Z25WindowPane_AllocateBufferP10WindowPaneP13SafeAllocatorij(void*,SafeAllocator*,int,unsigned int);
#if defined(jpn)
void func_02080654(void*,SafeAllocator*,const char*);
#else
void func_0207f914(void*,SafeAllocator*,const char*,const char*);
#endif
int func_0207f9f4(void*);
void LoadToSubBGStandardPalette(const void*,unsigned int,unsigned int);
void _Z15CleanCacheRangePKvj(const void*,unsigned int);
void func_0207fe44(void*);
void func_ov003_02167a5c(void*,int,int);
}
extern char data_ov003_021800a4[];
extern char data_ov003_021800bb[];
extern char data_ov003_021800d5[];
extern unsigned short data_ov003_0217f4dc[];
#if defined(jpn)
extern char data_ov003_0217e87f[];
#endif

// USA: func_ov003_0216759c
extern "C" ARM int func_ov003_0216759c(Struct_ov003_0216759c* arg0) {
    if (arg0->unknown_74_ != 0) return 1;
    int var0 = 1;
    BackgroundLoader* var1 = BackgroundLoader::GetInstance();
    if (arg0->unknown_75_ == 0) {
        *(volatile unsigned int*)0x4001010 = 0;
        *(volatile unsigned int*)0x4001014 = 0;
        SafeAllocator* alloc = self->alloc;
        alloc->Reset();
        self->lists = (BackgroundGraphics*)alloc->Allocate(0x40);
        int words[2];
        __clear(words, sizeof(words));
        BackgroundGraphics* list;
        for (int i=0; i<2; i++) {
            list = self->lists+i;
            _Z15Background_InitP18BackgroundGraphics(list);
            _Z21Background_SetMapSizePhi(list, words[i]);
            list->subScreen_=1;
            list->bgNumber_=i;
            Background_SetPriority(list,i);
            _Z22Background_AllocateMapP18BackgroundGraphicsP13SafeAllocator(list,alloc);
            _Z20Background_SetScrollP18BackgroundGraphicsii(list,0,0);
        }
        _Z26Background_AllocateScreensP18BackgroundGraphicsiP13SafeAllocator(self->lists+1,1,alloc);
        DisableSubBGVRAMBanks();
        MapVRAMBanksToSubBG(0x80);
        *(volatile unsigned short*)0x4001008 = (*(volatile unsigned short*)0x4001008 & 0x43) | 0xe00;
        *(volatile unsigned short*)0x400100a = (*(volatile unsigned short*)0x400100a & 0x43) | 0xf00;
        *(volatile unsigned short*)0x4001050 = 0;
        loader->FreeAllocations();
        self->task = loader->QueueLoadFile(data_ov003_021800a4,0);
        self->stage++;
        result=0;
    } else if (self->stage == 1) {
        if (loader->GetTaskStatus(self->task) != 0) {
            void* out; void* data; unsigned int size; int value;
            loader->GetLoadedFileByID(self->task,&data,&size);
            int count = _Z14Pac_CountFilesP9PacRecord(data);
            SafeAllocator* alloc=self->alloc;
            BackgroundGraphics* list=self->lists;
            for (int i=0;i<count;i++) {
                void* record=_Z11Pac_GetFileP9PacRecordiPPvPi(data,i,&out,&value);
                if (record) {
                    Background_LoadFile(list,record,alloc,value);
                    list=self->lists+1;
                }
            }
            loader->RemoveTask(self->task);
            self->task=-1;
            list=self->lists;
            Background_FillRect(list,0,0,0,0x20,0x19,0);
            _Z20Background_UploadMapP18BackgroundGraphicsPv(list,0);
            Entry6759c* entry=_Z20Background_GetScreenP18BackgroundGraphicsj(self->lists+1,0);
            if (entry) {
                void* data; unsigned int size=entry->size; data=entry->data;
                _Z25CleanInvalidateCacheRangePKvj(data,size);
                LoadToSubBG1ScreenData(data,0,size);
            }
            alloc=self->alloc;
            alloc[1].Reset();
            self->objects=(Node0207f7f0*)alloc[1].Allocate(0x380);
            for (result=0;result<4;result++) {
                Node0207f7f0* obj=self->objects+result;
                WindowPane_Init(obj);
                _Z25WindowPane_AllocateBufferP10WindowPaneP13SafeAllocatorij(obj,alloc+1,self->value,0x600);
                obj->lists=self->lists;
            }
            arg0->unknown_75_++;
        }
        var0=0;
    } else if (arg0->unknown_75_ == 2) {
        SafeAllocator* var19=arg0->unknown_4_;
        var19[2].Reset();
#if defined(jpn)
        arg0->unknown_10_=(Struct_0207f7f0*)var19[2].Allocate(0x34);
#else
        arg0->unknown_10_=(Struct_0207f7f0*)var19[2].Allocate(0x40);
#endif
        func_0207f84c(arg0->unknown_10_);
#if defined(jpn)
        func_02080654(arg0->unknown_10_,var19+2,data_ov003_0217e87f);
#else
        func_0207f914(arg0->unknown_10_,var19+2,data_ov003_021800bb,data_ov003_021800d5);
#endif
        arg0->unknown_75_++;
        var0=0;
    } else if (arg0->unknown_75_ == 3) {
        int var20=func_0207f9f4(arg0->unknown_10_);
        if (var20==0) arg0->unknown_75_++;
        if (var20<0) arg0->unknown_74_=2;
        var0=0;
    } else if (arg0->unknown_75_ == 4) {
        *(volatile unsigned short*)0x4001008 &= ~3;
        *(volatile unsigned short*)0x400100a = (*(volatile unsigned short*)0x400100a & ~3) | 1;
        *(volatile unsigned short*)0x400100c = (*(volatile unsigned short*)0x400100c & ~3) | 2;
        *(volatile unsigned short*)0x400100e = (*(volatile unsigned short*)0x400100e & ~3) | 3;
        *(volatile unsigned int*)0x4001000 = (*(volatile unsigned int*)0x4001000 & ~0x1f00) | 0x1300;
        _Z25CleanInvalidateCacheRangePKvj(data_ov003_0217f4dc,2);
        LoadToSubBGStandardPalette(data_ov003_0217f4dc,2,2);
        _Z15CleanCacheRangePKvj(data_ov003_0217f4dc,2);
        _Z25CleanInvalidateCacheRangePKvj(data_ov003_0217f4dc,2);
        LoadToSubBGStandardPalette(data_ov003_0217f4dc,0x22,2);
        _Z15CleanCacheRangePKvj(data_ov003_0217f4dc,2);
        func_0207f7f0(arg0->unknown_10_,arg0->unknown_c_,4);
        Struct_0207f7f0* var21=arg0->unknown_10_;
        var21->unknown_2c_=arg0->unknown_8_;
        var21->unknown_38_=1;
        arg0->unknown_10_->unknown_3a_=0;
        arg0->unknown_74_=1;
        arg0->unknown_75_=0;
        if (arg0->unknown_70_ != 0 && arg0->unknown_76_>=0) {
            func_0207fe44(arg0->unknown_10_);
            signed char var22=arg0->unknown_76_;
            arg0->unknown_76_=-1;
            func_ov003_02167a5c(arg0,arg0->unknown_70_,var22);
        }
    }
    return var0;
}
