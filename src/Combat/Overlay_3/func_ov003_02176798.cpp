#include <globaldefs.h>
#if defined(jpn)
enum { kRegion89c = 0x818 };
#else
enum { kRegion89c = 0x89c };
#endif

#include "GameState/GameState.h"

extern "C" void* GameState_GetParty(GameState*);
struct Struct_0207fdcc_2;
extern "C" void func_02080c20(struct Struct_0207fdcc_2* obj, int key);
extern "C" void func_02080c68(void* obj, int id, int value);
struct Struct_02080fa8;
extern "C" void func_02080fa8(struct Struct_02080fa8* obj, int id, int value);
extern "C" void func_020813ec(void* obj, int key);

// USA: func_ov003_02176798
extern "C" ARM void func_ov003_02176798(char* obj) {
    void* f2a04 = GameState_GetParty(GameState::GetInstance());
    struct Struct_0207fdcc_2* o = *(struct Struct_0207fdcc_2**)(obj + kRegion89c);
    func_02080c20(o, 0);
    func_02080c68(o, 0, 0);
    int f = *(int*)((char*)f2a04 + 0xf6c);
    func_02080fa8((struct Struct_02080fa8*)o, 0, f);
    func_020813ec(o, 0);
}
