#include <globaldefs.h>
extern "C" void* memset(void*, int, unsigned int);
#include "GameState/GameState.h"

struct Struct_0205d81c;
struct Container020e0310;
struct StoreStruct;
void* MessageSystem_GetInstance();
void Window_SetPanePalette(Struct_0205d81c*, int, int);
int KeyTable_Get(Container020e0310*, int);
int Text_Append(char*, const char*);
extern "C" void func_ov003_0216abd8(void*, char*);
extern "C" void func_ov003_02169c3c(void*);
extern "C" int func_ov003_02169eec(void*, void*);
extern "C" void func_02046380(void*);
extern "C" void func_020465c0(Struct_020465c0*, int, int);
extern "C" void func_020465f0(unsigned char*, int, unsigned char);
extern "C" void func_0205d6e4(Struct_0205d81c*, int);
extern "C" void* func_0205d81c(Struct_0205d81c*, int);
extern "C" int func_ov003_02169938(int, int);
#if defined(jpn)
extern "C" void func_0204500c(void*, int, int);
extern "C" void func_020474a8(void*, int, int, char*);
enum { Enum_ov003_02168d3c_228=0xe0, Enum_ov003_02168d3c_2464=0x870, Enum_ov003_02168d3c_6574=0x17de, Enum_ov003_02168d3c_2400=0x800 };
#else
extern "C" void func_0204500c(void*, int, int, int);
extern "C" void MessageSystem_FormatText(void*, int, int, char*, int, int, int);
enum { kMenu68d3c=0xe4, kStage68d3c=0x9a0, kFlag68d3c=0x19ae, kTextSize68d3c=0x960 };
#endif
struct Struct_ov003_02168d3c {
    char unknown_0_[0x64];
    char unknown_64_[0x18];
    char* unknown_7c_;
    char unknown_80_[Enum_ov003_02168d3c_228-0x80];
    char unknown_e4_[0x404];
    unsigned char unknown_4e8_;
    char unknown_4e9_[2];
    unsigned char unknown_4eb_;
    unsigned char unknown_4ec_;
    char unknown_4ed_[2];
    unsigned char unknown_4ef_[4];
    unsigned char unknown_4f3_[4];
    char unknown_4f7_;
    unsigned int unknown_4f8_;
    char unknown_4fc_[0xa4];
    unsigned int unknown_5a0_;
};
struct Struct_ov003_02168d3c_2 {
    char unknown_0_[Enum_ov003_02168d3c_2464-8];
    int unknown_998_;
    int unknown_99c_;
    int unknown_9a0_;
    char unknown_9a4_[Enum_ov003_02168d3c_6574-Enum_ov003_02168d3c_2464-4];
    unsigned char unknown_19ae_;
};
struct Struct_ov003_02168d3c_3 { char unknown_0_[0xf68]; unsigned int unknown_f68_; unsigned int unknown_f6c_; };
static inline void inline_ov003_02168d3c(Struct_ov003_02168d3c_2* arg0, int arg1) {
#if defined(jpn)
    func_0204500c(arg0,arg1,0);
#else
    func_0204500c(arg0,arg1,0,0xe3);
#endif
}
static inline void inline_ov003_02168d3c_2(Struct_ov003_02168d3c_2* arg0,int arg1,char* arg2) {
#if defined(jpn)
    func_020474a8(arg0,0xc,arg1,arg2);
#else
    MessageSystem_FormatText(g,0xc,fmt,out,0xe3,0,1);
#endif
}
// USA: func_ov003_02168d3c
extern "C" ARM void func_ov003_02168d3c(Obj68d3c* self, void* arg, int key) {
    GameState* gs=GameState::GetInstance();
    Global68d3c* global=(Global68d3c*)MessageSystem_GetInstance();
    Party68d3c* party=(Party68d3c*)GameState_GetParty(gs);
    if(global->stage==3) global->flag=0;
    if(self->state==0) {
        Window_SetPanePalette((Struct_0205d81c*)self->menu,1,1);
        if(key==0x3f2) {
            int error=-1;
            if(party->bank>=0x3b9ac618) error=(short)(key+5);
            else if(party->money<1000) error=(short)(key+3);
            if(error>=0) {
                memset(self->text,0,kTextSize68d3c);
                int text=KeyTable_Get((Container020e0310*)self->messages,error);
                Text_Append(self->text,(const char*)text);
                func_ov003_0216abd8(self,self->text);
                Show68d3c(global,(int)self->text);
                self->state=3;
                return;
            }
            unsigned int var5=var2->unknown_f6c_/1000;
            int var6=1;
            for(int var7=3;var7>=0;--var7) {
                unsigned int var8=var5/var6;
                unsigned int var9=var5/(var6*10);
                arg0->unknown_4f3_[var7]=var8-var9*10;
                var6*=10;
            }
            self->maximum=value*1000;
        } else if(key==0x3fc) {
            int error=-1;
            if(party->bank==0) error=(short)(key+3);
            else if(party->money>=0x989298) error=(short)(key+4);
            if(error>=0) {
                memset(self->text,0,kTextSize68d3c);
                int text=KeyTable_Get((Container020e0310*)self->messages,error);
                Text_Append(self->text,(const char*)text);
                func_ov003_0216abd8(self,self->text);
                Show68d3c(global,(int)self->text);
                self->state=3;
                return;
            }
            func_02046380(var1);
            func_020465c0((Struct_020465c0*)var1,0,var2->unknown_f68_);
            func_020465f0((unsigned char*)var1,0,0);
            unsigned int var12=var2->unknown_f68_/1000;
            unsigned int var13=var2->unknown_f6c_/1000;
            int var14=1;
            if(0x270f-var13<var12) var12=0x270f-var13;
            for(int var15=3;var15>=0;--var15) {
                unsigned int var16=var12/var14;
                unsigned int var17=var12/(var14*10);
                arg0->unknown_4f3_[var15]=var16-var17*10;
                var14*=10;
            }
            arg0->unknown_4f8_=var12*1000;
        }
        int text=KeyTable_Get((Container020e0310*)self->messages,(short)key);
        Show68d3c(global,text);
        self->state++;
    } else if(self->state==1) {
        if(global->stage==3) {
            func_ov003_02169c3c(self);
            Window_SetPanePalette((Struct_0205d81c*)self->menu,0,0);
            Window_SetPanePalette((Struct_0205d81c*)self->menu,2,0);
            self->state++;
        }
    } else if(self->state==2) {
        int result=func_ov003_02169eec(self,arg);
        if(result==-1) return;
        if(result==-2) {
            func_0205d6e4((Struct_0205d81c*)self->menu,1);
            Window_SetPanePalette((Struct_0205d81c*)self->menu,1,1);
            memset(self->text,0,kTextSize68d3c);
            int text=KeyTable_Get((Container020e0310*)self->messages,0x406);
            Text_Append(self->text,(const char*)text);
            func_ov003_0216abd8(self,self->text);
            Show68d3c(global,(int)self->text);
            self->state++;
            return;
        }
        if(var19!=0) return;
        func_0205d6e4((Struct_0205d81c*)arg0->unknown_e4_,1);
        void* var21=func_0205d81c((Struct_0205d81c*)arg0->unknown_e4_,1);
        *(unsigned short*)((char*)var21+0xc2)=1;
        bool var22=false;
        bool var23=false;
        int var24=(short)arg2;
        if(var24==0x3f2) {
            if(var2->unknown_f68_+arg0->unknown_5a0_>0x3b9ac618) {
                var23=true;
                var24=(short)(var24+4);
            } else if(func_ov003_02169938((int)arg0,-arg0->unknown_5a0_)) {
                var22=true;
                var2->unknown_f68_+=arg0->unknown_5a0_;
            }
        } else if(var24==0x3fc) {
            if(arg0->unknown_5a0_<=var2->unknown_f68_) {
                if(var2->unknown_f6c_+arg0->unknown_5a0_>0x98967f) {
                    var23=true;
                    var24=(short)(var24+4);
                } else {
                    var2->unknown_f68_-=arg0->unknown_5a0_;
                    func_ov003_02169938((int)arg0,arg0->unknown_5a0_);
                    var22=true;
                }
            }
        }
        if(success) {
            self->changed=1;
            memset(self->text,0,kTextSize68d3c);
            func_02046380(global);
            StoreInArray0x8b0_020465c0((StoreStruct*)global,0,self->selected);
            SetByteInRange_020465f0((unsigned char*)global,0,0);
            int text=KeyTable_Get((Container020e0310*)self->messages,(short)(message+1));
            Format68d3c(global,text,self->text);
            func_ov003_0216abd8(self,self->text);
            Show68d3c(global,(int)self->text);
            self->state++;
        } else if(error) {
            func_02046380(global);
            StoreInArray0x8b0_020465c0((StoreStruct*)global,0,0x3b9ac618-party->bank);
            SetByteInRange_020465f0((unsigned char*)global,0,0);
            int text=KeyTable_Get((Container020e0310*)self->messages,message);
            Format68d3c(global,text,self->text);
            func_ov003_0216abd8(self,self->text);
            Show68d3c(global,(int)self->text);
            self->state++;
        } else {
            memset(self->text,0,kTextSize68d3c);
            int text=KeyTable_Get((Container020e0310*)self->messages,(short)(message+2));
            Text_Append(self->text,(const char*)text);
            text=KeyTable_Get((Container020e0310*)self->messages,message);
            Text_Append(self->text,(const char*)text);
            Show68d3c(global,(int)self->text);
            for(int i=0;i<4;++i) self->digits[i]=0;
            self->selected=0;
            self->state=1;
        }
    } else if(arg0->unknown_4e8_==3) {
        if(var1->unknown_998_==0) { arg0->unknown_4ec_=6; arg0->unknown_4e8_=0; }
    }
}
