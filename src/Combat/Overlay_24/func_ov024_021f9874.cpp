#include <globaldefs.h>

#include "std_library_functions.h"
#include "Combat/Main/BattleList.h"
#include "Combat/Overlay_0/GetCombatantByID.h"

struct Struct_ov024_021f9874_4 {
    unsigned char weight : 6;
    unsigned char flag : 1;
    unsigned char sel : 1;
};

struct Struct_ov024_021f9874_6 {
    float value;
    unsigned char subtype;
    unsigned char enabled;
    unsigned char slot;
    unsigned char unknown_7_;
    unsigned char kind;
    struct Struct_ov024_021f9874_4 unknown_9_;
    char pad[2];
};

struct Struct_ov024_021f9874_7 {
    unsigned short f0;
    signed char f2;
    unsigned char f3;
    float value;
    unsigned short f8;
    unsigned char fa;
    unsigned char fb;
};

struct Struct_ov024_021f9874_8 {
    struct Struct_ov024_021f9874_6 entries[16];
    int count;
    float threshold;
};

struct Struct_ov024_021f9874_9 {
    char pad[4];
    unsigned int code : 12;
    unsigned int rest : 20;
    char pad2[0xc];
    unsigned int unknown_14_0_ : 28;
    unsigned int unknown_17_4_ : 4;
};

struct Struct_ov024_021f9874 {
    unsigned short f0;
    signed char f2;
    unsigned char f3;
};

struct Struct_ov024_021f9874_2 {
    unsigned int lo4 : 4;
    unsigned int unknown_0_4_ : 5;
    unsigned int rest : 23;
};

struct Struct_ov024_021f9874_3 {
    int f0;
    char pad04[2];
    unsigned char unknown_6_;
    char unknown_7_[1];
    GameObject* f8;
    char unknown_c_[8];
    unsigned char f14;
    char pad15[0x17];
    unsigned char unknown_2c_;
    char unknown_2d_[3];
    float unknown_30_;
    unsigned char f34;
    char unknown_35_[3];
    int unknown_38_;
    int f3c;
    unsigned char f40;
    char unknown_41_[3];
    float unknown_44_[4];
    unsigned char unknown_54_[0x28];
    GameObject* combatantList[8];
    int f9c;
    char unknown_a0_[0x24];
    int arrC4[25];
    int f128;
    char unknown_12c_[4];
    int f130;
    char unknown_134_[5];
    unsigned char unknown_139_;
    char unknown_13a_[0x32];
    int unknown_16c_;
    char unknown_170_[0x238];
    struct Struct_ov024_021f9874_7 unknown_3a8_[4];
    struct Struct_ov024_021f9874_7 unknown_3d8_[4];
    struct Struct_ov024_021f9874_7 unknown_408_[4];
    struct Struct_ov024_021f9874_7 unknown_438_[4];
    char unknown_468_[0x30];
    struct Struct_ov024_021f9874_7 unknown_498_[4];
    struct Struct_ov024_021f9874_7 unknown_4c8_[4];
    char unknown_4f8_[0x30];
    struct Struct_ov024_021f9874_7 unknown_528_[4];
    struct Struct_ov024_021f9874_7 unknown_558_[4];
    struct Struct_ov024_021f9874_7 unknown_588_[4];
    struct Struct_ov024_021f9874_7 unknown_5b8_[4];
    char unknown_5e8_[0x60];
    struct Struct_ov024_021f9874* unknown_648_;
    struct Struct_ov024_021f9874_9* unknown_64c_;
    int unknown_650_;
    char unknown_654_[1];
    unsigned char unknown_655_;
};

struct Struct_ov024_021f9874_5 {
    char pad0[2];
    unsigned char any;
    char pad1[2];
    unsigned char unknown_5_;
    unsigned char unknown_6_;
    unsigned char unknown_7_;
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    char pad2[2];
};

extern "C" void* __clear(void* dst, int size);
extern "C" void func_ov024_021f6830(void* arr, struct Struct_ov024_021f9874_7* item);
extern "C" int func_02053c6c(unsigned char* obj);
extern "C" int func_ov024_021eadfc(GameObject* combatant);

static inline unsigned short inline_ov024_021dc700(GameObject* c) { return c->currentStats_->primaryStats.maxHP; }
static inline unsigned short inline_ov024_021dc540_2(GameObject* c) { return c->currentStats_->primaryStats.maxMP; }
static inline unsigned short inline_ov000_0215cd44_2(GameObject* c) { return c->currentStats_->primaryStats.currMP; }
static inline unsigned int inline_ov024_021f9874(GameObject* c) { return c->baseStats_->primaryStats.defense; }

extern unsigned char data_ov024_021ffc98[12];
extern unsigned char data_ov024_021ffca4[33];
extern unsigned char data_ov024_021ffcc5[39];

// USA: func_ov024_021f9874
extern "C" ARM void func_ov024_021f9874(struct Struct_ov024_021f9874_3* obj, struct Struct_ov024_021f9874_8* buf, unsigned char p2, unsigned char p3) {
    char var0[0x38];
    int var1[8];
    float var2[8];
    struct Struct_ov024_021f9874_5 flags;
    float var4[14];
    float var5[8];
    int arrA[4];
    int arrB[4];
    float var8[4];
    struct Struct_ov024_021f9874_7 var9;
    float var10;
    float total;
    float v98;
    float v9c;
    float var14;
    float v94;
    float var16;
    int flagC;
    float var18;
    int var19;

    memset(var0, 0, 0x38);
    __clear(var1, 0x20);
    __clear(var2, 0x20);
    __clear(&flags, 0xe);
    __clear(var4, 0x38);
    __clear(var5, 0x20);
    __clear(arrA, 0x10);
    __clear(arrB, 0x10);

    flagC = 0;

    for (int i = 0; i < buf->count; i++) {
        struct Struct_ov024_021f9874_6* e = &buf->entries[i];
        if (e->kind != 0) continue;
        if (e->enabled == 0) continue;
        {
            int idx = e->slot;
            float v = e->value * e->unknown_9_.weight;
            if (obj->f34 != 0) v *= 1.2f;
            var2[idx] += v;
            if (var2[idx] >= obj->arrC4[idx]) var1[idx] = 10;
            flags.any = 1;
            if (e->unknown_9_.flag) flagC = 1;
        }
    }

    var19 = 0;
    if (obj->f14 != 0) {
        for (int i = 0; i < buf->count; i++) {
            struct Struct_ov024_021f9874_6* e = &buf->entries[i];
            if (e->kind != 2) continue;
            if (e->enabled == 0) continue;
            var5[e->slot] = 0.01f * e->unknown_7_;
            flags.any = 1;
            var19 = 1;
            if (e->unknown_9_.flag) flagC = 1;
        }
        if (var19) {
            float diff;
            int i;
            for (i = 0; i < buf->count; i++) {
                float var28;
                flags.any = 1;
                var28 = obj->arrC4[i];
                diff = var28 - var2[i];
                if (diff <= 0.0f) continue;
                {
                    float x = var5[i];
                    if (obj->unknown_6_ != 0) {
                        double var30 = x;
                        double var31 = 0.005 * (double)obj->unknown_650_;
                        x = (float)(var30 - var31);
                    }
                    {
                        float var32 = x * x;
                        float var33 = var32;
                        if (var32 > 0.9f) var33 = 0.9f;
                        var2[i] += diff * var33;
                    }
                }
            }
        }
    }

    for (int i = 0; i < buf->count; i++) {
        struct Struct_ov024_021f9874_6* e = &buf->entries[i];
        if (e->kind == 3) {
            if (e->enabled != 0) continue;
            arrA[e->slot] += e->value;
            flags.unknown_6_ = 1;
        }
        if (e->kind == 4 && e->enabled == 0) {
            arrB[e->slot] += e->value;
            flags.unknown_7_ = 1;
        }
    }

    var4[13] = obj->unknown_650_;
    if (obj->unknown_648_->f3 != 0) var4[13] += 30.0f;

    if (flags.any != 0) {
        float* var36 = var2;
        for (int i = 0; i < obj->f9c; i++) {
            float var38 = var36[i];
            int raw;
            if (var38 <= 0.0f) continue;
            raw = obj->arrC4[i];
            if (var38 >= raw) var38 = raw;
            var4[2] += 100.0f * var38 / inline_ov024_021dc700(obj->combatantList[i]);
        }
        if (obj->unknown_648_->f3 != 0 && obj->unknown_6_ != 0) var4[2] = 0.0f;
    }

    if (flags.unknown_6_ != 0) {
        for (int slot = 0; slot < 4; slot++) {
            int val = arrA[slot];
            if (val == 0) continue;
            {
                float var42 = 100.0f * val / inline_ov024_021dc700(GetCombatantByID(obj->f0, (short)slot));
                if (slot == obj->f128) var42 *= 2.0f;
                var4[6] += var42;
            }
        }
        if (obj->unknown_650_ != 0) {
            if (obj->unknown_648_->f0 == 0x310) {
                if (obj->f130 >= 2) var4[6] *= 0.66f;
                else var4[6] *= 0.55f;
                if (obj->unknown_139_ == 0) var4[6] = 0.0f;
            } else if (obj->unknown_648_->f0 == 0x21) {
                var4[6] *= 0.9f;
            }
        }
    }

    for (int i = 0; i < buf->count; i++) {
        struct Struct_ov024_021f9874_6* e = &buf->entries[i];
        if (e->kind == 5 && e->enabled == 0) {
            var4[5] += e->unknown_7_;
            flags.unknown_5_ = 1;
        }
    }

    if (obj->unknown_648_->f0 == 0x28) {
        flags.unknown_6_ = 1;
        var4[6] = 400.0f;
    }

    for (int i = 0; i < buf->count; i++) {
        struct Struct_ov024_021f9874_6* e = &buf->entries[i];
        int var47;

        var47 = 1;
        if (e->unknown_9_.sel) {
            var18 = 0.01f * obj->unknown_54_[obj->f3c];
            var47 = obj->f40;
        } else {
            var18 = 0.01f * obj->unknown_54_[obj->unknown_38_];
        }
        __clear(var8, 0x10);

        if (e->kind == 8) {
            if (e->enabled != 0) continue;
            var8[0] = 10.0f;
            {
                int t;
                for (t = 0; t < 6; t++) {
                    unsigned int val = data_ov024_021ffc98[t * 2 + 1];
                    if (e->subtype == data_ov024_021ffc98[t * 2]) var8[0] = val;
                }
            }
        } else if (e->kind == 7) {
            int idx;
            if (e->enabled != 0) continue;
            idx = e->slot;
            if (e->subtype == 0xd) {
                var8[1] = obj->unknown_16c_ * 13 / 100;
                if (e->subtype == 0x11 && obj->unknown_64c_->unknown_17_4_ == 2) {
                    if (idx >= 0 && idx < 4) var8[1] *= obj->unknown_44_[idx];
                }
            } else {
                int t;
                for (t = 0; t < 0xb; t++) {
                    int slot = data_ov024_021ffca4[t * 3 + 1];
                    unsigned int val = data_ov024_021ffca4[t * 3 + 2];
                    if (e->subtype != data_ov024_021ffca4[t * 3]) continue;
                    {
                        var8[slot] = val;
                        if (var47 == 0) var8[slot] = 0.0f;
                        if (e->subtype == 0x11 && obj->unknown_64c_->unknown_17_4_ == 2) {
                            if (idx >= 0 && idx < 4) var8[slot] *= obj->unknown_44_[idx];
                        }
                        if (e->value < 0.0f) {
                            var8[slot] = -3.0f * val;
                        }
                        break;
                    }
                }
            }
        } else if (e->kind == 6) {
            if (e->enabled == 0) continue;
            var8[3] += e->value;
        } else if (e->kind == 5) {
            int idx;
            if (e->enabled == 0) continue;
            idx = e->slot;
            if (var1[idx] != 0) continue;
            if (e->subtype == 0x12) {
                GameObject* c = obj->combatantList[idx];
                if (c != 0) {
                    unsigned int var56 = inline_ov024_021f9874(c);
                    unsigned short var57 = inline_ov024_021dc700(c);
                    float v = 100.0f * (int)(var56 >> 2);
                    v = v / var57;
                    if (v > 29.0f) v = 29.0f;
                    var8[2] = v;
                }
            } else {
                int t;
                for (t = 0; t < 0xd; t++) {
                    int slot = data_ov024_021ffcc5[t * 3 + 1];
                    unsigned int val = data_ov024_021ffcc5[t * 3 + 2];
                    if (e->subtype != data_ov024_021ffcc5[t * 3]) continue;
                    var8[slot] = val;
                    if (var47 == 0) var8[slot] = 0.0f;
                }
            }
        }

        if (var8[0]) {
            float v = var8[0] * e->unknown_7_;
            v = 0.01f * v;
            var4[8] += v;
            flags.b0 = 1;
        }
        if (var8[1]) {
            float v = var8[1] * e->unknown_7_;
            v = 0.01f * v;
            v = var18 * v;
            var4[9] += v;
            flags.b1 = 1;
        }
        if (var8[2]) {
            float v = var8[2] * e->unknown_7_;
            v = 0.01f * v;
            v = var18 * v;
            var4[10] += v;
            flags.b2 = 1;
        }
        if (var8[3]) {
            float v = var8[3] * e->unknown_7_;
            v = 0.01f * v;
            v = var18 * v;
            var4[11] += v;
            flags.b3 = 1;
        }
    }

    {
        struct Struct_ov024_021f9874* var66 = obj->unknown_648_;
        var9.f0 = var66->f0;
        var9.f2 = var66->f2;
        var9.f3 = var66->f3;
        var9.fa = p2;
        var9.fb = p3;
        var9.f8 = (unsigned short)obj->unknown_650_;
    }

    var10 = 0.0f;
    if (flags.any != 0) {
        var10 = var4[2];
        if (obj->unknown_2c_ != 0) var10 += var4[11];
        if (flagC != 0) var10 *= obj->unknown_30_;
        var9.value = var10 - 0.01f * var4[13];
        func_ov024_021f6830(obj->unknown_408_, &var9);
        if (0.0f == var4[13]) {
            func_ov024_021f6830(obj->unknown_438_, &var9);
        }
    }

    if (flags.unknown_5_ != 0) {
        var9.value = var4[5] - 0.1f * var4[13];
        func_ov024_021f6830(obj->unknown_498_, &var9);
    }
    if (obj->unknown_655_ != 0 && flags.unknown_6_ != 0) {
        var9.value = var4[6] - 0.1f * var4[13];
        func_ov024_021f6830(obj->unknown_4c8_, &var9);
    }

    var14 = 0.1f;
    if (obj->unknown_6_ == 0) var14 = 0.01f;
    v94 = 0.0f; v98 = 0.0f; v9c = 0.0f;

    if (flags.b0 != 0) {
        float v90 = var4[8] - 0.1f * var4[13];
        v90 += 0.01f * var4[6];
        var9.value = v90;
        func_ov024_021f6830(obj->unknown_528_, &var9);
    }
    if (obj->unknown_6_ == 2 && obj->unknown_64c_->code != 0x1f9) {
        var10 *= 0.3f;
    }
    if (flags.b1 != 0) {
        v94 = var4[9] - var4[13] * var14;
        var9.value = v94;
        func_ov024_021f6830(obj->unknown_558_, &var9);
    }
    if (flags.b2 != 0) {
        v98 = var4[10] - var4[13] * var14;
        var9.value = v98;
        func_ov024_021f6830(obj->unknown_588_, &var9);
    }
    if (flags.b3 != 0) {
        v9c = var4[11] - var4[13] * var14;
        var9.value = v9c;
        func_ov024_021f6830(obj->unknown_5b8_, &var9);
    }

    if (obj->unknown_6_ != 0 && obj->unknown_64c_->code == 1) {
        unsigned char* fld = (unsigned char*)func_02053c6c((unsigned char*)obj->f8);
        int s0;
        int var70;
        if (fld != 0 && *(short*)(fld + 0x2ac) > 0 &&
            ((struct Struct_ov024_021f9874_2*)(fld + 0x29c))->unknown_0_4_ == 3 &&
            !func_ov024_021eadfc(obj->f8) &&
            (s0 = buf->entries[0].slot, s0 >= 0) && s0 < 8 &&
            obj->combatantList[s0] != 0 &&
            (var70 = obj->combatantList[s0]->currentStats_->primaryStats.currMP, var70 > 0)) {
            var16 = (float)inline_ov000_0215cd44_2(obj->f8) / inline_ov024_021dc540_2(obj->f8);
            if (var16 <= 0.1f) buf->threshold += 50.0f;
            if (var16 <= 0.3f) buf->threshold += 30.0f;
            if (var16 <= 0.5f) buf->threshold += 10.0f;
        }
    }

    total = buf->threshold + v94;
    total = v98 + total;
    total = v9c + total;
    total = var10 + total;
    var9.value = total - var4[13] * var14;
    func_ov024_021f6830(obj->unknown_3a8_, &var9);

    if (!(var10 > 0.0f) || obj->unknown_650_ <= 0) {
        func_ov024_021f6830(obj->unknown_3d8_, &var9);
    }
}
