#include <globaldefs.h>

struct Struct_0203d028_15;
extern "C" void func_02040774(struct Struct_0203d028_15* obj, int a, int b, int c);

struct Struct_ov001_0216427c { int type; char pad[8]; void* unknown_c_; };
struct Struct_ov001_0216427c_2 { char unk0[0x44]; int field44; int field48; int field4c; };

// USA: func_ov001_0216427c
extern "C" ARM int func_ov001_0216427c(Struct_ov001_0216427c* table, int index, int arg2, int arg3, int arg4) {
	Struct_ov001_0216427c* entry;
	void* member;
	if (index < 0 || index >= 0x20) return 0;
	entry = &table[index];
	switch (entry->type) {
	case 0:
	case 1:
	case 4:
	case 5:
		member = entry->unknown_c_;
		if (member == 0) return 0;
		((Struct_ov001_0216427c_2*)member)->field44 = arg2;
		((Struct_ov001_0216427c_2*)member)->field48 = arg3;
		((Struct_ov001_0216427c_2*)member)->field4c = arg4;
		return 1;
	case 2:
	case 6:
		member = entry->unknown_c_;
		if (member == 0) return 0;
		func_02040774((struct Struct_0203d028_15*)member, arg2, arg3, arg4);
		return 1;
	default:
		return 0;
	}
}
