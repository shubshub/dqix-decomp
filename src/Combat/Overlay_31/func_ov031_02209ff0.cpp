#include <globaldefs.h>
#include "NitroSDK/Memory.h"

struct Struct_ov031_02209ff0_3 { unsigned char unknown_0_[0x30]; unsigned char resumed; char unknown_31_[3]; unsigned char unknown_34_[0x20]; char unknown_54_[0x20]; unsigned char session[0x20]; char unknown_94_[0x3c1]; unsigned char error; };
struct Struct_ov031_02209ff0 { char pad0[0xc]; Struct_ov031_02209ff0_3* state; char pad10[8]; unsigned short field18; char pad1a[2]; void* field1c; };
struct Struct_ov031_02209ff0_2 { unsigned char unknown_0_, unknown_1_, unknown_2_, recordLength[2], unknown_5_, unknown_6_[3], unknown_9_, unknown_a_, unknown_b_[32], unknown_2b_, session[32]; };
extern void* (*data_ov031_0224c994)(unsigned int);
extern void (*data_ov031_0224c9c0)(void*);
extern unsigned short data_ov031_022496fc[] __attribute__((aligned(4)));
extern "C" unsigned int func_ov031_02207c98();
extern "C" void func_ov031_02209cf8(void*,int);
extern "C" void func_ov031_02207aa4(Struct_ov031_02209ff0_3*,void*,unsigned short);
extern "C" void func_ov031_022037a8(void*,int,int,int,Struct_ov031_02209ff0*);
extern "C" void func_ov031_022098ac(void*,int,int);

// USA: func_ov031_02209ff0
extern "C" ARM void func_ov031_02209ff0(Struct_ov031_02209ff0* arg0) {
    Struct_ov031_02209ff0_3* state=arg0->state;
    Struct_ov031_02209ff0_2* var1=(Struct_ov031_02209ff0_2*)data_ov031_0224c994(0x98);
    if(!var1) { state->error=9; return; }
    var1->unknown_9_=3; var1->unknown_a_=0;
    unsigned int var2=func_ov031_02207c98();
    state->unknown_34_[0]=var2>>24; state->unknown_34_[1]=var2>>16;
    state->unknown_34_[2]=var2>>8; state->unknown_34_[3]=var2;
    func_ov031_02209cf8(state->unknown_34_+4,28);
    VectorizedInvertedMemcpy(state->unknown_34_,var1->unknown_b_,32);
    func_ov031_02207aa4(state,arg0->field1c,arg0->field18);
    int length;
    char* cursor;
    if(!state->resumed) { var1->unknown_2b_=0; cursor=(char*)var1->session; }
    else { var1->unknown_2b_=32; VectorizedInvertedMemcpy(state->session,var1->session,32); cursor=(char*)var1->session+32; }
    length=0;
    cursor[0]=0; cursor[1]=4; cursor+=2;
    do {
        cursor[0]=data_ov031_022496fc[length]>>8;
        cursor[1]=data_ov031_022496fc[length];
        cursor+=2;
    } while((unsigned int)++length<2);
    cursor[0]=1; cursor[1]=0;
    cursor+=2;
    length=cursor-(char*)var1;
    length-=5;
    int var5=length-4;
    var1->unknown_0_=0x16; var1->unknown_1_=3; var1->unknown_2_=0;
    var1->recordLength[0]=length>>8; var1->recordLength[1]=length;
    var1->unknown_5_=1;
    var1->unknown_6_[0]=var5>>16;
    var1->unknown_6_[1]=var5>>8;
    var1->unknown_6_[2]=var5;
    func_ov031_022037a8(var1,length+5,0,0,arg0);
    func_ov031_022098ac(state,(int)&var1->unknown_5_,length);
    data_ov031_0224c9c0(var1);
}
