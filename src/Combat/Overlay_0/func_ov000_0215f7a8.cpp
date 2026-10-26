#include <globaldefs.h>
struct Struct_02000c9c_32 {char p[0x34];unsigned short first,second;int inline_ov000_0215f7a8_3(){ return first; }int inline_ov000_0215f7a8_2(){ return second; }};
struct Actor {unsigned int zero;unsigned int value:10,rest:22;};
struct GameObject {char p[0x134];Struct_02000c9c_32* base;void* stats;
#if defined(jpn)
char q[8];
#else
char q[20];
#endif
Actor* actor;};
class GameState {public:static GameState* GetInstance();GameObject* GetCombatantByIndex(int);};
extern "C" GameObject* func_0200ff1c(GameState*,int);
struct Random;Random* GetBTRandom();int NextRandomMax(Random*,int);
struct Struct_ov000_021540fc {char p[0xc];int state;};
struct Struct_ov000_0215767c_2 {char p[0x8e18];Struct_ov000_021540fc* info;int unknown_8e1c_;int mode;char q[0x25];unsigned char flag;};
struct Struct_ov000_02182ae4 {short v[8];};
extern "C" {extern const Struct_ov000_02182ae4 data_ov000_02182b94;extern const int data_ov000_02182c04[];int func_ov000_0215ed34(void*,short*,int);int func_ov000_0215eb1c(void*,short*,int,int);int func_ov000_0215e9fc(void*,short*,int,int);int func_ov000_02155f9c(void*,int,int);}
inline GameObject* inline_ov000_021537b8_2(int id){GameState* gs=GameState::GetInstance();return gs->GetCombatantByIndex(id);}
inline int inline_ov000_0215f7a8(Struct_02000c9c_32* s){int second=s->inline_ov000_0215f7a8_2();int first=s->inline_ov000_0215f7a8_3();return first+second;}
// USA: func_ov000_0215f7a8
extern "C" ARM int func_ov000_0215f7a8(Struct_ov000_0215767c_2* self,short* selected,int count){
 Random* var0=GetBTRandom();if(self->info->state>=0)return 0;
 short states[3];int size=func_ov000_0215ed34(self,states,3);short* var3=states;for(int i=0;i<size;i++,var3++)if((unsigned int)(*var3-0x26)<=2)return 0;
 if(self->mode==0&&self->flag==1)return 1;
 int var5=0;int var6=0;Struct_ov000_02182ae4 ids(data_ov000_02182b94);short* ptr=ids.v;short n=func_ov000_0215eb1c(self,ptr,8,1);short i=0;
 for(;i<n;i++,ptr++){if(!func_ov000_02155f9c(self,*ptr,0))break;}
 if(i==n)return 1;
 ptr=ids.v;for(i=0;i<n;i++,ptr++){GameObject* unit=inline_ov000_021537b8_2(*ptr);if(unit)var6+=inline_ov000_0215f7a8(unit->base);}
 var6/=n;
 ptr=ids.v;n=func_ov000_0215e9fc(self,ptr,8,1);
 for(i=0;i<n;i++,ptr++){GameObject* unit=inline_ov000_021537b8_2(*ptr);if(unit)var5+=inline_ov000_0215f7a8(unit->base);}
 var5/=n;if(var6*3<=var5)return 1;
 GameState* gs=GameState::GetInstance();const int* var14=data_ov000_02182c04;int var15=0;
 for(int j=0;j<count;j++,selected++){GameObject* unit=func_0200ff1c(gs,*selected);if(unit){int value=10+(int)(0.05f*(float)(unsigned short)unit->actor->value);if(var15<value)var15=value;}}
 if(var15<var14[self->unknown_8e1c_])var15=var14[self->unknown_8e1c_];
 self->unknown_8e1c_++;return NextRandomMax(var0,100)<var15;
}
