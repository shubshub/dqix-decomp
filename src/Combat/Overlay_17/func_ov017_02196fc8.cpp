#include <globaldefs.h>
#include "World/Object3D.h"
#include "GameState/GameState.h"
struct GameObject;

struct Struct_02077788_2;
extern "C" int func_02077a20(struct Struct_02077788_2* p);

int fix32abs(int x);

// USA: func_ov017_02196fc8
extern "C" ARM int func_ov017_02196fc8(GameObject* arg0, GameObject* arg1, int extra) {
	unsigned char* other = (unsigned char*)arg1;
	int a = arg0->obj3D_.GetRadius();
	int half;

	if (arg1->obj3D_.unknown_0_ & 0x20) {
		int var3 = arg1->obj3D_.GetScale().x * 15;
		int var4 = func_02077a20((struct Struct_02077788_2*)other) >> 1;
		half = (int)(((long long)var4 * var3 + 0x800) >> 12);
	} else {
		half = arg1->obj3D_.GetRadius() >> 1;
	}

	int dist = extra + (half + (a >> 1));

	if (dist < fix32abs(arg0->obj3D_.position_.x - arg1->obj3D_.position_.x)) return 0;
	if (dist < fix32abs(arg0->obj3D_.position_.z - arg1->obj3D_.position_.z)) return 0;

	int d = Vector3fix_Distance(&arg0->obj3D_.position_, &arg1->obj3D_.position_);
	if (dist < d) return 0;

	return d != 0;
}
