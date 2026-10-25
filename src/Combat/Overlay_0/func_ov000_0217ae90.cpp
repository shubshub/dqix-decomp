#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Input/Input.h"

#if defined(jpn)
enum {Enum_ov000_0217ae90_130=0xc2,Enum_ov000_0217ae90_1085=0x47d,Enum_ov000_0217ae90_7538=0x1faa};
#else
enum {Enum_ov000_0217ae90_130=0x82,Enum_ov000_0217ae90_1085=0x43d,Enum_ov000_0217ae90_7538=0x1d72};
#endif
struct Struct_ov000_0217ae90_2 {
    char unknown_0_[8];signed char unknown_8_[8];signed char unknown_10_;char unknown_11_[3];
    signed char unknown_14_;unsigned char unknown_15_;short unknown_16_;
    signed char unknown_18_,unknown_19_,unknown_1a_,unknown_1b_;char unknown_1c_[2];short unknown_1e_;
    char unknown_20_[6];signed char unknown_26_;char unknown_27_[9];
};
struct Container020e0310;struct Struct_0205c570;struct Obj_0205da38;struct Entry_0205d6a0;
struct Obj0203c108;struct SePlayer;
struct Root {
    int p0;Container020e0310* container;CommandState command;
    Struct_0205c570* active;char p1[0x4c-0x3c];int member;
    char entry[selectionOffset-0x50];short selectionA,selectionB;signed char selectionC;
    char p2[savedOffset-selectionOffset-5];signed char saved;
    char p3[6];unsigned char flag;
};
struct Struct_ov000_0217ab8c_2 {char unknown_0_[Enum_ov000_0217ae90_7538];unsigned short unknown_1d72_;};
#if defined(jpn)
struct Struct_ov000_02184294 {Struct_ov000_0217ab8c_2* unknown1_8_;void* unknown_0_;int unknown_8_;};
#else
struct Struct_ov000_02184294 {void* unknown_0_;int unknown_4_;Struct_ov000_0217ab8c_2* unknown1_8_;};
#endif
struct Ability {char p[0x3b];unsigned char low:3,flag:1,high:4;};
struct Unit {char p[0x138];Ability* ability;};
extern GlobalData data_ov000_02184294;
extern SePlayer g_sePlayer;
GameObject* GetCombatantWithFlag0x100_0200ff1c(GameState*,int);
int GetFieldAt0x150_02053c6c(unsigned char*);
int Window_GetSelectedIndex(Struct_0205c570*);
void SePlayer_Play(SePlayer*,int,int);
int KeyTable_Get(Container020e0310*,int);
void SwapGlobalEntry0203c108(Obj0203c108*,char*);
int CheckFlagsOrField_0217ab48_0217ab48(void*);
void Window_ClosePane(Entry_0205d6a0*,int);
int Window_IsSelectionTouched(struct Obj_0205da38* obj, int key);
extern "C" {
void Zone3D_GetInstance();
void* _Z31GetStoredWorkPtr_ov000_02174504v(GlobalRoot*);
int func_ov000_0217c2a0(void*);int func_ov000_0217aa78(void*,int,int);
void func_ov000_0217c32c(void*);void func_ov000_02171c04(void*);
}

// USA: func_ov000_0217ae90
extern "C" ARM int func_ov000_0217ae90(Struct_ov000_021682ec_5* arg0)
{
    Unit* unit=(Unit*)GetCombatantWithFlag0x100_0200ff1c(GameState::GetInstance(),self->member);
    int state=0;
    if(unit)state=GetFieldAt0x150_02053c6c((unsigned char*)unit);
    Zone3D_GetInstance();
    CommandState* command=&self->command;
    command->mode=Window_GetSelectedIndex(self->active);
    command->kind=0;
    data_ov000_02184294.root->flags|=0x100;
    bool flag=g_keyManager.TestKeysPressed(0x601);
    bool active=flag | Window_IsSelectionTouched((Obj_0205da38*)self->active,20);
    if(active){
        self->flag=0;
        data_ov000_02184294.work=_Z31GetStoredWorkPtr_ov000_02174504v(data_ov000_02184294.root);
        switch(command->mode){
        case 0:
            self->saved=self->command.commands[self->command.index];
            SePlayer_Play(&g_sePlayer,1,0);
            command->index++;command->commands[command->index]=14;
            command->count=0;command->value19=-1;command->value26=-1;command->kind=1;
            if(func_ov000_0217c2a0(self)){
                command->commands[command->index]=100;
                SwapGlobalEntry0203c108((Obj0203c108*)self->entry,(char*)KeyTable_Get(self->container,0x7534));
            }
            return var2->unknown_8_[var2->unknown_10_];
        case 1:
            self->saved=self->command.commands[self->command.index];
            SePlayer_Play(&g_sePlayer,1,0);
            if(self->selectionA){
                command->index++;command->commands[command->index]=15;command->value18=0;
                if(state)command->value18=func_ov000_0217aa78(self,self->selectionA,0);
                return command->commands[command->index];
            }else{
                data_ov000_02184294.unknown1_8_->unknown_1d72_&=~0x100;
                var2->unknown_10_++;var2->unknown_8_[var2->unknown_10_]=27;var2->unknown_18_=-1;
                return var2->unknown_8_[var2->unknown_10_];
            }
        case 2:
            self->saved=self->command.commands[self->command.index];command->kind=3;
            SePlayer_Play(&g_sePlayer,1,0);
            SwapGlobalEntry0203c108((Obj0203c108*)self->entry,(char*)KeyTable_Get(self->container,0x7536));
            command->index++;command->commands[command->index]=100;
            return command->commands[command->index];
        case 3:
            self->saved=self->command.commands[self->command.index];
            SePlayer_Play(&g_sePlayer,1,0);
            if(self->selectionB){
                command->index++;command->commands[command->index]=16;command->value16=0;
                if(state)command->value16=func_ov000_0217aa78(self,self->selectionB,1);
                func_ov000_0217c32c(self);
                return command->commands[command->index];
            }else{
                data_ov000_02184294.unknown1_8_->unknown_1d72_&=~0x100;
                var2->unknown_10_++;var2->unknown_8_[var2->unknown_10_]=28;var2->unknown_16_=-1;
                return var2->unknown_8_[var2->unknown_10_];
            }
        case 4:
            self->saved=self->command.commands[self->command.index];
            SePlayer_Play(&g_sePlayer,1,0);
            func_ov000_02171c04(self);
            if(self->selectionC){
                command->index++;command->commands[command->index]=17;command->value1a=0;
                return command->commands[command->index];
            }else{
                data_ov000_02184294.unknown1_8_->unknown_1d72_&=~0x100;
                var2->unknown_10_++;var2->unknown_8_[var2->unknown_10_]=29;var2->unknown_1a_=-1;
                return var2->unknown_8_[var2->unknown_10_];
            }
        case 5:
            if(unit->ability->flag){
                self->saved=self->command.commands[self->command.index];
                SePlayer_Play(&g_sePlayer,1,0);
                command->index++;command->commands[command->index]=21;command->value1b=0;
                return command->commands[command->index];
            }
            break;
        }
    }else if(CheckFlagsOrField_0217ab48_0217ab48(self)){
        command->kind=0;data_ov000_02184294.root->flags&=~0x100;
        Window_ClosePane((Entry_0205d6a0*)self->active,1);
        return -2;
    }
    return -1;
}
