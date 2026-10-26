#include <globaldefs.h>
#include "std_library_functions.h"

struct GameObject { char p[0x138]; short* details; int inline_ov000_0215bf5c() const { return details[0]; } int inline_ov000_0215bf5c_2() const { return details[1]; } };
class GameState { public: static GameState* GetInstance(); GameObject* GetCombatantByIndex(int); };
struct Struct_ov000_0215440c_2 { void* first; void* last; unsigned char count; };
struct Struct_ov000_0215bf5c_2 {
    void* field0; void* field4; void* unknown_8_; void* fieldC; void* unknown_10_;
    char p0[8]; short unknown_1c_; char p1[2]; unsigned short id; unsigned short field22,field24,field26;
    unsigned char unknown_28_,unknown_29_,unknown_2a_; char p2[5]; int unknown_30_;
};
struct Struct_ov000_0215bf5c_3 { unsigned long long flags; };
struct Struct_ov000_0215bf5c_4 { unsigned short kind; char p[9]; unsigned char flags; };
struct Struct_ov000_0215bf5c_5 { char p0[0xe]; unsigned short id; char p1[7]; unsigned char flag; };
struct Struct_ov000_0215bf5c_6 { char p0[0x20]; int field20; };
extern "C" Struct_ov000_0215bf5c_2* func_ov000_02160094(Struct_ov000_0215440c_2*,int);
extern "C" Struct_ov000_0215bf5c_3* func_ov000_0215feb4(char*,int,int);
extern "C" void* func_ov000_0215e9d8(void*);
extern "C" void func_ov000_02160030(void*);
extern "C" void* func_ov000_0215e918(void*);
extern "C" void* func_ov000_0215e938(void*);
extern "C" void func_ov000_02157cdc(void*);
extern "C" void func_ov000_0215fe84(void*,void*,int);
extern "C" void func_ov000_0215ffc4(void*,void*,int);
struct Struct_ov000_0215767c_7; struct Struct_ov000_0215767c_6;
extern "C" void func_ov000_02160068(Struct_ov000_0215767c_7*,Struct_ov000_0215767c_6*);
struct Struct_ov000_0215767c_5; struct Struct_ov000_0215767c_4;
extern "C" void func_ov000_021600cc(Struct_ov000_0215767c_5*,Struct_ov000_0215767c_4*);
extern "C" {
GameObject* _ZN9GameState19GetCombatantByIndexEi(GameState*,int);
int func_ov000_0215fd90(Struct_ov000_0215bf5c_3*,int);
Struct_ov000_0215bf5c_6* func_ov000_0215e958(void*);
void func_ov000_0215ccbc(void*,Struct_ov000_0215bf5c_6*,GameObject*,short,short,short,unsigned long long,unsigned char);
}

struct Struct_ov000_0215bf5c { char p[0x8e00]; unsigned char unknown_8e00_,count1,count2; char q[0x21]; int unknown_8e24_; };

static inline GameObject* inline_02000c9c_5(int id) { return GameState::GetInstance()->GetCombatantByIndex(id); }
static inline int inline_ov000_0215bf5c_3(Struct_ov000_0215bf5c_2* node) { return node->unknown_28_; }

// USA: func_ov000_0215bf5c
extern "C" ARM void func_ov000_0215bf5c(Struct_ov000_0215bf5c* self,Struct_ov000_0215440c_2* list) {
    for (int i=0;i<list->count;i++) {
        Struct_ov000_0215bf5c_2* node=func_ov000_02160094(list,i);
        if (!node) continue;
        Struct_ov000_0215bf5c_3* flags;
        bool special;bool var4;
        Struct_ov000_0215bf5c_4* work;
        Struct_ov000_0215bf5c_5* state;
        Struct_ov000_0215bf5c_6* out;
        int id=(short)node->id;
        GameState* gs=GameState::GetInstance();
        GameObject* unit=gs->GetCombatantByIndex(id);
        if (!unit) continue;
        int count=inline_ov000_0215bf5c_3(node);
        flags=func_ov000_0215feb4((char*)node,i,2);
        special=false; var4=0;
        if (flags && (func_ov000_0215fd90(flags,0x22) || func_ov000_0215fd90(flags,0x25))) special=true;
        if (!special && !node->unknown_29_) { var4=1;count+=node->unknown_2a_; }
        if (count<=0) continue;
        work=(Struct_ov000_0215bf5c_4*)func_ov000_0215e9d8(self);
        if (!work) continue;
        func_ov000_02160030(work);
        Struct_ov000_0215bf5c_2* copy=(Struct_ov000_0215bf5c_2*)func_ov000_0215e918(self);
        if (!copy) continue;
        memset(copy,0,0x30);copy->unknown_1c_=-1;copy->unknown_30_=0;
        state=(Struct_ov000_0215bf5c_5*)func_ov000_0215e938(self);
        if (!state) continue;
        func_ov000_02157cdc(state);
        out=func_ov000_0215e958(self);
        if (!out) continue;
        memset(out,0,0x20);out->field20=0;
        work->kind=0x3ae;
        int moved=0;
        if (flags && ((flags->flags&2ULL) || (flags->flags&4ULL) || (flags->flags&0x10ULL) || (flags->flags&0x2000ULL))) {
            func_ov000_0215fe84(copy,flags,2);
            node->unknown_8_=0;node->unknown_28_=0;moved=1;
        }
        if (!moved && !var4) continue;
        if (var4) {
            copy->unknown_10_=node->unknown_10_;copy->unknown_2a_=node->unknown_2a_;
            node->unknown_10_=0;node->unknown_2a_=0;
        }
        copy->id=node->id;copy->field24=node->field24;
        int second=unit->inline_ov000_0215bf5c_2();
        int first=unit->inline_ov000_0215bf5c();
        func_ov000_0215ccbc(self,out,unit,0,first,second,0,0);
        state->id=node->id;state->flag=1;
        func_ov000_0215ffc4(state,out,0);
        work->flags|=4;
        func_ov000_02160068((Struct_ov000_0215767c_7*)work,(Struct_ov000_0215767c_6*)copy);
        func_ov000_021600cc((Struct_ov000_0215767c_5*)work,(Struct_ov000_0215767c_4*)state);
        self->unknown_8e24_++;self->unknown_8e00_++;self->count1++;self->count2++;
    }
}
