#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Grotto/Main/TreasureMapMetadata.h"
#include "Resource/GameResources.h"

extern "C" void func_02011a40(char* obj);
struct Struct_ov004_02164670;
extern "C" void func_ov017_0218d77c(int obj, int a);

// USA: func_ov004_02165ad4
extern "C" ARM int func_ov004_02165ad4(void) {
    func_02011a40((char*)GameState::GetInstance());
    func_ov017_0218d77c((int)((struct Struct_ov004_02164670*)GetGameResources()), 2);
    return 0;
}
