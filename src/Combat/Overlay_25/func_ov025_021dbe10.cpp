#include "Resource/ActionDataTables.h"
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"

#if defined(jpn)
#define RG(u, j) (j)
#else
#define RG(u, j) (u)
#endif

struct Foo0207df50;
struct Struct_ov000_0215440c_2 { unsigned short kind; };
struct Struct_ov025_021dbe10_2 { unsigned char padding0[0x20]; unsigned short id; };
struct Struct_ov025_021d8a40;
struct Struct_ov025_021dbe10_3 {
    unsigned char padding0[0x18];
    unsigned int flags : 5;
    unsigned int category : 7;
    unsigned int kind : 4;
    unsigned int other : 16;
};
struct Struct_ov025_021dbe10_4 {
    unsigned char padding0[0x30];
    SafeAllocator allocator;
    unsigned char unknown_44_[RG(0x14c, 0x138) - 0x30 - sizeof(SafeAllocator)];
    unsigned char tables[RG(0x150, 0xe0)];
    char* battle;
    unsigned char unknown_2a0_[8];
    char script[0xc04];
    int phase;
    unsigned char unknown_eb0_[RG(0x4874, 0x4ae8)];
    void* unknown_5724_;
    unsigned char unknown_5728_[0x229];
    unsigned char flags;
    unsigned char unknown_5952_[0x14f9];
    unsigned char state;
    unsigned char unknown_6e4c_[2];
    unsigned char unknown_6e4e_;
    unsigned char unknown_6e4f_[0xad];
    short unknown_6efc_;
    unsigned char pending;
    unsigned char unknown_6eff_[2];
    unsigned char unknown_6f01_;
    unsigned char unknown_6f02_[0xb6];
    short unknown_6fb8_;
    unsigned char unknown_6fba_[0x1a];
    unsigned char unknown_6fd4_;
    unsigned char unknown_6fd5_;
    short source;
    unsigned char unknown_6fd8_;
    unsigned char unknown_6fd9_[3];
    Vector3i position;
    unsigned char unknown_6fe8_;
    unsigned char unknown_6fe9_[3];
    Vector3i offset;
    unsigned char unknown_6ff8_;
    unsigned char unknown_6ff9_;
    unsigned char unknown_6ffa_[0x74a];
    unsigned char slots[3];
};
struct Struct_ov025_021dbe10 { unsigned char padding0[0xc]; int fieldc; };
extern "C" Struct_ov025_021dbe10 _ZZ21inline_ov025_021dcf14vE1s;
extern char data_ov025_021ef40c[];
extern char data_ov025_021ef424[];
extern char data_ov025_021ef43c[];
extern int data_ov025_021ef404;
extern "C" void VramState_Rewind(Foo0207df50*);
extern "C" void func_ov025_021dee20(Struct_ov025_021dbe10_4*);
extern "C" Struct_ov000_0215440c_2* func_ov000_02160f20(void*);
extern "C" Struct_ov025_021dbe10_2* func_ov000_02160094(Struct_ov000_0215440c_2*, int);
extern "C" void func_ov025_021dc0d8(void*);
extern "C" void* func_02048ab4(void*, int);
extern "C" void* func_ov025_021dfa9c(Struct_ov025_021dbe10_4*, char*);
extern "C" int func_ov000_0215fc60(char*);
extern "C" void* func_ov000_02169a58(void*, int);
extern "C" void func_ov025_021e88d8(void*);
extern "C" void func_ov025_021e8a40(char*, int, int);
extern "C" void func_ov025_021e8a4c(char*, int);
extern "C" void func_ov025_021e8d20(char*, void*);
extern "C" void func_ov025_021db8d8(Struct_ov025_021dbe10_4*);
extern "C" Struct_ov025_021dbe10_3* func_02079e2c(char*, int);
extern "C" void func_ov025_021d8a40(void*, Struct_ov025_021d8a40*);
extern "C" void func_ov025_021def30(unsigned char*);
static inline int inline_ov000_02156cc4_2(unsigned int id) { return id <= 3; }

// USA: func_ov025_021dbe10
extern "C" ARM void func_ov025_021dbe10(Struct_ov025_021dbe10_4* state) {
    GameState* game = GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    char* battle = state->battle;
    state->allocator.Reset();
    VramState_Rewind((Foo0207df50*)state->tables);
    func_ov025_021dee20(state);
    Struct_ov000_0215440c_2* list = func_ov000_02160f20(state);
    if (!list) return;
    Struct_ov025_021dbe10_2* source = func_ov000_02160094(list, 0);
    if (!source) return;
    state->state = 0;
    state->unknown_6e4e_ = 0;
    state->unknown_6efc_ = -1;
    state->pending = 0;
    state->source = -1;
    state->unknown_6fd8_ = 0;
    state->unknown_6fb8_ = -1;
    state->unknown_6f01_ = 0;
    state->unknown_6fd4_ = 0;
    Vector3i zero = {};
    state->position = zero;
    state->unknown_6fe8_ = 0;
    state->offset = zero;
    state->unknown_6ff8_ = 0;
    state->unknown_6ff9_ = 0;
    state->slots[0] = 0xff;
    state->slots[1] = 0xff;
    state->slots[2] = 0xff;
    state->flags &= ~4;
    _ZZ21inline_ov025_021dcf14vE1s.fieldc = 0;
    func_ov025_021dc0d8(state);
    int reset = 1;
    GameObject* object = game->GetCombatantByIndex(source->id);
    if (object) {
        int kind = list->kind;
        if (kind == 0x3ae) reset = 0;
        void* script = func_02048ab4(object, kind);
        void* var10 = func_ov025_021dfa9c(state, state->battle);
        if (var10) script = var10;
        if (func_ov000_0215fc60(battle) && source->id == 0)
            script = func_ov000_02169a58(state->unknown_5724_, 0xdd);
        if (script) {
            func_ov025_021e88d8(state->script);
            func_ov025_021e8a40(state->script, (int)&state->allocator, (int)state->tables);
            func_ov025_021e8a4c(state->script, (int)state->battle);
            func_ov025_021e8d20(state->script, script);
            func_ov025_021db8d8(state);
        } else {
            Struct_ov025_021dbe10_3* var11 = func_02079e2c((char*)func_020797dc(), (short)kind);
            if (var11) {
                if (var11->category == 0x22) func_ov025_021d8a40(state, (Struct_ov025_021d8a40*)list);
                else {
                    char path[0x50];
                    if (var11->kind == 2) sprintf(path, data_ov025_021ef40c);
                    else if ((var11->kind == 1 || var11->kind == 4) && inline_ov000_02156cc4_2(source->id))
                        sprintf(path, data_ov025_021ef424);
                    else sprintf(path, data_ov025_021ef43c);
                    data_ov025_021ef404 = loader->QueueLoadFile(path, 0);
                    state->phase = 4;
                }
            }
        }
    }
    if (reset) state->unknown_6fd5_ = 0;
    if (state->phase == 1) func_ov025_021def30((unsigned char*)state);
}
