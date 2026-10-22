#include "GameState/GameState.h"
#include <globaldefs.h>
#include "Input/Input.h"
#include "Resource/GameResources.h"

struct Struct_0205c570;
struct SePlayer;

int GetActiveScaledSum0205d794(struct Struct_0205c570 *s);
int CheckFlagOrThreshold_02161b48(char *self, int flag);
struct Obj_0205da38;
int IsActiveElementFlag2Set0205da38(struct Obj_0205da38* obj, int key);
void *GetFieldAt0x150_02053c6c(unsigned char *p);
void SePlayer_Play(SePlayer *obj, int a, int b);
void CopyPaletteEntry0215af64(char *self);
extern "C" void func_ov002_02161cf0(char *self);
extern "C" void func_ov002_02160068(char *self);
extern "C" void func_ov002_0215b9a4(char *self, unsigned char key, int flag);
extern "C" void func_ov017_0218f5a4(void *obj, int id, int b, int c, int d);
extern "C" void func_ov002_02161a8c();
extern "C" void func_020dc7e8(int arg0, int arg1);
extern "C" int *func_0202ae18();
extern "C" int func_0202b7d8(int *arg0);
extern "C" void func_ov017_021d0dbc();
extern "C" void func_ov002_02156e90(char *arg0);
struct Struct_0205d81c;
extern "C" void func_0205deb4(Struct_0205d81c*, int, int);

extern SePlayer g_sePlayer;

// USA: func_ov002_0216806c
#if defined(jpn)
extern "C" ARM void func_ov002_0216806c(char *arg0) {
    int var0 = *(int *) (arg0 + 0x1a88);
    if (var0 == 0) {
        func_ov002_02161cf0(arg0);
        func_ov002_02160068(arg0);
        func_ov002_02161cf0(arg0);
        func_ov002_0215af64(arg0);
        (*(int *) (arg0 + 0x1a88))++;
    } else if (var0 == 1) {
        short var1                  = *(short *) (arg0 + 0x1ace);
        *(short *) (arg0 + 0x1ace) = func_0205d794((struct Struct_0205c570 *) (arg0 + 0xe20));
        if (var1 != *(short *) (arg0 + 0x1ace)) {
            func_ov002_0215af64(arg0);
            func_ov002_0215b9a4(arg0, 0x1e, 0);
        }
        int a  = g_keyManager.TestKeysPressed(0x601);
        int b  = IsActiveElementFlag2Set0205da38((struct Obj_0205da38*)(self + 0xe20), 0x14);
        int ok = (a | b) ? 1 : 0;
        if (ok) {
            SePlayer_Play(&g_sePlayer, 1, 0);
            int id             = *(signed char *) (self + 0x1ae8);
            GameObject *member = GameState::GetInstance()->GetPartyMemberByIndex(id);
            if (member == 0) return;
            unsigned char *f = (unsigned char *) GetFieldAt0x150_02053c6c((unsigned char *) member);
            if (f[0x56a] != *(short *) (self + 0x1ace) && *(short *) (f + 0x488) < 0) {
                member->obj3D_.unknown_2_ = -1;
                func_ov017_0218f5a4(GetGameResources(), id, 0, 0, 0);
            }
            var7[0x56a] = *(short *) (arg0 + 0x1ace);
            func_ov002_02161a8c();
            func_020dc7e8(1, -1);
            func_020dc7e8(8, -1);
            func_020dc7e8(6, -1);
            func_020dc7e8(7, -1);
            int *var8 = func_0202ae18();
            if (var8 != 0 && func_0202b7d8(var8)) {
                func_ov017_021d0dbc();
            }
            func_ov002_02156e90(arg0);
            func_ov002_02156e90(arg0);
            func_0205deb4((Struct_0205d81c*)(arg0 + 0xe20), 0x19, 0);
            func_0205deb4((Struct_0205d81c*)(arg0 + 0xe20), 0x1b, 0);
            func_0205deb4((Struct_0205d81c*)(arg0 + 0xe20), 0x1c, 0);
        } else if (func_ov002_02161b48(arg0, 1)) {
            func_ov002_02156e90(arg0);
            func_ov002_02156e90(arg0);
            func_0205deb4((Struct_0205d81c*)(arg0 + 0xe20), 0x19, 0);
            func_0205deb4((Struct_0205d81c*)(arg0 + 0xe20), 0x1b, 0);
            func_0205deb4((Struct_0205d81c*)(arg0 + 0xe20), 0x1c, 0);
        }
    }
}
#else
extern "C" ARM void func_ov002_0216806c(char *arg0) {
    int var9 = *(int *) (arg0 + 0x1bc0);
    if (var9 == 0) {
        func_ov002_02161cf0(arg0);
        func_ov002_02160068(arg0);
        func_ov002_02161cf0(arg0);
        func_ov002_0215af64(arg0);
        (*(int *) (arg0 + 0x1bc0))++;
    } else if (var9 == 1) {
        short var10                  = *(short *) (arg0 + 0x1c06);
        *(short *) (arg0 + 0x1c06) = func_0205d794((struct Struct_0205c570 *) (arg0 + 0xec8));
        if (var10 != *(short *) (arg0 + 0x1c06)) {
            func_ov002_0215af64(arg0);
            func_ov002_0215b9a4(arg0, 0x1d, 0);
        }
        int a  = g_keyManager.TestKeysPressed(0x601);
        int b  = IsActiveElementFlag2Set0205da38((struct Obj_0205da38*)(self + 0xec8), 0x14);
        int ok = (a | b) ? 1 : 0;
        if (ok) {
            SePlayer_Play(&g_sePlayer, 1, 0);
            int id             = *(signed char *) (self + 0x1c20);
            GameObject *member = GameState::GetInstance()->GetPartyMemberByIndex(id);
            if (member == 0) return;
            unsigned char *f = (unsigned char *) GetFieldAt0x150_02053c6c((unsigned char *) member);
            if (f[0x56a] != *(short *) (self + 0x1c06) && *(short *) (f + 0x488) < 0) {
                member->obj3D_.unknown_2_ = -1;
                func_ov017_0218f5a4(GetGameResources(), id, 0, 0, 0);
            }
            var16[0x56a] = *(short *) (arg0 + 0x1c06);
            func_ov002_02161a8c();
            func_020dc7e8(1, -1);
            func_020dc7e8(8, -1);
            func_020dc7e8(6, -1);
            func_020dc7e8(7, -1);
            int *var17 = func_0202ae18();
            if (var17 != 0 && func_0202b7d8(var17)) {
                func_ov017_021d0dbc();
            }
            func_ov002_02156e90(arg0);
            func_ov002_02156e90(arg0);
            func_0205deb4((Struct_0205d81c*)(arg0 + 0xec8), 0x18, 0);
            func_0205deb4((Struct_0205d81c*)(arg0 + 0xec8), 0x1a, 0);
            func_0205deb4((Struct_0205d81c*)(arg0 + 0xec8), 0x1b, 0);
        } else if (func_ov002_02161b48(arg0, 1)) {
            func_ov002_02156e90(arg0);
            func_ov002_02156e90(arg0);
            func_0205deb4((Struct_0205d81c*)(arg0 + 0xec8), 0x18, 0);
            func_0205deb4((Struct_0205d81c*)(arg0 + 0xec8), 0x1a, 0);
            func_0205deb4((Struct_0205d81c*)(arg0 + 0xec8), 0x1b, 0);
        }
    }
}
#endif
