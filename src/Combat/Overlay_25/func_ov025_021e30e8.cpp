#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov000_02160130(void);

struct Struct_ov025_021ef9a8 { int a; int b; int c; int d; int e; int f; };
extern "C" void func_ov025_021e3158(struct Struct_ov025_021ef9a8* p);

extern int data_ov025_021ef988;
extern struct Struct_ov025_021ef9a8 data_ov025_021ef9a8;

struct Struct_ov025_021e30e8 { char pad[8]; unsigned int field8; unsigned char unknown_c_; };

// USA: func_ov025_021e30e8
extern "C" ARM int func_ov025_021e30e8(struct Struct_ov025_021e30e8* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x71c0};
#else
 enum {regionalOffset0=0x6fd0};
#endif
    GameState* battle = GameState::GetInstance();
    if (obj->field8 <= *(unsigned int*)((char*)&data_ov025_021ef988 + 0x34)) {
        if (obj->unknown_c_ != 0) {
            void* work = func_ov000_02160130();
            *(int*)((char*)work + regionalOffset0) = obj->field8;
        }
        func_ov025_021e3158(&data_ov025_021ef9a8);
        return 1;
    }
    int* p = &data_ov025_021ef988 + 13;
    *p += battle->GetEffectiveDeltaTime();
    return 0;
}
