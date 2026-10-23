#include <globaldefs.h>
#include "GameState/GameState.h"
extern "C" int func_ov000_0216352c(int,float,float);
extern "C" void func_0202e7d4(unsigned char*,int*,int*,int*);
int fix32abs(int);
int Vector3fixSquaredDistance(const Vector3i*,const Vector3i*);
void SetFlagOrState0216d530(void*,int);
void Camera_SetTarget(unsigned char*,int,int,int);
void* GetActiveCombatWork_ov000_02160130();
extern "C" { void func_ov000_0216d370(void*,int,int,int); void func_0202e5d8(void*,int,int,int); void func_ov000_02167f10(void*); }
struct Struct_ov000_0216df00 { char unknown_0_[0x10]; Vector3i unknown_10_; char unknown_1c_[0x5c-0x1c]; int unknown_5c_,unknown_60_; char unknown_64_[0x220-0x64]; unsigned char unknown_220_; char unknown_221_[3]; int unknown_224_; char unknown_228_[0x23c-0x228]; int unknown_23c_; };
inline int inline_ov000_021537b8(int arg0) { return arg0>=0 && arg0<=3; }
inline int inline_ov000_0216df00(int arg0) { return arg0>=0xc0 && arg0<=0xc7; }
inline int inline_ov000_0216df00_2(int arg0,float arg1) { return arg0-(int)(4096.0f*arg1); }
inline int inline_ov000_0216df00_3(int arg0,int arg1) { return (int)(((long long)arg0*arg1+0x800)>>12); }
// USA: func_ov000_0216df00
extern "C" ARM void func_ov000_0216df00(Struct_ov000_0216df00* arg0,int arg1,int arg2,float arg3,float arg4) {
    GameObject* var0=GameState::GetInstance()->GetCombatantByIndex(arg1);
    if(!var0) return;
    int var1=0;
    if(arg0->unknown_224_==arg1 && arg0->unknown_220_==1 && arg2==0) var1=1;
    int var2=0;
    if(inline_ov000_021537b8(arg1)) var2=1;
    int var3=var0->obj3D_.GetHeight();
    int var4=var3/2;
    if(var4<0x1000) var4=0x1000;
    int var5=(var4+0x800)*arg0->unknown_60_/arg0->unknown_5c_;
    int var6=inline_ov000_0216df00_3(var3,0x1ccc)+0x4000;
    if(var2) var6=inline_ov000_0216df00_3(var3,(int)(4096.0f*arg4))+0x4000;
    if(inline_ov000_0216df00(arg1)) var6+=inline_ov000_0216df00_3(func_ov000_0216352c(arg1,1.5f,0.5f),0x1000);
    if(var6<var5) var6=var5;
    if(var1) {
        int var7=0,var8=0,var9=0;
        func_0202e7d4((unsigned char*)arg0,&var7,&var8,&var9);
        if(var7==0) {
            int var10=inline_ov000_0216df00_3(var6,0x400);
            if(fix32abs(var9-var6)<var10) {
                Vector3i var11(arg0->unknown_10_), var12;
                var12.z=0; var12.x=0; var12.y=var4;
                if(Vector3fixSquaredDistance(&var11,&var12)<0x1000) return;
            }
        }
    }
    func_ov000_0216d370(self,1,1,1);
    self->mode=1;
    SetFlagOrState0216d530(self,id);
    if(party) { int y=HeightOffset(half,offset); Camera_SetTarget((unsigned char*)self,0,y,0); }
    else Camera_SetTarget((unsigned char*)self,0,half,0);
    int low=half-0x1800;
    if(low<0) low=0;
    func_0202e5d8(self,0,low,distance);
    self->angle=-20;
    Vector3i pos(unit->obj3D_.position_);
    int coordinates[2]={pos.x,pos.z};
    int changed=0;
    int* coordinate=coordinates;
    for(int i=0;i<2;i++,coordinate++) {
        if(*coordinate>0x6000) { *coordinate=0x6000; changed=1; }
        else if(*coordinate<-0x6000) { *coordinate=-0x6000; changed=1; }
    }
    var15.x=var16[0]; var15.z=var16[1];
    if(var17) {
        var15.y=0xcc;
        func_ov000_02167f10(func_ov000_02160130());
        var0->obj3D_.position_=var15;
    }
}
