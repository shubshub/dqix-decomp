#include <globaldefs.h>
#include "Resource/Brightness.h"

extern "C" int func_ov017_021d60f4(void*);

// USA: func_ov001_0215ee2c
extern "C" ARM int func_ov001_0215ee2c(void* self) {
	int obj = (int)GetGameResources();
	if (obj == 0) {
		return 0;
	}
	int a = func_ov017_021d60f4(self);
	int b = func_ov017_021d60f4((char*)self + 0x8);
	switch (a) {
	case 0:
		if (b != 0) {
			ClearFlags04((GameResources*)obj, 8);
		} else {
			SetFlags04((GameResources*)obj, 8);
		}
		break;
	case 1:
		if (b != 0) {
			ClearFlags04((GameResources*)obj, 0x400);
		} else {
			SetFlags04((GameResources*)obj, 0x400);
		}
		break;
	}
	return 1;
}
