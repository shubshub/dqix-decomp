#if defined(jpn)
#define R(j,u) (j)
#define data_ov015_02193d14 data_ov015_02194844
#define data_ov015_02193d2c data_ov015_0219485c
#define data_ov015_02193d38 data_ov015_02194868
#define data_ov027_021dd8e0 data_ov027_021de1a0
#define func_ov014_0218854c func_ov014_0218942c
#define func_ov014_021885bc func_ov014_0218948c
#define func_ov015_0219050c func_ov015_021910b0
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "NitroSDK/NSBXX/GeometryFifo.h"
#include "NitroSDK/NSBXX/RenderConfig.h"
#include "Resource/Brightness.h"
#include "NitroSDK/Graphics.h"
#include "NitroSDK/Matrix.h"

struct Struct_ov015_02193d38
{
    unsigned short colors_[8];
};

extern "C" void G3X_Reset();
extern "C" void G3X_ResetMtxStack();
extern "C" int G3X_SetEdgeColorTable(int a);
extern "C" void Camera_Update(void* camera);
extern "C" void G3i_LookAt_(int a, int b, int c, int d, void* e);
extern "C" void G3i_OrthoW_(int a, int b, int c, int d, int e, int f, int g, int h, void* i);
extern "C" void func_020d86d0(int a, int b);
extern "C" void func_ov015_02190348(void* self);
extern "C" void func_ov015_02190428(void* self);
extern "C" void func_ov015_0219050c(void* self);

extern const Struct_ov015_02193d38 data_ov015_02193d38;
extern const Vector3fix data_ov015_02193d14;
extern const Vector3fix data_ov015_02193d2c;

// USA: func_ov015_021901c8
extern "C" ARM void func_ov015_021901c8(void* self)
{
    GameState* gameState = GameState::GetInstance();
    if (gameState == NULL)
        return;
    G3X_Reset();
    G3X_ResetMtxStack();
    RenderConfig::Reset();
    DISP3DCNT = (DISP3DCNT & ~0x3000) | 8;
    DISP3DCNT = (DISP3DCNT & ~0x3000) | 0x10;
    DISP3DCNT = (DISP3DCNT & ~0x3000) | 0x20;
    {
        Struct_ov015_02193d38 colors = data_ov015_02193d38;
        G3X_SetEdgeColorTable((int)colors.colors_);
    }
    void* camera = gameState->GetCamera();
    if (camera != NULL)
        Camera_Update(camera);
    RenderConfig::SubmitToFifo();
    SendQueuedDataToGeometryFifo();
    func_ov015_02190348(self);
    G3X_Reset();
    G3X_ResetMtxStack();
    GXFIFO_MATRIX_MODE = 0;
    {
        Vector3fix target = data_ov015_02193d14;
        Vector3fix eye = {0};
        Vector3fix up = data_ov015_02193d2c;
        G3i_LookAt_((int)&eye, (int)&up, (int)&target, 1, NULL);
    }
    G3i_OrthoW_(0, 0xc0000, 0, 0x100000, -0x400000, 0x400000, 0x400000, 1, NULL);
    GXFIFO_MATRIX_MODE = 2;
    func_ov015_02190428(self);
    func_ov015_0219050c(self);
    func_020d86d0(1, 0);
    UpdateAndApplyBrightness((GameResources*)self);
}
