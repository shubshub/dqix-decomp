#include <globaldefs.h>

struct Struct_ov031_0224e5e8_13 {
	char pad[8];
	void *field8;
};
extern struct Struct_ov031_0224e5e8_13 data_ov031_0224e5e8;

struct Mutex;
void* LockMutex(Mutex*);

struct Struct_ov031_02290f8c;
void UnlockMutex(Mutex*);

// USA: func_ov031_02217598
extern "C" ARM void func_ov031_02217598(int val) {
	void *base = data_ov031_0224e5e8.field8;
	void *node = (char*)base + 0x1000 + 0x3d8;
	LockMutex((Mutex*)node);
	base = data_ov031_0224e5e8.field8;
	*(int*)((char*)base + 0x1000 + 0x4) = val;
	base = data_ov031_0224e5e8.field8;
	node = (char*)base + 0x1000 + 0x3d8;
	UnlockMutex((Mutex*)node);
}
