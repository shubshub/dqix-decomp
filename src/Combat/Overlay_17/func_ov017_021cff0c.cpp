#include <globaldefs.h>
#include "GameState/GameState.h"

struct SearchStruct0202c1a4;
extern "C" signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);
extern "C" void func_ov017_02191234(int a);
extern "C" void func_02026394(unsigned char* obj, unsigned int index);
extern "C" GameObject* func_0200ff58(GameState* battleStruct, int combatantId);
extern "C" int func_020546a8(void* obj);
extern "C" void func_ov017_021907dc(int a, int b, int c, int d, int e);

struct Struct_ov017_021cff0c {
	unsigned char pad0[4];
	unsigned char field4;
	unsigned char field5;
};

// USA: func_ov017_021cff0c
extern "C" ARM void func_ov017_021cff0c(int unused0, Struct_ov017_021cff0c* evt, GameState* battleStruct, int table, struct SearchStruct0202c1a4* extra) {
#if defined(jpn)
 enum {regionalOffset0=0x4c0};
#else
 enum {regionalOffset0=0x6d0};
#endif
	signed char val = LinkSession_GetOwnSlot(extra);
	if (evt->field4 != val) {
		return;
	}
	func_ov017_02191234(table);
	unsigned char* obj = *(unsigned char**)((unsigned char*)table + 0x3000 + regionalOffset0);
	func_02026394(obj, evt->field5);
	int v = evt->field5;
	GameObject* c = func_0200ff58(battleStruct, v);
	if (c != NULL) {
		v = func_020546a8(c);
	}
	func_ov017_021907dc(table, v, 1, 1, 1);
}
