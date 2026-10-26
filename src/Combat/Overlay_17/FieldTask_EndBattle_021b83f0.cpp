#include <globaldefs.h>

struct S021b83f0 { unsigned char f0; unsigned char f1; };

extern "C" void func_ov017_021b6f9c(S021b83f0*);

// Overlay 17, originally CallHelperAndSetFlag_021b83f0 (USA/EUR 0x021b83f0, JPN 0x021b8900)
extern "C" ARM void FieldTask_EndBattle(S021b83f0* obj) {
	func_ov017_021b6f9c(obj);
	obj->f1 = 1;
}
