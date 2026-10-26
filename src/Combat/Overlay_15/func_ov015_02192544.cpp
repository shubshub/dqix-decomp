#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_020100cc(char* obj);
struct Struct_0204a120_2;
extern "C" void func_020a2cf0(struct Struct_0204a120_2* obj);
struct Struct_020a3568;
extern "C" void func_020a3568(struct Struct_020a3568* p, int v);
extern "C" void Camera_GetOrbit(unsigned char* obj, int* a, int* b, int* c);
extern "C" void Camera_SetOrbit(void* obj, int a, int b, int c);

// USA: func_ov015_02192544
extern "C" ARM void func_ov015_02192544(void) {
    GameState* battle = GameState::GetInstance();
    if (battle == 0) {
        return;
    }
    int obj = func_020100cc((char*)battle);
    if (obj == 0) {
        return;
    }
    func_020a2cf0((struct Struct_0204a120_2*)obj);
    func_020a3568((struct Struct_020a3568*)obj, 2);
    int a, b, c;
    Camera_GetOrbit((unsigned char*)obj, &a, &b, &c);
    Camera_SetOrbit((void*)obj, a, 0x13d7, c);
}
