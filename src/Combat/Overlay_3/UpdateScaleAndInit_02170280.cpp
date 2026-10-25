#include <globaldefs.h>
#include "GameState/GameState.h"



int MessageSystem_GetInstance(void);
void Forward0204359c(void* obj, int count);
extern "C" void func_020439b0(void* obj, int flag);
struct Obj0205d2bc;
void Window_TransferLayers(struct Obj0205d2bc*);

// USA: func_ov003_02170280  (semantic: UpdateScaleAndInit_02170280)
extern "C" ARM void func_ov003_02170280(void* obj) {
    unsigned char* o = (unsigned char*)obj;
    GameState* battleStruct;
    void* g;
    unsigned int scaleCount;
    if (*(int*)(o + 0x3c) == 0) {
        return;
    }
    if (*(signed char*)(o + 1) <= 1) {
        return;
    }
    battleStruct = GameState::GetInstance();
    g = (void*)MessageSystem_GetInstance();
    scaleCount = battleStruct->GetTickCount();
    Forward0204359c(g, scaleCount);
    func_020439b0(g, 0);
    if (*(int*)(o + 0x3c) == 0) {
        return;
    }
    Window_TransferLayers((struct Obj0205d2bc*)*(int*)(o + 0x3c));
}
