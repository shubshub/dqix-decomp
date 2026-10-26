#include <globaldefs.h>
#include "Graphics/Vector.h"
#include "Resource/GameResources.h"
#include "World/Object3D.h"

struct Struct_ov017_0218dfd8 {
    Object3D obj3D;
#if defined(jpn)
    char pad[0x180 - sizeof(Object3D)];
#else
    char pad[0x18c - sizeof(Object3D)];
#endif
    unsigned int flags;
};

struct ActorEntry {
    char pad0[0x2];
    short state;
    char pad4[0x20];
    Vector3fix position;
    char unknown_30_[0x368 - 0x30];
};

// Zone3D up to lootables_ (this file's copy)
struct Zone3D0218dfd8 {
#if defined(jpn)
    char pad0[0x496];
#else
    char pad0[0x476];
#endif
    unsigned char count;
    char unknown_477_[0x1];
    ActorEntry* entries;
};

struct Struct_ov017_0218dfd8_2 {
    unsigned char tag;
    unsigned char pad1;
    short index;
    unsigned char pad4[4];
    ActorEntry* target;
    int unknown_c_;
    short angle;
    unsigned short pad12;
};

struct Header0218dfd8 {
    unsigned char pad0[3];
    unsigned char busy;
};

class Zone3D;
extern "C" Zone3D0218dfd8* Zone3D_GetInstance(void);
extern "C" ActorEntry* Zone3D_GetLootable(Zone3D* zone, int index);
extern "C" unsigned int func_02039dcc(unsigned char* obj);
struct Vec3;
extern "C" short func_ov017_021a4754(Vector3fix*, int, Vector3fix*);
extern "C" int FieldTaskQueue_IsEmpty(void** obj);
extern "C" int GameObject_IsGesturing(signed char* obj);
extern "C" void func_ov017_0219a674(unsigned char* self);
extern "C" void func_ov017_0219b33c(GameResources* res, Struct_ov017_0218dfd8_2* event);

// USA: func_ov017_0218dfd8
extern "C" ARM int func_ov017_0218dfd8(Struct_ov017_0218dfd8* self) {
    GameResources* res = GetGameResources();
    if (((Header0218dfd8*)res->unknown_ptr_array_3700[3])->busy != 0) {
        return 0;
    }
    Vector3fix pos = self->obj3D.position_;
    int moved = 0;
    Zone3D0218dfd8* manager = Zone3D_GetInstance();
    ActorEntry* entry = Zone3D_GetLootable((Zone3D*)manager, 0);
    if (entry == NULL) {
        return 0;
    }
    int var5 = self->obj3D.GetRadius() / 2 + 0x800;
    int bestAngle = 0x3244;
    int var7 = -1;
    ActorEntry* best = NULL;
    for (int i = 0; i < manager->count; entry++, i++) {
        if (entry->state != 0) {
            continue;
        }
        Vector3fix a = pos;
        Vector3fix b = entry->position;
        if (fix32abs(a.y - b.y) >= 0x1000) {
            continue;
        }
        a.y = 0;
        b.y = 0;
        int dist = Vector3fix_Distance(&a, &b);
        if (dist < var5) {
            if (!func_02039dcc((unsigned char*)self)) {
                Vector3fix dir;
                Vector3fix_Subtract(&a, &b, &dir);
                Vector3fix_Normalize(&dir, &dir);
                Vector3fixMultiplyScalar(&dir, var5, &dir);
                Vector3fix_Add(&b, &dir, &a);
                pos.x = a.x;
                pos.z = a.z;
                self->obj3D.position_ = pos;
            }
            moved = 1;
        }
        if (dist < var5 + 0x400) {
            int angle = func_ov017_021a4754(&pos, (short)self->obj3D.rotation_.y, &b);
            if (angle < bestAngle) {
                bestAngle = angle;
                var7 = i;
                best = entry;
            }
        }
    }
    void** list = (void**)res->fieldTaskQueue_;
    if (best != NULL && FieldTaskQueue_IsEmpty(list) != 0 &&
        GameObject_IsGesturing((signed char*)self) == 0 && !(self->flags & 0x40) && bestAngle < 0xc91) {
        Struct_ov017_0218dfd8_2 event;
        func_ov017_0219a674((unsigned char*)&event);
        event.tag = 5;
        event.angle = bestAngle;
        event.target = best;
        event.index = var7;
        func_ov017_0219b33c(res, &event);
    }
    return moved;
}
