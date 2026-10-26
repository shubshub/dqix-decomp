#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"

struct Struct_ov001_0215af34;
extern "C" void func_ov017_021d6148(Struct_ov001_0215af34* o, unsigned int v);
extern "C" unsigned int _fflt(int);
extern "C" unsigned int _fdiv(unsigned int, unsigned int);

struct Struct_ov001_0215daa8 { int a, b, c; };

// USA: func_ov001_0215daa8
extern "C" ARM int func_ov001_0215daa8(void* self) {
    int* base = (int*)GameState::GetInstance()->GetCamera();
    if (base == NULL) return 0;
    Struct_ov001_0215daa8 v = *(Struct_ov001_0215daa8*)((char*)base + 0x10);
    func_ov017_021d6148((Struct_ov001_0215af34*)self, _fdiv(_fflt(v.a), 0x45800000u));
    func_ov017_021d6148((Struct_ov001_0215af34*)((char*)self + 0x8), _fdiv(_fflt(v.b), 0x45800000u));
    func_ov017_021d6148((Struct_ov001_0215af34*)((char*)self + 0x10), _fdiv(_fflt(v.c), 0x45800000u));
    return 1;
}
