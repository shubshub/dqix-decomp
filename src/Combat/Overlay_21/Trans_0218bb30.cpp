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

void ResetGxEngineState020c52e8();
extern "C" void func_020c5414();
extern "C" void func_0202e0a4(void* camera);
extern "C" void CharacterCreationUI_Draw3D(void* obj);
extern "C" void CharacterCreationUI_Draw2D(void* obj);
extern "C" void* func_0203bd08();
void CleanInvalidateOamBuffers0203bd88(void* oam);
void WriteControlAndToggle020d86d0(int a, int b);

// USA: func_ov021_0218bb30  (semantic: Trans_0218bb30)
extern "C" ARM void func_ov021_0218bb30(Trans0218bb30* self)
{
    GameState* gameState = GameState::GetInstance();
    void* camera = GetField0x3b0Value_020100bc(gameState);
    ResetGxEngineState020c52e8();
    func_020c5414();
    DISP3DCNT = (DISP3DCNT & ~0x3000) | 8;
    DISP3DCNT = (DISP3DCNT & ~0x3000) | 0x10;
    DISP3DCNT = (DISP3DCNT & ~0x3000) | 0x20;
    if (camera != NULL)
        func_0202e0a4(camera);
    RenderConfig::SubmitToFifo();
    SendQueuedDataToGeometryFifo();
    CharacterCreationUI_Draw3D(self->f40);
    CharacterCreationUI_Draw2D(self->f40);
    CleanInvalidateOamBuffers0203bd88(func_0203bd08());
    WriteControlAndToggle020d86d0(1, 0);
}
