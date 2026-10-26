#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_02053c6c(unsigned char* obj);

// USA: func_ov017_021ccbdc
extern "C" ARM void func_ov017_021ccbdc(int unused0, unsigned char* obj, GameState* battleStruct) {
	unsigned char* src = obj + 4;
	unsigned short id = *(unsigned short*)(src + 0xc);
	GameObject* c = func_0200ff1c(battleStruct, id);
	if (!c) return;
	unsigned char* base = (unsigned char*)func_02053c6c((unsigned char*)c);
	if (!base) return;
	unsigned char var4 = src[0xe];
	unsigned char i = 0;
	while (i < 3) {
		unsigned int v = *(unsigned int*)(src + i * 4);
		unsigned char* dst = base + (i + var4) * 4;
		i++;
		*(unsigned int*)(dst + 0x138) = v;
	}
}
