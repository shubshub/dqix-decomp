#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "Filesystem/BackgroundLoader.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "std_library_functions.h"
#include "Resource/Brightness.h"
struct Obj020397cc; struct ListHead02046b60; struct Foo0207df50; struct Base02010834; struct TailList020469b4; struct TailNode020469b4;
struct StateE468 {
    unsigned char tag,done; char pad2[6]; int state,timer; Vector3i position; int field1c,task;
    SafeAllocator allocator; unsigned char actors,pending; unsigned short zone; unsigned char field3c; unsigned char flag:1,unknown_3d_1_:7; unsigned char unknown_3e_,unknown_3f_; unsigned short field40;
    short x,y,z; unsigned char field48; unsigned char low:4,high:4;
};
struct Foo0207df50 { unsigned int first[10],second[10],unknown_50_,field54,unknown_58_[2],unknown_60_[2]; };
struct Struct_ov017_021be468_6 { char pad0[0x568]; Foo0207df50 saved; };
struct ActorE468 {
#if defined(jpn)
    char pad0[0x148];
#else
    char pad0[0x154];
#endif
    Struct_ov017_021be468_6* data;
};
struct Struct_ov017_021be468 { unsigned char bit0:1,unknown_0_1_:1,bit2:1,unknown_0_3_:1,unknown_0_4_:1,unknown_0_5_:1,unknown_0_6_:1,unknown_0_7_:1; };
struct Struct_ov017_021be468_2 {
    unsigned char active; char pad1[15]; unsigned char mode; Struct_ov017_021be468 flags; unsigned short field12;
    short field14,unknown_16_,field18,unknown_1a_,field1c; char pad1e[2]; int field20,field24,field28; Vector3i position,rotation,scale;
};
struct WorldE468 { unsigned short id; char pad2[2]; unsigned char field4; char pad5[2]; unsigned char unknown_7_,field8,field9,unknown_a_; signed char unknown_b_; unsigned char fieldc; char unknown_d_[3]; Vector3i position; unsigned short field1c; short unknown_1e_; int field20,field24,field28,field2c; char unknown_30_[0x6c-0x30]; short unknown_6c_; char unknown_6e_[2]; };
struct Struct_ov017_021be468_4 {
    unsigned char active,pending; char pad2[3]; unsigned char environment,rank,unknown_7_,field8;
    char unknown_9_[3]; int zone; Vector3i unknown_10_;
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
extern "C" void GameObject_DisableControl(Obj020397cc*,int); extern "C" void func_0201bf98(unsigned char*,int,int);
extern "C" int func_02046b60(ListHead02046b60*,int); extern "C" void func_02046b8c(void*,int); extern "C" void func_02046a8c(void*,void*);
extern "C" void func_ov017_021d2738(unsigned char,unsigned char); extern "C" int FieldTaskQueue_IsEmpty(void**); 
extern "C" void* FontBankLoader_GetInstance(); extern "C" void FontBankLoader_CancelLoads(void*); extern "C" void func_020a0cc4(unsigned int);
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion*,unsigned int); extern "C" void VramState_Rewind(Foo0207df50*);
extern "C" void func_02057e6c(void*,int,SafeAllocator*,void*,unsigned int,Foo0207df50*);
int IsMainBrightnessTransitionActive(GameResources*); extern "C" void GameState_GetPartyMemberIds(Base02010834*,int,int*,int*);
extern "C" void func_02057fb4(void*,int,void*); extern "C" void SePlayer_LoadExtraArchiveB(void*,int,int); extern "C" void SePlayer_PlayExtra(void*,int,int);
void SetBrightness(GameResources*,int,int);  extern "C" void func_ov017_02197528();
extern "C" WorldE468* GameState_GetZoneTransition(GameState*); extern "C" void VectorizedMemset(void*,int,int);
extern "C" void FieldTask_InitEnterZone(unsigned char*,int); extern "C" void func_020469b4(TailList020469b4*,TailNode020469b4*);
extern "C" void GameObject_EnableControl(void*); extern "C" void func_ov017_021beb48(StateE468*); extern "C" void SePlayer_UnloadExtraArchiveB(void*);

// Overlay 17, originally func_ov017_021be468 (USA/EUR 0x021be468, JPN 0x021bea28)
extern "C" ARM void FieldTask_LeaveGrotto(StateE468* self,ListHead02046b60* list) {
    GameState* game=GameState::GetInstance(); LinkSession_GetInstance();
    GameResources* resources=GetGameResources();
    GameObject* actor=game->GetLeader();
    void* battle=func_02057924(); BackgroundLoader* loader=BackgroundLoader::GetInstance(); unsigned char* zone=Zone3D_GetInstance();
    if(self->state==0) {
        GameObject_DisableControl((Obj020397cc*)actor,1); func_0201bf98(zone,1,0);
        if(func_02046b60(list,3)) func_02046b8c(list,3);
        else {
            if(func_02046b60(list,0x34)) func_02046a8c(list,resources->fieldTasks_[28]);
            if(func_02046b60(list,0x2e)) { func_02046a8c(list,resources->fieldTasks_[21]); func_ov017_021d2738((unsigned char)actor->obj3D_.actorIndex_,0); }
            if(FieldTaskQueue_IsEmpty((void**)resources->unknown_ptr_array_3700[0])) {
                SetFlags00(resources, 0x10); FontBankLoader_CancelLoads(FontBankLoader_GetInstance()); func_020a0cc4(0x2800);
                self->task=loader->QueueLoadFile(data_ov017_021d7e80,0); self->state++;
            }
        }
    } else if(self->state==1) {
        if(loader->GetTaskStatus(self->task)!=0) {
            if(loader->GetDetailedTaskStatus(self->task)!=2) { loader->RemoveTask(self->task); self->done=1; }
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
            Struct_ov017_021be468_2 params[5];
            for(int i=0;i<count;i++) {
                GameObject* member=game->GetGameObjectByIndex(ids[i]); if(member==NULL) continue;
                params[i].active=0; params[i].mode=1; params[i].field12=0;
                params[i].field14=-1; params[i].unknown_16_=-1; params[i].field18=-1; params[i].unknown_1a_=-1; params[i].field1c=-0x1000;
                params[i].field20=0; params[i].field24=0; params[i].field28=0;
                params[i].position.x=0; params[i].position.y=0; params[i].position.z=0;
                params[i].rotation.x=0; params[i].rotation.y=0; params[i].rotation.z=0;
                params[i].scale.x=0x1000; params[i].scale.y=0x1000; params[i].scale.z=0x1000;
                Struct_ov017_021be468_2* p=&params[i]; p->flags.bit0=0; p->flags.unknown_0_1_=0; p->flags.bit2=1; p->flags.unknown_0_3_=0; p->flags.unknown_0_4_=0; p->flags.unknown_0_5_=0; p->flags.unknown_0_6_=0; p->flags.unknown_0_7_=0;
                p->position=member->obj3D_.position_; p->scale=member->obj3D_.GetScale();
                func_02057fb4(battle,5,p);
            }
            self->state++;
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
            ClearFlags00(resources, 0x10); func_ov017_02197528();
            WorldE468* world=GameState_GetZoneTransition(game); VectorizedMemset(world,0,0x70);
            world->field4=1; world->field8=1; world->field9=1; world->unknown_b_=-1;
            world->field20=-1; world->field24=-1; world->field28=-1; world->field2c=-1; world->unknown_1e_=-1; world->fieldc=0; world->unknown_6c_=-1;
            world->id=self->field1c; world->unknown_7_=1; world->field1c=0x3244; world->position=self->position;
            TailList020469b4* nodes=(TailList020469b4*)resources->fieldTaskQueue_; unsigned char* node=(unsigned char*)resources->unknown_ptr_array_3700[3];
            FieldTask_InitEnterZone(node,0); func_020469b4(nodes,(TailNode020469b4*)node);
            if(self->pending) {
                Struct_ov017_021be468_4* grotto=(Struct_ov017_021be468_4*)game->GetGrottoStruct();
                grotto->zone=self->zone; grotto->unknown_6c_=self->field3c;
                int active; if(self->flag) active=1; else active=0; grotto->active=active;
                grotto->unknown_10_.x=self->x<<7; grotto->unknown_10_.y=self->y<<7; grotto->unknown_10_.z=self->z<<7;
                grotto->unknown_83_=self->unknown_3e_; grotto->unknown_84_=self->unknown_3f_; grotto->unknown_86_=self->field40;
                grotto->rank=self->low; grotto->environment=self->high; grotto->field8=self->field48; grotto->pending=0; self->pending=0;
            }
            self->done=1; GameObject_EnableControl(actor); func_ov017_021beb48(self);
            SePlayer_UnloadExtraArchiveB(g_sePlayer);
        }
    }
}
