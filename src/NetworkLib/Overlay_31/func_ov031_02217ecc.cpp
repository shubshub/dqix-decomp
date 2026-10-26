#include <globaldefs.h>

extern "C" void func_020c9b10(void *p);
extern "C" void func_ov031_02209e28(void *p, int n);
struct Mutex;
void* LockMutex(Mutex*);
void SleepCurrentContext(unsigned int arg);

struct Struct_ov031_02290f8c;
void UnlockMutex(Mutex*);

// USA: func_ov031_02217ecc
extern "C" ARM int func_ov031_02217ecc(char *self) {
	if (*(int*)(self + 0x1000 + 0x130) == 1) {
		func_020c9b10(self + 0x1800 + 0x1d4);
		func_ov031_02209e28(self + 0x1800 + 0x1d4, 0x20);
	}
	LockMutex((Mutex*)(self + 0x1800 + 0x3f8));
	int w = *(int*)(self + 0x1000 + 0xc10);
	if (w == 1) {
		UnlockMutex((Mutex*)(self + 0x1800 + 0x3f8));
		return 0;
	}
	UnlockMutex((Mutex*)(self + 0x1800 + 0x3f8));
	SleepCurrentContext(0xa);
	return 1;
}
