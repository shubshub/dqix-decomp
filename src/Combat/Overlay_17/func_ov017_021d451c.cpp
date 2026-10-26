#include <globaldefs.h>

struct Struct_ov017_021c8f3c_2 {
	unsigned short a;
	unsigned short b;
	unsigned short c;
	unsigned short d;
	unsigned char e;
	unsigned char f;
	unsigned short g;
	unsigned short h;
};
extern "C" void func_ov017_021c90b4(Struct_ov017_021c8f3c_2* dst, Struct_ov017_021c8f3c_2* src);

struct Struct_ov017_021d451c {
	unsigned char flags;
	unsigned char pad1;
	unsigned short id;
	Struct_ov017_021c8f3c_2 data;
	unsigned char pad2[0x1e - 0x12];
};

extern "C" void func_ov017_021d46a4(Struct_ov017_021d451c* arr, Struct_ov017_021d451c* slot);

// USA: func_ov017_021d451c
extern "C" ARM void func_ov017_021d451c(Struct_ov017_021d451c* arr, Struct_ov017_021c8f3c_2* rec) {
	Struct_ov017_021d451c* found = NULL;
	Struct_ov017_021d451c* var1 = NULL;
	int i;
	for (i = 0; i < 0x30; i++) {
		if (rec->a == arr[i].id) {
			found = &arr[i];
			break;
		}
		if (var1 == NULL && arr[i].flags == 0) {
			var1 = &arr[i];
		}
	}
	if (found != NULL) {
		func_ov017_021c90b4(&found->data, rec);
		found->id = rec->a;
		found->flags |= 0x1;
		func_ov017_021d46a4(arr, found);
		return;
	}
	if (var1 == NULL) {
		return;
	}
	func_ov017_021c90b4(&var1->data, rec);
	var1->id = rec->a;
	var1->flags |= 0x1;
	func_ov017_021d46a4(arr, var1);
}
