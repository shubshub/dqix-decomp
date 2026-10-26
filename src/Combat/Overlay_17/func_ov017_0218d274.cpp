#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" unsigned char func_0200fb9c(char* obj);
extern "C" void MapVRAMBanksToTextureImage(int a);
extern "C" void func_020bb48c(unsigned int mode, int arg1);
extern "C" void func_020bb780(void* value, int arg1);

// USA: func_ov017_0218d274
extern "C" ARM void func_ov017_0218d274(void* controller) {
	if (func_0200fb9c((char*)GameState::GetInstance()) == 6) {
		MapVRAMBanksToTextureImage(3);
		func_020bb48c(2, 1);
	} else {
		MapVRAMBanksToTextureImage(0xf);
		func_020bb48c(4, 1);
	}
	func_020bb780((void*)0x4000, 1);
}
