#include <globaldefs.h>
#include "Resource/GameResources.h"

#if defined(jpn)
enum { Enum_ov003_02160e34_792 = 0x200 };
enum { Enum_ov003_02160e34_1124 = 0x28c };
enum { Enum_ov003_02160e34_796 = 0x204 };
enum { Enum_ov003_02160e34_1192 = 0x2d0 };
enum { Enum_ov003_02160e34_1128 = 0x290 };
#else
enum { Enum_ov003_02160e34_792 = 0x318 };
enum { Enum_ov003_02160e34_1124 = 0x464 };
enum { Enum_ov003_02160e34_796 = 0x31c };
enum { Enum_ov003_02160e34_1192 = 0x4a8 };
enum { Enum_ov003_02160e34_1128 = 0x468 };
#endif

extern "C" void* GlobalFlags_GetInstance(void);
struct GameResources;
void SetSubBrightness(GameResources*, int, int);
int IsSubBrightnessTransitionActive(GameResources*);
extern "C" void func_ov003_02167370(void* obj);
struct FlagWord020466f4;
extern "C" void FlagWord_ClearBits(struct FlagWord020466f4* word, unsigned int mask);
extern "C" void func_020dc2d0(int);

struct Struct_ov003_02160e34 {
	char pad0[Enum_ov003_02160e34_792];
	void* unknown_318_;
	char unknown_31c_[Enum_ov003_02160e34_1124 - Enum_ov003_02160e34_796];
	int unknown_464_;
	char unknown_468_[Enum_ov003_02160e34_1192 - Enum_ov003_02160e34_1128];
	unsigned char unknown_4a8_;
};

// USA: func_ov003_02160e34
extern "C" ARM int func_ov003_02160e34(struct Struct_ov003_02160e34* self) {
	int result = 0;
	void* dataPtr = GlobalFlags_GetInstance();
	GameResources* w = GetGameResources();
	unsigned char state = self->unknown_4a8_;

	if (state == 0) {
		SetSubBrightness(w, -16, 8);
		self->unknown_4a8_ = self->unknown_4a8_ + 1;
		goto end;
	}
	if (state != 1) {
		goto end;
	}
	if (IsSubBrightnessTransitionActive(w) != 0) {
		goto end;
	}

	func_ov003_02167370(self->unknown_318_);
	self->unknown_4a8_ = 0;
	result = 1;
	FlagWord_ClearBits((struct FlagWord020466f4*)dataPtr, 0x41);
	func_020dc2d0(0);
	self->unknown_464_ &= ~0x800;
end:
	return result;
}
