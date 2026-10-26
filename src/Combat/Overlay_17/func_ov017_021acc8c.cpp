#include <globaldefs.h>
#include "Resource/Script.h"

struct ResetStruct;

struct StreamState;
struct StreamHeader;

struct Struct_0201f040_3;

struct Struct_ov017_021d83cc_2 {
	void* field0;
	int field4;
};
extern struct Struct_ov017_021d83cc_2 data_ov017_021d83cc;
extern int data_ov017_021d7900;

// USA: func_ov017_021acc8c
extern "C" ARM void func_ov017_021acc8c(void* param0, struct StreamHeader* param1, int param2, int param3) {
	char local[0x430];
	data_ov017_021d83cc.field0 = param0;
	data_ov017_021d83cc.field4 = param3;
	((Script*)((struct ResetStruct*)local))->Initialize();
	((Script*)((struct ResetStruct*)local))->SetOpcodeLookup((Script::OpcodeLookupEntry*)&data_ov017_021d7900);
	((Script*)((struct StreamState*)local))->Load(param1, param2);
	((Script*)((struct Struct_0201f040_3*)local))->Execute();
}
