#include <globaldefs.h>
#include "GameState/GameState.h"

struct GameResources;
void SetBrightness(GameResources*, int, int);
void SetSubBrightness(GameResources*, int, int);
int IsBrightnessTransitionActive(GameResources*);
int IsAnimationActive0209ca2c(void* obj);
struct Entry_0205d6a0;
void Window_ClosePane(Entry_0205d6a0*, int);

struct Struct_0209cae8;
extern "C" short func_0209cae8(struct Struct_0209cae8* arg0);

struct Actor0209c678;
void BgmPlayer_FadeOut(struct Actor0209c678* actor, int arg);

extern int g_bgmPlayer;

struct Struct_ov008_021868a8 {
    char unknown_0_[0xb10];
    unsigned char unknown_b10_;
    unsigned char unknown_b11_;
    char unknown_b12_;
    unsigned char unknown_b13_;
    char unknown_b14_[0xb24 - 0xb14];
    int unknown_b24_;
};

// USA: func_ov008_021868a8
extern "C" ARM void func_ov008_021868a8(struct Obj021868a8* obj) {
    int* word = (int*)GameState::GetInstance()->GetResources();
    unsigned char flag = obj->b11;
    if (flag == 0) {
        if (obj->b24 == 0) {
            SetBrightness((GameResources*)word, -16, 15);
            if (obj->b13 == 0) {
                if (GetShortAt0xb8((struct ShortField0xb8_0209cae8*)&g_bgmPlayer) != 0x29) {
                    BgmPlayer_FadeOut((struct Actor0209c678*)&g_bgmPlayer, 15);
                }
            }
        } else {
            SetSubBrightness((GameResources*)var0, -16, 15);
        }
        arg0->unknown_b11_ = arg0->unknown_b11_ + 1;
        return;
    }
    if (flag != 1) return;
    if (IsBrightnessTransitionActive((GameResources*)word) != 0) return;
    if (IsAnimationActive0209ca2c(&g_bgmPlayer) != 0) return;
    Window_ClosePane((Entry_0205d6a0*)((char*)obj + 0x130), 1);
    obj->b10 = 0xe;
    obj->b11 = 0;
}
