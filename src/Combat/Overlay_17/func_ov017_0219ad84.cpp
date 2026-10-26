#include <globaldefs.h>
#include "GameState/GameState.h"
#include "GameState/Field3b0.h"
#include "Resource/GameResources.h"
#include "NitroSDK/Graphics.h"
#include "World/ZoneLootableRecord.h"
#include "Resource/Brightness.h"

struct Struct_02015438;
struct Struct_0201730c;
struct Struct_02015ef4_2;
struct Struct_0203402c;
struct Struct_0203a46c;
struct Struct_02017098_3;
struct Struct_0202c1a4;
struct Struct_02015ef4;

struct Struct_ov017_0219ad84 { unsigned short unknown_0_; };
struct Struct_ov017_0219ad84_2 {
#if defined(jpn)
    char unknown_0_[0x868];
#else
    char unknown1_0_[0x998];
#endif
    unsigned int unknown_998_;
};
struct Struct_ov017_0219ad84_3 { char unknown_0_[2]; unsigned char unknown_2_; };
struct Struct_ov017_0219ad84_4 {
    Object3D unknown_0_;
#if defined(jpn)
    char unknown_ac_[0x1a6 - 0xac];
#else
    char unknown1_ac_[0x1b2 - 0xac];
#endif
    unsigned short unknown_1b2_;
};

extern "C" Zone0219ad84* Zone3D_GetInstance();
Controller0219ad84* MessageSystem_GetInstance();
int FieldTaskQueue_GetCurrentKind(HeadNode02046b24**);
void AdvanceStreamRecord0204724c(Obj0204724C*);
void RenderFlaggedIndexedEntry(StructAt020473c8*, int);
unsigned char GameObject_IsClimbingLadder(char*);
int GameObject_IsSinking(BitField0203402c*);
void SprSprite_SetPosition(Vec3Target0203a46c*, int, int, int);
void RecomputeField0x7c(Struct020478bc*, int);
extern "C" void SprSprite_DrawGroup(Foo02048004*, int, int);
int GameObject_IsGesturing(signed char*);
int FieldTaskQueue_IsEmpty(void**);
extern "C" SearchStruct0202c1a4* LinkSession_GetInstance();
int LinkSession_IsActive(int*);
int LinkSession_GetOwnSlot(SearchStruct0202c1a4*);
void* GameState_GetZoneTransition(GameState*);
void Camera_WorldToScreen(void*, Vec3copy0202ec84*, int*, int*);
int HasFlagBit_0218d4ec(void*, int);

static inline Struct_02012fa4* inline_ov017_0219ad84(GameResources* arg0) {
    return *(Struct_02012fa4**)&arg0->unknown_35a8[0x88];
}
static inline unsigned char inline_ov017_0219ad84_2(void* arg0) {
    return ((Struct_ov017_0219ad84_3*)arg0)->unknown_2_;
}

// USA: func_ov017_0219ad84
// JPN: func_ov017_0219b924
extern "C" ARM void func_ov017_0219ad84(GameResources* self) {
    if (TestFlags04(self, 0x40)) return;
    GameState* game = GameState::GetInstance();
    Zone0219ad84* zone = Zone3D_GetInstance();
    void* camera = game->GetCamera();
    Controller0219ad84* controller = MessageSystem_GetInstance();
    Window0219ad84* field = (Window0219ad84*)GameState_GetZoneTransition(game);
    GameObject* actor = game->GetLeader();
    if (!actor) return;

    if (FieldTaskQueue_GetCurrentKind((HeadNode02046b24**)self->fieldTaskQueue_) == 4) {
        if (CurrentSprite(self) == NULL || !CurrentSprite(self)->bit0) return;
        GXFIFO_MATRIX_PUSH = 0;
        if (inline_ov017_0219ad84(arg0) != &arg0->substruct_array_2b90[12] &&
            inline_ov017_0219ad84(arg0) != &arg0->substruct_array_2b90[13] &&
            inline_ov017_0219ad84(arg0) != &arg0->substruct_array_2b90[14]) {
            func_0204724c((Struct_0201730c*)inline_ov017_0219ad84(arg0));
            func_020473c8((Struct_02015ef4_2*)inline_ov017_0219ad84(arg0), 1);
        } else {
            func_020473c8((Struct_02015ef4_2*)inline_ov017_0219ad84(arg0), 1);
        }
        GXFIFO_MATRIX_POP = 1;
        return;
    }

    int idle = 1;
    unsigned int busy = 0;
    if (controller) busy |= controller->busy;
    busy |= WindowOpen(self->unknown_ptr_array_3700[4]);
    busy |= WindowOpen(self->fieldTasks_[10]);
    busy |= WindowOpen(self->unknown_ptr_array_371c[1]);
    busy |= WindowOpen(self->fieldTasks_[20]);
    busy |= WindowOpen(self->fieldTasks_[1]);
    busy |= WindowOpen(self->fieldTasks_[16]);
    busy |= WindowOpen(self->fieldTasks_[7]);
    busy |= WindowOpen(self->fieldTasks_[11]);
    busy |= WindowOpen(self->fieldTasks_[27]);
    busy |= WindowOpen(self->fieldTasks_[4]);
    busy |= WindowOpen(self->fieldTasks_[47]);
    busy |= WindowOpen(self->fieldTasks_[9]);
    busy |= WindowOpen(self->fieldTasks_[6]);
    busy |= WindowOpen(self->fieldTasks_[42]);
    busy |= WindowOpen(self->fieldTasks_[29]);
    busy |= WindowOpen(self->fieldTasks_[30]);
    busy |= WindowOpen(self->fieldTasks_[21]);
    busy |= WindowOpen(self->fieldTasks_[43]);
    busy |= GameObject_IsClimbingLadder((char*)actor);
    int check = GameObject_IsSinking((BitField0203402c*)actor);
    if (busy | check | WindowOpen(field)) idle = 0;
    if (idle) {
        SprSprite_SetPosition((Vec3Target0203a46c*)&self->substruct_array_2b90[0], self->fieldButtonX[0] << 12, self->fieldButtonY[0] << 12, -0x1000);
        RecomputeField0x7c((Struct020478bc*)&self->substruct_array_2b90[0], 1);
        GXFIFO_MATRIX_PUSH = 0;
        SprSprite_DrawGroup(&self->substruct_array_2b90[0], 0, 1);
        GXFIFO_MATRIX_POP = 1;
    }

    if (self->interactionSelection.spriteIndex != 0x12 && !GameObject_IsGesturing((signed char*)actor) &&
        FieldTaskQueue_IsEmpty((void**)self->fieldTaskQueue_)) {
        int show = 1;
        if (TestFlags04(self, 8) && self->interactionSelection.kind == 0) show = 0;
        if (self->interactionSelection.spriteIndex == 0x11) show = 0;
        if (show) {
            int selection = self->interactionSelection.spriteIndex;
            Foo02048004* sprites = self->substruct_array_2b90;
            GXFIFO_MATRIX_PUSH = 0;
            func_0204724c((Struct_0201730c*)&var11[var10]);
            func_020473c8((Struct_02015ef4_2*)&var11[var10], 1);
            GXFIFO_MATRIX_POP = 1;
        }
    }

    SearchStruct0202c1a4* search = LinkSession_GetInstance();
    if (!LinkSession_IsActive((int*)search) || !camera) return;
    if (GameObject_IsGesturing((signed char*)actor)) return;
    int current = LinkSession_GetOwnSlot(search);
    int drawn = 0;
    for (int i = 0; i < 4; i++) {
        if (i == current) continue;
        Combatant0219ad84* member = (Combatant0219ad84*)GetCombatantWithFlag0x100_0200ff1c(game, i);
        if (!member) continue;
        if (!member->obj3D.IsVisible()) continue;
        if (!member->obj3D.GetInheritedAlpha()) continue;
        int marked = 0;
        if (member->obj3D.GetFlag(0x800000) && member->obj3D.GetFlag(0x400)) marked = 1;
        unsigned short id = zone->id;
        unsigned short field06 = member->obj3D.GetField06();
        if (field06 != id && !marked) continue;
        Vector3fix position = member->obj3D.position_;
        position.y += member->obj3D.GetHeight();
        int x, y;
        Camera_WorldToScreen(camera, (Vec3copy0202ec84*)&position, &x, &y);
        x -= 12;
        y -= 24;
        if (member->obj3D.GetFlag(0x400)) {
            Foo02048004* marker = &self->unknown_3520;
            SprSprite_SetPosition((Vec3Target0203a46c*)marker, x << 12, y << 12, -0xa000);
            RecomputeField0x7c((Struct020478bc*)marker, 1);
            AdvanceStreamRecord0204724c((Obj0204724C*)marker);
            GXFIFO_MATRIX_PUSH = 0;
            func_020473c8((Struct_02015ef4_2*)var23, 1);
            var14++;
            GXFIFO_MATRIX_POP = 1;
            if (drawn >= 3) break;
        } else if (member->field1b2) {
            Foo02048004* marker = (Foo02048004*)self->unknown_35a8;
            SprSprite_SetPosition((Vec3Target0203a46c*)marker, x << 12, y << 12, -0xa000);
            GXFIFO_MATRIX_PUSH = 0;
            func_0204724c((Struct_0201730c*)var24);
            func_020473c8((Struct_02015ef4_2*)var24, 1);
            var14++;
            GXFIFO_MATRIX_POP = 1;
            if (drawn >= 3) break;
        } else if (HasFlagBit_0218d4ec(self, member->obj3D.actorIndex_)) {
            Foo02048004* marker = &self->substruct_array_2b90[17];
            SprSprite_SetPosition((Vec3Target0203a46c*)marker, x << 12, y << 12, -0xa000);
            GXFIFO_MATRIX_PUSH = 0;
            func_0204724c((Struct_0201730c*)var25);
            func_020473c8((Struct_02015ef4_2*)var25, 1);
            GXFIFO_MATRIX_POP = 1;
        }
    }
}
