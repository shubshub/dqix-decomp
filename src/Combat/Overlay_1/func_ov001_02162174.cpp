#include <globaldefs.h>
#include "World/Object3D.h"
#include "Resource/GameResources.h"

extern "C" int func_ov017_021d60f4(void*);
extern "C" int func_ov017_021bdbc0(unsigned char* base);
extern "C" int func_ov017_021bdbcc(void*);

// USA: func_ov001_02162174
extern "C" ARM int func_ov001_02162174(void* self, int mode) {
	int extra;
	unsigned char* base;
	int flagWord = func_ov017_021d60f4(self);
	extra = 0;
	if (mode >= 2) extra = func_ov017_021d60f4((char*)self + 0x8);
	base = (unsigned char*)GetGameResources();
	if (extra == 0 || (extra & 1)) {
		int f1 = func_ov017_021bdbc0(base);
		if (f1 != 0) {
			if (flagWord != 0) ((Object3D*)((void*)f1))->MakeVisible();
			else ((Object3D*)((void*)f1))->MakeHidden();
		}
	}
	if (extra & 2) {
		int f2 = func_ov017_021bdbcc(base);
		if (f2 != 0) {
			if (flagWord != 0) ((Object3D*)((void*)f2))->MakeVisible();
			else ((Object3D*)((void*)f2))->MakeHidden();
		}
	}
	return 1;
}
