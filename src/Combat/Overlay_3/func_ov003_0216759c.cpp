#include "Combat/MenuNodeChain.h"
#include "Combat/MapDisplay.h"
#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"

struct Struct_ov003_0216759c {
    int value; SafeAllocator* alloc; BackgroundGraphics* lists; Node0207f7f0* objects; Manager0207f7f0* manager;
#if defined(jpn)
    char pad[0x34-0x14];
#else
    char pad[0x64-0x14];
#endif
    int task; char pad2[8]; int selected; unsigned char unknown_74_; unsigned char stage; signed char pending;
};
struct Entry6759c { char pad[8]; unsigned int size; void* data; };
extern "C" {
void* __clear(void*, int);
extern "C" void Background_Init(void*);
extern "C" void Background_SetMapSize(void*, int);
void Background_SetPriority(void*, int);
extern "C" void Background_AllocateMap(void*,SafeAllocator*);
extern "C" void Background_SetScroll(void*,int,int);
extern "C" void Background_AllocateScreens(void*,int,SafeAllocator*);
void DisableSubBGVRAMBanks();
void MapVRAMBanksToSubBG(int);
extern "C" int Pac_CountFiles(void*);
extern "C" void* Pac_GetFile(void*,int,void**,int*);
void Background_LoadFile(void*,void*,SafeAllocator*,int);
void Background_FillRect(void*,int,int,int,int,int,int);
extern "C" void Background_UploadMap(void*,void*);
extern "C" Entry6759c* Background_GetScreen(void*,unsigned int);
void _Z25CleanInvalidateCacheRangePKvj(const void*,unsigned int);
void LoadToSubBG1ScreenData(void*,int,unsigned int);
void WindowPane_Init(void*);
extern "C" void WindowPane_AllocateBuffer(void*,SafeAllocator*,int,unsigned int);
#if defined(jpn)
void func_02080654(void*,SafeAllocator*,const char*);
#else
extern "C" void func_0207f914(void*,SafeAllocator*,const char*,const char*);
#endif
int func_0207f9f4(void*);
void LoadToSubBGStandardPalette(const void*,unsigned int,unsigned int);
void _Z15CleanCacheRangePKvj(const void*,unsigned int);
extern "C" void func_0207fe44(void*);
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
extern "C" ARM int func_ov003_0216759c(Struct_ov003_0216759c* self) {
    if (self->unknown_74_ != 0) return 1;
    int result = 1;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (self->stage == 0) {
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
            Background_Init(list);
            Background_SetMapSize(list, words[i]);
            list->subScreen_=1;
            list->bgNumber_=i;
            Background_SetPriority(list,i);
            Background_AllocateMap(list,alloc);
            Background_SetScroll(list,0,0);
        }
        Background_AllocateScreens(self->lists+1,1,alloc);
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
            int count = Pac_CountFiles(data);
            SafeAllocator* alloc=self->alloc;
            BackgroundGraphics* list=self->lists;
            for (int i=0;i<count;i++) {
                void* record=Pac_GetFile(data,i,&out,&value);
                if (record) {
                    Background_LoadFile(list,record,alloc,value);
                    list=self->lists+1;
                }
            }
            loader->RemoveTask(self->task);
            self->task=-1;
            list=self->lists;
            Background_FillRect(list,0,0,0,0x20,0x19,0);
            Background_UploadMap(list,0);
            Entry6759c* entry=Background_GetScreen(self->lists+1,0);
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
                WindowPane_AllocateBuffer(obj,alloc+1,self->value,0x600);
                obj->lists=self->lists;
            }
            self->stage++;
        }
        result=0;
    } else if (self->stage == 2) {
        SafeAllocator* alloc=self->alloc;
        alloc[2].Reset();
#if defined(jpn)
        self->manager=(Manager0207f7f0*)alloc[2].Allocate(0x34);
#else
        self->manager=(Manager0207f7f0*)alloc[2].Allocate(0x40);
#endif
        func_0207f84c(self->manager);
#if defined(jpn)
        func_02080654(self->manager,alloc+2,data_ov003_0217e87f);
#else
        func_0207f914(self->manager,alloc+2,data_ov003_021800bb,data_ov003_021800d5);
#endif
        self->stage++;
        result=0;
    } else if (self->stage == 3) {
        int status=func_0207f9f4(self->manager);
        if (status==0) self->stage++;
        if (status<0) self->unknown_74_=2;
        result=0;
    } else if (self->stage == 4) {
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
        func_0207f7f0(self->manager,self->objects,4);
        Manager0207f7f0* manager=self->manager;
        manager->lists=self->lists;
        manager->mode=1;
        self->manager->active=0;
        self->unknown_74_=1;
        self->stage=0;
        if (self->selected != 0 && self->pending>=0) {
            func_0207fe44(self->manager);
            signed char index=self->pending;
            self->pending=-1;
            func_ov003_02167a5c(self,self->selected,index);
        }
    }
    return result;
}
