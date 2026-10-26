#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov017_021d246c_15116 = 0x38ec };
#else
enum { Enum_ov017_021d246c_15116 = 0x3b0c };
#endif

#include "GameState/GameState.h"

// USA: func_ov017_021d246c
extern "C" ARM void func_ov017_021d246c(int arg0, char* b, GameState* battleStruct, char* d) {
	GameObject* c = battleStruct->GetLeader();
	int* p = *(int**)((char*)c + 0x130);
	if (*p & 1) {
		int* inner = *(int**)(d + Enum_ov017_021d246c_15116);
		if (inner != 0) {
			*(int*)((char*)inner + 0x60) = *(int*)(b + 4);
		}
	}
}
