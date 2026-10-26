#include <globaldefs.h>


struct Struct_ov031_022386d4_4 {
	unsigned char language;
	unsigned char favoriteColor;
	unsigned char month;
	unsigned char day;
	unsigned short nickName[11];
	unsigned short nickNameLength;
	unsigned short comment[27];
	unsigned short commentLength;
};

struct Struct_ov031_022386d4 {
	unsigned char favoriteColor : 4;
	unsigned char unknown_0_4_ : 4;
	unsigned char nameLength;
	unsigned short name[10];
};

struct Struct_ov031_022386d4_2 {
	unsigned short v[7];
};

struct Struct_ov031_022386d4_3 {
	struct Struct_ov031_022386d4_2 flags;
	char pad0[0x40 - 0xe];
	char buf[0x10000];
	char work[0x1b140 - 0x10040];
	void* unknown_1b140_;
};

extern struct Struct_ov031_022386d4_3* data_ov031_02290d14;

extern "C" void OS_GetOwnerInfo(void* out);
extern "C" void* VectorizedInvertedMemcpy(void* src, void* dst, int n);
extern "C" int func_ov027_021dc680(void* work, struct Struct_ov031_022386d4* arg1, void* arg2, unsigned short tgid, int arg4);
extern "C" void HaltSystem(void);
extern "C" int func_ov027_021dc8d4(int a, int b);
extern "C" void func_ov023_021d8a40(void* cb);
extern "C" void func_ov031_02238de4(void);
extern "C" void func_ov031_02239108(unsigned short v);

// USA: func_ov031_022386d4
extern "C" ARM void func_ov031_022386d4(void* arg0, unsigned short tgid) {
	struct Struct_ov031_022386d4_4 info;
	struct Struct_ov031_022386d4 var1;
	OS_GetOwnerInfo(&info);
	var1.favoriteColor = info.favoriteColor;
	var1.nameLength = info.nickNameLength;
	VectorizedInvertedMemcpy(info.nickName, var1.name, info.nickNameLength * 2);
	var1.unknown_0_4_ = 0;
	struct Struct_ov031_022386d4_2 flags = {0};
	data_ov031_02290d14->flags = flags;
	data_ov031_02290d14->unknown_1b140_ = data_ov031_02290d14->work;
	if (func_ov027_021dc680(data_ov031_02290d14->unknown_1b140_, &var1, arg0, tgid, 2) != 0) {
		HaltSystem();
	}
	func_ov027_021dc8d4(0x100, 1);
	func_ov023_021d8a40((void*)func_ov031_02238de4);
	func_ov031_02239108(1);
}
