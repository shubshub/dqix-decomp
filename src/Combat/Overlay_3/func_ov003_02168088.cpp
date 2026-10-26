#include <globaldefs.h>

struct Struct_02080fa8_2 { int value; };
struct Struct_0207f524 { struct Struct_02080fa8_2* entries; short count; };
struct Struct_02080fa8 { char pad[4]; struct Struct_0207f524 list; };
extern "C" void func_02080fa8(struct Struct_02080fa8* obj, int id, int value);

struct Struct_ov003_02167b34_2 { char pad[0x10]; struct Struct_02080fa8* c; };

// USA: func_ov003_02168088
extern "C" ARM void func_ov003_02168088(struct Struct_ov003_02167b34_2* obj, int* arr) {
	struct Struct_02080fa8* c;
	short id;
	unsigned char i;
	if (!arr) return;
	c = obj->c;
	id = 0x13;
	for (i = 0; i < 0xc; i++) {
		func_02080fa8(c, id, arr[i]);
		id++;
	}
}
