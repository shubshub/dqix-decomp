#include <globaldefs.h>

struct Struct_ov031_0224e230 {
	char pad[0x7c];
	int next;
};

extern "C" void* func_ov031_02207120(void* head, Struct_ov031_0224e230* item);
extern Struct_ov031_0224e230 data_ov031_0224e230;

// USA: func_ov031_02207168
extern "C" ARM void* func_ov031_02207168(Struct_ov031_0224e230* item) {
	return func_ov031_02207120(&data_ov031_0224e230, item);
}
