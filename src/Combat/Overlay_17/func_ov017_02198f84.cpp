#include <globaldefs.h>
#include "World/ZoneChest.h"
#include "GameState/GameState.h"
#include "NitroSDK/Matrix.h"


struct Pending02198f84 {
    unsigned short id;
    unsigned char pending;
    unsigned char pad3[0xb - 0x3];
    signed char unknown_b_;
    unsigned char unknown_c_[0x10 - 0x0c];
    Vector3i pos;
    short field_0x1c;
    unsigned char pad1e[0x3c - 0x1e];
    Vector3i vecA;
    Vector3i vecB;
    Vector3i unknown_54_;
};

struct Struct_ov017_02198f84_2 {
    unsigned char pad0[0x1c];
    unsigned short field_0x1c;
    unsigned short field_0x1e;
    unsigned char pad20[0x28 - 0x20];
    short field_0x28;
    unsigned char pad2a[0x34 - 0x2a];
};

struct Struct_ov017_02198f84_3 {
#if defined(jpn)
    unsigned char pad0[0x34a8];
#else
    unsigned char pad0[0x36b8];
#endif
    unsigned char unknown_36b8_;
    unsigned char unknown_36b9_[3];
    ZoneFeatures::Opcode6aEntry* nodes[0x10];
    struct TailList020469b4* unknown_36fc_;
#if defined(jpn)
    unsigned char unknown_34f0_[0x38f0 - 0x34f0];
#else
    unsigned char unknown_3700_[0x3b10 - 0x3700];
#endif
    struct Struct_ov017_021ab250* unknown_3b10_;
    unsigned char unknown_3b14_[0x42ec - 0x3b14];
    unsigned short unknown_42ec_;
};

extern "C" void* Zone3D_GetInstance(void);
extern "C" void* Scenario_GetInstance(void);
extern "C" int Scenario_RunTrigger(void* a, int mode, void* c);
extern "C" void EventQuery_RunQueuedCommands(void* p);
extern "C" void func_ov017_021ab250(struct Struct_ov017_021ab250* p);
extern "C" Pending02198f84* GameState_GetZoneTransition(GameState* state);
extern "C" void func_ov017_021ab698(char* p, int v);
struct TailNode020469b4;
extern "C" void func_020469b4(struct TailList020469b4* list, struct TailNode020469b4* node);

// USA: func_ov017_02198f84
extern "C" ARM void func_ov017_02198f84(Struct_ov017_02198f84_3* self) {
    Zone3D* ctx = (Zone3D*)Zone3D_GetInstance();
    for (int i = 0; i < self->unknown_36b8_; i++) {
        ZoneFeatures::Opcode6aEntry* node = self->nodes[i];
        if (node == NULL) {
            continue;
        }
        int clear = 0;
        void* r = Scenario_GetInstance();
        Struct_ov017_02198f84_2 q;
        q.field_0x28 = node->angle;
        q.field_0x1e = node->unk_2c.type2.elementId;
        q.field_0x1c = node->unk_2c.type2.nodeId;
        if (Scenario_RunTrigger(r, 0x11, &q)) {
            EventQuery_RunQueuedCommands(&q);
        }
        if (!(node->unk_2c.type2.flags & 4)) {
            Zone3D_OpenDoor(ctx, node, 1, 1, 1);
            if ((node->unk_2c.type2.flags & 8) && node->unk_2c.type2.maybeZone != 0) {
                func_ov017_021ab250(self->unknown_3b10_);
                Pending02198f84* pending = GameState_GetZoneTransition(GameState::GetInstance());
                if (pending->pending != 0) {
                    node->unk_2c.type2.maybeZone = pending->id;
                    node->unk_2c.type2.vectors_c[0] = pending->pos;
                    node->unk_2c.type2.unk_3c = pending->field_0x1c;
                    node->unk_2c.type2.unk_3e = pending->unknown_b_;
                    node->unk_2c.type2.vectors_c[1] = pending->vecA;
                    node->unk_2c.type2.vectors_c[2] = pending->vecB;
                    node->unk_2c.type2.vectors_c[3] = pending->unknown_54_;
                    pending->pending = 0;
                }
                func_ov017_021ab698((char*)self->unknown_3b10_, (int)node);
                func_020469b4(self->unknown_36fc_, (struct TailNode020469b4*)self->unknown_3b10_);
            } else if (!(node->unk_2c.type2.flags & 8)) {
                clear = 1;
            }
        } else {
            self->unknown_42ec_ = 0;
            node->unk_2c.type2.flags &= ~4;
        }
        if (clear) {
            self->unknown_42ec_ = 0;
        }
    }
}
