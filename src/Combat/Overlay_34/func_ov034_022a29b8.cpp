#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

extern char data_ov034_022a2a54[12];
extern char data_ov034_022a2a48[12];

struct Struct_ov034_022a29b8 { void* field0; };

// USA: func_ov034_022a29b8
extern "C" ARM void* func_ov034_022a29b8(struct Struct_ov034_022a29b8* obj) {
	obj->field0 = &data_ov034_022a2a54;
	((BackgroundLoader*)(obj))->InitializeOrReset();
	obj->field0 = &data_ov034_022a2a48;
	return obj;
}
