#include <globaldefs.h>

struct Struct_ov031_0224c980_9 { unsigned short f0; unsigned short f2; };
struct Struct_ov031_022036a8 {
	unsigned char pad0[0x8];
	unsigned char state;
	unsigned char unknown_9_[0x2c - 0x9];
	unsigned short unknown_2c_;
	unsigned short unknown_2e_;
	unsigned char unknown_30_[0x34 - 0x30];
	unsigned int f34;
};

extern Struct_ov031_0224c980_9 data_ov031_0224c980;

extern "C" void func_ov031_02201550(unsigned char* buf, unsigned int len, Struct_ov031_022036a8* arg2, int flags, int opt);
void CycleCurrentPriorityContexts();

// USA: func_ov031_022036a8
extern "C" ARM int func_ov031_022036a8(unsigned char* buf, unsigned int len, Struct_ov031_022036a8* arg2, int flag) {
	unsigned int n;
	unsigned int win;
	unsigned int prev = arg2->f34;
	int cnt;
	if (flag != 0) {
		win = 1;
	} else {
		win = arg2->unknown_2c_;
	}
	cnt = prev * 2 + 4;
	while (len != 0 && arg2->state == 4) {
		unsigned int cur;
		n = arg2->unknown_2e_;
		if (n >= win) n = win;
		if (data_ov031_0224c980.f2 < n) n = data_ov031_0224c980.f2;
		if (flag == 0) n &= ~1;
		if (len < n) n = len;
		cur = arg2->f34;
		cnt += cur - prev;
		prev = cur;
		if (cnt-- == 0) n = 0;
		if (n == 0) break;
		win -= n;
		func_ov031_02201550(buf, n, arg2, 0x18, 0);
		CycleCurrentPriorityContexts();
		buf += n;
		len -= n;
	}
	return n;
}
