#include <globaldefs.h>
#include "std_library_functions.h"
#include "NitroSDK/Memory.h"
#include "Resource/GameResources.h"

extern const char data_ov031_0224c94e[];

struct Struct_ov031_02291e04_5 {
#if defined(jpn)
	unsigned char pad[0x2c];
#else
	unsigned char pad[0x28];
#endif
	int* field28;
};
extern Struct_ov031_02291e04_5 data_ov031_02291e04;

struct Struct_ov031_02245750 {
	char tag[4];
	int field4;
	int field8;
	unsigned char unknown_c_[8];
};

// USA: func_ov031_02245750
extern "C" ARM int func_ov031_02245750(void* unused, Struct_ov031_02245750* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x928};
#else
 enum {regionalOffset0=0xb48};
#endif
	if (strstr((char*)obj, data_ov031_0224c94e) == NULL) return 0;
	int idx = 0;
	while (idx < 0xe) {
		if (data_ov031_02291e04.field28[idx] == obj->field4) break;
		idx++;
	}
	if (idx == 0xe) return 0;
	char* base = (char*)GetGameResources();
	char* p = base + 0x3000;
	unsigned char* q = *(unsigned char**)(p + regionalOffset0);
	q[0x28] = (unsigned char)idx;
	q[0x29] = (unsigned char)obj->field8;
	VectorizedInvertedMemcpy(obj->unknown_c_, q + 0x2a, 8);
	return 1;
}
