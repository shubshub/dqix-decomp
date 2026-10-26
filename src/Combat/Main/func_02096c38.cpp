#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Graphics/Vector.h>
#include <NitroSDK/Graphics.h>


struct Struct_02015ef4_2 { char unknown_0_[0x88]; };
struct Struct_0201730c_2 { char unknown_0_[0x88]; };
union Struct_02096c38 {
    Struct_02015ef4_2 unknown_0_;
    Struct_0201730c_2 unknown1_0_;
};
struct Struct_020968d0 {
    Struct_02096c38 unknown_0_[4];
    unsigned char unknown_220_, unknown_221_, unknown_222_, unknown_223_, unknown_224_;
};
struct Facing02096c38 { char pad_0[0xae]; short angle; };
int CheckAndComputeDistance020968d0(Obj020968d0*, int*);
void RenderFlaggedIndexedEntry(StructAt020473c8*, int);
void RenderTransformedFlaggedIndexedEntry(StructAt020472e4*, int);
extern "C" void G3_MultMtx43(int);
extern "C" void __clear(void*, int);

// USA: func_02096c38
extern "C" ARM void func_02096c38(Struct_020968d0* arg0, int arg1, int arg2, int arg3, int arg4) {
    float var0;
    int var1, var2, var3, var4;
    int var5 = arg1 << 12;
    if (arg1 > 0) var0 = 0.5f + (float)var5;
    else var0 = (float)var5 - 0.5f;
    var1 = (int)var0;
    var5 = arg2 << 12;
    if (arg2 > 0) var0 = 0.5f + (float)var5;
    else var0 = (float)var5 - 0.5f;
    var2 = (int)var0;
    var5 = arg3 << 12;
    if (arg3 > 0) var0 = 0.5f + (float)var5;
    else var0 = (float)var5 - 0.5f;
    var3 = (int)var0;
    var5 = arg4 << 12;
    if (arg4 > 0) var0 = 0.5f + (float)var5;
    else var0 = (float)var5 - 0.5f;
    var4 = (int)var0;
    Vector3fix var6, var7;
    Matrix4x3 var8;
    Vector3fix var9;
    int var10;
    __clear(&var6, 12);
    var6.x = var1;
    var6.y = var2;
    __clear(&var7, 12);
    var7.x = var3;
    var7.y = var4;
    int var11 = 0;
    if (!func_020968d0(arg0, &var10)) {
        if (!arg0->unknown_224_) return;
        var10 = 0x8000;
        var11 = 1;
    }
    if (var11) {
        GameState* var12 = GameState::GetInstance();
        if (var12) {
            GameObject* var13 = var12->GetProtagonist();
            if (var13) {
                int var14 = ((Struct_02096c38_2*)var13)->unknown_ae_;
                int var15 = fix32cos(var14);
                var9.x = fix32sin(var14);
                var9.y = 0;
                var9.z = var15;
                Vector3fix_Normalize(&var9, &var9);
            }
        }
    } else {
        Vector3fix_Subtract(&var7, &var6, &var9);
        Vector3fix_Normalize(&var9, &var9);
    }
    GXFIFO_MATRIX_PUSH = 0;
    GXFIFO_MATRIX_TRANSLATE = var1;
    GXFIFO_MATRIX_TRANSLATE = var2;
    GXFIFO_MATRIX_TRANSLATE = 0;
    GXFIFO_MATRIX_PUSH = 0;
    GXFIFO_MATRIX_TRANSLATE = -0x8000;
    GXFIFO_MATRIX_TRANSLATE = -0x8000;
    GXFIFO_MATRIX_TRANSLATE = 0;
    func_020473c8(&arg0->unknown_0_[0].unknown_0_, 1);
    GXFIFO_MATRIX_POP = 1;
    GXFIFO_MATRIX_PUSH = 0;
    short angle = fix32ReduceAngle0To2Pi(-fix32_Atan2(direction.x, direction.y));
    rotation = RotationMatrixZ(angle);
    G3_MultMtx43((int)&rotation);
    GXFIFO_MATRIX_PUSH = 0;
    GXFIFO_MATRIX_TRANSLATE = 0;
    GXFIFO_MATRIX_TRANSLATE = 0;
    GXFIFO_MATRIX_TRANSLATE = 0x1000;
    GXFIFO_MATRIX_PUSH = 0;
    int var17 = fix32_Divide(var10 - 0x5000, 0x8000);
    GXFIFO_MATRIX_SCALE = 0x800;
    GXFIFO_MATRIX_SCALE = var17;
    GXFIFO_MATRIX_SCALE = 0x1000;
    func_020472e4(&arg0->unknown_0_[1].unknown1_0_, 1);
    GXFIFO_MATRIX_POP = 1;
    GXFIFO_MATRIX_POP = 1;
    GXFIFO_MATRIX_PUSH = 0;
    int var18 = var10;
    int var19 = 0x3000;
    GXFIFO_MATRIX_TRANSLATE = 0;
    GXFIFO_MATRIX_TRANSLATE = var18;
    GXFIFO_MATRIX_TRANSLATE = var19;
    GXFIFO_MATRIX_SCALE = 0xc00;
    GXFIFO_MATRIX_SCALE = -0xc00;
    GXFIFO_MATRIX_SCALE = 0x1000;
    func_020472e4(&arg0->unknown_0_[2].unknown1_0_, 1);
    GXFIFO_MATRIX_POP = 1;
    GXFIFO_MATRIX_POP = 1;
    GXFIFO_MATRIX_PUSH = 0;
    GXFIFO_MATRIX_TRANSLATE = -0x4000;
    GXFIFO_MATRIX_TRANSLATE = -0x4000;
    GXFIFO_MATRIX_TRANSLATE = 0x2000;
    func_020473c8(&arg0->unknown_0_[3].unknown_0_, 1);
    GXFIFO_MATRIX_POP = 1;
    GXFIFO_MATRIX_POP = 1;
}
