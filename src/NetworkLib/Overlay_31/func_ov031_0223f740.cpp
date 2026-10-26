#include <globaldefs.h>

struct Struct_ov031_0223ea84;
extern "C" int func_ov031_022412e8(Struct_ov031_0223ea84*, int*);

struct Struct_ov031_0223ea84_2 {
	char pad[0x14];
	int field14;
};

// USA: func_ov031_0223f740
extern "C" ARM int func_ov031_0223f740(Struct_ov031_0223ea84* self, Struct_ov031_0223ea84_2* other) {
	int local;
	int result = func_ov031_022412e8(self, &local);
	return result == other->field14;
}
