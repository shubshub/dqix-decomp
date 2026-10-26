#include <globaldefs.h>

struct MainStruct020e455c;
extern "C" void func_020e455c(struct MainStruct020e455c* obj);
extern "C" void func_020a1e54(int flag);

// Overlay 4, originally func_ov004_0216fa48 (USA/EUR 0x0216fa48, JPN 0x021701d8)
extern "C" ARM void FieldTask_EndGrottoBossIntro(struct MainStruct020e455c* obj) {
	func_020e455c(obj);
	if (*((unsigned char*)obj + 0xf) != 0) {
		func_020a1e54(1);
		*((unsigned char*)obj + 0xf) = 0;
	}
}
