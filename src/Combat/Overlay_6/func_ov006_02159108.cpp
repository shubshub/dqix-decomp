#if defined(jpn)
#define R(j,u) (j)
#define func_ov006_0215f3d8 func_ov006_021607f8
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct Struct_ov006_02159108 {
	unsigned char pad0[R(0x40, 0x48)];
	short** unknown_48_;
	unsigned char** unknown_4c_;
	unsigned short* unknown_50_;
	unsigned char pad1[0x372 - R(0x4c, 0x54)];
	unsigned short fieldA[3];
	short fieldB[3];
	unsigned char pad2[0x38c - 0x37e];
	unsigned char fieldC[3];
};

// USA: func_ov006_02159108
extern "C" ARM void func_ov006_02159108(struct Struct_ov006_02159108* obj, int idx1, int val2, int val3) {
	short* arrA = obj->unknown_48_[idx1];
	unsigned char* arrB = obj->unknown_4c_[idx1];
	unsigned short count = obj->unknown_50_[idx1];
	unsigned short i;
	unsigned char j;
	for (i = 0; i < count; i++) {
		if (val2 == arrA[i]) {
			arrB[i] -= val3;
		}
	}
	for (j = 0; j < 3; j++) {
		if (obj->fieldB[j] <= 0) {
			obj->fieldA[j] = idx1;
			obj->fieldB[j] = val2;
			obj->fieldC[j] = val3;
			return;
		}
	}
}
