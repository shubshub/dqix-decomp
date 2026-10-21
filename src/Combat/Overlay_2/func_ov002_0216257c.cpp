#include "GameState/GameState.h"
#include <globaldefs.h>
#include <Resource/ResourceNodeInsertion.h>
#include "Input/Input.h"

#if defined(jpn)
#define RG(u, j) (j)
#else
#define RG(u, j) (u)
#endif

struct Struct0205de24;
struct Struct_0205c570;
struct Obj_0205da38;
struct Obj0205eaa0;
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
int GetActiveScaledSum0205d794(struct Struct_0205c570 *s);
int IsActiveElementFlag2Set0205da38(struct Obj_0205da38* obj, int key);
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0 *o, int a, int b);
int CheckFlagOrThreshold_02161b48(char *base, int a);
extern "C" void func_ov002_02161cf0(void *base);
extern "C" void func_ov002_0215c2c8(void *base);
extern "C" void func_ov002_02156e90(void *base);
extern "C" void func_02012fe4(void);
extern "C" void func_02017c58(void);
extern "C" char data_02108760[];

static inline int GetSlot0216257c(char *b, int i) {
    return *(int *) (b + i * 4 + 0x1000 + RG(0xc54, 0xb18));
}
static inline int InRange0216257c(int v) {
    return (v >= 0 && v <= 3) ? 1 : 0;
}

// USA: func_ov002_0216257c
extern "C" ARM void func_ov002_0216257c(char *base) {
    int state = *(int *) (base + 0x1000 + RG(0xbc0, 0xa88));
    if (state == 0) {
        *(short *) (base + RG(0x1b00, 0x1a00) + RG(0xe2, 0xaa))        = 0;
        *(signed char *) (base + 0x1000 + RG(0xc20, 0xae8)) = GetSlot0216257c(base, *(short *) (base + RG(0x1b00, 0x1a00) + RG(0xe2, 0xaa)));
        FindAndLinkMatchingEntry0205de24((struct Struct0205de24 *) (base + RG(0x2c8, 0) + RG(0xc00, 0xe20)), 0, 2);
        func_ov002_02161cf0(base);
        func_ov002_0215c2c8(base);
        *(int *) (base + 0x1000 + RG(0xbc0, 0xa88)) += 1;
    } else if (state == 1) {
        *(unsigned int *) (base + 0x2000 + RG(0x47c, 0x2ac)) |= 4;
        *(short *) (base + RG(0x1b00, 0x1a00) + RG(0xe2, 0xaa)) =
            GetActiveScaledSum0205d794((struct Struct_0205c570 *) (base + RG(0x2c8, 0) + RG(0xc00, 0xe20)));
        int a = g_keyManager.TestKeysPressed(0x601);
        int b = IsActiveElementFlag2Set0205da38((struct Obj_0205da38*)(base + RG(0x2c8, 0) + RG(0xc00, 0xe20)), 0x14);
        if ((a | b) ? 1 : 0) {
            *(signed char *) (base + 0x1000 + RG(0xc20, 0xae8)) =
                *(signed char *) (base + *(short *) (base + RG(0x1b00, 0x1a00) + RG(0xe2, 0xaa)) + RG(0x1c00, 0x1b00) + RG(0x6e, 0x32));
            int v = *(signed char *) (base + RG(0x1c00, 0x1a00) + RG(0x20, 0xe8));
            if (!InRange0216257c(v)) return;
            *(unsigned int *) (base + 0x2000 + RG(0x47c, 0x2ac)) &= ~4;
            DispatchWithShortB4_0205eaa0((struct Obj0205eaa0 *) data_02108760, 1, 0);
            SetNodeFieldsAndInsert_021a120c(GameState::GetInstance()->GetResources(), 3, v);
            *(int *) (base + 0x1000 + RG(0xbb8, 0xa80)) = RG(0x2b, 0x2e);
            *(int *) (base + 0x1000 + RG(0xbc0, 0xa88)) = 0;
            func_02012fe4();
            func_02017c58();
        } else if (CheckFlagOrThreshold_02161b48(base, 1)) {
            *(short *) (base + RG(0x1b00, 0x1a00) + RG(0xe2, 0xaa)) = -1;
            func_ov002_02156e90(base);
        }
    }
}
