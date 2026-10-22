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
extern AllocatorUnion data_02114e20; extern char data_ov017_021d7e80[]; extern char g_sePlayer[];
extern "C" void func_0202ae18(); extern "C" void* func_02057924(); extern "C" unsigned char* func_02012fe4();
extern "C" void func_020397cc(Struct_02018300_3*,int); extern "C" void func_0201bf98(unsigned char*,int,int);
extern "C" int func_02046b60(Struct_02038598_5*,int); extern "C" void func_02046b8c(void*,int); extern "C" void func_02046a8c(void*,void*);
extern "C" void func_ov017_021d2738(unsigned char,unsigned char); extern "C" int func_02046b08(void**); 
extern "C" void* func_02094a00(); extern "C" void func_02094ab0(void*); extern "C" void func_020a0cc4(unsigned int);
extern "C" void* func_02012d88(AllocatorUnion*,unsigned int); extern "C" void func_0207df50(Struct_0203d028*);
extern "C" void func_02057e6c(void*,int,SafeAllocator*,void*,unsigned int,Struct_0203d028*);
int IsMainBrightnessTransitionActive(GameResources*); extern "C" void func_02010834(Struct_02010834*,int,int*,int*);
extern "C" void func_02057fb4(void*,int,void*); extern "C" void func_0205ebc0(void*,int,int); extern "C" void func_0205ebfc(void*,int,int);
void SetBrightness(GameResources*,int,int);  extern "C" void func_ov017_02197528();
extern "C" Struct_ov017_021be468_3* func_0200fd0c(GameState*); extern "C" void VectorizedMemset(void*,int,int);
extern "C" void func_ov017_0219e310(unsigned char*,int); extern "C" void func_020469b4(Struct_0201bdac_2*,Struct_0201bdac*);
extern "C" void func_020397c0(void*); extern "C" void func_ov017_021beb48(Struct_ov017_021be468_5*); extern "C" void func_0205ebec(void*);

// USA: func_ov017_021be468
extern "C" ARM void func_ov017_021be468(Struct_ov017_021be468_5* arg0,Struct_02038598_5* arg1) {
    GameState* var0=GameState::GetInstance(); func_0202ae18();
    GameResources* var1=GetGameResources();
    GameObject* var2=var0->GetUnknownGameObject();
    void* var3=func_02057924(); BackgroundLoader* var4=BackgroundLoader::GetInstance(); unsigned char* var5=func_02012fe4();
    if(arg0->unknown_8_==0) {
        func_020397cc((Struct_02018300_3*)var2,1); func_0201bf98(var5,1,0);
        if(func_02046b60(arg1,3)) func_02046b8c(arg1,3);
        else {
            if(func_02046b60(arg1,0x34)) func_02046a8c(arg1,var1->unknown_ptr_array_3afc[28]);
            if(func_02046b60(arg1,0x2e)) { func_02046a8c(arg1,var1->unknown_ptr_array_3afc[21]); func_ov017_021d2738((unsigned char)var2->obj3D_.unknown_4_,0); }
            if(func_02046b08((void**)var1->unknown_ptr_array_36fc[1])) {
                SetFlags00(var1, 0x10); func_02094ab0(func_02094a00()); func_020a0cc4(0x2800);
                arg0->unknown_20_=var4->QueueLoadFile(data_ov017_021d7e80,0); arg0->unknown_8_++;
            }
        }
    } else if(arg0->unknown_8_==1) {
        if(var4->GetTaskStatus(arg0->unknown_20_)!=0) {
            if(var4->GetDetailedTaskStatus(arg0->unknown_20_)!=2) { var4->RemoveTask(arg0->unknown_20_); arg0->unknown_1_=1; }
            {
                unsigned int var6; void* var7; var4->GetLoadedFileByID(arg0->unknown_20_,&var7,&var6);
                arg0->unknown_24_.CreateTypeA(func_02012d88(&data_02114e20,0x2800),0x2800); arg0->unknown_24_.Reset();
                Struct_0203d028* var8=&((Struct_ov017_021be468_7*)var0->GetUnknownGameObject())->unknown_154_->unknown_568_;
                func_0207df50(var8);
                void* var9=arg0->unknown_24_.Allocate(var6); memcpy(var9,var7,var6);
                func_02057e6c(var3,5,&arg0->unknown_24_,var9,var6,var8); var4->RemoveTask(arg0->unknown_20_); arg0->unknown_8_++;
            }
        }
    } else if(arg0->unknown_8_==2) {
        if(!IsMainBrightnessTransitionActive(var1)) {
            int var10[5],var11=0; func_02010834((Struct_02010834*)var0,var2->obj3D_.unknown_4_,var10,&var11);
            for(int var12=0;var12<var11;var12++) arg0->unknown_38_|=1<<var10[var12];
            Struct_ov017_021be468_2 var13[5];
            for(int var14=0;var14<var11;var14++) {
                GameObject* var15=var0->GetGameObjectByIndex(var10[var14]); if(var15==NULL) continue;
                var13[var14].unknown_0_=0; var13[var14].unknown_10_=1; var13[var14].unknown_12_=0;
                var13[var14].unknown_14_=-1; var13[var14].unknown_16_=-1; var13[var14].unknown_18_=-1; var13[var14].unknown_1a_=-1; var13[var14].unknown_1c_=-0x1000;
                var13[var14].unknown_20_=0; var13[var14].unknown_24_=0; var13[var14].unknown_28_=0;
                var13[var14].unknown_2c_.x=0; var13[var14].unknown_2c_.y=0; var13[var14].unknown_2c_.z=0;
                var13[var14].unknown_38_.x=0; var13[var14].unknown_38_.y=0; var13[var14].unknown_38_.z=0;
                var13[var14].unknown_44_.x=0x1000; var13[var14].unknown_44_.y=0x1000; var13[var14].unknown_44_.z=0x1000;
                Struct_ov017_021be468_2* var16=&var13[var14]; var16->unknown_11_.unknown_0_0_=0; var16->unknown_11_.unknown_0_1_=0; var16->unknown_11_.unknown_0_2_=1; var16->unknown_11_.unknown_0_3_=0; var16->unknown_11_.unknown_0_4_=0; var16->unknown_11_.unknown_0_5_=0; var16->unknown_11_.unknown_0_6_=0; var16->unknown_11_.unknown_0_7_=0;
                var16->unknown_2c_=var15->obj3D_.position_; var16->unknown_44_=var15->obj3D_.GetScale();
                func_02057fb4(var3,5,var16);
            }
            arg0->unknown_8_++;
        }
    } else if(self->state==3) {
        self->timer++;
        if(self->timer==5) { SetForwardAndStore0205ebc0(g_sePlayer,0xb1,0xb1); DispatchIfField0xc4NonNeg_0205ebfc(g_sePlayer,0,0); }
        if(self->timer>25) {
            for(int i=0;i<5;i++) if(self->actors&(1<<i)) { GameObject* member=game->GetGameObjectByIndex(i); if(member!=NULL) member->obj3D_.EnableFlag(1); }
            self->state++;
        }
    } else if(arg0->unknown_8_==4) {
        arg0->unknown_c_++; if(arg0->unknown_c_>55) { SetBrightness(var1,-16,30); arg0->unknown_8_++; }
    } else if(arg0->unknown_8_==5) {
        arg0->unknown_c_++;
        if(arg0->unknown_c_>85) {
            for(int var19=0;var19<5;var19++) if(arg0->unknown_38_&(1<<var19)) { GameObject* var20=var0->GetGameObjectByIndex(var19); if(var20!=NULL) var20->obj3D_.DisableFlag(1); }
            ClearFlags00(var1, 0x10); func_ov017_02197528();
            Struct_ov017_021be468_3* var21=func_0200fd0c(var0); VectorizedMemset(var21,0,0x70);
            var21->unknown_4_=1; var21->unknown_8_=1; var21->unknown_9_=1; var21->unknown_b_=-1;
            var21->unknown_20_=-1; var21->unknown_24_=-1; var21->unknown_28_=-1; var21->unknown_2c_=-1; var21->unknown_1e_=-1; var21->unknown_c_=0; var21->unknown_6c_=-1;
            var21->unknown_0_=arg0->unknown_1c_; var21->unknown_7_=1; var21->unknown_1c_=0x3244; var21->unknown_10_=arg0->unknown_10_;
            Struct_0201bdac_2* var22=(Struct_0201bdac_2*)var1->unknown_ptr_array_36fc[0]; unsigned char* var23=(unsigned char*)var1->unknown_ptr_array_36fc[4];
            func_ov017_0219e310(var23,0); func_020469b4(var22,(Struct_0201bdac*)var23);
            if(arg0->unknown_39_) {
                Struct_ov017_021be468_4* var24=(Struct_ov017_021be468_4*)var0->GetGrottoStruct();
                var24->unknown_c_=arg0->unknown_3a_; var24->unknown_6c_=arg0->unknown_3c_;
                int var25; if(arg0->unknown_3d_0_) var25=1; else var25=0; var24->unknown_0_=var25;
                var24->unknown_10_.x=arg0->unknown_42_<<7; var24->unknown_10_.y=arg0->unknown_44_<<7; var24->unknown_10_.z=arg0->unknown_46_<<7;
                var24->unknown_83_=arg0->unknown_3e_; var24->unknown_84_=arg0->unknown_3f_; var24->unknown_86_=arg0->unknown_40_;
                var24->unknown_6_=arg0->unknown_49_0_; var24->unknown_5_=arg0->unknown_49_4_; var24->unknown_8_=arg0->unknown_48_; var24->unknown_1_=0; arg0->unknown_39_=0;
            }
            self->done=1; SetByteField0x253_020397c0(actor); func_ov017_021beb48(self);
            ForwardField0xc0_0205ebec(g_sePlayer);
        }
    }
}
