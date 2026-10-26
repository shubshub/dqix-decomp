#if defined(jpn)
#define R(j,u) (j)
#define data_ov011_021889a0 data_ov011_02189700
#define data_ov013_02187dd8 data_ov013_02188cf0
#define func_ov006_02154fe4 func_ov006_02156730
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* MessageSystem_GetInstance();
extern "C" void func_0204359c(void*, int);
extern "C" void func_020439b0(void*, int);
struct Obj0205d2bc;
extern "C" void Window_TransferLayers(Obj0205d2bc*);
extern "C" void func_0205cb60(void*);

// USA: func_ov013_02184aec
extern "C" ARM void func_ov013_02184aec(void* obj) {
    unsigned char* o = (unsigned char*)obj;
    unsigned char tag = o[R(0x5c8,0x63c)];
    switch (tag) {
        case 0: case 5: case 6: return;
    }

    void* battle = GameState::GetInstance();
    void* field = MessageSystem_GetInstance();
    int count = ((GameState*)battle)->GetTickCount();
    func_0204359c(field, count);
    func_020439b0(field, 0);
    Window_TransferLayers((Obj0205d2bc*)(o + R(0x34,0x38)));
    func_0205cb60(o + R(0x3d0,0x3d4));
}
