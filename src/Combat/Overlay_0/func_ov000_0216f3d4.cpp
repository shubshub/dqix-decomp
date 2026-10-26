#include <globaldefs.h>
#include "NitroSDK/Matrix.h"
#include "World/Object3D.h"
#include "GameState/GameState.h"
extern "C" void* func_ov000_02160130();
extern "C" float func_02049fec(char*);
struct Struct_02049f50;
extern "C" void func_02049f50(Struct_02049f50*,int,int);
extern "C" { int func_ov000_02153e40(void*,short*,int,int); int func_02049fc0(void*); }
struct Struct_ov000_0215b278 { char p0[0x20]; unsigned short id; char p1[0xe]; Struct_ov000_0215b278* next; };
struct Struct_ov000_0215440c_6 { char p0[0xe]; short ids[4]; unsigned char unknown_16_,count; char p1[8]; Struct_ov000_0215440c_6* next; };
struct Struct_ov000_021537b8 { char p0[0x10]; Struct_ov000_0215b278* nodes; Struct_ov000_0215440c_6* groups; };
struct Camera { char p0[4]; Vector3i position; char p1[0x21c-0x10]; void* list; unsigned char mode,unknown_221_; char p2[2]; int index; char p3[0x260-0x228]; unsigned char active,state,first,second; char p4[0x278-0x264]; unsigned char enabled; char p5[3]; Struct_ov000_021537b8* work; };
inline int inline_ov000_0216f3d4(int a) { return (int)(((long long)a*a+0x800)>>12); }
// USA: func_ov000_0216f3d4
extern "C" ARM void func_ov000_0216f3d4(Camera* self) {
    if(!self->list || !self->enabled) return;
    short ids[12];
    int count=func_ov000_02153e40(self->list,ids,12,0);
    GameState* gs=GameState::GetInstance();
    int duration=180;
    if(self->unknown_221_) { duration=0; self->unknown_221_=0; }
    short* id=ids;
    for(int i=0;i<count;i++,id++) {
        GameObject* unit=gs->GetCombatantByIndex(*id);
        if(!unit || !unit->obj3D_.IsVisible() || unit->obj3D_.GetInheritedAlpha()<=0) continue;
        Vector3i camera(self->position);
        int radius=unit->obj3D_.GetRadius()/2;
        int var9=radius+0x2000;
        int var10=radius+0x2b33;
        var9=inline_ov000_0216f3d4(var9); var10=inline_ov000_0216f3d4(var10);
        Vector3i origin(camera),position(unit->obj3D_.position_),delta;
        position.y+=unit->obj3D_.GetHeight()/2;
        Vector3fix_Subtract(&position,&origin,&delta);
        int distance=Vector3fix_InnerProduct(&delta,&delta);
        int selected=self->index==*id;
        if(func_ov000_02160130() && (self->active || self->work) && !selected) {
            Struct_ov000_021537b8* work=self->work;
            if(work) {
                Struct_ov000_0215b278* n=work->nodes;
                while(n) { if(n->id==*id) { selected=1; break; } n=n->next; }
                if(!selected) {
                    Struct_ov000_0215440c_6* g=work->groups;
                    while(g) {
                        short* entry=g->ids;
                        for(int j=0;j<g->count;entry++,j++) { if(*entry==*id) { selected=1; break; } }
                        if(selected) break;
                        g=g->next;
                    }
                }
            } else if(self->active) {
                if(self->first==*id || self->second==*id) selected=1;
            }
        }
        if(distance<=var9 && !selected) {
            if((!func_02049fc0(unit) && unit->obj3D_.GetOwnAlpha()>0) || (func_02049fc0(unit) && func_02049fec((char*)unit)>0.0f))
                func_02049f50((Struct_02049f50*)unit,0,duration);
        } else {
            if(distance>=var10 || duration==0 || selected) {
                if(duration==0 || (!func_02049fc0(unit) && unit->obj3D_.GetOwnAlpha()<31) || (func_02049fc0(unit) && func_02049fec((char*)unit)<31.0f))
                    func_02049f50((Struct_02049f50*)unit,31,duration);
            }
        }
    }
}
