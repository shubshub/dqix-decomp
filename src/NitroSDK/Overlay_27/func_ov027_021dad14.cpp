#include <globaldefs.h>

#if defined(jpn)
#define func_020ca3b8 func_020cbe84
#endif

extern "C" void func_020ca3b8(int a, void* p, int size);

struct Struct_ov027_021d8c94 {
	unsigned char pad0[0x358];
	unsigned char unknown_358_;
	unsigned char pad1;
	unsigned short unknown_35a_;
	unsigned short unknown_35c_;
	unsigned char unknown_35e_[0x156];
	unsigned char unknown_4b4_;
};

// USA: func_ov027_021dad14
extern "C" ARM void func_ov027_021dad14(Struct_ov027_021d8c94* s, int a, unsigned int flags, int c) {
	unsigned char cnt = 1;
	func_020ca3b8(a, &s->unknown_35e_, 0x14a);
	int i = 0;
	do {
		if (flags & (2 << i)) cnt = (cnt + 1) & 0xff;
		i++;
	} while (i < 15);
	s->unknown_358_ = cnt;
	s->unknown_35a_ = flags | 1;
	s->unknown_35c_ = c;
	s->unknown_4b4_ = s->unknown_4b4_ + 1;
}
