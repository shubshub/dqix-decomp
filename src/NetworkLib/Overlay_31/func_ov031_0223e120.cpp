#include <globaldefs.h>

struct Struct_ov031_0223d884 { int a, b, c, d; };
struct Struct_ov031_0223bf2c { int a, b, c, d; };
extern "C" void func_ov031_0223d884(Struct_ov031_0223d884);
extern "C" void func_ov031_0223bf2c(Struct_ov031_0223bf2c);
typedef void (*Type_ov031_0223e120)(int);

struct Struct_ov031_0223e120 {
	int slots;
	int entries;
	int node;
	unsigned char pad[0x34];
};

extern "C" void func_ov031_0223cf70(void** slot);
extern "C" Struct_ov031_0223e120* data_ov031_02290d9c;
namespace DuplicatePool {
    extern "C" Struct_ov031_0223e120* data_ov031_02290d9c;
}

// USA: func_ov031_0223e120
extern "C" ARM void func_ov031_0223e120(void) {
	for (int i = 0; i < 2; i++) {
		((Type_ov031_0223e120)func_ov031_0223d884)(data_ov031_02290d9c[i].node);
		((Type_ov031_0223e120)func_ov031_0223bf2c)(data_ov031_02290d9c[i].slots);
	}
	func_ov031_0223cf70((void**)&DuplicatePool::data_ov031_02290d9c);
}
