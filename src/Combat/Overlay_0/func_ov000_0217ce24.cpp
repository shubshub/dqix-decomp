#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"

#if defined(jpn)
enum {Enum_ov000_0217ce24_7520=0x1f98, Enum_ov000_0217ce24_6904=0x1bf8, Enum_ov000_0217ce24_336=0x144};
#else
enum {Enum_ov000_0217ce24_7520=0x1d60, Enum_ov000_0217ce24_6904=0x1af8, Enum_ov000_0217ce24_336=0x150};
#endif
struct Struct_ov000_021682ec_5 {
    char pad0[0x68];int mask;
    char pad1[0x79-0x6c];unsigned char limit;
    char pad2[2];SafeAllocator unknown_7c_;char pad3[0xb3-0x90];unsigned char unknown_b3_;
    char pad4[0x17c-0xb4];int member;
    char pad5[8];char updateState[0x956-0x188];unsigned char unknown_956_;
    char pad6[Enum_ov000_0217ce24_6904-0x957];SafeAllocator allocator;
    char unknown_1b0c_[Enum_ov000_0217ce24_7520-Enum_ov000_0217ce24_6904-0x14];signed char commands[8];signed char index;
    char pad8;signed char mode;unsigned char count;
    char unknown_1d6c_[2];unsigned char special;char pad10[3];unsigned short flags;
    char unknown_1d74_[4];bool force;
};
struct Party {char p[0xf78];signed char members[4];unsigned char count;};
struct Struct_ov000_0217ce24_2 {char p[0x56b];unsigned char low:4,high:4;};
struct Struct_ov000_0217ce24 {char p[Enum_ov000_0217ce24_336];Struct_ov000_0217ce24_2* state;};
struct Struct_0205c570;struct SePlayer;struct Struct0217f8c0;struct TableEntry0217f8c0;
struct Struct_0205d81c;struct Entry_0205d6a0;struct Struct_02092aa4;
extern "C" int Window_GetSelectedIndex(Struct_0205c570*);
extern "C" void SePlayer_Play(SePlayer*,int,int);
extern "C" void* GameState_GetParty(GameState*);
extern "C" GameObject* func_0200ff1c(GameState*,int);
extern "C" TableEntry0217f8c0* func_ov000_0217f8c0(Struct0217f8c0*);
extern "C" int GameState_GetProtagonistIndex(GameState*);
extern "C" int func_ov000_0218155c(void*);
extern "C" void func_ov000_0217a9d0(int,int,int,Struct_0205d81c*);
extern "C" void func_02092aa4(Struct_02092aa4*, int);
extern "C" void func_02092a74(SafeAllocator*,SafeAllocator*);
extern "C" int func_ov000_0217c5f4(void*);
extern "C" void Window_ClosePane(Entry_0205d6a0*,int);
extern SePlayer g_sePlayer;
extern "C" {
void Zone3D_GetInstance();int func_ov000_0217c594(void*,int);
void* func_ov000_02161318(void*,int);int func_ov000_0217f5dc(void*);
void func_ov000_02177038(void*,int,int,int,int);
void func_ov000_02176634(void*,void*,int,int,int);
int func_020dd3cc(int);int func_ov000_0217c514(int,int);
void func_ov000_02176e3c(void*,int,int,int,int,int);
void func_ov000_0217c638(void*,int,int);
}

// USA: func_ov000_0217ce24
extern "C" ARM void func_ov000_0217ce24(Struct_ov000_021682ec_5* self,int a,int b)
{
    Zone3D_GetInstance();
    self->flags|=0x100;
    int mode=Window_GetSelectedIndex((Struct_0205c570*)self->updateState);
    if(mode<0)mode=0;
    self->mode=mode;
    if(func_ov000_0217c594(self,5)){
        self->unknown_956_=0;
        SePlayer_Play(&g_sePlayer,1,0);
        GameState* game=GameState::GetInstance();
        Party* party=(Party*)GameState_GetParty(game);
        signed char count=0;bool active=false;
        unsigned char i=0;unsigned char total=party->count;
        for(;i<total;i++){
            int member=party->members[i];
            Struct_ov000_0217ce24* unit=(Struct_ov000_0217ce24*)func_0200ff1c(game,member);
            if(unit){
                bool var9=unit->state?unit->state->low!=0:false;
                if(var9)active=true;
                void* entry=func_ov000_02161318(self,member);
                if(entry&&func_ov000_0217f5dc(entry))count++;
            }
        }
        if(self->limit<count)count=self->limit;
        switch(self->mode){
        case 0:
            func_ov000_02177038(self,0,self->commands[self->index],a,b);
            if(party->count==1||active||self->force||count==1){
                self->count=0;self->index++;self->commands[self->index]=12;
                func_ov000_02176634(self,func_ov000_0217f8c0((Struct0217f8c0*)self),12,a,b);
            }else{
                self->count=0;self->index++;self->commands[self->index]=3;
                func_ov000_02176634(self,func_ov000_0217f8c0((Struct0217f8c0*)self),3,a,b);
            }
            break;
        case 1:
            func_ov000_02177038(self,0,self->commands[self->index],a,b);
            self->special=0;self->count=0;self->index++;self->commands[self->index]=5;
            if(party->count==1||active||count==1){
                int member=(signed char)GameState_GetProtagonistIndex(game);
                self->mask=func_020dd3cc(member);
                self->mask=func_ov000_0217c514(member,self->mask);
                self->commands[self->index]=6;
                if(self->mask==0){
                    self->commands[self->index]=43;
                    func_ov000_02176634(self,func_ov000_02161318(self,member),43,a,b);
                    break;
                }
            }
            {TableEntry0217f8c0* entry=func_ov000_0217f8c0((Struct0217f8c0*)self);
            func_ov000_02176634(self,entry,self->commands[self->index],a,b);}
            func_ov000_0217a9d0(6,func_ov000_0218155c(self),4,(Struct_0205d81c*)self->updateState);
            break;
        case 2:
            self->limit=count;
            func_ov000_02177038(self,0,self->commands[self->index],a,b);
            self->count=0;self->index++;self->commands[self->index]=8;
            func_ov000_02176634(self,func_ov000_0217f8c0((Struct0217f8c0*)self),8,a,b);
            break;
        case 3:
            func_ov000_02176e3c(self,0,self->commands[self->index],a,b,1);
            self->index++;self->commands[self->index]=9;
            self->allocator.Reset();
            func_02092aa4((Struct_02092aa4*)&self->unknown_7c_, (signed char)self->member);
            func_02092a74(&self->unknown_7c_,&self->allocator);
            self->unknown_b3_|=8;
            break;
        }
    }else if(func_ov000_0217c5f4(self)){
        self->unknown_956_=0;
        Window_ClosePane((Entry_0205d6a0*)self->updateState,0);
        self->commands[self->index]=0;self->index--;
        func_ov000_0217c638(self,a,b);
    }
}
