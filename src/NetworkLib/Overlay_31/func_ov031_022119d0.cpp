#include <globaldefs.h>

struct Struct_ov031_0224e5a4_2 {
	int field0;
	int field4;
};
extern Struct_ov031_0224e5a4_2 data_ov031_0224e5a4;

// USA: func_ov031_022119d0
extern "C" ARM int func_ov031_022119d0(int *out, int *arg1) {
	if (out != 0) {
		*out = data_ov031_0224e5a4.field4;
	}
	if (arg1 != 0) {
		switch (data_ov031_0224e5a4.field0) {
			case 2:
			case 3:
			case 4:
			case 5:
			case 8:
				*arg1 = 6;
				break;
			case 6:
				*arg1 = 3;
				break;
			case 7:
				*arg1 = 4;
				break;
			case 10:
			case 11:
			case 12:
			case 13:
				*arg1 = 1;
				break;
			case 1:
			case 9:
				*arg1 = 7;
				break;
			case 14:
				*arg1 = 5;
				break;
			case 15:
			case 17:
			case 19:
				*arg1 = 6;
				break;
			case 16:
			case 18:
			case 20:
			case 21:
				*arg1 = 2;
				break;
			default:
				*arg1 = 0;
				break;
		}
	}
	return data_ov031_0224e5a4.field0;
}
