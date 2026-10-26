#include <globaldefs.h>

struct Obj021e4e20 {
#if defined(jpn)
	char pad[0x124];
#else
	char pad[0x128];
#endif
	void *ptr;
};

extern "C" int CharacterModel_GetBody(void *p);

// USA: func_ov023_021e4e20
extern "C" ARM int func_ov023_021e4e20(struct Obj021e4e20 *obj) {
	void *p = obj->ptr;
	if (p == NULL) {
		return 0;
	}
	return CharacterModel_GetBody(p);
}
