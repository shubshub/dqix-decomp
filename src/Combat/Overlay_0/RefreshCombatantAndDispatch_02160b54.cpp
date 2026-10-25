#include <globaldefs.h>
#include "GameState/Field3b0.h"
#if defined(jpn)
enum { flagsOffset = 0x57e4, workOffset = 0xe44, combatantOffset = 0x71c6, stateOffset = 0xe24, dispatchOffset = 0x5ca0 };
#else
enum { flagsOffset = 0x55f4, workOffset = 0xec8, combatantOffset = 0x6fd6, stateOffset = 0xea8, dispatchOffset = 0x5ab0 };
#endif
#include "GameState/GameState.h"
#include "NitroSDK/NSBXX/RenderConfig.h"
#include "Resource/Brightness.h"

extern "C" void func_02016874(void* big);
extern "C" void func_ov000_02161020(void* obj);
struct Vector3i;
int PeekInputLogB_020a1fa8(void);
extern "C" void func_ov025_021df864(void* arg);

// USA: func_ov000_02160b54  (semantic: RefreshCombatantAndDispatch_02160b54)
extern "C" ARM void func_ov000_02160b54(unsigned char* obj) {
    GameState* battle = GameState::GetInstance();
    unsigned int* v = ((unsigned int*)GetGameResources());
    battle->GetCamera();
    if (!(*(int*)(obj + flagsOffset) & 0x200)) {
        return;
    }
    if (TestFlags04((GameResources*)v, 0x100000) == 0) {
        func_02016874(obj + workOffset);
    }
    func_ov000_02161020(obj);
    if (TestFlags04((GameResources*)v, 4) == 0) {
        GameObject* c1 = battle->GetGameObjectByIndex(*(short*)(obj + combatantOffset));
        GameObject* c2 = battle->GetGameObjectByIndex(0xc8);
        if (c2 != 0) {
            if (c1 != 0) {
                *(Vector3i*)(&c2->obj3D_.position_.x) = *(Vector3i const*)(&c1->obj3D_.position_.x);
                *(Vector3i*)(&c2->obj3D_.rotation_.x) = *(Vector3i const*)(&c1->obj3D_.rotation_.x);
                const Vector3fix& tmp = c1->obj3D_.GetScale();
                ((Object3D*)((unsigned char*)c2))->SetScale(&tmp);
            }
            c2->obj3D_.Draw(0);
        }
    }
    RenderConfig::SubmitToFifo();
    if (*(int*)(obj + stateOffset) != 8) {
        return;
    }
    if (PeekInputLogB_020a1fa8() != 4) {
        return;
    }
    func_ov025_021df864(obj + dispatchOffset);
}
