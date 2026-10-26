#include "GameState/GameState.h"
#include <globaldefs.h>
#include "Input/Input.h"
#include "Resource/GameResources.h"

struct Struct_0205c570;
struct SePlayer;

extern "C" int Window_GetSelectedIndex(struct Struct_0205c570 *s);
extern "C" int func_ov002_02161b48(char *self, int flag);
struct Obj_0205da38;
extern "C" int Window_IsSelectionTouched(struct Obj_0205da38* obj, int key);
extern "C" void *func_02053c6c(unsigned char *p);
extern "C" void SePlayer_Play(SePlayer *obj, int a, int b);
extern "C" void func_ov002_0215af64(char *self);
extern "C" void func_ov002_02161cf0(char *self);
extern "C" void func_ov002_02160068(char *self);
extern "C" void func_ov002_0215b9a4(char *self, unsigned char key, int flag);
extern "C" void func_ov017_0218f5a4(void *obj, int id, int b, int c, int d);
extern "C" void func_ov002_02161a8c();
extern "C" void func_020dc7e8(int a, int b);
extern "C" int *LinkSession_GetInstance();
extern "C" int LinkSession_IsActive(int *p);
extern "C" void func_ov017_021d0dbc();
extern "C" void func_ov002_02156e90(char *self);
struct Struct_0205d81c;
extern "C" void Window_SetPanePalette(Struct_0205d81c*, int, int);

extern SePlayer g_sePlayer;

// USA: func_ov002_0216806c
#if defined(jpn)
extern "C" ARM void func_ov002_0216806c(char *self) {
    int phase = *(int *) (self + 0x1a88);
    if (phase == 0) {
        func_ov002_02161cf0(self);
        func_ov002_02160068(self);
        func_ov002_02161cf0(self);
        func_ov002_0215af64(self);
        (*(int *) (self + 0x1a88))++;
    } else if (phase == 1) {
        short old                  = *(short *) (self + 0x1ace);
        *(short *) (self + 0x1ace) = Window_GetSelectedIndex((struct Struct_0205c570 *) (self + 0xe20));
        if (old != *(short *) (self + 0x1ace)) {
            func_ov002_0215af64(self);
            func_ov002_0215b9a4(self, 0x1e, 0);
        }
        int a  = g_keyManager.TestKeysPressed(0x601);
        int b  = Window_IsSelectionTouched((struct Obj_0205da38*)(self + 0xe20), 0x14);
        int ok = (a | b) ? 1 : 0;
        if (ok) {
            SePlayer_Play(&g_sePlayer, 1, 0);
            int id             = *(signed char *) (self + 0x1ae8);
            GameObject *member = GameState::GetInstance()->GetPartyMemberByIndex(id);
            if (member == 0) return;
            unsigned char *f = (unsigned char *) func_02053c6c((unsigned char *) member);
            if (f[0x56a] != *(short *) (self + 0x1ace) && *(short *) (f + 0x488) < 0) {
                member->obj3D_.unknown_2_ = -1;
                func_ov017_0218f5a4(GetGameResources(), id, 0, 0, 0);
            }
            f[0x56a] = *(short *) (self + 0x1ace);
            func_ov002_02161a8c();
            func_020dc7e8(1, -1);
            func_020dc7e8(8, -1);
            func_020dc7e8(6, -1);
            func_020dc7e8(7, -1);
            int *p = LinkSession_GetInstance();
            if (p != 0 && LinkSession_IsActive(p)) {
                func_ov017_021d0dbc();
            }
            func_ov002_02156e90(self);
            func_ov002_02156e90(self);
            Window_SetPanePalette((Struct_0205d81c*)(self + 0xe20), 0x19, 0);
            Window_SetPanePalette((Struct_0205d81c*)(self + 0xe20), 0x1b, 0);
            Window_SetPanePalette((Struct_0205d81c*)(self + 0xe20), 0x1c, 0);
        } else if (func_ov002_02161b48(self, 1)) {
            func_ov002_02156e90(self);
            func_ov002_02156e90(self);
            Window_SetPanePalette((Struct_0205d81c*)(self + 0xe20), 0x19, 0);
            Window_SetPanePalette((Struct_0205d81c*)(self + 0xe20), 0x1b, 0);
            Window_SetPanePalette((Struct_0205d81c*)(self + 0xe20), 0x1c, 0);
        }
    }
}
#else
extern "C" ARM void func_ov002_0216806c(char *self) {
    int phase = *(int *) (self + 0x1bc0);
    if (phase == 0) {
        func_ov002_02161cf0(self);
        func_ov002_02160068(self);
        func_ov002_02161cf0(self);
        func_ov002_0215af64(self);
        (*(int *) (self + 0x1bc0))++;
    } else if (phase == 1) {
        short old                  = *(short *) (self + 0x1c06);
        *(short *) (self + 0x1c06) = Window_GetSelectedIndex((struct Struct_0205c570 *) (self + 0xec8));
        if (old != *(short *) (self + 0x1c06)) {
            func_ov002_0215af64(self);
            func_ov002_0215b9a4(self, 0x1d, 0);
        }
        int a  = g_keyManager.TestKeysPressed(0x601);
        int b  = Window_IsSelectionTouched((struct Obj_0205da38*)(self + 0xec8), 0x14);
        int ok = (a | b) ? 1 : 0;
        if (ok) {
            SePlayer_Play(&g_sePlayer, 1, 0);
            int id             = *(signed char *) (self + 0x1c20);
            GameObject *member = GameState::GetInstance()->GetPartyMemberByIndex(id);
            if (member == 0) return;
            unsigned char *f = (unsigned char *) func_02053c6c((unsigned char *) member);
            if (f[0x56a] != *(short *) (self + 0x1c06) && *(short *) (f + 0x488) < 0) {
                member->obj3D_.unknown_2_ = -1;
                func_ov017_0218f5a4(GetGameResources(), id, 0, 0, 0);
            }
            f[0x56a] = *(short *) (self + 0x1c06);
            func_ov002_02161a8c();
            func_020dc7e8(1, -1);
            func_020dc7e8(8, -1);
            func_020dc7e8(6, -1);
            func_020dc7e8(7, -1);
            int *p = LinkSession_GetInstance();
            if (p != 0 && LinkSession_IsActive(p)) {
                func_ov017_021d0dbc();
            }
            func_ov002_02156e90(self);
            func_ov002_02156e90(self);
            Window_SetPanePalette((Struct_0205d81c*)(self + 0xec8), 0x18, 0);
            Window_SetPanePalette((Struct_0205d81c*)(self + 0xec8), 0x1a, 0);
            Window_SetPanePalette((Struct_0205d81c*)(self + 0xec8), 0x1b, 0);
        } else if (func_ov002_02161b48(self, 1)) {
            func_ov002_02156e90(self);
            func_ov002_02156e90(self);
            Window_SetPanePalette((Struct_0205d81c*)(self + 0xec8), 0x18, 0);
            Window_SetPanePalette((Struct_0205d81c*)(self + 0xec8), 0x1a, 0);
            Window_SetPanePalette((Struct_0205d81c*)(self + 0xec8), 0x1b, 0);
        }
    }
}
#endif
