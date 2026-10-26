#include <globaldefs.h>
#include "std_library_functions.h"

extern int data_ov014_02189800;

struct Struct_ov014_021844c4;
extern "C" ARM int func_ov014_02188bd0(struct Struct_ov014_021844c4* s);
struct Struct_ov014_021845d4 {
	int a;
	short b;
	unsigned short c;
};
extern "C" ARM void func_ov014_021845d4(struct Struct_ov014_021845d4* s);
extern "C" ARM void func_02096fb0(void* p);

struct Struct_ov014_021844c4_2 {
	unsigned char bit0 : 1;
	unsigned char unknown_0_1_ : 1;
	unsigned char bit2 : 1;
	unsigned char unknown_0_3_ : 1;
	unsigned char upper : 4;
};

struct Struct_ov014_021844c4_3 {
	int f0;
	int f4;
	int f8;
	char unknown_c_[0x10];
	char unknown_1c_[0x1e];
	char unknown_3a_[2];
	int f3c;
	int f40;
	int unknown_44_;
	int unknown_48_;
	int unknown_4c_;
	int unknown_50_;
	int unknown_54_;
	int unknown_58_;
	int unknown_5c_;
	int f60;
	int f64;
	int f68;
	int f6c;
	int unknown_70_;
	int unknown_74_;
	int unknown_78_;
	unsigned char f7c;
	unsigned char unknown_7d_;
	unsigned char unknown_7e_;
	unsigned char unknown_7f_;
	unsigned char unknown_80_;
	unsigned char unknown_81_;
	struct Struct_ov014_021844c4_2 unknown_82_;
	char unknown_83_[3];
	short unknown_86_[5];
	char unknown_90_[8];
	int unknown_98_;
	struct Struct_ov014_021845d4 f9c;
};

// USA: func_ov014_021844c4
extern "C" ARM void func_ov014_021844c4(struct Struct_ov014_021844c4_3* obj) {
	*(int*)((char*)&data_ov014_02189800 + 0xc) = 0;
	obj->f0 = 0;
	obj->f4 = 0;
	obj->f8 = 0;
	func_02096fb0(obj->unknown_c_);
	func_ov014_02188bd0((struct Struct_ov014_021844c4*)obj->unknown_1c_);
	obj->f3c = 0;
	obj->f40 = 0;
	obj->unknown_44_ = 0;
	obj->unknown_48_ = 0;
	obj->unknown_4c_ = 0;
	obj->unknown_50_ = 0;
	obj->unknown_54_ = 0;
	obj->unknown_58_ = 0;
	obj->unknown_5c_ = 0;
	obj->f60 = 0;
	obj->f64 = 0;
	obj->f68 = 0;
	obj->f6c = -1;
	obj->unknown_70_ = -1;
	obj->unknown_78_ = -1;
	obj->unknown_74_ = 0;
	obj->f7c = 0;
	obj->unknown_7d_ = 0;
	obj->unknown_7e_ = 0;
	obj->unknown_7f_ = 0;
	obj->unknown_80_ = 0;
	obj->unknown_81_ = 0;
	obj->unknown_82_.bit0 = 0;
	obj->unknown_82_.unknown_0_1_ = 0;
	obj->unknown_82_.bit2 = 0;
	obj->unknown_82_.upper = 0;
	obj->unknown_82_.unknown_0_3_ = 0;
	for (int i = 0; i < 5; i++) {
		obj->unknown_86_[i] = -1;
	}
	obj->unknown_98_ = 0;
	func_ov014_021845d4(&obj->f9c);
	memset((char*)obj + 0x90, 0, 3);
	((unsigned char*)obj)[0x93] = 0;
	((unsigned char*)obj)[0x94] = 0;
}
