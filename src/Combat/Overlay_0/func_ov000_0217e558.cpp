#include <globaldefs.h>
#include "Resource/ActionDataTables.h"
#include "GameState/GameState.h"

struct Struct_0205c570 { unsigned char data[0x7cc]; };
struct Struct_0205def8 { unsigned char data[0x7cc]; };
struct Struct_0205d81c { unsigned char data[0x7cc]; };
struct Struct0217f8c0;
struct SePlayer { unsigned char data[0xd0]; };
#if defined(jpn)
struct Struct_ov000_0217e558_2 { unsigned char unknown_0_[0x7902]; signed char unknown_7712_; };
#else
struct Struct_ov000_0217e558_2 { unsigned char unknown_0_[0x7712]; signed char unknown_7712_; };
#endif
struct Struct_ov000_0217e558_3 { unsigned char unknown_0_[0xf78]; signed char unknown_f78_[4]; unsigned char unknown_f7c_; };
struct Struct_ov000_0217e558_4 { int unknown_0_; unsigned int unknown_4_0_ : 12; unsigned int unknown_5_4_ : 20; unsigned int unknown_8_; };
struct Struct_ov000_0217e558_5 {
    unsigned char unknown_0_[0x10];
    signed char unknown_10_[8];
    signed char unknown_18_;
    unsigned char unknown_19_[4];
    signed char unknown_1d_;
    unsigned char unknown_1e_[8];
    unsigned short unknown_26_;
    unsigned char unknown_28_[6];
    signed char unknown_2e_;
    signed char inline_ov000_0217e558() const { return unknown_1d_; }
    signed char inline_ov000_0217e558_2() const { return unknown_2e_; }
    int inline_ov000_0217e558_3(int arg0) { return unknown_1d_ = arg0; }
    int inline_ov000_0217e558_4(int arg0) { return unknown_2e_ = arg0; }
};
struct Struct_ov000_0217e558 {
    unsigned char unknown_0_[0x10];
    union {
        short unknown_10_[8];
        struct { unsigned char unknown1_10_[0xc]; unsigned char unknown_1c_; };
    };
    unsigned char unknown_20_[0x188 - 0x20];
    union { Struct_0205c570 unknown_0_; Struct_0205def8 unknown1_0_; Struct_0205d81c unknown2_0_; } unknown_188_;
    unsigned char unknown_954_[2];
    unsigned char unknown_956_;
#if defined(jpn)
    unsigned char unknown_957_[0x1f98 - 0x957];
#else
    unsigned char unknown1_957_[0x1d60 - 0x957];
#endif
    signed char unknown_1d60_[8];
    signed char unknown_1d68_;
    unsigned char unknown_1d69_[4];
    signed char unknown_1d6d_;
    unsigned char unknown_1d6e_[4];
    unsigned short unknown_1d72_;
    unsigned char unknown_1d74_[5];
    unsigned char unknown_1d79_;
};
int Window_GetSelectedIndex(Struct_0205c570*);
void SetElementFlag0x20ByKey0205def8(Struct_0205def8*, int, int);
void SetElementFieldC2_0205deb4(Struct_0205d81c*, int, int);
extern "C" ResourceE558* func_ov017_021b8468(void*);
extern "C" int func_ov000_0217c594(BattleE558*, int);
void SePlayer_Play(SePlayer*, int, int);
extern "C" ActorE558* func_ov000_02161318(BattleE558*, int);
extern "C" void func_ov000_02170db0(ActorE558*);

ActionRecordE558* SearchBothTables02079e2c(char*, int);
extern "C" void func_ov000_02175b54(BattleE558*);
int GetField0x3acValue_020100a8(GameState*);
extern "C" void func_ov000_02176e3c(BattleE558*, int, int, int, int, int);
int FindMatchingTableEntry0217f8c0(Struct0217f8c0*);
extern "C" void func_ov000_02176634(BattleE558*, int, int, int, int);
extern SePlayer g_sePlayer;
extern int data_ov000_02184294[3];
#if defined(jpn)
#define G02184294(i) data_ov000_02184294[(i) + 1]
#define PTR3718(d) (*(void**)((char*)(d) + 0x3508))
#else
#define G02184294(i) data_ov000_02184294[i]
#define PTR3718(d) ((d)->unknown_ptr_3718)
#endif

// USA: func_ov000_0217e558
extern "C" ARM void func_ov000_0217e558(BattleE558* battle, int arg1, int arg2) {
    battle->flags |= 0x100;
    battle->selected = Window_GetSelectedIndex(&battle->list.sums);
    SetElementFlag0x20ByKey0205def8(&battle->list.flags, 1, 0x18);
    SetElementFieldC2_0205deb4(&battle->list.fields, 0x18, 0);
    GameState* game = GameState::GetInstance();
    GameResources* data = game->GetResources();
    if (func_ov017_021b8468(PTR3718(data))->selected != -1 || !func_ov000_0217c594(battle, 5)) return;
    battle->field956 = 0;
    SePlayer_Play(&g_sePlayer, 1, 0);
    if ((unsigned short)battle->keys[battle->selected] == 0) {
        battle->actionIndex++;
        battle->actions[battle->actionIndex] = 100;
        PartyEffectsE558* party = (PartyEffectsE558*)GetPtrField0x2a04_02010828(game);
        unsigned char count = party->count;
        for (unsigned char i = 0; i < count; i++) {
            ActorE558* actor = func_ov000_02161318(battle, party->members[i]);
            if (actor) {
                actor->SetTarget(actor->GetTarget());
                actor->value = 0;
                actor->SetAlternateTarget(actor->GetAlternateTarget());
                actor->actions[actor->actionIndex] = 100;
                func_ov000_02170db0(actor);
            }
        }
    } else {
        Struct_02108e10* var6 = func_020797dc();
        if (!var6) return;
        Struct_ov000_0217e558_4* var7 = func_02079e2c((char*)var6, arg0->unknown_10_[arg0->unknown_1d6d_]);
        if (!var7) return;
        func_ov000_02175b54(arg0);
        GameState* var8 = GameState::GetInstance();
        Struct_ov000_0217e558_3* var9 = (Struct_ov000_0217e558_3*)func_02010828(var8);
        Struct_ov000_0217e558_5* var10 = func_ov000_02161318(arg0, func_020100a8(var8));
        if (!var10) return;
        switch (arg0->unknown_1d60_[arg0->unknown_1d68_]) {
        case 14: arg0->unknown_1d60_[arg0->unknown_1d68_] = 25; arg0->unknown_1d79_ = 0; break;
        case 18:
        case 19: arg0->unknown_1d60_[arg0->unknown_1d68_] = 100; break;
        }
        signed char var11 = -1;
        int var12 = var11;
        unsigned int var13 = (var7->unknown_8_ << 22) >> 30;
        if (var13 == 1) var11 = var10->unknown_1d_;
        if (var13 == 2) var12 = var10->unknown_2e_;
        unsigned char var14 = var9->unknown_f7c_;
        for (unsigned char var15 = 0; var15 < var14; var15++) {
            Struct_ov000_0217e558_5* var16 = func_ov000_02161318(arg0, var9->unknown_f78_[var15]);
            if (var16) {
                var16->unknown_1d_ = var11;
                var16->unknown_26_ = var7->unknown_4_0_;
                var16->unknown_2e_ = var12;
                var16->unknown_10_[var16->unknown_18_] = arg0->unknown_1d60_[arg0->unknown_1d68_];
                func_ov000_02170db0(var16);
            }
        }
    }
    if (arg0->unknown_1d60_[arg0->unknown_1d68_] != 25) return;
    func_ov000_02176e3c(arg0, 0, 23, G02184294(1), G02184294(0), 1);
    arg0->unknown_1c_ = 0;
    int var17 = func_ov000_0217f8c0((Struct_ov000_021735d0_3*)arg0);
    func_ov000_02176634(arg0, var17, 25, arg1, arg2);
}
