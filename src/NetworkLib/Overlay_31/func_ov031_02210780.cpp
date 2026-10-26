#include <globaldefs.h>

struct Struct_ov031_02210780 {
	int field0;
	int field4;
	char pad8[0x34 - 8];
	volatile int field34;
};

extern void* volatile data_ov031_0224e588;

extern "C" void func_ov031_022103dc(void* value);
extern "C" void func_ov031_022103f8(void* value);
extern "C" int func_ov031_022125c8(void);
extern "C" int func_ov031_0221268c(void);
extern "C" int func_ov031_02212784(void);
void SleepCurrentContext(unsigned int ms);

// USA: func_ov031_02210780
extern "C" ARM void func_ov031_02210780(void) {
	{
		Struct_ov031_02210780* obj = (Struct_ov031_02210780*)data_ov031_0224e588;
		if (obj->field4 == 1 && obj->field34 == 3) {
			func_ov031_022103dc((void*)3);
			return;
		}
	}

	if (!func_ov031_022125c8()) return;

	Struct_ov031_02210780* obj;
	while ((obj = (Struct_ov031_02210780*)data_ov031_0224e588)->field34 != 3 && obj->field34 != 5 && obj->field34 != 4) {
		int state = func_ov031_0221268c();
		obj = (Struct_ov031_02210780*)data_ov031_0224e588;
		obj->field34 = state;
		obj = (Struct_ov031_02210780*)data_ov031_0224e588;
		switch (obj->field34) {
		case 1:
		case 2:
			SleepCurrentContext(0x64);
			obj = (Struct_ov031_02210780*)data_ov031_0224e588;
			if (obj->field4 == 2) {
				func_ov031_02212784();
			}
			break;
		case 0:
		case 3:
		case 4:
		case 5:
			if (obj->field34 == 3 && obj->field4 == 1) {
				func_ov031_022103dc((void*)3);
			} else {
				func_ov031_022103f8((void*)1);
				obj = (Struct_ov031_02210780*)data_ov031_0224e588;
				obj->field34;
			}
			break;
		}
	}
}
