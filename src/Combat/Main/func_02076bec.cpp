#include <globaldefs.h>
#include "GameState/GameState.h"
#include "GameState/Field3b0.h"
#include "NitroSDK/NSBXX/RenderConfig.h"

extern "C" int GameObject_Draw(void* obj, void* param1, int flag);
extern "C" void* Camera_GetInverseRotation(void* obj);
extern "C" void MI_Copy36B(void* ptr, void* addr);

extern "C" void func_02047448(int a, int b, int c);

extern int data_0210a0cc;
extern Vector3i data_020e8920;

// USA: func_02076bec
extern "C" ARM int func_02076bec(GameObject* arg0, void* param1) {
    unsigned char* obj = (unsigned char*)arg0;
    if (!arg0->obj3D_.IsVisible()) {
        return 0;
    }

    int result = GameObject_Draw(obj, param1, 0);
    if (*(unsigned char*)(obj + 0x17a) == 0) {
        return result;
    }

    GameState* battleStruct = GameState::GetInstance();
    void* f3b0 = battleStruct->GetCamera();

    Vector3i localBuf = arg0->obj3D_.position_;
    localBuf.y = *(int*)(obj + 0x170);
    RenderConfig::SetObjectPosition(&localBuf);

    if (f3b0 != 0) {
        void* ptr = Camera_GetInverseRotation(f3b0);
        MI_Copy36B(ptr, &data_0210a0cc);
        data_0210a010.flags &= ~0xa4;
    }

    Vector3i var6 = data_020e8920;
    RenderConfig::SetObjectScale(&var6);
    RenderConfig::SubmitToFifo();

    func_02047448(*(int*)(obj + 0x16c), 0, 1);
    return result;
}
