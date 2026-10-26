#include <globaldefs.h>
#include "NitroSDK/Graphics.h"
#include "GameState/GameState.h"

struct Struct0200fb08;
struct Vec3Target0203a46c;

struct GaugeSprite0218251c {
    unsigned char pad0[0x82];
    short alpha;
    unsigned char pad84[0x88 - 0x84];
};

struct Struct_ov000_0218251c_2 {
    GaugeSprite0218251c sprites[13];
    unsigned char level;
    unsigned char subLevel;
    short timer;
    short fade;
};

struct Struct_ov000_021836d0 {
    unsigned char order[5];
};

extern "C" int GameState_GetLanguage(Struct0200fb08* gs);
extern "C" void SprSprite_SetPosition(Vec3Target0203a46c* obj, int x, int y, int z);
extern "C" void SprSprite_DrawGroup(GaugeSprite0218251c* obj, int idx, int something);

extern const Struct_ov000_021836d0 data_ov000_021836d0;
extern const signed char data_ov000_021836d5[][2];
extern const signed char data_ov000_021836d6[][2];

static inline void inline_ov000_0218251c(GaugeSprite0218251c* sprite) {
    GXFIFO_MATRIX_PUSH = 0;
    SprSprite_DrawGroup(sprite, 0, 1);
    GXFIFO_MATRIX_POP = 1;
}

#if defined(jpn)
extern const int data_ov000_02184788[][2];
extern const int data_ov000_0218478c[][2];

// JPN: func_ov000_0218251c (no phase badge; the gauge letters are drawn in a loop)
extern "C" ARM void func_ov000_0218251c(Struct_ov000_0218251c_2* self) {
    int level = self->level;
    int subLevel = self->subLevel;
    if (level <= 0) {
        return;
    }
    int t = 30 - self->timer;

    if (level > 1 || t >= 0) {
        int x = 0;
        int z = 15;
        if (t < 6) {
            float f = (6 - t) / 6.0f;
            x = (int)(-64.0f * (f * f));
        }
        int x2 = x;
        if (level >= 2) {
            x = 0;
            x2 /= 4;
        }
        int fade = self->fade;
        if (fade > 0 && fade < 5) {
            float f = (5 - fade) / 5.0f;
            int d = (int)(64.0f * (f * f));
            x -= d;
            x2 -= d;
        }

        SprSprite_SetPosition((Vec3Target0203a46c*)&self->sprites[7], (x + 2) << 12, 0x1f000, z-- << 12);
        self->sprites[7].alpha = 0x1f;
        inline_ov000_0218251c(&self->sprites[7]);

        int l = level - 1;

        SprSprite_SetPosition((Vec3Target0203a46c*)&self->sprites[l], (x2 + 11) << 12, 0x8000, z-- << 12);
        self->sprites[l].alpha = 0x1f;
        inline_ov000_0218251c(&self->sprites[l]);

        if (level >= 2 && t < 6) {
            SprSprite_SetPosition((Vec3Target0203a46c*)&self->sprites[subLevel - 1], (x + 11) << 12, 0x8000, z-- << 12);
            self->sprites[subLevel - 1].alpha = (6 - t) * 31 / 6;
            if (self->sprites[subLevel - 1].alpha > 0x1f) {
                self->sprites[subLevel - 1].alpha = 0x1f;
            }
            inline_ov000_0218251c(&self->sprites[subLevel - 1]);
        }

        int count = 4;
        if ((level == 3 && t >= 6) || subLevel == 3) {
            count = 5;
        }
        int w = t - 2;
        for (int i = 0; i < count; w--, i++) {
            int idx = i + 3;
            if (i == 4) {
                if (w < 0 && subLevel < 3) {
                    break;
                }
                idx = 6;
            }
            int y = 0;
            if (w > 0 && w < 6) {
                if (w <= 3) {
                    y = -w;
                } else {
                    y = w - 6;
                }
            }
            SprSprite_SetPosition((Vec3Target0203a46c*)&self->sprites[idx], (x + data_ov000_02184788[i + 1][0]) << 12,
                          (y + data_ov000_0218478c[i + 1][0]) << 12, z-- << 12);
            self->sprites[idx].alpha = 0x1f;
            inline_ov000_0218251c(&self->sprites[idx]);
        }
    }

    int u = t - 5;
    if (level > 1 || u > 0) {
        int x = 0;
        if (u < 6) {
            float f = (6 - u) / 6.0f;
            x = (int)(-64.0f * (f * f));
        }
        int fade = self->fade;
        if (fade > 0 && fade < 5) {
            float f = (5 - fade) / 5.0f;
            x -= (int)(64.0f * (f * f));
        }

        SprSprite_SetPosition((Vec3Target0203a46c*)&self->sprites[8], (x + 3) << 12, 0x21000, 0x1000);
        self->sprites[8].alpha = 0x1f;
        inline_ov000_0218251c(&self->sprites[8]);

        SprSprite_SetPosition((Vec3Target0203a46c*)&self->sprites[9], (x + 36) << 12, 0x22000, 0);
        self->sprites[9].alpha = 0x1f;
        inline_ov000_0218251c(&self->sprites[9]);

        int slot = level + 9;
        int k = 9;
        if (level == 3) {
            k = 10;
        }
        SprSprite_SetPosition((Vec3Target0203a46c*)&self->sprites[slot], (x + data_ov000_02184788[k][0]) << 12,
                      data_ov000_0218478c[k][0] << 12, -0x1000);
        self->sprites[slot].alpha = 0x1f;
        inline_ov000_0218251c(&self->sprites[slot]);
    }
}
#else
// USA: func_ov000_0218251c
extern "C" ARM void func_ov000_0218251c(Struct_ov000_0218251c_2* self) {
    int level = self->level;
    int subLevel = self->subLevel;
    if (level <= 0) {
        return;
    }
    int phase = GameState_GetLanguage((Struct0200fb08*)GameState::GetInstance()) - 1;
    Struct_ov000_021836d0 order = data_ov000_021836d0;
    int t = 30 - self->timer;

    if (level > 1 || t >= 0) {
        int x = 0;
        int z = 15;
        if (t < 6) {
            float f = (6 - t) / 6.0f;
            x = (int)(-64.0f * (f * f));
        }
        int x2 = x;
        if (level >= 2) {
            x = 0;
            x2 /= 4;
        }
        int fade = self->fade;
        if (fade > 0 && fade < 5) {
            float f = (5 - fade) / 5.0f;
            int d = (int)(64.0f * (f * f));
            x -= d;
            x2 -= d;
        }

        SprSprite_SetPosition((Vec3Target0203a46c*)&self->sprites[3], (x + 2) << 12, 0x1f000, z-- << 12);
        self->sprites[3].alpha = 0x1f;
        inline_ov000_0218251c(&self->sprites[3]);

        int l = level - 1;

        SprSprite_SetPosition((Vec3Target0203a46c*)&self->sprites[l], (x2 + 11) << 12, 0x8000, z-- << 12);
        self->sprites[l].alpha = 0x1f;
        inline_ov000_0218251c(&self->sprites[l]);

        if (level >= 2 && t < 6) {
            SprSprite_SetPosition((Vec3Target0203a46c*)&self->sprites[subLevel - 1], (x + 11) << 12, 0x8000, z-- << 12);
            self->sprites[subLevel - 1].alpha = (6 - t) * 31 / 6;
            if (self->sprites[subLevel - 1].alpha > 0x1f) {
                self->sprites[subLevel - 1].alpha = 0x1f;
            }
            inline_ov000_0218251c(&self->sprites[subLevel - 1]);
        }

        int w = t - 2;
        int idx = 9;
        if ((level == 3 && t >= 6) || subLevel == 3) {
            idx = 10;
        }
        int y = 0;
        if (w > 0 && w < 6) {
            if (w <= 3) {
                y = -w;
            } else {
                y = w - 6;
            }
        }
        SprSprite_SetPosition((Vec3Target0203a46c*)&self->sprites[idx], (x + 28) << 12, (y + 20) << 12, z << 12);
        self->sprites[idx].alpha = 0x1f;
        inline_ov000_0218251c(&self->sprites[idx]);

        if (phase == 4) {
            int k = 0x1b;
            int j = 11;
            if (idx == 10) {
                k = 0x1c;
                j = 12;
            }
            SprSprite_SetPosition((Vec3Target0203a46c*)&self->sprites[j], (x + data_ov000_021836d5[k][0]) << 12,
                          (y + data_ov000_021836d6[k][0]) << 12, (z - 1) << 12);
            self->sprites[j].alpha = 0x1f;
            inline_ov000_0218251c(&self->sprites[j]);
        }
    }

    int u = t - 5;
    if (level > 1 || u > 0) {
        int x = 0;
        if (u < 6) {
            float f = (6 - u) / 6.0f;
            x = (int)(-64.0f * (f * f));
        }
        int fade = self->fade;
        if (fade > 0 && fade < 5) {
            float f = (5 - fade) / 5.0f;
            x -= (int)(64.0f * (f * f));
        }

        SprSprite_SetPosition((Vec3Target0203a46c*)&self->sprites[8], (x + 3) << 12, 0x21000, 0x1000);
        self->sprites[8].alpha = 0x1f;
        inline_ov000_0218251c(&self->sprites[8]);

        int c = order.order[phase];
        unsigned char k = c + 4;
        SprSprite_SetPosition((Vec3Target0203a46c*)&self->sprites[4], (x + data_ov000_021836d5[k][0]) << 12,
                      data_ov000_021836d6[k][0] << 12, 0);
        self->sprites[4].alpha = 0x1f;
        inline_ov000_0218251c(&self->sprites[4]);

        int slot = level + 4;
        int nextC = c + 5;
        if (level == 3) {
            nextC++;
        }
        SprSprite_SetPosition((Vec3Target0203a46c*)&self->sprites[slot], (x + data_ov000_021836d5[nextC][0]) << 12,
                      data_ov000_021836d6[nextC][0] << 12, -0x1000);
        self->sprites[slot].alpha = 0x1f;
        inline_ov000_0218251c(&self->sprites[slot]);
    }
}
#endif
