#include <globaldefs.h>

#if defined(jpn)
#define func_020ca3b8 func_020cbe84
#endif

typedef void (*Type_ov031_02227898)(int);

extern "C" void func_ov031_0223a794(void);
extern "C" void func_ov031_0223ab18(unsigned char* out0, unsigned char* out1);
extern "C" void* func_ov031_0223ab5c(void);
extern "C" void func_020ca3b8(const void* src, void* dst, unsigned long size);
extern "C" void func_ov031_0223e2c0(int idx, void* obj);
extern "C" unsigned int func_ov031_0223cf70(void** a);
extern "C" char* data_ov031_02290c44;
namespace DuplicatePool {
	extern "C" char* data_ov031_02290c44;
}

static inline void inline_ov031_02227898(int code) {
	Type_ov031_02227898 cb = *(Type_ov031_02227898*)(data_ov031_02290c44 + 0x1e000 + 0x298);
	if (cb == NULL) {
		*(unsigned char*)(data_ov031_02290c44 + 0x1e000 + 0x2a0) = 1;
	} else {
		cb(code);
	}
}

// USA: func_ov031_02227898
extern "C" ARM void func_ov031_02227898(void* task) {
	unsigned char state;
	unsigned char changed;

	func_ov031_0223a794();
	if (*(unsigned char*)(data_ov031_02290c44 + 0x1e000 + 0x2a0) != 0 &&
	    *(unsigned char*)(data_ov031_02290c44 + 0x1e000 + 0x2a1) == 0) {
		Type_ov031_02227898 cb = *(Type_ov031_02227898*)(data_ov031_02290c44 + 0x1e000 + 0x298);
		if (cb != NULL) {
			cb(0);
		}
		return;
	}

	func_ov031_0223ab18(&state, &changed);
	switch (state) {
	case 1:
	case 2:
	case 3:
	case 4:
		break;
	case 5:
		if (changed) {
			char* dst = data_ov031_02290c44 + 0x1e280;
			void* src = func_ov031_0223ab5c();
			func_020ca3b8(src, dst, 0x16);
			inline_ov031_02227898(0);
		}
		break;
	case 13:
		if (changed) {
			inline_ov031_02227898(1);
		}
		break;
	case 20:
	case 23:
		if (changed) {
			inline_ov031_02227898(3);
		}
		break;
	case 26:
	case 29:
		if (changed) {
			inline_ov031_02227898(4);
		}
		break;
	case 12:
		if (changed) {
			inline_ov031_02227898(2);
		}
		break;
	case 34:
		func_ov031_0223e2c0(0, task);
		func_ov031_0223cf70((void**)&DuplicatePool::data_ov031_02290c44);
		break;
	}
}
