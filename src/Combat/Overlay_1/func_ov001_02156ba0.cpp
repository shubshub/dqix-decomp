#include <globaldefs.h>

struct Struct_ov001_02156ba0_2 {
	unsigned int a;
	unsigned int b;
	unsigned int unknown_8_[4][3];
};

struct Struct_ov001_02156ba0 {
	struct Struct_ov001_02156ba0_2 entries[16];
	unsigned int unknown_380_;
	unsigned int w1;
	unsigned int w2;
	unsigned int pad[3];
	unsigned int unknown_398_;
};

// USA: func_ov001_02156ba0
extern "C" ARM void func_ov001_02156ba0(struct Struct_ov001_02156ba0* buf) {
	int i, j;
	for (i = 0; i < 16; i++) {
		buf->entries[i].a = 0;
		buf->entries[i].b = 0;
		for (j = 0; j < 3; j++) {
			buf->entries[i].unknown_8_[0][j] = 0;
			buf->entries[i].unknown_8_[1][j] = 0;
			buf->entries[i].unknown_8_[2][j] = 0;
			buf->entries[i].unknown_8_[3][j] = 0;
		}
	}
	buf->unknown_380_ = 0;
	buf->w1 = 0;
	buf->w2 = 0;
	buf->unknown_398_ = 0;
}
