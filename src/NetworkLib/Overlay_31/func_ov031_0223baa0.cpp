#include <globaldefs.h>

struct Struct_ov031_02223268_2 { int a, b; };
struct Struct_ov031_022269d8 { int pad0, pad1; Struct_ov031_02223268_2* arr; };

// USA: func_ov031_0223baa0
extern "C" ARM Struct_ov031_02223268_2* func_ov031_0223baa0(Struct_ov031_022269d8* obj, int idx) {
	return &obj->arr[idx];
}
