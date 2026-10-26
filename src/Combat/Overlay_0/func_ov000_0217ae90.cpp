#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Input/Input.h"

#if defined(jpn)
enum {Enum_ov000_0217ae90_130=0xc2,Enum_ov000_0217ae90_1085=0x47d,Enum_ov000_0217ae90_7538=0x1faa};
#else
enum {Enum_ov000_0217ae90_130=0x82,Enum_ov000_0217ae90_1085=0x43d,Enum_ov000_0217ae90_7538=0x1d72};
#endif
struct Struct_ov000_0217ae90_2 {
    char p0[8];signed char commands[8];signed char index;char p1[3];
    signed char mode;unsigned char count;short unknown_16_;
    signed char unknown_18_,unknown_19_,unknown_1a_,unknown_1b_;char p2[2];short kind;
    char p3[6];signed char unknown_26_;char p4[9];
};
struct Container020e0310;struct Struct_0205c570;struct Obj_0205da38;struct Entry_0205d6a0;
struct Obj0203c108;struct SePlayer;
struct Struct_ov000_021682ec_5 {
    int p0;Container020e0310* container;Struct_ov000_0217ae90_2 command;
    Struct_0205c570* active;char p1[0x4c-0x3c];int member;
    char entry[Enum_ov000_0217ae90_130-0x50];short unknown_82_,unknown_84_;signed char unknown_86_;
    char p2[Enum_ov000_0217ae90_1085-Enum_ov000_0217ae90_130-5];signed char saved;
    char p3[6];unsigned char flag;
};
struct Struct_ov000_0217ab8c_2 {char p[Enum_ov000_0217ae90_7538];unsigned short flags;};
#if defined(jpn)
struct GlobalData {Struct_ov000_0217ab8c_2* root;void* work;int other;};
#else
struct GlobalData {void* work;int other;Struct_ov000_0217ab8c_2* root;};
#endif
struct Struct_ov000_0217ae90 {char p[0x3b];unsigned char low:3,flag:1,high:4;};
struct Unit {char p[0x138];Struct_ov000_0217ae90* unknown_138_;};
extern GlobalData data_ov000_02184294;
extern SePlayer g_sePlayer;
extern "C" GameObject* func_0200ff1c(GameState*,int);
extern "C" int func_02053c6c(unsigned char*);
extern "C" int Window_GetSelectedIndex(Struct_0205c570*);
extern "C" void SePlayer_Play(SePlayer*,int,int);
extern "C" int KeyTable_Get(Container020e0310*,int);
extern "C" void CachedTextLabel_SetText(Obj0203c108*,char*);
extern "C" int func_ov000_0217ab48(void*);
extern "C" void Window_ClosePane(Entry_0205d6a0*,int);
extern "C" int Window_IsSelectionTouched(struct Obj_0205da38* obj, int key);
extern "C" {
void Zone3D_GetInstance();
extern "C" void* func_ov000_02174504(Struct_ov000_0217ab8c_2*);
int func_ov000_0217c2a0(void*);int func_ov000_0217aa78(void*,int,int);
void func_ov000_0217c32c(void*);void func_ov000_02171c04(void*);
}

// USA: func_ov000_0217ae90
extern "C" ARM int func_ov000_0217ae90(Struct_ov000_021682ec_5* self)
{
    Unit* unit=(Unit*)func_0200ff1c(GameState::GetInstance(),self->member);
    int state=0;
    if(unit)state=func_02053c6c((unsigned char*)unit);
    Zone3D_GetInstance();
    Struct_ov000_0217ae90_2* command=&self->command;
    command->mode=Window_GetSelectedIndex(self->active);
    command->kind=0;
    data_ov000_02184294.root->flags|=0x100;
    bool flag=g_keyManager.TestKeysPressed(0x601);
    bool active=flag | Window_IsSelectionTouched((Obj_0205da38*)self->active,20);
    if(active){
        self->flag=0;
        data_ov000_02184294.work=func_ov000_02174504(data_ov000_02184294.root);
        switch(command->mode){
        case 0:
            self->saved=self->command.commands[self->command.index];
            SePlayer_Play(&g_sePlayer,1,0);
            command->index++;command->commands[command->index]=14;
            command->count=0;command->unknown_19_=-1;command->unknown_26_=-1;command->kind=1;
            if(func_ov000_0217c2a0(self)){
                command->commands[command->index]=100;
                CachedTextLabel_SetText((Obj0203c108*)self->entry,(char*)KeyTable_Get(self->container,0x7534));
            }
            return command->commands[command->index];
        case 1:
            self->saved=self->command.commands[self->command.index];
            SePlayer_Play(&g_sePlayer,1,0);
            if(self->unknown_82_){
                command->index++;command->commands[command->index]=15;command->unknown_18_=0;
                if(state)command->unknown_18_=func_ov000_0217aa78(self,self->unknown_82_,0);
                return command->commands[command->index];
            }else{
                data_ov000_02184294.root->flags&=~0x100;
                command->index++;command->commands[command->index]=27;command->unknown_18_=-1;
                return command->commands[command->index];
            }
        case 2:
            self->saved=self->command.commands[self->command.index];command->kind=3;
            SePlayer_Play(&g_sePlayer,1,0);
            CachedTextLabel_SetText((Obj0203c108*)self->entry,(char*)KeyTable_Get(self->container,0x7536));
            command->index++;command->commands[command->index]=100;
            return command->commands[command->index];
        case 3:
            self->saved=self->command.commands[self->command.index];
            SePlayer_Play(&g_sePlayer,1,0);
            if(self->unknown_84_){
                command->index++;command->commands[command->index]=16;command->unknown_16_=0;
                if(state)command->unknown_16_=func_ov000_0217aa78(self,self->unknown_84_,1);
                func_ov000_0217c32c(self);
                return command->commands[command->index];
            }else{
                data_ov000_02184294.root->flags&=~0x100;
                command->index++;command->commands[command->index]=28;command->unknown_16_=-1;
                return command->commands[command->index];
            }
        case 4:
            self->saved=self->command.commands[self->command.index];
            SePlayer_Play(&g_sePlayer,1,0);
            func_ov000_02171c04(self);
            if(self->unknown_86_){
                command->index++;command->commands[command->index]=17;command->unknown_1a_=0;
                return command->commands[command->index];
            }else{
                data_ov000_02184294.root->flags&=~0x100;
                command->index++;command->commands[command->index]=29;command->unknown_1a_=-1;
                return command->commands[command->index];
            }
        case 5:
            if(unit->unknown_138_->flag){
                self->saved=self->command.commands[self->command.index];
                SePlayer_Play(&g_sePlayer,1,0);
                command->index++;command->commands[command->index]=21;command->unknown_1b_=0;
                return command->commands[command->index];
            }
            break;
        }
    }else if(func_ov000_0217ab48(self)){
        command->kind=0;data_ov000_02184294.root->flags&=~0x100;
        Window_ClosePane((Entry_0205d6a0*)self->active,1);
        return -2;
    }
    return -1;
}
