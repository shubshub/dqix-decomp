#include <globaldefs.h>
#if defined(jpn)
enum { kRegion103a = 0xfb6 };
enum { kRegion874 = 0x7f0 };
enum { kRegion103c = 0xfb8 };
#else
enum { kRegion103a = 0x103a };
enum { kRegion874 = 0x874 };
enum { kRegion103c = 0x103c };
#endif

#include "GameState/GameState.h"

struct ItemTable;
struct Element020de650;
struct Element020de650* ItemTable_Find(struct ItemTable* c, int key);
void* GameState_GetParty(GameState* battleStruct);
extern "C" void func_ov003_02176798(void* obj);

// USA: func_ov003_02175d78
ARM int RefillAndResetEntry_02175d78(char* obj) {
	GameState* bs = GameState::GetInstance();
	int key = *(short*)(obj + kRegion103a);
	struct Element020de650* elem = ItemTable_Find((struct ItemTable*)(obj + kRegion874), key);
	void* p;
	unsigned int a;
	unsigned int b;
	unsigned int delta;
	if (elem == NULL) return 0;
	p = GameState_GetParty(bs);
	a = *(unsigned char*)(obj + kRegion103c);
	b = *(unsigned short*)((char*)elem + 0x1a);
	delta = a * b;
	{
		unsigned int cap = 0x98967f - *(unsigned int*)((char*)p + 0xf6c);
		if (cap < delta) delta = cap;
	}
	*(int*)((char*)p + 0xf6c) += delta;
	func_ov003_02176798(obj);
	return 1;
}
