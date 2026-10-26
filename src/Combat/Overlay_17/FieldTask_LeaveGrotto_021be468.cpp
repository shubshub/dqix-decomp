#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "Filesystem/BackgroundLoader.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "std_library_functions.h"
#include "Resource/Brightness.h"
struct Struct_02018300_3; struct Struct_02038598_5; struct Struct_0203d028; struct Struct_02010834; struct Struct_0201bdac_2; struct Struct_0201bdac;
struct Struct_ov017_021be468_5 {
    unsigned char unknown_0_,unknown_1_; char unknown_2_[6]; int unknown_8_,unknown_c_; Vector3i unknown_10_; int unknown_1c_,unknown_20_;
    SafeAllocator unknown_24_; unsigned char unknown_38_,unknown_39_; unsigned short unknown_3a_; unsigned char unknown_3c_; unsigned char unknown_3d_0_:1,unknown_3d_1_:7; unsigned char unknown_3e_,unknown_3f_; unsigned short unknown_40_;
    short unknown_42_,unknown_44_,unknown_46_; unsigned char unknown_48_; unsigned char unknown_49_0_:4,unknown_49_4_:4;
};
struct Struct_0203d028 { unsigned int unknown_0_[10],unknown_28_[10],unknown_50_,unknown_54_,unknown_58_[2],unknown_60_[2]; };
struct Struct_ov017_021be468_6 { char unknown_0_[0x568]; Struct_0203d028 unknown_568_; };
struct Struct_ov017_021be468_7 {
#if defined(jpn)
    char unknown1_0_[0x148];
#else
    char unknown_0_[0x154];
#endif
    Struct_ov017_021be468_6* unknown_154_;
};
struct Struct_ov017_021be468 { unsigned char unknown_0_0_:1,unknown_0_1_:1,unknown_0_2_:1,unknown_0_3_:1,unknown_0_4_:1,unknown_0_5_:1,unknown_0_6_:1,unknown_0_7_:1; };
struct Struct_ov017_021be468_2 {
    unsigned char unknown_0_; char unknown_1_[15]; unsigned char unknown_10_; Struct_ov017_021be468 unknown_11_; unsigned short unknown_12_;
    short unknown_14_,unknown_16_,unknown_18_,unknown_1a_,unknown_1c_; char unknown_1e_[2]; int unknown_20_,unknown_24_,unknown_28_; Vector3i unknown_2c_,unknown_38_,unknown_44_;
};
struct Struct_ov017_021be468_3 { unsigned short unknown_0_; char unknown_2_[2]; unsigned char unknown_4_; char unknown_5_[2]; unsigned char unknown_7_,unknown_8_,unknown_9_,unknown_a_; signed char unknown_b_; unsigned char unknown_c_; char unknown_d_[3]; Vector3i unknown_10_; unsigned short unknown_1c_; short unknown_1e_; int unknown_20_,unknown_24_,unknown_28_,unknown_2c_; char unknown_30_[0x6c-0x30]; short unknown_6c_; char unknown_6e_[2]; };
struct Struct_ov017_021be468_4 {
    unsigned char unknown_0_,unknown_1_; char unknown_2_[3]; unsigned char unknown_5_,unknown_6_,unknown_7_,unknown_8_;
    char unknown_9_[3]; int unknown_c_; Vector3i unknown_10_;
#if defined(jpn)
    char unknown_1c_[0x4c-0x1c];
#else
    char unknown1_1c_[0x6c-0x1c];
#endif
    unsigned char unknown_6c_; char unknown_6d_[0x83-0x6d];
    unsigned char unknown_83_,unknown_84_,unknown_85_; unsigned short unknown_86_;
};
#if defined(jpn)
#define data_ov017_021d7e80 data_ov017_021d8693
#endif
extern AllocatorUnion g_mainAllocator; extern char data_ov017_021d7e80[]; extern char g_sePlayer[];
extern "C" void LinkSession_GetInstance(); extern "C" void* func_02057924(); extern "C" unsigned char* Zone3D_GetInstance();
void GameObject_DisableControl(Obj020397cc*,int); void SetOrClearBit_0201bf98(unsigned char*,int,int);
int ListContainsId(ListHead02046b60*,int); extern "C" void func_02046b8c(void*,int); extern "C" void func_02046a8c(void*,void*);
void EnqueueEventTag33_021d2738(unsigned char,unsigned char); int FieldTaskQueue_IsEmpty(void**); 
void* FontBankLoader_GetInstance(); extern "C" void FontBankLoader_CancelLoads(void*); extern "C" void func_020a0cc4(unsigned int);
void* AllocatorUnion_AllocateRounded(AllocatorUnion*,unsigned int); void VramState_Rewind(Foo0207df50*);
extern "C" void func_02057e6c(void*,int,SafeAllocator*,void*,unsigned int,Foo0207df50*);
int IsMainBrightnessTransitionActive(GameResources*); void GameState_GetPartyMemberIds(Base02010834*,int,int*,int*);
void FindNodeAndProcess02057fb4(void*,int,void*); void SePlayer_LoadExtraArchiveB(void*,int,int); void SePlayer_PlayExtra(void*,int,int);
void SetBrightness(GameResources*,int,int);  void CallListIfFlagsSet_02197528();
WorldE468* GameState_GetZoneTransition(GameState*); extern "C" void VectorizedMemset(void*,int,int);
void FieldTask_InitEnterZone(unsigned char*,int); void AppendNodeToTail(TailList020469b4*,TailNode020469b4*);
void GameObject_EnableControl(void*); extern "C" void func_ov017_021beb48(StateE468*); void SePlayer_UnloadExtraArchiveB(void*);

// Overlay 17, originally func_ov017_021be468 (USA/EUR 0x021be468, JPN 0x021bea28)
extern "C" ARM void FieldTask_LeaveGrotto(StateE468* self,ListHead02046b60* list) {
    GameState* game=GameState::GetInstance(); LinkSession_GetInstance();
    GameResources* resources=GetGameResources();
    GameObject* actor=game->GetLeader();
    void* battle=func_02057924(); BackgroundLoader* loader=BackgroundLoader::GetInstance(); unsigned char* zone=Zone3D_GetInstance();
    if(self->state==0) {
        GameObject_DisableControl((Obj020397cc*)actor,1); SetOrClearBit_0201bf98(zone,1,0);
        if(ListContainsId(list,3)) func_02046b8c(list,3);
        else {
            if(ListContainsId(list,0x34)) func_02046a8c(list,resources->fieldTasks_[28]);
            if(ListContainsId(list,0x2e)) { func_02046a8c(list,resources->fieldTasks_[21]); EnqueueEventTag33_021d2738((unsigned char)actor->obj3D_.actorIndex_,0); }
            if(FieldTaskQueue_IsEmpty((void**)resources->unknown_ptr_array_3700[0])) {
                SetFlags00(resources, 0x10); FontBankLoader_CancelLoads(FontBankLoader_GetInstance()); func_020a0cc4(0x2800);
                self->task=loader->QueueLoadFile(data_ov017_021d7e80,0); self->state++;
            }
        }
    } else if(arg0->unknown_8_==1) {
        if(var4->GetTaskStatus(arg0->unknown_20_)!=0) {
            if(var4->GetDetailedTaskStatus(arg0->unknown_20_)!=2) { var4->RemoveTask(arg0->unknown_20_); arg0->unknown_1_=1; }
            {
                unsigned int length; void* file; loader->GetLoadedFileByID(self->task,&file,&length);
                self->allocator.CreateTypeA(AllocatorUnion_AllocateRounded(&g_mainAllocator,0x2800),0x2800); self->allocator.Reset();
                Foo0207df50* source=&((ActorE468*)game->GetLeader())->data->saved;
                VramState_Rewind(source);
                void* copy=self->allocator.Allocate(length); memcpy(copy,file,length);
                func_02057e6c(battle,5,&self->allocator,copy,length,source); loader->RemoveTask(self->task); self->state++;
            }
        }
    } else if(self->state==2) {
        if(!IsMainBrightnessTransitionActive(resources)) {
            int ids[5],count=0; GameState_GetPartyMemberIds((Base02010834*)game,actor->obj3D_.actorIndex_,ids,&count);
            for(int i=0;i<count;i++) self->actors|=1<<ids[i];
            ParamsE468 params[5];
            for(int i=0;i<count;i++) {
                GameObject* member=game->GetGameObjectByIndex(ids[i]); if(member==NULL) continue;
                params[i].active=0; params[i].mode=1; params[i].field12=0;
                params[i].field14=-1; params[i].field16=-1; params[i].field18=-1; params[i].field1a=-1; params[i].field1c=-0x1000;
                params[i].field20=0; params[i].field24=0; params[i].field28=0;
                params[i].position.x=0; params[i].position.y=0; params[i].position.z=0;
                params[i].rotation.x=0; params[i].rotation.y=0; params[i].rotation.z=0;
                params[i].scale.x=0x1000; params[i].scale.y=0x1000; params[i].scale.z=0x1000;
                ParamsE468* p=&params[i]; p->flags.bit0=0; p->flags.bit1=0; p->flags.bit2=1; p->flags.bit3=0; p->flags.bit4=0; p->flags.bit5=0; p->flags.bit6=0; p->flags.bit7=0;
                p->position=member->obj3D_.position_; p->scale=member->obj3D_.GetScale();
                FindNodeAndProcess02057fb4(battle,5,p);
            }
            arg0->unknown_8_++;
        }
    } else if(self->state==3) {
        self->timer++;
        if(self->timer==5) { SePlayer_LoadExtraArchiveB(g_sePlayer,0xb1,0xb1); SePlayer_PlayExtra(g_sePlayer,0,0); }
        if(self->timer>25) {
            for(int i=0;i<5;i++) if(self->actors&(1<<i)) { GameObject* member=game->GetGameObjectByIndex(i); if(member!=NULL) member->obj3D_.EnableFlag(1); }
            self->state++;
        }
    } else if(self->state==4) {
        self->timer++; if(self->timer>55) { SetBrightness(resources,-16,30); self->state++; }
    } else if(self->state==5) {
        self->timer++;
        if(self->timer>85) {
            for(int i=0;i<5;i++) if(self->actors&(1<<i)) { GameObject* member=game->GetGameObjectByIndex(i); if(member!=NULL) member->obj3D_.DisableFlag(1); }
            ClearFlags00(resources, 0x10); CallListIfFlagsSet_02197528();
            WorldE468* world=GameState_GetZoneTransition(game); VectorizedMemset(world,0,0x70);
            world->field4=1; world->field8=1; world->field9=1; world->fieldb=-1;
            world->field20=-1; world->field24=-1; world->field28=-1; world->field2c=-1; world->field1e=-1; world->fieldc=0; world->field6c=-1;
            world->id=self->field1c; world->field7=1; world->field1c=0x3244; world->position=self->position;
            TailList020469b4* nodes=(TailList020469b4*)resources->fieldTaskQueue_; unsigned char* node=(unsigned char*)resources->unknown_ptr_array_3700[3];
            FieldTask_InitEnterZone(node,0); AppendNodeToTail(nodes,(TailNode020469b4*)node);
            if(self->pending) {
                GrottoViewE468* grotto=(GrottoViewE468*)game->GetGrottoStruct();
                grotto->zone=self->zone; grotto->field6c=self->field3c;
                int active; if(self->flag) active=1; else active=0; grotto->active=active;
                grotto->entrance.x=self->x<<7; grotto->entrance.y=self->y<<7; grotto->entrance.z=self->z<<7;
                grotto->field83=self->field3e; grotto->field84=self->field3f; grotto->field86=self->field40;
                grotto->rank=self->low; grotto->environment=self->high; grotto->field8=self->field48; grotto->pending=0; self->pending=0;
            }
            self->done=1; GameObject_EnableControl(actor); func_ov017_021beb48(self);
            SePlayer_UnloadExtraArchiveB(g_sePlayer);
        }
    }
}
