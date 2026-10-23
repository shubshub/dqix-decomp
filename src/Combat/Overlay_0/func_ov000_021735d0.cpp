#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"

#if defined(jpn)
enum {Enum_ov000_021735d0_7520=0x1f98, Enum_ov000_021735d0_23756=0x5a6c};
#else
enum {Enum_ov000_021735d0_7520=0x1d60, Enum_ov000_021735d0_23756=0x5ccc};
#endif
struct Struct_ov000_021682ec_5 {
    char unknown_0_[0x118]; int unknown_118_;
    char unknown_11c_[0x188-0x11c]; char unknown_188_[0x94];
    bool unknown_21c_,unknown_21d_;
    char unknown_21e_[0x8a4-0x21e]; char unknown_8a4_[0x20],unknown_8c4_[0x20],unknown_8e4_[0x20];
    char unknown_904_[8]; int unknown_90c_;
    char unknown_910_[0x940-0x910]; int unknown_940_,unknown_944_; int unknown_948_,unknown_94c_;
    char unknown_950_[Enum_ov000_021735d0_7520-0x950]; signed char unknown_1d60_[8]; signed char unknown_1d68_;
    char unknown_1d69_[7]; bool unknown_1d70_; char unknown_1d71_; unsigned short unknown_1d72_;
    char unknown_1d74_[13]; unsigned char unknown_1d81_;
};
struct GameFlags {char pad[gameFlagsOffset]; signed int bit0:1,bit1:1,rest:30;};
struct TableEntry0217f8c0 {char p[0x10];signed char commands[8];signed char index;char q[0x24-0x19];unsigned char flags;};
struct Struct0217f8c0;struct Obj0204b5e8;struct Struct021754fc;struct S02180b50;
int Background_SetScroll(Obj0204b5e8*,int,int);
TableEntry0217f8c0* FindMatchingTableEntry0217f8c0(Struct0217f8c0*);
void UpdateLastEntryField02175440(void*);
void UpdateFieldromTable_02174fc0_02174fc0(void*);
void NotifyEachViaLookup021754fc(Struct021754fc*,int);
void TickCounter02180b50(S02180b50*);
int GetField0x3acValue_020100a8(GameState*);
int CheckField0NonZero_0202b7d8(int*);
extern "C" {
int* func_0202ae18(); void func_020dc7e8(int,int); int Window_Update(void*,int);
void func_ov000_02175fc8(void*);void func_ov000_02174d08(void*);void func_ov000_02175024(void*,int);
void* func_ov000_02161318(void*,int);
void func_ov000_0217f304(void*,int,int,void*);void func_ov000_0217c908(void*,int,int);
void func_ov000_02176e3c(void*,void*,int,int,int,int);
int func_ov000_0217fd60(void*,int);void func_ov000_021751ac(void*);
void func_ov000_0217f00c(void*,int,int);void func_ov000_02175258(void*);
void func_ov000_0218099c(void*,int);void func_ov000_02180a64(void*);
}
extern int data_ov000_02183ff0;extern int data_ov000_02184288[];

// USA: func_ov000_021735d0
extern "C" ARM void func_ov000_021735d0(Struct_ov000_021682ec_5* arg0,int arg1)
{
    self->delta=delta;
    Background_SetScroll((Obj0204b5e8*)self->dispatchA,-self->x,-self->y);
    Background_SetScroll((Obj0204b5e8*)self->dispatchB,0,0);
    Background_SetScroll((Obj0204b5e8*)self->dispatchC,0,0);
    GameState* gs=GameState::GetInstance();func_0202ae18();
    if(((GameFlags*)gs)->bit1)func_020dc7e8(0,-1);
    if(!delta)delta=1;
    int update=1;
    TableEntry0217f8c0* entry=FindMatchingTableEntry0217f8c0((Struct0217f8c0*)self);
    if(entry&&entry->commands[entry->index]==100)update=0;
    if(update){
        UpdateLastEntryField02175440(self);
        entry=FindMatchingTableEntry0217f8c0((Struct0217f8c0*)self);
        int clear;bool a=self->flagA,b=self->flagB;clear=0;
        if(entry&&!(self->flags&0x200)&&self->commands[self->commandIndex]!=6&&self->commands[self->commandIndex]!=7&&!(entry->flags&1))clear=1;
        if(clear){self->flagA=false;self->flagB=false;}
        self->result=Window_Update(self->updateState,delta);
        if(clear){if(a)self->flagA=true;if(b)self->flagB=true;}
    }
    func_ov000_02175fc8(arg0);func_ov000_02174d08(arg0);func_ov000_02174fc0(arg0);
    func_ov000_02175024(arg0,arg1);func_ov000_021754fc((Struct_ov000_021735d0_4*)arg0,arg1);
    if(arg0->unknown_1d72_&0x200){
        void* var6=func_ov000_02161318(arg0,(signed char)func_020100a8(GameState::GetInstance()));
        func_ov000_0217f304(arg0,data_ov000_02183ff0,data_ov000_02184288[1],var6);
        func_ov000_0217c908(arg0,data_ov000_02183ff0,data_ov000_02184288[1]);
        func_ov000_02180b50((Struct_ov000_021735d0_5*)arg0);
        int var7=arg0->unknown_1d60_[arg0->unknown_1d68_]==100;
        if(var7 & func_0202b7d8(func_0202ae18())){
            if(arg0->unknown_1d81_==1){
                for(int var8=0;var8<2;var8++)func_ov000_02176e3c(arg0,var6,23,data_ov000_02183ff0,data_ov000_02184288[1],0);
                arg0->unknown_1d81_=2;
            }else if(arg0->unknown_1d81_==0)arg0->unknown_1d81_=1;
        }
    }
    if(arg0->unknown_1d72_&0x400)func_ov000_02180b50((Struct_ov000_021735d0_5*)arg0);
    if(!func_ov000_0217fd60(arg0,-1)){
        if(arg0->unknown_1d70_&&arg0->unknown_90c_>=0){BackgroundLoader* var9=BackgroundLoader::GetInstance();var9->RemoveTask(arg0->unknown_90c_);arg0->unknown_90c_=-1;}
    }else{
        func_ov000_021751ac(arg0);
        if(!(arg0->unknown_1d72_&0x200)){
            if(arg0->unknown_1d60_[arg0->unknown_1d68_]==13){if(!(arg0->unknown_1d72_&4))func_ov000_0217f00c(arg0,data_ov000_02183ff0,data_ov000_02184288[1]);}
            else func_ov000_0217c908(arg0,data_ov000_02183ff0,data_ov000_02184288[1]);
            func_ov000_02175258(arg0);func_ov000_0218099c(arg0,arg1);func_ov000_02180a64(arg0);
        }
    }
}
