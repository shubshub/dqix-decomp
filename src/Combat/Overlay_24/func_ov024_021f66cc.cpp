#include <globaldefs.h>
#include "Resource/ActionDataTables.h"
#include "GameState/GameState.h"

extern "C" GameObject* func_0200fea4(GameState* gameState, int combatantId);
extern "C" int func_ov000_02159d94(void* unused, int id);

struct Struct_ov024_021f66cc {
	char pad0[0xc];
	unsigned short unknown_c_;
	unsigned short unknown_e_;
};

extern "C" struct Struct_ov024_021f66cc* func_02079e2c(char* table, int key);

class Struct_ov024_021f66cc_2 {
public:
	void* battle;
};

typedef int (Struct_ov024_021f66cc_2::*Type_02000c9c_16)(unsigned char id, struct Struct_ov024_021f66cc* move, int a3, int a4);

extern Type_02000c9c_16 data_ov024_021ff790[];

// USA: func_ov024_021f66cc
extern "C" ARM int func_ov024_021f66cc(Struct_ov024_021f66cc_2* obj, void* battle, int arg2, int id, int a4, int a5) {
	obj->battle = battle;
	func_0200fea4(GameState::GetInstance(), id);
	struct Struct_ov024_021f66cc* move = func_02079e2c((char*)func_020797dc(), (short)arg2);
	int handler = 0;
	int kind = func_ov000_02159d94(obj->battle, (short)id);
	switch (kind) {
	case 1:
		handler = move->unknown_c_;
		break;
	case 2:
		handler = move->unknown_e_;
		break;
	}
	if (handler >= 0xa1) {
		return (obj->*data_ov024_021ff790[0])(id, move, a4, a5);
	}
	if (data_ov024_021ff790[handler] == 0) {
		return (obj->*data_ov024_021ff790[0])(id, move, a4, a5);
	}
	return (obj->*data_ov024_021ff790[handler])(id, move, a4, a5);
}
