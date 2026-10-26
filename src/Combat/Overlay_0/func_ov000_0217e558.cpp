#include <globaldefs.h>
#include "Sound/SePlayer.h"
#include "Resource/ActionDataTables.h"
#include "GameState/GameState.h"

struct Struct_0205c570 { unsigned char data[0x7cc]; };
struct Struct_0205def8 { unsigned char data[0x7cc]; };
struct Struct_0205d81c { unsigned char data[0x7cc]; };
struct Struct0217f8c0;
#if defined(jpn)
struct Struct_ov000_0217e558_2 { unsigned char padding[0x7902]; signed char selected; };
#else
struct Struct_ov000_0217e558_2 { unsigned char padding[0x7712]; signed char selected; };
#endif
struct PartyEffectsE558 { unsigned char padding[0xf78]; signed char members[4]; unsigned char count; };
struct Struct_ov000_0217e558_4 { int field0; unsigned int value : 12; unsigned int unknown_5_4_ : 20; unsigned int flags; };
struct ActorE558 {
    unsigned char padding[0x10];
    signed char actions[8];
    signed char unknown_18_;
    unsigned char unknown_19_[4];
    signed char target;
    unsigned char unknown_1e_[8];
    unsigned short value;
    unsigned char padding28[6];
    signed char unknown_2e_;
    signed char inline_ov000_0217e558() const { return target; }
    signed char inline_ov000_0217e558_2() const { return unknown_2e_; }
    int inline_ov000_0217e558_3(int value) { return target = value; }
    int inline_ov000_0217e558_4(int value) { return unknown_2e_ = value; }
};
struct Struct_ov000_0217e558 {
    unsigned char padding[0x10];
    union {
        short keys[8];
        struct { unsigned char unknown1_10_[0xc]; unsigned char field1c; };
    };
    unsigned char unknown_20_[0x188 - 0x20];
    union { Struct_0205c570 sums; Struct_0205def8 flags; Struct_0205d81c fields; } list;
    unsigned char unknown_954_[2];
    unsigned char unknown_956_;
#if defined(jpn)
    unsigned char unknown_957_[0x1f98 - 0x957];
#else
    unsigned char unknown1_957_[0x1d60 - 0x957];
#endif
    signed char actions[8];
    signed char unknown_1d68_;
    unsigned char unknown_1d69_[4];
    signed char selected;
    unsigned char unknown_1d6e_[4];
    unsigned short flags;
    unsigned char unknown_1d74_[5];
    unsigned char unknown_1d79_;
};
extern "C" int Window_GetSelectedIndex(Struct_0205c570*);
extern "C" void func_0205def8(Struct_0205def8*, int, int);
extern "C" void Window_SetPanePalette(Struct_0205d81c*, int, int);
extern "C" Struct_ov000_0217e558_2* func_ov017_021b8468(void*);
extern "C" int func_ov000_0217c594(Struct_ov000_0217e558*, int);
extern "C" void SePlayer_Play(SePlayer*, int, int);
extern "C" ActorE558* func_ov000_02161318(Struct_ov000_0217e558*, int);
extern "C" void func_ov000_02170db0(ActorE558*);

extern "C" Struct_ov000_0217e558_4* func_02079e2c(char*, int);
extern "C" void func_ov000_02175b54(Struct_ov000_0217e558*);
extern "C" int GameState_GetProtagonistIndex(GameState*);
extern "C" void func_ov000_02176e3c(Struct_ov000_0217e558*, int, int, int, int, int);
extern "C" int func_ov000_0217f8c0(Struct0217f8c0*);
extern "C" void func_ov000_02176634(Struct_ov000_0217e558*, int, int, int, int);
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
extern "C" ARM void func_ov000_0217e558(Struct_ov000_0217e558* battle, int arg1, int arg2) {
    battle->flags |= 0x100;
    battle->selected = Window_GetSelectedIndex(&battle->list.sums);
    func_0205def8(&battle->list.flags, 1, 0x18);
    Window_SetPanePalette(&battle->list.fields, 0x18, 0);
    GameState* game = GameState::GetInstance();
    GameResources* data = game->GetResources();
    if (func_ov017_021b8468(PTR3718(data))->selected != -1 || !func_ov000_0217c594(battle, 5)) return;
    battle->unknown_956_ = 0;
    SePlayer_Play(&g_sePlayer, 1, 0);
    if ((unsigned short)battle->keys[battle->selected] == 0) {
        battle->unknown_1d68_++;
        battle->actions[battle->unknown_1d68_] = 100;
        PartyEffectsE558* party = (PartyEffectsE558*)GameState_GetParty(game);
        unsigned char count = party->count;
        for (unsigned char i = 0; i < count; i++) {
            ActorE558* actor = func_ov000_02161318(battle, party->members[i]);
            if (actor) {
                actor->inline_ov000_0217e558_3(actor->inline_ov000_0217e558());
                actor->value = 0;
                actor->inline_ov000_0217e558_4(actor->inline_ov000_0217e558_2());
                actor->actions[actor->unknown_18_] = 100;
                func_ov000_02170db0(actor);
            }
        }
    } else {
        ActionDataTables* tables = func_020797dc();
        if (!tables) return;
        Struct_ov000_0217e558_4* entry = func_02079e2c((char*)tables, battle->keys[battle->selected]);
        if (!entry) return;
        func_ov000_02175b54(battle);
        GameState* game = GameState::GetInstance();
        PartyEffectsE558* party = (PartyEffectsE558*)GameState_GetParty(game);
        ActorE558* current = func_ov000_02161318(battle, GameState_GetProtagonistIndex(game));
        if (!current) return;
        switch (battle->actions[battle->unknown_1d68_]) {
        case 14: battle->actions[battle->unknown_1d68_] = 25; battle->unknown_1d79_ = 0; break;
        case 18:
        case 19: battle->actions[battle->unknown_1d68_] = 100; break;
        }
        signed char target = -1;
        int alternate = target;
        unsigned int kind = (entry->flags << 22) >> 30;
        if (kind == 1) target = current->target;
        if (kind == 2) alternate = current->unknown_2e_;
        unsigned char count = party->count;
        for (unsigned char i = 0; i < count; i++) {
            ActorE558* actor = func_ov000_02161318(battle, party->members[i]);
            if (actor) {
                actor->target = target;
                actor->value = entry->value;
                actor->unknown_2e_ = alternate;
                actor->actions[actor->unknown_18_] = battle->actions[battle->unknown_1d68_];
                func_ov000_02170db0(actor);
            }
        }
    }
    if (battle->actions[battle->unknown_1d68_] != 25) return;
    func_ov000_02176e3c(battle, 0, 23, G02184294(1), G02184294(0), 1);
    battle->field1c = 0;
    int match = func_ov000_0217f8c0((Struct0217f8c0*)battle);
    func_ov000_02176634(battle, match, 25, arg1, arg2);
}
