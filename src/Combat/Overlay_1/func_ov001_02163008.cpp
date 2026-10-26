#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"



struct Struct020a9ea4;
extern "C" void func_020a9ea4(struct Struct020a9ea4* p);
extern "C" void* Scenario_GetInstance(void);
extern "C" void Scenario_SetFlag(void* unused, unsigned char* array, int bit, int value);

struct Struct_ov001_021658b8_14 {
	SafeAllocator* alloc;
	char pad[0x4b4 - 4];
	void* unknown_4b4_;
	void* unknown_4b8_;
};
extern Struct_ov001_021658b8_14 data_ov001_021658b8;

// USA: func_ov001_02163008
extern "C" ARM int func_ov001_02163008(void) {
	SafeAllocator* alloc = data_ov001_021658b8.alloc;
	void* p1 = alloc->Allocate(8);
	data_ov001_021658b8.unknown_4b4_ = p1;
	func_020a9ea4((struct Struct020a9ea4*)p1);
	void* p2 = alloc->Allocate(0x8000);
	data_ov001_021658b8.unknown_4b8_ = p2;
	memset(p2, 0, 0x8000);
	void* g = Scenario_GetInstance();
	Scenario_SetFlag(g, (unsigned char*)g + 0x8c, 0x1142, 1);
	return 1;
}
