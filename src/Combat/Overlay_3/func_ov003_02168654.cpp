#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"

#if defined(jpn)
enum { Enum_ov003_02168654_128=0x7c, Enum_ov003_02168654_16=8 };
#else
enum { Enum_ov003_02168654_128=0x80, Enum_ov003_02168654_16=16 };
#endif
struct Struct_ov003_02168654_2 { char pad[0x1c]; unsigned char lo:4; unsigned char hi:4; char tail[3]; };
struct Struct_ov003_02168654_3 { int unused; void* list; char pad[0xd8]; };
struct Struct_ov003_02168654_4 { char pad[0x98]; void* list; char unknown_9c_[0x16]; unsigned char count; char tail[9]; };
struct Struct_ov003_02168654_5 {
    SafeAllocator alloc[4]; char pad[0x14]; char resource[Enum_ov003_02168654_128];
    Struct_ov003_02168654_4 entries; Struct_ov003_02168654_2 lists[2]; Struct_ov003_02168654_3 objects[3]; char records[0x3c];
    void* fieldA; void* fieldB; char unknown_4c4_[8]; short stride; char unknown_4ce_[2]; unsigned char flag;
    char unknown_4d1_[3]; void* unknown_4d4_; void* unknown_4d8_; char unknown_4dc_[4]; int task; void* buffer;
    unsigned char stage; char unknown_4e9_[3]; unsigned char state; char unknown_4ed_[0xb7];
    unsigned char active; unsigned char unknown_5a5_;
};
extern "C" {
void KeyTable_Load(void*,SafeAllocator*,void*,unsigned int);
extern "C" void Background_SetMapSize(void*,int);
void Background_SetPriority(void*,int);
extern "C" void Background_AllocateMap(void*,SafeAllocator*);
extern "C" void Background_SetScroll(void*,int,int);
void ColorEffect_ConfigureAlphaBlend(unsigned int*,unsigned char,unsigned char,unsigned char,int);
extern "C" int Pac_CountFiles(void*);
extern "C" void* Pac_GetFile(void*,int,void**,int*);
void Background_LoadFile(void*,void*,SafeAllocator*,int);
void Background_FillRect(void*,int,int,int,int,int,int);
extern "C" void Background_UploadMap(void*,void*);
extern "C" void WindowPane_AllocateBuffer(void*,SafeAllocator*,void*,unsigned int);
extern "C" void Window_SetPanes(void*,void*,unsigned char);
void SpriteContext_LoadFile(void*,void*,int,SafeAllocator*);
}
extern char data_ov003_021800e0[];
extern char data_ov003_021800fb[];
struct Struct_ov003_02168654 { unsigned char v[2]; };
struct Struct_ov003_0217f528 {
#if defined(jpn)
    Struct_ov003_02168654 mode; Struct_ov003_02168654 hi;
#else
    Struct_ov003_02168654 hi; Struct_ov003_02168654 mode;
#endif
};
extern const Struct_ov003_0217f528 data_ov003_0217f528;
extern char data_ov003_0218010d[];
extern char data_ov003_02180120[];
#if defined(jpn)
extern char data_ov003_0217e8a0[];
#endif

// USA: func_ov003_02168654
extern "C" ARM void func_ov003_02168654(Struct_ov003_02168654_5* self) {
    if (self->stage==0) {
#if defined(jpn)
        self->task=BackgroundLoader::GetInstance()->QueueLoadFile(data_ov003_0217e8a0,0);
#else
        self->task=BackgroundLoader::GetInstance()->QueueLoadFileInGP2(data_ov003_021800e0,data_ov003_021800fb,0);
#endif
        self->stage++;
    } else if (self->stage==1) {
        if (BackgroundLoader::GetInstance()->GetTaskStatus(self->task)!=0) {
            void* data; unsigned int size;
            BackgroundLoader::GetInstance()->GetLoadedFileByID(self->task,&data,&size);
            self->alloc[0].Reset();
            KeyTable_Load(self->resource,self->alloc,data,size);
            BackgroundLoader::GetInstance()->RemoveTask(self->task);
            self->task=-1;
            Struct_ov003_02168654 hi=data_ov003_0217f528.hi;
            Struct_ov003_02168654 mode=data_ov003_0217f528.mode;
            Struct_ov003_02168654_2* list;
            for (int i=0;i<2;i++) {
                list=self->lists+i;
                Background_SetMapSize(list,0);
                int h=hi.v[i]; int m=mode.v[i];
                list->lo=0;
                list->hi=h;
                Background_SetPriority(list,m);
                Background_AllocateMap(list,self->alloc+1);
                Background_SetScroll(list,0,0);
            }
            *(volatile unsigned short*)0x400000a=(*(volatile unsigned short*)0x400000a&0x43)|0x1d00;
            *(volatile unsigned short*)0x400000c=(*(volatile unsigned short*)0x400000c&0x43)|0x1e00;
            ColorEffect_ConfigureAlphaBlend((unsigned int*)0x4000050,2,1,10,6);
            self->task=BackgroundLoader::GetInstance()->QueueLoadFile(data_ov003_0218010d,0);
            self->stage++;
        }
    } else if (self->stage==2) {
        BackgroundLoader* loader=BackgroundLoader::GetInstance();
        if (loader->GetTaskStatus(self->task)!=0) {
            void* out; void* data; unsigned int size; void* records[2]; int values[2];
            loader->GetLoadedFileByID(self->task,&data,&size);
            int count=Pac_CountFiles(data);
            for (int i=0;i<count;i++) records[i]=Pac_GetFile(data,i,&out,values+i);
            for (int i=0;i<count;i++) {
                if (records[i]) {
                    Background_LoadFile(self->lists+1,records[i],self->alloc+1,values[i]);
                    Background_LoadFile(self->objects,records[i],self->alloc+1,values[i]);
                }
            }
            loader->RemoveTask(self->task);
            self->task=-1;
            Struct_ov003_02168654_2* list;
            for (int i=0;i<2;i++) {
                list=self->lists+i;
                Background_FillRect(list,0,0,0,0x20,0x19,0);
                Background_UploadMap(list,0);
            }
            self->alloc[2].Reset();
            self->buffer=self->alloc[2].Allocate(0x4000);
            Struct_ov003_02168654_3* obj;
            for (int i=0;i<3;i++) {
                obj=self->objects+i;
                WindowPane_AllocateBuffer(obj,self->alloc+1,self->buffer,0x400);
                obj->list=self->lists+1;
            }
            self->entries.list=self->lists;
            self->entries.count=2;
            Window_SetPanes(&self->entries,self->objects,3);
            self->stage++;
        }
    } else if (self->stage==3) {
        self->flag=0;
        self->fieldB=self->unknown_4d4_;
        self->stride=Enum_ov003_02168654_16;
        self->fieldA=self->unknown_4d8_;
        self->task=BackgroundLoader::GetInstance()->QueueLoadFile(data_ov003_02180120,0);
        self->stage++;
    } else if (self->stage==4) {
        BackgroundLoader* loader=BackgroundLoader::GetInstance();
        if (loader->GetTaskStatus(self->task)!=0) {
            void* out; void* data; unsigned int size; int value;
            loader->GetLoadedFileByID(self->task,&data,&size);
            int count=Pac_CountFiles(data);
            self->alloc[3].Reset();
            for (int i=0;i<count;i++) {
                void* record=Pac_GetFile(data,i,&out,&value);
                SpriteContext_LoadFile(self->records,record,value,self->alloc+3);
            }
            loader->RemoveTask(self->task);
            self->task=-1;
            self->stage++;
        }
    } else if (self->stage==5) {
        *(volatile unsigned short*)0x4000008=(*(volatile unsigned short*)0x4000008&~3)|2;
        *(volatile unsigned short*)0x400000a=(*(volatile unsigned short*)0x400000a&~3)|1;
        *(volatile unsigned short*)0x400000c&=~3;
        *(volatile unsigned short*)0x400000e=(*(volatile unsigned short*)0x400000e&~3)|3;
        *(volatile unsigned int*)0x4000000=(*(volatile unsigned int*)0x4000000&~0x1f00)|0x1700;
        self->state=1;
        self->stage=0;
        self->active=1;
        self->unknown_5a5_=0;
    }
}
