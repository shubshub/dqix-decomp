#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "Resource/Brightness.h"
#include "std_library_functions.h"
#include <globaldefs.h>
#include "Input/Input.h"

struct Struct_02072a68;
struct Struct_02072a68_2 {
    Struct_02072a68 *unknown_0_;
    short unknown_4_;
};
struct Struct_0205a330;

struct Struct_ov003_02172e84_8 {
    unsigned int unknown_0_0_ : 12;
    unsigned int unknown_1_4_ : 4;
    unsigned int unknown_2_0_ : 5;
    unsigned int unknown_2_5_ : 4;
    unsigned int unknown_3_1_ : 1;
    unsigned int unknown_3_2_ : 1;
    unsigned int unknown_3_3_ : 1;
    unsigned int unknown_3_4_ : 1;
    unsigned int unknown_3_5_ : 1;
    unsigned int unknown_3_6_ : 1;
    unsigned int unknown_3_7_ : 1;
    unsigned int unknown_4_0_ : 9;
    int unknown_5_1_ : 10;
    int unknown_6_3_ : 11;
    int unknown_7_6_ : 1;
    unsigned int unknown_7_7_ : 1;
};

struct Struct_ov003_02172e84_9 {
    char unknown_0_[0x6c];
    Struct_ov003_02172e84_8 unknown_6c_;
    char unknown_74_[0xe8 - 0x74];
};

static inline int inline_ov003_02172e84_2(Struct_ov003_02172e84_8 *arg0) { return arg0->unknown_6_3_; }
static inline Struct_ov003_02172e84_8 *inline_ov003_02172e84(Struct_ov003_02172e84_9 *arg0) { return &arg0->unknown_6c_; }

struct Struct_ov003_02172e84 {
    unsigned char unknown_0_;
#if defined(jpn)
    char unknown_1_[0x35c - 1];
    Struct_ov003_02172e84_9 unknown_35c_[3];
    unsigned char unknown_614_;
    char unknown_615_[0x634 - 0x615];
#else
    char unknown1_1_[0x460 - 1];
    Struct_ov003_02172e84_9 unknown_460_[3];
    unsigned char unknown_718_;
    char unknown_719_[0x738 - 0x719];
#endif
    unsigned int unknown_738_;
};

struct Struct_ov003_02172e84_2 {
    char unknown_0_[0x28];
    unsigned char unknown_28_;
};

struct Struct_ov003_02172e84_3 {
#if defined(jpn)
    char unknown_0_[0x228];
    void *unknown_228_;
    int unknown_22c_;
    Struct_0205a330 *unknown_230_;
    char unknown_234_[0x868 - 0x234];
    int unknown_868_;
    int unknown_86c_;
    int unknown_870_;
    char unknown_874_[0x17ee - 0x874];
    unsigned char unknown_17ee_;
#else
    char unknown1_0_[0x2d8];
    void *unknown_2d8_;
    int unknown_2dc_;
    Struct_0205a330 *unknown_2e0_;
    char unknown_2e4_[0x998 - 0x2e4];
    int unknown_998_;
    int unknown_99c_;
    int unknown_9a0_;
    char unknown_9a4_[0x19be - 0x9a4];
    unsigned char unknown_19be_;
#endif
};

struct Struct_ov003_02172e84_4 {
    unsigned char unknown_0_[0xb48];
    unsigned int unknown_b48_;
    unsigned int unknown_b4c_;
};

struct Struct_ov003_02172e84_5 {
    unsigned char unknown_0_[0x1000];
    Struct_ov003_02172e84_4 unknown_1000_;
};

struct Struct_ov003_02172e84_6 {
#if defined(jpn)
    unsigned char unknown_0_[0x860];
#else
    unsigned char unknown1_0_[0x840];
#endif
    Struct_ov003_02172e84_5 unknown_840_;
};

static inline bool inline_ov003_02172e84_3(Struct_ov003_02172e84 *arg0) { return arg0->unknown_0_ == 8 || arg0->unknown_0_ == 9; }

#if defined(jpn)
struct Struct_ov003_02172e84_7 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    char unknown_2_[0x40];
    char unknown_42_[0x80];
    unsigned char unknown_c2_;
    char unknown_c3_[0xc8 - 0xc3];
    unsigned char unknown_c8_;
    unsigned char unknown_c9_;
    char unknown_ca_[0xcc - 0xca];
    Struct_ov003_02172e84 *unknown_cc_;
    unsigned char unknown_d0_;
    unsigned char unknown_d1_;
    char unknown_d2_[0xd4 - 0xd2];
    char unknown_d4_[0xe8 - 0xd4];
    unsigned char unknown_e8_;
    unsigned char unknown_e9_;
    unsigned char unknown_ea_;
    char unknown_eb_[0x134 - 0xeb];
    int unknown_134_;
    Struct_0205a330 *unknown_138_;
    char unknown_13c_[0x1cc - 0x13c];
    int unknown_1cc_;
    char unknown_1d0_[0x1dc - 0x1d0];
    Struct_02072a68_2 unknown_1dc_;
    Struct_02072a68_2 unknown_1e4_;
    char unknown_1ec_[0x319 - 0x1ec];
    unsigned char unknown_319_;
    char unknown_31a_[0x34c - 0x31a];
    void *unknown_34c_;
    unsigned char unknown_350_;
};
#else
struct Struct_ov003_02172e84_7 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    short unknown_2_;
    char unknown_4_[0x40];
    char unknown_44_[0x80];
    unsigned char unknown_c4_;
    char unknown_c5_[0xca - 0xc5];
    unsigned char unknown_ca_;
    unsigned char unknown_cb_;
    char unknown_cc_[0xd0 - 0xcc];
    Struct_ov003_02172e84 *unknown_d0_;
    unsigned char unknown_d4_;
    unsigned char unknown_d5_;
    char unknown_d6_[0xd8 - 0xd6];
    char unknown_d8_[0xec - 0xd8];
    unsigned char unknown_ec_;
    unsigned char unknown_ed_;
    unsigned char unknown_ee_;
    char unknown_ef_[0x128 - 0xef];
    int unknown_128_;
    Struct_0205a330 *unknown_12c_;
    char unknown_130_[0x1c0 - 0x130];
    int unknown_1c0_;
    char unknown_1c4_[0x1d0 - 0x1c4];
    Struct_02072a68_2 unknown_1d0_;
    Struct_02072a68_2 unknown_1d8_;
    char unknown_1e0_[0x30d - 0x1e0];
    unsigned char unknown_30d_;
    char unknown_30e_[0x340 - 0x30e];
    void *unknown_340_;
    unsigned char unknown_344_;
};
#endif

Messages02172e84 *MessageSystem_GetInstance();
const char *FindEntryByKey_02072a68(TableA68 *table, int key);
#if defined(jpn)
extern "C" void func_0204500c(Struct_ov003_02172e84_3 *arg0, const char *arg1, int arg2);
extern "C" void func_020e2168(char *arg0, const char *arg1, int arg2, int arg3, int arg4);
extern char data_ov003_0217eb9b[];
extern char data_ov003_0217ebff[];
extern char data_ov003_0217ec02[];
extern char data_ov003_0217ec1d[];
#else
extern "C" void func_0204500c(Struct_ov003_02172e84_3 *arg0, const char *arg1, int arg2, int arg3);
#endif
extern "C" Zone02172e84 *Zone3D_GetInstance(void);
extern "C" void __clear(void *dst, int count);
extern "C" void Font_DecodeText(Member02172e84 *member, char *buf, int flag);
extern "C" void *ExtractFileFromGP2(const char *gp2Path, const char *innerFilePath, unsigned int *outSize);
extern "C" char *func_020e046c(char *buf, void *data, unsigned int size, int idx);
extern "C" void func_ov003_0217bd38(void *obj, int arg);
unsigned char GetByteField28_021b1fa8(void *obj);
extern "C" void *LinkSession_GetInstance(void);
int LinkSession_IsActive(int *obj);
extern "C" void LinkSession_End(void *obj);
int IsInRangePair_021734dc(int unused, int a, int b);
void SpriteEntryList_AdvanceAnimations(Container0205a330 *c, int arg);
extern "C" int func_020457e0(Messages02172e84 *window);
extern "C" int func_ov003_02172570(unsigned char *obj, void *extra);

extern char data_ov003_02180a49[];
extern char data_ov003_02180a4c[];
extern char data_ov003_02180a63[];

// USA: func_ov003_02172e84
#if defined(jpn)
extern "C" ARM void func_ov003_02172e84(Self02172e84 *self) {
    GameResources *res = GetGameResources();
    Messages02172e84 *msg = MessageSystem_GetInstance();
    Battle02172e84 *battle = (Battle02172e84 *) res->fieldTasks_[19];
    if (self->step_ == 0) {
        if (IsMainBrightnessTransitionActive(res) == 0) {
            func_0204500c(msg, data_ov003_0217eb9b, 0);
            msg->flag19be_ = 1;
            msg->busy_ = 1;
            self->step_ = 1;
        }
    } else if (self->step_ == 1) {
        Zone02172e84 *zone = Zone3D_GetInstance();
        Save02172e84 *save = &zone->save_;
        unsigned char count = self->party_->count_;
        unsigned int joined = self->party_->joined_ & ~1;
        joined &= joined ^ save->progress_.seen_;
        if (battle->flag28_ != 0) {
            if (!IsLinked(self->party_)) {
                self->pending_ = 1;
            }
        }
        if (var6 != 0 && arg0->unknown_d0_ < 3) {
            arg0->unknown_d0_++;
            arg0->unknown_c9_ = 1;
            arg0->unknown_1_ = 1;
            int var7;
            for (var7 = 1; var7 < 24; var7++) {
                if (var6 & (1 << var7)) break;
            }
            var4->unknown_1000_.unknown_b48_ |= 1 << var7;
            var4->unknown_1000_.unknown_b4c_ |= 1 << var7;
            sprintf(arg0->unknown_2_, data_ov003_0217ebff, func_02072a68(&arg0->unknown_1e4_, (short) var7));
            arg0->unknown_c2_++;
            arg0->unknown_ea_ = 99;
        } else if (arg0->unknown_d1_ != var5 && arg0->unknown_d0_ < 3) {
            Struct_ov003_02172e84_9 *var8 = &arg0->unknown_cc_->unknown_35c_[arg0->unknown_d1_];
            arg0->unknown_d1_++;
            arg0->unknown_c9_ = 1;
            arg0->unknown_d0_++;
            sprintf(arg0->unknown_2_, data_ov003_0217ebff, var8);
            int var9 = inline_ov003_02172e84_2(inline_ov003_02172e84(var8));
            if (var9 < 700) {
                func_020e2168(arg0->unknown_42_, data_ov003_0217ec02, (short) var9, var8->unknown_6c_.unknown_3_1_, 1);
            } else {
                sprintf(arg0->unknown_42_, data_ov003_0217ebff,
                        func_02072a68(&arg0->unknown_1dc_, (short) (var8->unknown_6c_.unknown_6_3_ + 20000)));
            }
            arg0->unknown_ea_ = 99;
        } else if (arg0->unknown_350_ != 0 && !((*(unsigned short *) 0x27fffa8 & 0x8000) >> 15)) {
            arg0->unknown_34c_ = arg0->unknown_d4_;
            func_ov003_0217bd38(arg0->unknown_1ec_, arg0->unknown_1cc_);
            arg0->unknown_319_ = func_ov017_021b1fa8(var2);
            arg0->unknown_e8_ = 5;
            arg0->unknown_ea_ = 0;
        } else {
            int var10 = g_touchInput.pressX_;
            int var11 = g_touchInput.pressY_;
            int var12;
            int var13;
            g_touchInput.GetTouchPoint(&var12, &var13);
            if (func_ov003_021734dc((int) arg0, var10, var11) && func_ov003_021734dc((int) arg0, var12, var13)) {
                arg0->unknown_0_ = 1;
                if (g_touchInput.released_ != 0) {
                    arg0->unknown_ea_ = 2;
                }
            } else if (g_keyManager.TestKeysPressed(2)) {
                arg0->unknown_0_ = 1;
                arg0->unknown_ea_ = 2;
            } else {
                arg0->unknown_0_ = 0;
            }
        }
    } else if (self->step_ == 2) {
        func_0204500c(msg, data_ov003_0217ec1d, 0);
        msg->busy_ = 1;
        self->step_ = 3;
    } else if (self->step_ == 3) {
        GameState *state = GameState::GetInstance();
        msg->target_ = self->field130_;
        msg->field2dc_ = self->field128_;
        msg->entries_ = self->entries_;
        self->active_ = 0;
        Container0205a330 *entries = msg->entries_;
        SpriteEntryList_AdvanceAnimations(entries, state->GetTickCount() >> 2);
        if (msg->state_ == 0) {
            msg->busy_ = 1;
            if (func_020457e0(msg) == 0) {
                self->done_ = 1;
                self->step_ = 4;
            } else {
                arg0->unknown_ea_ = 0;
            }
        }
    } else if (arg0->unknown_ea_ == 4) {
        if (arg0->unknown_c8_ != 0 && !inline_ov003_02172e84_3(arg0->unknown_cc_)) {
            arg0->unknown_e8_ = 4;
            arg0->unknown_ea_ = 0;
            arg0->unknown_cc_->unknown_0_ = 10;
        } else if (inline_ov003_02172e84_3(arg0->unknown_cc_)) {
            func_ov003_02172570((unsigned char *) arg0->unknown_cc_, 0);
        }
    } else if (arg0->unknown_ea_ == 99) {
        if (arg0->unknown_e9_ == 2) {
            arg0->unknown_ea_ = 1;
        }
    }
}
#else
extern "C" ARM void func_ov003_02172e84(Self02172e84 *self) {
    GameResources *res = GetGameResources();
    Messages02172e84 *msg = MessageSystem_GetInstance();
    Battle02172e84 *battle = (Battle02172e84 *) res->fieldTasks_[19];
    if (self->step_ == 0) {
        if (IsMainBrightnessTransitionActive(res) == 0) {
            func_0204500c(msg, FindEntryByKey_02072a68(&self->texts_, 100), 0, 0xe3);
            msg->flag19be_ = 1;
            msg->busy_ = 1;
            self->step_ = 1;
        }
    } else if (self->step_ == 1) {
        Zone02172e84 *zone = Zone3D_GetInstance();
        Save02172e84 *save = &zone->save_;
        unsigned char count = self->party_->count_;
        unsigned int joined = self->party_->joined_ & ~1;
        joined &= joined ^ save->progress_.seen_;
        if (battle->flag28_ != 0) {
            if (!IsLinked(self->party_)) {
                self->pending_ = 1;
            }
        }
        if (var22 != 0 && arg0->unknown_d4_ < 3) {
            arg0->unknown_d4_++;
            arg0->unknown_cb_ = 1;
            arg0->unknown_1_ = 1;
            int var23;
            for (var23 = 1; var23 < 24; var23++) {
                if (var22 & (1 << var23)) break;
            }
            save->progress_.seen_ |= 1 << i;
            save->progress_.announced_ |= 1 << i;
            sprintf(self->text_, data_ov003_02180a49, FindEntryByKey_02072a68(&self->texts_, (short) i));
            self->bit_ = i;
            self->announceCount_++;
            self->step_ = 99;
        } else if (self->memberIndex_ != count && self->shownCount_ < 3) {
            Member02172e84 *member = &self->party_->members_[self->memberIndex_];
            self->memberIndex_++;
            self->busy_ = 1;
            self->shownCount_++;
            char name[0x30];
            __clear(name, sizeof(name));
            Font_DecodeText(member, name, 1);
            sprintf(self->text_, data_ov003_02180a49, name);
            if (GetAccolade(GetProfile(member)) < 700) {
                BackgroundLoader::AddLockGlobal();
                unsigned int var26 = 0;
                char var27[0x40];
                char var28[0x20];
                __clear(var27, sizeof(var27));
                __clear(var28, sizeof(var28));
                sprintf(var27, data_ov003_02180a4c, var24->unknown_6c_.unknown_3_1_);
                sprintf(var28, data_ov003_02180a63, var24->unknown_6c_.unknown_3_1_);
                void *var29 = ExtractFileFromGP2(var27, var28, &var26);
                if (var29 != 0) {
                    func_020e046c(arg0->unknown_44_, var29, var26, (short) var24->unknown_6c_.unknown_6_3_);
                }
                BackgroundLoader::RemoveLockGlobal();
            } else {
                sprintf(arg0->unknown_44_, data_ov003_02180a49,
                        func_02072a68(&arg0->unknown_1d0_, (short) (var24->unknown_6c_.unknown_6_3_ + 20000)));
            }
            self->step_ = 99;
        } else if (self->pending_ != 0 && !((*(unsigned short *) 0x27fffa8 & 0x8000) >> 15)) {
            self->field340_ = self->fieldd8_;
            func_ov003_0217bd38(self->field1e0_, self->field1c0_);
            self->field30d_ = GetByteField28_021b1fa8(battle);
            self->party_->state_ = 10;
            void *save = LinkSession_GetInstance();
            if (LinkSession_IsActive((int *) save)) {
                LinkSession_End(save);
            }
            arg0->unknown_ec_ = 5;
            arg0->unknown_ee_ = 0;
        } else {
            int var31 = g_touchInput.pressX_;
            int var32 = g_touchInput.pressY_;
            int var33;
            int var34;
            g_touchInput.GetTouchPoint(&var33, &var34);
            if (func_ov003_021734dc((int) arg0, var31, var32) && func_ov003_021734dc((int) arg0, var33, var34)) {
                arg0->unknown_0_ = 1;
                if (g_touchInput.released_ != 0) {
                    arg0->unknown_ee_ = 2;
                }
            } else if (g_keyManager.TestKeysPressed(2)) {
                arg0->unknown_0_ = 1;
                arg0->unknown_ee_ = 2;
            } else {
                arg0->unknown_0_ = 0;
            }
        }
    } else if (self->step_ == 2) {
        func_0204500c(msg, FindEntryByKey_02072a68(&self->texts_, 101), 0, 0xe3);
        msg->busy_ = 1;
        self->step_ = 3;
    } else if (self->step_ == 3) {
        GameState *state = GameState::GetInstance();
        msg->target_ = self->field130_;
        msg->field2dc_ = self->field128_;
        msg->entries_ = self->entries_;
        self->active_ = 0;
        Container0205a330 *entries = msg->entries_;
        SpriteEntryList_AdvanceAnimations(entries, state->GetTickCount() >> 2);
        if (msg->state_ == 0) {
            msg->busy_ = 1;
            if (func_020457e0(msg) == 0) {
                self->done_ = 1;
                self->step_ = 4;
            } else {
                arg0->unknown_ee_ = 0;
            }
        }
    } else if (arg0->unknown_ee_ == 4) {
        if (arg0->unknown_ca_ != 0 && !inline_ov003_02172e84_3(arg0->unknown_d0_)) {
            arg0->unknown_ec_ = 4;
            arg0->unknown_ee_ = 0;
            arg0->unknown_d0_->unknown_0_ = 10;
        } else if (inline_ov003_02172e84_3(arg0->unknown_d0_)) {
            func_ov003_02172570((unsigned char *) arg0->unknown_d0_, 0);
        }
    } else if (arg0->unknown_ee_ == 99) {
        if (arg0->unknown_ed_ == 2) {
            arg0->unknown_ee_ = 1;
        }
    }
}
#endif
