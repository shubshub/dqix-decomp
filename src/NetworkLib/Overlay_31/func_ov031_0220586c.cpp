#include <globaldefs.h>


struct Mutex;
void* LockMutex(Mutex*);
extern "C" void func_ov031_022031bc(int a, unsigned short b, unsigned int c);
extern "C" int func_ov031_02203358(void);
struct Struct_ov031_02290f8c;
void UnlockMutex(Mutex*);

struct Struct_ov031_0220586c {
	char pad0[0x64];
	void* inner;
	char pad1[0x70 - 0x64 - 4];
	volatile short unknown_70_;
};

struct Struct_ov031_0220586c_2 {
	char pad0[4];
	Struct_ov031_0220586c* ctx;
	char pad1[0xc - 0x4 - 4];
	signed char fieldC;
	char pad2[0x10 - 0xc - 1];
	unsigned short field10;
	unsigned short field12;
	unsigned int field14;
};

// USA: func_ov031_0220586c
extern "C" ARM int func_ov031_0220586c(Struct_ov031_0220586c_2* self) {
	Struct_ov031_0220586c* ctx = self->ctx;
	char* inner = (char*)ctx->inner;
	int flag = 0;
	LockMutex((Mutex*)(inner + 0xe0));
	func_ov031_022031bc(self->field10, self->field12, self->field14);
	*(int*)(inner + 0xf8) = 0;
	signed char b = self->fieldC;
	if (b == 0 || b == 4) {
		flag = func_ov031_02203358();
	}
	UnlockMutex((Mutex*)(inner + 0xe0));
	if (flag != 0) {
		ctx->unknown_70_ |= 0x40;
		return -0x4c;
	}
	ctx->unknown_70_ |= 4;
	return 0;
}
