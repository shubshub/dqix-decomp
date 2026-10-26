#include <globaldefs.h>
#include "GameState/GameState.h"
extern "C" GameObject* func_ov000_021536f8(int,int);
extern "C" void* func_ov000_02160130();
struct Struct_ov024_021fea1c;
extern "C" int func_ov000_0215fb54(int, int, Struct_ov024_021fea1c*);
extern "C" void* func_ov000_02162d88(void*,int);
extern "C" int func_ov000_02161380(void*,int,int,int);
struct Struct_ov024_021dc2a0_8 {char pad[0xe];short unknown_e_;short field10;short field12;short field14;char pad16;unsigned char unknown_17_;char pad18[8];int field20;};
extern "C" Struct_ov024_021dc2a0_8* func_ov000_0215e938(void*);
struct Struct_ov000_0215fef0;
extern "C" void func_ov000_0215fef0(Struct_ov000_0215fef0*);
extern "C" Struct_ov024_021dc2a0_8* func_ov000_0215e958(void*);
extern "C" void func_ov000_0215fd7c(void*);
extern "C" void func_ov000_0215ffc4(void*,void*,int);
struct Struct_ov000_0215767c_4;
struct Struct_ov000_0215767c_5;
extern "C" void func_ov000_021600cc(Struct_ov000_0215767c_5*, Struct_ov000_0215767c_4*);
extern "C" void func_ov000_0215a88c(void*,void*,int);
extern "C" void func_ov000_0215cd44(void*,void*,GameObject*,int,int,int,int);
struct Struct_ov024_021fe6d0 {int values[2];};
extern Struct_ov024_021fe6d0 data_ov024_021fe6d0;
struct Struct_ov024_021dc2a0 {unsigned int value:12;unsigned int rest:20;};
struct Struct_ov024_021dc2a0_2 {unsigned int low:5;unsigned int mode:7;unsigned int high:20;};
struct Struct_ov024_021dc2a0_3 {unsigned int a:10;unsigned int b:10;unsigned int c:10;unsigned int high:2;};
struct Struct_ov024_021dc2a0_4 {char pad[4];Struct_ov024_021dc2a0 code;char pad8[0x10];Struct_ov024_021dc2a0_2 field18;char unknown_1c_[8];Struct_ov024_021dc2a0_3 field24;};
struct Struct_ov024_021dc2a0_5 {unsigned short code;};
struct Struct_ov024_021dc2a0_6 {char pad[4];Struct_ov024_021dc2a0_5* message;char pad8[8];void* context;int count;};
struct Struct_ov024_021dc2a0_7 {char pad[0x188];unsigned short hp;unsigned short mp;};
// USA: func_ov024_021dc2a0
extern "C" ARM void* func_ov024_021dc2a0(Struct_ov024_021dc2a0_6* obj,short id,int unused,Struct_ov024_021dc2a0_4* params,int arg4,int arg5,unsigned char enabled){
    GameObject* c=func_ov000_021536f8((int)obj->context,id);
    if(!c)return 0;
    void* work=func_ov000_02160130();
    int total=1;
    Struct_ov024_021fe6d0 ids=data_ov024_021fe6d0;
    ids.values[0]=c->obj3D_.unknown_2_;
    if(params->field18.mode==12){
        total=func_ov000_0215fb54((int)obj->context, params->code.value, (Struct_ov024_021fea1c*)&ids);
        for(int i=0;i<total;i++){
            if(!func_ov000_02162d88(work,ids.values[i])){total=0;break;}
        }
    }
    int slot=-1;
    if(params->code.value==0xf2)slot=*(signed char*)((char*)c+0x17c);
    int var6=0;
    if(enabled){
        for(int i=0;i<total;i++){
            for(int j=0;j<1;j++){
                int var9=func_ov000_02161380(work,ids.values[i],slot,1);
                if(var9>=0xc0){
                    Struct_ov024_021dc2a0_8* node=func_ov000_0215e938(obj->context);
                    if(node){
                        func_ov000_0215fef0((Struct_ov000_0215fef0*)node);
                        node->field20=0;
                        node->unknown_e_=var9;
                        node->unknown_17_=1;
                        GameObject* actor=func_ov000_021536f8((int)obj->context,var9);
                        if(actor){
                            Struct_ov024_021dc2a0_8* entry=func_ov000_0215e958(obj->context);
                            if(entry){
                                func_ov000_0215fd7c(entry);
                                entry->field20=0;
                                entry->unknown_e_=((Struct_ov024_021dc2a0_7*)actor)->hp;
                                entry->field10=((Struct_ov024_021dc2a0_7*)actor)->mp;
                                entry->field12=((Struct_ov024_021dc2a0_7*)actor)->hp;
                                entry->field14=((Struct_ov024_021dc2a0_7*)actor)->mp;
                                func_ov000_0215ffc4(node,entry,0);
                                ((unsigned char*)obj->context)[0x8e02]++;
                                func_ov000_021600cc((Struct_ov000_0215767c_5*)obj->message, (Struct_ov000_0215767c_4*)node);
                                var6++;
                                ((unsigned char*)obj->context)[0x8e01]++;
                                obj->count++;
                            }
                        }
                    }
                }
            }
        }
    }
    if(var6<=0){
        Struct_ov024_021dc2a0_8* entry=func_ov000_0215e958(obj->context);
        if(!entry)return 0;
        obj->message->code=0x1f5;
        unsigned short selection=params->field24.c;
        func_ov000_0215a88c(obj->context,entry,selection);
        GameObject* actor=func_ov000_021536f8((int)obj->context,id);
        if(!actor)return 0;
        func_ov000_0215cd44(obj->context,entry,actor,0,0,0,0);
        return entry;
    }
    return 0;
}
