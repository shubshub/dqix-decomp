#include <globaldefs.h>

extern "C" void func_ov017_021ce29c(void);
extern "C" void func_ov017_021b0a7c(void* obj);

// USA: func_ov017_021b0224
extern "C" ARM int func_ov017_021b0224(unsigned char* obj) {
	int ok = 1;
	int i;
	for (i = 1; i < 4; i++) {
		if ((obj + i)[0x1b] == 1) {
			if (!(obj[0x1f] & (1 << i))) {
				ok = 0;
				break;
			}
		}
	}
	if (!ok) return obj[0xa];
	func_ov017_021ce29c();
	func_ov017_021b0a7c(obj);
	return 4;
}
