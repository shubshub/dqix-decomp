#include <globaldefs.h>

struct Struct_ov031_02214854_3 {
	unsigned char state;
	unsigned char id;
	unsigned char level;
	unsigned char unknown_3_0_ : 7;
	unsigned char unknown_3_7_ : 1;
};

struct Struct_ov031_02214854 {
	unsigned char pad[0x36];
	unsigned short unknown_36_;
	unsigned char rest[0x88];
};

struct Struct_ov031_02214854_2 {
	unsigned char pad[0x444];
	Struct_ov031_02214854_3 entries[11];
	Struct_ov031_02214854 records[11];
	unsigned char pad2[0x62];
	unsigned char count;
};

// USA: func_ov031_02214854
extern "C" ARM int func_ov031_02214854(void* obj) {
	Struct_ov031_02214854_2* s = (Struct_ov031_02214854_2*)obj;
	int i;
	unsigned char result = 0;
	for (i = 0; i < s->count; i++) {
		if (s->entries[i].state == 0 && s->records[i].unknown_36_ - 1 != s->entries[i].unknown_3_0_) {
			s->entries[i].unknown_3_7_ = 0;
			result++;
		} else {
			s->entries[i].unknown_3_7_ = 1;
		}
	}
	return result;
}
