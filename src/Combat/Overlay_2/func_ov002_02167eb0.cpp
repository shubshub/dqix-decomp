#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Input/Input.h"

class GameState;
struct Struct_0205de24_2;
struct Struct_0205c570;
struct Struct_0205d81c;
struct SePlayer;

void FindAndLinkMatchingEntry0205de24(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
int Window_GetSelectedIndex(struct Struct_0205c570 *s);
struct Obj_0205da38;
int Window_IsSelectionTouched(struct Obj_0205da38* obj, int key);
void SePlayer_Play(struct SePlayer *o, int a, int b);
int CheckFlagOrThreshold_02161b48(char *self, int flag);
void Window_SetPanePalette(struct Struct_0205d81c *s, int key, int value);
void *GameState_GetParty(GameState *gs);
unsigned char *GetFieldAt0x150_02053c6c(unsigned char *c);
extern "C" void func_ov002_02161cf0(void *self);
extern "C" void func_ov002_0215fb54(void *self);
extern "C" void func_ov002_0215b9a4(void *self, int mode, int flag);
extern "C" void func_ov002_02156e90(void *self);
extern char g_sePlayer[];

// USA: func_ov002_02167eb0
#if defined(jpn)
extern "C" ARM void func_ov002_02167eb0(char *arg0) {
    int var0 = *(int *) (arg0 + 0x1a88);
    if (var0 == 0) {
        func_0205de24((struct Struct_0205de24_2 *) (arg0 + 0xe20), 0, 3);
        func_ov002_02161cf0(arg0);
        func_ov002_0215fb54(arg0);
        (*(int *) (arg0 + 0x1a88))++;
        return;
    }
    if (phase != 1) return;
    *(int *) (base + 0x22ac) |= 4;
    short old                  = *(short *) (base + 0x1acc);
    *(short *) (base + 0x1acc) = Window_GetSelectedIndex((struct Struct_0205c570 *) (base + 0xe20));
    if (old != *(short *) (base + 0x1acc)) return;
    int pressed = g_keyManager.TestKeysPressed(0x601);
    int confirm = (pressed | Window_IsSelectionTouched((struct Obj_0205da38*)(base + 0xe20), 0x14)) ? 1 : 0;
    if (confirm) {
        func_ov002_0215b9a4(base, *(int *) (base + 0x1a80) & 0xff, 1);
        SePlayer_Play((struct SePlayer *) g_sePlayer, 1, 0);
        GameState *gs = GameState::GetInstance();
        GameState_GetParty(gs);
        unsigned char *m = (unsigned char *)gs->GetPartyMemberByIndex(*(signed char *) (base + 0x1ae8));
        if (m == 0) return;
        *(int *) (GetFieldAt0x150_02053c6c(m) + 0x8b4) = *(short *) (base + 0x1acc);
        *(short *) (base + 0x1acc)            = -1;
        func_ov002_02156e90(base);
        Window_SetPanePalette((struct Struct_0205d81c *) (base + 0xe20), 0x1b, 0);
        Window_SetPanePalette((struct Struct_0205d81c *) (base + 0xe20), 0x1c, 0);
        return;
    }
    if (CheckFlagOrThreshold_02161b48(base, 1)) {
        *(short *) (base + 0x1acc) = -1;
        func_ov002_02156e90(base);
        Window_SetPanePalette((struct Struct_0205d81c *) (base + 0xe20), 0x1b, 0);
        Window_SetPanePalette((struct Struct_0205d81c *) (base + 0xe20), 0x1c, 0);
    }
}
#else
extern "C" ARM void func_ov002_02167eb0(char *arg0) {
    int var6 = *(int *) (arg0 + 0x1bc0);
    if (var6 == 0) {
        func_0205de24((struct Struct_0205de24_2 *) (arg0 + 0xec8), 0, 3);
        func_ov002_02161cf0(arg0);
        func_ov002_0215fb54(arg0);
        (*(int *) (arg0 + 0x1bc0))++;
        return;
    }
    if (phase != 1) return;
    *(int *) (base + 0x247c) |= 4;
    short old                  = *(short *) (base + 0x1c04);
    *(short *) (base + 0x1c04) = Window_GetSelectedIndex((struct Struct_0205c570 *) (base + 0xec8));
    if (old != *(short *) (base + 0x1c04)) return;
    int pressed = g_keyManager.TestKeysPressed(0x601);
    int confirm = (pressed | Window_IsSelectionTouched((struct Obj_0205da38*)(base + 0xec8), 0x14)) ? 1 : 0;
    if (confirm) {
        func_ov002_0215b9a4(base, *(int *) (base + 0x1bb8) & 0xff, 1);
        SePlayer_Play((struct SePlayer *) g_sePlayer, 1, 0);
        GameState *gs = GameState::GetInstance();
        GameState_GetParty(gs);
        unsigned char *m = (unsigned char *)gs->GetPartyMemberByIndex(*(signed char *) (base + 0x1c20));
        if (m == 0) return;
        *(int *) (GetFieldAt0x150_02053c6c(m) + 0x94c) = *(short *) (base + 0x1c04);
        *(short *) (base + 0x1c04)            = -1;
        func_ov002_02156e90(base);
        Window_SetPanePalette((struct Struct_0205d81c *) (base + 0xec8), 0x1a, 0);
        Window_SetPanePalette((struct Struct_0205d81c *) (base + 0xec8), 0x1b, 0);
        return;
    }
    if (CheckFlagOrThreshold_02161b48(base, 1)) {
        *(short *) (base + 0x1c04) = -1;
        func_ov002_02156e90(base);
        Window_SetPanePalette((struct Struct_0205d81c *) (base + 0xec8), 0x1a, 0);
        Window_SetPanePalette((struct Struct_0205d81c *) (base + 0xec8), 0x1b, 0);
    }
}
#endif
