#include "GameState/GameState.h"
#include <globaldefs.h>
#include "Input/Input.h"

#if defined(jpn)
#define RG(u, j) (j)
#else
#define RG(u, j) (u)
#endif

struct Struct_0205de24_2;
struct Struct_0205c570;
struct Struct_02108760;
struct Struct_020d7aa0_2;

void FindAndLinkMatchingEntry0205de24(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
int GetActiveScaledSum0205d794(struct Struct_0205c570 *s);
int CheckFlagOrThreshold_02161b48(char *self, int flag);
struct Obj_0205da38;
int IsActiveElementFlag2Set0205da38(struct Obj_0205da38* obj, int key);
void *GetFieldAt0x150_02053c6c(unsigned char *p);
void DispatchWithShortB4_0205eaa0(Obj0205eaa0 *obj, int a, int b);
int GetCountByType02157108(void *self, int type);
Obj020d7aa0 *GetGlobalResetObj020d7a50();
void TeardownAndResetState020d7aa0(Obj020d7aa0 *obj);
extern "C" void func_020d7978(char *self);
extern "C" void func_ov002_02161cf0(char *self);
extern "C" void func_ov002_0215c474(char *self);
extern "C" void func_ov002_02156e90(char *self);

extern Struct_02108760 data_02108760;

// USA: func_ov002_02162714
extern "C" ARM void func_ov002_02162714(char *arg0) {
    int var0 = *(int *) (arg0 + RG(0x1bc0, 0x1a88));
    if (var0 == 0) {
        *(short *) (arg0 + RG(0x1be4, 0x1aac)) = 0;
        func_0205de24((struct Struct_0205de24_2 *) (arg0 + RG(0xec8, 0xe20)), 0, 2);
        func_ov002_02161cf0(arg0);
        func_ov002_0215c474(arg0);
        (*(int *) (arg0 + RG(0x1bc0, 0x1a88)))++;
    } else if (var0 == 1) {
        *(int *) (arg0 + RG(0x247c, 0x22ac)) |= 4;
        short var1 = *(short *) (arg0 + RG(0x1be4, 0x1aac));
        *(short *) (arg0 + RG(0x1be4, 0x1aac)) =
            func_0205d794((struct Struct_0205c570 *) (arg0 + RG(0xec8, 0xe20)));
        if (var1 != *(short *) (arg0 + RG(0x1be4, 0x1aac))) {
            return;
        }
        int a  = g_keyManager.TestKeysPressed(0x601);
        int b  = IsActiveElementFlag2Set0205da38((struct Obj_0205da38*)(self + RG(0xec8, 0xe20)), 0x14);
        int ok = (a | b) ? 1 : 0;
        if (ok) {
            int flags = *(int *) (self + RG(0x247c, 0x22ac));
            if (flags & 2) return;
            if (!(flags & 0x10)) return;
            GameState *gs = GameState::GetInstance();
            gs->GetResources();
            GameObject *prot = gs->GetProtagonist();
            if (prot != 0) {
                *(short *) ((char *) GetFieldAt0x150_02053c6c((unsigned char *) prot) + RG(0x95a, 0x8c2)) = *(short *) (self + RG(0x1be4, 0x1aac));
            }
            switch (*(short *) (arg0 + RG(0x1be4, 0x1aac))) {
                case 0:
                    func_0205eaa0(&data_02108760, 1, 0);
                    *(int *) (arg0 + RG(0x1bb8, 0x1a80)) = 4;
                    *(int *) (arg0 + RG(0x1bc0, 0x1a88)) = 0;
                    break;
                case 1:
                    *(unsigned char *) (arg0 + RG(0xf80, 0xed8)) = *(int *) (arg0 + RG(0x1bb8, 0x1a80));
                    *(int *) (arg0 + RG(0x247c, 0x22ac)) &= ~4;
                    func_0205eaa0(&data_02108760, 1, 0);
                    *(signed char *) (arg0 + RG(0x1c20, 0x1ae8)) = 5;
                    *(int *) (arg0 + RG(0x1bb8, 0x1a80))         = RG(10, 0xb);
                    *(int *) (arg0 + RG(0x1bc0, 0x1a88))         = 0;
                    if (func_ov002_02157108(arg0, *(signed char *) (arg0 + RG(0x1c20, 0x1ae8))) != 0) {
                        return;
                    }
                    func_020d7aa0(func_020d7a50());
                    *(short *) (arg0 + RG(0x1c28, 0x1af0)) = 0x2395;
                    *(short *) (arg0 + RG(0x1c2a, 0x1af2)) = -1;
                    *(int *) (arg0 + RG(0x1bb8, 0x1a80))   = RG(0x26, 0x29);
                    *(int *) (arg0 + RG(0x1bbc, 0x1a84))   = 3;
                    break;
                case 2:
                    func_020d7978(arg0);
                    *(int *) (arg0 + RG(0x1bb8, 0x1a80)) = RG(0x2b, 0x2e);
                    *(int *) (arg0 + RG(0x1bc0, 0x1a88)) = 0;
                    break;
            }
        } else if (func_ov002_02161b48(arg0, 1)) {
            *(short *) (arg0 + RG(0x1be4, 0x1aac)) = -1;
            func_ov002_02156e90(arg0);
        }
    }
}
