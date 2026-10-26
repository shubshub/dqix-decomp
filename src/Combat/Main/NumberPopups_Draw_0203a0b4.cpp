#include <globaldefs.h>
#include "GameState/GameState.h"
#include "NitroSDK/Graphics.h"
#include "World/ZoneLootableRecord.h"

struct Vec3copy0202ec84 { unsigned int v[3]; };

struct Vec3Target0203a46c {
    char unk[0x1c];
    int x;
    int y;
    int z;
};

extern "C" void Camera_WorldToScreen(void*, struct Vec3copy0202ec84*, int*, int*);
extern "C" void SprSprite_SetPosition(struct Vec3Target0203a46c*, int, int, int);
extern "C" void SprSprite_SetScale(unsigned int*, unsigned int, unsigned int, unsigned int);
extern "C" void SprSprite_DrawGroup(void* sprite, int frame, int flag);

// data_020e7830: how much a digit grows (0x800, 0x1000, 0x1000, 0x1000, 0x800) over the five frames after it appears.
extern const int data_020e7830[5];

// A Foo02048004 .spr sprite, with the fields drawn here: position (+0x1c, the end of base), alpha (+0x82).
struct PopupSprite {
    struct Vec3Target0203a46c base;
    char pad28[0x82 - 0x28];
    short alpha;
    char pad84[0x88 - 0x84];
};

// One number popup (see NumberPopups_Init).
struct NumberPopup {
    unsigned short value;
    short offsetY;
    signed char offsetX;
    signed char timer;
    unsigned char digitCount;
    unsigned char style;
    short frameVelocity;
    short frameScale;
    struct Vec3copy0202ec84 anchor;
};

// data_02104b6c, the battle's number popups: a number and a frame sprite per style, a ring of 16 from head to tail.
struct NumberPopups {
    struct PopupSprite numberSprites[5];
    struct PopupSprite frameSprites[5];
    struct NumberPopup popups[16];
    int head;
    int tail;
};

// Main, originally func_0203a0b4 (USA 0x0203a0b4, EUR 0x0203a0c4, JPN 0x02039b0c)
extern "C" ARM void NumberPopups_Draw(struct NumberPopups* numberPopups) {
    int digitX;
    int alpha;
    int i;
    struct NumberPopup* popup;
    int frameX;
    int layer;
    int digitsLeft;
    void* camera = (void*)GameState::GetInstance()->GetCamera();
    if (camera == 0) return;
    i = numberPopups->head;
    while (i != numberPopups->tail) {
        popup = &numberPopups->popups[i];
        alpha = popup->timer - 5;
        alpha = alpha <= 4 ? alpha * 7 : 31;
        if (popup->timer < 35 && alpha > 0) {
            int style = popup->style;
            int value = popup->value;
            layer = 1;
            int x, y;
            Camera_WorldToScreen(camera, &popup->anchor, &x, &y);
            x += popup->offsetX;
            y = y + popup->offsetY - 20;
            if (x < 16) x = 16;
            if (x > 240) x = 240;
            frameX = x;
            if (y < 16) y = 16;
            if (y > 176) y = 176;
            int frameY = y;
            digitX = frameX + (popup->digitCount * 8 / 2 - 8);
            x = digitX;
            digitsLeft = popup->digitCount - 1;
            while (value > 0) {
                bool visible = true;
                int dx = 0, dy = 0, dz = 0;
                int scale = 0x1000;
                int growFrame = 34 - popup->timer - digitsLeft * 3;
                if (growFrame < 0) {
                    growFrame = 0;
                    visible = false;
                } else if (growFrame < 5) {
                    int growth = data_020e7830[growFrame];
                    scale = growth + 0x1000;
                    dx = (int)(((long long)growth * -0x4000 + 0x800) >> 12);
                    dy = (int)(((long long)growth * -0x8000 + 0x800) >> 12);
                    dz = (int)(((long long)growth * 0x5000 + 0x800) >> 12);
                }
                if (visible) {
                    SprSprite_SetPosition(&numberPopups->numberSprites[style].base, dx + (digitX << 12), dy + ((y - 8) << 12), dz + (layer << 12));
                    numberPopups->numberSprites[style].alpha = alpha;
                    SprSprite_SetScale((unsigned int*)&numberPopups->numberSprites[style], scale, scale, 0x1000);
                    GXFIFO_MATRIX_PUSH = 0;
                    SprSprite_DrawGroup(&numberPopups->numberSprites[style], value % 10, 1);
                    GXFIFO_MATRIX_POP = 1;
                }
                value = value / 10;
                x -= 8;
                digitX = x;
                layer++;
                digitsLeft--;
            }
            if (alpha > 0) {
                float frameScale = (float)numberPopups->popups[i].frameScale / 4096.0f;
                frameX -= (int)(16.0f * frameScale);
                int frameTop = frameY - (int)(8.0f * frameScale) - 8;
                SprSprite_SetPosition(&numberPopups->frameSprites[style].base, frameX << 12, frameTop << 12, 0);
                SprSprite_SetScale((unsigned int*)&numberPopups->frameSprites[style], numberPopups->popups[i].frameScale, numberPopups->popups[i].frameScale, 0x1000);
                numberPopups->frameSprites[style].alpha = alpha;
                GXFIFO_MATRIX_PUSH = 0;
                SprSprite_DrawGroup(&numberPopups->frameSprites[style], 0, 1);
                GXFIFO_MATRIX_POP = 1;
            }
        }
        i++;
        if (i >= 16) i = 0;
    }
}
