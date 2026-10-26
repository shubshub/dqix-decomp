#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

extern char data_ov034_022a2a54[12];

struct Struct_ov034_022a29e4 { void* field0; };

// USA: func_ov034_022a29e4
extern "C" ARM void* func_ov034_022a29e4(struct Struct_ov034_022a29e4* obj) {
	obj->field0 = &data_ov034_022a2a54;
	((BackgroundLoader*)(obj))->InitializeOrReset();
	return obj;
}
