#include <globaldefs.h>
#include "GameState/GameState.h"

struct GameResources;
void SetBrightness(GameResources*, int, int);
void SetSubBrightness(GameResources*, int, int);
int IsBrightnessTransitionActive(GameResources*);
extern "C" int func_0209ca2c(void* arg0);
struct Struct_0205d6a0;
extern "C" void func_0205d6a0(Struct_0205d6a0*, int);

struct Struct_0209cae8;
extern "C" short func_0209cae8(struct Struct_0209cae8* arg0);

struct Struct_02109bf4_4;
extern "C" void func_0209c678(struct Struct_02109bf4_4* arg0, int arg1);

extern int data_02109bf4;

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
                if (GetShortAt0xb8((struct ShortField0xb8_0209cae8*)&data_02109bf4) != 0x29) {
                    DispatchContextByState0209c678((struct Actor0209c678*)&data_02109bf4, 15);
                }
            }
        } else {
            SetSubBrightness((GameResources*)var0, -16, 15);
        }
        arg0->unknown_b11_ = arg0->unknown_b11_ + 1;
        return;
    }
    if (var1 != 1) return;
    if (IsBrightnessTransitionActive((GameResources*)var0) != 0) return;
    if (func_0209ca2c(&data_02109bf4) != 0) return;
    func_0205d6a0((Struct_0205d6a0*)((char*)arg0 + 0x130), 1);
    arg0->unknown_b10_ = 0xe;
    arg0->unknown_b11_ = 0;
}
