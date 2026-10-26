#include <globaldefs.h>
#include "Combat/FieldActorState.h"
#include "NitroSDK/Matrix.h"

#if defined(jpn)
enum { EntryListOffset = 0x14 };
#else
enum { EntryListOffset = 0x18 };
#endif

struct Entry_02028bd0;
struct Struct_0201a300_11;
struct Obj02033834;
struct Obj02033b68;
struct SearchStruct0202c1a4;

struct Struct_02076fdc {
    unsigned char type;
    char pad1[3];
    short x;
    short y;
    short z;
};

extern "C" struct Entry_02028bd0* ZoneRecords_GetInstance();
extern "C" struct Entry_02028bd0* ZoneRecords_Find(struct Entry_02028bd0* table, int key);
extern "C" struct Struct_02076fdc* func_020283c0(struct Struct_0201a300_11* list, int key);

extern "C" int fix32_Atan2(int x, int z);
extern "C" void GameObject_SetFacing(struct Obj02033834* obj, int angle);
extern "C" void GameObject_SetMotionState(struct Obj02033b68* obj, int value);
extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsActive(int* obj);
extern "C" signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);
extern "C" int _s32_div_f(int a, int b);
extern "C" void func_ov017_021c9168(int id, int slot, int heading, int type,
        Vector3fix a, Vector3fix b, int dir);

// USA: func_02076fdc
extern "C" ARM int func_02076fdc(FieldMonsterState* self) {
    struct Entry_02028bd0* table = ZoneRecords_GetInstance();
    struct Entry_02028bd0* entry =
        ZoneRecords_Find(table, self->actor.base.object.GetField06());
    if (entry == 0) {
        return 0;
    }
    struct Struct_0201a300_11* list = (struct Struct_0201a300_11*)((char*)entry + EntryListOffset);
    if (list == 0) {
        return 0;
    }
    struct Struct_02076fdc* row = func_020283c0(list, self->unknown_164_);
    if (row == 0) {
        return 0;
    }
    self->targetPosition.x = row->x << 0xc;
    self->targetPosition.y = row->y << 0xc;
    self->targetPosition.z = row->z << 0xc;
    Vector3fix diff;
    Vector3fix_Subtract(&self->targetPosition, &self->actor.base.object.position_, &diff);
    if (Vector3fix_Length(&diff) < 0x1000) {
        return 0;
    }
    Vector3fix_Normalize(&diff, &diff);
    GameObject_SetFacing((struct Obj02033834*)self, fix32_Atan2(diff.x, diff.z));
    self->flags |= 0x40;
    switch (self->actor.unknown_139_) {
    case 0:
        self->actor.base.fieldB4 = 0;
        self->actor.base.fieldB2 = 0;
        break;
    case 1:
        self->actor.base.fieldB4 = 0x9a;
        self->actor.base.fieldB2 = 0x9a;
        break;
    case 2:
        self->actor.base.fieldB4 = 0xe6;
        self->actor.base.fieldB2 = 0xe6;
        break;
    case 3:
        self->actor.base.fieldB4 = 0x1c2;
        self->actor.base.fieldB2 = 0x1c2;
        break;
    }
    GameObject_SetMotionState((struct Obj02033b68*)self, 1);
    if (self->actor.unknown_134_ == 4 || self->actor.unknown_134_ == 5 || self->actor.unknown_134_ == 6) {
        self->actor.base.object.DisableFlag(0x80);
    } else {
        self->actor.base.object.EnableFlag(0x80);
    }
    void* g = LinkSession_GetInstance();
    if (LinkSession_IsActive((int*)g)) {
        if (LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)g) == 0) {
            int id = self->actor.base.object.GetField06();
            int wanted = self->actor.base.object.actorIndex_;
            wanted -= 0x70;
            int heading = self->actor.base.object.unknown_2_;
            Vector3fix a = self->actor.base.object.position_;
            Vector3fix b = self->actor.base.object.rotation_;
            int slot = wanted % 0xc;
            if (slot >= 0 && slot < 0xc) {
                func_ov017_021c9168(id, slot, heading, row->type, a, b, -1);
            }
        }
    }
    return 1;
}
