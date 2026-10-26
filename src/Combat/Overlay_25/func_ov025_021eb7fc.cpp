#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

struct Struct_ov025_021e4450;
struct Struct_ov000_0215440c_2;
struct Struct_ov000_0215440c;
struct Obj02033874;

struct Struct_ov025_021eb7fc {
    char pad0[0x1c4];
    unsigned int flags;
};

struct Struct_ov025_021eb7fc_2 {
    char pad0[0x278];
    unsigned char unknown_278_;
    char unknown_279_[3];
    void* slot;
};

struct Actor021eb7fc {
    char pad0[0xae];
    short facing;
};

struct Struct_ov025_021eb7fc_4 {
    char pad0[0x20];
    unsigned short id;
};

struct Struct_ov025_021eb7fc_5 {
    char pad0[0xe];
    short id;
};

extern "C" void* func_ov000_02160130(void);
extern "C" struct Struct_ov025_021eb7fc_2* func_ov000_02160f14(void* work);
extern "C" void* func_ov000_02160f20(void* obj);
extern "C" void func_ov025_021eb00c(struct Struct_ov025_021e4450* obj);
extern "C" void func_ov000_02163710(void* obj, int flag);
extern "C" void func_ov025_021eb8e8(struct Struct_ov025_021eb7fc* ctx);
extern "C" struct Struct_ov025_021eb7fc_4* func_ov000_02160094(struct Struct_ov000_0215440c_2* list, int index);
extern "C" struct Struct_ov025_021eb7fc_5* func_ov000_021600f8(struct Struct_ov000_0215440c* list, int index);
extern "C" void GameObject_FaceGameObject(struct Actor021eb7fc* obj, int id, int flag);
extern "C" void GameObject_SnapFacing(struct Obj02033874* obj, int arg);

// USA: func_ov025_021eb7fc
extern "C" ARM void func_ov025_021eb7fc(struct Struct_ov025_021eb7fc* ctx) {
    GameState* gs = GameState::GetInstance();
    GameResources* res = GetGameResources();
    void* work = func_ov000_02160130();
    struct Struct_ov025_021eb7fc_2* field = func_ov000_02160f14(work);
    field->slot = func_ov000_02160f20(work);
    func_ov025_021eb00c((struct Struct_ov025_021e4450*)ctx);
    func_ov000_02163710(work, 0);
    func_ov025_021eb8e8(ctx);
    if (!(ctx->flags & 0x20)) {
        ClearFlags04((GameResources*)res, 0x400);
        if (ctx->flags & 0x80) {
            void* list = func_ov000_02160f20(work);
            struct Struct_ov025_021eb7fc_4* leader = func_ov000_02160094((struct Struct_ov000_0215440c_2*)list, 0);
            struct Struct_ov025_021eb7fc_5* target = func_ov000_021600f8((struct Struct_ov000_0215440c*)list, 0);
            if (leader != 0 && target != 0) {
                struct Actor021eb7fc* actor = (Actor021eb7fc*)gs->GetCombatantByIndex(leader->id);
                if (actor != 0) {
                    GameObject_FaceGameObject(actor, target->id, 0);
                    GameObject_SnapFacing((struct Obj02033874*)actor, actor->facing);
                }
            }
        }
        field->unknown_278_ = 1;
    }
    ctx->flags |= 0x20;
}
