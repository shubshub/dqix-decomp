#if defined(jpn)
enum { Enum_ov017_02197a64_108 = 0x8c };
#else
enum { Enum_ov017_02197a64_108 = 0x6c };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "Graphics/Vector.h"
#include "Input/Input.h"

struct Struct_020968d0;

struct Struct_ov017_02197a64_2 {
    unsigned char unknown_0_[0x8];
    Vector3fix unknown_8_;
    unsigned char unknown_14_[0x20 - 0x14];
    short unknown_20_;
    unsigned char unknown_22_[0x2e - 0x22];
    unsigned short unknown_2e_0_ : 4;
    unsigned short unknown_2e_4_ : 12;
    unsigned char unknown_30_[0x70 - 0x30];
    struct Struct_ov017_02197a64_2* unknown_70_;
};

struct Struct_ov017_02197a64_3 {
    unsigned char unknown_0_[0x44];
    Vector3fix unknown_44_;
    unsigned char unknown_50_[0x54 - 0x50];
    int unknown_54_;
    unsigned char unknown_58_[0xbe - 0x58];
    unsigned char unknown_be_;
};

struct Struct_ov017_02197a64_4 {
#if defined(jpn)
    unsigned char unknown_0_[0x4188];
#else
    unsigned char unknown1_0_[0x4438];
#endif
    Vector3fix unknown_4438_;
};

struct Struct_ov017_02197a64_5 {
#if defined(jpn)
    unsigned char unknown_0_[0x40cc];
#else
    unsigned char unknown1_0_[0x42ec];
#endif
    short unknown_42ec_;
};

struct Struct_ov017_02197a64 {
    unsigned char unknown_0_;
    unsigned char unknown_1_[3];
    unsigned char unknown_4_;
    unsigned char unknown_5_[3];
    struct Struct_ov017_02197a64_2* unknown_8_[2];
    short unknown_10_;
    short unknown_12_;
};

extern "C" void* Zone3D_GetInstance(void);
void* ZoneFeatures_GetFirstOfType(unsigned char* obj, unsigned int index);
Obj020968d0* GameResources_GetTouchWalk(void* res);
void InitObj0219a674(unsigned char* self);
extern "C" int func_02094b9c(void* a, void* b);
int BuildAndForwardVec_0218da48(void* obj, int angle, int c, int d, unsigned char e);
int CheckAndComputeDistance020968d0(Obj020968d0* obj, int* outDist);
extern "C" void __clear(void* buf, int count);
struct Vec3;
short GetAbsAngleDeltaBetween_021a4754(Vector3fix*, int, Vector3fix*);
extern "C" void func_ov017_0219b33c(Self02197a64* self, GroupEvent02197a64* event);
extern "C" void func_ov017_02198f84(Self02197a64* self);

#define FACING_LIMIT ((int)(0.8f * 4096.0f))

// USA: func_ov017_02197a64
extern "C" ARM void func_ov017_02197a64(Self02197a64* self) {
    GameState* gs = GameState::GetInstance();
    Resources02197a64* res = (Resources02197a64*)GetGameResources();
    void* cache = Zone3D_GetInstance();
    Leader02197a64* leader = (Leader02197a64*)gs->GetLeader();
    Vector3fix filter = leader->position;
    GroupNode02197a64* node = (GroupNode02197a64*)ZoneFeatures_GetFirstOfType((unsigned char*)cache + RegionOffset6c, 2);
    Obj020968d0* field = GameResources_GetTouchWalk(res);
    int notify = 0;
    GroupEvent02197a64 event;
    InitObj0219a674((unsigned char*)&event);
    int counted = 0;
    int built = 0;

    while (var5 != NULL && var8.unknown_4_ < 2) {
        if (!(var5->unknown_2e_4_ & 1) && !(var5->unknown_2e_4_ & 4) && func_02094b9c(var5, &var4)) {
            if (!var10) {
                var10 = func_ov017_0218da48(arg0, var5->unknown_20_, FACING_LIMIT, FACING_LIMIT >> 3, 0);
            }
            Vector3fix dir;
            int c = fix32cos(node->angle);
            dir.x = fix32sin(node->angle);
            dir.y = 0;
            dir.z = c;
            Vector3fix_Normalize(&dir, &dir);
            Vector3fix fwd;
            c = fix32cos(leader->rotationY);
            fwd.x = fix32sin(leader->rotationY);
            fwd.y = 0;
            fwd.z = c;
            Vector3fix_Normalize(&fwd, &fwd);
            Vector3fix heading = res->heading;
            int facing = Vector3fix_InnerProduct(&dir, &fwd);
            int along = Vector3fix_InnerProduct(&dir, &heading);
            if ((heading.x != 0 || heading.z != 0) &&
                (CheckAndComputeDistance020968d0(field, NULL) != 0 || g_keyManager.TestKeysHeld(KEY_DPAD) != 0)) {
                facing = along;
            }
            if (var5->unknown_2e_4_ & 0x10) {
                Vector3fix var17;
                Vector3fix_Subtract(&var4, &var5->unknown_8_, &var17);
                var17.y = 0;
                Vector3fix_Normalize(&var17, &var17);
                if (Vector3fix_InnerProduct(&var11, &var17) > 0) {
                    if (var15 >= 0) {
                        var5 = var5->unknown_70_;
                        continue;
                    }
                } else {
                    if (var15 <= 0) {
                        var5 = var5->unknown_70_;
                        continue;
                    }
                }
            } else {
                if (var15 > 0) {
                    var5 = var5->unknown_70_;
                    continue;
                }
            }
            var8.unknown_8_[var8.unknown_4_++] = var5;
            if (arg0->unknown_42ec_ <= 2) {
                if (var3->unknown_be_ == 1 &&
                    (var16 < 0x170 - FACING_LIMIT || var16 > FACING_LIMIT - 0x170 ||
                     var15 < 0x170 - FACING_LIMIT || var15 > FACING_LIMIT - 0x170)) {
                    if (!var9) {
                        var9 = 1;
                        arg0->unknown_42ec_++;
                    }
                } else {
                    arg0->unknown_42ec_ = 0;
                }
            } else if (arg0->unknown_42ec_ > 2) {
                if (!var9) var7 = 1;
            }
        }
        var5 = var5->unknown_70_;
    }

    if (var8.unknown_4_ != 0) {
        Vector3fix var18;
        __clear(&var18, sizeof(var18));
        for (int var19 = 0; var19 < var8.unknown_4_; var19++) {
            Vector3fix_Add(&var18, &var8.unknown_8_[var19]->unknown_8_, &var18);
        }
        Vector3fixDivideScalar(&var18, var8.unknown_4_ << 12, &var18);
        var8.unknown_10_ = func_ov017_021a4754(&var3->unknown_44_, (short)var3->unknown_54_, &var18);
        var8.unknown_0_ = 4;
        func_ov017_0219b33c(arg0, &var8);
    }
    if (var7) {
        func_ov017_02198f84(arg0);
    }
}
