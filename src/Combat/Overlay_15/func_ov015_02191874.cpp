#include <globaldefs.h>
#include "GameState/GameState.h"
#include "NitroSDK/NSBXX/RenderConfig.h"
#include "NitroSDK/Matrix.h"
#include "Input/Input.h"

struct Vec3
{
    int x;
    int y;
    int z;
};

struct Struct_ov015_0218f44c_2;
struct Struct_ov015_0218c03c_2;

struct Struct_ov015_02190acc
{
    char unk_0[0x34];
    Struct_ov015_0218c03c_2* unknown_34_;
};

void Vector3fixMultiplyScalar(const Vector3i* in, int scale, Vector3i* out);
extern "C" void func_ov015_0218f44c(Struct_ov015_0218f44c_2* object, Vec3 offset);
extern "C" void func_ov015_0218f5f8(Struct_ov015_0218c03c_2* object, int angle);

// USA: func_ov015_02191874
extern "C" ARM void func_ov015_02191874(Struct_ov015_02190acc* self)
{
    if (self->unknown_34_ == NULL)
        return;
    GameState::GetInstance();
    Vector3fix move = {0};
    Matrix3x3 view;
    if (g_keyManager.TestKeysHeld(0x40))
        move.z = -0x199;
    if (g_keyManager.TestKeysHeld(0x80))
        move.z = 0x199;
    if (g_keyManager.TestKeysHeld(0x10))
        move.x = 0x199;
    if (g_keyManager.TestKeysHeld(0x20))
        move.x = -0x199;
    memcpy(&view, RenderConfig::GetInverseViewMatrix(), sizeof(view));
    Mat3x3_ApplyToVector(&move, &view, &move);
    move.y = 0;
    Vector3fix_Normalize(&move, &move);
    Vector3fixMultiplyScalar(&move, 0x199, &move);
    if (g_keyManager.TestKeysHeld(0x400))
        move.y += 0x199;
    if (g_keyManager.TestKeysHeld(0x800))
        move.y -= 0x199;
    func_ov015_0218f44c((Struct_ov015_0218f44c_2*)self->unknown_34_, *(Vec3*)&move);
    if (g_keyManager.TestKeysHeld(0x200))
        func_ov015_0218f5f8(self->unknown_34_, 0x199);
    if (g_keyManager.TestKeysHeld(0x100))
        func_ov015_0218f5f8(self->unknown_34_, -0x199);
}
