#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_ov031_02218e2c_2 {
	const char* name;
	void* value;
};

struct Struct_ov031_02218e2c {
	unsigned char pad[0x1a38];
	Struct_ov031_02218e2c_2 entries[0x20];
};

// USA: func_ov031_02218e2c
extern "C" ARM void* func_ov031_02218e2c(void* self, const char* key) {
	Struct_ov031_02218e2c* owner = (Struct_ov031_02218e2c*)self;
	for (int i = 0; i < 0x20; i++) {
		if (owner->entries[i].name == NULL) break;
		if (strcmp(key, owner->entries[i].name) == 0) {
			return owner->entries[i].value;
		}
	}
	return NULL;
}
