#include <globaldefs.h>

#include "GameState/GameState.h"

extern "C" int func_02053c6c(unsigned char* obj);
extern "C" void func_02083acc(unsigned char* obj, int index);
extern "C" void PartyMember_RecalculateStats(void* a, int arg1);

struct Struct_ov017_021cd1ac {
	unsigned char id : 3;
	unsigned char count : 3;
	unsigned char pad : 2;
};

struct Struct_ov017_021cd1ac_2 {
    Struct_ov017_021cd1ac header;
    unsigned char unknown5;
    unsigned short bitIndices[7];
};

struct Struct_ov017_021cd1ac_3 {
    unsigned char unknown0[4];
    Struct_ov017_021cd1ac_2 payload;
};

// USA: func_ov017_021cd1ac
extern "C" ARM void func_ov017_021cd1ac(int unused0, unsigned char* obj, GameState* battleStruct) {
    Struct_ov017_021cd1ac_2* list = &((Struct_ov017_021cd1ac_3*)obj)->payload;
    Struct_ov017_021cd1ac* hdr = &list->header;
	GameObject* c = func_0200ff1c(battleStruct, hdr->id);
	if (!c) return;
	unsigned char* base = (unsigned char*)func_02053c6c((unsigned char*)c);
	if (!base) return;
	for (int i = 0; i < hdr->count; i++) {
        unsigned short v = list->bitIndices[i];
		func_02083acc(base, v);
	}
	PartyMember_RecalculateStats(base, 0);
}
