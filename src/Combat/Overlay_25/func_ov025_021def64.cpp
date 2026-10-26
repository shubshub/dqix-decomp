#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_02049c08_2;
struct Struct_02033834;
struct Struct_ov025_021def64;

struct Struct_ov025_021def64_2 {
    int unknown_0_;
    struct Struct_ov025_021def64_2* unknown_4_;
    struct Struct_ov025_021def64_2* unknown_8_;
    GameObject* unknown_c_;
};

int DispatchByIndex021820bc(void* obj, int unused, int index, int arg);
Vector3fix GetSubTriple02049c08(struct Obj02049c08* obj);
void GameObject_SnapFacing(struct Obj02033874* obj, int arg);
void ResetFields_021df554(void* obj);
struct Node021df568* InsertSorted_021df568(struct Node021df568* head, struct Node021df568* newNode);
struct Node021df5cc* FindLastNode021df5cc(struct Node021df5cc* node);
extern "C" fix32_t fix32_Divide(fix32_t a, fix32_t b);

static inline int inline_02061c04_5(int arg0, int arg1) { return (int)(((long long)arg0 * arg1 + 0x800) >> 12); }

struct Struct_ov025_021def64_3 {
#if defined(jpn)
    char unknown_0_[0x218];
#else
    char unknown1_0_[0x29c];
#endif
    void* unknown_29c_;
};

// USA: func_ov025_021def64
extern "C" ARM void func_ov025_021def64(struct Struct_ov025_021def64_3* arg0, int arg1, int arg2) {
    struct Struct_ov025_021def64_2 var0[16];
    struct Struct_ov025_021def64_2 var1[16];
    int var2[16];
    GameObject* var3[16];
    GameState* var4 = GameState::GetInstance();
    int var5 = func_ov000_021820bc(arg0->unknown_29c_, arg1, arg2, (int)var2);
    if (var5 == 0) return;

    int n = 0;
    int i;
    for (i = 0; i < count; i++) {
        objs[n] = gs->GetCombatantByIndex(ids[i]);
        if (objs[n] == NULL) continue;
        GameObject* o = objs[i];
        o->obj3D_.position_ = GetSubTriple02049c08((struct Obj02049c08*)o);
        GameObject_SnapFacing((struct Obj02033874*)o, 0);
        n++;
    }
    var5 = var6;

    {
        int var9;
        int var10;
        int var11;
        struct Struct_ov025_021def64_2* var12;
        struct Struct_ov025_021def64_2* var13;
        fix32_t var14;
        int var15;
        int var16;
        int var17;
        struct Struct_ov025_021def64_2* var18;
        struct Struct_ov025_021def64_2* var19;
        int var20;
        int var21;
        for (var7 = 0; var7 < var5; var7++) {
            func_ov025_021df554(&var0[var7]);
            GameObject* var22 = var3[var7];
            var0[var7].unknown_0_ = func_02049c08((struct Struct_02049c08_2*)var22).x;
            var0[var7].unknown_c_ = var22;
        }
        var12 = &var0[0];
        for (var21 = 1; var21 < var5; var21++) {
            var12 = func_ov025_021df568(var12, &var0[var21]);
        }
        var19 = (struct Struct_ov025_021def64_2*)func_ov025_021df5cc((struct Struct_ov025_021def64*)var12);
        var20 = (var19->unknown_0_ + var19->unknown_c_->obj3D_.GetRadius() / 2) - (var12->unknown_0_ - var12->unknown_c_->obj3D_.GetRadius() / 2);
        if (var20 > 0x4000 && var6 > 1) {
            int var23[16];
            var10 = 0;
            var11 = 0;
            var18 = var12;
            var9 = 0;
            for (; (var13 = var18->unknown_8_) != NULL; var18 = var18->unknown_8_) {
                var16 = var18->unknown_c_->obj3D_.GetRadius();
                var17 = (var13->unknown_0_ - var18->unknown_0_) - (var13->unknown_c_->obj3D_.GetRadius() / 2 + var16 / 2);
                var23[var9] = var17;
                var10 += var17;
                var9++;
            }
            for (var18 = var12; var18 != NULL; var18 = var18->unknown_8_) {
                var11 += var18->unknown_c_->obj3D_.GetRadius();
            }
            var14 = 0;
            if (var11 < 0x4000 && var10 != 0) {
                var14 = fix32_Divide(0x4000 - var11, var10);
            }
            var9 = 0;
            var18 = var12;
            var10 = 0;
            while ((var18 = var18->unknown_8_) != NULL) {
                var23[var9] = inline_02061c04_5(var23[var9], var14);
                var10 += var23[var9];
                var9++;
            }
            var15 = -((var11 + var10) / 2);
            var9 = 0;
            for (var18 = var12; var18 != NULL; var18 = var18->unknown_8_, var9++) {
                var15 += var18->unknown_c_->obj3D_.GetRadius() / 2;
                Vector3fix var24 = var18->unknown_c_->obj3D_.position_;
                var24.x = var15;
                var18->unknown_0_ = var15;
                var18->unknown_c_->obj3D_.position_ = var24;
                var15 += var18->unknown_c_->obj3D_.GetRadius() / 2;
                var15 += var23[var9];
            }
        } else {
            int var25 = -((var12->unknown_0_ - var12->unknown_c_->obj3D_.GetRadius() / 2) + var20 / 2);
            for (; var12 != NULL; var12 = var12->unknown_8_) {
                Vector3fix var26 = var12->unknown_c_->obj3D_.position_;
                var26.x += var25;
                var12->unknown_c_->obj3D_.position_ = var26;
            }
        }
    }

    {
        int var27;
        int var28;
        int var29;
        struct Struct_ov025_021def64_2* var30;
        struct Struct_ov025_021def64_2* var31;
        int var32;
        struct Struct_ov025_021def64_2* var33;
        fix32_t var34;
        int var35;
        int var36;
        int var37;
        struct Struct_ov025_021def64_2* var38;
        int var39;
        for (var7 = 0; var7 < var5; var7++) {
            func_ov025_021df554(&var1[var7]);
            GameObject* var40 = var3[var7];
            var1[var7].unknown_0_ = func_02049c08((struct Struct_02049c08_2*)var40).z;
            var1[var7].unknown_c_ = var40;
        }
        var30 = &var1[0];
        for (var39 = 1; var39 < var5; var39++) {
            var30 = func_ov025_021df568(var30, &var1[var39]);
            for (struct Struct_ov025_021def64_2* var41 = var30; var41 != NULL; var41 = var41->unknown_8_) {
            }
        }
        var31 = (struct Struct_ov025_021def64_2*)func_ov025_021df5cc((struct Struct_ov025_021def64*)var30);
        var32 = (var31->unknown_0_ + var31->unknown_c_->obj3D_.GetRadius() / 2) - (var30->unknown_0_ - var30->unknown_c_->obj3D_.GetRadius() / 2);
        if (var32 > 0x4000 && var6 > 1) {
            int var42[16];
            var28 = 0;
            var29 = 0;
            var38 = var30;
            var27 = 0;
            for (; (var33 = var38->unknown_8_) != NULL; var38 = var38->unknown_8_) {
                var36 = var38->unknown_c_->obj3D_.GetRadius();
                var37 = (var33->unknown_0_ - var38->unknown_0_) - (var33->unknown_c_->obj3D_.GetRadius() / 2 + var36 / 2);
                var42[var27] = var37;
                var28 += var37;
                var27++;
            }
            for (var38 = var30; var38 != NULL; var38 = var38->unknown_8_) {
                var29 += var38->unknown_c_->obj3D_.GetRadius();
            }
            var34 = 0;
            if (var29 < 0x4000 && var28 != 0) {
                var34 = fix32_Divide(0x4000 - var29, var28);
            }
            var27 = 0;
            var38 = var30;
            var28 = 0;
            while ((var38 = var38->unknown_8_) != NULL) {
                var42[var27] = inline_02061c04_5(var42[var27], var34);
                var28 += var42[var27];
                var27++;
            }
            var35 = -((var29 + var28) / 2);
            var27 = 0;
            for (var38 = var30; var38 != NULL; var38 = var38->unknown_8_) {
                var35 += var38->unknown_c_->obj3D_.GetRadius() / 2;
                Vector3fix var43 = var38->unknown_c_->obj3D_.position_;
                var43.z = var35;
                var38->unknown_0_ = var35;
                var38->unknown_c_->obj3D_.position_ = var43;
                var35 += var38->unknown_c_->obj3D_.GetRadius() / 2;
                var35 += var42[var27];
                var27++;
            }
        } else {
            int var44 = -((var30->unknown_0_ - var30->unknown_c_->obj3D_.GetRadius() / 2) + var32 / 2);
            for (; var30 != NULL; var30 = var30->unknown_8_) {
                Vector3fix var45 = var30->unknown_c_->obj3D_.position_;
                var45.z += var44;
                var30->unknown_c_->obj3D_.position_ = var45;
            }
        }
    }
}
