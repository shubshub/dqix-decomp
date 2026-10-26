#include <globaldefs.h>
#include "GameState/GameState.h"

struct GameResources;
void SetBrightness(GameResources*, int, int);
void SetSubBrightness(GameResources*, int, int);
int IsBrightnessTransitionActive(GameResources*);
extern "C" int func_0209ca2c(void* obj);
struct Entry_0205d6a0;
extern "C" void Window_ClosePane(Entry_0205d6a0*, int);

struct ShortField0xb8_0209cae8;
extern "C" short func_0209cae8(struct ShortField0xb8_0209cae8* obj);

struct Actor0209c678;
extern "C" void BgmPlayer_FadeOut(struct Actor0209c678* actor, int arg);

extern int g_bgmPlayer;

struct Struct_ov008_021868a8 {
    char pad0[0xb10];
    unsigned char b10;
    unsigned char unknown_b11_;
    char pad1;
    unsigned char unknown_b13_;
    char pad2[0xb24 - 0xb14];
    int unknown_b24_;
};

// USA: func_ov008_021868a8
extern "C" ARM void func_ov008_021868a8(struct Struct_ov008_021868a8* obj) {
    int* word = (int*)GameState::GetInstance()->GetResources();
    unsigned char flag = obj->unknown_b11_;
    if (flag == 0) {
        if (obj->unknown_b24_ == 0) {
            SetBrightness((GameResources*)word, -16, 15);
            if (obj->unknown_b13_ == 0) {
                if (func_0209cae8((struct ShortField0xb8_0209cae8*)&g_bgmPlayer) != 0x29) {
                    BgmPlayer_FadeOut((struct Actor0209c678*)&g_bgmPlayer, 15);
                }
            }
        } else {
            SetSubBrightness((GameResources*)word, -16, 15);
        }
        obj->unknown_b11_ = obj->unknown_b11_ + 1;
        return;
    }
    if (flag != 1) return;
    if (IsBrightnessTransitionActive((GameResources*)word) != 0) return;
    if (func_0209ca2c(&g_bgmPlayer) != 0) return;
    Window_ClosePane((Entry_0205d6a0*)((char*)obj + 0x130), 1);
    obj->b10 = 0xe;
    obj->unknown_b11_ = 0;
}
