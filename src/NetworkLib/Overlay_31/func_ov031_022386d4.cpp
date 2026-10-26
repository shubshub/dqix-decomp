#include <globaldefs.h>


struct Struct_ov031_022386d4_4 {
	unsigned char unknown_0_;
	unsigned char unknown_1_;
	unsigned char unknown_2_;
	unsigned char unknown_3_;
	unsigned short unknown_4_[11];
	unsigned short unknown_1a_;
	unsigned short unknown_1c_[27];
	unsigned short unknown_52_;
};

struct Struct_ov031_022386d4 {
	unsigned char unknown_0_0_ : 4;
	unsigned char unknown_0_4_ : 4;
	unsigned char unknown_1_;
	unsigned short unknown_2_[10];
};

struct Struct_ov031_022386d4_2 {
	unsigned short unknown_0_[7];
};

struct Struct_ov031_022386d4_3 {
	struct Struct_ov031_022386d4_2 unknown_0_;
	char unknown_e_[0x40 - 0xe];
	char unknown_40_[0x10000];
	char unknown_10040_[0x1b140 - 0x10040];
	void* unknown_1b140_;
};

extern struct Struct_ov031_022386d4_3* data_ov031_02290d14;

extern "C" void OS_GetOwnerInfo(void* out);
extern "C" void* VectorizedInvertedMemcpy(void* src, void* dst, int n);
extern "C" int func_ov027_021dc680(void* work, struct UserInfo_022386d4* user, void* ggid, unsigned short tgid, int dma);
extern "C" void HaltSystem(void);
extern "C" int func_ov027_021dc8d4(int a, int b);
extern "C" void func_ov023_021d8a40(void* cb);
extern "C" void func_ov031_02238de4(void);
extern "C" void func_ov031_02239108(unsigned short arg0);

// USA: func_ov031_022386d4
extern "C" ARM void func_ov031_022386d4(void* ggid, unsigned short tgid) {
	struct OwnerInfo_022386d4 info;
	struct UserInfo_022386d4 user;
	OS_GetOwnerInfo(&info);
	user.favoriteColor = info.favoriteColor;
	user.nameLength = info.nickNameLength;
	VectorizedInvertedMemcpy(info.nickName, user.name, info.nickNameLength * 2);
	user.playerNo = 0;
	struct Flags_022386d4 flags = {0};
	data_ov031_02290d14->flags = flags;
	data_ov031_02290d14->workPtr = data_ov031_02290d14->work;
	if (func_ov027_021dc680(data_ov031_02290d14->workPtr, &user, ggid, tgid, 2) != 0) {
		HaltSystem();
	}
	func_ov027_021dc8d4(0x100, 1);
	func_ov023_021d8a40((void*)func_ov031_02238de4);
	func_ov031_02239108(1);
}
