#include <globaldefs.h>

struct Struct_ov031_02205194;
extern "C" int func_ov031_02205194(Struct_ov031_02205194* obj);
extern "C" int func_ov031_022051a8(int v, void* extra);

// USA: func_ov031_022051f4
extern "C" ARM int func_ov031_022051f4(Struct_ov031_02205194* obj, void* extra) {
	int v = func_ov031_02205194(obj);
	return func_ov031_022051a8(v, extra);
}
