#include <globaldefs.h>
#include "Resource/GameResources.h"

extern "C" int func_ov017_021d60f4(void* a);

struct Struct_ov001_02161374 {
	#if defined(jpn)
	char pad[0xf4];
#else
	char pad[0xf8];
#endif
	unsigned int flags : 27;
	unsigned int unknown_fb_3_ : 5;
};

// USA: func_ov001_02161374
extern "C" ARM int func_ov001_02161374(void* values, int count) {
	Struct_ov001_02161374* holder = (Struct_ov001_02161374*)GetGameResources()->unknown_ptr_array_371c[6];
	for (int i = 0; i < count; i++) {
		holder->flags |= func_ov017_021d60f4(values);
		values = (char*)values + 8;
	}
	return 1;
}
