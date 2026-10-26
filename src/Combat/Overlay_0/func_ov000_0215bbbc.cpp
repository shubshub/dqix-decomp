#include <globaldefs.h>
#include "std_library_functions.h"
union Struct_ov000_021573a8_2 { struct { short first,second; }; struct { unsigned short unknown_0_,unknown_2_; }; };
struct GameObject { char p[0x138]; Struct_ov000_021573a8_2* detail; int inline_ov000_0215b278() const { return detail->first; } int inline_ov000_0215b278_2() const { return detail->second; } };
class GameState { public: static GameState* GetInstance(); GameObject* GetCombatantByIndex(int); };
struct Struct_ov000_0215440c_2 { void* first; void* last; unsigned char count; };
struct Struct_ov000_0215b278 { void* unknown_0_[6]; char p0[4]; short unknown_1c_,unknown_1e_; unsigned short id,field22,field24; unsigned char counts[6],pad2c,trigger; char p1[2]; int tail; };
struct Struct_ov000_021537b8 { unsigned short kind; char p[9]; unsigned char flags; };
struct Struct_ov000_0215b278_2 { char p0[0xe]; unsigned short id; char p1[7]; unsigned char flag; };
struct Struct_ov000_0215b278_3 { char p[0x20]; int tail; };
extern "C" Struct_ov000_0215b278* func_ov000_02160094(Struct_ov000_0215440c_2*,int);
extern "C" void* func_ov000_0215e9d8(void*);
extern "C" void func_ov000_02160030(void*);
extern "C" void* func_ov000_0215e918(void*);
extern "C" void* func_ov000_0215e938(void*);
extern "C" void func_ov000_02157cdc(void*);
extern "C" void func_ov000_0215ffc4(void*,void*,int);
extern "C" void func_ov000_0215a88c(void*,void*,int);
struct Struct_ov000_0215767c_7; struct Struct_ov000_0215767c_6; struct Struct_ov000_0215767c_5; struct Struct_ov000_0215767c_4;
extern "C" void func_ov000_02160068(Struct_ov000_0215767c_7*,Struct_ov000_0215767c_6*);
extern "C" void func_ov000_021600cc(Struct_ov000_0215767c_5*,Struct_ov000_0215767c_4*);
extern "C" { Struct_ov000_0215b278_3* func_ov000_0215e958(void*); void func_ov000_0215ccbc(void*,Struct_ov000_0215b278_3*,GameObject*,short,short,short,unsigned long long,unsigned char); }
inline int inline_ov000_021537b8(unsigned short n) { int result=0; if(n<=3) result=1; return result; }
// USA: func_ov000_0215bbbc
extern "C" ARM void func_ov000_0215bbbc(unsigned char* self,Struct_ov000_0215440c_2* list) {
    for(int i=0;i<list->count;i++) {
        Struct_ov000_0215b278* node=func_ov000_02160094(list,i);
        if(!node) continue;
        Struct_ov000_021537b8* work; Struct_ov000_0215b278* copy; Struct_ov000_0215b278_2* state; Struct_ov000_0215b278_3* out;
        int id=(short)node->id;
        GameState* gs=GameState::GetInstance();
        GameObject* unit=gs->GetCombatantByIndex(id);
        if(!unit) continue;
        int sum=0;
        for(int j=0;j<6;j++) if(j!=1) sum+=node->counts[j];
        if(sum<=0) continue;
#define ALLOCATE() \
        work=(Struct_ov000_021537b8*)func_ov000_0215e9d8(self); \
        if(!work) continue; func_ov000_02160030(work); \
        copy=(Struct_ov000_0215b278*)func_ov000_0215e918(self); \
        if(!copy) continue; memset(copy,0,0x30); copy->unknown_1c_=-1; copy->tail=0; \
        state=(Struct_ov000_0215b278_2*)func_ov000_0215e938(self); \
        if(!state) continue; func_ov000_02157cdc(state); \
        out=func_ov000_0215e958(self); \
        if(!out) continue; memset(out,0,0x20); out->tail=0;
        ALLOCATE()
        work->kind=0x3ae;
        memcpy(copy,node,0x34);
        for(int j=0;j<6;j++) if(j!=1) { node->unknown_0_[j]=0; node->counts[j]=0; }
        node->unknown_1c_=-1; node->unknown_1e_=0; node->trigger=0;
        copy->unknown_0_[1]=0; copy->counts[1]=0;
        { int second=unit->inline_ov000_0215b278_2(); int first=unit->inline_ov000_0215b278();
        func_ov000_0215ccbc(self,out,unit,0,first,second,0,0); }
        state->id=node->id; state->flag=1;
        func_ov000_0215ffc4(state,out,0);
        work->flags|=4;
        func_ov000_02160068((Struct_ov000_0215767c_7*)work,(Struct_ov000_0215767c_6*)copy);
        func_ov000_021600cc((Struct_ov000_0215767c_5*)work,(Struct_ov000_0215767c_4*)state);
        (*(int*)(self+0x8e24))++; self[0x8e00]++; self[0x8e01]++; self[0x8e02]++;
        if(copy->trigger==1) {
            ALLOCATE()
             int party=0; if(node->id<=3) party=1; if(party) work->kind=0x39c; else work->kind=0x39d;
            copy->id=node->id;
            copy->field22=unit->detail->unknown_0_; copy->field24=unit->detail->unknown_2_;
            work->flags|=4;
            { int second=unit->inline_ov000_0215b278_2(); int first=unit->inline_ov000_0215b278();
        func_ov000_0215ccbc(self,out,unit,0,first,second,0,0); }
            func_ov000_0215a88c(self,out,0x35);
            state->id=node->id; state->flag=1;
            func_ov000_0215ffc4(state,out,0);
            self[0x8e02]++;
            func_ov000_02160068((Struct_ov000_0215767c_7*)work,(Struct_ov000_0215767c_6*)copy);
            func_ov000_021600cc((Struct_ov000_0215767c_5*)work,(Struct_ov000_0215767c_4*)state);
            (*(int*)(self+0x8e24))++; self[0x8e00]++; self[0x8e01]++; self[0x8e02]++;
            copy->trigger=0;
        }
#undef ALLOCATE
    }
}
