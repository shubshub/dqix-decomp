#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"

extern "C" void GameObject_EnableControl(void* obj);
extern "C" void* GlobalFlags_GetInstance(void);
struct FlagWord020466f4 {
    unsigned int flags;
};
extern "C" void FlagWord_ClearBits(struct FlagWord020466f4* word, unsigned int mask);

struct Struct020d9fc8 {
    char pad[0xc];
    int arr[1];
};

// Main, originally ClearHandleArrayAndFinalize020d9fc8 (USA 0x020d9fc8, EUR 0x020d9fd8, JPN 0x020db9d0)
extern "C" ARM void FieldTask_EndQuestCancel(struct Struct020d9fc8* p) {
    int x = (int)BackgroundLoader::GetInstance();
    int i;
    for (i = 0; i < 1; i++) {
        if (p->arr[i] != -1) {
            ((BackgroundLoader*)(x))->RemoveTask((int)(p->arr[i]));
            p->arr[i] = -1;
        }
    }
    GameObject_EnableControl(GameState::GetInstance()->GetLeader());
    FlagWord_ClearBits((struct FlagWord020466f4*)GlobalFlags_GetInstance(), 0x1e);
    *((unsigned char*)p + 1) = 1;
}
