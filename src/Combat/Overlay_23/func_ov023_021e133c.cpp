#include <globaldefs.h>
#include "Resource/Script.h"

struct ResetStruct;

struct StreamState;
struct StreamHeader;

struct Struct_0201f040_3;

struct Struct_ov023_021ffa34_3 {
	short field0;
	int field4;
	int field8;
	void* fieldC;
};
extern struct Struct_ov023_021ffa34_3 data_ov023_021ffa34;
extern int data_ov023_021fdc78;

// USA: func_ov023_021e133c
extern "C" ARM void func_ov023_021e133c(void* a, void* b, int c, int d, int e, short f) {
	char local[0x430];
	if (c != 0 && d != 0) {
		data_ov023_021ffa34.fieldC = a;
		data_ov023_021ffa34.field8 = (int)b;
		data_ov023_021ffa34.field4 = e;
		data_ov023_021ffa34.field0 = f;
		((Script*)((struct ResetStruct*)local))->Initialize();
		((Script*)((struct ResetStruct*)local))->SetOpcodeLookup((Script::OpcodeLookupEntry*)&data_ov023_021fdc78);
		((Script*)((struct StreamState*)local))->Load((struct StreamHeader*)c, d);
		((Script*)((struct Struct_0201f040_3*)local))->Execute();
	}
}
