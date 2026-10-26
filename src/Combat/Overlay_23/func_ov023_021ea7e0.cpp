#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int GameState_GetProtagonistIndex(GameState* battleStruct);
extern "C" int func_02053c6c(unsigned char* obj);
extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov023_021ea7e0
extern "C" ARM int func_ov023_021ea7e0(void *obj) {
	GameState *bs = GameState::GetInstance();
	int id = GameState_GetProtagonistIndex(bs);
	void *combatant = (void*)func_0200ff1c(bs, id);
	int sum = 0;
	if (combatant) {
		int var4 = func_02053c6c((unsigned char*)combatant);
		int *arr = (int*)(var4 + 0x138);
		for (int i = 0; i < 13; i++) {
			sum += arr[i];
			if ((unsigned int)sum > 0x7fffffffu) {
				sum = 0x7fffffff;
				break;
			}
		}
	}
	func_ov017_021d6134(obj, sum);
	return 1;
}
