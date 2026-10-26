#include <globaldefs.h>
extern "C" void* memset(void*, int, unsigned int);
#include "GameState/GameState.h"

struct Struct_0205d81c;
struct Container020e0310;
struct StoreStruct;
extern "C" void* MessageSystem_GetInstance();
extern "C" void Window_SetPanePalette(Struct_0205d81c*, int, int);
extern "C" int KeyTable_Get(Container020e0310*, int);
extern "C" int Text_Append(char*, const char*);
extern "C" void func_ov003_0216abd8(void*, char*);
extern "C" void func_ov003_02169c3c(void*);
extern "C" int func_ov003_02169eec(void*, void*);
extern "C" void func_02046380(void*);
extern "C" void func_020465c0(StoreStruct*, int, int);
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
enum { Enum_ov003_02168d3c_228=0xe4, Enum_ov003_02168d3c_2464=0x9a0, Enum_ov003_02168d3c_6574=0x19ae, Enum_ov003_02168d3c_2400=0x960 };
#endif
struct Struct_ov003_02168d3c {
    char pad0[0x64];
    char messages[0x18];
    char* text;
    char unknown_80_[Enum_ov003_02168d3c_228-0x80];
    char menu[0x404];
    unsigned char state;
    char pad1[2];
    unsigned char changed;
    unsigned char next;
    char pad2[2];
    unsigned char digits[4];
    unsigned char unknown_4f3_[4];
    char pad3;
    unsigned int maximum;
    char pad4[0xa4];
    unsigned int selected;
};
struct Global68d3c {
    char pad0[Enum_ov003_02168d3c_2464-8];
    int busy;
    int pad1;
    int stage;
    char pad2[Enum_ov003_02168d3c_6574-Enum_ov003_02168d3c_2464-4];
    unsigned char flag;
};
struct Party68d3c { char pad0[0xf68]; unsigned int bank; unsigned int unknown_f6c_; };
static inline void inline_ov003_02168d3c(Global68d3c* g, int text) {
#if defined(jpn)
    func_0204500c(g,text,0);
#else
    func_0204500c(g,text,0,0xe3);
#endif
}
static inline void inline_ov003_02168d3c_2(Global68d3c* g,int fmt,char* out) {
#if defined(jpn)
    func_020474a8(g,0xc,fmt,out);
#else
    MessageSystem_FormatText(g,0xc,fmt,out,0xe3,0,1);
#endif
}
// USA: func_ov003_02168d3c
extern "C" ARM void func_ov003_02168d3c(Struct_ov003_02168d3c* self, void* arg, int key) {
    GameState* gs=GameState::GetInstance();
    Global68d3c* global=(Global68d3c*)MessageSystem_GetInstance();
    Party68d3c* party=(Party68d3c*)GameState_GetParty(gs);
    if(global->stage==3) global->flag=0;
    if(self->state==0) {
        Window_SetPanePalette((Struct_0205d81c*)self->menu,1,1);
        if(key==0x3f2) {
            int error=-1;
            if(party->bank>=0x3b9ac618) error=(short)(key+5);
            else if(party->unknown_f6c_<1000) error=(short)(key+3);
            if(error>=0) {
                memset(self->text,0,Enum_ov003_02168d3c_2400);
                int text=KeyTable_Get((Container020e0310*)self->messages,error);
                Text_Append(self->text,(const char*)text);
                func_ov003_0216abd8(self,self->text);
                inline_ov003_02168d3c(global,(int)self->text);
                self->state=3;
                return;
            }
            unsigned int value=party->unknown_f6c_/1000;
            int var6=1;
            for(int i=3;i>=0;--i) {
                unsigned int a=value/var6;
                unsigned int b=value/(var6*10);
                self->unknown_4f3_[i]=a-b*10;
                var6*=10;
            }
            self->maximum=value*1000;
        } else if(key==0x3fc) {
            int error=-1;
            if(party->bank==0) error=(short)(key+3);
            else if(party->unknown_f6c_>=0x989298) error=(short)(key+4);
            if(error>=0) {
                memset(self->text,0,Enum_ov003_02168d3c_2400);
                int text=KeyTable_Get((Container020e0310*)self->messages,error);
                Text_Append(self->text,(const char*)text);
                func_ov003_0216abd8(self,self->text);
                inline_ov003_02168d3c(global,(int)self->text);
                self->state=3;
                return;
            }
            func_02046380(global);
            func_020465c0((StoreStruct*)global,0,party->bank);
            func_020465f0((unsigned char*)global,0,0);
            unsigned int value=party->bank/1000;
            unsigned int var13=party->unknown_f6c_/1000;
            int var14=1;
            if(0x270f-var13<value) value=0x270f-var13;
            for(int i=3;i>=0;--i) {
                unsigned int a=value/var14;
                unsigned int b=value/(var14*10);
                self->unknown_4f3_[i]=a-b*10;
                var14*=10;
            }
            self->maximum=value*1000;
        }
        int text=KeyTable_Get((Container020e0310*)self->messages,(short)key);
        inline_ov003_02168d3c(global,text);
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
            memset(self->text,0,Enum_ov003_02168d3c_2400);
            int text=KeyTable_Get((Container020e0310*)self->messages,0x406);
            Text_Append(self->text,(const char*)text);
            func_ov003_0216abd8(self,self->text);
            inline_ov003_02168d3c(global,(int)self->text);
            self->state++;
            return;
        }
        if(result!=0) return;
        func_0205d6e4((Struct_0205d81c*)self->menu,1);
        void* element=func_0205d81c((Struct_0205d81c*)self->menu,1);
        *(unsigned short*)((char*)element+0xc2)=1;
        bool var22=false;
        bool error=false;
        int message=(short)key;
        if(message==0x3f2) {
            if(party->bank+self->selected>0x3b9ac618) {
                error=true;
                message=(short)(message+4);
            } else if(func_ov003_02169938((int)self,-self->selected)) {
                var22=true;
                party->bank+=self->selected;
            }
        } else if(message==0x3fc) {
            if(self->selected<=party->bank) {
                if(party->unknown_f6c_+self->selected>0x98967f) {
                    error=true;
                    message=(short)(message+4);
                } else {
                    party->bank-=self->selected;
                    func_ov003_02169938((int)self,self->selected);
                    var22=true;
                }
            }
        }
        if(var22) {
            self->changed=1;
            memset(self->text,0,Enum_ov003_02168d3c_2400);
            func_02046380(global);
            func_020465c0((StoreStruct*)global,0,self->selected);
            func_020465f0((unsigned char*)global,0,0);
            int text=KeyTable_Get((Container020e0310*)self->messages,(short)(message+1));
            inline_ov003_02168d3c_2(global,text,self->text);
            func_ov003_0216abd8(self,self->text);
            inline_ov003_02168d3c(global,(int)self->text);
            self->state++;
        } else if(error) {
            func_02046380(global);
            func_020465c0((StoreStruct*)global,0,0x3b9ac618-party->bank);
            func_020465f0((unsigned char*)global,0,0);
            int text=KeyTable_Get((Container020e0310*)self->messages,message);
            inline_ov003_02168d3c_2(global,text,self->text);
            func_ov003_0216abd8(self,self->text);
            inline_ov003_02168d3c(global,(int)self->text);
            self->state++;
        } else {
            memset(self->text,0,Enum_ov003_02168d3c_2400);
            int text=KeyTable_Get((Container020e0310*)self->messages,(short)(message+2));
            Text_Append(self->text,(const char*)text);
            text=KeyTable_Get((Container020e0310*)self->messages,message);
            Text_Append(self->text,(const char*)text);
            inline_ov003_02168d3c(global,(int)self->text);
            for(int i=0;i<4;++i) self->digits[i]=0;
            self->selected=0;
            self->state=1;
        }
    } else if(self->state==3) {
        if(global->busy==0) { self->next=6; self->state=0; }
    }
}
