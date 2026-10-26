#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021cc198 {
	unsigned char field4;
	unsigned char pad1[3];
	int field8;
};

struct Struct_ov017_021cc198_2 {
	unsigned char tag;
	unsigned char pad0[3];
	Struct_ov017_021cc198 sub;
	unsigned char pad2[8];
};

// USA: func_ov017_021cc198
extern "C" ARM void func_ov017_021cc198(unsigned char a, int b) {
	Struct_ov017_021cc198_2 buf;
	GameState::GetInstance();
	void* p = LinkMessageQueue_GetInstance();
	Struct_ov017_021cc198* s = &buf.sub;
	buf.tag = 0x2c;
	s->field4 = a;
	s->field8 = b;
	func_0205e330(p, &buf, 0);
}
