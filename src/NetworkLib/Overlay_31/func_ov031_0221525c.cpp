#include <globaldefs.h>

extern "C" int func_ov031_022134b0(void);
extern "C" char* func_ov031_022133f8(int);
extern "C" int func_ov031_0220d540(void);
extern "C" int func_ov031_02215358(char*);
extern "C" int func_ov031_022153bc(char*);
extern "C" int func_ov031_0221544c(void);
extern "C" int func_ov031_02215478(char*);
extern "C" int func_ov031_022154e4(void*);
extern "C" int func_ov031_022154f8(void);
extern "C" void func_ov031_02219178(void);
extern "C" void func_ov031_02219080(void);

// USA: func_ov031_0221525c
extern "C" ARM int func_ov031_0221525c(void) {
	int field9 = func_ov031_022134b0();
	char* obj = func_ov031_022133f8(0x10);

	if (func_ov031_0220d540() == 9) {
		unsigned int idx = field9 - 0xa;
		if (idx <= 5) {
			switch (idx) {
			case 0:
				field9 = func_ov031_02215358(obj);
				break;
			case 2:
				field9 = func_ov031_022153bc(obj);
				break;
			case 3:
				field9 = func_ov031_0221544c();
				break;
			case 4:
				field9 = func_ov031_02215478(obj);
				break;
			case 5:
				field9 = func_ov031_022154e4(obj);
				break;
			case 1:
				field9 = func_ov031_022154f8();
				break;
			}
		}
		goto done;
	}

	if (field9 == 0xb) goto handle_b;
	if (field9 == 0xe) goto handle_e;
	if (field9 != 0xf) goto common;
	field9 = func_ov031_022154e4(obj);
	goto done;
handle_b:
	field9 = func_ov031_022154f8();
	goto done;
handle_e:
	func_ov031_02219178();
	func_ov031_02219080();
common:
	{
		unsigned char idx2 = *(unsigned char*)(obj + 0xd13);
		*(unsigned char*)(obj + idx2 * 4 + 0x444) = 2;
	}
	field9 = 0xb;
done:
	return field9;
}
