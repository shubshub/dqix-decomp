#include <globaldefs.h>

struct S021a7a5c { unsigned char f0; unsigned char f1; };

extern "C" void func_ov017_021a79f0(S021a7a5c*);

// Overlay 17, originally CallHelperAndSetFlag_021a7a5c (USA/EUR 0x021a7a5c, JPN 0x021a83ec)
extern "C" ARM void FieldTask_EndStarflightPrompt(S021a7a5c* obj) {
	func_ov017_021a79f0(obj);
	obj->f1 = 1;
}
