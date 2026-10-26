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
struct Struct_ov000_0215440c { unsigned short kind; char p[7]; unsigned char count; };
struct Entry { char p[0xe]; short id; char q[0xd]; unsigned char unknown_1d_0_:1, extra:1, rest:6; };
extern "C" Entry* func_ov000_021600f8(Struct_ov000_0215440c*,int);
// USA: func_ov000_0215b278
extern "C" ARM void func_ov000_0215b278(unsigned char* self,Struct_ov000_0215440c* list) {
 if(list->kind!=0x20b) return;
 for(int i=0;i<list->count;i++) {
  Entry* entry=func_ov000_021600f8(list,i);
  if(!entry) continue;
  int id=entry->id;
  GameState* gs=GameState::GetInstance();
  GameObject* unit=gs->GetCombatantByIndex(id);
  if(!unit) continue;
  Struct_ov000_021537b8* work=(Struct_ov000_021537b8*)func_ov000_0215e9d8(self);
  if(!work) continue; func_ov000_02160030(work);
  Struct_ov000_0215b278* copy=(Struct_ov000_0215b278*)func_ov000_0215e918(self);
  if(!copy) continue; memset(copy,0,0x30);copy->unknown_1c_=-1;copy->tail=0;
  Struct_ov000_0215b278_2* state=(Struct_ov000_0215b278_2*)func_ov000_0215e938(self);
  if(!state) continue;func_ov000_02157cdc(state);
  work->kind=0x3b1;
  copy->id=entry->id;copy->field22=unit->detail->unknown_0_;copy->field24=unit->detail->unknown_2_;
  memcpy(state,entry,0x24);
  func_ov000_02160068((Struct_ov000_0215767c_7*)work,(Struct_ov000_0215767c_6*)copy);
  func_ov000_021600cc((Struct_ov000_0215767c_5*)work,(Struct_ov000_0215767c_4*)state);
  work->flags|=4;
  (*(int*)(self+0x8e24))++; self[0x8e00]++;self[0x8e01]++;
  if(entry->extra) {
   Struct_ov000_021537b8* work2=(Struct_ov000_021537b8*)func_ov000_0215e9d8(self);
   if(!work2) continue;func_ov000_02160030(work2);
   copy=(Struct_ov000_0215b278*)func_ov000_0215e918(self);
   if(!copy) continue;memset(copy,0,0x30);copy->unknown_1c_=-1;copy->tail=0;
   Struct_ov000_0215b278_2* var9=(Struct_ov000_0215b278_2*)func_ov000_0215e938(self);
   if(!var9) continue;func_ov000_02157cdc(var9);
   Struct_ov000_0215b278_3* out=func_ov000_0215e958(self);
   if(!out)continue;memset(out,0,0x20);out->tail=0;
   work2->kind=0x39c;
   copy->id=entry->id;copy->field22=unit->detail->unknown_0_;copy->field24=unit->detail->unknown_2_;
   work2->flags|=4;
   {int second=unit->inline_ov000_0215b278_2();int first=unit->inline_ov000_0215b278();
   func_ov000_0215ccbc(self,out,unit,0,first,second,0,0);}
   func_ov000_0215a88c(self,out,0x35);
   var9->id=entry->id;var9->flag=1;
   func_ov000_0215ffc4(var9,out,0);
   self[0x8e02]++;
   func_ov000_02160068((Struct_ov000_0215767c_7*)work2,(Struct_ov000_0215767c_6*)copy);
   func_ov000_021600cc((Struct_ov000_0215767c_5*)work2,(Struct_ov000_0215767c_4*)var9);
   (*(int*)(self+0x8e24))++; self[0x8e00]++;self[0x8e01]++;self[0x8e02]++;
  }
 }
}
