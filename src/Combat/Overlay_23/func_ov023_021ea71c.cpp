#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_ov017_021d60f4(void*);
extern "C" int func_ov023_021e8f28(int);
extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov023_021ea71c
extern "C" ARM int func_ov023_021ea71c(void *obj) {
	GameState::GetInstance();
	void *p = (void*)func_ov023_021e8f28(func_ov017_021d60f4(obj));
	if (!p) return 0;
	void *q = *(void**)((char*)p + 0x130);
	int flag = 0;
	if (*(int*)q & 0x2) flag = 1;
	if (flag) {
		func_ov017_021d6134((char*)obj + 8, 1);
	} else {
		func_ov017_021d6134((char*)obj + 8, 0);
	}
	return 1;
}
