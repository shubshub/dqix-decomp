#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

struct Struct_ov025_021e4450;
struct Struct_ov000_0215440c_2;
struct Struct_ov000_0215440c;
struct Struct_02033834;

struct Struct_ov025_021eb7fc {
    char unknown_0_[0x1c4];
    unsigned int unknown_1c4_;
};

struct Struct_ov025_021eb7fc_2 {
    char unknown_0_[0x278];
    unsigned char unknown_278_;
    char unknown_279_[3];
    void* unknown_27c_;
};

struct Struct_ov025_021eb7fc_3 {
    char unknown_0_[0xae];
    short unknown_ae_;
};

struct Struct_ov025_021eb7fc_4 {
    char unknown_0_[0x20];
    unsigned short unknown_20_;
};

struct Struct_ov025_021eb7fc_5 {
    char unknown_0_[0xe];
    short unknown_e_;
};

void* GetActiveCombatWork_ov000_02160130(void);
extern "C" struct Field021eb7fc* func_ov000_02160f14(void* work);
void* GetSlotPtr02160f20(void* obj);
void SetFlagField_021eb00c_021eb00c(struct Obj021eb00c* obj);
void ClearFlagIfParityMismatch02163710_02163710(void* obj, int flag);
extern "C" void func_ov025_021eb8e8(struct Ctx021eb7fc* ctx);
struct Leader021eb7fc* GetNodeAtIndex02160094(struct List02160094* list, int index);
struct Target021eb7fc* GetNodeAtIndex021600f8(struct List021600f8* list, int index);
extern "C" void GameObject_FaceGameObject(struct Actor021eb7fc* obj, int id, int flag);
void GameObject_SnapFacing(struct Obj02033874* obj, int arg);

// USA: func_ov025_021eb7fc
extern "C" ARM void func_ov025_021eb7fc(struct Ctx021eb7fc* ctx) {
    GameState* gs = GameState::GetInstance();
    GameResources* res = GetGameResources();
    void* work = GetActiveCombatWork_ov000_02160130();
    struct Field021eb7fc* field = func_ov000_02160f14(work);
    field->slot = GetSlotPtr02160f20(work);
    SetFlagField_021eb00c_021eb00c((struct Obj021eb00c*)ctx);
    ClearFlagIfParityMismatch02163710_02163710(work, 0);
    func_ov025_021eb8e8(ctx);
    if (!(ctx->flags & 0x20)) {
        ClearFlags04((GameResources*)res, 0x400);
        if (ctx->flags & 0x80) {
            void* list = GetSlotPtr02160f20(work);
            struct Leader021eb7fc* leader = GetNodeAtIndex02160094((struct List02160094*)list, 0);
            struct Target021eb7fc* target = GetNodeAtIndex021600f8((struct List021600f8*)list, 0);
            if (leader != 0 && target != 0) {
                struct Actor021eb7fc* actor = (Actor021eb7fc*)gs->GetCombatantByIndex(leader->id);
                if (actor != 0) {
                    GameObject_FaceGameObject(actor, target->id, 0);
                    GameObject_SnapFacing((struct Obj02033874*)actor, actor->facing);
                }
            }
        }
        var3->unknown_278_ = 1;
    }
    arg0->unknown_1c4_ |= 0x20;
}
