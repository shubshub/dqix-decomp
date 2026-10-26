#include <globaldefs.h>
#if defined(jpn)
enum { Enum_020a8b0c_14076 = 0x34ec };
#else
enum { Enum_020a8b0c_14076 = 0x36fc };
#endif
#include <GameState/GameState.h>
#include <std_library_functions.h>
#include "Resource/GameResources.h"
struct Struct_020a8b0c { char pad[4]; unsigned char mask; char pad2[3]; int progress, step, limit; signed char count; };
struct Struct_020a8b0c_2 { Object3D obj; short height, y; };
struct Field020a8b0c { char pad[0xc]; unsigned char flag; };
struct HeadNode02046b24;
struct Party020874bc;
struct Struct_020a8b0c_4 { char pad[Enum_020a8b0c_14076]; HeadNode02046b24** head; };
struct Obj020397cc;
struct Obj02033874;
extern "C" Field020a8b0c* GameState_GetZoneTransition(GameState*);
extern "C" void GameObject_DisableControl(Obj020397cc*, int);
extern "C" int FieldTaskQueue_GetCurrentKind(HeadNode02046b24**);
extern "C" void SePlayer_UnloadExtraArchiveA(void*);
extern "C" void SePlayer_LoadExtraArchiveA(void*, int, int);
extern "C" void func_0205eb90(void*, int, int);
extern "C" void GameObject_SnapFacing(Obj02033874*, int);
extern "C" void func_020874bc(Party020874bc*, int);
int fix32abs(int);
extern char g_sePlayer;
// USA: func_020a8b0c
extern "C" ARM void func_020a8b0c(Struct_020a8b0c* self, int index) {
    if (!(self->mask & (1<<index))) return;
    GameState* state = GameState::GetInstance();
    Struct_020a8b0c_2* actor = (Struct_020a8b0c_2*)state->GetPartyMemberByIndex(index);
    Field020a8b0c* field = GameState_GetZoneTransition(state);
    Party020874bc* party;
    HeadNode02046b24** head = ((Struct_020a8b0c_4*)GetGameResources())->head;
    party = (Party020874bc*)GameState_GetParty(state);
    int height = actor->height;
    field->flag = 0;
    GameObject_DisableControl((Obj020397cc*)actor, 1);
    self->progress+=self->step;
    if (self->limit < self->progress) self->progress = self->limit;
    int difference;
    if (FieldTaskQueue_GetCurrentKind(head) == 3) { difference = -3686; actor->obj.DisableFlag(0x8000100); }
    else {
        difference = height-self->progress;
        if (fix32abs(difference) < 40) {
            SePlayer_UnloadExtraArchiveA(&g_sePlayer);
            SePlayer_LoadExtraArchiveA(&g_sePlayer, 114, 114);
            func_0205eb90(&g_sePlayer, 3, 0);
        }
    }
    actor->height = difference;
    if (difference < 0) {
        int y = actor->y;
        GameObject_SnapFacing((Obj02033874*)actor, y+labs(difference));
        func_020874bc(party, self->count);
        int count = self->count;
        if (count > 0) count--;
        self->count = count;
    }
}
