#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"


struct Struct_ov014_021845ec {
	char unknown_0_[0x16];
	short state;
	int handle;
	int field1c;
};

// USA: func_ov014_02188d10
extern "C" ARM int func_ov014_02188d10(struct Struct_ov014_021845ec* s) {
	int t = (int)BackgroundLoader::GetInstance();
	if (s->handle >= 0) {
		((BackgroundLoader*)(t))->RemoveTask((int)(s->handle));
		s->handle = -1;
	}
	s->state = 0;
	s->field1c = 0;
	return 1;
}
