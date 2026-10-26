#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_ov024_021f6830 { int pad0; float value; int pad2; };

// USA: func_ov024_021f6830
extern "C" ARM void func_ov024_021f6830(struct Struct_ov024_021f6830* arr, struct Struct_ov024_021f6830* arg1) {
	if (arg1->value < arr[3].value) return;
	int i;
	for (i = 0; i < 4; i++) {
		if (arg1->value > arr[i].value) {
			int k;
			for (k = 2; k >= i; k--) {
				memcpy(&arr[i + 1], &arr[i], 0xc);
			}
			memcpy(&arr[i], arg1, 0xc);
			return;
		}
	}
}
