#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"

#if defined(jpn)
enum { Enum_ov003_02168654_128=0x7c, Enum_ov003_02168654_16=8 };
#else
enum { Enum_ov003_02168654_128=0x80, Enum_ov003_02168654_16=16 };
#endif
struct Struct_ov003_02168654_2 { char unknown_0_[0x1c]; unsigned char unknown_1c_0_:4; unsigned char unknown_1c_4_:4; char unknown_1d_[3]; };
struct Struct_ov003_02168654_3 { int unknown_0_; void* unknown_4_; char unknown_8_[0xd8]; };
struct Struct_ov003_02168654_4 { char unknown_0_[0x98]; void* unknown_98_; char unknown_9c_[0x16]; unsigned char unknown_b2_; char unknown_b3_[9]; };
struct Struct_ov003_02168654_5 {
    SafeAllocator unknown_0_[4]; char unknown_50_[0x14]; char unknown_64_[Enum_ov003_02168654_128];
    Struct_ov003_02168654_4 unknown_e4_; Struct_ov003_02168654_2 unknown_1a0_[2]; Struct_ov003_02168654_3 unknown_1e0_[3]; char unknown_480_[0x3c];
    void* unknown_4bc_; void* unknown_4c0_; char unknown_4c4_[8]; short unknown_4cc_; char unknown_4ce_[2]; unsigned char unknown_4d0_;
    char unknown_4d1_[3]; void* unknown_4d4_; void* unknown_4d8_; char unknown_4dc_[4]; int unknown_4e0_; void* unknown_4e4_;
    unsigned char unknown_4e8_; char unknown_4e9_[3]; unsigned char unknown_4ec_; char unknown_4ed_[0xb7];
    unsigned char unknown_5a4_; unsigned char unknown_5a5_;
};
extern "C" {
void KeyTable_Load(void*,SafeAllocator*,void*,unsigned int);
void _Z21Background_SetMapSizePhi(void*,int);
void Background_SetPriority(void*,int);
void _Z22Background_AllocateMapP19AllocTarget0204b12cP13SafeAllocator(void*,SafeAllocator*);
void _Z20Background_SetScrollP11Obj0204b5e8ii(void*,int,int);
void ColorEffect_ConfigureAlphaBlend(unsigned int*,unsigned char,unsigned char,unsigned char,int);
int _Z14Pac_CountFilesP19ActiveEntry02046900(void*);
void* _Z11Pac_GetFileP11Rec020467f0iPPvPi(void*,int,void**,int*);
void Background_LoadFile(void*,void*,SafeAllocator*,int);
void Background_FillRect(void*,int,int,int,int,int,int);
void _Z20Background_UploadMapP12List0204b0e8Pv(void*,void*);
void _Z25WindowPane_AllocateBufferP11Obj0204c7a8P13SafeAllocatorij(void*,SafeAllocator*,void*,unsigned int);
void _Z15Window_SetPanesP15Struct_0205cf78P13Elem_0205cf78h(void*,void*,unsigned char);
void SpriteContext_LoadFile(void*,void*,int,SafeAllocator*);
}
extern char data_ov003_021800e0[];
extern char data_ov003_021800fb[];
struct Struct_ov003_02168654 { unsigned char unknown_0_[2]; };
struct Struct_ov003_0217f528 {
#if defined(jpn)
    Struct_ov003_02168654 unknown_2_; Struct_ov003_02168654 unknown_0_;
#else
    Struct_ov003_02168654 unknown_0_; Struct_ov003_02168654 unknown_2_;
#endif
};
extern const Struct_ov003_0217f528 data_ov003_0217f528;
extern char data_ov003_0218010d[];
extern char data_ov003_02180120[];
#if defined(jpn)
extern char data_ov003_0217e8a0[];
#endif

// USA: func_ov003_02168654
extern "C" ARM void func_ov003_02168654(Struct_ov003_02168654_5* arg0) {
    if (arg0->unknown_4e8_==0) {
#if defined(jpn)
        arg0->unknown_4e0_=BackgroundLoader::GetInstance()->QueueLoadFile(data_ov003_0217e8a0,0);
#else
        arg0->unknown_4e0_=BackgroundLoader::GetInstance()->QueueLoadFileInGP2(data_ov003_021800e0,data_ov003_021800fb,0);
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
            Pair68654 hi=data_ov003_0217f528.hi;
            Pair68654 mode=data_ov003_0217f528.mode;
            List68654* list;
            for (int i=0;i<2;i++) {
                list=self->lists+i;
                _Z21Background_SetMapSizePhi(list,0);
                int h=hi.v[i]; int m=mode.v[i];
                list->lo=0;
                list->hi=h;
                Background_SetPriority(list,m);
                _Z22Background_AllocateMapP19AllocTarget0204b12cP13SafeAllocator(list,self->alloc+1);
                _Z20Background_SetScrollP11Obj0204b5e8ii(list,0,0);
            }
            *(volatile unsigned short*)0x400000a=(*(volatile unsigned short*)0x400000a&0x43)|0x1d00;
            *(volatile unsigned short*)0x400000c=(*(volatile unsigned short*)0x400000c&0x43)|0x1e00;
            ColorEffect_ConfigureAlphaBlend((unsigned int*)0x4000050,2,1,10,6);
            arg0->unknown_4e0_=BackgroundLoader::GetInstance()->QueueLoadFile(data_ov003_0218010d,0);
            arg0->unknown_4e8_++;
        }
    } else if (self->stage==2) {
        BackgroundLoader* loader=BackgroundLoader::GetInstance();
        if (loader->GetTaskStatus(self->task)!=0) {
            void* out; void* data; unsigned int size; void* records[2]; int values[2];
            loader->GetLoadedFileByID(self->task,&data,&size);
            int count=_Z14Pac_CountFilesP19ActiveEntry02046900(data);
            for (int i=0;i<count;i++) records[i]=_Z11Pac_GetFileP11Rec020467f0iPPvPi(data,i,&out,values+i);
            for (int i=0;i<count;i++) {
                if (records[i]) {
                    Background_LoadFile(self->lists+1,records[i],self->alloc+1,values[i]);
                    Background_LoadFile(self->objects,records[i],self->alloc+1,values[i]);
                }
            }
            loader->RemoveTask(self->task);
            self->task=-1;
            List68654* list;
            for (int i=0;i<2;i++) {
                list=self->lists+i;
                Background_FillRect(list,0,0,0,0x20,0x19,0);
                _Z20Background_UploadMapP12List0204b0e8Pv(list,0);
            }
            self->alloc[2].Reset();
            self->buffer=self->alloc[2].Allocate(0x4000);
            Obj68654* obj;
            for (int i=0;i<3;i++) {
                obj=self->objects+i;
                _Z25WindowPane_AllocateBufferP11Obj0204c7a8P13SafeAllocatorij(obj,self->alloc+1,self->buffer,0x400);
                obj->list=self->lists+1;
            }
            self->entries.list=self->lists;
            self->entries.count=2;
            _Z15Window_SetPanesP15Struct_0205cf78P13Elem_0205cf78h(&self->entries,self->objects,3);
            self->stage++;
        }
    } else if (self->stage==3) {
        self->flag=0;
        self->fieldB=self->dataA;
        self->stride=kStride;
        self->fieldA=self->dataB;
        self->task=BackgroundLoader::GetInstance()->QueueLoadFile(data_ov003_02180120,0);
        self->stage++;
    } else if (self->stage==4) {
        BackgroundLoader* loader=BackgroundLoader::GetInstance();
        if (loader->GetTaskStatus(self->task)!=0) {
            void* out; void* data; unsigned int size; int value;
            loader->GetLoadedFileByID(self->task,&data,&size);
            int count=_Z14Pac_CountFilesP19ActiveEntry02046900(data);
            self->alloc[3].Reset();
            for (int i=0;i<count;i++) {
                void* record=_Z11Pac_GetFileP11Rec020467f0iPPvPi(data,i,&out,&value);
                SpriteContext_LoadFile(self->records,record,value,self->alloc+3);
            }
            var21->RemoveTask(arg0->unknown_4e0_);
            arg0->unknown_4e0_=-1;
            arg0->unknown_4e8_++;
        }
    } else if (arg0->unknown_4e8_==5) {
        *(volatile unsigned short*)0x4000008=(*(volatile unsigned short*)0x4000008&~3)|2;
        *(volatile unsigned short*)0x400000a=(*(volatile unsigned short*)0x400000a&~3)|1;
        *(volatile unsigned short*)0x400000c&=~3;
        *(volatile unsigned short*)0x400000e=(*(volatile unsigned short*)0x400000e&~3)|3;
        *(volatile unsigned int*)0x4000000=(*(volatile unsigned int*)0x4000000&~0x1f00)|0x1700;
        arg0->unknown_4ec_=1;
        arg0->unknown_4e8_=0;
        arg0->unknown_5a4_=1;
        arg0->unknown_5a5_=0;
    }
}
