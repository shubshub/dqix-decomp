#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "GameState/Field3b0.h"
#include "NitroSDK/NSBXX/GeometryFifo.h"
#include "NitroSDK/NSBXX/RenderConfig.h"
#include "NitroSDK/Graphics.h"

struct Trans0218bb30
{
    char pad0[0x40];
    void* f40;
};

void G3X_Reset();
extern "C" void G3X_ResetMtxStack();
extern "C" void Camera_Update(void* camera);
extern "C" void CharacterCreationUI_Draw3D(void* obj);
extern "C" void CharacterCreationUI_Draw2D(void* obj);
extern "C" void* OamManager_GetInstance();
void OamManager_FlushBuffers(void* oam);
void WriteControlAndToggle020d86d0(int a, int b);

// USA: func_ov021_0218bb30  (semantic: Trans_0218bb30)
extern "C" ARM void func_ov021_0218bb30(Trans0218bb30* self)
{
    GameState* gameState = GameState::GetInstance();
    void* camera = gameState->GetCamera();
    G3X_Reset();
    G3X_ResetMtxStack();
    DISP3DCNT = (DISP3DCNT & ~0x3000) | 8;
    DISP3DCNT = (DISP3DCNT & ~0x3000) | 0x10;
    DISP3DCNT = (DISP3DCNT & ~0x3000) | 0x20;
    if (camera != NULL)
        Camera_Update(camera);
    RenderConfig::SubmitToFifo();
    SendQueuedDataToGeometryFifo();
    CharacterCreationUI_Draw3D(self->f40);
    CharacterCreationUI_Draw2D(self->f40);
    OamManager_FlushBuffers(OamManager_GetInstance());
    WriteControlAndToggle020d86d0(1, 0);
}
