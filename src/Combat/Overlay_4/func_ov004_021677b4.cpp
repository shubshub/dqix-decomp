#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

extern "C" void func_ov011_02184a24(void* a, void* b, int c);

#if defined(jpn)
enum { Enum_ov004_021677b4_19 = 18 };
#define data_ov004_0216ffac data_ov004_02170708
#else
enum { Enum_ov004_021677b4_19 = 19 };
#endif

struct Struct_ov004_0216ffac { unsigned int w[Enum_ov004_021677b4_19]; };
extern struct Struct_ov004_0216ffac data_ov004_0216ffac;

// USA: func_ov004_021677b4
extern "C" ARM void func_ov004_021677b4(SafeAllocator* self, void* target) {
	struct Struct_ov004_0216ffac buf = data_ov004_0216ffac;
	void* allocated = self->Allocate(sizeof(Struct_ov004_0216ffac));
	memcpy(allocated, &buf, sizeof(Struct_ov004_0216ffac));
	func_ov011_02184a24(target, allocated, Enum_ov004_021677b4_19);
}
