#include <globaldefs.h>
#include "World/ZoneChest.h"
#include "GameState/GameState.h"
#include "NitroSDK/Matrix.h"


struct Struct_ov017_02198f84 {
    unsigned short unknown_0_;
    unsigned char unknown_2_;
    unsigned char unknown_3_[0xb - 0x3];
    signed char unknown_b_;
    unsigned char unknown_c_[0x10 - 0x0c];
    Vector3i unknown_10_;
    short unknown_1c_;
    unsigned char unknown_1e_[0x3c - 0x1e];
    Vector3i unknown_3c_;
    Vector3i unknown_48_;
    Vector3i unknown_54_;
};

struct Struct_ov017_02198f84_2 {
    unsigned char unknown_0_[0x1c];
    unsigned short unknown_1c_;
    unsigned short unknown_1e_;
    unsigned char unknown_20_[0x28 - 0x20];
    short unknown_28_;
    unsigned char unknown_2a_[0x34 - 0x2a];
};

struct Struct_ov017_02198f84_3 {
#if defined(jpn)
    unsigned char unknown_0_[0x34a8];
#else
    unsigned char unknown1_0_[0x36b8];
#endif
    unsigned char unknown_36b8_;
    unsigned char unknown_36b9_[3];
    Struct_020134e0::Struct_02018300* unknown_36bc_[0x10];
    struct Struct_0201bdac_2* unknown_36fc_;
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
int Scenario_RunTrigger(void* a, int mode, void* c);
extern "C" void EventQuery_RunQueuedCommands(void* p);
void InitState6_021ab250(struct Struct021ab250* p);
Pending02198f84* GetField0x3f8Address_0200fd0c(GameState* state);
void SetIntField_021ab698_021ab698(char* p, int v);
struct TailNode020469b4;
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);

// USA: func_ov017_02198f84
extern "C" ARM void func_ov017_02198f84(Self02198f84* self) {
    Zone3D* ctx = (Zone3D*)Zone3D_GetInstance();
    for (int i = 0; i < self->nodeCount; i++) {
        ZoneFeatures::Opcode6aEntry* node = self->nodes[i];
        if (node == NULL) {
            continue;
        }
        int clear = 0;
        void* r = Scenario_GetInstance();
        Query02198f84 q;
        q.field_0x28 = node->angle;
        q.field_0x1e = node->unk_2c.type2.elementId;
        q.field_0x1c = node->unk_2c.type2.nodeId;
        if (Scenario_RunTrigger(r, 0x11, &q)) {
            EventQuery_RunQueuedCommands(&q);
        }
        if (!(node->unk_2c.type2.flags & 4)) {
            Zone3D_OpenDoor(ctx, node, 1, 1, 1);
            if ((node->unk_2c.type2.flags & 8) && node->unk_2c.type2.maybeZone != 0) {
                InitState6_021ab250(self->state6);
                Pending02198f84* pending = GetField0x3f8Address_0200fd0c(GameState::GetInstance());
                if (pending->pending != 0) {
                    node->unk_2c.type2.maybeZone = pending->id;
                    node->unk_2c.type2.vectors_c[0] = pending->pos;
                    node->unk_2c.type2.unk_3c = pending->field_0x1c;
                    node->unk_2c.type2.unk_3e = pending->field_0xb;
                    node->unk_2c.type2.vectors_c[1] = pending->vecA;
                    node->unk_2c.type2.vectors_c[2] = pending->vecB;
                    node->unk_2c.type2.vectors_c[3] = pending->vecC;
                    pending->pending = 0;
                }
                SetIntField_021ab698_021ab698((char*)self->state6, (int)node);
                AppendNodeToTail(self->tailList, (struct TailNode020469b4*)self->state6);
            } else if (!(node->unk_2c.type2.flags & 8)) {
                clear = 1;
            }
        } else {
            self->field_0x42ec = 0;
            node->unk_2c.type2.flags &= ~4;
        }
        if (var3) {
            arg0->unknown_42ec_ = 0;
        }
    }
}
