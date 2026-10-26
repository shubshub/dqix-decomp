#include <globaldefs.h>

struct S021a9314 { unsigned char f0; unsigned char f1; };

extern "C" void func_ov017_021a92a0(S021a9314*);

// Overlay 17, originally CallHelperAndSetFlag_021a9314 (USA/EUR 0x021a9314, JPN 0x021a9af8)
extern "C" ARM void FieldTask_EndChooseStarflightStop(S021a9314* obj) {
	func_ov017_021a92a0(obj);
	obj->f1 = 1;
}
