#include <globaldefs.h>

struct Struct_ov006_02159094 {
	char pad0[0x372];
	unsigned short fieldA[3];
	short fieldB[3];
	char pad1[0x38c - 0x37e];
	unsigned char fieldC[3];
};

extern "C" void func_ov006_02158fd8(Struct_ov006_02159094* obj, int arg1, int b, int c);

// USA: func_ov006_02159094
extern "C" ARM void func_ov006_02159094(Struct_ov006_02159094* obj) {
	for (signed char i = 2; i >= 0; i--) {
		if (obj->fieldB[i] > 0) {
			unsigned char a = (unsigned char)obj->fieldA[i];
			unsigned char c = obj->fieldC[i];
			func_ov006_02158fd8(obj, a, obj->fieldB[i], c);
			obj->fieldA[i] = 0;
			obj->fieldB[i] = -1;
			obj->fieldC[i] = 0;
			return;
		}
	}
}
