#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"
#include "std_library_functions.h"

extern "C" void* __clear(void*, int);
struct Vec3copy0202ec84 { unsigned int v[3]; };
int Camera_WorldToScreen(void*, Vec3copy0202ec84*, int*, int*);

struct Struct_02039fec {
    unsigned char unknown_0_[5];
    signed char unknown_5_;
    unsigned char unknown_6_[2];
    short unknown_8_;
    short unknown_a_;
    unsigned char unknown_c_[0xc];
};
struct Struct_02039fec_2 {
    unsigned char unknown_0_[0x550];
    struct Struct_02039fec unknown_550_[16];
    int unknown_6d0_;
    int unknown_6d4_;
};
struct Struct_0203a5e8 {
    unsigned char unknown_0_[2];
    short unknown_2_;
    signed char unknown_4_;
    signed char unknown_5_;
    unsigned char unknown_6_;
    unsigned char unknown_7_;
    short unknown_8_;
    short unknown_a_;
    Struct_02015ef4 unknown_c_;
};
struct Struct_0203a5e8_2 {
    unsigned char unknown_0_[0x550];
    Struct_0203a5e8 unknown_550_[16];
    int unknown_6d0_;
    int unknown_6d4_;
};

// USA: func_0203a5e8
extern "C" ARM void func_0203a5e8(Obj02039fec* obj, int index) {
    SlotProjection0203a5e8* current = (SlotProjection0203a5e8*)&obj->slots[index];
    ObjProjection0203a5e8* projection = (ObjProjection0203a5e8*)obj;
    signed char horizontal = 0;
    int vertical = 0;
    void* camera = GameState::GetInstance()->GetCamera();
    if (camera != NULL) {
        bool alternate = false;
        int step = alternate;
        int xs[16];
        int clampedYs[16];
        int ys[16];
        __clear(xs, sizeof(xs));
        __clear(clampedYs, sizeof(clampedYs));
        __clear(ys, sizeof(ys));
        for (int i = 0; i < 16; i++) {
            if (projection->slots[i].timer > 0) {
                int x, y = 0;
                Camera_WorldToScreen(camera, &projection->slots[i].vector, &x, &y);
                x += projection->slots[i].horizontalOffset;
                y += projection->slots[i].verticalOffset;
                ys[i] = y;
                if (y < 36) y = 36;
                else if (y > 196) y = 196;
                xs[i] = x;
                clampedYs[i] = y;
            }
        }
        for (int var13 = 0; var13 < 16; var13++) {
            bool var14 = false;
            int* var15 = var9;
            int var16 = var3 + var15[arg1];
            if (var16 < 36) var16 = 36;
            else if (var16 > 196) var16 = 196;
            for (int var17 = 0; var17 < 16; var17++) {
                if (var17 == arg1) continue;
                if (var1->unknown_550_[var17].unknown_5_ <= 0 || var1->unknown_550_[var17].unknown_5_ >= 35) continue;
                if (var0->unknown_7_ == 4 && var1->unknown_550_[var17].unknown_7_ == 4) continue;
                if (abs(var2 + var7[arg1] - var7[var17]) < 8 && abs(var16 - var8[var17]) < 14) {
                    var14 = true;
                    break;
                }
            }
            if (!var14) break;
            if (!var5) {
                var3 = 20 * var6 - 4;
                var6 = -var6;
                var2 = 24;
                var5 = true;
            } else {
                var3 = 20 * var6;
                var2 = 0;
                if (var6 <= 0) var6--;
                var5 = false;
            }
        }
    }
    if (var0->unknown_4_ == -127) {
        var0->unknown_4_ = 0;
        var0->unknown_2_ = 0;
    }
    var0->unknown_4_ += var2;
    var0->unknown_2_ += var3;
}
