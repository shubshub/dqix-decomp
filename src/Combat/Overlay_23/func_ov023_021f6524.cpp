#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(void* ctx);
extern "C" void* func_ov023_021f6880(void* list, int value);
extern "C" int func_ov023_021f6f10(void* obj);

// USA: func_ov023_021f6524
extern "C" ARM void* func_ov023_021f6524(void* ctx, int value) {
	void* obj = func_ov023_021f6880(func_ov011_021849c8(ctx), value);
	if (obj == 0) return 0;
	if (func_ov023_021f6f10(obj) != 7) return 0;
	return obj;
}
