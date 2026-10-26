#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_021580a0_512 = 0x118 };
#else
enum { Enum_ov003_021580a0_512 = 0x200 };
#endif
#include "std_library_functions.h"

struct Struct_020a1180;
extern "C" void func_020a1380(struct Struct_020a1180* rec);

struct Struct_ov003_021575dc {
	char pad0[4];
	void* field4;      // 0x4
	char pad1[4];
	char blockA[0x38]; // 0xc
	char blockB[Enum_ov003_021580a0_512];
};

// USA: func_ov003_021580a0
extern "C" ARM void func_ov003_021580a0(struct Struct_ov003_021575dc* p) {
	func_020a1380((struct Struct_020a1180*)p);
	memset(p->blockA, 0, sizeof(p->blockA));
	memset(p->blockB, 0, sizeof(p->blockB));
	p->field4 = p->blockB;
}
