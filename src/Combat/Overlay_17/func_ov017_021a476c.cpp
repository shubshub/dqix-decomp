#include <globaldefs.h>
#include "GameState/GameState.h"
#include "GameState/Field3b0.h"
#include "Graphics/Vector.h"
#include "World/ZoneFeatures.h"
#include "Resource/Brightness.h"

struct Struct_0203dce4_2;
struct Struct_0203e0a0;
struct Struct_0203de84;
struct Node020406f8;
struct BitField0203402c;
struct Vec3 {
    int x, y, z;
};

#if defined(jpn)
enum { regionalOffset = 0x54c4 };
#else
enum { regionalOffset = 0x5724 };
#endif

struct Struct_ov017_021a476c_8 {
    unsigned char busy;
};

struct Struct_ov017_021a476c_9 {
#if defined(jpn)
    char pad0[0x34ec];
    void* list;
    char unknown_34f0_[0x416c - 0x34f0];
    Struct_ov017_021a476c_8* holder;
    char unknown_4170_[0x41e1 - 0x4170];
#else
    char pad0[0x36fc];
    void* list;
    char unknown_3700_[0x441c - 0x3700];
    Struct_ov017_021a476c_8* holder;
    char unknown_4420_[0x4491 - 0x4420];
#endif
    unsigned char active;
};

struct Actor021a476c {
    Object3D obj3D;
#if defined(jpn)
    char unknown_ac_[0x180 - 0xac];
    unsigned int unknown_18c_;
    char unknown_184_[0x1a6 - 0x184];
#else
    char unknown1_ac_[0x18c - 0xac];
    unsigned int unknown_18c_;
    char unknown_190_[0x1b2 - 0x190];
#endif
    unsigned short field1b2;
};

struct Struct_ov017_021a476c {
    char pad0[0xc];
    unsigned char lo : 4;
    unsigned char blocked : 1;
};

struct Work021a476c {
    unsigned short mapId;
    char pad2[0x8 - 0x2];
    Struct_ov017_021a476c* flags;
};

struct Struct_ov017_021a476c_3 {
    unsigned int flags;
};

struct Struct_ov017_021a476c_4 {
    unsigned short kind;
    unsigned char sub;
};

struct Struct_ov017_021a476c_5 {
    char pad0[0xa];
    unsigned char lo : 3;
    unsigned char mode : 3;
    char unknown_b_[0x10 - 0xb];
    Vector3fix pos;
};

struct Struct_ov017_021a476c_6 {
    unsigned char kind;
    unsigned char field1;
    short field2;
    unsigned char field4;
    char pad5[3];
    int field8;
    int fieldc;
    short angle;
    short field12;
};

struct Save021a476c {
    char pad0[0x8c];
    unsigned char flags[1];
};

signed char data_ov017_021d76d8 = -1;
short data_ov017_021d76da = -1;
unsigned short data_ov017_021d83a8;

extern "C" void* func_0203cf4c(void);
extern "C" int MessageSystem_GetInstance(void);
extern "C" Work021a476c* Zone3D_GetInstance(void);
extern "C" void* LinkSession_GetInstance(void);
extern "C" int FieldTaskQueue_IsEmpty(void** obj);
extern "C" int func_ov017_021a4e88(int arg0, unsigned short* arg1);
extern "C" int LinkSession_IsActive(int* obj);
extern "C" Struct_ov017_021a476c_3* func_0203dce4(Struct_0203dce4_2* list, int id);
extern "C" Struct_ov017_021a476c_4* func_02040528(int* obj);
extern "C" Struct_ov017_021a476c_5* func_02040538(Struct_0203e0a0* p);
extern "C" unsigned char GameObject_IsClimbingLadder(char* obj);
extern "C" int GameObject_IsGesturing(signed char* obj);
extern "C" int GameObject_IsSinking(BitField0203402c* p);
extern "C" void func_ov017_0219a674(unsigned char* self);
extern "C" void func_020406f8(Struct_0203de84* out, Node020406f8* n);
extern "C" short func_ov017_021a4700(Vec3* p0, int arg1, Vec3* p2);
extern "C" int func_ov017_0218daa8(void* obj, Vec3* arg1, int c, int d, unsigned char e);
extern "C" int LinkSession_IsHostOrSolo(void* obj);
extern "C" void func_ov017_0219b33c(Struct_ov017_021a476c_9* self, Struct_ov017_021a476c_6* msg);
extern "C" int func_02039860(void* obj);
extern "C" unsigned int func_02039de8(unsigned char* obj);
extern "C" Save021a476c* Scenario_GetInstance(void);
extern "C" int func_ov017_0218d4ec(void* obj, int bit);
extern "C" int Scenario_TestFlag(int unused, unsigned char* arr, int index);

// USA: func_ov017_021a476c
extern "C" ARM void func_ov017_021a476c(Struct_ov017_021a476c_9* self) {
    Struct_ov017_021a476c_6 msg;
    Struct_ov017_021a476c_6 var1;
    Vector3fix pos;
    GameState* game = GameState::GetInstance();
    void* list = func_0203cf4c();
    game->GetCamera();
    MessageSystem_GetInstance();
    Actor021a476c* player = (Actor021a476c*)game->GetLeader();
    GameResources* res = GetGameResources();
    Work021a476c* work = Zone3D_GetInstance();
    void* session = LinkSession_GetInstance();

    data_ov017_021d76da = -1;
    data_ov017_021d83a8 = 0;
    data_ov017_021d76d8 = -1;
    *(int*)((char*)game + regionalOffset) = -1;

    if (self->active == 0 && !FieldTaskQueue_IsEmpty((void**)self->list)) {
        func_ov017_021a4e88(0, &data_ov017_021d83a8);
        return;
    }
    if (LinkSession_IsActive((int*)session) && self->holder->busy != 0) {
        return;
    }
    data_ov017_021d76da = func_ov017_021a4e88(1, &data_ov017_021d83a8);
    if (data_ov017_021d76da >= 0) {
        Struct_ov017_021a476c_3* entry = func_0203dce4((Struct_0203dce4_2*)list, data_ov017_021d76da);
        if (entry != NULL) {
            Struct_ov017_021a476c_4* data = func_02040528((int*)entry);
            Struct_ov017_021a476c_5* info = func_02040538((Struct_0203e0a0*)entry);
            if (entry->flags & 0x200) {
                return;
            }
            if (GameObject_IsClimbingLadder((char*)player) != 0 || res->unknown_4080 != 0) {
                return;
            }
            if (IsScreenFullyFaded(res, false)) {
                return;
            }
            if (GameObject_IsGesturing((signed char*)player)) {
                return;
            }
            if (GameObject_IsSinking((BitField0203402c*)player)) {
                return;
            }
            if (data != NULL && info != NULL) {
                int limit = 0x1922;
                func_ov017_0219a674((unsigned char*)&msg);
                msg.kind = 0;
                func_020406f8((Struct_0203de84*)&pos, (Node020406f8*)entry);
                msg.angle = fix32abs(func_ov017_021a4700((Vec3*)&player->obj3D.position_, (short)player->obj3D.rotation_.y, (Vec3*)&pos));
                if (work->mapId == 0x1901 && data->kind == 0x6a) {
                    limit = 0x25b3;
                    func_ov017_0218daa8(self, (Vec3*)&info->pos, 0xccc, -0x199, 0);
                }
                if (msg.angle < limit) {
                    int set = 0;
                    int var14 = 0;
                    int mode = info->mode;
                    if (mode == 0) {
                        if (data->sub == 1) {
                            msg.field1 = 3;
                            set = 1;
                        }
                    } else if (mode == 1) {
                        msg.field1 = 3;
                        set = 1;
                    } else if (mode == 2) {
                        msg.field1 = 4;
                        set = 1;
                    } else if (mode == 3) {
                        if (LinkSession_IsHostOrSolo(LinkSession_GetInstance())) {
                            msg.field1 = 0xf;
                        } else {
                            msg.field1 = 2;
                        }
                    } else if (mode == 4) {
                        var14 = 1;
                    }
                    if (!set) {
                        msg.field2 = data_ov017_021d76da;
                    }
                    if (!var14) {
                        func_ov017_0219b33c(self, &msg);
                    }
                }
            }
        }
    } else {
        Actor021a476c* mem;
        Save021a476c* save;
        int sum;
        int ay;
        int var20;
        int ax;
        Actor021a476c* member;
        int i;
        int dy;
        int dz;
        int dx;
        int best;
        int found;
        Actor021a476c* leader;
        GameState* game2;
        Work021a476c* work2;
        void* list2;
        GameResources* res2;
        if (!LinkSession_IsActive((int*)LinkSession_GetInstance())) {
            goto none;
        }
        res2 = GetGameResources();
        list2 = res2->fieldTaskQueue_;
        work2 = Zone3D_GetInstance();
        if (IsScreenFullyFaded(res2, false)) {
            found = -1;
            goto done;
        }
        if (work2->flags->blocked) {
            found = -1;
            goto done;
        }
        if (FieldTaskQueue_IsEmpty((void**)list2) == 0) {
            found = -1;
            goto done;
        }
        game2 = GameState::GetInstance();
        leader = (Actor021a476c*)game2->GetLeader();
        found = -1;
        best = -1;
        dx = 0;
        dz = 0;
        dy = 0;
        for (i = 0; i <= 3; i++) {
            member = (Actor021a476c*)game2->GetPartyMemberByIndex(i);
            if (member == NULL || member == leader) {
                continue;
            }
            if (leader->obj3D.GetField06() != member->obj3D.GetField06()) {
                continue;
            }
            if (member->obj3D.unknown_0_ & 0x1000) {
                continue;
            }
            if (member->unknown_18c_ & 1) {
                continue;
            }
            if (func_02039860(member) >= 0) {
                continue;
            }
            if (func_02039de8((unsigned char*)member)) {
                continue;
            }
            if (!member->obj3D.IsVisible()) {
                continue;
            }
            Struct_02014900 var34;
            Struct_02014900 var35;
            var35 = *(Struct_02014900*)&leader->obj3D.position_;
            var34 = *(Struct_02014900*)&member->obj3D.position_;
            ax = fix32abs(var35.vec.x - var34.vec.x);
            var20 = fix32abs(var35.vec.z - var34.vec.z);
            ay = fix32abs(var35.vec.y - var34.vec.y);
            sum = ax + var20;
            if (best == -1 || sum < best) {
                found = member->obj3D.actorIndex_;
                best = sum;
                dx = ax;
                dz = var20;
                dy = ay;
            }
        }
        if (dx < 0x1800 && dz < 0x1800 && dy < 0xb33) {
            goto done;
        }
    none:
        found = -1;
    done:
        data_ov017_021d76d8 = found;
        if (data_ov017_021d76d8 >= 0) {
            mem = (Actor021a476c*)game->GetPartyMemberByIndex(data_ov017_021d76d8);
            save = Scenario_GetInstance();
            if (mem->field1b2 == 0) {
                if (!func_ov017_0218d4ec(self, data_ov017_021d76d8) ||
                    !Scenario_TestFlag((int)save, save->flags, 0x799)) {
                    func_ov017_0219a674((unsigned char*)&var1);
                    var1.kind = 0xa;
                    var1.angle = fix32abs(func_ov017_021a4700((Vec3*)&player->obj3D.position_, (short)player->obj3D.rotation_.y, (Vec3*)&mem->obj3D.position_));
                    if (var1.angle < 0x1922) {
                        var1.field2 = data_ov017_021d76d8;
                        func_ov017_0219b33c(self, &var1);
                    }
                }
            }
        }
    }
    self->active = 0;
}
