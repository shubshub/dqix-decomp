#include <globaldefs.h>

struct Struct_ov031_0223b710_2 { int a, b, c, d; };
extern "C" void func_ov031_0223cf70(Struct_ov031_0223b710_2* args);
extern "C" void func_ov031_0223bf48(void* obj, int val);

struct Struct_ov031_0223b710 { unsigned char pad[0x84]; void* unknown_84_; };
extern Struct_ov031_0223b710* data_ov031_02290d24;

// USA: func_ov031_0223b710
extern "C" ARM void func_ov031_0223b710(Struct_ov031_0223b710_2 args) {
	func_ov031_0223cf70(&args);
	func_ov031_0223bf48(data_ov031_02290d24->unknown_84_, args.a);
}
