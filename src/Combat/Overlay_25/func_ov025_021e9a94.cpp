#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"

extern "C" void* func_ov000_02160130(void);
extern "C" void func_ov000_0216d370(int a, int b, int c, int d);

extern unsigned int data_ov025_021ef9a4;
extern unsigned int data_ov025_021ef9c0;

struct Struct_ov025_021e9778_5 {
    char pad[0x1c0];
    int unknown_1c0_;
};

// USA: func_ov025_021e9a94
extern "C" ARM void func_ov025_021e9a94(struct Struct_ov025_021e9778_5* obj) {
    GameState* bs = GameState::GetInstance();
    void* val = bs->GetCamera();
    bs->GetResources();
    func_ov000_02160130();
    if (data_ov025_021ef9a4 & 1) {
        data_ov025_021ef9a4 = (data_ov025_021ef9a4 | 8) & ~1;
    }
    if (!(data_ov025_021ef9a4 & 2)) {
        return;
    }
    if (obj->unknown_1c0_ == 0) {
        func_ov000_0216d370((int)val, 1, 1, 1);
    }
    data_ov025_021ef9c0 += 1;
    data_ov025_021ef9a4 &= ~2;
}
