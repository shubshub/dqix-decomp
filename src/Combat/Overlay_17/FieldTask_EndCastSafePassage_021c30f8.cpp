#include <globaldefs.h>

struct Obj1_021c30f8 { unsigned char b0; unsigned char b1; };
extern "C" void func_ov017_021c310c(Obj1_021c30f8* obj);

// Overlay 17, originally SetFlag1ThenDestroy_021c30f8 (USA/EUR 0x021c30f8, JPN 0x021c35f4)
extern "C" ARM void FieldTask_EndCastSafePassage(Obj1_021c30f8* obj) {
	obj->b1 = 1;
	func_ov017_021c310c(obj);
}
