#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

typedef Vector3fix Type_ov017_021a4e88;

struct Struct_ov017_021a4e88 {
    Type_ov017_021a4e88 center;
    int radius;
};

struct Struct_ov017_021a4e88_2 {
    int id;
    int maxX;
    int maxZ;
    int minX;
    int minZ;
    Struct_ov017_021a4e88_2* next;
};

struct Struct_ov017_021a4e88_3 {
    char pad0[0xb];
    unsigned char unknown_b_;
    char unknown_c_[0x40 - 0xc];
    Struct_ov017_021a4e88_2* zones;
    char unknown_44_[0x5c - 0x44];
    Struct_ov017_021a4e88* shape;
};

struct Struct_ov017_021a4e88_4 {
    unsigned int flags;
};

struct Obj021a4e88 {
    char pad0[0x44];
    Type_ov017_021a4e88 pos;
    Type_ov017_021a4e88 rot;
};

struct Struct_ov017_021a4e88_6 {
#if defined(jpn)
    char pad0[0x3e60];
#else
    char pad0[0x4080];
#endif
    int busy;
};

extern "C" void* func_0203cf4c(void);
extern "C" void __clear(void* p, int n);
struct Struct_0203dce4_2;
extern "C" Struct_ov017_021a4e88_4* func_0203dce4(Struct_0203dce4_2*, int);
extern "C" void func_02040648(unsigned int*);
extern "C" void func_02040658(unsigned int*);
extern "C" void func_02040bcc(char*);
struct Struct_0203de84;
struct Node020406f8;
extern "C" void func_020406f8(Struct_0203de84* out, Node020406f8* n);
struct Struct_0203e0a0;
extern "C" Struct_ov017_021a4e88_3* func_02040538(Struct_0203e0a0*);
extern "C" Struct_ov017_021a4e88_4* func_0203df78(void* list, int key);
extern "C" int GameObject_IsGesturing(signed char*);
struct Vec3;
extern "C" short func_ov017_021a4700(Vec3*, int, Vec3*);
extern "C" unsigned char* func_02040528(int*);
int fix32abs(int x);

static inline short inline_ov017_021a4e88(Type_ov017_021a4e88* pos, int base, Struct_ov017_021a4e88_4* e) {
    Type_ov017_021a4e88 cur;
    func_020406f8((Struct_0203de84*)&cur, (Node020406f8*)e);
    return func_ov017_021a4700((Vec3*)pos, base, (Vec3*)&cur);
}

// USA: func_ov017_021a4e88
extern "C" ARM int func_ov017_021a4e88(int arg0, unsigned short* arg1) {
    GameState* gs = GameState::GetInstance();
    void* list = func_0203cf4c();
    Struct_ov017_021a4e88_6* res = (Struct_ov017_021a4e88_6*)GetGameResources();
    Obj021a4e88* obj = (Obj021a4e88*)gs->GetLeader();
    if (obj == NULL) {
        return -1;
    }
    Type_ov017_021a4e88 pos = obj->pos;
    Type_ov017_021a4e88 rot = obj->rot;
    int result = -1;
    int bestAngle = 0x3244;
    int range = 0x1c00;
    unsigned short ids[0x20];
    __clear(ids, sizeof(ids));
    int var10 = -1;
    short best = 0x3244;
    for (int i = 0; i < 0x20; i++) {
        Struct_ov017_021a4e88_4* e = func_0203dce4((Struct_0203dce4_2*)list, i);
        if (e == NULL) {
            continue;
        }
        func_02040648((unsigned int*)e);
        int hidden;
        if (e->flags & 0x40000) {
            hidden = 1;
        } else {
            hidden = 0;
        }
        e->flags &= ~0x40000;
        Type_ov017_021a4e88 var15 = ((Type_ov017_021a4e88 (*)(Struct_ov017_021a4e88_4*))func_020406f8)(e);
        int var16 = 0;
        int var17 = 0x1800;
        Struct_ov017_021a4e88_3* info = func_02040538((Struct_0203e0a0*)e);
        if (info != NULL) {
            if (info->shape != NULL) {
                Vector3fix_Add(&var15, &info->shape->center, &var15);
                var17 = info->shape->radius + 0x1000;
                range = info->shape->radius + 0x1400;
            }
            for (Struct_ov017_021a4e88_2* z = info->zones; z != NULL; z = z->next) {
                if (pos.x < z->maxX && pos.z < z->maxZ && pos.x > z->minX && pos.z > z->minZ) {
                    ids[i] = z->id;
                    var16 = 1;
                    break;
                }
            }
        }
        if (var16 == 0) {
            if (var17 < fix32abs(pos.x - var15.x)) {
                continue;
            }
            if (var17 < fix32abs(pos.z - var15.z)) {
                continue;
            }
        }
        if (hidden) {
            e->flags |= 0x40000;
        }
        func_02040658((unsigned int*)e);
        func_02040bcc((char*)e);
        if (info->unknown_b_ != 0) {
            Struct_ov017_021a4e88_4* link = func_0203df78(list, info->unknown_b_);
            if (link != NULL) {
                func_02040658((unsigned int*)link);
                func_02040bcc((char*)link);
                link->flags |= 0x20000;
            }
        }
        if ((e->flags & 0x200) || res->busy != 0) {
            continue;
        }
        if (GameObject_IsGesturing((signed char*)obj)) {
            continue;
        }
        int angle = (short)fix32abs(inline_ov017_021a4e88(&pos, (short)rot.y, e));
        if (angle > best) {
            continue;
        }
        if (var16) {
            result = i;
            var10 = i;
            best = angle;
            continue;
        }
        unsigned char* data = func_02040528((int*)e);
        if (arg0 == 0 || data[2] == 1) {
            continue;
        }
        if (Vector3fix_Distance(&pos, &var15) < range && angle < 0x3244 && angle < bestAngle) {
            bestAngle = angle;
            result = i;
            var10 = i;
            best = angle;
        }
    }
    if (var10 >= 0) {
        *arg1 = ids[var10];
    }
    return result;
}
