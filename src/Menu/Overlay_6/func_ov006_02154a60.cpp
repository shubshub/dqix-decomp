#if defined(jpn)
#define R(j,u) (j)
#define data_0210a00c data_02109cc4
#define data_ov005_0215cd74 data_ov005_0215e154
#define data_ov006_0215ff6c data_ov006_021612d0
#define func_ov005_02158878 func_ov005_02159e70
#define func_ov005_0215cb4c func_ov005_0215df2c
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "World/Object3D.h"
#include "NitroSDK/NSBXX/RenderConfig.h"
#include "GameState/GameState.h"

struct Struct_ov006_02154a60 {
    char unknown_0_[0x14];
    void* resource;
    char unknown18[0x2c];
    int resourceIndex;
    char unknown48[4];
    int unknown_4c_;
    char unknown50[0x26];
    short x;
    short y;
    char unknown_7a_[2];
};
struct Struct_ov006_02154a60_2 {
    char unknown_0_[R(0x54, 0x1d4)];
    void* unknown_1d4_;
    char unknown_1d8_[0x130];
    int phase;
    char unknown30c[0x1c];
    Vector3fix position;
    char unknown_334_[0x560];
    Struct_ov006_02154a60 unknown_894_[4];
    char unknown_a84_[0x58];
    unsigned char active;
    char unknown_add_[5];
    unsigned short flags;
    char unknown_ae4_[R(0x717, 0x79b)];
    unsigned char unknown_127f_0_ : 1;
    unsigned char hidden : 1;
    unsigned char unknown_127f_2_ : 6;
    char unknown_1280_[0x3b];
    unsigned char layout;
};
extern "C" {
extern "C" void func_0207fcb8(void*);
extern "C" void func_0207fd44(void*);
void G3X_ResetMtxStack();
extern Matrix4x3* data_ov006_0216038c[3];
struct Struct_ov006_0215ff6c { unsigned char entries[4][4]; };
extern Struct_ov006_0215ff6c data_ov006_0215ff6c;
extern int data_0210a00c;
extern "C" void Camera_WorldToScreen(void*, const Vector3fix*, int*, int*);
void OamManager_GetInstance();
void* OamManager_GetMainOamBuffer();
extern "C" void func_02076988(Struct_ov006_02154a60*, int, int);
extern "C" void func_02075db0(Struct_ov006_02154a60*, short, short);
}
inline int inline_ov006_02154a60(int a, int b)
{
    return (int)(((int64_t)a * b + 0x800) >> 12);
}
extern "C" ARM void func_ov006_02154a60(Struct_ov006_02154a60_2* state)
{
    if (state->hidden) return;
    if (!state->active) return;
    void* var0 = state->unknown_1d4_;
    func_0207fcb8(var0);
    func_0207fd44(var0);
    if (state->flags & 8) return;
    Matrix4x3 var1[3];
    for (int index = 0; index < 3; index++) data_ov006_0216038c[index] = &var1[index];
    G3X_ResetMtxStack();
    RenderConfig::SubmitToFifo();
    ((Object3D*)((char*)state + R(0x368, 0x4e8)))->UpdateTrackedBones();
    for (int index = 0; index < 3; index++) data_ov006_0216038c[index] = NULL;
    Vector3fix positions[3] = {
        {var1[0].translation.x, var1[0].translation.y, var1[0].translation.z},
        {var1[1].translation.x, var1[1].translation.y, var1[1].translation.z},
        {var1[2].translation.x, var1[2].translation.y, var1[2].translation.z}};
    int widths[3] = {var1[0].entries[0], var1[1].entries[0], var1[2].entries[0]};
    int heights[3] = {var1[0].entries[4], var1[1].entries[4], var1[2].entries[4]};
    for (int index = 0; index < 3; index++) {
        if (widths[index] < 40) widths[index] = 40;
        if (heights[index] < 40) heights[index] = 40;
    }
    unsigned char layout = state->layout;
    Struct_ov006_0215ff6c lookup = data_ov006_0215ff6c;
    void* camera = GameState::GetInstance()->GetCamera();
    if (camera) {
        Struct_ov006_02154a60* var11 = state->unknown_894_;
        for (unsigned char index = 0; index < 4; index++, var11++) {
            Vector3fix position = positions[lookup.entries[layout][index]];
            position.x = inline_ov006_02154a60(position.x, ((Object3D*)((char*)state + R(0x164, 0x2e4)))->GetScale().x);
            position.y = inline_ov006_02154a60(position.y, ((Object3D*)((char*)state + R(0x164, 0x2e4)))->GetScale().y);
            position.z = inline_ov006_02154a60(position.z, ((Object3D*)((char*)state + R(0x164, 0x2e4)))->GetScale().z);
            Vector3fix world;
            Vector3fix offset = state->position;
            Vector3fix_Add(&position, &offset, &world);
            int x, y;
            Camera_WorldToScreen(camera, &world, &x, &y);
            var11->x = x - 18;
            var11->y = y - 12;
        }
    }
    OamManager_GetInstance();
    void* resource = OamManager_GetMainOamBuffer();
    Struct_ov006_02154a60* var19;
    unsigned char index;
    int phase = state->phase;
    if ((state->flags & 0x2000) || (state->flags & 0x80)) {
        if (!((Object3D*)((char*)state + R(0x368, 0x4e8)))->HasAnimationStopped()) {
            index = 1;
            var19 = &state->unknown_894_[1];
            for (; index < 4; index++) {
                int var22 = lookup.entries[layout][index];
                int var23 = index * 4 + 0x20;
                var19->unknown_4c_ = 0x300;
                var19->resource = (char*)resource + var23 * 8;
                var19->resourceIndex = var23 / 4;
                func_02076988(var19, widths[var22], heights[var22]);
                func_02075db0(var19, var19->x, var19->y);
                var19++;
            }
        }
    }
    if (state->flags & 0x200) {
        data_0210a00c = 0;
        Struct_ov006_02154a60* var24 = &state->unknown_894_[0];
        if (phase > 983 && var24->y < 192) {
            var24->unknown_4c_ = 0x300;
            var24->resource = (char*)resource + 0x120;
            var24->resourceIndex = 9;
            func_02076988(var24, widths[0], heights[0]);
            func_02075db0(var24, var24->x, var24->y);
        }
    }
}
