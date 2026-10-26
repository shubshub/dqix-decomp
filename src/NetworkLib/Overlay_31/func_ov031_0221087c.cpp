#include <globaldefs.h>

struct Struct_ov031_0221087c {
	int field0;
	int field4;
	char pad8[0x40 - 8];
	volatile int field40;
};

extern void* volatile data_ov031_0224e588;

extern "C" void func_ov031_022103dc(void* value);
extern "C" void func_ov031_022103f8(void* value);
extern "C" int func_ov031_02212598(void);
extern "C" int func_ov031_022125bc(void);
extern "C" int func_ov031_02212524(char* str, void* b);
void SleepCurrentContext(unsigned int ms);

// USA: func_ov031_0221087c
extern "C" ARM void func_ov031_0221087c(void) {
	{
		Struct_ov031_0221087c* obj = (Struct_ov031_0221087c*)data_ov031_0224e588;
		if (obj->field4 == 1 && obj->field40 == 3) {
			func_ov031_022103dc((void*)4);
			return;
		}
	}

	{
		Struct_ov031_0221087c* obj = (Struct_ov031_0221087c*)data_ov031_0224e588;
		if (!func_ov031_02212524((char*)obj + 0x38, (char*)obj + 0x44)) return;
	}

	Struct_ov031_0221087c* obj;
	while ((obj = (Struct_ov031_0221087c*)data_ov031_0224e588)->field40 != 3 && obj->field40 != 5 && obj->field40 != 4) {
		int state = func_ov031_02212598();
		obj = (Struct_ov031_0221087c*)data_ov031_0224e588;
		obj->field40 = state;
		obj = (Struct_ov031_0221087c*)data_ov031_0224e588;
		switch (obj->field40) {
		case 1:
		case 2:
			SleepCurrentContext(0x64);
			obj = (Struct_ov031_0221087c*)data_ov031_0224e588;
			if (obj->field4 == 2) {
				func_ov031_022125bc();
			}
			break;
		case 0:
		case 3:
		case 4:
		case 5:
			if (obj->field40 == 3 && obj->field4 == 1) {
				func_ov031_022103dc((void*)4);
			} else {
				func_ov031_022103f8((void*)1);
				obj = (Struct_ov031_0221087c*)data_ov031_0224e588;
				obj->field40;
			}
			break;
		}
	}
}
