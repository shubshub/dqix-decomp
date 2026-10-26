#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { Enum_ov003_02166184_1116 = 0x284 };
enum { Enum_ov003_02166184_1183 = 0x2c7 };
#else
enum { Enum_ov003_02166184_1116 = 0x45c };
enum { Enum_ov003_02166184_1183 = 0x49f };
#endif

extern "C" void func_ov003_02160c58(unsigned char* self, short* arg1, short* arg2);
extern "C" void* GameState_GetParty(GameState*);
extern "C" void func_ov003_02166220(unsigned char* self);

// USA: func_ov003_02166184
extern "C" ARM void func_ov003_02166184(unsigned char* self) {
	short var0, var1;
	unsigned char* base;
	int var3;
	int limit;
	int flags;
	func_ov003_02160c58(self, &var0, &var1);

	base = (unsigned char*)GameState_GetParty(GameState::GetInstance()) + 0x2000;
	var3 = base[0xc8c];
	limit = (var3 + 3) / 4;

	flags = *(int*)(self + Enum_ov003_02166184_1116);
	if (flags & 0x10) {
		self[Enum_ov003_02166184_1183] = (signed char)self[Enum_ov003_02166184_1183] + 1;
	} else if (flags & 0x20) {
		self[Enum_ov003_02166184_1183] = (signed char)self[Enum_ov003_02166184_1183] - 1;
	}
	if (limit <= (signed char)self[Enum_ov003_02166184_1183]) {
		self[Enum_ov003_02166184_1183] = 0;
	} else if ((signed char)self[Enum_ov003_02166184_1183] < 0) {
		self[Enum_ov003_02166184_1183] = limit - 1;
	}

	func_ov003_02166220(self);
}
