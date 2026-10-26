#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "Resource/Brightness.h"
#include "std_library_functions.h"
#include <globaldefs.h>
#include "Input/Input.h"

struct Struct_02072a68;
struct TableA68 {
    Struct_02072a68 *entries;
    short count;
};
struct Container0205a330;

struct Struct_ov003_02172e84_8 {
    unsigned int unknown_0_0_ : 12;
    unsigned int unknown_1_4_ : 4;
    unsigned int unknown_2_0_ : 5;
    unsigned int unknown_2_5_ : 4;
    unsigned int female_ : 1;
    unsigned int unknown_3_2_ : 1;
    unsigned int unknown_3_3_ : 1;
    unsigned int unknown_3_4_ : 1;
    unsigned int unknown_3_5_ : 1;
    unsigned int unknown_3_6_ : 1;
    unsigned int unknown_3_7_ : 1;
    unsigned int unknown_4_0_ : 9;
    int unknown_5_1_ : 10;
    int accolade_ : 11;
    int unknown_7_6_ : 1;
    unsigned int unknown_7_7_ : 1;
};

struct Member02172e84 {
    char name_[0x6c];
    Struct_ov003_02172e84_8 unknown_6c_;
    char unknown_74_[0xe8 - 0x74];
};

static inline int inline_ov003_02172e84_2(Struct_ov003_02172e84_8 *profile) { return profile->accolade_; }
static inline Struct_ov003_02172e84_8 *inline_ov003_02172e84(Member02172e84 *member) { return &member->unknown_6c_; }

struct Struct_ov003_02172e84 {
    unsigned char state_;
#if defined(jpn)
    char pad1[0x35c - 1];
    Member02172e84 members_[3];
    unsigned char count_;
    char unknown_615_[0x634 - 0x615];
#else
    char pad1[0x460 - 1];
    Member02172e84 members_[3];
    unsigned char count_;
    char unknown_719_[0x738 - 0x719];
#endif
    unsigned int unknown_738_;
};

struct Battle02172e84 {
    char pad0[0x28];
    unsigned char unknown_28_;
};

struct Messages02172e84 {
#if defined(jpn)
    char pad0[0x228];
    void *unknown_228_;
    int unknown_22c_;
    Container0205a330 *entries_;
    char unknown_234_[0x868 - 0x234];
    int busy_;
    int unknown_86c_;
    int state_;
    char unknown_874_[0x17ee - 0x874];
    unsigned char unknown_17ee_;
#else
    char pad0[0x2d8];
    void *unknown_2d8_;
    int unknown_2dc_;
    Container0205a330 *entries_;
    char unknown_2e4_[0x998 - 0x2e4];
    int busy_;
    int unknown_99c_;
    int state_;
    char unknown_9a4_[0x19be - 0x9a4];
    unsigned char unknown_19be_;
#endif
};

struct Struct_ov003_02172e84_4 {
    unsigned char pad0[0xb48];
    unsigned int unknown_b48_;
    unsigned int unknown_b4c_;
};

struct Struct_ov003_02172e84_5 {
    unsigned char pad0[0x1000];
    Struct_ov003_02172e84_4 unknown_1000_;
};

struct Zone02172e84 {
#if defined(jpn)
    unsigned char pad0[0x860];
#else
    unsigned char pad0[0x840];
#endif
    Struct_ov003_02172e84_5 unknown_840_;
};

static inline bool inline_ov003_02172e84_3(Struct_ov003_02172e84 *party) { return party->state_ == 8 || party->state_ == 9; }

#if defined(jpn)
struct Struct_ov003_02172e84_7 {
    unsigned char active_;
    unsigned char unknown_1_;
    char text_[0x40];
    char unknown_42_[0x80];
    unsigned char unknown_c2_;
    char padc3[0xc8 - 0xc3];
    unsigned char unknown_c8_;
    unsigned char busy_;
    char unknown_ca_[0xcc - 0xca];
    Struct_ov003_02172e84 *unknown_cc_;
    unsigned char unknown_d0_;
    unsigned char unknown_d1_;
    char unknown_d2_[0xd4 - 0xd2];
    char unknown_d4_[0xe8 - 0xd4];
    unsigned char mode_;
    unsigned char unknown_e9_;
    unsigned char step_;
    char unknown_eb_[0x134 - 0xeb];
    int unknown_134_;
    Container0205a330 *entries_;
    char unknown_13c_[0x1cc - 0x13c];
    int unknown_1cc_;
    char unknown_1d0_[0x1dc - 0x1d0];
    TableA68 titles_;
    TableA68 texts_;
    char unknown_1ec_[0x319 - 0x1ec];
    unsigned char unknown_319_;
    char unknown_31a_[0x34c - 0x31a];
    void *unknown_34c_;
    unsigned char unknown_350_;
};
#else
struct Struct_ov003_02172e84_7 {
    unsigned char active_;
    unsigned char unknown_1_;
    short unknown_2_;
    char text_[0x40];
    char unknown_44_[0x80];
    unsigned char unknown_c4_;
    char unknown_c5_[0xca - 0xc5];
    unsigned char unknown_ca_;
    unsigned char busy_;
    char unknown_cc_[0xd0 - 0xcc];
    Struct_ov003_02172e84 *unknown_d0_;
    unsigned char unknown_d4_;
    unsigned char unknown_d5_;
    char unknown_d6_[0xd8 - 0xd6];
    char unknown_d8_[0xec - 0xd8];
    unsigned char mode_;
    unsigned char unknown_ed_;
    unsigned char step_;
    char unknown_ef_[0x128 - 0xef];
    int unknown_128_;
    Container0205a330 *entries_;
    char unknown_130_[0x1c0 - 0x130];
    int unknown_1c0_;
    char unknown_1c4_[0x1d0 - 0x1c4];
    TableA68 titles_;
    TableA68 texts_;
    char unknown_1e0_[0x30d - 0x1e0];
    unsigned char unknown_30d_;
    char unknown_30e_[0x340 - 0x30e];
    void *unknown_340_;
    unsigned char unknown_344_;
};
#endif

extern "C" Messages02172e84 *MessageSystem_GetInstance();
extern "C" const char *func_02072a68(TableA68 *table, int key);
#if defined(jpn)
extern "C" void func_0204500c(Messages02172e84 *window, const char *text, int mode);
extern "C" void func_020e2168(char *dst, const char *arg1, int index, int female, int flag);
extern char data_ov003_0217eb9b[];
extern char data_ov003_0217ebff[];
extern char data_ov003_0217ec02[];
extern char data_ov003_0217ec1d[];
#else
extern "C" void func_0204500c(Messages02172e84 *window, const char *text, int mode, int width);
#endif
extern "C" Zone02172e84 *Zone3D_GetInstance(void);
extern "C" void __clear(void *dst, int count);
extern "C" void Font_DecodeText(Member02172e84 *member, char *buf, int flag);
extern "C" void *ExtractFileFromGP2(const char *arg0, const char *innerFilePath, unsigned int *outSize);
extern "C" char *func_020e046c(char *buf, void *data, unsigned int size, int idx);
extern "C" void func_ov003_0217bd38(void *obj, int arg);
extern "C" unsigned char func_ov017_021b1fa8(void *obj);
extern "C" void *LinkSession_GetInstance(void);
extern "C" int LinkSession_IsActive(int *obj);
extern "C" void LinkSession_End(void *obj);
extern "C" int func_ov003_021734dc(int unused, int a, int b);
extern "C" void SpriteEntryList_AdvanceAnimations(Container0205a330 *c, int arg);
extern "C" int func_020457e0(Messages02172e84 *window);
extern "C" int func_ov003_02172570(unsigned char *obj, void *extra);

extern char data_ov003_02180a49[];
extern char data_ov003_02180a4c[];
extern char data_ov003_02180a63[];

// USA: func_ov003_02172e84
#if defined(jpn)
extern "C" ARM void func_ov003_02172e84(Struct_ov003_02172e84_7 *self) {
    GameResources *res = GetGameResources();
    Messages02172e84 *msg = MessageSystem_GetInstance();
    Battle02172e84 *battle = (Battle02172e84 *) res->fieldTasks_[19];
    if (self->step_ == 0) {
        if (IsMainBrightnessTransitionActive(res) == 0) {
            func_0204500c(msg, data_ov003_0217eb9b, 0);
            msg->unknown_17ee_ = 1;
            msg->busy_ = 1;
            self->step_ = 1;
        }
    } else if (self->step_ == 1) {
        Zone02172e84 *zone = Zone3D_GetInstance();
        Struct_ov003_02172e84_5 *save = &zone->unknown_840_;
        unsigned char count = self->unknown_cc_->count_;
        unsigned int var6 = self->unknown_cc_->unknown_738_ & ~1;
        var6 &= var6 ^ save->unknown_1000_.unknown_b48_;
        if (battle->unknown_28_ != 0) {
            if (!inline_ov003_02172e84_3(self->unknown_cc_)) {
                self->unknown_350_ = 1;
            }
        }
        if (var6 != 0 && self->unknown_d0_ < 3) {
            self->unknown_d0_++;
            self->busy_ = 1;
            self->unknown_1_ = 1;
            int i;
            for (i = 1; i < 24; i++) {
                if (var6 & (1 << i)) break;
            }
            save->unknown_1000_.unknown_b48_ |= 1 << i;
            save->unknown_1000_.unknown_b4c_ |= 1 << i;
            sprintf(self->text_, data_ov003_0217ebff, func_02072a68(&self->texts_, (short) i));
            self->unknown_c2_++;
            self->step_ = 99;
        } else if (self->unknown_d1_ != count && self->unknown_d0_ < 3) {
            Member02172e84 *member = &self->unknown_cc_->members_[self->unknown_d1_];
            self->unknown_d1_++;
            self->busy_ = 1;
            self->unknown_d0_++;
            sprintf(self->text_, data_ov003_0217ebff, member);
            int accolade = inline_ov003_02172e84_2(inline_ov003_02172e84(member));
            if (accolade < 700) {
                func_020e2168(self->unknown_42_, data_ov003_0217ec02, (short) accolade, member->unknown_6c_.female_, 1);
            } else {
                sprintf(self->unknown_42_, data_ov003_0217ebff,
                        func_02072a68(&self->titles_, (short) (member->unknown_6c_.accolade_ + 20000)));
            }
            self->step_ = 99;
        } else if (self->unknown_350_ != 0 && !((*(unsigned short *) 0x27fffa8 & 0x8000) >> 15)) {
            self->unknown_34c_ = self->unknown_d4_;
            func_ov003_0217bd38(self->unknown_1ec_, self->unknown_1cc_);
            self->unknown_319_ = func_ov017_021b1fa8(battle);
            self->mode_ = 5;
            self->step_ = 0;
        } else {
            int x = g_touchInput.pressX_;
            int y = g_touchInput.pressY_;
            int curX;
            int curY;
            g_touchInput.GetTouchPoint(&curX, &curY);
            if (func_ov003_021734dc((int) self, x, y) && func_ov003_021734dc((int) self, curX, curY)) {
                self->active_ = 1;
                if (g_touchInput.released_ != 0) {
                    self->step_ = 2;
                }
            } else if (g_keyManager.TestKeysPressed(2)) {
                self->active_ = 1;
                self->step_ = 2;
            } else {
                self->active_ = 0;
            }
        }
    } else if (self->step_ == 2) {
        func_0204500c(msg, data_ov003_0217ec1d, 0);
        msg->busy_ = 1;
        self->step_ = 3;
    } else if (self->step_ == 3) {
        GameState *state = GameState::GetInstance();
        msg->unknown_228_ = self->unknown_13c_;
        msg->unknown_22c_ = self->unknown_134_;
        msg->entries_ = self->entries_;
        self->active_ = 0;
        Container0205a330 *entries = msg->entries_;
        SpriteEntryList_AdvanceAnimations(entries, state->GetTickCount() >> 2);
        if (msg->state_ == 0) {
            msg->busy_ = 1;
            if (func_020457e0(msg) == 0) {
                self->unknown_c8_ = 1;
                self->step_ = 4;
            } else {
                self->step_ = 0;
            }
        }
    } else if (self->step_ == 4) {
        if (self->unknown_c8_ != 0 && !inline_ov003_02172e84_3(self->unknown_cc_)) {
            self->mode_ = 4;
            self->step_ = 0;
            self->unknown_cc_->state_ = 10;
        } else if (inline_ov003_02172e84_3(self->unknown_cc_)) {
            func_ov003_02172570((unsigned char *) self->unknown_cc_, 0);
        }
    } else if (self->step_ == 99) {
        if (self->unknown_e9_ == 2) {
            self->step_ = 1;
        }
    }
}
#else
extern "C" ARM void func_ov003_02172e84(Struct_ov003_02172e84_7 *self) {
    GameResources *res = GetGameResources();
    Messages02172e84 *msg = MessageSystem_GetInstance();
    Battle02172e84 *battle = (Battle02172e84 *) res->fieldTasks_[19];
    if (self->step_ == 0) {
        if (IsMainBrightnessTransitionActive(res) == 0) {
            func_0204500c(msg, func_02072a68(&self->texts_, 100), 0, 0xe3);
            msg->unknown_19be_ = 1;
            msg->busy_ = 1;
            self->step_ = 1;
        }
    } else if (self->step_ == 1) {
        Zone02172e84 *zone = Zone3D_GetInstance();
        Struct_ov003_02172e84_5 *save = &zone->unknown_840_;
        unsigned char count = self->unknown_d0_->count_;
        unsigned int var22 = self->unknown_d0_->unknown_738_ & ~1;
        var22 &= var22 ^ save->unknown_1000_.unknown_b48_;
        if (battle->unknown_28_ != 0) {
            if (!inline_ov003_02172e84_3(self->unknown_d0_)) {
                self->unknown_344_ = 1;
            }
        }
        if (var22 != 0 && self->unknown_d4_ < 3) {
            self->unknown_d4_++;
            self->busy_ = 1;
            self->unknown_1_ = 1;
            int i;
            for (i = 1; i < 24; i++) {
                if (var22 & (1 << i)) break;
            }
            save->unknown_1000_.unknown_b48_ |= 1 << i;
            save->unknown_1000_.unknown_b4c_ |= 1 << i;
            sprintf(self->text_, data_ov003_02180a49, func_02072a68(&self->texts_, (short) i));
            self->unknown_2_ = i;
            self->unknown_c4_++;
            self->step_ = 99;
        } else if (self->unknown_d5_ != count && self->unknown_d4_ < 3) {
            Member02172e84 *member = &self->unknown_d0_->members_[self->unknown_d5_];
            self->unknown_d5_++;
            self->busy_ = 1;
            self->unknown_d4_++;
            char name[0x30];
            __clear(name, sizeof(name));
            Font_DecodeText(member, name, 1);
            sprintf(self->text_, data_ov003_02180a49, name);
            if (inline_ov003_02172e84_2(inline_ov003_02172e84(member)) < 700) {
                BackgroundLoader::AddLockGlobal();
                unsigned int size = 0;
                char path[0x40];
                char inner[0x20];
                __clear(path, sizeof(path));
                __clear(inner, sizeof(inner));
                sprintf(path, data_ov003_02180a4c, member->unknown_6c_.female_);
                sprintf(inner, data_ov003_02180a63, member->unknown_6c_.female_);
                void *file = ExtractFileFromGP2(path, inner, &size);
                if (file != 0) {
                    func_020e046c(self->unknown_44_, file, size, (short) member->unknown_6c_.accolade_);
                }
                BackgroundLoader::RemoveLockGlobal();
            } else {
                sprintf(self->unknown_44_, data_ov003_02180a49,
                        func_02072a68(&self->titles_, (short) (member->unknown_6c_.accolade_ + 20000)));
            }
            self->step_ = 99;
        } else if (self->unknown_344_ != 0 && !((*(unsigned short *) 0x27fffa8 & 0x8000) >> 15)) {
            self->unknown_340_ = self->unknown_d8_;
            func_ov003_0217bd38(self->unknown_1e0_, self->unknown_1c0_);
            self->unknown_30d_ = func_ov017_021b1fa8(battle);
            self->unknown_d0_->state_ = 10;
            void *save = LinkSession_GetInstance();
            if (LinkSession_IsActive((int *) save)) {
                LinkSession_End(save);
            }
            self->mode_ = 5;
            self->step_ = 0;
        } else {
            int x = g_touchInput.pressX_;
            int y = g_touchInput.pressY_;
            int curX;
            int curY;
            g_touchInput.GetTouchPoint(&curX, &curY);
            if (func_ov003_021734dc((int) self, x, y) && func_ov003_021734dc((int) self, curX, curY)) {
                self->active_ = 1;
                if (g_touchInput.released_ != 0) {
                    self->step_ = 2;
                }
            } else if (g_keyManager.TestKeysPressed(2)) {
                self->active_ = 1;
                self->step_ = 2;
            } else {
                self->active_ = 0;
            }
        }
    } else if (self->step_ == 2) {
        func_0204500c(msg, func_02072a68(&self->texts_, 101), 0, 0xe3);
        msg->busy_ = 1;
        self->step_ = 3;
    } else if (self->step_ == 3) {
        GameState *state = GameState::GetInstance();
        msg->unknown_2d8_ = self->unknown_130_;
        msg->unknown_2dc_ = self->unknown_128_;
        msg->entries_ = self->entries_;
        self->active_ = 0;
        Container0205a330 *entries = msg->entries_;
        SpriteEntryList_AdvanceAnimations(entries, state->GetTickCount() >> 2);
        if (msg->state_ == 0) {
            msg->busy_ = 1;
            if (func_020457e0(msg) == 0) {
                self->unknown_ca_ = 1;
                self->step_ = 4;
            } else {
                self->step_ = 0;
            }
        }
    } else if (self->step_ == 4) {
        if (self->unknown_ca_ != 0 && !inline_ov003_02172e84_3(self->unknown_d0_)) {
            self->mode_ = 4;
            self->step_ = 0;
            self->unknown_d0_->state_ = 10;
        } else if (inline_ov003_02172e84_3(self->unknown_d0_)) {
            func_ov003_02172570((unsigned char *) self->unknown_d0_, 0);
        }
    } else if (self->step_ == 99) {
        if (self->unknown_ed_ == 2) {
            self->step_ = 1;
        }
    }
}
#endif
