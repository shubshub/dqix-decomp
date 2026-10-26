#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"
#include "std_library_functions.h"

extern "C" void* __clear(void*, int);
struct Vec3copy0202ec84 { unsigned int v[3]; };
int Camera_WorldToScreen(void*, Vec3copy0202ec84*, int*, int*);

// One number popup (see NumberPopups_Init).
struct NumberPopup {
    unsigned char value[2];
    short offsetY;
    signed char offsetX;
    signed char timer;
    unsigned char digitCount;
    unsigned char style;
    short frameVelocity;
    short frameScale;
    Vec3copy0202ec84 anchor;
};
// data_02104b6c, the battle's number popups: a ring of 16 after the sprites.
struct NumberPopups {
    unsigned char sprites[0x550];
    NumberPopup popups[16];
    int head;
    int tail;
};

enum { kNumberPopupStyle_Tension = 4 };     // tension_num.spr: tension popups may overlap each other

// Main, originally func_0203a5e8 (USA 0x0203a5e8, EUR 0x0203a5f8, JPN 0x0203a040)
extern "C" ARM void NumberPopups_AvoidOverlap(NumberPopups* numberPopups, int index) {
    NumberPopup* popup = &numberPopups->popups[index];
    NumberPopups* others = numberPopups;
    signed char shiftX = 0;
    int shiftY = 0;
    void* camera = GameState::GetInstance()->GetCamera();
    if (camera != NULL) {
        bool shiftedRight = false;
        int step = shiftedRight;
        int screenXs[16];
        int clampedYs[16];
        int screenYs[16];
        __clear(screenXs, sizeof(screenXs));
        __clear(clampedYs, sizeof(clampedYs));
        __clear(screenYs, sizeof(screenYs));
        for (int i = 0; i < 16; i++) {
            if (others->popups[i].timer > 0) {
                int x, y = 0;
                Camera_WorldToScreen(camera, &others->popups[i].anchor, &x, &y);
                x += others->popups[i].offsetX;
                y += others->popups[i].offsetY;
                screenYs[i] = y;
                if (y < 36) y = 36;
                else if (y > 196) y = 196;
                screenXs[i] = x;
                clampedYs[i] = y;
            }
        }
        for (int attempt = 0; attempt < 16; attempt++) {
            bool overlaps = false;
            int* ys = screenYs;
            int candidateY = shiftY + ys[index];
            if (candidateY < 36) candidateY = 36;
            else if (candidateY > 196) candidateY = 196;
            for (int j = 0; j < 16; j++) {
                if (j == index) continue;
                if (others->popups[j].timer <= 0 || others->popups[j].timer >= 35) continue;
                if (popup->style == kNumberPopupStyle_Tension && others->popups[j].style == kNumberPopupStyle_Tension) continue;
                if (abs(shiftX + screenXs[index] - screenXs[j]) < 8 && abs(candidateY - clampedYs[j]) < 14) {
                    overlaps = true;
                    break;
                }
            }
            if (!overlaps) break;
            if (!shiftedRight) {
                shiftY = 20 * step - 4;
                step = -step;
                shiftX = 24;
                shiftedRight = true;
            } else {
                shiftY = 20 * step;
                shiftX = 0;
                if (step <= 0) step--;
                shiftedRight = false;
            }
        }
    }
    if (popup->offsetX == -127) {
        popup->offsetX = 0;
        popup->offsetY = 0;
    }
    popup->offsetX += shiftX;
    popup->offsetY += shiftY;
}
