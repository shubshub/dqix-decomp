#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov005_02156e1c_15600 = 0x3c68 };
#else
enum { Enum_ov005_02156e1c_15600 = 0x3cf0 };
#endif

#include <NitroSDK/Matrix.h>
#include <std_library_functions.h>

struct Vec3Target0203a46c;

struct MenuModel {
    char unk_0[0x1c];
    Vector3fix position_;
    char unk_28[0x88 - 0x28];
};

struct EquipmentMenu {
    char unk_0[Enum_ov005_02156e1c_15600];
    MenuModel dragModel_;
    short dragged_;
};

extern "C" void SprSprite_SetPosition(Vec3Target0203a46c* obj, int x, int y, int z);

// USA: func_ov005_02156e1c
extern "C" ARM void func_ov005_02156e1c(EquipmentMenu* self, int x, int y) {
    if (self->dragged_ < 0)
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
