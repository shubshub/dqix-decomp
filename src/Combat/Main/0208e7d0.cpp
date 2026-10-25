#include <globaldefs.h>
#include "Util/Random.h"
#include "GameState/GameState.h"


struct Struct_0208e7d0 {
    char unknown_0_[0xc];
    short* unknown_c_;
};

extern "C" void* Scenario_GetInstance(void);
int GetField5cb0Value_0201079c(char* obj);

// USA: func_0208e7d0
extern "C" ARM int func_0208e7d0(struct Struct_0208e7d0* arg0) {
    if (arg0->unknown_c_ == 0) {
        return 0;
    }
    int count = 8;
    GameState* bs = GameState::GetInstance();
    Scenario_GetInstance();
    if (GetField5cb0Value_0201079c((char*)bs) >= 0x13) {
        count = 0x10;
    }
    struct Random* var2 = GetBTRandom();
    int var3 = NextRandomMax(var2, var0);
    return arg0->unknown_c_[var3];
}
