#include <globaldefs.h>

struct Obj_02184374;
void ClearFields_02184374(Obj_02184374* obj);

struct Foo0207df50;
void VramState_Rewind(Foo0207df50* p);

struct State0207dfc8;
void VramState_CopyCurrentTo(State0207dfc8* src, State0207dfc8* dst);

// USA: func_ov011_02184640
ARM void InitEntry02184640(char* obj, char* arg) {
    ClearFields_02184374((Obj_02184374*)(obj + 0x20));
    VramState_Rewind((Foo0207df50*)arg);
    VramState_CopyCurrentTo((State0207dfc8*)arg, (State0207dfc8*)(obj + 0x24));
}
