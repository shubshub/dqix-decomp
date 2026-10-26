#include <globaldefs.h>
#include "Combat/FieldActorState.h"
#include "NitroSDK/Matrix.h"

#if defined(jpn)
enum { Enum_02076fdc_24 = 0x14 };
#else
enum { Enum_02076fdc_24 = 0x18 };
#endif

struct Struct_020fdd44;
struct Struct_0201a300_11;
struct Struct_02033834_2;
struct Struct_02033b68;
struct Struct_0202c1a4;

struct Struct_02076fdc {
    unsigned char unknown_0_;
    char unknown_1_[3];
    short unknown_4_;
    short unknown_6_;
    short unknown_8_;
};

extern struct Entry_02028bd0* ZoneRecords_GetInstance();
extern struct Entry_02028bd0* ZoneRecords_Find(struct Entry_02028bd0* table, int key);
extern struct Row02076fdc* FindListEntryById(struct List_020283c0* list, int key);

extern "C" int fix32_Atan2(int x, int z);
void GameObject_SetFacing(struct Obj02033834* obj, int angle);
void GameObject_SetMotionState(struct Obj02033b68* obj, int value);
extern "C" void* LinkSession_GetInstance(void);
int LinkSession_IsActive(int* obj);
signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);
extern "C" int _s32_div_f(int a, int b);
extern "C" void func_ov017_021c9168(int arg0, int arg1, int arg2, int arg3,
        Vector3fix arg4, Vector3fix arg5, int arg6);

// USA: func_02076fdc
extern "C" ARM int func_02076fdc(FieldMonsterState* self) {
    struct Entry_02028bd0* table = ZoneRecords_GetInstance();
    struct Entry_02028bd0* entry =
        ZoneRecords_Find(table, self->actor.base.object.GetField06());
    if (entry == 0) {
        return 0;
    }
    struct Struct_0201a300_11* var2 = (struct Struct_0201a300_11*)((char*)var1 + Enum_02076fdc_24);
    if (var2 == 0) {
        return 0;
    }
    struct Struct_02076fdc* var3 = func_020283c0(var2, arg0->unknown_164_);
    if (var3 == 0) {
        return 0;
    }
    arg0->unknown_158_.x = var3->unknown_4_ << 0xc;
    arg0->unknown_158_.y = var3->unknown_6_ << 0xc;
    arg0->unknown_158_.z = var3->unknown_8_ << 0xc;
    Vector3fix var4;
    Vector3fix_Subtract(&arg0->unknown_158_, &arg0->unknown_0_.unknown_0_.unknown_0_.position_, &var4);
    if (Vector3fix_Length(&var4) < 0x1000) {
        return 0;
    }
    Vector3fix_Normalize(&diff, &diff);
    GameObject_SetFacing((struct Obj02033834*)self, fix32_Atan2(diff.x, diff.z));
    self->flags |= 0x40;
    switch (self->actor.unknown_139) {
    case 0:
        arg0->unknown_0_.unknown_0_.unknown_b4_ = 0;
        arg0->unknown_0_.unknown_0_.unknown_b2_ = 0;
        break;
    case 1:
        arg0->unknown_0_.unknown_0_.unknown_b4_ = 0x9a;
        arg0->unknown_0_.unknown_0_.unknown_b2_ = 0x9a;
        break;
    case 2:
        arg0->unknown_0_.unknown_0_.unknown_b4_ = 0xe6;
        arg0->unknown_0_.unknown_0_.unknown_b2_ = 0xe6;
        break;
    case 3:
        arg0->unknown_0_.unknown_0_.unknown_b4_ = 0x1c2;
        arg0->unknown_0_.unknown_0_.unknown_b2_ = 0x1c2;
        break;
    }
    GameObject_SetMotionState((struct Obj02033b68*)self, 1);
    if (self->actor.unknown_134 == 4 || self->actor.unknown_134 == 5 || self->actor.unknown_134 == 6) {
        self->actor.base.object.DisableFlag(0x80);
    } else {
        arg0->unknown_0_.unknown_0_.unknown_0_.EnableFlag(0x80);
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
