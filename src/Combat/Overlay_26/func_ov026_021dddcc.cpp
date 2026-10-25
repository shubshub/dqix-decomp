#if defined(jpn)
#define data_ov026_021de7fa data_ov026_021ded16
#define data_ov026_021de802 data_ov026_021ded1e
#define data_ov026_021de812 data_ov026_021ded2e
#define data_ov026_021de822 data_ov026_021ded3e
#define data_ov026_021def00 data_ov026_021df660
#define func_ov000_02171ffc func_ov000_02173834
#endif
#include <globaldefs.h>

struct GameState;
struct Struct_ov000_02161e30;
struct Struct_ov026_021d8ba0_4;
struct Struct_02015ef4_2;

struct Struct_ov026_021dddcc {
    int unknown_0_[3];
};

struct Struct_ov026_021de6cc {
    short unknown_0_[4];
};

struct Struct_ov026_021de802 {
    short unknown_0_[8];
};

struct Struct_ov026_021d8ba0_6 {
    char unknown_0_[0x10];
    signed char unknown_10_[8];
    signed char unknown_18_;
    char unknown_19_[0x3];
    signed char unknown_1c_;
    signed char unknown_1d_;
    char unknown_1e_[0x10];
    signed char unknown_2e_;
};

struct Struct_ov000_0215ab88 {
    char unknown_0_[0x4];
    short unknown_4_;
    char unknown_6_[0x3e];
    Struct_ov026_021dddcc unknown_44_;
};

struct Struct_ov026_021dddcc_2 {
    char unknown_0_[0x80];
    unsigned short unknown_80_;
    char unknown_82_[0x6];
};

struct Struct_ov000_02160da0 {
    #if defined(jpn)
    char unknown_0_[0x218];
#else
    char unknown1_0_[0x29c];
#endif
    Struct_ov000_02161e30* unknown_29c_;
    char unknown_2a0_[0xc08];
    int unknown_ea8_;
    int unknown_eac_;
    #if defined(jpn)
    char unknown_e2c_[0x28f0];
#else
    char unknown_eb0_[0x28b0];
#endif
    char unknown_3760_[0x17c];
    int unknown_38dc_;
    #if defined(jpn)
    char unknown_389c_[0x1f54];
#else
    char unknown_38e0_[0x1d20];
#endif
    Struct_ov026_021dddcc_2 unknown_5600_[2];
    char unknown_5710_[0x2002];
    signed char unknown_7712_;
};

struct Struct_ov026_021def00 {
    float unknown_0_;
    float unknown_4_;
};

extern "C" {
GameState* _ZN9GameState11GetInstanceEv();
Combatant* _ZN9GameState21GetPartyMemberByIndexEi(GameState* gs, int index);
unsigned char* _Z24GetFieldAt0x150_02053c6cPh(unsigned char* obj);
char* _Z24GetData02109dcc_020a6084v();
SlotWork* _Z21FindSlotById_021dae60P18Container_021dae60i(Container_021dae60* list, int id);
int _Z29HasAnyFlags_021719f8_021719f8Pi(int* obj);
int _Z40GetClampedArrayField0xd1c_ov000_021761c8Pci(char* base, int index);
int _Z40GetClampedArrayField0xd3c_ov000_021761ecPci(char* base, int index);
Combatant* _Z34GetCombatantWithFlag0x400_0200fea4P9GameStatei(GameState* gs, int id);
void* _ZN9GameState9GetCameraEv(GameState* gs); // GameState::GetCamera()
int _ZNK8Object3D9GetHeightEv(Combatant* obj);
int _Z20Camera_WorldToScreenPvP16Vec3copy0202ec84PiS2_(void* obj, Pos3* src, int* out1, int* out2);
void _Z25RenderFlaggedIndexedEntryP16StructAt020473c8i(IconSprite* obj, int param1);
void Vector3fix_Add(const Pos3* a, const Pos3* b, Pos3* out);
void Vector3fix_Normalize(const Pos3* in, Pos3* out);
int func_ov000_0217fd60(void* list, int id);
int func_ov000_0215e9fc(BattleState* battle, short* out, int max, int flag);
int func_ov000_0215eb1c(BattleState* battle, short* out, int max, int flag);
int func_ov000_02153e78(BattleState* battle, short* out, int max, int group, int flag);
int func_ov000_02171ffc(SlotWork* slot);
double func_02009424(double x);
void __clear(void* dst, int size);
}

extern Struct_ov026_021de6cc data_ov026_021de7fa;
extern Struct_ov026_021de802 data_ov026_021de802;
extern Struct_ov026_021de802 data_ov026_021de812;
extern Struct_ov026_021de802 data_ov026_021de822;
extern Struct_ov026_021def00 data_ov026_021def00;

#define IN_RANGE(x) (((x) >= 0 && (x) <= 3) ? 1 : 0)

static inline void inline_ov026_021dddcc() {
    *(volatile int*)0x04000444 = 0;
}

static inline void inline_ov026_021dddcc_2(int arg0) {
    *(volatile int*)0x04000448 = arg0;
}

static inline void inline_ov026_021dddcc_3(int arg0, int arg1, int arg2) {
    *(volatile int*)0x04000470 = arg0;
    *(volatile int*)0x04000470 = arg1;
    *(volatile int*)0x04000470 = arg2;
}

// USA: func_ov026_021dddcc
extern "C" ARM void func_ov026_021dddcc(Struct_ov000_02160da0* arg0) {
    Struct_ov026_021de802 var0;
    short var1[8];
    short var2[8];
    unsigned short var3[4];
    Struct_ov026_021de6cc var4;
    short var5[4];
    GameState* var6 = _ZN9GameState11GetInstanceEv();
    Struct_ov000_02161e30* var7 = arg0->unknown_29c_;
    char* var8;
    signed char var9;
    int var10;
    int var11;
    int var12;
    int var13;
    int var14;

    if (arg0->unknown_ea8_ != 7 || arg0->unknown_eac_ != 4) {
        return;
    }
    if (func_ov000_0217fd60(arg0->unknown_3760_, -1) == 0) {
        return;
    }
    if (arg0->unknown_7712_ != 0) {
        return;
    }

    __clear(var3, sizeof(var3));
    var8 = func_020a6084();
    for (var9 = 0; var9 < 4; var9++) {
        Struct_ov000_0215ab88* var15 = _ZN9GameState21GetPartyMemberByIndexEi(var6, var9);
        if (var15 != 0) {
            unsigned char* var16 = func_02053c6c((unsigned char*)var15);
            if (var16 != 0) {
                var3[var9] = *(unsigned short*)(var8 + var16[0x56a] * 0x20 + 0x1e);
            }
        }
    }

    var4 = data_ov026_021de7fa;
    var10 = func_ov000_0215e9fc(var7, var4.unknown_0_, 4, 0);
    var0 = data_ov026_021de802;
    var11 = func_ov000_0215eb1c(var7, var0.unknown_0_, 8, 1);
    __clear(var5, sizeof(var5));
    __clear(var1, sizeof(var1));
    __clear(var2, sizeof(var2));

    for (var12 = 0; var12 < var10; var12++) {
        int var17 = var4.unknown_0_[var12];
        Struct_ov026_021d8ba0_6* var18 = func_ov026_021dae60((Struct_ov026_021d8ba0_4*)arg0->unknown_3760_, var17);
        int var19;
        int var20;
        int var21;
        if (var18 == 0) continue;
        if (func_ov000_021719f8((int*)var18) != 0) continue;
        if (var18->unknown_1c_ == 6) continue;
        var19 = 0;
        if (var18->unknown_2e_ >= 0) {
            var19 = var18->unknown_2e_ <= 3;
        }
        if (var19) continue;
        if (var18->unknown_10_[var18->unknown_18_] != 0xe && var18->unknown_10_[var18->unknown_18_] != 0x64) continue;
        var21 = var18->unknown_1d_;
        if (var21 < 0) continue;
        var20 = func_ov000_021761c8(arg0->unknown_3760_, var21);
        var21 = func_ov000_021761ec(arg0->unknown_3760_, var21);
        switch (func_ov000_02171ffc(var18)) {
        case 3:
            var5[var12] = var11;
            if (var17 != arg0->unknown_38dc_) {
                int var22;
                for (var22 = 0; var22 < var11; var22++) {
                    int var23 = var0.unknown_0_[var22] - 0xc0;
                    if (var23 >= 0 && var23 < 8) {
                        var1[var23]++;
                    }
                }
            }
            break;
        case 4: {
            Struct_ov026_021de802 var24;
            var24 = data_ov026_021de812;
            var5[var12] = func_ov000_02153e78(var7, var24.unknown_0_, 8, var20, 1);
            if (var17 != arg0->unknown_38dc_) {
                int var25;
                for (var25 = 0; var25 < var5[var12]; var25++) {
                    int var26 = var24.unknown_0_[var25] - 0xc0;
                    if (var26 >= 0 && var26 < 8) {
                        var1[var26]++;
                    }
                }
            }
            break;
        }
        case 2:
            if (IN_RANGE(var21)) continue;
            var5[var12] = 1;
            if (var17 != arg0->unknown_38dc_) {
                int var27 = var21 - 0xc0;
                if (var27 >= 0 && var27 < 8) {
                    var1[var27]++;
                }
            }
            break;
        }
    }

    for (var13 = 0; var13 < 8; var13++) {
        var2[var13] = var1[var13] * -5;
    }

    data_ov026_021def00.unknown_4_ += 0.1f;
    if (6.28f < data_ov026_021def00.unknown_4_) {
        data_ov026_021def00.unknown_4_ -= 6.28f;
    }
    {
        float var28 = data_ov026_021def00.unknown_4_;
        if (6.28f < var28) {
            var28 -= 6.28f;
        }
        data_ov026_021def00.unknown_0_ = func_02009424((double)(var28));
    }

    for (var14 = 0; var14 < var10; var14++) {
        unsigned char var29;
        int var30 = var4.unknown_0_[var14];
        var29 = 0;
        Struct_ov026_021d8ba0_6* var31 = func_ov026_021dae60((Struct_ov026_021d8ba0_4*)arg0->unknown_3760_, var30);
        int var32;
        int var33;
        int var34;
        int var35;
        short var36;
        int var37;
        if (var31 == 0) continue;
        if (func_ov000_021719f8((int*)var31) != 0) continue;
        if (var31->unknown_1c_ == 6) continue;
        var32 = 0;
        if (var31->unknown_2e_ >= 0) {
            var32 = var31->unknown_2e_ <= 3;
        }
        if (var32) continue;
        if (var31->unknown_10_[var31->unknown_18_] != 0xe && var31->unknown_10_[var31->unknown_18_] != 0x64) continue;
        var33 = var31->unknown_1d_;
        if (var33 < 0) continue;
        var34 = func_ov000_021761c8(arg0->unknown_3760_, var33);
        var33 = func_ov000_021761ec(arg0->unknown_3760_, var33);
        var35 = func_ov000_02171ffc(var31);
        Struct_ov026_021de802 var38;
        var38 = data_ov026_021de822;
        var36 = 0;
        switch (var35) {
        case 3:
            var36 = func_ov000_0215eb1c(var7, var38.unknown_0_, 8, 1);
            if (var36 == 0) continue;
            break;
        case 4:
            var29 = 1;
            var36 = func_ov000_02153e78(var7, var38.unknown_0_, 8, var34, var29);
            if (var36 == 0) continue;
            break;
        case 2:
            if (IN_RANGE(var33)) continue;
            var38.unknown_0_[0] = var33;
            var36 = 1;
            break;
        }
        for (j = 0; j < count; j++) {
            Combatant* c = _Z34GetCombatantWithFlag0x400_0200fea4P9GameStatei(gs, targets.v[j]);
            int e;
            if (c == 0) continue;
            e = c->id - 0xc0;
            if (e < 0) continue;
            if (e >= 8) continue;
            if (id == self->activeSlot) {
                Pos3 dir;
                Pos3 shake;
                Pos3 pos;
                int x, y;
                int dy;
                void* view;
                IconSprite* spr;
                dir.v[1] = 1;
                dir.v[0] = 1;
                dir.v[2] = 0;
                Vector3fix_Normalize(&dir, &shake);
                shake.v[0] = (float)shake.v[0] * (0.2f * data_ov026_021def00.value);
                shake.v[1] = (float)shake.v[1] * (0.2f * data_ov026_021def00.value);
                view = _ZN9GameState9GetCameraEv(gs);
                pos = c->pos;
                pos.v[1] += _ZNK8Object3D9GetHeightEv(c);
                Vector3fix_Add(&pos, &shake, &pos);
                _Z20Camera_WorldToScreenPvP16Vec3copy0202ec84PiS2_(view, &pos, &x, &y);
                dy = 0x18;
                if (grouped != 0) {
                    if (target == targets.v[j]) {
                        dy = 0x20;
                    }
                }
                var48 = &arg0->unknown_5600_[0];
                var48->unknown_80_ = var3[var30];
                inline_ov026_021dddcc();
                inline_ov026_021dddcc_3((var44 + var2[var40]) << 12, (var45 + 3 - var46) << 12, 0x1000);
                func_020473c8(var48, 1);
                inline_ov026_021dddcc_2(1);
            } else {
                Pos3 dir;
                Pos3 shake;
                Pos3 pos;
                int x, y;
                void* view;
                IconSprite* spr;
                dir.v[1] = 1;
                dir.v[2] = 0;
                dir.v[0] = 0;
                Vector3fix_Normalize(&dir, &shake);
                shake.v[0] = 0;
                shake.v[1] = 0;
                view = _ZN9GameState9GetCameraEv(gs);
                pos = c->pos;
                pos.v[1] += _ZNK8Object3D9GetHeightEv(c);
                Vector3fix_Add(&pos, &shake, &pos);
                _Z20Camera_WorldToScreenPvP16Vec3copy0202ec84PiS2_(view, &pos, &x, &y);
                spr = &self->icons[1];
                spr->icon = icons[id];
                G3_PushMtx();
                G3_Translate((x + offs[e]) << 12, (y - 0x18) << 12, 0);
                _Z25RenderFlaggedIndexedEntryP16StructAt020473c8i(spr, 1);
                G3_PopMtx(1);
            }
            var2[var40] += 10;
        }
    }
}
