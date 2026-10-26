#include "GameState/GameState.h"
#include <globaldefs.h>
#include "Input/Input.h"
#include "Resource/GameResources.h"

struct Run02012fe4;
extern "C" struct Run02012fe4 *Zone3D_GetInstance(void);
extern "C" void func_0205d7a0(void *list, int index);
extern "C" void ColorEffect_ConfigureAlphaBlend(unsigned int *out, unsigned char a, unsigned char b, unsigned char c, int d);
extern "C" char *MessageSystem_GetInstance(void);
struct Container0205a330;
extern "C" void SpriteEntryList_AdvanceAnimations(struct Container0205a330 *c, int arg);
struct Struct_0205c570;
extern "C" int Window_GetSelectedIndex(struct Struct_0205c570 *s);
struct Obj_0205da38;
extern "C" int Window_IsSelectionTouched(struct Obj_0205da38* obj, int key);
extern "C" int func_0205d97c(void *p);
struct Entry_0205d6a0;
extern "C" void Window_ClosePane(struct Entry_0205d6a0 *a, int flag);
extern "C" void MessageSystem_Reset(char *obj);
struct SePlayer;
extern struct SePlayer g_sePlayer;
extern "C" void SePlayer_Play(struct SePlayer *obj, int a, int b);
extern "C" void func_ov017_021baedc(void *self, int flag);
struct TailList020469b4;
struct TailNode020469b4;
extern "C" void func_020469b4(struct TailList020469b4 *list, struct TailNode020469b4 *node);
extern "C" void FieldTask_InitEnterZone(unsigned char *obj, int arg);
extern "C" void *GameState_GetZoneTransition(GameState *state);
extern "C" void func_02070378(char *obj);

struct Struct_ov003_0217d6ac_2;
extern "C" void func_ov003_0217dd60(Struct_ov003_0217d6ac_2 *self);
extern "C" int func_ov003_0217e1e4(Struct_ov003_0217d6ac_2 *self);
extern "C" void func_ov003_0217dfb4(Struct_ov003_0217d6ac_2 *self);

#if defined(jpn)
#define RG(usa, jpn) (jpn)
#else
#define RG(usa, jpn) (usa)
#endif

struct Progress02012fe4 {
    unsigned char pad0[RG(0xb3c, 0x1b3c)];
    int chapter;
};

struct Run02012fe4 {
    unsigned char pad0[RG(0x1840, 0x860)];
    struct Progress02012fe4 progress;
};

static inline struct Progress02012fe4 *GetProgress(struct Run02012fe4 *run) { return &run->progress; }
static inline int inline_ov003_0217d6ac(struct Progress02012fe4 *progress) { return progress->chapter; }

struct Struct_ov003_0217d6ac_3 {
    unsigned char pad0[0x8];
    unsigned short messageId;
    unsigned char padA[RG(0x10b, 0x107) - 0xa];
    unsigned char active;
};

struct EventRecord_0217d6ac {
    unsigned short id;
    unsigned char pad2[0x7 - 0x2];
    unsigned char unknown_7_;
    unsigned char pad8[0xc - 0x8];
    unsigned char unknown_c_;
    unsigned char padD[0x14 - 0xd];
    int unknown_14_;
    int unknown_18_;
};

struct Struct_ov003_0217d6ac_2 {
    unsigned char pad0[0x4];
    unsigned char state;
    signed char busy;
    unsigned char pad6[RG(0x14, 0x10) - 0x6];
    int unknown_14_;
    unsigned char ids[0x32 - 0x18];
    unsigned char count;
    unsigned char unknown_33_[0x90 - 0x33];
    void *list;
};

// USA: func_ov003_0217d6ac
extern "C" ARM void func_ov003_0217d6ac(Struct_ov003_0217d6ac_2 *self) {
    GameState *gs;
    char *res;
    char *global;
    int extra;
    int sel;
    struct TailList020469b4 *list;
#if defined(jpn)
    struct Progress02012fe4 *progress;
#else
    struct Run02012fe4 *current;
#endif
    res     = (char *) GetGameResources();
    list    = *(struct TailList020469b4 **) (res + RG(0x36fc, 0x34ec));
#if defined(jpn)
    progress = GetProgress(Zone3D_GetInstance());
#else
    current = Zone3D_GetInstance();
#endif
    if (self->busy == 0) {
        func_0205d7a0(self->list, 0);
        func_ov003_0217dd60(self);
        ColorEffect_ConfigureAlphaBlend((unsigned int *) 0x04000050, 4, 1, 10, 6);
        self->busy = 1;
        return;
    }
    if (self->busy != 1) return;

    gs                                = GameState::GetInstance();
    global                            = MessageSystem_GetInstance();
    struct Container0205a330 *entries = *(struct Container0205a330 **) (global + RG(0x2e0, 0x230));
    SpriteEntryList_AdvanceAnimations(entries, gs->GetTickCount());
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
        sel = -2;
    } else if (func_0205d97c(self->list) == 2) {
        sel = -2;
    }
    if (self->unknown_14_ != 0 || extra != 0) {
        func_ov003_0217dfb4(self);
    }
    if (sel == -2) {
        self->state = 4;
        self->busy  = 0;
        Window_ClosePane((struct Entry_0205d6a0 *) self->list, 0);
        MessageSystem_Reset(global);
        return;
    }
    if (sel == -1) return;

    self->state = 4;
    self->busy  = 0;
    SePlayer_Play(&g_sePlayer, 1, 0);
    Window_ClosePane((struct Entry_0205d6a0 *) self->list, 0);
    MessageSystem_Reset(global);
    Struct_ov003_0217d6ac_3 *event = *(Struct_ov003_0217d6ac_3 **) (res + RG(0x3734, 0x3524));
    func_ov017_021baedc(event, 1);
    event->active = 1;
#if defined(jpn)
    switch (inline_ov003_0217d6ac(progress)) {
#else
    switch (inline_ov003_0217d6ac(GetProgress(current))) {
#endif
        case 0:
        case 1:
        case 2: event->messageId = 0xd067; break;
        case 3:
        case 4: event->messageId = 0xd068; break;
        case 5: event->messageId = 0xd069; break;
        case 6: event->messageId = 0xd06a; break;
    }
    func_020469b4(list, (struct TailNode020469b4 *) event);
    if (sel != 0) {
        unsigned char *header = *(unsigned char **) (res + RG(0x370c, 0x34fc));
        FieldTask_InitEnterZone(header, 0);
        EventRecord_0217d6ac *record = (EventRecord_0217d6ac *) GameState_GetZoneTransition(gs);
        func_02070378((char *) record);
        record->id         = self->ids[sel] + 0xc544;
        record->unknown_7_  = 1;
        record->unknown_14_ = 0x2b8;
        record->unknown_18_ = -0x7b33;
        record->unknown_c_  = 1;
        func_020469b4(list, (struct TailNode020469b4 *) header);
    } else {
        unsigned char *header = *(unsigned char **) (res + RG(0x370c, 0x34fc));
        FieldTask_InitEnterZone(header, 0);
        EventRecord_0217d6ac *record = (EventRecord_0217d6ac *) GameState_GetZoneTransition(gs);
        func_02070378((char *) record);
        record->id         = 0xc3bc;
        record->unknown_7_  = 1;
        record->unknown_14_ = 0x266;
        record->unknown_18_ = -0x7b33;
        record->unknown_c_  = 1;
        func_020469b4(list, (struct TailNode020469b4 *) header);
    }
}
