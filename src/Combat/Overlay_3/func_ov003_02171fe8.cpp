#include "GameState/GameState.h"
#include "Grotto/Main/TreasureMapMetadata.h"
#include "std_library_functions.h"
#include <globaldefs.h>

extern "C" void __clear(void *dst, int count);
extern "C" void func_ov003_02170a7c(char *in, char *out);
extern "C" void Font_EncodeText(const char *text, char *codes, int a);
extern "C" void *Zone3D_GetInstance(void);
extern "C" int func_ov003_021725a4(void *self, void *rec);

struct Struct0200fb08;
int GameState_GetLanguage(Struct0200fb08 *p);
int CheckNoConflictInArray0209890c(void *zone, void *rec);

extern const char *data_ov003_021805bc[];

struct Struct_ov003_02171fe8_4 {
    char unknown_0_[6];
};
struct Struct_ov003_02171fe8_5 {
    char unknown_0_[11];
};
struct Struct_ov003_02171fe8_6 {
    unsigned short unknown_0_[14];
};
struct Struct_ov003_02171fe8_7 {
    int unknown_0_[6];
};
struct Struct_ov003_02171fe8_8 {
    int unknown_0_[31];
};

struct Struct_ov003_02171fe8_9 {
    unsigned int unknown_0_0_ : 25;
    unsigned int unknown_3_1_ : 1;
    unsigned int unknown_3_2_ : 6;
    int unknown_4_0_ : 9;
    int unknown_5_1_ : 10;
    int unknown_6_3_ : 11;
    int unknown_7_6_ : 2;
    int unknown_8_[29];
};

struct Struct_ov000_021700dc {
    Struct_ov003_02171fe8_5 unknown_0_;
    unsigned char unknown_b_0_ : 7;
    unsigned char unknown_b_7_ : 1;
    unsigned int unknown_c_0_ : 4;
    unsigned int unknown_c_4_ : 4;
    unsigned int unknown_d_0_ : 7;
    unsigned int unknown_d_7_ : 17;
    int unknown_10_;
    Struct_ov003_02171fe8_4 unknown_14_;
    Struct_ov003_02171fe8_6 unknown_1a_;
    Struct_ov003_02171fe8_7 unknown_38_;
    Struct_ov003_02171fe8_6 unknown_50_;
    Struct_ov003_02171fe8_8 unknown_6c_;
};

struct Struct_ov003_02171fe8 {
    Struct_ov003_02171fe8_5 unknown_0_;
    unsigned char unknown_b_;
    unsigned int unknown_c_;
    int unknown_10_;
    Struct_ov003_02171fe8_4 unknown_14_;
    Struct_ov003_02171fe8_6 unknown_1a_;
    Struct_ov003_02171fe8_7 unknown_38_;
    Struct_ov003_02171fe8_6 unknown_50_;
    Struct_ov003_02171fe8_8 unknown_6c_;
};

struct Struct_ov003_02171fe8_2 {
    Struct_ov003_02171fe8_5 unknown_0_;
    unsigned char unknown_b_;
    unsigned char unknown_c_;
    unsigned char unknown_d_;
    Struct_ov003_02171fe8_4 unknown_e_;
    Struct_ov003_02171fe8_8 unknown_14_;
    Struct_ov003_02171fe8_6 unknown_90_;
    Struct_ov003_02171fe8_7 unknown_ac_;
    TreasureMapMetadata unknown_c4_;
};

struct Struct_ov003_02171fe8_3 {
    char unknown_0_[0x199];
    unsigned char unknown_199_;
#if defined(jpn)
    char unknown_19a_[0x27c - 0x19a];
    Struct_ov003_02171fe8_2 unknown_2a0_;
#else
    char unknown_19a_[0x2a0 - 0x19a];
    Struct_ov003_02171fe8_2 unknown_2a0_;
    char unknown_380_[0x460 - 0x380];
#endif
    Struct_ov000_021700dc unknown_460_[3];
    unsigned char unknown_718_;
    char unknown_719_[3];
    int unknown_71c_;
    int unknown_720_;
    int unknown_724_;
    char unknown_728_[4];
    int unknown_72c_;
};

// USA: func_ov003_02171fe8
extern "C" ARM void func_ov003_02171fe8(Self0217 *self, int id, void *data, unsigned int len, unsigned int offset) {
    char a[11];
    char a2[11];
    Slot local;
    if (self->b199_ == id) {
        self->w72c_ = 0;
        memcpy((char *) &self->wire_ + offset, data, len);
        if (offset + len >= 0xe0) {
            self->w71c_ = 1;
            self->w724_ = 1;
            if (*(unsigned int *) ((char *) self + 0x34c) >> 31) {
                self->wire_.tm_.SetDiscoveryState(DiscoveryState_Undiscovered);
                self->wire_.tm_.ClearInitialByteUnknownBit();
                strcpy((char *) &local.name_, (char *) &self->wire_.name_);
                local.lo_   = self->wire_.b0_;
                local.mid_  = self->wire_.b1_;
                local.flag_ = self->wire_.b2_;
                memcpy(&local.w6c_, &self->wire_.w_, 0x7c);
                memcpy(&local.h1a_, &self->wire_.h_, 0x1c);
                memcpy(&local.w38_, &self->wire_.x_, 0x18);
                memcpy(&local.h50_, &self->wire_.tm_, 0x1c);
                memcpy(&local.s14_, &self->wire_.s_, 6);
                local.w6c_.v[0] |= 0x4000000;
            } else {
                GameState *gs = GameState::GetInstance();
                self->wire_.tm_.SetDiscoveryState(DiscoveryState_Undiscovered);
                self->wire_.tm_.ClearInitialByteUnknownBit();
                local.lo_   = self->wire_.b0_;
                local.mid_  = self->wire_.b1_;
                local.flag_ = self->wire_.b2_;
                memcpy(&local.w6c_, &self->wire_.w_, 0x7c);
                memcpy(&local.h1a_, &self->wire_.h_, 0x1c);
                memcpy(&local.w38_, &self->wire_.x_, 0x18);
                memcpy(&local.h50_, &self->wire_.tm_, 0x1c);
                memcpy(&local.s14_, &self->wire_.s_, 6);
                local.w6c_.v[0] |= 0x4000000;
                int kind = GameState_GetLanguage((Struct0200fb08 *) gs);
                int idx  = 0;
                switch (kind) {
                    case 2: idx = 1; break;
                    case 3: idx = 2; break;
                    case 4: idx = 3; break;
                    case 5: idx = 4; break;
                }
                __clear(a, 11);
                memset(a, 0, 0xb);
                func_ov003_02170a7c((char *) &self->wire_.name_, a);
                memset(&self->wire_.name_, 0, 0xb);
                Font_EncodeText(a, (char *) &local.name_, 1);
                Font_EncodeText(data_ov003_021805bc[idx], (char *) &local.w6c_.v[2], 1);
                Stat7c *st = (Stat7c *) &local.w6c_;
                if (st->f9_ >= 100) {
                    if (st->f9_ < 200) {
                        st->f9_ = 396;
                    }
                }
                if (st->flag_ == 1) {
                    if (st->f19_ >= 700 && st->f19_ < 750) {
                        st->f19_ = st->f19_ + 50;
                    } else if (st->f19_ >= 800) {
                        st->f19_ = st->f19_ + 100;
                    }
                }
                char *tm = (char *) &local.h50_;
                __clear(a2, 11);
                memset(a, 0, 0xb);
                memset(a2, 0, 0xb);
                memcpy(a2, tm + 1, 10);
                func_ov003_02170a7c(a2, a);
                memset(tm + 1, 0, 10);
                Font_EncodeText(a, tm + 1, 1);
                memset(a, 0, 0xb);
                memset(a2, 0, 0xb);
                memcpy(a2, tm + 0xb, 10);
                func_ov003_02170a7c(a2, a);
                memset(tm + 0xb, 0, 10);
                Font_EncodeText(a, tm + 0xb, 1);
            }
            char *zone = (char *) Zone3D_GetInstance();
            if (self->b718_ < 3) {
                if (CheckNoConflictInArray0209890c(zone + 0x840, &local) != 0) {
                    if (func_ov003_021725a4(self, &local) != 0) {
                        SlotRaw *d  = (SlotRaw *) &self->slots_[self->b718_];
                        d->name_    = ((SlotRaw *) &local)->name_;
                        d->b0b_     = ((SlotRaw *) &local)->b0b_;
                        d->w0c_     = ((SlotRaw *) &local)->w0c_;
                        d->w10_     = ((SlotRaw *) &local)->w10_;
                        d->s14_     = ((SlotRaw *) &local)->s14_;
                        d->h1a_     = ((SlotRaw *) &local)->h1a_;
                        d->w38_     = ((SlotRaw *) &local)->w38_;
                        d->h50_     = ((SlotRaw *) &local)->h50_;
                        d->w6c_     = ((SlotRaw *) &local)->w6c_;
                        self->b718_ = self->b718_ + 1;
                    }
                }
            }
        }
    }
#else
    char var0[11];
    char var1[11];
    Struct_ov000_021700dc var2;
    if (arg0->unknown_199_ == arg1) {
        arg0->unknown_72c_ = 0;
        memcpy((char *) &arg0->unknown_2a0_ + arg4, arg2, arg3);
        if (arg4 + arg3 >= 0xe0) {
            arg0->unknown_71c_ = 1;
            arg0->unknown_724_ = 1;
            if (*(unsigned int *) ((char *) arg0 + 0x34c) >> 31) {
                arg0->unknown_2a0_.unknown_c4_.SetDiscoveryState(DiscoveryState_Undiscovered);
                arg0->unknown_2a0_.unknown_c4_.ClearInitialByteUnknownBit();
                strcpy((char *) &var2.unknown_0_, (char *) &arg0->unknown_2a0_.unknown_0_);
                var2.unknown_c_0_   = arg0->unknown_2a0_.unknown_b_;
                var2.unknown_d_0_  = arg0->unknown_2a0_.unknown_c_;
                var2.unknown_b_7_ = arg0->unknown_2a0_.unknown_d_;
                memcpy(&var2.unknown_6c_, &arg0->unknown_2a0_.unknown_14_, 0x7c);
                memcpy(&var2.unknown_1a_, &arg0->unknown_2a0_.unknown_90_, 0x1c);
                memcpy(&var2.unknown_38_, &arg0->unknown_2a0_.unknown_ac_, 0x18);
                memcpy(&var2.unknown_50_, &arg0->unknown_2a0_.unknown_c4_, 0x1c);
                memcpy(&var2.unknown_14_, &arg0->unknown_2a0_.unknown_e_, 6);
                var2.unknown_6c_.unknown_0_[0] |= 0x4000000;
            } else {
                GameState *var3 = GameState::GetInstance();
                arg0->unknown_2a0_.unknown_c4_.SetDiscoveryState(DiscoveryState_Undiscovered);
                arg0->unknown_2a0_.unknown_c4_.ClearInitialByteUnknownBit();
                var2.unknown_c_0_   = arg0->unknown_2a0_.unknown_b_;
                var2.unknown_d_0_  = arg0->unknown_2a0_.unknown_c_;
                var2.unknown_b_7_ = arg0->unknown_2a0_.unknown_d_;
                memcpy(&var2.unknown_6c_, &arg0->unknown_2a0_.unknown_14_, 0x7c);
                memcpy(&var2.unknown_1a_, &arg0->unknown_2a0_.unknown_90_, 0x1c);
                memcpy(&var2.unknown_38_, &arg0->unknown_2a0_.unknown_ac_, 0x18);
                memcpy(&var2.unknown_50_, &arg0->unknown_2a0_.unknown_c4_, 0x1c);
                memcpy(&var2.unknown_14_, &arg0->unknown_2a0_.unknown_e_, 6);
                var2.unknown_6c_.unknown_0_[0] |= 0x4000000;
                int var4 = func_0200fb08((Struct_02000c9c_8 *) var3);
                int var5  = 0;
                switch (var4) {
                    case 2: var5 = 1; break;
                    case 3: var5 = 2; break;
                    case 4: var5 = 3; break;
                    case 5: var5 = 4; break;
                }
                __clear(var0, 11);
                memset(var0, 0, 0xb);
                func_ov003_02170a7c((char *) &arg0->unknown_2a0_.unknown_0_, var0);
                memset(&arg0->unknown_2a0_.unknown_0_, 0, 0xb);
                func_020426bc(var0, (char *) &var2.unknown_0_, 1);
                func_020426bc(data_ov003_021805bc[var5], (char *) &var2.unknown_6c_.unknown_0_[2], 1);
                Struct_ov003_02171fe8_9 *var6 = (Struct_ov003_02171fe8_9 *) &var2.unknown_6c_;
                if (var6->unknown_5_1_ >= 100) {
                    if (var6->unknown_5_1_ < 200) {
                        var6->unknown_5_1_ = 396;
                    }
                }
                if (var6->unknown_3_1_ == 1) {
                    if (var6->unknown_6_3_ >= 700 && var6->unknown_6_3_ < 750) {
                        var6->unknown_6_3_ = var6->unknown_6_3_ + 50;
                    } else if (var6->unknown_6_3_ >= 800) {
                        var6->unknown_6_3_ = var6->unknown_6_3_ + 100;
                    }
                }
                char *var7 = (char *) &var2.unknown_50_;
                __clear(var1, 11);
                memset(var0, 0, 0xb);
                memset(var1, 0, 0xb);
                memcpy(var1, var7 + 1, 10);
                func_ov003_02170a7c(var1, var0);
                memset(var7 + 1, 0, 10);
                func_020426bc(var0, var7 + 1, 1);
                memset(var0, 0, 0xb);
                memset(var1, 0, 0xb);
                memcpy(var1, var7 + 0xb, 10);
                func_ov003_02170a7c(var1, var0);
                memset(var7 + 0xb, 0, 10);
                func_020426bc(var0, var7 + 0xb, 1);
            }
            char *var8 = (char *) func_02012fe4();
            if (arg0->unknown_718_ < 3) {
                if (func_0209890c(var8 + 0x840, &var2) != 0) {
                    if (func_ov003_021725a4(arg0, &var2) != 0) {
                        Struct_ov003_02171fe8 *var9  = (Struct_ov003_02171fe8 *) &arg0->unknown_460_[arg0->unknown_718_];
                        var9->unknown_0_    = ((Struct_ov003_02171fe8 *) &var2)->unknown_0_;
                        var9->unknown_b_     = ((Struct_ov003_02171fe8 *) &var2)->unknown_b_;
                        var9->unknown_c_     = ((Struct_ov003_02171fe8 *) &var2)->unknown_c_;
                        var9->unknown_10_     = ((Struct_ov003_02171fe8 *) &var2)->unknown_10_;
                        var9->unknown_14_     = ((Struct_ov003_02171fe8 *) &var2)->unknown_14_;
                        var9->unknown_1a_     = ((Struct_ov003_02171fe8 *) &var2)->unknown_1a_;
                        var9->unknown_38_     = ((Struct_ov003_02171fe8 *) &var2)->unknown_38_;
                        var9->unknown_50_     = ((Struct_ov003_02171fe8 *) &var2)->unknown_50_;
                        var9->unknown_6c_     = ((Struct_ov003_02171fe8 *) &var2)->unknown_6c_;
                        arg0->unknown_718_ = arg0->unknown_718_ + 1;
                    }
                }
            }
        }
    }
#endif
}
