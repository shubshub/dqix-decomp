#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_0217e5dc_2456 = 0x868 };
enum { Enum_ov003_0217e5dc_14076 = 0x34ec };
enum { Enum_ov003_0217e5dc_15108 = 0x38e4 };
#else
enum { Enum_ov003_0217e5dc_2456 = 0x998 };
enum { Enum_ov003_0217e5dc_14076 = 0x36fc };
enum { Enum_ov003_0217e5dc_15108 = 0x3b04 };
#endif

#include "GameState/GameState.h"

extern "C" int MessageSystem_GetInstance(void);

extern "C" void MessageSystem_Reset(char* obj);
extern "C" void MessageSystem_Stop(char* obj);

struct TailNode020469b4;
struct TailList020469b4;
extern "C" void func_020469b4(struct TailList020469b4* list, struct TailNode020469b4* node);

extern "C" void func_ov003_0217e630(void* obj, signed char flag);

struct Struct_ov003_02162f40_3 {
	char pad1[Enum_ov003_0217e5dc_14076];
	struct TailList020469b4* list;
	char pad2[Enum_ov003_0217e5dc_15108 - Enum_ov003_0217e5dc_14076 - 4];
	void* target;
};

// USA: func_ov003_0217e5dc
extern "C" ARM void func_ov003_0217e5dc(struct Struct_ov003_02162f40_3* self, signed char flag) {
	GameState::GetInstance();
	int* g = (int*)(int)MessageSystem_GetInstance();
	if (*(int*)((char*)g + Enum_ov003_0217e5dc_2456) != 0) {
		MessageSystem_Reset((char*)g);
		MessageSystem_Stop((char*)g);
	}
	func_ov003_0217e630(self->target, flag);
	func_020469b4(self->list, (struct TailNode020469b4*)self->target);
}
