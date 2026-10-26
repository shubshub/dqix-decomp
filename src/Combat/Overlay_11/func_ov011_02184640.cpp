#include <globaldefs.h>

struct Struct_ov011_02184374;
extern "C" void func_ov011_02184374(Struct_ov011_02184374* obj);

struct Foo0207df50;
extern "C" void VramState_Rewind(Foo0207df50* p);

struct State0207dfc8;
extern "C" void VramState_CopyCurrentTo(State0207dfc8* src, State0207dfc8* dst);

// USA: func_ov011_02184640
extern "C" ARM void func_ov011_02184640(char* obj, char* arg) {
    func_ov011_02184374((Struct_ov011_02184374*)(obj + 0x20));
    VramState_Rewind((Foo0207df50*)arg);
    VramState_CopyCurrentTo((State0207dfc8*)arg, (State0207dfc8*)(obj + 0x24));
}
