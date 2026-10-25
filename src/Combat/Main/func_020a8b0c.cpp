#include <globaldefs.h>
#if defined(jpn)
enum { Enum_020a8b0c_14076 = 0x34ec };
#else
enum { Enum_020a8b0c_14076 = 0x36fc };
#endif
#include <GameState/GameState.h>
#include <std_library_functions.h>
#include "Resource/GameResources.h"
struct Obj020a8b0c { char pad[4]; unsigned char mask; char pad2[3]; int progress, step, limit; signed char count; };
struct Actor020a8b0c { Object3D obj; short height, y; };
struct Field020a8b0c { char pad[0xc]; unsigned char flag; };
struct HeadNode02046b24;
struct Party020874bc;
struct Manager020a8b0c { char pad[kManagerPrefix]; HeadNode02046b24** head; };
struct Obj020397cc;
struct Obj02033874;
Field020a8b0c* GetField0x3f8Address_0200fd0c(GameState*);
void GameObject_DisableControl(Obj020397cc*, int);
int GetHeadNodeIdOrMinusOne(HeadNode02046b24**);
void SePlayer_UnloadExtraArchiveA(void*);
void SePlayer_LoadExtraArchiveA(void*, int, int);
void DispatchIfField0xc4NonNeg_0205eb90(void*, int, int);
void SetVecYFromValue02033874(Obj02033874*, int);
void ApplyToListedCombatants020874bc(Party020874bc*, int);
int fix32abs(int);
extern char g_sePlayer;
// USA: func_020a8b0c
extern "C" ARM void func_020a8b0c(Obj020a8b0c* self, int index) {
    if (!(self->mask & (1<<index))) return;
    GameState* state = GameState::GetInstance();
    Actor020a8b0c* actor = (Actor020a8b0c*)state->GetPartyMemberByIndex(index);
    Field020a8b0c* field = GetField0x3f8Address_0200fd0c(state);
    Party020874bc* party;
    HeadNode02046b24** head = ((Manager020a8b0c*)GetGameResources())->head;
    party = (Party020874bc*)GameState_GetParty(state);
    int height = actor->height;
    field->flag = 0;
    GameObject_DisableControl((Obj020397cc*)actor, 1);
    self->progress+=self->step;
    if (self->limit < self->progress) self->progress = self->limit;
    int difference;
    if (GetHeadNodeIdOrMinusOne(head) == 3) { difference = -3686; actor->obj.DisableFlag(0x8000100); }
    else {
        difference = height-self->progress;
        if (fix32abs(difference) < 40) {
            SePlayer_UnloadExtraArchiveA(&g_sePlayer);
            SePlayer_LoadExtraArchiveA(&g_sePlayer, 114, 114);
            DispatchIfField0xc4NonNeg_0205eb90(&g_sePlayer, 3, 0);
        }
    }
    var1->unknown_ac_ = var6;
    if (var6 < 0) {
        int var7 = var1->unknown_ae_;
        func_02033874((Struct_02033834*)var1, var7+labs(var6));
        func_020874bc(var3, arg0->unknown_14_);
        int var8 = arg0->unknown_14_;
        if (var8 > 0) var8--;
        arg0->unknown_14_ = var8;
    }
}
