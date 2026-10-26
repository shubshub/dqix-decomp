#include <globaldefs.h>


extern int GetField40_02239be8(void);
extern "C" int func_ov031_02239bfc(void);
extern "C" int func_ov031_02239e68(void);
extern int CheckFirstOrRunTen_0223a358(void);
extern "C" int HaltSystem(void);

struct Struct0223ab6c {
	unsigned char pad0[0x64a];
	unsigned short field64a;
	unsigned char pad1[0x444];
	unsigned char fieldA90;
	unsigned char pad2[7];
	int fieldA98;
};
extern struct Struct0223ab6c* data_ov031_02290d20;

// USA: func_ov031_0223ab6c  (semantic: HandleField40Event_0223ab6c)
extern "C" ARM void func_ov031_0223ab6c(void) {
	switch (GetField40_02239be8()) {
	case 1:
		func_ov031_02239bfc();
		break;
	case 7: {
		int v = func_ov031_02239e68();
		data_ov031_02290d20->field64a = (unsigned short)v;
		data_ov031_02290d20->fieldA98 = 0;
		data_ov031_02290d20->fieldA90 = 3;
		break;
	}
	case 0:
		data_ov031_02290d20->fieldA98 = 0;
		data_ov031_02290d20->fieldA90 = 3;
		break;
	case 9:
		CheckFirstOrRunTen_0223a358();
		break;
	case 3:
		break;
	default:
		HaltSystem();
		break;
	}
}
