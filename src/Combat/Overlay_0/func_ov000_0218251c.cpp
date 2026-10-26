#include <globaldefs.h>
#include "NitroSDK/Graphics.h"
#include "GameState/GameState.h"

struct Struct_02000c9c_8;
struct Struct_0203a46c;

struct Struct_ov000_0218251c {
    unsigned char unknown_0_[0x82];
    short unknown_82_;
    unsigned char unknown_84_[0x88 - 0x84];
};

struct Struct_ov000_0218251c_2 {
    Struct_ov000_0218251c unknown_0_[13];
    unsigned char unknown_6e8_;
    unsigned char unknown_6e9_;
    short unknown_6ea_;
    short unknown_6ec_;
};

struct Struct_ov000_021836d0 {
    unsigned char unknown_0_[5];
};

int GameState_GetLanguage(Struct0200fb08* gs);
void SprSprite_SetPosition(Vec3Target0203a46c* obj, int x, int y, int z);
extern "C" void SprSprite_DrawGroup(GaugeSprite0218251c* obj, int idx, int something);

extern const Struct_ov000_021836d0 data_ov000_021836d0;
extern const signed char data_ov000_021836d5[][2];
extern const signed char data_ov000_021836d6[][2];

static inline void inline_ov000_0218251c(Struct_ov000_0218251c* arg0) {
    GXFIFO_MATRIX_PUSH = 0;
    SprSprite_DrawGroup(sprite, 0, 1);
    GXFIFO_MATRIX_POP = 1;
}

#if defined(jpn)
extern const int data_ov000_02184788[][2];
extern const int data_ov000_0218478c[][2];

// JPN: func_ov000_0218251c (no phase badge; the gauge letters are drawn in a loop)
extern "C" ARM void func_ov000_0218251c(Struct_ov000_0218251c_2* arg0) {
    int var0 = arg0->unknown_6e8_;
    int var1 = arg0->unknown_6e9_;
    if (var0 <= 0) {
        return;
    }
    int var2 = 30 - arg0->unknown_6ea_;

    if (var0 > 1 || var2 >= 0) {
        int var3 = 0;
        int var4 = 15;
        if (var2 < 6) {
            float var5 = (6 - var2) / 6.0f;
            var3 = (int)(-64.0f * (var5 * var5));
        }
        int var6 = var3;
        if (var0 >= 2) {
            var3 = 0;
            var6 /= 4;
        }
        int var7 = arg0->unknown_6ec_;
        if (var7 > 0 && var7 < 5) {
            float var8 = (5 - var7) / 5.0f;
            int var9 = (int)(64.0f * (var8 * var8));
            var3 -= var9;
            var6 -= var9;
        }

        SprSprite_SetPosition((Vec3Target0203a46c*)&self->sprites[7], (x + 2) << 12, 0x1f000, z-- << 12);
        self->sprites[7].alpha = 0x1f;
        DrawSprite(&self->sprites[7]);

        int var10 = var0 - 1;

        SprSprite_SetPosition((Vec3Target0203a46c*)&self->sprites[l], (x2 + 11) << 12, 0x8000, z-- << 12);
        self->sprites[l].alpha = 0x1f;
        DrawSprite(&self->sprites[l]);

        if (level >= 2 && t < 6) {
            SprSprite_SetPosition((Vec3Target0203a46c*)&self->sprites[subLevel - 1], (x + 11) << 12, 0x8000, z-- << 12);
            self->sprites[subLevel - 1].alpha = (6 - t) * 31 / 6;
            if (self->sprites[subLevel - 1].alpha > 0x1f) {
                self->sprites[subLevel - 1].alpha = 0x1f;
            }
            inline_ov000_0218251c(&arg0->unknown_0_[var1 - 1]);
        }

        int var11 = 4;
        if ((var0 == 3 && var2 >= 6) || var1 == 3) {
            var11 = 5;
        }
        int var12 = var2 - 2;
        for (int var13 = 0; var13 < var11; var12--, var13++) {
            int var14 = var13 + 3;
            if (var13 == 4) {
                if (var12 < 0 && var1 < 3) {
                    break;
                }
                var14 = 6;
            }
            int var15 = 0;
            if (var12 > 0 && var12 < 6) {
                if (var12 <= 3) {
                    var15 = -var12;
                } else {
                    var15 = var12 - 6;
                }
            }
            SprSprite_SetPosition((Vec3Target0203a46c*)&self->sprites[idx], (x + data_ov000_02184788[i + 1][0]) << 12,
                          (y + data_ov000_0218478c[i + 1][0]) << 12, z-- << 12);
            self->sprites[idx].alpha = 0x1f;
            DrawSprite(&self->sprites[idx]);
        }
    }

    int var16 = var2 - 5;
    if (var0 > 1 || var16 > 0) {
        int var17 = 0;
        if (var16 < 6) {
            float var18 = (6 - var16) / 6.0f;
            var17 = (int)(-64.0f * (var18 * var18));
        }
        int var19 = arg0->unknown_6ec_;
        if (var19 > 0 && var19 < 5) {
            float var20 = (5 - var19) / 5.0f;
            var17 -= (int)(64.0f * (var20 * var20));
        }

        SprSprite_SetPosition((Vec3Target0203a46c*)&self->sprites[8], (x + 3) << 12, 0x21000, 0x1000);
        self->sprites[8].alpha = 0x1f;
        DrawSprite(&self->sprites[8]);

        SprSprite_SetPosition((Vec3Target0203a46c*)&self->sprites[9], (x + 36) << 12, 0x22000, 0);
        self->sprites[9].alpha = 0x1f;
        DrawSprite(&self->sprites[9]);

        int var21 = var0 + 9;
        int var22 = 9;
        if (var0 == 3) {
            var22 = 10;
        }
        SprSprite_SetPosition((Vec3Target0203a46c*)&self->sprites[slot], (x + data_ov000_02184788[k][0]) << 12,
                      data_ov000_0218478c[k][0] << 12, -0x1000);
        self->sprites[slot].alpha = 0x1f;
        DrawSprite(&self->sprites[slot]);
    }
}
#else
// USA: func_ov000_0218251c
extern "C" ARM void func_ov000_0218251c(Struct_ov000_0218251c_2* arg0) {
    int var23 = arg0->unknown_6e8_;
    int var24 = arg0->unknown_6e9_;
    if (var23 <= 0) {
        return;
    }
    int phase = GameState_GetLanguage((Struct0200fb08*)GameState::GetInstance()) - 1;
    GaugeOrder0218251c order = data_ov000_021836d0;
    int t = 30 - self->timer;

    if (var23 > 1 || var27 >= 0) {
        int var28 = 0;
        int var29 = 15;
        if (var27 < 6) {
            float var30 = (6 - var27) / 6.0f;
            var28 = (int)(-64.0f * (var30 * var30));
        }
        int var31 = var28;
        if (var23 >= 2) {
            var28 = 0;
            var31 /= 4;
        }
        int var32 = arg0->unknown_6ec_;
        if (var32 > 0 && var32 < 5) {
            float var33 = (5 - var32) / 5.0f;
            int var34 = (int)(64.0f * (var33 * var33));
            var28 -= var34;
            var31 -= var34;
        }

        SprSprite_SetPosition((Vec3Target0203a46c*)&self->sprites[3], (x + 2) << 12, 0x1f000, z-- << 12);
        self->sprites[3].alpha = 0x1f;
        DrawSprite(&self->sprites[3]);

        int var35 = var23 - 1;

        SprSprite_SetPosition((Vec3Target0203a46c*)&self->sprites[l], (x2 + 11) << 12, 0x8000, z-- << 12);
        self->sprites[l].alpha = 0x1f;
        DrawSprite(&self->sprites[l]);

        if (level >= 2 && t < 6) {
            SprSprite_SetPosition((Vec3Target0203a46c*)&self->sprites[subLevel - 1], (x + 11) << 12, 0x8000, z-- << 12);
            self->sprites[subLevel - 1].alpha = (6 - t) * 31 / 6;
            if (self->sprites[subLevel - 1].alpha > 0x1f) {
                self->sprites[subLevel - 1].alpha = 0x1f;
            }
            inline_ov000_0218251c(&arg0->unknown_0_[var24 - 1]);
        }

        int var36 = var27 - 2;
        int var37 = 9;
        if ((var23 == 3 && var27 >= 6) || var24 == 3) {
            var37 = 10;
        }
        int var38 = 0;
        if (var36 > 0 && var36 < 6) {
            if (var36 <= 3) {
                var38 = -var36;
            } else {
                var38 = var36 - 6;
            }
        }
        SprSprite_SetPosition((Vec3Target0203a46c*)&self->sprites[idx], (x + 28) << 12, (y + 20) << 12, z << 12);
        self->sprites[idx].alpha = 0x1f;
        DrawSprite(&self->sprites[idx]);

        if (var25 == 4) {
            int var39 = 0x1b;
            int var40 = 11;
            if (var37 == 10) {
                var39 = 0x1c;
                var40 = 12;
            }
            SprSprite_SetPosition((Vec3Target0203a46c*)&self->sprites[j], (x + data_ov000_021836d5[k][0]) << 12,
                          (y + data_ov000_021836d6[k][0]) << 12, (z - 1) << 12);
            self->sprites[j].alpha = 0x1f;
            DrawSprite(&self->sprites[j]);
        }
    }

    int var41 = var27 - 5;
    if (var23 > 1 || var41 > 0) {
        int var42 = 0;
        if (var41 < 6) {
            float var43 = (6 - var41) / 6.0f;
            var42 = (int)(-64.0f * (var43 * var43));
        }
        int var44 = arg0->unknown_6ec_;
        if (var44 > 0 && var44 < 5) {
            float var45 = (5 - var44) / 5.0f;
            var42 -= (int)(64.0f * (var45 * var45));
        }

        SprSprite_SetPosition((Vec3Target0203a46c*)&self->sprites[8], (x + 3) << 12, 0x21000, 0x1000);
        self->sprites[8].alpha = 0x1f;
        DrawSprite(&self->sprites[8]);

        int c = order.order[phase];
        unsigned char k = c + 4;
        SprSprite_SetPosition((Vec3Target0203a46c*)&self->sprites[4], (x + data_ov000_021836d5[k][0]) << 12,
                      data_ov000_021836d6[k][0] << 12, 0);
        self->sprites[4].alpha = 0x1f;
        DrawSprite(&self->sprites[4]);

        int var48 = var23 + 4;
        int var49 = var46 + 5;
        if (var23 == 3) {
            var49++;
        }
        SprSprite_SetPosition((Vec3Target0203a46c*)&self->sprites[slot], (x + data_ov000_021836d5[nextC][0]) << 12,
                      data_ov000_021836d6[nextC][0] << 12, -0x1000);
        self->sprites[slot].alpha = 0x1f;
        DrawSprite(&self->sprites[slot]);
    }
}
#endif
