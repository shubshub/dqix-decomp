#include <globaldefs.h>

struct Struct_ov031_0224e5e8_6 {
	char pad[8];
	void *field8;
};
extern struct Struct_ov031_0224e5e8_6 data_ov031_0224e5e8;

struct Mutex;
void* LockMutex(Mutex*);

struct Struct_ov031_02290f8c;
void UnlockMutex(Mutex*);

// USA: func_ov031_02216ab4
extern "C" ARM int func_ov031_02216ab4(void) {
	void *base = data_ov031_0224e5e8.field8;
	if (base == 0) return 0x16;
	void *node = (char*)base + 0x1000 + 0x3d8;
	LockMutex((Mutex*)node);
	base = data_ov031_0224e5e8.field8;
	node = (char*)base + 0x1000 + 0x3d8;
	int r4 = *(int*)((char*)base + 0x1000 + 0x4);
	UnlockMutex((Mutex*)node);
	return r4;
}
