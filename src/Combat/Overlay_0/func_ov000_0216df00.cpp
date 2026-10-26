#include <globaldefs.h>
#include "GameState/GameState.h"
extern "C" int func_ov000_0216352c(int,float,float);
extern "C" void Camera_GetOrbit(unsigned char*,int*,int*,int*);
int fix32abs(int);
int Vector3fixSquaredDistance(const Vector3i*,const Vector3i*);
extern "C" void func_ov000_0216d530(void*,int);
extern "C" void Camera_SetTarget(struct Camera*,int,int,int);
extern "C" void* func_ov000_02160130();
extern "C" { void func_ov000_0216d370(void*,int,int,int); void Camera_SetOrbit(void*,int,int,int); void func_ov000_02167f10(void*); }
struct Camera { char p0[0x10]; Vector3i position; char p1[0x5c-0x1c]; int unknown_5c_,scale; char p2[0x220-0x64]; unsigned char mode; char p3[3]; int index; char p4[0x23c-0x228]; int angle; };
inline int inline_ov000_021537b8(int n) { return n>=0 && n<=3; }
inline int inline_ov000_0216df00(int n) { return n>=0xc0 && n<=0xc7; }
inline int HeightOffset(int h,float f) { return h-(int)(4096.0f*f); }
inline int inline_ov000_0216df00_3(int a,int b) { return (int)(((long long)a*b+0x800)>>12); }
// USA: func_ov000_0216df00
extern "C" ARM void func_ov000_0216df00(Camera* self,int id,int force,float offset,float arg4) {
    GameObject* unit=GameState::GetInstance()->GetCombatantByIndex(id);
    if(!unit) return;
    int var1=0;
    if(self->index==id && self->mode==1 && force==0) var1=1;
    int party=0;
    if(inline_ov000_021537b8(id)) party=1;
    int height=unit->obj3D_.GetHeight();
    int half=height/2;
    if(half<0x1000) half=0x1000;
    int minimum=(half+0x800)*self->scale/self->unknown_5c_;
    int distance=inline_ov000_0216df00_3(height,0x1ccc)+0x4000;
    if(party) distance=inline_ov000_0216df00_3(height,(int)(4096.0f*arg4))+0x4000;
    if(inline_ov000_0216df00(id)) distance+=inline_ov000_0216df00_3(func_ov000_0216352c(id,1.5f,0.5f),0x1000);
    if(distance<minimum) distance=minimum;
    if(var1) {
        int x=0,y=0,z=0;
        Camera_GetOrbit((unsigned char*)self,&x,&y,&z);
        if(x==0) {
            int var10=inline_ov000_0216df00_3(distance,0x400);
            if(fix32abs(z-distance)<var10) {
                Vector3i old(self->position), target;
                target.z=0; target.x=0; target.y=half;
                if(Vector3fixSquaredDistance(&old,&target)<0x1000) return;
            }
        }
    }
    func_ov000_0216d370(self,1,1,1);
    self->mode=1;
    func_ov000_0216d530(self,id);
    if(party) { int y=HeightOffset(half,offset); Camera_SetTarget((struct Camera*)self,0,y,0); }
    else Camera_SetTarget((struct Camera*)self,0,half,0);
    int low=half-0x1800;
    if(low<0) low=0;
    Camera_SetOrbit(self,0,low,distance);
    self->angle=-20;
    Vector3i pos(unit->obj3D_.position_);
    int coordinates[2]={pos.x,pos.z};
    int changed=0;
    int* var18=coordinates;
    for(int i=0;i<2;i++,var18++) {
        if(*var18>0x6000) { *var18=0x6000; changed=1; }
        else if(*var18<-0x6000) { *var18=-0x6000; changed=1; }
    }
    pos.x=coordinates[0]; pos.z=coordinates[1];
    if(changed) {
        pos.y=0xcc;
        func_ov000_02167f10(func_ov000_02160130());
        unit->obj3D_.position_=pos;
    }
}
