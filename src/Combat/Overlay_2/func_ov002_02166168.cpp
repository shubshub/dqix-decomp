#include "GameState/GameState.h"
#include <globaldefs.h>
#include "Input/Input.h"

struct Struct_0205de24_2;
struct Struct_0205c570;
struct Struct_0205d81c;
struct Struct_0205def8;
struct Struct_02108760;
struct Struct_020d7aa0_2;

extern "C" void func_02012fe4(void);
extern "C" void func_0205de24(struct Struct_0205de24_2 *arg0, unsigned char arg1,
                                                                        unsigned char arg2);
extern "C" void func_ov002_02161cf0(char *arg0);
extern "C" void func_ov002_0215f3a0(void *arg0);
extern "C" void func_0205def8(struct Struct_0205def8 *arg0, int arg1, int arg2);
extern "C" void func_0205deb4(struct Struct_0205d81c *arg0, int arg1, int arg2);
extern "C" int func_0205d794(struct Struct_0205c570 *arg0);
extern "C" char *func_0205d81c(struct Struct_0205d81c *arg0, int arg1);
extern "C" int func_ov002_0216197c(int arg0, struct Struct_0205d81c *arg1);
extern "C" void func_ov002_0215b9a4(void *arg0, int arg1, int arg2);
struct Struct_0205da38;
extern "C" int func_0205da38(struct Struct_0205da38* arg0, int arg1);
extern "C" Struct_020d7aa0_2 *func_020d7a50();
extern "C" void func_020d7aa0(Struct_020d7aa0_2 *arg0);
extern "C" void func_ov002_02156080(void *arg0, short *arg1, short *arg2);
extern "C" int func_ov002_02161920(void *arg0);
extern "C" void func_0205eaa0(struct Struct_02108760 *arg0, int arg1, int arg2);
extern "C" void func_ov017_021c1798(GameResources *arg0, unsigned char arg1);
extern "C" void func_ov002_0215a878(char *arg0);
extern "C" int func_020100a8(GameState *arg0);
extern "C" void func_ov017_021bff8c(int arg0, int arg1);
extern "C" int func_ov002_02161b48(char *arg0, int arg1);
extern "C" void func_ov002_02156e90(void *arg0);

extern "C" char data_02108760;

#define OBJ (arg0 + 0x2c8 + 0xc00)

// USA: func_ov002_02166168
#if defined(jpn)
#undef OBJ
#define OBJ (self + 0xe20)
extern "C" ARM void func_ov002_02166168(char *self) {
    GameState *gs      = GameState::GetInstance();
    GameResources *res = gs->GetResources();
    func_02012fe4();
    int var2 = *(int *) (arg0 + 0x1a88);
    if (var2 == 0) {
        *(short *) (arg0 + 0x1ac6) = 0;
        func_0205de24((struct Struct_0205de24_2 *) OBJ, 0, 2);
        func_ov002_02161cf0(arg0);
        func_ov002_0215f3a0(arg0);
        *(int *) (arg0 + 0x1a88) += 1;
    } else if (var2 == 1) {
        *(unsigned int *) (arg0 + 0x22ac) |= 4;
        func_0205def8((struct Struct_0205def8 *) OBJ, 1, 0x2c);
        func_0205deb4((struct Struct_0205d81c *) OBJ, 0x16, 0);
        short var3                  = *(short *) (arg0 + 0x1ac6);
        *(short *) (arg0 + 0x1ac6) = func_0205d794((struct Struct_0205c570 *) OBJ);
        char *var4                    = func_0205d81c((struct Struct_0205d81c *) OBJ, 0x17);
        if (var4 != 0) {
            *(short *) (var4 + 0xc2) = 0;
        }
        func_ov002_0215b9a4(arg0, *(int *) (arg0 + 0x1a80) & 0xff, 0);
        if (var3 != *(short *) (arg0 + 0x1ac6)) {
            func_ov002_0215b9a4(arg0, 0x17, 0);
        }
        int var5  = g_keyManager.TestKeysPressed(0x601);
        int var6  = func_0205da38((struct Struct_0205da38*)OBJ, 0x14);
        int var7 = (var5 | var6) ? 1 : 0;
        if (var7) {
            unsigned int var8 = *(unsigned int *) (arg0 + 0x22ac);
            if (var8 & 2) {
                return;
            }
            func_020d7aa0(func_020d7a50());
            short var9 = 0;
            short var10[9];
            func_ov002_02156080(arg0, var10, &var9);
            func_ov002_02161920(arg0);
            switch (var10[*(short *) (arg0 + 0x1ac6)]) {
                case 0:
                    func_0205eaa0((struct Struct_02108760 *) &data_02108760, 1, 0);
                    *(unsigned char *) (arg0 + 0xed8) = *(int *) (arg0 + 0x1a80);
                    *(unsigned int *) (arg0 + 0x22ac) &= ~4;
                    *(int *) (arg0 + 0x1a80) = 0x18;
                    *(int *) (arg0 + 0x1a88) = 0;
                    break;
                case 1:
                    func_0205eaa0((struct Struct_02108760 *) &data_02108760, 1, 0);
                    *(int *) (arg0 + 0x1a80) = 0x19;
                    *(int *) (arg0 + 0x1a88) = 0;
                    break;
                case 2:
                    func_0205eaa0((struct Struct_02108760 *) &data_02108760, 1, 0);
                    *(unsigned char *) (arg0 + 0xed8) = *(int *) (arg0 + 0x1a80);
                    *(unsigned int *) (arg0 + 0x22ac) &= ~4;
                    *(int *) (arg0 + 0x1a80) = 0x20;
                    *(int *) (arg0 + 0x1a88) = 0;
                    break;
                case 3:
                    func_0205eaa0((struct Struct_02108760 *) &data_02108760, 1, 0);
                    *(int *) (arg0 + 0x1a80) = 0x24;
                    *(int *) (arg0 + 0x1a88) = 0;
                    break;
                case 4:
                    func_0205eaa0((struct Struct_02108760 *) &data_02108760, 1, 0);
                    func_ov017_021c1798(var1, 1);
                    func_ov002_0215a878(arg0);
                    *(int *) (arg0 + 0x1a80) = 0x2e;
                    *(int *) (arg0 + 0x1a88) = 0;
                    break;
                case 5:
                    func_0205eaa0((struct Struct_02108760 *) &data_02108760, 1, 0);
                    *(int *) (arg0 + 0x1a80) = 0x26;
                    *(int *) (arg0 + 0x1a88) = 0;
                    break;
                case 7:
                    func_0205eaa0((struct Struct_02108760 *) &data_02108760, 1, 0);
                    *(int *) (arg0 + 0x1a80) = 0x27;
                    *(int *) (arg0 + 0x1a88) = 0;
                    break;
                case 8: {
                    func_0205eaa0((struct Struct_02108760 *) &data_02108760, 1, 0);
                    int var11 = (signed char) func_020100a8(var0);
                    for (int var12 = 0; var12 < *(int *) (arg0 + 0x1b14); var12++) {
                        char *var13 = (char *) func_0200ff1c(var0, *(int *) (arg0 + var12 * 4 + 0x1b18));
                        if (var13 != 0 && !(**(int **) (var13 + 0x130) & 1)) {
                            var11 = (signed char) ((int *) (arg0 + 0x1b18))[var12];
                            break;
                        }
                    }
                    func_ov017_021bff8c((int) var1, var11);
                    *(int *) (arg0 + 0x1a80) = 0x2e;
                    *(int *) (arg0 + 0x1a88) = 0;
                    break;
                }
            }
        } else if (func_ov002_02161b48(arg0, 1)) {
            *(short *) (arg0 + 0x1ac6) = -1;
            func_ov002_02156e90(arg0);
        }
    }
}
#else
extern "C" ARM void func_ov002_02166168(char *self) {
    GameState *gs      = GameState::GetInstance();
    GameResources *res = gs->GetResources();
    func_02012fe4();
    int var16 = *(int *) (arg0 + 0x1bc0);
    if (var16 == 0) {
        *(short *) (arg0 + 0x1bfe) = 0;
        func_0205de24((struct Struct_0205de24_2 *) OBJ, 0, 2);
        func_ov002_02161cf0(arg0);
        func_ov002_0215f3a0(arg0);
        *(int *) (arg0 + 0x1bc0) += 1;
    } else if (var16 == 1) {
        *(unsigned int *) (arg0 + 0x247c) |= 4;
        func_0205def8((struct Struct_0205def8 *) OBJ, 1, 0x29);
        func_0205def8((struct Struct_0205def8 *) OBJ, 1, 1);
        func_0205deb4((struct Struct_0205d81c *) OBJ, 0x15, 0);
        short var17                  = *(short *) (arg0 + 0x1bfe);
        *(short *) (arg0 + 0x1bfe) = func_0205d794((struct Struct_0205c570 *) OBJ);
        char *var18                    = func_0205d81c((struct Struct_0205d81c *) OBJ, 0x16);
        if (var18 != 0) {
            *(short *) (var18 + 0xc2) = 0;
        }
        if (func_ov002_0216197c(*(int *) (arg0 + 0x1bb8) & 0xff,
                                                                  (struct Struct_0205d81c *) OBJ))
        {
            func_ov002_0215b9a4(arg0, *(int *) (arg0 + 0x1bb8) & 0xff, 0);
        }
        if (var17 != *(short *) (arg0 + 0x1bfe)) {
            func_ov002_0215b9a4(arg0, 0x16, 0);
        }
        int var19  = g_keyManager.TestKeysPressed(0x601);
        int var20  = func_0205da38((struct Struct_0205da38*)OBJ, 0x14);
        int var21 = (var19 | var20) ? 1 : 0;
        if (var21) {
            unsigned int var22 = *(unsigned int *) (arg0 + 0x247c);
            if (var22 & 2) {
                return;
            }
            if (!(var22 & 0x20)) {
                return;
            }
            func_020d7aa0(func_020d7a50());
            short var23 = 0;
            short var24[9];
            func_ov002_02156080(arg0, var24, &var23);
            func_ov002_02161920(arg0);
            switch (var24[*(short *) (arg0 + 0x1bfe)]) {
                case 0:
                    func_0205eaa0((struct Struct_02108760 *) &data_02108760, 1, 0);
                    *(unsigned char *) (arg0 + 0xf80) = *(int *) (arg0 + 0x1bb8);
                    *(unsigned int *) (arg0 + 0x247c) &= ~4;
                    *(int *) (arg0 + 0x1bb8) = 0x17;
                    *(int *) (arg0 + 0x1bc0) = 0;
                    break;
                case 1:
                    func_0205eaa0((struct Struct_02108760 *) &data_02108760, 1, 0);
                    *(int *) (arg0 + 0x1bb8) = 0x18;
                    *(int *) (arg0 + 0x1bc0) = 0;
                    break;
                case 2:
                    func_0205eaa0((struct Struct_02108760 *) &data_02108760, 1, 0);
                    *(unsigned char *) (arg0 + 0xf80) = *(int *) (arg0 + 0x1bb8);
                    *(unsigned int *) (arg0 + 0x247c) &= ~4;
                    *(int *) (arg0 + 0x1bb8) = 0x1f;
                    *(int *) (arg0 + 0x1bc0) = 0;
                    break;
                case 3:
                    func_0205eaa0((struct Struct_02108760 *) &data_02108760, 1, 0);
                    *(int *) (arg0 + 0x1bb8) = 0x21;
                    *(int *) (arg0 + 0x1bc0) = 0;
                    break;
                case 4:
                    func_0205eaa0((struct Struct_02108760 *) &data_02108760, 1, 0);
                    func_ov017_021c1798(var15, 1);
                    func_ov002_0215a878(arg0);
                    *(int *) (arg0 + 0x1bb8) = 0x2b;
                    *(int *) (arg0 + 0x1bc0) = 0;
                    break;
                case 5:
                    func_0205eaa0((struct Struct_02108760 *) &data_02108760, 1, 0);
                    *(int *) (arg0 + 0x1bb8) = 0x23;
                    *(int *) (arg0 + 0x1bc0) = 0;
                    break;
                case 7:
                    func_0205eaa0((struct Struct_02108760 *) &data_02108760, 1, 0);
                    *(int *) (arg0 + 0x1bb8) = 0x24;
                    *(int *) (arg0 + 0x1bc0) = 0;
                    break;
                case 8: {
                    func_0205eaa0((struct Struct_02108760 *) &data_02108760, 1, 0);
                    int var25 = (signed char) func_020100a8(var14);
                    for (int var26 = 0; var26 < *(int *) (arg0 + 0x1c50); var26++) {
                        char *var27 = (char *) func_0200ff1c(var14, *(int *) (arg0 + var26 * 4 + 0x1c54));
                        if (var27 != 0 && !(**(int **) (var27 + 0x130) & 1)) {
                            var25 = (signed char) ((int *) (arg0 + 0x1c54))[var26];
                            break;
                        }
                    }
                    func_ov017_021bff8c((int) var15, var25);
                    *(int *) (arg0 + 0x1bb8) = 0x2b;
                    *(int *) (arg0 + 0x1bc0) = 0;
                    break;
                }
            }
        } else if (func_ov002_02161b48(arg0, 1)) {
            *(short *) (arg0 + 0x1bfe) = -1;
            func_ov002_02156e90(arg0);
        }
    }
}
#endif
