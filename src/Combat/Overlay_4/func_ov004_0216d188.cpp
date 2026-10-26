#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_0200fb94(char* obj, unsigned char value);
extern "C" void func_02012028(void* obj, unsigned char value);
extern "C" void func_ov011_021848a0(void* obj, int val);

// USA: func_ov004_0216d188
extern "C" ARM int func_ov004_0216d188(void* obj) {
    GameState* battle = GameState::GetInstance();
    func_0200fb94((char*)battle, 2);
    func_02012028(battle, 0);
    func_ov011_021848a0(obj, 0x3e7);
    return 0;
}
