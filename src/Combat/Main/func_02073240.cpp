#include <globaldefs.h>

#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" void func_020730e0(int id, int index);
extern "C" int func_ov017_0218fcf8(int a, int b, int c);

extern short data_020e8846[];

// USA: func_02073240
extern "C" ARM void func_02073240(int arg0) {
    GameState* gs = GameState::GetInstance();
    GameObject* obj = gs->GetGameObjectByIndex(arg0);
    if (!obj) return;

    short v;
    int i = 0;
    while ((v = data_020e8846[i]) >= 0) {
        func_020730e0(arg0, v);
        i++;
    }

    if (*(unsigned short*)((char*)obj + 0x9c) == 0) return;

    int x = (int)GetGameResources();
    func_ov017_0218fcf8(x, arg0, *(unsigned short*)((char*)obj + 0x9c));
}
