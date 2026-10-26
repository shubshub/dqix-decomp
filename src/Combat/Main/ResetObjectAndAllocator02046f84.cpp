#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"

void Camera_SetRoll(unsigned char* obj, unsigned short val);
struct AngleTrig0202e9a4;
void Camera_SetFieldOfView(struct AngleTrig0202e9a4* objParam, int angle);
extern "C" void Camera_SetOrbitFromPosition(void* obj);
void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);

extern int g_mainAllocator;

struct Struct02046f84 {
    int field0;
    int field4;
    char pad[0x24 - 8];
    SafeAllocator allocator;
    int field38;
};

// USA: func_02046f84
ARM void ResetObjectAndAllocator02046f84(struct Struct02046f84* s) {
    GameState* battleStruct = GameState::GetInstance();
    battleStruct->GetResources();
    void* obj = battleStruct->GetCamera();
    Camera_SetRoll((unsigned char*)obj, 0);
    Camera_SetFieldOfView((struct AngleTrig0202e9a4*)obj, 0xf000);
    Camera_SetOrbitFromPosition(obj);

    if (s->field38 == 0) {
        void* p = s->allocator.GetSignedAllocator();
        if (p != NULL) {
            s->allocator.Reset();
            s->allocator.Destroy();
            AllocatorUnion_Free((AllocatorUnion*)&g_mainAllocator, p);
        }
    }
    s->field0 = 0;
    s->field4 = 0;
}
