#include "Resource/ActionDataTables.h"
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"

#if defined(jpn)
#define RG(u, j) (j)
#else
#define RG(u, j) (u)
#endif

struct Struct_0203d028;
struct Struct_ov000_0215440c_2 { unsigned short unknown_0_; };
struct Struct_ov025_021dbe10_2 { unsigned char unknown_0_[0x20]; unsigned short unknown_20_; };
struct Struct_ov025_021d8a40;
struct Struct_ov025_021dbe10_3 {
    unsigned char unknown_0_[0x18];
    unsigned int unknown_18_0_ : 5;
    unsigned int unknown_18_5_ : 7;
    unsigned int unknown_19_4_ : 4;
    unsigned int unknown_1a_0_ : 16;
};
struct Struct_ov025_021dbe10_4 {
    unsigned char unknown_0_[0x30];
    SafeAllocator unknown_30_;
    unsigned char unknown_44_[RG(0x14c, 0x138) - 0x30 - sizeof(SafeAllocator)];
    unsigned char unknown_14c_[RG(0x150, 0xe0)];
    char* unknown_29c_;
    unsigned char unknown_2a0_[8];
    char unknown_2a8_[0xc04];
    int unknown_eac_;
    unsigned char unknown_eb0_[RG(0x4874, 0x4ae8)];
    void* unknown_5724_;
    unsigned char unknown_5728_[0x229];
    unsigned char unknown_5951_;
    unsigned char unknown_5952_[0x14f9];
    unsigned char unknown_6e4b_;
    unsigned char unknown_6e4c_[2];
    unsigned char unknown_6e4e_;
    unsigned char unknown_6e4f_[0xad];
    short unknown_6efc_;
    unsigned char unknown_6efe_;
    unsigned char unknown_6eff_[2];
    unsigned char unknown_6f01_;
    unsigned char unknown_6f02_[0xb6];
    short unknown_6fb8_;
    unsigned char unknown_6fba_[0x1a];
    unsigned char unknown_6fd4_;
    unsigned char unknown_6fd5_;
    short unknown_6fd6_;
    unsigned char unknown_6fd8_;
    unsigned char unknown_6fd9_[3];
    Vector3i unknown_6fdc_;
    unsigned char unknown_6fe8_;
    unsigned char unknown_6fe9_[3];
    Vector3i unknown_6fec_;
    unsigned char unknown_6ff8_;
    unsigned char unknown_6ff9_;
    unsigned char unknown_6ffa_[0x74a];
    unsigned char unknown_7744_[3];
};
struct Struct_ov025_021dbe10 { unsigned char unknown_0_[0xc]; int unknown_c_; };
extern "C" Struct_ov025_021dbe10 _ZZ21inline_ov025_021dcf14vE1s;
extern char data_ov025_021ef40c[];
extern char data_ov025_021ef424[];
extern char data_ov025_021ef43c[];
extern int data_ov025_021ef404;
void VramState_Rewind(Foo0207df50*);
extern "C" void func_ov025_021dee20(ActionState*);
List02160094* GetSlotPtr02160f20(void*);
BattleSource* GetNodeAtIndex02160094(List02160094*, int);
void UpdateFlagAndDispatch_021dc0d8(void*);
void* GetField0Result02169a58_02048ab4(void*, int);
extern "C" void* func_ov025_021dfa9c(ActionState*, char*);
int ClassifyField0x81fe_ov000_0215fc60(char*);
extern "C" void* func_ov000_02169a58(void*, int);
extern "C" void func_ov025_021e88d8(void*);
extern "C" void func_ov025_021e8a40(char*, int, int);
extern "C" void func_ov025_021e8a4c(char*, int);
extern "C" void func_ov025_021e8d20(char*, void*);
extern "C" void func_ov025_021db8d8(Struct_ov025_021dbe10_4*);
extern "C" Struct_ov025_021dbe10_3* func_02079e2c(char*, int);
extern "C" void func_ov025_021d8a40(void*, Struct_ov025_021d8a40*);
extern "C" void func_ov025_021def30(unsigned char*);
static inline int inline_ov000_02156cc4_2(unsigned int arg0) { return arg0 <= 3; }

// USA: func_ov025_021dbe10
extern "C" ARM void func_ov025_021dbe10(ActionState* state) {
    GameState* game = GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    char* battle = state->battle;
    state->allocator.Reset();
    VramState_Rewind((Foo0207df50*)state->tables);
    func_ov025_021dee20(state);
    List02160094* list = GetSlotPtr02160f20(state);
    if (!list) return;
    BattleSource* source = GetNodeAtIndex02160094(list, 0);
    if (!source) return;
    state->state = 0;
    state->field6e4e = 0;
    state->field6efc = -1;
    state->pending = 0;
    state->source = -1;
    state->field6fd8 = 0;
    state->field6fb8 = -1;
    state->field6f01 = 0;
    state->faded = 0;
    Vector3i zero = {};
    state->position = zero;
    state->field6fe8 = 0;
    state->offset = zero;
    state->field6ff8 = 0;
    state->field6ff9 = 0;
    state->slots[0] = 0xff;
    state->slots[1] = 0xff;
    state->slots[2] = 0xff;
    state->flags &= ~4;
    _ZZ16GetTimer021ef974vE1s.fieldc = 0;
    UpdateFlagAndDispatch_021dc0d8(state);
    int reset = 1;
    GameObject* object = game->GetCombatantByIndex(source->id);
    if (object) {
        int kind = list->kind;
        if (kind == 0x3ae) reset = 0;
        void* script = GetField0Result02169a58_02048ab4(object, kind);
        void* overrideScript = func_ov025_021dfa9c(state, state->battle);
        if (overrideScript) script = overrideScript;
        if (ClassifyField0x81fe_ov000_0215fc60(battle) && source->id == 0)
            script = func_ov000_02169a58(state->specialCombatant, 0xdd);
        if (script) {
            func_ov025_021e88d8(state->script);
            SetTwoFields_021e8a40(state->script, (int)&state->allocator, (int)state->tables);
            SetField_021e8a4c(state->script, (int)state->battle);
            func_ov025_021e8d20(state->script, script);
            func_ov025_021db8d8(state);
        } else {
            Struct_ov025_021dbe10_3* var11 = func_02079e2c((char*)func_020797dc(), (short)var8);
            if (var11) {
                if (var11->unknown_18_5_ == 0x22) func_ov025_021d8a40(arg0, (Struct_ov025_021d8a40*)var3);
                else {
                    char var12[0x50];
                    if (var11->unknown_19_4_ == 2) sprintf(var12, data_ov025_021ef40c);
                    else if ((var11->unknown_19_4_ == 1 || var11->unknown_19_4_ == 4) && inline_ov000_02156cc4_2(var4->unknown_20_))
                        sprintf(var12, data_ov025_021ef424);
                    else sprintf(var12, data_ov025_021ef43c);
                    data_ov025_021ef404 = var1->QueueLoadFile(var12, 0);
                    arg0->unknown_eac_ = 4;
                }
            }
        }
    }
    if (var6) arg0->unknown_6fd5_ = 0;
    if (arg0->unknown_eac_ == 1) func_ov025_021def30((unsigned char*)arg0);
}
