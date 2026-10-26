#include <globaldefs.h>
#include "std_library_functions.h"


extern "C" void HaltSystem(void);

struct S021b2ba0 {
	unsigned char pad0[0x24];
	char name[1];
};

// USA: func_ov017_021b2ba0
ARM void SetNameChecked_021b2ba0(S021b2ba0* obj, char* src) {
	if (strlen(src) >= 0xc) HaltSystem();
	strcpy(obj->name, src);
}
