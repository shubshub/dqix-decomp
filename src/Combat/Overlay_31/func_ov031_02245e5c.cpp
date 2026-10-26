#include <globaldefs.h>

struct BlockedContextList;
void UnblockContexts(struct BlockedContextList* list);
extern "C" void func_020c7e0c(void* data, int a, int b);
extern "C" void func_020c7f44(void* data, int a, int b);
extern "C" int func_020c7fe0(void* obj, unsigned int* out, int arg2);

struct Struct_ov031_0224c954 { short unknown_0_; short unknown_2_; };
struct Struct_ov031_02245e5c { short type; short value; };
struct Struct_ov031_02291f24_3 { char pad0[8]; int field8; char unknown_c_[4]; int field10; char unknown_14_[4]; int field18; };

extern struct Struct_ov031_0224c954 data_ov031_0224c954;
extern struct Struct_ov031_02291f24_3 data_ov031_02291f24;
extern struct BlockedContextList data_ov031_02291f3c;
extern int data_ov031_02291f60;

// USA: func_ov031_02245e5c
extern "C" ARM void func_ov031_02245e5c(struct Struct_ov031_02245e5c* msg) {
	if (data_ov031_0224c954.unknown_2_ != msg->type || data_ov031_0224c954.unknown_0_ != msg->value) {
		data_ov031_0224c954.unknown_2_ = msg->type;
		data_ov031_0224c954.unknown_0_ = msg->value;
	}
	switch (msg->type) {
	case 1:
		data_ov031_02291f24.field10 = 0;
	case 2:
	case 3:
	case 4:
	case 5:
	case 9:
		data_ov031_02291f24.field8 = msg->value;
		UnblockContexts(&data_ov031_02291f3c);
		return;
	case 6:
		if (data_ov031_02291f24.field18 != 0) {
			data_ov031_02291f24.field8 = msg->value;
			UnblockContexts(&data_ov031_02291f3c);
			return;
		}
		if (msg->value == 0) {
			func_020c7e0c(&data_ov031_02291f60, 2, 0);
		} else {
			func_020c7f44(&data_ov031_02291f60, 3, 0);
		}
		return;
	case 7:
		if (msg->value == 0) {
			unsigned int tmp;
			if (func_020c7fe0(&data_ov031_02291f60, &tmp, 0) != 0) return;
			func_020c7e0c(&data_ov031_02291f60, 1, 0);
		} else {
			func_020c7f44(&data_ov031_02291f60, 3, 0);
		}
		return;
	case 8:
		data_ov031_02291f24.field10++;
		return;
	}
}
