#include <globaldefs.h>
#include "GameState/GameState.h"
#include "NitroSDK/Graphics.h"

struct Struct_02015ef4 { unsigned int unknown_0_[3]; };

struct Struct_0203a46c {
    char unknown_0_[0x1c];
    int unknown_1c_;
    int unknown_20_;
    int unknown_24_;
};

void Camera_WorldToScreen(void*, struct Vec3copy0202ec84*, int*, int*);
void SetVec3At0x1c(struct Vec3Target0203a46c*, int, int, int);
void StoreVec3At0x34_0203a47c(unsigned int*, unsigned int, unsigned int, unsigned int);
extern "C" void func_02047554(void* sprite, int digit, int flag);

extern const int data_020e7830[5];

struct Struct_0203a0b4_2 {
    struct Struct_0203a46c unknown_0_;
    char unknown_28_[0x82 - 0x28];
    short unknown_82_;
    char unknown_84_[0x88 - 0x84];
};

struct Struct_0203a0b4_3 {
    unsigned short unknown_0_;
    short unknown_2_;
    signed char unknown_4_;
    signed char unknown_5_;
    unsigned char unknown_6_;
    unsigned char unknown_7_;
    short unknown_8_;
    short unknown_a_;
    struct Struct_02015ef4 unknown_c_;
};

struct Struct_0203a0b4 {
    struct Struct_0203a0b4_2 unknown_0_[5];
    struct Struct_0203a0b4_2 unknown_2a8_[5];
    struct Struct_0203a0b4_3 unknown_550_[16];
    int unknown_6d0_;
    int unknown_6d4_;
};

// USA: func_0203a0b4
extern "C" ARM void func_0203a0b4(struct Obj0203a0b4* obj) {
    int px;
    int n;
    int i;
    struct Slot0203a0b4* slot;
    int baseX;
    int digit;
    int left;
    void* camera = (void*)GameState::GetInstance()->GetCamera();
    if (camera == 0) return;
    i = obj->cursor;
    while (i != obj->limit) {
        slot = &obj->slots[i];
        n = slot->timer - 5;
        n = n <= 4 ? n * 7 : 31;
        if (slot->timer < 35 && n > 0) {
            int spriteIndex = slot->spriteIndex;
            int value = slot->value;
            digit = 1;
            int x, y;
            Camera_WorldToScreen(camera, &slot->anchor, &x, &y);
            x += slot->offsetX;
            y = y + slot->offsetY - 20;
            if (x < 16) x = 16;
            if (x > 240) x = 240;
            baseX = x;
            if (y < 16) y = 16;
            if (y > 176) y = 176;
            int baseY = y;
            px = baseX + (slot->digits * 8 / 2 - 8);
            x = px;
            left = slot->digits - 1;
            while (value > 0) {
                bool show = true;
                int dx = 0, dy = 0, dz = 0;
                int scale = 0x1000;
                int k = 34 - slot->timer - left * 3;
                if (k < 0) {
                    k = 0;
                    show = false;
                } else if (k < 5) {
                    int t = data_020e7830[k];
                    scale = t + 0x1000;
                    dx = (int)(((long long)t * -0x4000 + 0x800) >> 12);
                    dy = (int)(((long long)t * -0x8000 + 0x800) >> 12);
                    dz = (int)(((long long)t * 0x5000 + 0x800) >> 12);
                }
                if (var13) {
                    func_0203a46c(&arg0->unknown_0_[var8].unknown_0_, var14 + (var0 << 12), var15 + ((var11 - 8) << 12), var16 + (var5 << 12));
                    arg0->unknown_0_[var8].unknown_82_ = var1;
                    func_0203a47c((unsigned int*)&arg0->unknown_0_[var8], var17, var17, 0x1000);
                    GXFIFO_MATRIX_PUSH = 0;
                    func_02047554(&arg0->unknown_0_[var8], var9 % 10, 1);
                    GXFIFO_MATRIX_POP = 1;
                }
                var9 = var9 / 10;
                var10 -= 8;
                var0 = var10;
                var5++;
                var6--;
            }
            if (var1 > 0) {
                float var20 = (float)arg0->unknown_550_[var2].unknown_a_ / 4096.0f;
                var4 -= (int)(16.0f * var20);
                int var21 = var12 - (int)(8.0f * var20) - 8;
                func_0203a46c(&arg0->unknown_2a8_[var8].unknown_0_, var4 << 12, var21 << 12, 0);
                func_0203a47c((unsigned int*)&arg0->unknown_2a8_[var8], arg0->unknown_550_[var2].unknown_a_, arg0->unknown_550_[var2].unknown_a_, 0x1000);
                arg0->unknown_2a8_[var8].unknown_82_ = var1;
                GXFIFO_MATRIX_PUSH = 0;
                func_02047554(&arg0->unknown_2a8_[var8], 0, 1);
                GXFIFO_MATRIX_POP = 1;
            }
        }
        var2++;
        if (var2 >= 16) var2 = 0;
    }
}
