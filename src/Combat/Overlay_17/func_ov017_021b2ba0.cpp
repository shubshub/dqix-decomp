#include <globaldefs.h>
#include "std_library_functions.h"


extern "C" void HaltSystem(void);

struct Struct_0206f81c_2 {
	unsigned char pad0[0x24];
	char name[1];
};

// USA: func_ov017_021b2ba0
extern "C" ARM void func_ov017_021b2ba0(Struct_0206f81c_2* obj, char* src) {
	if (strlen(src) >= 0xc) HaltSystem();
	strcpy(obj->name, src);
}
