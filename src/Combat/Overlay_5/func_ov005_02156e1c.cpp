#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov005_02156e1c_15600 = 0x3c68 };
#else
enum { Enum_ov005_02156e1c_15600 = 0x3cf0 };
#endif

#include <NitroSDK/Matrix.h>
#include <std_library_functions.h>

struct Struct_0203a46c;

struct Struct_ov005_02155d6c_2 {
    char unknown_0_[0x1c];
    Vector3fix unknown_1c_;
    char unknown_28_[0x88 - 0x28];
};

struct Struct_ov005_02153954 {
    char unknown_0_[Enum_ov005_02156e1c_15600];
    Struct_ov005_02155d6c_2 unknown_3cf0_;
    short unknown_3d78_;
};

void SprSprite_SetPosition(Vec3Target0203a46c* obj, int x, int y, int z);

// USA: func_ov005_02156e1c
extern "C" ARM void func_ov005_02156e1c(Struct_ov005_02153954* arg0, int arg1, int arg2) {
    if (arg0->unknown_3d78_ < 0)
        return;
    Vector3fix position = self->dragModel_.position_;
    int curX = position.x >> 12;
    int curY = position.y >> 12;
    int newX = x - 12;
    if (newX < 1)
        newX = 1;
    if (newX > 0xe7)
        newX = 0xe7;
    int newY = y - 12;
    if (newY < 1)
        newY = 1;
    if (newY > 0xa7)
        newY = 0xa7;
    if (abs(curX - newX) < 3)
        newX = curX;
    if (abs(curY - newY) < 3)
        newY = curY;
    SprSprite_SetPosition((Vec3Target0203a46c*)&self->dragModel_, newX << 12, newY << 12, 0x2000);
}
