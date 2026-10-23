#include "GameState/GameState.h"
#include <globaldefs.h>
#include "Input/Input.h"
#include "Resource/GameResources.h"

struct Struct_ov003_0217d6ac;
extern "C" struct Struct_ov003_0217d6ac *func_02012fe4(void);
extern "C" void func_0205d7a0(void *arg0, int arg1);
extern "C" void ColorEffect_ConfigureAlphaBlend(unsigned int *out, unsigned char a, unsigned char b, unsigned char c, int d);
extern "C" char *func_020421a0(void);
struct Struct_0205a330;
extern "C" void func_0205a330(struct Struct_0205a330 *arg0, int arg1);
struct Struct_0205c570;
int Window_GetSelectedIndex(struct Struct_0205c570 *s);
struct Obj_0205da38;
int Window_IsSelectionTouched(struct Obj_0205da38* obj, int key);
extern "C" int func_0205d97c(void *p);
struct Entry_0205d6a0;
void ResetEntryList0205d6a0(struct Entry_0205d6a0 *a, int flag);
void ReinitController02043204(char *obj);
struct SePlayer;
extern struct SePlayer g_sePlayer;
void SePlayer_Play(struct SePlayer *obj, int a, int b);
extern "C" void func_ov017_021baedc(void *self, int flag);
struct TailList020469b4;
struct TailNode020469b4;
void AppendNodeToTail(struct TailList020469b4 *list, struct TailNode020469b4 *node);
void InitAndResetHeader_0219e310(unsigned char *obj, int arg);
void *GetField0x3f8Address_0200fd0c(GameState *state);
void InitStruct02070378(char *obj);

struct Struct_ov003_0217d6ac_2;
extern "C" void func_ov003_0217dd60(Struct_ov003_0217d6ac_2 *arg0);
extern "C" int func_ov003_0217e1e4(Struct_ov003_0217d6ac_2 *arg0);
extern "C" void func_ov003_0217dfb4(Struct_ov003_0217d6ac_2 *arg0);

#if defined(jpn)
#define RG(usa, jpn) (jpn)
#else
#define RG(usa, jpn) (usa)
#endif

struct Struct_ov003_0217d53c_4 {
    unsigned char unknown_0_[RG(0xb3c, 0x1b3c)];
    int unknown_b3c_;
};

struct Struct_ov003_0217d6ac {
    unsigned char unknown_0_[RG(0x1840, 0x860)];
    struct Struct_ov003_0217d53c_4 unknown_1840_;
};

static inline struct Struct_ov003_0217d53c_4 *inline_ov003_0216e714_2(struct Struct_ov003_0217d6ac *arg0) { return &arg0->unknown_1840_; }
static inline int inline_ov003_0217d6ac(struct Struct_ov003_0217d53c_4 *arg0) { return arg0->unknown_b3c_; }

struct Struct_ov003_0217d6ac_3 {
    unsigned char unknown_0_[0x8];
    unsigned short unknown_8_;
    unsigned char unknown_a_[RG(0x10b, 0x107) - 0xa];
    unsigned char unknown_10b_;
};

struct Struct_ov003_0217d6ac_4 {
    unsigned short unknown_0_;
    unsigned char unknown_2_[0x7 - 0x2];
    unsigned char unknown_7_;
    unsigned char unknown_8_[0xc - 0x8];
    unsigned char unknown_c_;
    unsigned char unknown_d_[0x14 - 0xd];
    int unknown_14_;
    int unknown_18_;
};

struct Struct_ov003_0217d6ac_2 {
    unsigned char unknown_0_[0x4];
    unsigned char unknown_4_;
    signed char unknown_5_;
    unsigned char unknown_6_[RG(0x14, 0x10) - 0x6];
    int unknown_14_;
    unsigned char unknown_18_[0x32 - 0x18];
    unsigned char unknown_32_;
    unsigned char unknown_33_[0x90 - 0x33];
    void *unknown_90_;
};

// USA: func_ov003_0217d6ac
extern "C" ARM void func_ov003_0217d6ac(Struct_ov003_0217d6ac_2 *arg0) {
    GameState *var0;
    char *var1;
    char *var2;
    int var3;
    int var4;
    struct Struct_0201bdac_2 *var5;
#if defined(jpn)
    struct Struct_ov003_0217d53c_4 *var6;
#else
    struct Struct_ov003_0217d6ac *var7;
#endif
    var1     = (char *) GetGameResources();
    var5    = *(struct Struct_0201bdac_2 **) (var1 + RG(0x36fc, 0x34ec));
#if defined(jpn)
    var6 = inline_ov003_0216e714_2(func_02012fe4());
#else
    var7 = func_02012fe4();
#endif
    if (arg0->unknown_5_ == 0) {
        func_0205d7a0(arg0->unknown_90_, 0);
        func_ov003_0217dd60(arg0);
        ColorEffect_ConfigureAlphaBlend((unsigned int *) 0x04000050, 4, 1, 10, 6);
        arg0->unknown_5_ = 1;
        return;
    }
    if (arg0->unknown_5_ != 1) return;

    gs                                = GameState::GetInstance();
    global                            = GetGlobalField0x1c020421a0();
    struct Container0205a330 *entries = *(struct Container0205a330 **) (global + RG(0x2e0, 0x230));
    IterateEntries0205a330(entries, gs->GetTickCount());
    global[RG(0x19ae, 0x17de)] = 0;
    Window_GetSelectedIndex((struct Struct_0205c570 *) self->list);
    extra = 0;
    if (self->count > 1) {
        extra = func_ov003_0217e1e4(self);
    }
    sel = -1;
    if (Window_IsSelectionTouched((struct Obj_0205da38*)self->list, 0x14) == 1) {
        sel = Window_GetSelectedIndex((struct Struct_0205c570 *) self->list);
    } else if (g_keyManager.TestKeysPressed(0x601) != 0) {
        sel = Window_GetSelectedIndex((struct Struct_0205c570 *) self->list);
    } else if (g_keyManager.TestKeysPressed(2) != 0) {
        var4 = -2;
    } else if (func_0205d97c(arg0->unknown_90_) == 2) {
        var4 = -2;
    }
    if (arg0->unknown_14_ != 0 || var3 != 0) {
        func_ov003_0217dfb4(arg0);
    }
    if (var4 == -2) {
        arg0->unknown_4_ = 4;
        arg0->unknown_5_  = 0;
        func_0205d6a0((struct Struct_0205d6a0 *) arg0->unknown_90_, 0);
        func_02043204(var2);
        return;
    }
    if (var4 == -1) return;

    self->state = 4;
    self->busy  = 0;
    SePlayer_Play(&g_sePlayer, 1, 0);
    ResetEntryList0205d6a0((struct Entry_0205d6a0 *) self->list, 0);
    ReinitController02043204(global);
    BattleEvent_0217d6ac *event = *(BattleEvent_0217d6ac **) (res + RG(0x3734, 0x3524));
    func_ov017_021baedc(event, 1);
    event->active = 1;
#if defined(jpn)
    switch (inline_ov003_0217d6ac(var6)) {
#else
    switch (inline_ov003_0217d6ac(inline_ov003_0216e714_2(var7))) {
#endif
        case 0:
        case 1:
        case 2: var9->unknown_8_ = 0xd067; break;
        case 3:
        case 4: var9->unknown_8_ = 0xd068; break;
        case 5: var9->unknown_8_ = 0xd069; break;
        case 6: var9->unknown_8_ = 0xd06a; break;
    }
    func_020469b4(var5, (struct Struct_0201bdac *) var9);
    if (var4 != 0) {
        unsigned char *var10 = *(unsigned char **) (var1 + RG(0x370c, 0x34fc));
        func_ov017_0219e310(var10, 0);
        Struct_ov003_0217d6ac_4 *var11 = (Struct_ov003_0217d6ac_4 *) func_0200fd0c(var0);
        func_02070378((char *) var11);
        var11->unknown_0_         = arg0->unknown_18_[var4] + 0xc544;
        var11->unknown_7_  = 1;
        var11->unknown_14_ = 0x2b8;
        var11->unknown_18_ = -0x7b33;
        var11->unknown_c_  = 1;
        func_020469b4(var5, (struct Struct_0201bdac *) var10);
    } else {
        unsigned char *var12 = *(unsigned char **) (var1 + RG(0x370c, 0x34fc));
        func_ov017_0219e310(var12, 0);
        Struct_ov003_0217d6ac_4 *var13 = (Struct_ov003_0217d6ac_4 *) func_0200fd0c(var0);
        func_02070378((char *) var13);
        var13->unknown_0_         = 0xc3bc;
        var13->unknown_7_  = 1;
        var13->unknown_14_ = 0x266;
        var13->unknown_18_ = -0x7b33;
        var13->unknown_c_  = 1;
        func_020469b4(var5, (struct Struct_0201bdac *) var12);
    }
}
