#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"

#if defined(jpn)
enum {Enum_ov000_0217ce24_7520=0x1f98, Enum_ov000_0217ce24_6904=0x1bf8, Enum_ov000_0217ce24_336=0x144};
#else
enum {Enum_ov000_0217ce24_7520=0x1d60, Enum_ov000_0217ce24_6904=0x1af8, Enum_ov000_0217ce24_336=0x150};
#endif
struct Struct_ov000_021682ec_5 {
    char unknown_0_[0x68];int unknown_68_;
    char unknown_6c_[0x79-0x6c];unsigned char unknown_79_;
    char unknown_7a_[2];SafeAllocator unknown_7c_;char unknown_90_[0xb3-0x90];unsigned char unknown_b3_;
    char unknown_b4_[0x17c-0xb4];int unknown_17c_;
    char unknown_180_[8];char unknown_188_[0x956-0x188];unsigned char unknown_956_;
    char unknown_957_[Enum_ov000_0217ce24_6904-0x957];SafeAllocator unknown_1af8_;
    char unknown_1b0c_[Enum_ov000_0217ce24_7520-Enum_ov000_0217ce24_6904-0x14];signed char unknown_1d60_[8];signed char unknown_1d68_;
    char unknown_1d69_;signed char unknown_1d6a_;unsigned char unknown_1d6b_;
    char unknown_1d6c_[2];unsigned char unknown_1d6e_;char unknown_1d6f_[3];unsigned short unknown_1d72_;
    char unknown_1d74_[4];bool unknown_1d78_;
};
struct Party {char p[0xf78];signed char members[4];unsigned char count;};
struct UnitState {char p[0x56b];unsigned char low:4,high:4;};
struct UnitView {char p[unitStateOffset];UnitState* state;};
struct Struct_0205c570;struct SePlayer;struct Struct0217f8c0;struct TableEntry0217f8c0;
struct Struct_0205d81c;struct Entry_0205d6a0;struct Obj02092aa4;
int Window_GetSelectedIndex(Struct_0205c570*);
void SePlayer_Play(SePlayer*,int,int);
void* GetPtrField0x2a04_02010828(GameState*);
GameObject* GetCombatantWithFlag0x100_0200ff1c(GameState*,int);
TableEntry0217f8c0* FindMatchingTableEntry0217f8c0(Struct0217f8c0*);
int GetField0x3acValue_020100a8(GameState*);
int CountSetBitsLow12_0x68_ov000_0218155c(void*);
void SetElementStateIfLess0217a9d0(int,int,int,Struct_0205d81c*);
void InitObj02092aa4(Obj02092aa4*, int);
void CreateTypeAFromAllocator_02092a74(SafeAllocator*,SafeAllocator*);
int CheckFlagsOrField_0217c5f4_0217c5f4(void*);
void ResetEntryList0205d6a0(Entry_0205d6a0*,int);
extern SePlayer g_sePlayer;
extern "C" {
void func_02012fe4();int func_ov000_0217c594(void*,int);
void* func_ov000_02161318(void*,int);int func_ov000_0217f5dc(void*);
void func_ov000_02177038(void*,int,int,int,int);
void func_ov000_02176634(void*,void*,int,int,int);
int func_020dd3cc(int);int func_ov000_0217c514(int,int);
void func_ov000_02176e3c(void*,int,int,int,int,int);
void func_ov000_0217c638(void*,int,int);
}

// USA: func_ov000_0217ce24
extern "C" ARM void func_ov000_0217ce24(Struct_ov000_021682ec_5* arg0,int arg1,int arg2)
{
    func_02012fe4();
    self->flags|=0x100;
    int mode=Window_GetSelectedIndex((Struct_0205c570*)self->updateState);
    if(mode<0)mode=0;
    self->mode=mode;
    if(func_ov000_0217c594(self,5)){
        self->flag956=0;
        SePlayer_Play(&g_sePlayer,1,0);
        GameState* game=GameState::GetInstance();
        Party* party=(Party*)GetPtrField0x2a04_02010828(game);
        signed char count=0;bool active=false;
        unsigned char i=0;unsigned char total=party->count;
        for(;i<total;i++){
            int member=party->members[i];
            UnitView* unit=(UnitView*)GetCombatantWithFlag0x100_0200ff1c(game,member);
            if(unit){
                bool stateActive=unit->state?unit->state->low!=0:false;
                if(stateActive)active=true;
                void* entry=func_ov000_02161318(self,member);
                if(entry&&func_ov000_0217f5dc(entry))count++;
            }
        }
        if(arg0->unknown_79_<var3)var3=arg0->unknown_79_;
        switch(arg0->unknown_1d6a_){
        case 0:
            func_ov000_02177038(arg0,0,arg0->unknown_1d60_[arg0->unknown_1d68_],arg1,arg2);
            if(var2->unknown_f7c_==1||var4||arg0->unknown_1d78_||var3==1){
                arg0->unknown_1d6b_=0;arg0->unknown_1d68_++;arg0->unknown_1d60_[arg0->unknown_1d68_]=12;
                func_ov000_02176634(arg0,func_ov000_0217f8c0((Struct_ov000_021735d0_3*)arg0),12,arg1,arg2);
            }else{
                arg0->unknown_1d6b_=0;arg0->unknown_1d68_++;arg0->unknown_1d60_[arg0->unknown_1d68_]=3;
                func_ov000_02176634(arg0,func_ov000_0217f8c0((Struct_ov000_021735d0_3*)arg0),3,arg1,arg2);
            }
            break;
        case 1:
            func_ov000_02177038(arg0,0,arg0->unknown_1d60_[arg0->unknown_1d68_],arg1,arg2);
            arg0->unknown_1d6e_=0;arg0->unknown_1d6b_=0;arg0->unknown_1d68_++;arg0->unknown_1d60_[arg0->unknown_1d68_]=5;
            if(var2->unknown_f7c_==1||var4||var3==1){
                int var11=(signed char)func_020100a8(var1);
                arg0->unknown_68_=func_020dd3cc(var11);
                arg0->unknown_68_=func_ov000_0217c514(var11,arg0->unknown_68_);
                arg0->unknown_1d60_[arg0->unknown_1d68_]=6;
                if(arg0->unknown_68_==0){
                    arg0->unknown_1d60_[arg0->unknown_1d68_]=43;
                    func_ov000_02176634(arg0,func_ov000_02161318(arg0,var11),43,arg1,arg2);
                    break;
                }
            }
            {Struct_ov000_021735d0_2* var12=func_ov000_0217f8c0((Struct_ov000_021735d0_3*)arg0);
            func_ov000_02176634(arg0,var12,arg0->unknown_1d60_[arg0->unknown_1d68_],arg1,arg2);}
            func_ov000_0217a9d0(6,func_ov000_0218155c(arg0),4,(Struct_0205d81c*)arg0->unknown_188_);
            break;
        case 2:
            arg0->unknown_79_=var3;
            func_ov000_02177038(arg0,0,arg0->unknown_1d60_[arg0->unknown_1d68_],arg1,arg2);
            arg0->unknown_1d6b_=0;arg0->unknown_1d68_++;arg0->unknown_1d60_[arg0->unknown_1d68_]=8;
            func_ov000_02176634(arg0,func_ov000_0217f8c0((Struct_ov000_021735d0_3*)arg0),8,arg1,arg2);
            break;
        case 3:
            func_ov000_02176e3c(arg0,0,arg0->unknown_1d60_[arg0->unknown_1d68_],arg1,arg2,1);
            arg0->unknown_1d68_++;arg0->unknown_1d60_[arg0->unknown_1d68_]=9;
            arg0->unknown_1af8_.Reset();
            func_02092aa4((Struct_02092aa4*)&arg0->unknown_7c_, (signed char)arg0->unknown_17c_);
            func_02092a74(&arg0->unknown_7c_,&arg0->unknown_1af8_);
            arg0->unknown_b3_|=8;
            break;
        }
    }else if(func_ov000_0217c5f4(arg0)){
        arg0->unknown_956_=0;
        func_0205d6a0((Struct_0205d6a0*)arg0->unknown_188_,0);
        arg0->unknown_1d60_[arg0->unknown_1d68_]=0;arg0->unknown_1d68_--;
        func_ov000_0217c638(arg0,arg1,arg2);
    }
}
