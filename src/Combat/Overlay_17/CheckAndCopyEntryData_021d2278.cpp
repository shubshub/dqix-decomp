#include <globaldefs.h>
#include "std_library_functions.h"


struct SearchStruct0202c1a4 {
	char pad[0x1038];
	signed char arr[16];
};
signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);
extern "C" void* Scenario_GetInstance(void* arg);

struct Packed021d2278 {
	unsigned short len : 4;
	unsigned short id : 2;
	unsigned short index : 10;
};

// USA: func_ov017_021d2278
ARM void CheckAndCopyEntryData_021d2278(void* unused, char* p1, int p2, int p3, struct SearchStruct0202c1a4* p4) {
	signed char cur = LinkSession_GetOwnSlot(p4);
	struct Packed021d2278* pk = (struct Packed021d2278*)(p1 + 0x12);
	if (cur != pk->id) return;
	int off = pk->index * 14;
	unsigned char len = pk->len;
	char* base = (char*)Scenario_GetInstance((void*)(int)pk->len);
	memcpy(base + 0x2cc + (unsigned char)off, p1 + 4, len);
}
