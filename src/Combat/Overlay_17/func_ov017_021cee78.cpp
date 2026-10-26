#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);
struct Vector3i;

struct Struct_ov017_021cee78 {
	unsigned char tag;
	unsigned char pad0[3];
	int vec[3];
	unsigned short field10;
	unsigned char field12;
	unsigned char unknown_13_;
};

// USA: func_ov017_021cee78
extern "C" ARM void func_ov017_021cee78(int id, unsigned char b) {
	GameObject* c = GameState::GetInstance()->GetGameObjectByIndex(id);
	if (c == NULL) {
		return;
	}
	void* p = LinkMessageQueue_GetInstance();
	Struct_ov017_021cee78 buf;
	buf.tag = 0x14;
	buf.field12 = id;
	*(Vector3i*)buf.vec = *(Vector3i const*)(&c->obj3D_.position_.x);
	buf.field10 = c->obj3D_.rotation_.y;
	buf.unknown_13_ = b;
	func_0205e330(p, &buf, 0);
}
