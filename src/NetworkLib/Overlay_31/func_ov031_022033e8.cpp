#include <globaldefs.h>
#include "NitroSDK/ProcessorContext.h"

extern "C" void func_ov031_0220a9b0(void*);
struct Struct_ov031_02203398;
extern "C" ARM void func_ov031_02203398(Struct_ov031_02203398* obj);

// USA: func_ov031_022033e8
extern "C" ARM void func_ov031_022033e8(void) {
	void* mgr = *(void**)((char*)data_02111304.activeContext + 0xa4);
	if (mgr == NULL) return;
	if (*((unsigned char*)mgr + 9) != 0) {
		func_ov031_0220a9b0(mgr);
	}
	func_ov031_02203398((Struct_ov031_02203398*)mgr);
}
