#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_0201075c(char* obj, unsigned char value);

// USA: func_ov017_021d2428
extern "C" ARM void func_ov017_021d2428() {
	func_0201075c((char*)GameState::GetInstance(), 1);
}
