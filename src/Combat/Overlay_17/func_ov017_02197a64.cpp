#if defined(jpn)
enum { RegionOffset6c = 0x8c };
#else
enum { RegionOffset6c = 0x6c };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "Graphics/Vector.h"
#include "Input/Input.h"

struct Obj020968d0;

struct GroupNode02197a64 {
    unsigned char pad0[0x8];
    Vector3fix position;
    unsigned char unknown_14_[0x20 - 0x14];
    short angle;
    unsigned char unknown_22_[0x2e - 0x22];
    unsigned short low : 4;
    unsigned short flags : 12;
    unsigned char unknown_30_[0x70 - 0x30];
    struct GroupNode02197a64* next;
};

struct Leader02197a64 {
    unsigned char pad0[0x44];
    Vector3fix position;
    unsigned char unknown_50_[0x54 - 0x50];
    int rotationY;
    unsigned char unknown_58_[0xbe - 0x58];
    unsigned char mode;
};

struct Struct_ov017_02197a64_4 {
#if defined(jpn)
    unsigned char pad0[0x4188];
#else
    unsigned char pad0[0x4438];
#endif
    Vector3fix heading;
};

struct Struct_ov017_02197a64_5 {
#if defined(jpn)
    unsigned char pad0[0x40cc];
#else
    unsigned char pad0[0x42ec];
#endif
    short unknown_42ec_;
};

struct Struct_ov017_02197a64 {
    unsigned char tag;
    unsigned char pad1[3];
    unsigned char count;
    unsigned char pad5[3];
    struct GroupNode02197a64* nodes[2];
    short angle;
    short pad12;
};

extern "C" void* Zone3D_GetInstance(void);
extern "C" void* ZoneFeatures_GetFirstOfType(unsigned char* obj, unsigned int index);
extern "C" Obj020968d0* GameResources_GetTouchWalk(void* res);
extern "C" void func_ov017_0219a674(unsigned char* self);
extern "C" int func_02094b9c(void* a, void* b);
extern "C" int func_ov017_0218da48(void* obj, int angle, int c, int d, unsigned char e);
extern "C" int func_020968d0(Obj020968d0* obj, int* arg1);
extern "C" void __clear(void* buf, int count);
struct Vec3;
extern "C" short func_ov017_021a4754(Vector3fix*, int, Vector3fix*);
extern "C" void func_ov017_0219b33c(Struct_ov017_02197a64_5* self, Struct_ov017_02197a64* event);
extern "C" void func_ov017_02198f84(Struct_ov017_02197a64_5* self);

#define FACING_LIMIT ((int)(0.8f * 4096.0f))

// USA: func_ov017_02197a64
extern "C" ARM void func_ov017_02197a64(Struct_ov017_02197a64_5* self) {
    GameState* gs = GameState::GetInstance();
    Struct_ov017_02197a64_4* res = (Struct_ov017_02197a64_4*)GetGameResources();
    void* cache = Zone3D_GetInstance();
    Leader02197a64* leader = (Leader02197a64*)gs->GetLeader();
    Vector3fix var4 = leader->position;
    GroupNode02197a64* node = (GroupNode02197a64*)ZoneFeatures_GetFirstOfType((unsigned char*)cache + RegionOffset6c, 2);
    Obj020968d0* field = GameResources_GetTouchWalk(res);
    int notify = 0;
    Struct_ov017_02197a64 event;
    func_ov017_0219a674((unsigned char*)&event);
    int var9 = 0;
    int var10 = 0;

    while (node != NULL && event.count < 2) {
        if (!(node->flags & 1) && !(node->flags & 4) && func_02094b9c(node, &var4)) {
            if (!var10) {
                var10 = func_ov017_0218da48(self, node->angle, FACING_LIMIT, FACING_LIMIT >> 3, 0);
            }
            Vector3fix dir;
            int c = fix32cos(node->angle);
            dir.x = fix32sin(node->angle);
            dir.y = 0;
            dir.z = c;
            Vector3fix_Normalize(&dir, &dir);
            Vector3fix var13;
            c = fix32cos(leader->rotationY);
            var13.x = fix32sin(leader->rotationY);
            var13.y = 0;
            var13.z = c;
            Vector3fix_Normalize(&var13, &var13);
            Vector3fix heading = res->heading;
            int facing = Vector3fix_InnerProduct(&dir, &var13);
            int var16 = Vector3fix_InnerProduct(&dir, &heading);
            if ((heading.x != 0 || heading.z != 0) &&
                (func_020968d0(field, NULL) != 0 || g_keyManager.TestKeysHeld(KEY_DPAD) != 0)) {
                facing = var16;
            }
            if (node->flags & 0x10) {
                Vector3fix var17;
                Vector3fix_Subtract(&var4, &node->position, &var17);
                var17.y = 0;
                Vector3fix_Normalize(&var17, &var17);
                if (Vector3fix_InnerProduct(&dir, &var17) > 0) {
                    if (facing >= 0) {
                        node = node->next;
                        continue;
                    }
                } else {
                    if (facing <= 0) {
                        node = node->next;
                        continue;
                    }
                }
            } else {
                if (facing > 0) {
                    node = node->next;
                    continue;
                }
            }
            event.nodes[event.count++] = node;
            if (self->unknown_42ec_ <= 2) {
                if (leader->mode == 1 &&
                    (var16 < 0x170 - FACING_LIMIT || var16 > FACING_LIMIT - 0x170 ||
                     facing < 0x170 - FACING_LIMIT || facing > FACING_LIMIT - 0x170)) {
                    if (!var9) {
                        var9 = 1;
                        self->unknown_42ec_++;
                    }
                } else {
                    self->unknown_42ec_ = 0;
                }
            } else if (self->unknown_42ec_ > 2) {
                if (!var9) notify = 1;
            }
        }
        node = node->next;
    }

    if (event.count != 0) {
        Vector3fix center;
        __clear(&center, sizeof(center));
        for (int i = 0; i < event.count; i++) {
            Vector3fix_Add(&center, &event.nodes[i]->position, &center);
        }
        Vector3fixDivideScalar(&center, event.count << 12, &center);
        event.angle = func_ov017_021a4754(&leader->position, (short)leader->rotationY, &center);
        event.tag = 4;
        func_ov017_0219b33c(self, &event);
    }
    if (notify) {
        func_ov017_02198f84(self);
    }
}
