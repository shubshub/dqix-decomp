#include <globaldefs.h>

struct Struct_ov031_0224e22c {
	char pad[0x7c];
	int next;
};

extern "C" void* func_ov031_02207120(void* head, Struct_ov031_0224e22c* item);
extern Struct_ov031_0224e22c data_ov031_0224e22c;

// USA: func_ov031_02207108
extern "C" ARM void* func_ov031_02207108(Struct_ov031_0224e22c* item) {
	return func_ov031_02207120(&data_ov031_0224e22c, item);
}
