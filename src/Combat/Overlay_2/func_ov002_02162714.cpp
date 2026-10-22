#include "GameState/GameState.h"
#include <globaldefs.h>
#include "Input/Input.h"

#if defined(jpn)
#define RG(u, j) (j)
#else
#define RG(u, j) (u)
#endif

struct Struct0205de24;
struct Struct_0205c570;
struct SePlayer;
struct Obj020d7aa0;

void FindAndLinkMatchingEntry0205de24(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
int GetActiveScaledSum0205d794(struct Struct_0205c570 *s);
int CheckFlagOrThreshold_02161b48(char *self, int flag);
struct Obj_0205da38;
int IsActiveElementFlag2Set0205da38(struct Obj_0205da38* obj, int key);
void *GetFieldAt0x150_02053c6c(unsigned char *p);
void SePlayer_Play(SePlayer *obj, int a, int b);
int GetCountByType02157108(void *self, int type);
Obj020d7aa0 *GetGlobalResetObj020d7a50();
void TeardownAndResetState020d7aa0(Obj020d7aa0 *obj);
extern "C" void func_020d7978(char *self);
extern "C" void func_ov002_02161cf0(char *self);
extern "C" void func_ov002_0215c474(char *self);
extern "C" void func_ov002_02156e90(char *self);

extern SePlayer g_sePlayer;

// USA: func_ov002_02162714
extern "C" ARM void func_ov002_02162714(char *self) {
    int phase = *(int *) (self + RG(0x1bc0, 0x1a88));
    if (phase == 0) {
        *(short *) (self + RG(0x1be4, 0x1aac)) = 0;
        FindAndLinkMatchingEntry0205de24((struct Struct0205de24 *) (self + RG(0xec8, 0xe20)), 0, 2);
        func_ov002_02161cf0(self);
        func_ov002_0215c474(self);
        (*(int *) (self + RG(0x1bc0, 0x1a88)))++;
    } else if (phase == 1) {
        *(int *) (self + RG(0x247c, 0x22ac)) |= 4;
        short old = *(short *) (self + RG(0x1be4, 0x1aac));
        *(short *) (self + RG(0x1be4, 0x1aac)) =
            GetActiveScaledSum0205d794((struct Struct_0205c570 *) (self + RG(0xec8, 0xe20)));
        if (old != *(short *) (self + RG(0x1be4, 0x1aac))) {
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
            switch (*(short *) (self + RG(0x1be4, 0x1aac))) {
                case 0:
                    SePlayer_Play(&g_sePlayer, 1, 0);
                    *(int *) (self + RG(0x1bb8, 0x1a80)) = 4;
                    *(int *) (self + RG(0x1bc0, 0x1a88)) = 0;
                    break;
                case 1:
                    *(unsigned char *) (self + RG(0xf80, 0xed8)) = *(int *) (self + RG(0x1bb8, 0x1a80));
                    *(int *) (self + RG(0x247c, 0x22ac)) &= ~4;
                    SePlayer_Play(&g_sePlayer, 1, 0);
                    *(signed char *) (self + RG(0x1c20, 0x1ae8)) = 5;
                    *(int *) (self + RG(0x1bb8, 0x1a80))         = RG(10, 0xb);
                    *(int *) (self + RG(0x1bc0, 0x1a88))         = 0;
                    if (GetCountByType02157108(self, *(signed char *) (self + RG(0x1c20, 0x1ae8))) != 0) {
                        return;
                    }
                    TeardownAndResetState020d7aa0(GetGlobalResetObj020d7a50());
                    *(short *) (self + RG(0x1c28, 0x1af0)) = 0x2395;
                    *(short *) (self + RG(0x1c2a, 0x1af2)) = -1;
                    *(int *) (self + RG(0x1bb8, 0x1a80))   = RG(0x26, 0x29);
                    *(int *) (self + RG(0x1bbc, 0x1a84))   = 3;
                    break;
                case 2:
                    func_020d7978(self);
                    *(int *) (self + RG(0x1bb8, 0x1a80)) = RG(0x2b, 0x2e);
                    *(int *) (self + RG(0x1bc0, 0x1a88)) = 0;
                    break;
            }
        } else if (CheckFlagOrThreshold_02161b48(self, 1)) {
            *(short *) (self + RG(0x1be4, 0x1aac)) = -1;
            func_ov002_02156e90(self);
        }
    }
}
