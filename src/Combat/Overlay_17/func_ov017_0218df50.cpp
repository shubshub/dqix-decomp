#include <globaldefs.h>
#include "Combat/EntryGetterTypes.h"
#include "Resource/Brightness.h"

extern "C" void* func_0203cf4c(void);

struct Struct_0203dce4;
struct Struct_0203dce4_2;
extern "C" struct Struct_0203dce4* func_0203dce4(struct Struct_0203dce4_2* list, int id);
extern "C" int func_02040528(int* obj);

extern "C" int func_ov017_0218dd18(void* a, struct Struct_0203dce4* entry, void* b);

#pragma optimize_for_size off
// USA: func_ov017_0218df50
extern "C" ARM int func_ov017_0218df50(void* a, void* b) {
	int result = 0;
	GameResources* ctx = GetGameResources();
	if (TestFlags00(ctx, 0x100) == 0) {
		void* list = func_0203cf4c();
		for (int i = 0; i < 0x20; i++) {
			struct Struct_0203dce4* entry = func_0203dce4((struct Struct_0203dce4_2*)list, i);
			if (!entry) continue;
			int field = func_02040528(&entry->flags);
			if (*((unsigned char*)field + 2) == 1) continue;
			if (func_ov017_0218dd18(a, entry, b) != 0) {
				result = 1;
			}
		}
	}
	return result;
}
