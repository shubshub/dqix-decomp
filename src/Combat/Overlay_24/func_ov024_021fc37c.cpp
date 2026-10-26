#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

extern "C" int func_ov024_021fe698(void* obj, int arg);
extern "C" void func_ov024_021f9874(void* obj, void* buf, int zero, int val);
struct Struct_ov024_021fc37c;
extern "C" int func_ov024_021fc498(struct Struct_ov024_021fc37c* obj);

struct Struct_ov024_021fc37c_2 {
	char pad[4];
	unsigned int code : 12;
	unsigned int rest : 20;
};

struct Struct_ov024_021fc37c_3 {
	char pad0[6];
	unsigned char field6;
	char pad1[1];
	GameObject* field8;
	int fieldC;
	char pad2[0x64c - 0x10];
	struct Struct_ov024_021fc37c_2* unknown_64c_;
};

static inline unsigned short inline_ov000_0215cd44_2(GameObject* c) { return c->currentStats_->primaryStats.currMP; }
static inline unsigned short inline_ov024_021dc540_2(GameObject* c) { return c->currentStats_->primaryStats.maxMP; }

// USA: func_ov024_021fc37c
extern "C" ARM void func_ov024_021fc37c(struct Struct_ov024_021fc37c_3* obj) {
	if (obj->unknown_64c_->code != 0x202) return;
	GameObject* c = obj->field8;
	unsigned short maxMP = inline_ov024_021dc540_2(obj->field8);
	float ratio = (float)inline_ov000_0215cd44_2(c) / (float)maxMP;
	float threshold = 0.8f;
	int flag = 0;
	if (obj->field6 == 2) {
		flag = 1;
	} else if (obj->field6 == 0) {
		return;
	} else if (obj->fieldC >= 3) {
		threshold = 0.6f;
		flag = 1;
	}
	if (func_ov024_021fc498((struct Struct_ov024_021fc37c*)c) <= 2) {
		threshold = 0.8f;
		flag = 1;
	}
	if (ratio >= threshold) return;
	if (!flag) return;
	if (!func_ov024_021fe698(obj, 0x12)) return;
	if (((unsigned char*)obj->field8->currentStats_)[0x24] >= 3) return;
	char buf[0xc8];
	memset(buf, 0, 0xc8);
	*(float*)(buf + 0xc4) = 1000.0f;
	func_ov024_021f9874(obj, buf, 0, 0);
}
