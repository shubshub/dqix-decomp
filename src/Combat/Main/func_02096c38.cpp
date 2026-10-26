#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Graphics/Vector.h>
#include <NitroSDK/Graphics.h>


struct StructAt020473c8 { char data[0x88]; };
struct StructAt020472e4 { char data[0x88]; };
union Struct_02096c38 {
    StructAt020473c8 unknown_0_;
    StructAt020472e4 transformed;
};
struct Obj020968d0 {
    Struct_02096c38 entries[4];
    unsigned char startX, startY, endX, endY, flag;
};
struct Struct_02096c38_2 { char unknown_0_[0xae]; short angle; };
extern "C" int func_020968d0(Obj020968d0*, int*);
extern "C" void func_020473c8(StructAt020473c8*, int);
extern "C" void func_020472e4(StructAt020472e4*, int);
extern "C" void G3_MultMtx43(int);
extern "C" void __clear(void*, int);

// USA: func_02096c38
extern "C" ARM void func_02096c38(Obj020968d0* object, int startX, int startY, int endX, int endY) {
    float converted;
    int var1, var2, var3, var4;
    int var5 = startX << 12;
    if (startX > 0) converted = 0.5f + (float)var5;
    else converted = (float)var5 - 0.5f;
    var1 = (int)converted;
    var5 = startY << 12;
    if (startY > 0) converted = 0.5f + (float)var5;
    else converted = (float)var5 - 0.5f;
    var2 = (int)converted;
    var5 = endX << 12;
    if (endX > 0) converted = 0.5f + (float)var5;
    else converted = (float)var5 - 0.5f;
    var3 = (int)converted;
    var5 = endY << 12;
    if (endY > 0) converted = 0.5f + (float)var5;
    else converted = (float)var5 - 0.5f;
    var4 = (int)converted;
    Vector3fix start, end;
    Matrix4x3 rotation;
    Vector3fix direction;
    int distance;
    __clear(&start, 12);
    start.x = var1;
    start.y = var2;
    __clear(&end, 12);
    end.x = var3;
    end.y = var4;
    int var11 = 0;
    if (!func_020968d0(object, &distance)) {
        if (!object->flag) return;
        distance = 0x8000;
        var11 = 1;
    }
    if (var11) {
        GameState* game = GameState::GetInstance();
        if (game) {
            GameObject* protagonist = game->GetProtagonist();
            if (protagonist) {
                int angle = ((Struct_02096c38_2*)protagonist)->angle;
                int cosine = fix32cos(angle);
                direction.x = fix32sin(angle);
                direction.y = 0;
                direction.z = cosine;
                Vector3fix_Normalize(&direction, &direction);
            }
        }
    } else {
        Vector3fix_Subtract(&end, &start, &direction);
        Vector3fix_Normalize(&direction, &direction);
    }
    GXFIFO_MATRIX_PUSH = 0;
    GXFIFO_MATRIX_TRANSLATE = var1;
    GXFIFO_MATRIX_TRANSLATE = var2;
    GXFIFO_MATRIX_TRANSLATE = 0;
    GXFIFO_MATRIX_PUSH = 0;
    GXFIFO_MATRIX_TRANSLATE = -0x8000;
    GXFIFO_MATRIX_TRANSLATE = -0x8000;
    GXFIFO_MATRIX_TRANSLATE = 0;
    func_020473c8(&object->entries[0].unknown_0_, 1);
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
    int scale = fix32_Divide(distance - 0x5000, 0x8000);
    GXFIFO_MATRIX_SCALE = 0x800;
    GXFIFO_MATRIX_SCALE = scale;
    GXFIFO_MATRIX_SCALE = 0x1000;
    func_020472e4(&object->entries[1].transformed, 1);
    GXFIFO_MATRIX_POP = 1;
    GXFIFO_MATRIX_POP = 1;
    GXFIFO_MATRIX_PUSH = 0;
    int var18 = distance;
    int depth = 0x3000;
    GXFIFO_MATRIX_TRANSLATE = 0;
    GXFIFO_MATRIX_TRANSLATE = var18;
    GXFIFO_MATRIX_TRANSLATE = depth;
    GXFIFO_MATRIX_SCALE = 0xc00;
    GXFIFO_MATRIX_SCALE = -0xc00;
    GXFIFO_MATRIX_SCALE = 0x1000;
    func_020472e4(&object->entries[2].transformed, 1);
    GXFIFO_MATRIX_POP = 1;
    GXFIFO_MATRIX_POP = 1;
    GXFIFO_MATRIX_PUSH = 0;
    GXFIFO_MATRIX_TRANSLATE = -0x4000;
    GXFIFO_MATRIX_TRANSLATE = -0x4000;
    GXFIFO_MATRIX_TRANSLATE = 0x2000;
    func_020473c8(&object->entries[3].unknown_0_, 1);
    GXFIFO_MATRIX_POP = 1;
    GXFIFO_MATRIX_POP = 1;
}
