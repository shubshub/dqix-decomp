#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

#if defined(jpn)
enum { Enum_ov004_0215502c_20 = 19 };
#define data_ov004_0216fa8c data_ov004_0217021c
#else
enum { Enum_ov004_0215502c_20 = 20 };
#endif

struct Struct_ov004_0216fa8c {
	unsigned int words[Enum_ov004_0215502c_20];
};

extern Struct_ov004_0216fa8c data_ov004_0216fa8c;

extern "C" int func_ov011_02184a24(int, void*, int);

// USA: func_ov004_0215502c
extern "C" ARM int func_ov004_0215502c(SafeAllocator* alloc, int arg) {
	Struct_ov004_0216fa8c local = data_ov004_0216fa8c;
	void* buf = alloc->Allocate(sizeof(Struct_ov004_0216fa8c));
	memcpy(buf, &local, sizeof(Struct_ov004_0216fa8c));
	return func_ov011_02184a24(arg, buf, Enum_ov004_0215502c_20);
}
