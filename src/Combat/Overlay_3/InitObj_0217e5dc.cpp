#include <globaldefs.h>
#if defined(jpn)
enum { kRegion998 = 0x868 };
enum { kRegion36fc = 0x34ec };
enum { kRegion3b04 = 0x38e4 };
#else
enum { kRegion998 = 0x998 };
enum { kRegion36fc = 0x36fc };
enum { kRegion3b04 = 0x3b04 };
#endif

#include "GameState/GameState.h"

int MessageSystem_GetInstance(void);

void MessageSystem_Reset(char* obj);
extern "C" void MessageSystem_Stop(char* obj);

struct TailNode020469b4;
struct TailList020469b4;
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);

void InitStruct0217e630(void* obj, signed char flag);

struct Obj0217e5dc {
	char pad1[kRegion36fc];
	struct TailList020469b4* list;
	char pad2[kRegion3b04 - kRegion36fc - 4];
	void* target;
};

// USA: func_ov003_0217e5dc
ARM void InitObj_0217e5dc(struct Obj0217e5dc* self, signed char flag) {
	GameState::GetInstance();
	int* g = (int*)(int)MessageSystem_GetInstance();
	if (*(int*)((char*)g + kRegion998) != 0) {
		MessageSystem_Reset((char*)g);
		MessageSystem_Stop((char*)g);
	}
	InitStruct0217e630(self->target, flag);
	AppendNodeToTail(self->list, (struct TailNode020469b4*)self->target);
}
