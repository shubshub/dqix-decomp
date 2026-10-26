#include <globaldefs.h>
#include "NitroSDK/Memory.h"

extern "C" int func_ov031_022077cc(int a, unsigned int* out);
struct Mutex;
void* LockMutex(Mutex*);
struct Struct_ov031_02290f8c;
void UnlockMutex(Mutex*);

struct Struct_ov031_02210f78 {
	char pad[0xa];
	short fieldA;
	void** fieldC;
};
extern "C" Struct_ov031_02210f78* func_ov031_02207440(int a);

extern void* data_ov031_0224e588;

// USA: func_ov031_02210f78
extern "C" ARM int func_ov031_02210f78(int a, int code, void* buf) {
	unsigned char* b = (unsigned char*)buf;
	b[0] = 8;
	b[1] = 2;
	*(short*)(b + 2) = (short)(((code >> 8) & 0xff) | ((code << 8) & 0xff00));
	if (func_ov031_022077cc(a, (unsigned int*)(b + 4)) == 0) {
		LockMutex((Mutex*)((char*)data_ov031_0224e588 + 0x1bc));
		Struct_ov031_02210f78* s = func_ov031_02207440(a);
		if (s != NULL) {
			VectorizedInvertedMemcpy(*s->fieldC, b + 4, s->fieldA);
		}
		UnlockMutex((Mutex*)((char*)data_ov031_0224e588 + 0x1bc));
		if (s == NULL) {
			return 0;
		}
	}
	return 1;
}
