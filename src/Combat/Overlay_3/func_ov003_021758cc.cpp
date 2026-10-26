#include <globaldefs.h>
#if defined(jpn)
enum { kRegion103a = 0xfb6 };
enum { kRegion874 = 0x7f0 };
#else
enum { kRegion103a = 0x103a };
enum { kRegion874 = 0x874 };
#endif

#include "GameState/GameState.h"

struct ItemTable;
struct Element020de650;
extern "C" struct Element020de650* ItemTable_Find(struct ItemTable* c, int key);
extern "C" unsigned int func_ov003_02175898(char* obj, void* s);
extern "C" void* GameState_GetParty(GameState* battleStruct);

// USA: func_ov003_021758cc
extern "C" ARM int func_ov003_021758cc(char* self, int count) {
	short key = *(short*)(self + kRegion103a);
	struct Element020de650* elem = ItemTable_Find((struct ItemTable*)(self + kRegion874), key);
	if (elem == NULL)
		return 0;
	unsigned int total = count * func_ov003_02175898(self, elem);
	int result = 0;
	if (total <= *(unsigned int*)((char*)GameState_GetParty(GameState::GetInstance()) + 0xf6c))
		result = 1;
	return result;
}
